RouteOekRout: интерфейс загрузки путей из файлов .oek.
*Добавлена возможность записи файлов.
*Для загрузки используется функция load_from_file(std::string filepath).
*ВЦУ и маршрут, полученный от камеры получаются отдельно функциями getVCU(),getFullRout().
*Маршруты хранятся в формате std::vector<OekPoint>.
*Точки маршрута хранятся в формате std::map<std::string,double>.
*Интерфейс использует библиотеку https://github.com/ben-strasser/fast-cpp-csv-parser
*Сборка требует поддержки 17 стандарта.
*Пример использования в файле test.cpp.
