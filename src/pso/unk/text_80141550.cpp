#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/enemy/TObjEneMe3Stelth_803DC82C.h"
#include "pso/player/TObjPlayer_803DC834.h"
#include "pso/system/MaterialAlphaCompare.h"
#include "pso/unk/text_80141550.h"
#include "pso/unk/text_80141A30.h"
#include "pso/render/depth_buffer.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct Stack_801415BC {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};

struct Cfg_80141604 { u32 a; u8 b; u8 c; u8 pad6[2]; u32 d; u8 e; u8 f; u8 pad_e[2]; u32 g; };

extern "C" {
extern s32 model_render_flags;
extern const f32 lbl_805DB150;
extern const f32 lbl_805DB154;
int GXSetCullMode(void*);

int TObjFish::set_cull_none() { return GXSetCullMode((void*)(0)); }
int TObjFish::set_cull_mode_front() { return GXSetCullMode((void*)(1)); }
int TObjFish::set_cull_back() { return GXSetCullMode((void*)(2)); }
}
void set_shadow_material_state(void) {
    Stack_801415BC stack;
    stack.spC = lbl_805DB150;
    stack.sp10 = lbl_805DB150;
    stack.sp14 = lbl_805DB150;
    stack.sp8 = lbl_805DB154;
    ((void (*)(void *, f32))set_constant_material)(&stack.sp8, lbl_805DB150);
    model_render_flags |= 0x400;
}
u32 saved_model_draw_color[8];
f32 lbl_8050BEE0[8];
f32 lbl_8050BF00[8];
u32 lbl_8050BF20[8];
u32 lbl_8050BF40[8];
f32 lbl_8050BF60[16];
u32 dragonfly_random_destination[16];
f32 player_feedback_light_color[4];
u32 photon_chair_color_vec4[4];
Cfg_80141604 depth_buffer_settings;
Cfg_80141604 depth_buffer_config_copy;
Cfg_80141604 saved_depth_alpha_scene_state;

void TObjPlayer::init_default_config() {
    depth_buffer_settings.a = 7;
    depth_buffer_settings.b = 1;
    depth_buffer_settings.c = 1;
    depth_buffer_settings.d = 1;
    depth_buffer_settings.e = 1;
    depth_buffer_settings.f = 0xBF;
    depth_buffer_settings.g = 1;
    ((TObjPlayer *)(&depth_buffer_config_copy))->copy_config(&depth_buffer_settings);
    ((TObjPlayer *)(&saved_depth_alpha_scene_state))->copy_config(&depth_buffer_settings);
}

struct RecoveredGlobal_80141860_lbl_8050C000 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_80141730_lbl_8050C028 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_80141788_lbl_8050C000 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_80141788_lbl_8050C028 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_801417B8_lbl_8050C000 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_801417B8_lbl_8050C028 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_801417E8_lbl_8050C028 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8014175C_lbl_8050C000 {
    s32 value;
    u8 remaining[0x24];
};

struct G_80141820 { u8 pad[0xd]; u8 scene; };

extern "C" {
void GXSetZMode(u8, s32, s32);
void GXSetZCompLoc(s32);
void TObjPlayer::copy_config(void* q) { *(u32*)((char*)this + 0x0) = *(u32*)((char*)q + 0x0); *(u8*)((char*)this + 0x4) = *(u8*)((char*)q + 0x4); *(u8*)((char*)this + 0x5) = *(u8*)((char*)q + 0x5); *(u32*)((char*)this + 0x8) = *(u32*)((char*)q + 0x8); *(u8*)((char*)this + 0xc) = *(u8*)((char*)q + 0xc); *(u8*)((char*)this + 0xd) = *(u8*)((char*)q + 0xd); *(u32*)((char*)this + 0x10) = *(u32*)((char*)q + 0x10); }
void TObjPlayer__sub_801416AC(void) {
    depth_buffer_settings.a = 7;
    depth_buffer_settings.b = 1;
    depth_buffer_settings.c = 1;
    depth_buffer_settings.d = 1;
    depth_buffer_settings.e = 1;
    depth_buffer_settings.f = 0xBF;
    depth_buffer_settings.g = 1;
    ((TObjPlayer *)(&depth_buffer_config_copy))->copy_config(&depth_buffer_settings);
    ((TObjPlayer *)(&saved_depth_alpha_scene_state))->copy_config(&depth_buffer_settings);
    TObjPlayer::set_global_state((s32)((void *)restore_saved_depth_alpha_state));
    set_ginja_draw_end_callback((s32)restore_saved_depth_alpha_state);
}
typedef char RecoveredGlobal_80141860_lbl_8050C000_size[sizeof(RecoveredGlobal_80141860_lbl_8050C000) == 0x28 ? 1 : -1];

typedef char RecoveredGlobal_80141730_lbl_8050C028_size[sizeof(RecoveredGlobal_80141730_lbl_8050C028) == 0x18 ? 1 : -1];
}

