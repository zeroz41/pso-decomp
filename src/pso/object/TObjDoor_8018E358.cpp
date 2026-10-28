#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/vector.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjDoor.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Node_8018E358 { s32 pad0; void *f4; };
struct Glob_8018E358 { s32 f0; s32 pad4; s32 pad8; Node_8018E358 *a; Node_8018E358 *b; };
struct Door_8018E358 { u8 pad0[0x38]; u8 f38[0x28]; s32 f60; u8 pad64[0x50]; f32 fB4; };

struct DoorMotionHeader;
struct Color_8018E40C { f32 a; f32 r; f32 g; f32 b; };

struct Node_8018E40C { s32 pad0; void *f4; };

struct Glob_8018E40C { s32 f0; s32 pad4; Node_8018E40C *c; Node_8018E40C *a; Node_8018E40C *b; };

struct Door_8018E40C { u8 pad0[0x38]; u8 f38[0x28]; s32 f60; u8 pad64[0x50]; f32 fB4; u8 padB8[0xC]; f32 fC4; u8 padC8[8]; s32 fD0; };

struct Color_8018E5F4 { f32 a; f32 r; f32 g; f32 b; };

struct Node_8018E5F4 { s32 pad0; void *f4; };

struct Glob_8018E5F4 { s32 f0; s32 pad4; Node_8018E5F4 *c; Node_8018E5F4 *a; Node_8018E5F4 *b; };

struct Door_8018E5F4 { u8 pad0[0x38]; u8 f38[0x28]; s32 f60; u8 pad64[0x50]; f32 fB4; u8 padB8[0xC]; f32 fC4; u8 padC8[8]; s32 fD0; };

struct Color_8018E74C { f32 a; f32 r; f32 g; f32 b; };

struct Node_8018E74C { s32 pad0; void *f4; };

struct Glob_8018E74C { s32 f0; s32 f4; Node_8018E74C *c; Node_8018E74C *a; Node_8018E74C *b; };

struct Door_8018E74C { u8 pad0[0x38]; u8 f38[0x28]; s32 f60; u8 pad64[0x50]; f32 fB4; f32 fB8; u8 padBC[0x8]; f32 fC4; u8 padC8[8]; s32 fD0; };

struct Door_8018F15C;
struct Door_8018F15C {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u8 pad1c[0x30 - 0x1C];
    u32 f30;
    u8 pad34[0x84 - 0x34];
    u32 f84;
    u8 pad88[4];
    s32 f8C;
    u8 pad90[0xAC - 0x90];
    s32 fAC;
    s32 fB0;
    f32 fB4;
    f32 fB8;
    s8 fBC;
    u8 padbd[3];
    s32 fC0;
    f32 fC4;
    s32 fC8;
    s32 fCC;
    s32 fD0;
};

