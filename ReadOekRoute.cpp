#include "ReadOekRoute.h"

oek_route ReadRoute::getFullRoute()
{
    load_from_file();
    return mRoute;
}

oek_route ReadRoute::getMainRoute(std::string filename)
{
    file_loaded=false;
    if(!load_from_file(filename))
        throw;
    oek_routes routes;
    oek_types_on_route types = getTypes();
    for (auto& typo: types)
        routes.push_back(getRouteByType(typo));
    for(auto&route:routes)
        if(route.size()==routes.max_size())
            return route;
}

oek_route ReadRoute::getMainRoute()
{
    load_from_file();
    oek_routes routes;
    oek_types_on_route types = getTypes();
    for (auto& typo: types)
        routes.push_back(getRouteByType(typo));
    for(auto&route:routes)
        if(route.size()==routes.max_size())
            return route;
}

oek_route ReadRoute::getVCU()
{
    load_from_file();
    return mVCU;
}

oek_route ReadRoute::getVCU(std::string filepath)
{
    file_loaded = false;
    load_from_file(filepath);
    return mVCU;
}

oek_routes ReadRoute::getRoutesByType(int typo)
{
    load_from_file();
    int prev_id=0;
    oek_routes routes_by_type;
    oek_route* part_of_route = new oek_route;
    for (auto& point : mRoute)
        if((prev_id = point["type_id"]) == typo)
        {
            part_of_route -> push_back(point);
        } else if (prev_id == typo) {
            routes_by_type.push_back(*part_of_route);
            delete part_of_route;
            oek_route* part_of_route = new oek_route;
        }
    delete part_of_route;
    return routes_by_type;
}

oek_routes ReadRoute::getRoutesByType(int typo, std::string filepath)
{
    file_loaded = false;
    if(load_from_file(filepath))
        return getRoutesByType(typo);
    throw;
}

oek_route ReadRoute::getRouteByType(int typo)
{
    load_from_file();
    oek_route route_by_type;
    for (auto&point: mRoute)
        if(point["type_id"] == typo)
            route_by_type.push_back(point);
    return route_by_type;
}

oek_route ReadRoute::getRouteByType(int typo, std::string filepath)
{
    file_loaded = false;
    if(load_from_file(filepath))
        return getRouteByType(typo);
    throw;
}

oek_types_on_route ReadRoute::getTypes()
{
    load_from_file();
    oek_types_on_route types;
    std::set<int> setTypes;
    for (auto& point: mRoute)
        setTypes.insert(point["type_id"]);
    for (auto& unic_type:setTypes)
        types.push_back(unic_type);
    return types;
}

oek_types_on_route ReadRoute::getTypes(std::string filepath)
{
    file_loaded = false;
    if(load_from_file(filepath))
        return getTypes();
    throw;
}



void ReadRoute::set_formatting(bool fmt)
{
    use_formatting = fmt;
}

bool ReadRoute::load_new_file(std::string file)
{
    file_loaded = false;
    if(load_from_file(file))
        return true;
    return false;
}


bool ReadRoute::load_from_file()
{
    std::string filename = "routee.oek";
    if(load_from_file(filename))
        return true;
    return false;
}

bool ReadRoute::load_from_file(std::string filepath)
{
    if(!file_loaded)
    {
        if(!use_formatting)
        {
            csv::CSVReader reader(filepath);
            std::vector <std::string> names=reader.get_col_names();
            for(auto& oekPoint: reader)
            {
                OekPoint *point = new OekPoint;
                for (auto& name : names)
                {
                    (*point)[name] =oekPoint[name].get<double>();
                }
                mRoute.push_back(*point);
                delete point;
            }
        } else//use formatting
        {



            csv::CSVFormat mFormat = csv::CSVFormat::guess_csv();
            mFormat.column_names(default_col_names);
            mFormat.delimiter(';');
            mFormat.variable_columns(csv::VariableColumnPolicy::KEEP);

            csv::CSVReader reader(filepath,mFormat);
            int row_size = (++(reader.begin()))->size();//0,5,12,13
            for (auto& row: reader)
            {
                if(row.size()==3)
                    continue;
                if(row.size()==4)
                {
                    OekPoint *point = new OekPoint;
                    auto field = row.begin();
                        (*point)[SID]       = field->get<int>();//sid
                            field++;
                        (*point)[OEK_TIME]  = field->get<int>();//time
                            field++;
                        (*point)[AZ]        = field->get<double>();//az
                            field++;
                        (*point)[EL]        = field->get<double>();//el
                    mVCU.push_back(*point);
                    delete point;
                }
                else
                {
                    if(row_size==7 || row_size==6)
                    {
                        OekPoint *point = new OekPoint;
                        for(int i = 0; i<row.size();i++)
                        {
                            (*point)[default_gps_col_names[i]] = row[i].get<double>();
                        }
                        mRoute.push_back(*point);
                    }

                    OekPoint *point = new OekPoint;
                    for(int i = 0; i<row.size();i++)
                    {
                        (*point)[default_col_names[i]] = row[i].get<double>();
                    }
                    mRoute.push_back(*point);
                    delete point;
                }
            }
        }

        file_loaded = true;
        return true;
    }
    return true;
}

oek_route ReadRoute::getFullRoute(std::string filePath)
{
    file_loaded = false;
    if(load_from_file(filePath))
    {
        return mRoute;
    }
    throw;
}

bool WriteRoute::saveToFile(oek_route route_to_save)
{
    std::ofstream ss;
    ss.open("new_file.oek");
    auto writer = csv::make_csv_writer(ss);
    csv::DelimWriter <std::ofstream, ';', '"',false> mWriter(ss);

    for(auto &point:route_to_save)
    {
        std::vector<double> * row = new std::vector<double>;
        for(auto& name:default_col_names)
        {
            row->push_back(point[name]);
        }
        mWriter<<*row;
        delete row;
    }
    return true;
}

auto WriteRoute::makeFileSaver(std::string filename,std::ofstream ss)
{
    ss.open(filename);
    csv::DelimWriter <std::ofstream, ';', '"',false> mWriter(ss);
    return mWriter;
}
