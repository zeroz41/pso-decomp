#ifndef PSO_OBJECT_CITY_CITYTRAFFIC_H
#define PSO_OBJECT_CITY_CITYTRAFFIC_H

#include "types.h"

void free_buffer_pair_table(void);
s32 get_city_common_model(s32 i);
extern "C" {
s32 get_city_common_motion(s32 i);
}
void measure_traffic_path_lengths(void);
s32 sample_aircar_path_position(s32 arg0, void *arg1, f32 farg0);

#endif
