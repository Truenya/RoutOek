#include "csv.h"
using namespace io;
struct OekRoutString;
typedef std::vector <OekRoutString> oek_rout;

struct OekRoutString
{
  double sId;
  double type_id;
  double x;
  double y;
  double h;
  double time;
  double cam_focus;
  double size_pix;
  double frame_x;
  double frame_y;
  double frame_height;
  double Az;
  double El;
  double indxcam;
  double indxframe;
  double objectmethod;
  OekRoutString()
  {
     sId=0;
     type_id=0;
     x=0;
     y=0;
     h=0;
     time=0;
     cam_focus=0;
     size_pix=0;
     frame_x=0;
     frame_y=0;
     frame_height=0;
     Az=0;
     El=0;
     indxcam=0;
     indxframe=0;
     objectmethod=0;
  }
  OekRoutString(double a,double b,double c,double d,double e,double f,double g,double h,double i,double j,double k,double l,double m,double n,double o)
  {
     sId=a;
     type_id=b;
     x=c;
     y=d;
     h=e;
     time=f;
     cam_focus=g;
     size_pix=h;
     frame_x=i;
     frame_y=j;
     frame_height=k;
     Az=l;
     El=m;
     indxcam=n;
     indxframe=o;
     objectmethod=0;
  }
};

struct ReadOekRout
{

  oek_rout save_to_vector();
};




