#ifndef ROUTINCLUDES_H
#define ROUTINCLUDES_H
#include <set>
#include <map>
#include "csv-parser/include/csv.hpp"
#include <math.h>

typedef std::map<std::string,double> OekPoint;
typedef std::vector<OekPoint> oek_route;
typedef std::vector <oek_route> oek_routes;
typedef std::vector <int> oek_types_on_route;
// Defines for better coding
#define SID "sId"
#define TYPE_ID "type_id"
#define COORDX "coordX"
#define COORDY "coordY"
#define COORDH "coordH"
#define OEK_TIME "time"
#define CAM_FOCUS "cam_focus"
#define SIZE_PIX "size_pix"
#define FRAME_WIDTH "frame_width"
#define FRAME_X "frame_x"
#define FRAME_Y "frame_y"
#define FRAME_HEIGHT "frame_height"
#define AZ "Az"
#define EL "El"
#define INDXCAM "indxcam"
#define INDXFRAME "indxframe"
#define OBJECTMETHOD "objectmethod"

#define LATITUDE "latitude"
#define LONGITUDE "longitude"
#define ALTITUDE "altitude"
#define HEADING "heading"
#define SPEED "speed"
#define BTRACKING "btracking"

enum fileType
{
    gps,
    oek
};
const std::vector <std::string> default_col_names={SID,TYPE_ID,COORDX,COORDY,COORDH,OEK_TIME,CAM_FOCUS,SIZE_PIX,FRAME_WIDTH,FRAME_X,FRAME_Y,FRAME_HEIGHT,AZ,EL,INDXCAM,INDXFRAME,OBJECTMETHOD};
const std::vector <std::string> default_gps_col_names = {LATITUDE,LONGITUDE,ALTITUDE,HEADING,SPEED,BTRACKING,OEK_TIME};
#endif // ROUTEINCLUDES_H
