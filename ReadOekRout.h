#include "RoutIncludes.h"

class ReadRout
{
    oek_rout mRout;
    oek_rout mVCU;
    bool file_loaded = false;
    bool use_formatting = false;
    csv::CSVFormat mFormat;
public:

    bool load_from_file();
    bool load_from_file(std::string);
    bool load_from_file(std::string,fileType);
    /**
     * @brief getFullRout
     * @return std::vector<OekPoint> получает полный путь без ВЦУ.
     */
    oek_rout getFullRout();
    /**
     * @brief getVCU
     * @return std::vector<OekPoint> получает ВЦУ.
     */
    oek_rout getVCU();
    /**
     * @brief getRoutsByType
     * @param int type_id
     * @return oek_routs вектор отрезков маршрута, где  опознавался данный тип
     */
    oek_routs getRoutsByType(int);
    /**
     * @brief getRoutByType
     * @param int type_id
     * @return oek_rout маршрут, составленный из всех точек, по данному типу
     */
    oek_rout getRoutByType(int);
    /**
     * @brief getTypes
     * @return std::vector <int> вектор типов, представленных в загруженном пути.
     */
    oek_types_on_rout getTypes();
    bool saveToFile(oek_rout);
    auto makeFileSaver(std::string,std::ofstream);
};
