#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/misc/TODoorAncient09.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_8016BF68_lbl_80441B4C {
    s32 value;
    u8 remaining[0x8C];
};

struct RecoveredGlobal_8016C010_lbl_80441B4C {
    s32 value;
    u8 remaining[0x8C];
};

struct Node_80160BA8 {
    u8 pad0[4];
    void *model;
    u8 pos[0x24];
    Node_80160BA8 *x2c;
    Node_80160BA8 *x30;
};

struct Door_80160BA8 {
    u8 pad0[0x34];
    Node_80160BA8 *root;
    u8 pos[0x28];
    s32 x60;
    u8 pad64[0xC8 - 0x64];
    s32 xC8;
    u32 padCC;
    s32 xD0;
    u16 xD4;
};

extern "C" {
u8 is_current_floor_switch_set(int);
u8 *load_resource_from_descriptor(void *, s32, BmlResourceDescriptor *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern const char lbl_80440CEC[];
extern BmlResourceDescriptor ancient_door09_resource_descriptor;
extern u32 door_ancient09_bml_resource;
extern void *TODoorAncient09__texture_lists;
s32 play_sound_effect(s32, void *, s32, s32);
s32 is_any_player_within_radius_xz(u8 *self, f32 radius);

s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_model(s32 model);
struct TODoor9Base_801608B4 { char pad[0x14]; void **vtbl; };
struct TODoor9VObj_801608B4 : TODoor9Base_801608B4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

void *__dt__15TODoorAncient09Fv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
u8 *TODoorAncient09__ct(TODoorAncient09 *arg0, s32 arg1, s32 arg2);
s32 draw_ginja_model_with_motion(s32, s32, f32);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void mem_free(void *p);
s32 get_main_phase();
s32 is_split_screen();

void TODoorAncient09::vfunc_6(s16 *arg1, s32) {
    if ((s16) *arg1 == 1) {
        this->m_d0 = (s32) (this->m_d0 | 1);
    }
}

s32 TODoorAncient09::init_door_switch_binding() {
    s32 temp_r0;

    *(s32 *)&this->unk_C8 = (s32) this->set_params[0];
    temp_r0 = *(s32 *)&this->unk_C8;
    if (temp_r0 > 0x100) {
        this->m_cc = 0;
    } else if (temp_r0 < 0) {
        this->m_cc = 1;
    } else if (((s32) this->set_params[2] < 0) && ((get_main_phase() == 0xF) || (is_split_screen() == 1))) {
        this->m_cc = 3;
    } else {
        this->m_cc = 2;
    }
    return *(s32 *)&this->unk_C8;
}

#define VCALL_m8(obj) (((TODoor9VObj_801608B4*)(obj))->m8((*(f32 *)(obj + 0xC0)), (*(f32 *)(obj + 0xC4))))

void TODoorAncient09::sub_80160968() {
    u8 *arg0 = (u8 *)this;
    if (!(*(s32 *)(arg0 + 0xD0) & 1)) {
        switch ((u32)get_current_area()) {
        case 0:
            play_sound_effect(0x42A04, (u8 *)&this->position, 0, 0);
            break;
        case 1:
        case 2:
            play_sound_effect(0x4BC07, (u8 *)&this->position, 0, 0);
            break;
        case 3:
        case 4:
        case 5:
            play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
            break;
        case 6:
        case 7:
            play_sound_effect(0x4004BC00, (u8 *)&this->position, 0, 0);
            break;
        case 8:
        case 9:
        case 10:
            play_sound_effect(0x4004BC07, (u8 *)&this->position, 0, 0);
            break;
        case 15:
            break;
        }
    }
}

#pragma push
#pragma fp_contract on
void TODoorAncient09::update_door_switch_state() {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    s32 cc;
    cc = this->m_cc;
    switch (cc) {
    case 1:
        ((TODoorAncient09 *)arg0)->sub_80160968();
        this->m_d0 = (s32) (this->m_d0 | 1);
        return;
    case 2:
        if ((is_current_floor_switch_set((int) ((u16) *(s32 *)&this->unk_C8)) == 1) && (is_current_floor_switch_set(this->m_d4) == 1)) {
            ((TODoorAncient09 *)arg0)->sub_80160968();
            this->m_d0 = (s32) (this->m_d0 | 1);
            *(s32 *)&this->m_d8 = 1;
            return;
        }
        this->m_d0 = (s32) (this->m_d0 & 0xFFFFFFFE);
        *(s32 *)&this->m_d8 = 0;
        return;
    case 3:
        if ((is_current_floor_switch_set((int) ((u16) *(s32 *)&this->unk_C8)) == 1) && (is_current_floor_switch_set(this->m_d4) == 1)) {
            ((TODoorAncient09 *)arg0)->sub_80160968();
            this->m_d0 = (s32) (this->m_d0 | 1);
            if (((u32) *(u32 *)&this->set_entry != 0U) && (((TUnk_804AF8A0 *)arg0)->access_object_saved_state((void *) (&sp8), 1) != 0)) {
                sp8 = 1;
                ((TODoorAncient09 *)arg0)->door_ancient09_sync_state((void *) (&sp8));
                ((TUnk_804AF8A0 *)arg0)->access_object_saved_state((void *) (&sp8), 0);
            }
        }
        return;
    default:
        this->m_d0 = (s32) (this->m_d0 & 0xFFFFFFFE);
        break;
    }
}
#pragma pop

void TODoorAncient09::draw_model() {
    Door_80160BA8 *self = (Door_80160BA8 *)this;
    s32 on[2];
    Node_80160BA8 *pairs[2][2];
    Node_80160BA8 *root;
    u8 f;
    u8 g;
    Node_80160BA8 **pp;
    s32 i;
    f = 0;
    root = self->root;
    pairs[0][0] = root->x2c->x2c;
    pairs[0][1] = root->x2c->x2c->x30;
    pairs[1][0] = root->x2c->x30;
    pairs[1][1] = root->x2c->x30->x30;
    if (is_current_floor_switch_set((u16)self->xC8) != 0 || (self->xD0 & 1)) {
        f = 1;
    }
    on[0] = f;
    g = 0;
    if (is_current_floor_switch_set(self->xD4) != 0 || (self->xD0 & 1)) {
        g = 1;
    }
    on[1] = g;
    push_matrix();
    TObjFish::set_global_param(((s32 *)TODoorAncient09__texture_lists)[0]);
    post_translate_matrix(self->pos);
    post_translate_matrix(root->pos);
    rotate_matrix_y(0, self->x60);
    draw_ginja_model((s32)root->model);
    draw_ginja_model((s32)root->x2c->model);
    TParticleCtrl::begin_effect_render();
    for (i = 0; i < 2; i++) {
        if (on[i] != 0) {
            TObjFish::set_global_param(((s32 *)TODoorAncient09__texture_lists)[1]);
        } else {
            TObjFish::set_global_param(((s32 *)TODoorAncient09__texture_lists)[0]);
        }
        push_matrix();
        pp = pairs[i];
        post_translate_matrix(pp[0]->pos);
        draw_ginja_model((s32)pp[0]->model);
        pop_matrix();
        push_matrix();
        post_translate_matrix(pp[1]->pos);
        draw_ginja_model((s32)pp[1]->model);
        pop_matrix();
    }
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TODoorAncient09::render() {
    u8 *arg0 = (u8 *)this;

    if ((VCALL_m8(arg0) != 0) && (((TUnk_804AFBF8 *)arg0)->is_in_view_depth(3e+01f) != 0)) {
        switch (this->m_ac) {
        case 1:
        case 3:
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(this->texture_id);
            draw_ginja_model_with_motion(*(s32 *)&this->model, *(s32 *)&this->m_bc, this->m_b0);
            pop_matrix();
            return;
        case 2:
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(this->texture_id);
            draw_ginja_model_with_motion(*(s32 *)&this->model, *(s32 *)&this->m_bc, *(f32 *)&this->m_b4 - 1.0f);
            pop_matrix();
            return;
        case 0:
            draw_model();
            break;
        }
    }
}

void TODoorAncient09::vfunc_20() {  }

extern void *tl_05;

void TODoorAncient09::vfunc_17() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)(arg0 + 0xD0) & 1) {
        *(s32 *)(arg0 + 0x24) = ((s32 *)TODoorAncient09__texture_lists)[1];
        if (is_any_player_within_radius_xz(arg0, 1e+04f) == 1) {
            return;
        }
        *(s32 *)(arg0 + 0xAC) = 3;
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 8);
        *(s32 *)(arg0 + 0xE0) = 0;
        switch ((u32)get_current_area()) {
        case 3:
        case 4:
        case 5:
            play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
            break;
        case 6:
        case 7:
            play_sound_effect(0x4004BC01, (u8 *)&this->position, 0, 0);
            break;
        case 8:
        case 9:
        case 10:
            play_sound_effect(0x4004B708, (u8 *)&this->position, 0, 0);
            break;
        case 0:
        case 15:
            break;
        }
    } else {
        *(s32 *)(arg0 + 0xAC) = 3;
        *(s32 *)(arg0 + 0x24) = ((s32 *)TODoorAncient09__texture_lists)[0];
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 8);
        *(s32 *)(arg0 + 0xE0) = 0;
    }
}

