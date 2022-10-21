#ifndef TYPES
#define TYPES

typedef struct {
  int degree;
  int minutes;
  int second;
} coordinates;

typedef struct {
  coordinates lat;
  coordinates longitude;
} position;

typedef struct {
  position apex1;
  position apex2;
  position apex3;
} fig;

#endif
