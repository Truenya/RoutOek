#include "RoutIncludes.h"

class ReadRout
{
    oek_rout mRout;
    oek_rout mVCU;
    bool file_loaded;
    bool use_formatting;
    csv::CSVFormat mFormat;
    bool load_from_file();
    bool load_from_file(std::string);
public:
    ReadRout();
    void set_formatting(bool);


    bool load_new_file(std::string);
    /**
     * @brief getFullRout
     * @param filepath абсолютный или относительный путь к файлу
     * @return std::vector<OekPoint> получает полный путь без ВЦУ.
     */
    oek_rout getFullRout(std::string);
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
     * @brief getVCU
     * @param filepath абсолютный или относительный путь к файлу
     * @return std::vector<OekPoint> получает ВЦУ.
     */
    oek_rout getVCU(std::string);
    /**
     * @brief getRoutsByType
     * @param int type_id
     * @return oek_routs вектор отрезков маршрута, где  опознавался данный тип
     */
    oek_routs getRoutsByType(int);
    /**
     * @brief getRoutsByType
     * @param int type_id
     * @param filepath абсолютный или относительный путь к файлу
     * @return oek_routs вектор отрезков маршрута, где  опознавался данный тип
     */
    oek_routs getRoutsByType(int, std::string);
    /**
     * @brief getRoutByType
     * @param int type_id
     * @return oek_rout маршрут, составленный из всех точек, по данному типу
     */
    oek_rout getRoutByType(int);
    /**
     * @brief getRoutByType
     * @param int type_id
     * @param filepath абсолютный или относительный путь к файлу
     * @return oek_rout маршрут, составленный из всех точек, по данному типу
     */
    oek_rout getRoutByType(int, std::string);
    /**
     * @brief getTypes
     * @return std::vector <int> вектор типов, представленных в загруженном пути.
     */
    oek_types_on_rout getTypes();
    /**
     * @brief getTypes
     * @param filepath абсолютный или относительный путь к файлу
     * @return std::vector <int> вектор типов, представленных в загруженном пути.
     */
    oek_types_on_rout getTypes(std::string);

    bool saveToFile(oek_rout);
    /**
     * @brief ReadRout::makeFileSaver
     * @param filename путь к файлу
     * @param ss файлстрим, используемый для записи
     * @details Используется как cout, принимает на вход std {array,tuple,list,vector}// saver << container;
     * @return Объект записи пути.
     */
    auto makeFileSaver(std::string,std::ofstream);

    csv::CSVFormat Format() const;
    void setFormat(const csv::CSVFormat &format);
};
