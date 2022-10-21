#include "specialtypes.h"
#include "slope_finder.h"

void matrix_of_slopes(int N, position *ship, fig triangle, 
                      position port, float (*slopes)[4]) {
  const double min = 60.0;
  const double sec = 3600.0; 

  double latitude_port = port.lat.degree + port.lat.minute / min
                       + port.lat.second / sec;
  double longitude_port = port.longitude.degree + port.longitude.minute / min
                        + port.longitude.second / sec;

  double latitude_apex[3] = {0};
  double longitude_apex[3] = {0};
  latitude_apex[0] = triangle.apex1.lat.degree + triangle.apex1.lat.minute / min
                   + triangle.apex1.lat.second / sec;
  longitude_apex[0] = triangle.apex1.longitude.degree + triangle.apex1.longitude.minute / min 
                    + triangle.apex1.longitude.second / sec;
  latitude_apex[1] = triangle.apex2.lat.degree + triangle.apex2.lat.minute / min
                   + triangle.apex2.lat.second / sec;
  longitude_apex[1] = triangle.apex2.longitude.degree + triangle.apex2.longitude.minute / min 
                    + triangle.apex2.longitude.second / sec;
  latitude_apex[2] = triangle.apex3.lat.degree + triangle.apex3.lat.minute / min
                   + triangle.apex3.lat.second / sec;
  longitude_apex[2] = triangle.apex3.longitude.degree + triangle.apex3.longitude.minute / min 
                    + triangle.apex3.longitude.second / sec;

  for (int cur_ship = 0; cur_ship < N; ++cur_ship) {
    double latitude_ship = ship[cur_ship].lat.degree + ship[cur_ship].lat.minute / min
                         + ship[cur_ship].lat.second / sec;
    double longitude_ship = ship[cur_ship].longitude.degree + ship[cur_ship].longitude.minute / min 
                          + ship[cur_ship].longitude.second / sec;
    slopes[cur_ship][3] = (latitude_port - latitude_ship) / (longitude_port - longitude_ship);
    for (int cur_apex = 0; cur_apex < 3; ++cur_apex) {
      slopes[cur_ship][cur_apex] = (latitude_apex[cur_apex] - latitude_ship) / (longitude_apex[cur_apex] - longitude_ship);
    } 
  } 

  return;
}