#include "specialtypes.h"
#include "slope_finder.h"

void matrix_of_slopes(int N, position *ship, fig triangle, 
                      position port, float (*slopes)[4]) {
  double latitude_port = port.lat.degree + port.lat.minute / 60.0
                       + port.lat.second / 3600.0;
  double longitude_port = port.longitude.degree + port.longitude.minute / 60.0
                        + port.longitude.second / 360.0;
  double latitude_apex[3] = {0};
  double longitude_apex[3] = {0};
  latitude_apex[0] = triangle.apex1.lat.degree + triangle.apex1.lat.minute / 60.0
                                 + triangle.apex1.lat.second / 3600.0;
  longitude_apex[0] = triangle.apex1.longitude.degree + triangle.apex1.longitude.minute / 60.0 
                                  + triangle.apex1.longitude.second / 3600.0;
  latitude_apex[1] = triangle.apex2.lat.degree + triangle.apex2.lat.minute / 60.0
                                 + triangle.apex2.lat.second / 3600.0;
  longitude_apex[1] = triangle.apex2.longitude.degree + triangle.apex2.longitude.minute / 60.0 
                                  + triangle.apex2.longitude.second / 3600.0;
  latitude_apex[2] = triangle.apex3.lat.degree + triangle.apex3.lat.minute / 60.0
                                 + triangle.apex3.lat.second / 3600.0;
  longitude_apex[2] = triangle.apex3.longitude.degree + triangle.apex3.longitude.minute / 60.0 
                                  + triangle.apex3.longitude.second / 3600.0;

  for (int cur_ship = 0; cur_ship < N; ++cur_ship) {
    double latitude_ship = ship[cur_ship].lat.degree + ship[cur_ship].lat.minute / 60.0
                         + ship[cur_ship].lat.second / 3600.0;
    double longitude_ship = ship[cur_ship].longitude.degree + ship[cur_ship].longitude.minute / 60.0 
                          + ship[cur_ship].longitude.second / 3600.0;
    slopes[cur_ship][3] = (latitude_port - latitude_ship) / (longitude_port - longitude_ship);
    for (int cur_apex = 0; cur_apex < 3; ++cur_apex) {
      slopes[cur_ship][cur_apex] = (latitude_apex[cur_apex] - latitude_ship) / (longitude_apex[cur_apex] - longitude_ship);
    } 
  } 

  return;
}