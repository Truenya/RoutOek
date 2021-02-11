# include "ReadOekRout.h"

int main(){
    ReadOekRout reader;
    oek_rout rout = reader.save_to_vector();
    for (auto& coord : rout)
        printf("X: %f, Y: %f\n", coord.x,coord.y);
    coord.
    system("pause");
}
