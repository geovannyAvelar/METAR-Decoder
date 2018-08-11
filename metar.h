#ifndef METAR_H
#define METAR_H

struct Metar {
    char * icao_code;
    long int timestamp;
    int wind_direction;
    int wind_speed;
    int visibility;
    int temperature;
    int dew_point;
    int pressure;
} Metar;

#endif // METAR_H