extern "C" {
void rotate_matrix_y(int, int);
void push_matrix();
s32 pop_matrix(void);
void post_translate_matrix(void *);
void draw_ginja_object(void *);
void draw_ginja_model_with_motion(int, int, void *, f32);
extern Glob_8018E358 TObjDoor__model_resource_ptrs[];
void TObjDoor__sub_8018E8BC(void);
f32 sin_table_lookup(s32);
void update_anim__8TObjDoorFPv(void *arg0);
f32 xyz_distance_squared(u8 *arg0, u8 *arg1);
s32 project_world_to_screen(int, void *, void *);
extern s32 camera_ctrl_instance;
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
extern s32 __vt__8TObjDoor[];
void *__dt__8TObjDoorFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
extern void *tl_05;
void *TObjDoor__create(void *arg0);
void TLobby__sub_8001FE7C(void*, int);
extern s32 TObjDoor__resource_param;
extern u32 door_resource_handle;
u8 *TObjDoorJung__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjDoorJung__create(void *arg0);
void update_opening_glow__8TObjDoorFPv(u8 *arg0);
extern DoorMotionHeader* TObjDoor__motion_table[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void render__8TObjDoorFPv(Door_8018E40C *arg0);
s32 draw_closed__8TObjDoorFPv(Door_8018E5F4 *arg0);
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
u8 *load_gvm_texture_file(s32 arg0);
s32 get_bml_model(s32, s32);
s32 get_bml_motion(s32, s32);
s32 draw_locked__8TObjDoorFPv(Door_8018E74C *arg0);
void set_active_camera_pose(u8 *arg0, u8 *arg1);
s32 restore_player_cameras(void);
s32 activate_camera_mode(s32);
}
s32 check_player_door_proximity(s32 arg0, s32 arg1, f32 farg0);
extern "C" {
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
u8 is_current_floor_switch_set(u16);
extern s32 TObjDoor__data_805D5BC8;
s32 init_collision_body_parts(void *, void *, s32);
s32 __ct__13TUnk_804AF8A0FP7TObject(void *, void *);
extern s32 TObjDoor__name;
void *TObjDoor__ct(void *arg0, void *arg1, void *arg2);
void draw_closed_glow__8TObjDoorFPv(TObjDoor* door);
struct DoorMotionHeader { void* rows; u32 frameCount; };

void TObjDoor__sub_8018E890(void);
void update_timer__8TObjDoorFPv(void *arg0);

extern "C" void update_locked_pulse__8TObjDoorFPv(TObjDoor *door);
extern "C" void draw_closing__8TObjDoorFPv(Door_8018E358 *arg0);
extern "C" void draw_model__8TObjDoorFPv(Door_8018E358 *arg0);
extern "C" u8 lbl_804454A0[];
extern "C" u8 lbl_804454B8[];
extern "C" u8 lbl_804454D4[];
extern "C" u8 lbl_804454F0[];
extern "C" u8 lbl_8044550C[];
extern "C" u8 lbl_80445524[];
extern "C" u8 lbl_80445538[];
extern "C" u8 lbl_80445558[];
extern void *fe_obj_doa_kanban_model_names[6];
extern void *fe_obj_doa_kanban_motion_names[3];
void *fe_obj_doa_kanban_model_names[6] = {
    (void *)&lbl_804454A0, (void *)&lbl_804454B8, (void *)&lbl_804454D4, (void *)&lbl_804454F0,
    (void *)&lbl_8044550C, (void *)0x0,
};
void *fe_obj_doa_kanban_motion_names[3] = {
    (void *)&lbl_80445524, (void *)&lbl_80445538, (void *)0x0,
};
void *door_resource_descriptor[4] = {
    (void *)&lbl_80445558, (void *)&fe_obj_doa_kanban_model_names, (void *)&fe_obj_doa_kanban_motion_names, (void *)0x50002,
};
void *TObjDoor__collision_desc[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x42200000, (void *)0x1, (void *)0x10003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *TObjDoor__label_color_table[40] = {
    (void *)0x3f800000, (void *)0x3f52d2d3, (void *)0x3dc8c8c9, (void *)0x3dc8c8c9,
    (void *)0x3f800000, (void *)0x3dc8c8c9, (void *)0x3dc8c8c9, (void *)0x3f52d2d3,
    (void *)0x3f800000, (void *)0x3f52d2d3, (void *)0x3f52d2d3, (void *)0x3dc8c8c9,
    (void *)0x3f800000, (void *)0x3dc8c8c9, (void *)0x3f52d2d3, (void *)0x3f52d2d3,
    (void *)0x3f800000, (void *)0x3f52d2d3, (void *)0x3dc8c8c9, (void *)0x3f52d2d3,
    (void *)0x3f800000, (void *)0x3f52d2d3, (void *)0x3f008081, (void *)0x3dc8c8c9,
    (void *)0x3f800000, (void *)0x3dc8c8c9, (void *)0x3f008081, (void *)0x3f52d2d3,
    (void *)0x3f800000, (void *)0x3f34b4b5, (void *)0x3f66e6e7, (void *)0x3dc8c8c9,
    (void *)0x3f800000, (void *)0x3f52d2d3, (void *)0x3dc8c8c9, (void *)0x3ec8c8c9,
    (void *)0x3f800000, (void *)0x3f800000, (void *)0x3f800000, (void *)0x3f800000,
};
void *lbl_804B7718[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_locked_pulse__8TObjDoorFPv,
};
void *lbl_804B7724[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_anim__8TObjDoorFPv,
};
void *lbl_804B7730[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&draw_closed_glow__8TObjDoorFPv,
};
void *lbl_804B773C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TObjDoor__sub_8018E8BC,
};
void *lbl_804B7748[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_opening_glow__8TObjDoorFPv,
};
void *lbl_804B7754[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TObjDoor__sub_8018E890,
};
void *lbl_804B7760[18] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
void *lbl_804B77A8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&draw_locked__8TObjDoorFPv,
};
void *lbl_804B77B4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_timer__8TObjDoorFPv,
};
void *lbl_804B77C0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&draw_closed__8TObjDoorFPv,
};
void *lbl_804B77CC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&draw_closing__8TObjDoorFPv,
};
void *lbl_804B77D8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&render__8TObjDoorFPv,
};
void *lbl_804B77E4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&draw_model__8TObjDoorFPv,
};
void *lbl_804B77F0[18] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
#define door_resource_descriptor ((u8 *)door_resource_descriptor)
#define TObjDoor__collision_desc ((u8 *)TObjDoor__collision_desc)
#define TObjDoor__label_color_table ((Color_8018E40C *)TObjDoor__label_color_table)

