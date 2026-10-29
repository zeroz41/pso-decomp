#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOKeyAncient02.h"
#include "pso/misc/TOKeyAncient03.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct VBase18 { char pad[0x18]; };

struct VObj18 : VBase18 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual s32 m8(f32, f32); };

struct RecoveredGlobal_8016B5A4_lbl_80441A74 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_8016B5A4_lbl_804B2A7C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8016B6A4_lbl_804B2A8C { s32 value; u8 remaining[0x28]; };

struct RecoveredGlobal_8016B6A4___vt__14TOKeyAncient02 { s32 value; u8 remaining[0x6C]; };

struct Pkt_8016B84C { u8 code, words; u16 object, zero, reserved, switchId; u8 area, flags; };

extern "C" {
s32 is_split_screen();
void scale_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_model(s32 model);
extern s32 TOKeyAncient02__model_root;
extern void *TOKeyAncient02__texture_lists;
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 * load_gvm_texture_file(s32);
extern RecoveredGlobal_8016B5A4_lbl_80441A74 lbl_80441A74;
extern RecoveredGlobal_8016B5A4_lbl_804B2A7C bm_fs_obj_o_doorswitch01_resource_descriptor;
extern u32 TOKeyAncient02__model_archive;
s32 init_collision_body_parts(void *, void *, int);
void *__ct__5TOKeyFP7TObject(TOKey *arg0);
extern RecoveredGlobal_8016B6A4_lbl_804B2A8C key_ancient02_collision_body;
extern s32 __vt__14TOKeyAncient02[];
extern s32 TOKeyAncient02__class_name;
extern const f32 TOKeyAncient02__data_805DB70C;
extern const f32 lbl_805DB710;
extern const f32 lbl_805DB714;
u8 *TOKeyAncient02__ct(TOKeyAncient02 *arg0, s32 arg1, s32 arg2);
s32 get_current_floor();
extern s32 local_client_id;
extern const f32 lbl_805DB700;
extern const f32 lbl_805DB704;
extern const f32 lbl_805DB708;
void *__dt__14TOKeyAncient02Fv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void *__dt__5TOKeyFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
void mem_free(void *p);

void TOKeyAncient02::vfunc_25() {  }

extern void *tl_05;

void TOKeyAncient02::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    u8 *temp_r31_4;
    u8 *temp_r31_5;
    if (((VObj18*)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        temp_r31 = *(u8 * *)&this->model;
        push_matrix();
        post_translate_matrix(temp_r31 + 8);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
        temp_r31_2 = *(u8 **)((s8 *)temp_r31 + 0x2C);
        push_matrix();
        post_translate_matrix(temp_r31_2 + 8);
        scale_matrix_vec3(0, ((u8 *)&this->scale));
        TParticleCtrl::begin_effect_render();
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
        TParticleCtrl::end_effect_render();
        pop_matrix();
        temp_r31_3 = *(u8 **)((s8 *)temp_r31_2 + 0x30);
        push_matrix();
        post_translate_matrix(temp_r31_3 + 8);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
        pop_matrix();
        pop_matrix();
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)(*(s32 *)&TOKeyAncient02__texture_lists) + (*(s32 *)&this->is_on * 4))));
        TParticleCtrl::begin_effect_render();
        temp_r31_4 = (u8 *)((*(u8 * *)&TOKeyAncient02__model_root));
        push_matrix();
        post_translate_matrix(temp_r31_4 + 8);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_4 + 4)));
        temp_r31_5 = *(u8 **)((s8 *)temp_r31_4 + 0x2C);
        push_matrix();
        post_translate_matrix(temp_r31_5 + 8);
        rotate_matrix_y(0, this->m_ec);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_5 + 4)));
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TOKeyAncient02::update_switch_off() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)(arg0 + 0xE8) & 1) {
        *(f32 *)(arg0 + 0x6C) += lbl_805DB700;
        *(f32 *)(arg0 + 0x68) += lbl_805DB704;
        *(f32 *)(arg0 + 0x70) = *(f32 *)(arg0 + 0x68);
        if (lbl_805DB708 <= *(f32 *)(arg0 + 0x6C)) {
            *(s32 *)(arg0 + 0xE8) &= ~1;
        }
    } else {
        *(f32 *)(arg0 + 0x6C) -= lbl_805DB700;
        *(f32 *)(arg0 + 0x68) -= lbl_805DB704;
        *(f32 *)(arg0 + 0x70) = *(f32 *)(arg0 + 0x68);
        if (*(f32 *)(arg0 + 0x6C) <= TOKeyAncient02__data_805DB70C) {
            *(s32 *)(arg0 + 0xE8) |= 1;
        }
    }
    *(s32 *)(arg0 + 0xEC) += 0x222;
    this->submit_cursor_target();
}

void TOKeyAncient02::update_switch_on() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)(arg0 + 0xE8) & 1) {
        *(f32 *)(arg0 + 0x6C) += lbl_805DB700;
        *(f32 *)(arg0 + 0x68) += lbl_805DB704;
        *(f32 *)(arg0 + 0x70) = *(f32 *)(arg0 + 0x68);
        if (lbl_805DB708 <= *(f32 *)(arg0 + 0x6C)) {
            *(s32 *)(arg0 + 0xE8) &= ~1;
        }
    } else {
        *(f32 *)(arg0 + 0x6C) -= lbl_805DB700;
        *(f32 *)(arg0 + 0x68) -= lbl_805DB704;
        *(f32 *)(arg0 + 0x70) = *(f32 *)(arg0 + 0x68);
        if (*(f32 *)(arg0 + 0x6C) <= TOKeyAncient02__data_805DB70C) {
            *(s32 *)(arg0 + 0xE8) |= 1;
        }
    }
    *(s32 *)(arg0 + 0xEC) += 0x444;
    this->submit_cursor_target();
}

