#include "slope_finder.h"

void matrix_of_slopes(int N, struct position *ship, struct fig triangle, 
                      struct position port, float (*slopes)[4]) {
  double latitude_port = port.lat.degree + port.lat.minute / 60
                       + port.lat.second / 3600;
  double longitude_port = port.longitude.degree + port.longitude.minute / 60
                        + port.longitude.second / 3600;
  double latitude_apex[3] = {0};
  double longitude_apex[3] = {0};
  latitude_apex[0] = fig.apex1.lat.degree + fig.lat.minute / 60
                                 + fig.lat.second / 3600;
  longitude_apex[0] = fig.apex1.longitude.degree + fig.longitude.minute / 60 
                                  + fig.longitude.second / 3600;
  latitude_apex[1] = fig.apex2.lat.degree + fig.lat.minute / 60
                                 + fig.lat.second / 3600;
  longitude_apex[1] = fig.apex2.longitude.degree + fig.longitude.minute / 60 
                                  + fig.longitude.second / 3600;
  latitude_apex[2] = fig.apex3.lat.degree + fig.lat.minute / 60
                                 + fig.lat.second / 3600;
  longitude_apex[2] = fig.apex3.longitude.degree + fig.longitude.minute / 60 
                                  + fig.longitude.second / 3600;

  for (int cur_ship = 0; cur_ship < N; ++cur_ship) {
    double latitude_ship = ship[cur_ship].lat.degree + ship[cur_ship].lat.minute / 60
                         + ship[cur_ship].lat.second / 3600;
    double longitude_ship = ship[cur_ship].longitude.degree + ship[cur_ship].longitude.minute / 60 
                          + ship[cur_ship].longitude.second / 3600;
    slopes[cur_ship][3] = (latitude_port - latitude_ship) / (longitude_port - longitude_ship);
    for (int cur_apex = 0; cur_apex < 3; ++cur_apex) {
      slopes[i][j] = (latitude_apex[cur_apex] - latitude_ship) / (longitude_apex[cur_apex] - longitude_ship);
    } 
  } 
  
  return;
}