#include "pso/object/city/CityTrafficTables.h"

// .rodata 0x80443B18-0x80443B68, between TObjChip and CityTraffic: CityTraffic.cpp
// addresses each table on its own (no shared .rodata base), so it did not compile them itself.

const s32 city_traffic_path_motion_index_table[5] = {0, 1, 2, 3, 4};
const s32 city_aircar_model_indices[5] = {15, 16, 17, 18, 19};
const s32 city_air_car_model_index_table[5] = {4, 2, 5, 6, 7};
const s32 city_traffic_car_chunk_index_table[5] = {0, 1, 2, 3, 4};
