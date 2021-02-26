#include "RouteIncludes.h"

class ReadRoute
{
    oek_route mRoute;
    oek_route mVCU;
    bool file_loaded = false;
    bool use_formatting = true;
    bool load_from_file();
    bool load_from_file(std::string);
public:
    void set_formatting(bool);
    bool load_new_file(std::string);
    /**
     * @brief getFullRoute
     * @param filepath абсолютный или относительный путь к файлу
     * @return std::vector<OekPoint> получает полный путь без ВЦУ.
     */
    oek_route getFullRoute(std::string);
    /**
     * @brief getFullRoute
     * @return std::vector<OekPoint> получает полный путь без ВЦУ.
     */
    oek_route getFullRoute();
    /**
     * @brief getMainRoute
     * @param filepath абсолютный или относительный путь к файлу
     * @return oek_route маршрут, составленный из всех точек, по данному типу
     */
    oek_route getMainRoute(std::string);
    /**
     * @brief getMainRoute
     * @return oek_route маршрут, составленный из всех точек, по типу с максимальным количеством отметок
     */
    oek_route getMainRoute();
    /**
     * @brief getVCU
     * @return std::vector<OekPoint> получает ВЦУ.
     */
    oek_route getVCU();
    /**
     * @brief getVCU
     * @param filepath абсолютный или относительный путь к файлу
     * @return std::vector<OekPoint> получает ВЦУ.
     */
    oek_route getVCU(std::string);
    /**
     * @brief getRoutesByType
     * @param int type_id
     * @return oek_routes вектор отрезков маршрута, где  опознавался данный тип
     */
    oek_routes getRoutesByType(int);
    /**
     * @brief getRoutesByType
     * @param int type_id
     * @param filepath абсолютный или относительный путь к файлу
     * @return oek_routes вектор отрезков маршрута, где  опознавался данный тип
     */
    oek_routes getRoutesByType(int, std::string);
    /**
     * @brief getRouteByType
     * @param int type_id
     * @return oek_route маршрут, составленный из всех точек, по данному типу
     */
    oek_route getRouteByType(int);
    /**
     * @brief getRouteByType
     * @param int type_id
     * @param filepath абсолютный или относительный путь к файлу
     * @return oek_route маршрут, составленный из всех точек, по данному типу
     */
    oek_route getRouteByType(int, std::string);
    /**
     * @brief getTypes
     * @return std::vector <int> вектор типов, представленных в загруженном пути.
     */
    oek_types_on_route getTypes();
    /**
     * @brief getTypes
     * @param filepath абсолютный или относительный путь к файлу
     * @return std::vector <int> вектор типов, представленных в загруженном пути.
     */
    oek_types_on_route getTypes(std::string);
};

class WriteRoute
{
    bool saveToFile(oek_route);
    /**
     * @brief ReadRoute::makeFileSaver
     * @param filename путь к файлу
     * @param ss файлстрим, используемый для записи
     * @details Используется как cout, принимает на вход std {array,tuple,list,vector}// saver << container;
     * @return Объект записи пути.
     */
    static auto makeFileSaver(std::string,std::ofstream);
};
