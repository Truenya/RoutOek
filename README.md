RouteOekRout: интерфейс загрузки путей из файлов .oek.
Добавлена возможность записи файлов.
Для загрузки используется функция load_from_file(std::string filepath).
ВЦУ и маршрут, полученный от камеры получаются отдельно функциями getVCU(),getFullRout().
Маршруты хранятся в формате std::vector<OekPoint>.
Точки маршрута хранятся в формате std::map<std::string,double>.
Интерфейс использует библиотеку https://github.com/ben-strasser/fast-cpp-csv-parser
Сборка требует поддержки 17 стандарта.
Пример использования:
# include "ReadOekRout.h"
using namespace  std;

int main(){
    ReadRout reader;
    oek_types_on_rout types = reader.getTypes();
    if(reader.load_from_file("route_17_42.oek"))
      printf("File was read succesfull, got %f rows.",reader.size());
    oek_rout rout_0 = reader.getFullRout();
    oek_rout VCU = reader.getVCU();
    double dalnost_by_frame=0;
    double MSE = 0;
    double sum = 0;
    int i =1;
    for (auto& row : rout_0) {
            dalnost_by_frame = (row[cam_focus]*((row[frame_height]+row[frame_width])/2))/(row[frame_width]*row[size_pix]);
            sum += dalnost_by_frame;
            i++;
    }
    double mean = sum/i;
    for (auto& row : rout_0) {
            dalnost_by_frame = (row[cam_focus]*((row[frame_height]+row[frame_width])/2))/(row[frame_width]*row[size_pix]);
            MSE += sqrt((mean - dalnost_by_frame)*(mean - dalnost_by_frame))/i;
    }
    std::cout<<"MSE without filtering: "<<MSE<<endl;
    KF1_dimension filter;

    for (auto& row : rout_0) {
            dalnost_by_frame = (row[cam_focus]*((row[frame_height]+row[frame_width])/2))/(row[frame_width]*row[size_pix]);
            dalnost_by_frame = filter.ab_filter(dalnost_by_frame);
            MSE += sqrt((mean - dalnost_by_frame)*(mean - dalnost_by_frame))/i;
    }
    std::cout<<"MSE withs filtering: "<<MSE<<endl;
}

