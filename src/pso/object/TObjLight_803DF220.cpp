


#include "types.h"
#include "pso/object/TObjLight_803DF220.h"
#include "pso/player/TObjPlayer_803E21B8.h"
#include "pso/unk/text_803E20B0.h"
#include "pso/object/TObjLight.h"
#include "pso/player/TObjPlayer.h"


#pragma scheduling off


struct RecoveredGlobal_803DF528_TObjLight__data_8058D528 {
    s32 value;
    u8 remaining[0x13C];
};


typedef struct GXColor_803DF268 { u8 r, g, b, a; } GXColor_803DF268;


#pragma scheduling off
typedef struct Vtx_803DF5E4 { f32 x, y, z; u32 color; } Vtx_803DF5E4;

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
extern RecoveredGlobal_803DF528_TObjLight__data_8058D528 TObjLight__gx_light_objects;
void OSPanic(char *, s32, char *, ...);
void GXSetChanAmbColor(s32 chan, GXColor_803DF268 color);
void GXInitLightColor(void *, GXColor_803DF268);
s32 GXInitLightPos(void *, f32, f32, f32);
s32 GXInitLightDir(void *, f32, f32, f32);
extern const f32 light_position_distance;
void GXBegin(int, int, u16);


void TObjLight::assert_light_id(s32 arg0) {
    if (arg0 < 0 || arg0 > 5) {
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


typedef char RecoveredGlobal_803DF528_TObjLight__data_8058D528_size[sizeof(RecoveredGlobal_803DF528_TObjLight__data_8058D528) == 0x140 ? 1 : -1];

#pragma push
#pragma scheduling off
void set_gx_light_color(s32 idx, f32 r, f32 g, f32 b) {
    GXColor_803DF268 c;
    TObjLight::assert_light_id(idx);
    c.r = (u8)(255.0f * r);
    c.g = (u8)(255.0f * g);
    c.b = (u8)(255.0f * b);
    c.a = 0xFF;
    GXInitLightColor((u8 *)&TObjLight__gx_light_objects + (idx << 6), c);
}
#pragma pop


#pragma push
#pragma scheduling off
void init_distant_light(s32 idx, f32 x, f32 y, f32 z) {
    TObjLight::assert_light_id(idx);
    if (idx == 0) {
        GXInitLightPos((u8 *)&TObjLight__gx_light_objects + (idx << 6), light_position_distance * -x, light_position_distance * -y, light_position_distance * -z);
    } else {
        GXInitLightDir((u8 *)&TObjLight__gx_light_objects + (idx << 6), x, y, z);
    }
}
#pragma pop

void load_gx_light_slot(s32 arg0) {
    TObjLight::assert_light_id((s32)arg0);
    GXLoadLightObjImm((void *) ((u8 *)&TObjLight__gx_light_objects.value + (arg0 << 6)), (int) (*(s32 *)((s8 *)((u8 *)light_slot_mask_table + (arg0 * 4)) + 0)));
}


void TObjPlayer::draw_trail_strip(void *arg1, s32 arg2) {
    TObjPlayer__sub_803DF768(arg2);
    draw_untextured_trail_strip(this, arg1);
    reset_player_transform();
}

void reset_player_transform(void) {
    TObjPlayer__sub_803E2248();
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
void draw_untextured_trail_strip(void *arg0, void *arg1) {
    s32 n;
    Vtx_803DF5E4 *v;
    u32 c;
    v = (Vtx_803DF5E4 *)arg0;
    n = (s32)arg1;
    GXBegin(0x98, 4, n);
    for (; n != 0; n--) {
        GXPosition3f32_803DF5E4(v->x, v->y, v->z);
        c = v->color;
        GXColor1u32_803DF5E4(((c & 0xFFFFFF) << 8) | ((c & 0xFF000000) >> 24));
        v++;
    }
}
#pragma pop


void TObjPlayer__sub_803DF768(s32 arg0) {
    load_camera_view_matrix();
    if (arg0 != 0) {
        TObjPlayer__sub_803E21DC();
        return;
    }
    setup_opaque_color_draw();
}
