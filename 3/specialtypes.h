#ifndef TYPES
#define TYPES

struct coordinates{
  int degree;
  int minute;
  int second;
};

struct position {
  coordinates lat;
  coordinates longitude;
};

struct fig {
  position apex1;
  position apex2;
  position apex3;
};

#endif
