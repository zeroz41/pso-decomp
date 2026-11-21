#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/object/door/TObjDoor.h"
#include "types.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/task/TObject.h"

struct BmlResource;
struct GinjaTextureList;
struct AnimationMotion;

struct Node_8018E358 { s32 pad0; void *f4; };
// The five door models load_resources takes from the door BML (models 4, 3, 0, 1, 2).
struct DoorModelSet { saddr f0; s32 f4; Node_8018E358 *c; Node_8018E358 *a; Node_8018E358 *b; };
struct Door_8018E358 { u8 pad0[0x38]; u8 f38[0x28]; s32 f60; u8 pad64[0x50]; f32 fB4; };

struct DoorMotionHeader;

struct Door_8018E40C { u8 pad0[0x38]; u8 f38[0x28]; s32 f60; u8 pad64[0x50]; f32 fB4; u8 padB8[0xC]; f32 fC4; u8 padC8[8]; s32 fD0; };


struct Door_8018E5F4 { u8 pad0[0x38]; u8 f38[0x28]; s32 f60; u8 pad64[0x50]; f32 fB4; u8 padB8[0xC]; f32 fC4; u8 padC8[8]; s32 fD0; };


struct Door_8018E74C { u8 pad0[0x38]; u8 f38[0x28]; s32 f60; u8 pad64[0x50]; f32 fB4; f32 fB8; u8 padBC[0x8]; f32 fC4; u8 padC8[8]; s32 fD0; };