void draw_model__8TObjDoorFPv(Door_8018E358 *arg0) {
    TObjFish::set_global_param(TObjDoor__resource_param);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_model_with_motion(TObjDoor__model_resource_ptrs->f0, (int)TObjDoor__motion_table[0], TObjDoor__model_resource_ptrs, arg0->fB4);
    TParticleCtrl::begin_effect_render();
    Glob_8018E358 *g1 = TObjDoor__model_resource_ptrs;
    ((TObjDoorJung *)(g1->a->f4))->free_children((void *)0xA);
    Glob_8018E358 *g2 = TObjDoor__model_resource_ptrs;
    ((TObjDoorJung *)(g2->b->f4))->free_children((void *)0xA);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void render__8TObjDoorFPv(Door_8018E40C *arg0) {
    TObjFish::set_global_param(TObjDoor__resource_param);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_model_with_motion(((Glob_8018E40C *)&TObjDoor__model_resource_ptrs)->f0, (int)((DoorMotionHeader * *)&TObjDoor__motion_table)[0], ((Glob_8018E40C *)&TObjDoor__model_resource_ptrs), arg0->fB4);
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    Color_8018E40C color = TObjDoor__label_color_table[arg0->fD0];
    color.a = arg0->fC4;
    set_constant_material((const NJS_ARGB *)(((f32 *)&color)));
    Glob_8018E40C *g0 = ((Glob_8018E40C *)&TObjDoor__model_resource_ptrs);
    ((TObjDoorJung *)(g0->c->f4))->free_children((void *)((u16)arg0->fD0));
    draw_ginja_object(g0->c);
    model_render_flags = saved_model_render_flags;
    Glob_8018E40C *g1 = ((Glob_8018E40C *)&TObjDoor__model_resource_ptrs);
    ((TObjDoorJung *)(g1->a->f4))->free_children((void *)0xA);
    Glob_8018E40C *g2 = ((Glob_8018E40C *)&TObjDoor__model_resource_ptrs);
    ((TObjDoorJung *)(g2->b->f4))->free_children((void *)0xA);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void draw_closing__8TObjDoorFPv(Door_8018E358 *arg0) {
    TObjFish::set_global_param(TObjDoor__resource_param);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_model_with_motion(TObjDoor__model_resource_ptrs->f0, (int)TObjDoor__motion_table[0], TObjDoor__model_resource_ptrs, arg0->fB4);
    TParticleCtrl::begin_effect_render();
    Glob_8018E358 *g1 = TObjDoor__model_resource_ptrs;
    ((TObjDoorJung *)(g1->a->f4))->free_children((void *)0xA);
    Glob_8018E358 *g2 = TObjDoor__model_resource_ptrs;
    ((TObjDoorJung *)(g2->b->f4))->free_children((void *)0xA);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

s32 draw_closed__8TObjDoorFPv(Door_8018E5F4 *arg0) {
    TObjFish::set_global_param(TObjDoor__resource_param);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_object((void *)((Glob_8018E5F4 *)&TObjDoor__model_resource_ptrs)->f0);
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    Color_8018E5F4 color = ((Color_8018E5F4 *)TObjDoor__label_color_table)[arg0->fD0];
    color.a = arg0->fC4;
    set_constant_material((const NJS_ARGB *)((&color)));
    Glob_8018E5F4 *g0 = ((Glob_8018E5F4 *)&TObjDoor__model_resource_ptrs);
    ((TObjDoorJung *)(g0->c->f4))->free_children((void *)((u16)arg0->fD0));
    draw_ginja_object(g0->c);
    model_render_flags = saved_model_render_flags;
    Glob_8018E5F4 *g1 = ((Glob_8018E5F4 *)&TObjDoor__model_resource_ptrs);
    ((TObjDoorJung *)(g1->a->f4))->free_children((void *)0xA);
    Glob_8018E5F4 *g2 = ((Glob_8018E5F4 *)&TObjDoor__model_resource_ptrs);
    ((TObjDoorJung *)(g2->b->f4))->free_children((void *)0xA);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void update_timer__8TObjDoorFPv(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0xC0) < 0x3C) {
        draw_closed__8TObjDoorFPv((Door_8018E5F4 *)(arg0));
        return;
    }
    draw_locked__8TObjDoorFPv((Door_8018E74C *)(arg0));
}

s32 draw_locked__8TObjDoorFPv(Door_8018E74C *arg0) {
    TObjFish::set_global_param(TObjDoor__resource_param);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_object((void *)((Glob_8018E74C *)&TObjDoor__model_resource_ptrs)->f0);
    TParticleCtrl::begin_effect_render();
    draw_ginja_model_with_motion(((Glob_8018E74C *)&TObjDoor__model_resource_ptrs)->f4, (int) ((DoorMotionHeader * *)&TObjDoor__motion_table)[1], TObjDoor__model_resource_ptrs, arg0->fB8);
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    Color_8018E74C color = ((Color_8018E74C *)TObjDoor__label_color_table)[arg0->fD0];
    color.a = arg0->fC4;
    set_constant_material((const NJS_ARGB *)((&color)));
    Glob_8018E74C *g0 = ((Glob_8018E74C *)&TObjDoor__model_resource_ptrs);
    ((TObjDoorJung *)(g0->c->f4))->free_children((void *)((u16)arg0->fD0));
    draw_ginja_object(g0->c);
    model_render_flags = saved_model_render_flags;
    Glob_8018E74C *g1 = ((Glob_8018E74C *)&TObjDoor__model_resource_ptrs);
    ((TObjDoorJung *)(g1->a->f4))->free_children((void *)0xB);
    Glob_8018E74C *g2 = ((Glob_8018E74C *)&TObjDoor__model_resource_ptrs);
    ((TObjDoorJung *)(g2->b->f4))->free_children((void *)0xB);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjDoor__sub_8018E890(void) {  }

#pragma push
#pragma opt_common_subs off
void update_opening_glow__8TObjDoorFPv(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) (*(f32 *)((s8 *)arg0 + 0xC4) - (0.05f));
    if (*(f32 *)((s8 *)arg0 + 0xC4) < (0.0f)) {
        *(f32 *)((s8 *)arg0 + 0xC4) = (f32) (0.0f);
    }
}
#pragma pop

void TObjDoor__sub_8018E8BC(void) {  }

void draw_closed_glow__8TObjDoorFPv(TObjDoor* door) {
    door->frame+=(1.5f);
    if(door->frame>(TObjDoor__motion_table[0]->frameCount-1))door->frame=(0.0f);
    door->glow+=0.05f;
    if(door->glow>0.5f)door->glow=0.5f;
}

#pragma push
#pragma fp_contract on
void update_anim__8TObjDoorFPv(void *arg0) {
    *(s32 *)((s8 *)arg0 + 0xC8) = (s32) (*(s32 *)((s8 *)arg0 + 0xC8) + 0x300);
    *(f32 *)((s8 *)arg0 + 0xC4) = (0.2f) * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0xC8)) + (0.4f);
}
void update_locked_pulse__8TObjDoorFPv(TObjDoor* door) {
    door->accentFrame+=(2.0f);
    if(door->accentFrame>(TObjDoor__motion_table[1]->frameCount-1))door->accentFrame=(0.0f);
    door->phase+=0x300;
    door->glow=(0.2f)*sin_table_lookup(door->phase)+(0.4f);
}

