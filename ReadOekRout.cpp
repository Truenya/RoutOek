#include "ReadOekRout.h"

oek_rout ReadOekRout::save_to_vector()
{
    std::vector <OekRoutString> rout_data;
    double a,b,c,d,e,f,g,h,i,j,k,l,m,n,o;
    io::CSVReader <15,io::trim_chars<' '>,io::no_quote_escape<';'>> reader("./test.csv");;
    reader.read_header(io::ignore_extra_column, "a", "b", "c", "d","e","f","g","h","i","j","k","l","m","n","o");
    while(reader.read_row(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o))//some_string.sId,some_string.type_id,some_string.x,some_string.y,some_string.h))//,some_string.time,some_string.cam_focus,some_string.size_pix,some_string.frame_x,some_string.frame_y));//,
        //some_string.frame_height,some_string.Az,some_string.El,some_string.indxcam,some_string.indxframe))
  {
    rout_data.push_back(OekRoutString(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o));
        //printf("%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f \n",a,b,c,d,e,f,g,h,i,j,k,l,m,n,o);//,some_string.time,some_string.cam_focus,some_string.size_pix,some_string.frame_x,some_string.frame_y));//
       // some_string.frame_height,some_string.Az,some_string.El,some_string.indxcam,some_string.indxframe));
  }
    return rout_data;
};