void TODoorAncient09::play_proximity_sound() {
    u8 *arg0 = (u8 *)this;
    if ((*(s32 *)(arg0 + 0xD0) & 1) && is_any_player_within_radius_xz(arg0, 4.9e+03f) == 1) {
        *(s32 *)(arg0 + 0xAC) = 1;
        *(s32 *)(arg0 + 0x24) = ((s32 *)TODoorAncient09__texture_lists)[1];
        ((TUnk_804AF8A0 *)arg0)->set_indexed_flags(0, 8);
        *(s32 *)(arg0 + 0xE0) = 1;
        switch ((u32)get_current_area()) {
        case 3:
        case 4:
        case 5:
            play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
            break;
        case 6:
        case 7:
            play_sound_effect(0x4004BC01, (u8 *)&this->position, 0, 0);
            break;
        case 8:
        case 9:
        case 10:
            play_sound_effect(0x4004B708, (u8 *)&this->position, 0, 0);
            break;
        case 0:
        case 15:
            break;
        }
    }
}

void *TODoorAncient09::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE8);
    if (o != NULL) {
        o = TODoorAncient09__ct((TODoorAncient09 *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TODoorAncient09::free_rocks() {
    if ((void *) TODoorAncient09__texture_lists != NULL) {
        TObjPlayer::free_if_valid(*(s32 *)((s8 *)TODoorAncient09__texture_lists + 4));
        if ((void *) TODoorAncient09__texture_lists != NULL) {
            mem_free(TODoorAncient09__texture_lists);
            TODoorAncient09__texture_lists = NULL;
        }
    }
    if ((u32) door_ancient09_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)door_ancient09_bml_resource, 1);
        door_ancient09_bml_resource = 0U;
    }
}

extern s32 __vt__15TODoorAncient09[];

void TODoorAncient09::load_resources() {
    s32 *temp_r3_2;
    u8 *temp_r3;
    u8 *var_r0;
    temp_r3 = (u8 *)((int)::operator new(0x440));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(load_resource_from_descriptor(temp_r3, 1, &ancient_door09_resource_descriptor, 0, 0, 0));
    }
    (*(u8 * *)&door_ancient09_bml_resource) = var_r0;
    temp_r3_2 = (s32 *)(mem_alloc(8));
    (*(s32 * *)&TODoorAncient09__texture_lists) = temp_r3_2;
    *temp_r3_2 = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&door_ancient09_bml_resource) + 0x42C)) + 0xC);
    *(s32 *)((s8 *)(*(s32 * *)&TODoorAncient09__texture_lists) + 4) = (s32)load_gvm_texture_file((s32)lbl_80440CEC);
}
typedef char RecoveredGlobal_8016BF68_lbl_80441B4C_size[sizeof(RecoveredGlobal_8016BF68_lbl_80441B4C) == 0x90 ? 1 : -1];
typedef char RecoveredGlobal_8016C010_lbl_80441B4C_size[sizeof(RecoveredGlobal_8016C010_lbl_80441B4C) == 0x90 ? 1 : -1];