#pragma push
#pragma fp_contract on
s32 TObjDoor::is_visible(f32 farg0, f32 farg1) {
    s32 arg0 = (s32)this;
    f32 sp8;
    f32 temp_f1;
    temp_f1 = xyz_distance_squared((u8 *)(arg0 + 0x38), (u8 *)(camera_ctrl_instance + 0x178));
    if (temp_f1 > (farg0 * farg0)) {
        return 0;
    }
    if (temp_f1 < (farg1 * farg1)) {
        return 1;
    }
    project_world_to_screen(0, (void *)(arg0 + 0x38), (void *)&sp8);
    if ((-farg1 <= sp8) && (sp8 <= ((6.4e+02f) + farg1))) {
        return 1;
    }
    return 0;
}
#pragma pop

struct VBase_8018EAF8 { char pad[0x18]; };
struct VObj_8018EAF8 : VBase_8018EAF8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};
typedef void (VObj_8018EAF8::*Pmf_8018EAF8)();

s32 TObjDoor__resource_param;
u32 door_resource_handle;
s32 TObjDoor__data_805D5BC8;
static s8 door_run_task_init_done;
static s8 lbl_805D5BCD;
void render__8TObjDoorFv(VObj_8018EAF8 *self) {
    s32 saved;
    if (!lbl_805D5BCD) {
        ((Pmf_8018EAF8 *)lbl_804B77F0)[0] = *(Pmf_8018EAF8 *)lbl_804B77A8;
        ((Pmf_8018EAF8 *)lbl_804B77F0)[1] = *(Pmf_8018EAF8 *)lbl_804B77B4;
        ((Pmf_8018EAF8 *)lbl_804B77F0)[2] = *(Pmf_8018EAF8 *)lbl_804B77C0;
        ((Pmf_8018EAF8 *)lbl_804B77F0)[3] = *(Pmf_8018EAF8 *)lbl_804B77CC;
        ((Pmf_8018EAF8 *)lbl_804B77F0)[4] = *(Pmf_8018EAF8 *)lbl_804B77D8;
        ((Pmf_8018EAF8 *)lbl_804B77F0)[5] = *(Pmf_8018EAF8 *)lbl_804B77E4;
        lbl_805D5BCD = 1;
    }
    saved = ((TObjDoor *)self)->state;

    if (TObjDoor__data_805D5BC8 != 0) {
        ((TObjDoor *)self)->state = 0;
    }
    if (((TObjDoor *)self)->state == 0 || ((TObjDoor *)self)->state == 2) {
        if (((TObjDoor *)self)->is_visible((7e+02f), (2.5e+02f)) != 0) {
            (self->*((Pmf_8018EAF8 *)lbl_804B77F0)[((TObjDoor *)self)->state])();
        }
    } else if (self->m8((7e+02f), (2.5e+02f)) != 0) {
        (self->*((Pmf_8018EAF8 *)lbl_804B77F0)[((TObjDoor *)self)->state])();
    }
    if (TObjDoor__data_805D5BC8 != 0) {
        ((TObjDoor *)self)->state = saved;
    }
}