struct Door_8018F15C;
struct Door_8018F15C {
    const char *name;
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
void post_translate_matrix(void *);
void draw_ginja_model_with_motion(int, int, void *, f32);
void TObjDoor__sub_8018E8BC(void);
void update_anim__8TObjDoorFPv(void *arg0);
f32 xyz_distance_squared(u8 *arg0, u8 *arg1);
s32 project_world_to_screen(int, void *, void *);
extern saddr camera_ctrl_instance;
s32 free_collision_body_parts(void *);
extern s32 __vt__8TObjDoor[];
extern void *tl_05;
void *TObjDoor__create(void *arg0);
extern GinjaTextureList *TObjDoor__resource_param;
extern BmlResource *door_resource_handle;
u8 *TObjDoorJung__ct(u8 *arg0, saddr arg1, saddr arg2);
void *TObjDoorJung__create(void *arg0);
void update_opening_glow__8TObjDoorFPv(u8 *arg0);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void render__8TObjDoorFPv(Door_8018E40C *arg0);
void draw_closed__8TObjDoorFPv(Door_8018E5F4 *arg0);
}
u8 *load_gvm_texture_file(saddr arg0);
extern "C" {

AnimationMotion *get_bml_motion(BmlResource *, s32);
void draw_locked__8TObjDoorFPv(Door_8018E74C *arg0);
void set_active_camera_pose(u8 *arg0, u8 *arg1);
s32 restore_player_cameras(void);
s32 activate_camera_mode(s32);
}
s32 check_player_door_proximity(saddr arg0, s32 arg1, f32 farg0);
extern "C" {
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
u8 is_current_floor_switch_set(s32 id);
extern s32 TObjDoor__data_805D5BC8;
s32 init_collision_body_parts(void *, void *, s32);
s32 __ct__14TObjCollidableFP7TObject(void *, void *);
void *TObjDoor__ct(void *arg0, void *arg1, void *arg2);
void draw_closed_glow__8TObjDoorFPv(TObjDoor* door);
struct DoorMotionHeader { void* rows; u32 frameCount; };

void TObjDoor__sub_8018E890(void);
void update_timer__8TObjDoorFPv(void *arg0);

extern "C" void update_locked_pulse__8TObjDoorFPv(TObjDoor *door);
extern "C" void draw_closing__8TObjDoorFPv(Door_8018E358 *arg0);
extern "C" void draw_model__8TObjDoorFPv(Door_8018E358 *arg0);
const char *fe_obj_doa_kanban_model_names[6] = {
    "fe_obj_doa_kanban.gj", "fs_obj_doa_shingo_omote.gj", "fs_obj_doa_shingo_ura.gj", "taiki_fe_obj_doa_laz_oya.gj",
    "taiki_fe_obj_doa_oya.gj", NULL,
};
const char *fe_obj_doa_kanban_motion_names[3] = {"fe_obj_doa_oya.njm", "taiki_fe_obj_doa_laz_oya.njm", NULL};
BmlResourceDescriptor door_resource_descriptor = {
    "fe_obj_doa_kanban.bml", fe_obj_doa_kanban_model_names, fe_obj_doa_kanban_motion_names, 5, 2,
};
CollisionBody TObjDoor__collision_desc = {{0.0f, 0.0f, 0.0f}, 10.0f, 40.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
/* label colour (a, r, g, b) per door id */
NJS_ARGB TObjDoor__label_color_table[10] = {
    { 1.0f, 0.8235294f, 0.09803922f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.09803922f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.8235294f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.8235294f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.09803922f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.5019608f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.5019608f, 0.8235294f },
    { 1.0f, 0.7058824f, 0.9019608f, 0.09803922f },
    { 1.0f, 0.8235294f, 0.09803922f, 0.39215687f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
};
const char *TObjDoor__name = "TObjDoor";

DoorMotionHeader *TObjDoor__motion_table[2];
DoorModelSet TObjDoor__model_resource_ptrs;

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

void draw_model__8TObjDoorFPv(Door_8018E358 *arg0) {
    TObjFish::set_global_param((saddr)TObjDoor__resource_param);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_model_with_motion(TObjDoor__model_resource_ptrs.f0, (int)TObjDoor__motion_table[0], &TObjDoor__model_resource_ptrs, arg0->fB4);
    TParticleCtrl::begin_effect_render();
    DoorModelSet *g1 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g1->a->f4)), 0xA);
    DoorModelSet *g2 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g2->b->f4)), 0xA);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void render__8TObjDoorFPv(Door_8018E40C *arg0) {
    TObjFish::set_global_param((saddr)TObjDoor__resource_param);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_model_with_motion(TObjDoor__model_resource_ptrs.f0, (int)TObjDoor__motion_table[0], &TObjDoor__model_resource_ptrs, arg0->fB4);
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    NJS_ARGB color = TObjDoor__label_color_table[arg0->fD0];
    color.a = arg0->fC4;
    set_constant_material(&color);
    DoorModelSet *g0 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g0->c->f4)), ((u16)arg0->fD0));
    draw_ginja_object(g0->c);
    model_render_flags = saved_model_render_flags;
    DoorModelSet *g1 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g1->a->f4)), 0xA);
    DoorModelSet *g2 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g2->b->f4)), 0xA);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void draw_closing__8TObjDoorFPv(Door_8018E358 *arg0) {
    TObjFish::set_global_param((saddr)TObjDoor__resource_param);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_model_with_motion(TObjDoor__model_resource_ptrs.f0, (int)TObjDoor__motion_table[0], &TObjDoor__model_resource_ptrs, arg0->fB4);
    TParticleCtrl::begin_effect_render();
    DoorModelSet *g1 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g1->a->f4)), 0xA);
    DoorModelSet *g2 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g2->b->f4)), 0xA);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void draw_closed__8TObjDoorFPv(Door_8018E5F4 *arg0) {
    TObjFish::set_global_param((saddr)TObjDoor__resource_param);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_object((void *)TObjDoor__model_resource_ptrs.f0);
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    NJS_ARGB color = TObjDoor__label_color_table[arg0->fD0];
    color.a = arg0->fC4;
    set_constant_material(&color);
    DoorModelSet *g0 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g0->c->f4)), ((u16)arg0->fD0));
    draw_ginja_object(g0->c);
    model_render_flags = saved_model_render_flags;
    DoorModelSet *g1 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g1->a->f4)), 0xA);
    DoorModelSet *g2 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g2->b->f4)), 0xA);
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

void draw_locked__8TObjDoorFPv(Door_8018E74C *arg0) {
    TObjFish::set_global_param((saddr)TObjDoor__resource_param);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_object((void *)TObjDoor__model_resource_ptrs.f0);
    TParticleCtrl::begin_effect_render();
    draw_ginja_model_with_motion(TObjDoor__model_resource_ptrs.f4, (int) TObjDoor__motion_table[1], &TObjDoor__model_resource_ptrs, arg0->fB8);
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    NJS_ARGB color = TObjDoor__label_color_table[arg0->fD0];
    color.a = arg0->fC4;
    set_constant_material(&color);
    DoorModelSet *g0 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g0->c->f4)), ((u16)arg0->fD0));
    draw_ginja_object(g0->c);
    model_render_flags = saved_model_render_flags;
    DoorModelSet *g1 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g1->a->f4)), 0xB);
    DoorModelSet *g2 = &TObjDoor__model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g2->b->f4)), 0xB);
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
    saddr arg0 = (saddr)this;
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

