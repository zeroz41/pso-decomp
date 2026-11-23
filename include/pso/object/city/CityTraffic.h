#ifndef PSO_OBJECT_CITY_CITYTRAFFIC_H
#define PSO_OBJECT_CITY_CITYTRAFFIC_H

#include "types.h"

struct AnimationMotion;
struct BmlResource;
struct NJS_TEXLIST;
struct NJS_OBJECT;

extern "C" {
extern BmlResource *city_common_model_archive;
extern NJS_TEXLIST *city_common_texture_list;
}

void free_buffer_pair_table(void);
NJS_OBJECT *get_city_common_model(s32 i);
AnimationMotion *get_city_common_motion(s32 i);
void measure_traffic_path_lengths(void);
s32 sample_aircar_path_position(s32 lane, void *pos, f32 frame);

#endif