void TObjDoor::update_state() {
    f32 target[3],position[3];
    switch(this->state) {
    case 0:
        if(is_current_floor_switch_set((u16)this->switchId)==1) {
            if(TObjDoor__data_805D5BC8==0)this->accentFrame=(0.0f);
            if(this->cameraMode==0)this->state=2;
            else this->state=1;
        }
        set_indexed_flags(0, 1);return;
    case 1:
        if(this->cameraMode==1 && activate_camera_mode(9)!=0) {
            VecCopy((Vec *)target, (const Vec *)this->position);
            VecCopy((Vec *)position, (const Vec *)((f32 *)&this->scale));
            set_active_camera_pose((u8 *)position, (u8 *)target);this->cameraMode=2;
        }
        if(this->cameraMode==2) {
            s32 ticks=this->cameraTicks-1;this->cameraTicks=ticks;
            if(ticks==0) {restore_player_cameras();this->state=2;return;}
        }
        if(this->cameraTicks>60) {
            this->accentFrame+=(2.0f);
            if(this->accentFrame>(TObjDoor__motion_table[1]->frameCount-1))this->accentFrame=(0.0f);
        }
        return;
    case 2:
        set_indexed_flags(0, 1);
        if(check_player_door_proximity((s32)this, 0, (7e+01f))!=0) {
            this->frame=(0.0f);this->state=4;clear_player_status_flag(0, 1);
        }
        break;
    case 4:
        play_persistent_sound(0x49e08, (s32)this, (u32)this->position, 0, 0);
        this->frame+=(1.8f);
        if(this->frame>(TObjDoor__motion_table[0]->frameCount-1)) {
            this->frame=(TObjDoor__motion_table[0]->frameCount-1);this->state=5;
        }
        break;
    case 3:
        play_persistent_sound(0x49e08, (s32)this, (u32)this->position, 0, 0);
        this->frame-=1.8f;
        if(this->frame<0.0f) {this->frame=0.0f;this->state=2;}
        break;
    case 5:
        clear_player_status_flag(0, 1);
        if(check_player_door_proximity((s32)this, 1, 100.0f)!=0) {this->state=3;set_indexed_flags(0, 1);}
        break;
    }
}