GinjaTextureList *TObjDoor__resource_param;
BmlResource *door_resource_handle;
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
            VecCopy((Vec *)target, &this->position);
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
        if(check_player_door_proximity((saddr)this, 0, (7e+01f))!=0) {
            this->frame=(0.0f);this->state=4;clear_player_status_flag(0, 1);
        }
        break;
    case 4:
        play_persistent_sound(0x49e08, (saddr)this, (uaddr)&this->position, 0, 0);
        this->frame+=(1.8f);
        if(this->frame>(TObjDoor__motion_table[0]->frameCount-1)) {
            this->frame=(TObjDoor__motion_table[0]->frameCount-1);this->state=5;
        }
        break;
    case 3:
        play_persistent_sound(0x49e08, (saddr)this, (uaddr)&this->position, 0, 0);
        this->frame-=1.8f;
        if(this->frame<0.0f) {this->frame=0.0f;this->state=2;}
        break;
    case 5:
        clear_player_status_flag(0, 1);
        if(check_player_door_proximity((saddr)this, 1, 100.0f)!=0) {this->state=3;set_indexed_flags(0, 1);}
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
        ((TObjCollidable *)self)->set_indexed_flags(0, 1);
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
}
TObjDoor::~TObjDoor() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}


#define d ((Door_8018F15C *)arg0)
void *TObjDoor__ct(void *arg0, void *arg1, void *arg2) {
    __ct__14TObjCollidableFP7TObject(arg0, arg1);
    d->vt = __vt__8TObjDoor;
    d->name = TObjDoor__name;
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
    init_collision_body_parts(d, &TObjDoor__collision_desc, 1);
    d->f30 |= 0x40000000;
    ((TObjPlayer *)d)->register_object_by_id();
    return d;
}

void *TObjDoor__create(void *arg0) {
    void *o = TObject::operator new(0xD4);
    if (o != NULL) {
        o = TObjDoor__ct(o, tl_05, arg0);
    }
    return o;
}
void TObjDoor::free_resources() {
    TObjPlayer::free_if_valid((saddr)TObjDoor__resource_param);
    TObjDoor__resource_param = NULL;
    if (door_resource_handle != NULL) {
        delete (BmlResource *)door_resource_handle;
        door_resource_handle = NULL;
    }
}

extern "C" const char lbl_80445588[] = "fe_obj_door.gvm";
void TObjDoor::load_resources() {
    s32 p = (saddr)new BmlResource(5, &door_resource_descriptor, 0, 0, NULL);
    door_resource_handle = (BmlResource *)p;
    TObjDoor__resource_param = (GinjaTextureList *)load_gvm_texture_file((saddr)lbl_80445588);
    TObjDoor__model_resource_ptrs.f0 = (saddr)get_bml_model((BmlResource *)door_resource_handle, 4);
    TObjDoor__model_resource_ptrs.f4 = (saddr)get_bml_model((BmlResource *)door_resource_handle, 3);
    TObjDoor__model_resource_ptrs.c = (Node_8018E358 *)get_bml_model((BmlResource *)door_resource_handle, 0);
    TObjDoor__model_resource_ptrs.a = (Node_8018E358 *)get_bml_model((BmlResource *)door_resource_handle, 1);
    TObjDoor__model_resource_ptrs.b = (Node_8018E358 *)get_bml_model((BmlResource *)door_resource_handle, 2);
    TObjDoor__motion_table[0] = (DoorMotionHeader *)get_bml_motion(door_resource_handle, 0);
    TObjDoor__motion_table[1] = (DoorMotionHeader *)get_bml_motion(door_resource_handle, 1);
}

void *TObjDoorJung__create(void *arg0) {
    void *o = TObject::operator new(0xD8);
    if (o != NULL) {
        o = TObjDoorJung__ct((u8 *)o, (saddr)tl_05, (saddr)arg0);
    }
    return o;
}

#pragma pop
