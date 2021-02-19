#ifndef ROUTINCLUDES_H
#define ROUTINCLUDES_H
#include <set>
#include <map>
#include "../csv-parser/include/csv.hpp"
#include <math.h>
#include "kf1_dimension.h"

typedef std::map<std::string,double> OekPoint;
typedef std::vector<OekPoint> oek_rout;
typedef std::vector <oek_rout> oek_routs;
typedef std::vector <int> oek_types_on_rout;
// Defines for better coding
#define sId "sId"
#define type_id "type_id"
#define coordX "coordX"
#define coordY "coordY"
#define coordH "coordH"
#define oek_time "time"
#define cam_focus "cam_focus"
#define size_pix "size_pix"
#define frame_width "frame_width"
#define frame_x "frame_x"
#define frame_y "frame_y"
#define frame_height "frame_height"
#define Az "Az"
#define El "El"
#define indxcam "indxcam"
#define indxframe "indxframe"
#define objectmethod "objectmethod"
enum fileType
{
    gps,
    oek
};
const std::vector <std::string> default_col_names={sId,type_id,coordX,coordY,coordH,oek_time,cam_focus,size_pix,frame_width,frame_x,frame_y,frame_height,Az,El,indxcam,indxframe,objectmethod};
#endif // ROUTINCLUDES_H
