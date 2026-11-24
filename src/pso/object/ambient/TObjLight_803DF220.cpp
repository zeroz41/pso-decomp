#include "pso/system/TrailStrip.h"
#include "types.h"
#include "pso/object/ambient/TObjLight_803DF220.h"
#include "pso/player/TObjPlayer_803E21B8.h"
#include "pso/player/TObjPlayer_803E20B0.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/player/TObjPlayer.h"


#pragma scheduling off


typedef struct GXColor_803DF268 { u8 r, g, b, a; } GXColor_803DF268;



typedef union WGPipe_803DF5E4 {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe_803DF5E4;

s32 light_slot_mask_table[5] = { 1, 2, 4, 8, 16 };
extern s32 gx_chan_ctrl_light_mask;
extern "C" {
s32 GXLoadLightObjImm(void *, int);
struct TObjLightGxLightObjects { s32 value; u8 remaining[0x13C]; };
extern TObjLightGxLightObjects gx_light_objects;
void OSPanic(char *, s32, char *, ...);
void GXSetChanAmbColor(s32 chan, GXColor_803DF268 color);
void GXInitLightColor(void *, GXColor_803DF268);
s32 GXInitLightPos(void *, f32, f32, f32);
s32 GXInitLightDir(void *, f32, f32, f32);
extern const f32 light_position_distance;
void GXBegin(int, int, u16);


void TObjLight::assert_light_id(s32 idx) {
    if (idx < 0 || idx > 5) {
        OSPanic("gjLight.c", 0x12, "illegal Light ID.");
    }
}
}


void set_light_ambient_color(f32 r, f32 g, f32 b) {
    GXColor_803DF268 c;
    if (r >= 1.0f) {
        r = 1.0f;
    }
    if (g >= 1.0f) {
        g = 1.0f;
    }
    if (b >= 1.0f) {
        b = 1.0f;
    }
    c.r = (u8)(255.0f * r);
    c.g = (u8)(255.0f * g);
    c.b = (u8)(255.0f * b);
    c.a = 0xFF;
    GXSetChanAmbColor(4, c);
}

void submit_light0(s32 arg0, s32 arg1) {
    s32 var_r0;
    TObjLight::assert_light_id((s32)arg0);
    if (arg1 == 0) {
        var_r0 = gx_chan_ctrl_light_mask & ~*(s32 *)((s8 *)((u8 *)light_slot_mask_table + (arg0 * 4)) + 0);
    } else {
        var_r0 = gx_chan_ctrl_light_mask | *(s32 *)((s8 *)((u8 *)light_slot_mask_table + (arg0 * 4)) + 0);
    }
    gx_chan_ctrl_light_mask = var_r0;
}


void set_gx_light_color(s32 idx, f32 r, f32 g, f32 b) {
    GXColor_803DF268 c;
    TObjLight::assert_light_id(idx);
    c.r = (u8)(255.0f * r);
    c.g = (u8)(255.0f * g);
    c.b = (u8)(255.0f * b);
    c.a = 0xFF;
    GXInitLightColor((u8 *)&gx_light_objects + (idx << 6), c);
}


void init_distant_light(s32 idx, f32 x, f32 y, f32 z) {
    TObjLight::assert_light_id(idx);
    if (idx == 0) {
        GXInitLightPos((u8 *)&gx_light_objects + (idx << 6), light_position_distance * -x, light_position_distance * -y, light_position_distance * -z);
    } else {
        GXInitLightDir((u8 *)&gx_light_objects + (idx << 6), x, y, z);
    }
}

void load_gx_light_slot(s32 arg0) {
    TObjLight::assert_light_id((s32)arg0);
    GXLoadLightObjImm((void *) ((u8 *)&gx_light_objects.value + (arg0 << 6)), (int) (*(s32 *)((s8 *)((u8 *)light_slot_mask_table + (arg0 * 4)) + 0)));
}


void draw_trail_strip(void *vertices, s32 count, s32 mode) {
    setup_world_color_draw(mode);
    draw_untextured_trail_strip(vertices, count);
    reset_player_transform();
}

void reset_player_transform(void) {
    end_primitive_draw();
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern "C" {
static inline void GXPosition3f32_803DF5E4(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803DF5E4 *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803DF5E4 *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803DF5E4 *)0xCC008000).f32 = z;
}
static inline void GXColor1u32_803DF5E4(u32 c) {
    (*(volatile WGPipe_803DF5E4 *)0xCC008000).u32 = c;
}
}
void draw_untextured_trail_strip(void *vertices, int count) {
    s32 n;
    TrailStripVertex *v;
    u32 c;
    v = (TrailStripVertex *)vertices;
    n = (s32)count;
    GXBegin(0x98, 4, n);
    for (; n != 0; n--) {
        GXPosition3f32_803DF5E4(v->x, v->y, v->z);
        c = v->color;
        GXColor1u32_803DF5E4(((c & 0xFFFFFF) << 8) | ((c & 0xFF000000) >> 24));
        v++;
    }
}
#pragma pop


void setup_world_color_draw(s32 blended) {
    load_camera_view_matrix();
    if (blended != 0) {
        setup_blended_color_draw();
        return;
    }
    setup_opaque_color_draw();
}
