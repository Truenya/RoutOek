#include "ReadOekRout.h"

oek_rout ReadRout::getFullRout()
{
    load_from_file();
    return mRout;
}

oek_rout ReadRout::getVCU()
{
    load_from_file();
    return mVCU;
}

oek_routs ReadRout::getRoutsByType(int typo)
{
    load_from_file();
    int prev_id=0;
    oek_routs routs_by_type;
    oek_rout* part_of_rout = new oek_rout;
    for (auto& point : mRout)
        if((prev_id = point["type_id"]) == typo)
        {
            part_of_rout -> push_back(point);
        } else if (prev_id == typo) {
            routs_by_type.push_back(*part_of_rout);
            delete part_of_rout;
            oek_rout* part_of_rout = new oek_rout;
        }
    delete part_of_rout;
    return routs_by_type;
}

oek_rout ReadRout::getRoutByType(int typo)
{
    load_from_file();
    oek_rout rout_by_type;
    for (auto&point: mRout)
        if(point["type_id"] == typo)
            rout_by_type.push_back(point);
    return rout_by_type;
}

oek_types_on_rout ReadRout::getTypes()
{
    load_from_file();
    oek_types_on_rout types;
    std::set<int> setTypes;
    for (auto& point: mRout)
        setTypes.insert(point["type_id"]);
    for (auto& unic_type:setTypes)
        types.push_back(unic_type);
    return types;
}

bool ReadRout::saveToFile(oek_rout rout_to_save)
{
    std::ofstream ss;
    ss.open("new_file.oek");
    auto writer = csv::make_csv_writer(ss);
    csv::DelimWriter <std::ofstream, ';', '"',false> mWriter(ss);

    for(auto &point:rout_to_save)
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

auto ReadRout::makeFileSaver(std::string filename,std::ofstream ss)
{
    ss.open(filename);
    csv::DelimWriter <std::ofstream, ';', '"',false> mWriter(ss);
    return mWriter;
}

void ReadRout::set_formatting(bool fmt)
{
    use_formatting = fmt;
}

bool ReadRout::load_from_file()
{
    std::string filename = "route.oek";
    if(load_from_file(filename))
        return true;
    return false;
}

bool ReadRout::load_from_file(std::string filepath)
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
                mRout.push_back(*point);
                delete point;
            }
        } else//use formatting
        {
            mFormat = csv::CSVFormat::guess_csv();

            mFormat.column_names(default_col_names);
            mFormat.delimiter(';');
            mFormat.variable_columns(csv::VariableColumnPolicy::KEEP);

            csv::CSVReader reader(filepath,mFormat);
            int row_size = (++reader.begin())->size();//0,5,12,13
            for (auto& row: reader)
            {
                if(row.size()==4)
                {
                    OekPoint *point = new OekPoint;
                    auto field = row.begin();
                        (*point)[sId]       = field->get<int>();//sid
                            field++;
                        (*point)[oek_time]  = field->get<int>();//time
                            field++;
                        (*point)[Az]        = field->get<double>();//az
                            field++;
                        (*point)[El]        = field->get<double>();//el
                    mVCU.push_back(*point);
                    delete point;
                }
                else
                {
                    OekPoint *point = new OekPoint;
                    for(int i = 0; i<row.size();i++)
                    {
                        (*point)[default_col_names[i]] = row[i].get<double>();
                    }
                    mRout.push_back(*point);
                    delete point;
                }
            }
        }

        file_loaded = true;
        return true;
    }
    return true;
}

