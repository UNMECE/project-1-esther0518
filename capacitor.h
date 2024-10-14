#ifndef CAPICITOR_H
#define CAPICITOR_H

struct _capacitor
{
  double *time;       // time array
  double *voltage;    // voltage array
  double *current;    // current array
  double C;           // capacitance value
};
typedef struct _capacitor Capacitor;


#endif 