struct VBase_8018EF70 { char pad[0x18]; };
struct VObj_8018EF70 : VBase_8018EF70 {
    virtual void m0();
};
typedef void (VObj_8018EF70::*Pmf_8018EF70)();
void minimap_render_gate(void *, u32, u16, int, int);

void run_task__8TObjDoorFv(VObj_8018EF70 *self) {
    s32 saved;
    if (!door_run_task_init_done) {
        ((Pmf_8018EF70 *)lbl_804B7760)[0] = *(Pmf_8018EF70 *)lbl_804B7718;
        ((Pmf_8018EF70 *)lbl_804B7760)[1] = *(Pmf_8018EF70 *)lbl_804B7724;
        ((Pmf_8018EF70 *)lbl_804B7760)[2] = *(Pmf_8018EF70 *)lbl_804B7730;
        ((Pmf_8018EF70 *)lbl_804B7760)[3] = *(Pmf_8018EF70 *)lbl_804B773C;
        ((Pmf_8018EF70 *)lbl_804B7760)[4] = *(Pmf_8018EF70 *)lbl_804B7748;
        ((Pmf_8018EF70 *)lbl_804B7760)[5] = *(Pmf_8018EF70 *)lbl_804B7754;
        door_run_task_init_done = 1;
    }
    saved = ((TObjDoor *)self)->state;

    if (TObjDoor__data_805D5BC8 != 0) {
        ((TObjDoor *)self)->state = 0;
        ((TUnk_804AF8A0 *)self)->set_indexed_flags(0, 1);
    } else {
        ((TObjDoor *)self)->update_state();
    }
    (self->*((Pmf_8018EF70 *)lbl_804B7760)[((TObjDoor *)self)->state])();
    if (((TObjDoor *)self)->state == 0) {
        minimap_render_gate((u8 *)self + 0x38, 0xFFFF0000, ((TObjDoor *)self)->rotation_y, 0, 0);
    } else {
        minimap_render_gate((u8 *)self + 0x38, 0xFF00FF00, ((TObjDoor *)self)->rotation_y, 0, 0);
    }
    if (TObjDoor__data_805D5BC8 != 0) {
        ((TObjDoor *)self)->state = saved;
    }
}
void *__dt__8TObjDoorFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__8TObjDoor;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define d ((Door_8018F15C *)arg0)
void *TObjDoor__ct(void *arg0, void *arg1, void *arg2) {
    __ct__13TUnk_804AF8A0FP7TObject(arg0, arg1);
    d->vt = __vt__8TObjDoor;
    d->f0 = TObjDoor__name;
    ((TObjPlayer *)d)->apply_object_set_data(arg2);
    d->fAC = 0;
    d->fB8 = (0.0f);
    d->fB4 = (0.0f);
    d->fB0 = 1;
    d->fBC = d->f8C % 2;
    d->fC0 = 0x50;
    d->fC4 = (0.0f);
    d->fC8 = 0;
    d->fCC = (u8)d->f84;
    d->fD0 = (u8)(d->f84 >> 8) % 10;
    if (d->fBC < 0) {
        d->fBC = 0;
    }
    if (d->fBC > 1) {
        d->fBC = 1;
    }
    init_collision_body_parts(d, TObjDoor__collision_desc, 1);
    d->f30 |= 0x40000000;
    ((TObjPlayer *)d)->reset_photon_effect();
    return d;
}