void *__dt__15TODoorAncient09Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TODoorAncient09;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B0BB8 *)arg0)->destroy_ancient_door_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/misc/TODoorAncient09.h"
#include "pso/misc/TODoorCave01.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801611CC_lbl_804B1248 {
    s32 value;
    u8 remaining[0x28];
};

extern "C" {

s32 init_collision_body_parts(void *, void *, int);
void *init_door_base(void *a0);
extern RecoveredGlobal_801611CC_lbl_804B1248 TODoorAncient09__collision_body_template;
extern s32 lbl_805D2F58;

typedef char RecoveredGlobal_801611CC_lbl_804B1248_size[sizeof(RecoveredGlobal_801611CC_lbl_804B1248) == 0x2C ? 1 : -1];
u8 *TODoorAncient09__ct(TODoorAncient09 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    init_door_base((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TODoorAncient09;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2F58;
    ((TODoorAncient09 *)(arg0))->apply_object_set_data((void *)arg2);
    arg0->texture_id = (s32) *(*(s32 **)&TODoorAncient09__texture_lists);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 **)&door_ancient09_bml_resource) + 0x42C)) + 8);
    *(u8 **)((s8 *)arg0 + 0xBC) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 **)&door_ancient09_bml_resource) + 0x430)) + 4));
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xBC)) + 4) - 1.0f);
    arg0->m_b8 = (f32) (*(f32 *)((s8 *)arg0 + 0xB4) / 3e+01f);
    init_collision_body_parts(arg0, &TODoorAncient09__collision_body_template.value, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    temp_r0 = arg0->set_params[0];
    if (temp_r0 < 0) {
        arg0->set_params[0] = 0;
    } else if (temp_r0 > 0xFE) {
        arg0->set_params[0] = 0xFE;
    }
    ((TODoorAncient09 *)(arg0))->init_door_switch_binding();
    arg0->m_d4 = (arg0->set_params[0] + 1);
    arg0->m_d8 = 0;
    arg0->m_dc = 0;
    arg0->m_e0 = 0;
    arg0->m_e4 = 0;
    return (u8 *)arg0;
}

}