void restore_draw_list_mask() {
    set_ginja_draw_list_mask((*(s32 *)((s8 *)(&(*(RecoveredGlobal_80141730_lbl_8050C028 *)&saved_depth_alpha_scene_state).value) + 0x10)));
}

extern "C" {

typedef char RecoveredGlobal_80141788_lbl_8050C000_size[sizeof(RecoveredGlobal_80141788_lbl_8050C000) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_80141788_lbl_8050C028_size[sizeof(RecoveredGlobal_80141788_lbl_8050C028) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8014175C_lbl_8050C000_size[sizeof(RecoveredGlobal_8014175C_lbl_8050C000) == 0x28 ? 1 : -1];
}
void set_depth_buffer_settings_id(u32 arg0) {
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8014175C_lbl_8050C000 *)&(*(RecoveredGlobal_80141860_lbl_8050C000 *)&depth_buffer_settings)).value) + 0x10) = arg0;
    set_ginja_draw_list_mask(arg0);
}
void restore_depth_buffer_settings(void) {
    ((TObjPlayer *)(&(*(RecoveredGlobal_80141788_lbl_8050C000 *)&(*(RecoveredGlobal_80141860_lbl_8050C000 *)&depth_buffer_settings)).value))->copy_config((void*)((void *) (&(*(RecoveredGlobal_80141788_lbl_8050C028 *)&(*(RecoveredGlobal_80141730_lbl_8050C028 *)&saved_depth_alpha_scene_state)).value)));
}

typedef char RecoveredGlobal_801417B8_lbl_8050C000_size[sizeof(RecoveredGlobal_801417B8_lbl_8050C000) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_801417B8_lbl_8050C028_size[sizeof(RecoveredGlobal_801417B8_lbl_8050C028) == 0x18 ? 1 : -1];
void save_depth_buffer_settings(void) {
    ((TObjPlayer *)(&(*(RecoveredGlobal_801417B8_lbl_8050C028 *)&(*(RecoveredGlobal_80141730_lbl_8050C028 *)&saved_depth_alpha_scene_state)).value))->copy_config((void*)((void *) (&(*(RecoveredGlobal_801417B8_lbl_8050C000 *)&(*(RecoveredGlobal_80141860_lbl_8050C000 *)&depth_buffer_settings)).value)));
}
typedef char RecoveredGlobal_801417E8_lbl_8050C028_size[sizeof(RecoveredGlobal_801417E8_lbl_8050C028) == 0x18 ? 1 : -1];
void restore_default_scene(void) {
    model_render_flags &= 0xFFFFFFFE;
    set_material_alpha_compare_reference((s32)((int) ((s32) *(u8 *)((s8 *)(&(*(RecoveredGlobal_801417E8_lbl_8050C028 *)&(*(RecoveredGlobal_80141730_lbl_8050C028 *)&saved_depth_alpha_scene_state)).value) + 0xD))));
}

void set_scene_override(u8 scene) {
    model_render_flags |= 1;
    (*(G_80141820 *)&(*(RecoveredGlobal_80141860_lbl_8050C000 *)&depth_buffer_settings)).scene = scene;
    set_material_alpha_compare_reference(scene);
}
void set_depth_buffer_settings_2(void) {
    *(s8 *)((s8 *)(&(*(RecoveredGlobal_80141860_lbl_8050C000 *)&depth_buffer_settings).value) + 4) = 0;
    *(s8 *)((s8 *)(&(*(RecoveredGlobal_80141860_lbl_8050C000 *)&depth_buffer_settings).value) + 5) = 1;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_80141860_lbl_8050C000 *)&depth_buffer_settings).value) + 8) = 7;
    *(s8 *)((s8 *)(&(*(RecoveredGlobal_80141860_lbl_8050C000 *)&depth_buffer_settings).value) + 0xC) = 0;
    *(s8 *)((s8 *)(&(*(RecoveredGlobal_80141860_lbl_8050C000 *)&depth_buffer_settings).value) + 0xD) = 0;
    GXSetZCompLoc(0);
    GXSetZMode(1U, 7, 0);
    set_material_alpha_compare_reference(0);
}
