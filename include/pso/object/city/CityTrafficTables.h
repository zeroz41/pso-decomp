#ifndef PSO_OBJECT_CITY_CITYTRAFFICTABLES_H
#define PSO_OBJECT_CITY_CITYTRAFFICTABLES_H
#include "types.h"

// .rodata block, defined by CityTrafficTables.cpp: TObjCityAirCar_Car.cpp
// addresses each table on its own. One entry per traffic air car (5).
extern "C" {
extern const s32 city_traffic_path_motion_index_table[5];
extern const s32 city_aircar_model_indices[5];
extern const s32 city_air_car_model_index_table[5];
extern const s32 city_traffic_car_chunk_index_table[5];
}

#endif
