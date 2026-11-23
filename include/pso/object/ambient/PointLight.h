#ifndef PSO_OBJECT_AMBIENT_POINTLIGHT_H
#define PSO_OBJECT_AMBIENT_POINTLIGHT_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// One of the three point lights TObjLight::alloc_light_slot hands out (GX lights 2..4); the laser
// light bosses move it along their beam and fade its range in and out.
struct PointLight {
    s32 light_id;   // 0x00: GX light id from light_type_id_table
    u8 pad_4[0x4];
    Vec position;   // 0x08
    f32 range[2];   // 0x14: 5.0 / 30.0 when allocated
    u8 pad_1C[0x4];
    f32 color[3];   // 0x20: r, g, b
    PointLight(s32 index);
    // Empty on GameCube: the constructor calls them after setting the colour, range and position.
    void apply_color();
    void set_color(f32 *argb);
    void disable();
    void enable();
    void set_range(f32 *range);
    void apply_range();
    void apply_position();
    void set_position(Vec *position);
    void unregister_and_free();
};

LAYOUT_ASSERT(PointLight_size, sizeof(PointLight) == 0x2C);

void copy_light_range(f32 *dst, f32 *src);

#endif