void *TObjDoor__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD4);
    if (o != NULL) {
        o = TObjDoor__ct(o, tl_05, arg0);
    }
    return o;
}
void TObjDoor::free_resources() {
    TObjPlayer::free_if_valid(TObjDoor__resource_param);
    TObjDoor__resource_param = 0;
    if ((u32) door_resource_handle != 0U) {
        TLobby__sub_8001FE7C((void*)door_resource_handle, 1);
        door_resource_handle = 0U;
    }
}

extern "C" const char lbl_80445588[] = "fe_obj_door.gvm";
void TObjDoor::load_resources() {
    s32 p = (int)::operator new(0x440);
    if (p != 0) {
        p = (s32)load_resource_from_descriptor((void *)p, 5, door_resource_descriptor, 0, 0, 0);
    }
    door_resource_handle = p;
    TObjDoor__resource_param = (s32)load_gvm_texture_file((s32)lbl_80445588);
    ((s32 *)&TObjDoor__model_resource_ptrs)[0] = get_bml_model(door_resource_handle, 4);
    ((s32 *)&TObjDoor__model_resource_ptrs)[1] = get_bml_model(door_resource_handle, 3);
    ((s32 *)&TObjDoor__model_resource_ptrs)[2] = get_bml_model(door_resource_handle, 0);
    ((s32 *)&TObjDoor__model_resource_ptrs)[3] = get_bml_model(door_resource_handle, 1);
    ((s32 *)&TObjDoor__model_resource_ptrs)[4] = get_bml_model(door_resource_handle, 2);
    ((s32 *)&TObjDoor__motion_table)[0] = get_bml_motion(door_resource_handle, 0);
    ((s32 *)&TObjDoor__motion_table)[1] = get_bml_motion(door_resource_handle, 1);
}

void *TObjDoorJung__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        o = TObjDoorJung__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}
}

#pragma pop
