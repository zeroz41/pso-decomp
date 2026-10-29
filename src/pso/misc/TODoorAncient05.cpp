#include "types.h"
#include "pso/misc/TODoorAncient05_8015EE50.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TODoorAncient05.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/misc/TODoorAncient01.h"

struct Base1 { char pad[0x18]; };

struct VObj1 : Base1 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_object(void *child);
s32 draw_ginja_model_with_motion(s32, s32, f32);
extern u8 *door_ancient05_static_model_nodes;

s32 play_sound_effect(s32, void *, s32, s32);
extern u8 *TODoorAncient05__switch_texture_lists;

void *__nw__7TObjectFUl(int);

void TODoorAncient05::render() {
    u8 *arg0 = (u8 *)this;
    VObj1 *self = (VObj1 *)arg0;
    if ((self->m8(4e+02f, 2e+01f) != 0) && (((TUnk_804AFBF8 *)arg0)->is_in_view_depth(3e+01f) != 0)) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        if (((u32) this->m_bc != 0U) && (0.0f != this->m_b0)) {
            draw_ginja_model_with_motion(*(s32 *)&this->model, *(s32 *)&this->m_bc, this->m_b0);
        } else {
            draw_ginja_object((void *)door_ancient05_static_model_nodes);
            draw_ginja_object((void *)(door_ancient05_static_model_nodes + 0x38));
            TParticleCtrl::begin_effect_render();
            draw_ginja_object((void *)(door_ancient05_static_model_nodes + 0x70));
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

void TODoorAncient05::vfunc_17() {
    u8 *arg0 = (u8 *)this;
    if (this->m_d0 & 1) {
        this->texlist = (s32) *(s32 *)((s8 *)TODoorAncient05__switch_texture_lists + 4);
        if (((TUnk_804AFBF8 *)arg0)->is_any_player_within_radius_xz(1e+04f) != 1) {
            this->m_ac = 3;
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8);
            play_sound_effect(0x4004B708, (u8 *)&this->position, 0, 0);
        }
    } else {
        this->m_ac = 3;
        this->texlist = (s32) *(s32 *)((s8 *)TODoorAncient05__switch_texture_lists + 0);
        ((TObjCollidable *)arg0)->clear_player_status_flag((s32)NULL, 8);
        play_sound_effect(0x4004B708, (u8 *)&this->position, 0, 0);
    }
}

extern void *tl_05;

void TODoorAncient05::play_proximity_sound() {
    u8 *arg0 = (u8 *)this;
    if (this->m_d0 & 1) {
        this->texlist = (s32) *(s32 *)((s8 *)TODoorAncient05__switch_texture_lists + 4);
        if (((TUnk_804AFBF8 *)arg0)->is_any_player_within_radius_xz(4.9e+03f) == 1) {
            this->m_ac = 1;
            ((TObjCollidable *)arg0)->set_indexed_flags(0, 8);
            play_sound_effect(0x4004B708, (u8 *)&this->position, 0, 0);
        }
    } else {
        this->texlist = (s32) *(s32 *)((s8 *)TODoorAncient05__switch_texture_lists + 0);
    }
}

void *TODoorAncient05::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD4);
    if (o != NULL) {
        o = TODoorAncient05__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

}

struct RecoveredGlobal_8015F048_lbl_804B0F28 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8015F048___vt__15TODoorAncient05 {
    s32 value;
    u8 remaining[0x50];
};

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
void *__ct__13TUnk_804B0BB8FP7TObject(void *a0);
extern RecoveredGlobal_8015F048_lbl_804B0F28 TODoorAncient05__collision_body;
extern s32 __vt__15TODoorAncient05[];
extern s32 lbl_805D2F38;
extern void *door_ancient05_bml_resource;

u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void copy_model_node(u8 *arg0, u8 *arg1);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern u8 lbl_80440B10[];
extern u8 door_ancient_567_resource_descriptor[];

void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void mem_free(void *p);

void TODoorAncient05::reset() {
    if (door_ancient05_static_model_nodes != NULL) {
        mem_free(door_ancient05_static_model_nodes);
        door_ancient05_static_model_nodes = NULL;
    }
    if (TODoorAncient05__switch_texture_lists != NULL) {
        TObjPlayer::free_if_valid(*(s32 *)((s8 *)TODoorAncient05__switch_texture_lists + 4));
        if (TODoorAncient05__switch_texture_lists != NULL) {
            mem_free(TODoorAncient05__switch_texture_lists);
            TODoorAncient05__switch_texture_lists = NULL;
        }
    }
    if (door_ancient05_bml_resource != NULL) {
        TLobby__sub_8001FE7C(door_ancient05_bml_resource, 1);
        door_ancient05_bml_resource = NULL;
    }
}

#define G5918 (*(u8 **)&door_ancient05_bml_resource)
#define G591C (*(s32 **)&TODoorAncient05__switch_texture_lists)
#define G5920 (*(u8 **)&door_ancient05_static_model_nodes)
#define NODE(p, o) (*(u8 **)(p + (o)))
void TODoorAncient05::load_resources() {
    u8 *p;
    s32 *buf;
    p = (u8 *)::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 1, door_ancient_567_resource_descriptor, 0, 0, 0);
    }
    G5918 = p;
    buf = (s32 *)mem_alloc(8);
    G591C = buf;
    buf[0] = *(s32 *)(NODE(G5918, 0x42C) + 0xC);
    G591C[1] = (s32)load_gvm_texture_file((s32)lbl_80440B10);
    G5920 = (u8 *)mem_alloc(0xA8);
    if (G5918 != NULL && G5920 != NULL) {
        copy_model_node(G5920, NODE(NODE(G5918, 0x42C), 8));
        *(s32 *)(G5920 + 0x2C) = 0;
        *(s32 *)(G5920 + 0) |= 0x10;
        copy_model_node(G5920 + 0x38, NODE(NODE(NODE(G5918, 0x42C), 8), 0x2C));
        *(s32 *)(G5920 + 0x68) = 0;
        copy_model_node(G5920 + 0x70, NODE(NODE(NODE(NODE(G5918, 0x42C), 8), 0x2C), 0x30));
    }
}

void *__dt__15TODoorAncient05Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TODoorAncient05;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804B0BB8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8015F048_lbl_804B0F28_size[sizeof(RecoveredGlobal_8015F048_lbl_804B0F28) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8015F048___vt__15TODoorAncient05_size[sizeof(RecoveredGlobal_8015F048___vt__15TODoorAncient05) == 0x54 ? 1 : -1];
u8 *TODoorAncient05__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__13TUnk_804B0BB8FP7TObject((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8015F048___vt__15TODoorAncient05 *)&__vt__15TODoorAncient05).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2F38;
    ((TODoorAncient05 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&door_ancient05_bml_resource) + 0x42C)) + 8);
    ((TODoorAncient05 *)arg0)->texlist = (s32) *(*(s32 * *)&TODoorAncient05__switch_texture_lists);
    *(u8 **)((s8 *)arg0 + 0xBC) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&door_ancient05_bml_resource) + 0x430)) + 4));
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xBC)) + 4) - 1.0f);
    ((TODoorAncient05 *)arg0)->m_b8 = (f32) (*(f32 *)((s8 *)arg0 + 0xB4) / 3e+01f);
    init_collision_body_parts(arg0, &TODoorAncient05__collision_body.value, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TODoorAncient05 *)(arg0))->init_door_switch_binding();
    return arg0;
}

}