void *TOKeyAncient02::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xF0);
    if (o != NULL) {
        o = TOKeyAncient02__ct((TOKeyAncient02 *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOKeyAncient02::free_static() {
    if ((void *) TOKeyAncient02__texture_lists != NULL) {
        TObjPlayer::free_if_valid(*(s32 *)((s8 *)TOKeyAncient02__texture_lists + 4));
        if ((void *) TOKeyAncient02__texture_lists != NULL) {
            mem_free(TOKeyAncient02__texture_lists);
            TOKeyAncient02__texture_lists = NULL;
        }
    }
    if ((u32) TOKeyAncient02__model_archive != 0U) {
        TLobby__sub_8001FE7C((void*)TOKeyAncient02__model_archive, 1);
        TOKeyAncient02__model_archive = 0U;
    }
    TOKeyAncient02__model_root = 0;
}

typedef char RecoveredGlobal_8016B5A4_lbl_80441A74_size[sizeof(RecoveredGlobal_8016B5A4_lbl_80441A74) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_8016B5A4_lbl_804B2A7C_size[sizeof(RecoveredGlobal_8016B5A4_lbl_804B2A7C) == 0x10 ? 1 : -1];
void TOKeyAncient02::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_o_doorswitch01_resource_descriptor.value, 0, 0, 0));
    }
    (*(u8 * *)&TOKeyAncient02__model_archive) = (unsigned char *) ((void *) var_r0);
    (*(s32 *)&TOKeyAncient02__texture_lists) = (s32)mem_alloc((u32)((void *)8));
    *(s32 *)((s8 *)(*(s32 *)&TOKeyAncient02__texture_lists) + 0) = TObjFish__sub_8001EDB0((*(u8 * *)&TOKeyAncient02__model_archive), 0);
    *(u8 **)((s8 *)(*(s32 *)&TOKeyAncient02__texture_lists) + 4) = load_gvm_texture_file((s32) &lbl_80441A74.value);
    TOKeyAncient02__model_root = get_bml_model((*(u8 * *)&TOKeyAncient02__model_archive), 0);
}

void *__dt__14TOKeyAncient02Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TOKeyAncient02;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__5TOKeyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TOKeyAncient02__ct(TOKeyAncient02 *key_ancient02, s32 arg1, s32 arg2) {
    __ct__5TOKeyFP7TObject((key_ancient02));
    *(s32 **)((s8 *)key_ancient02 + 0x18) = &(*(RecoveredGlobal_8016B6A4___vt__14TOKeyAncient02 *)&__vt__14TOKeyAncient02).value;
    *(s32 *)((s8 *)key_ancient02 + 0) = (s32) TOKeyAncient02__class_name;
    ((TOKeyAncient02 *)(key_ancient02))->apply_object_set_data((void *)arg2);
    ((TOKey *)key_ancient02)->init_switch_id();
    key_ancient02->model = ((u8 *)get_bml_model((void *)((*(s32 *)&TOKeyAncient02__model_archive)), 1));
    key_ancient02->texlist = TObjFish__sub_8001EDB0((void *)((void *) ((*(s32 *)&TOKeyAncient02__model_archive))), 1);
    init_collision_body_parts(key_ancient02, &key_ancient02_collision_body.value, 1);
    ((TObjCollidable *)key_ancient02)->refresh_collision_body_centers();
    ((TObjPlayer *)key_ancient02)->register_object_by_id();
    key_ancient02->m_c0 = (f32) lbl_805DB710;
    *(f32 *)((s8 *)key_ancient02 + 0xC4) = (f32) (lbl_805DB714 + *(f32 *)((s8 *)(*(void **)((s8 *)key_ancient02->model + 4)) + 0x14));
    key_ancient02->m_e8 = 0;
    key_ancient02->m_ec = 0;
    if (((s32) key_ancient02->mode != 2) && ((s32) *(s32 *)((s8 *)key_ancient02 + 0x88) < 0)) {
        key_ancient02->mode = 1;
    } else {
        key_ancient02->mode = 0;
    }
    *(f32 *)((s8 *)key_ancient02 + 0x70) = (f32) TOKeyAncient02__data_805DB70C;
    key_ancient02->scale.y = (f32) TOKeyAncient02__data_805DB70C;
    key_ancient02->scale.x = (f32) TOKeyAncient02__data_805DB70C;
    return (u8 *)key_ancient02;
}

void TOKeyAncient03::vfunc_25() {  }
s32 TOKeyAncient03::is_confirm_pressed() {
    s32 temp_r0;
    s32 var_r31;
    s32 var_r3;
    var_r31 = 0;
    temp_r0 = this->mode;
    switch (temp_r0) {
    case 0:
        if (is_split_screen() == 1) {
            var_r3 = this->is_any_player_in_range();
        } else {
            var_r3 = this->is_local_player_in_range();
        }
        if (((s32) this->is_on == 1) || (var_r3 == 1)) {
            var_r31 = 1;
        }
        break;
    case 1:
        var_r31 = this->is_any_player_in_range();
        break;
    }
    return var_r31;
}
void TOKeyAncient03::send_switch_changed(s32 flags) {
    TOKeyAncient03 *self = this;
    Pkt_8016B84C pkt;
    ((G_SwitchStateChanged_6x05 *)(&pkt))->init();
    pkt.object = self->entity_id;
    pkt.zero = local_client_id;
    pkt.switchId = self->switch_id;
    pkt.area = get_current_floor();
    pkt.flags = flags;
    ((G_SwitchStateChanged_6x05 *)(&pkt))->send();
}

}
