#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/misc/TODoorAncient09.h"
#include "pso/misc/TODoorCave01.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TODoorCave01_80161A30.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TODoorAncient01.h"

struct State_80161320 { s16 a; s16 b; };

struct Pkt_80161320 { s16 hdr; u16 id; s32 state; s32 kind; };

struct Obj_80161320 { u8 pad[4]; s16 kind; };

struct Self_80161320 { u8 pad[0x1C]; u16 id; u8 pad1e[0x80 - 0x1E]; Obj_80161320 *obj; };

struct Door_801615C4 {
    u8 pad0[0x80];
    void *obj;
    u8 pad84[0xC8 - 0x84];
    s32 base;
    s32 state;
    u32 flags;
    s32 count;
    s32 num;
};

extern "C" {
s32 is_any_player_within_radius_xz(f32);
s32 play_sound_effect(s32, void *, s32, s32);
void update_and_send_60__6TLobbyFPv(void *);
u8 is_current_floor_switch_set(u16);
s32 get_main_phase();

void TODoorCave01::vfunc_20() {  }

void TODoorCave01::send_state(void *src_arg) {
    Self_80161320 *self = (Self_80161320 *)this;
    State_80161320 *src = (State_80161320 *)src_arg;
    State_80161320 st;
    Obj_80161320 *obj;
    if (src != 0) {
        ((TLobby *)(&st))->copy_short_fields(src);
    } else {
        ((TUnk_804AF8A0 *)self)->access_object_saved_state((void *)((s32)&st), (s16)1);
    }
    obj = *(Obj_80161320 * *)&this->set_entry;
    if (obj != 0) {
        Pkt_80161320 pkt;
        ((TOBarrierEnergy01 *)(&pkt))->init();
        pkt.id = this->entity_id;
        pkt.state = st.a;
        pkt.kind = obj->kind;
        update_and_send_60__6TLobbyFPv(&pkt);
    }
}

void TODoorCave01::vfunc_6(s16 *arg1, s32) {
    if ((s16) *arg1 == 1) {
        this->m_d0 = (s32) (this->m_d0 | 0xF0000 | 1);
    }
}

s32 TODoorCave01::init_door_switch_binding() {
    s32 temp_r0;

    *(s32 *)&this->unk_C8 = (s32) this->set_params[0];
    temp_r0 = *(s32 *)&this->unk_C8;
    if (temp_r0 > 0x100) {
        this->m_cc = 0;
    } else if (temp_r0 < 0) {
        this->m_cc = 1;
    } else if ((s32) this->set_params[2] < 0) {
        if ((get_main_phase() == 0xF) || (TRaderMapCore::is_not_split_screen() == 1)) {
            this->m_cc = 3;
        } else {
            this->m_cc = 2;
        }
    } else {
        this->m_cc = 2;
    }
    return *(s32 *)&this->unk_C8;
}

void TODoorCave01::vfunc_17() {
    u8 *arg0 = (u8 *)this;
    if (((u8) ((u32) __cntlzw(this->m_d0 & 1) >> 5) == 1) || (is_any_player_within_radius_xz(1e+04f) != 1)) {
        this->m_ac = 3;
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 8);
        play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
    }
}
void TODoorCave01::play_proximity_sound() {
    u8 *arg0 = (u8 *)this;
    if ((this->m_d0 & 1) && (is_any_player_within_radius_xz(4.9e+03f) == 1)) {
        this->m_ac = 1;
        ((TUnk_804AF8A0 *)arg0)->set_indexed_flags(0, 8);
        play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
    }
    if (this->m_d0 & 0x100000) {
        this->m_e0 += 0.1f;
        if (1.0f <= this->m_e0) {
            this->m_d0 = (s32) (this->m_d0 & 0xFFEFFFFF);
        }
    } else {
        this->m_e0 = (f32) (this->m_e0 - 0.1f);
        if (this->m_e0 <= 0.0f) {
            this->m_d0 = (s32) (this->m_d0 | 0x100000);
        }
    }
}

void TODoorCave01::update_door_switch_state() {
    u8 *arg0 = (u8 *)this;
    Door_801615C4 *d = (Door_801615C4 *)arg0;
    State_80161320 st;
    s32 i;

    switch (d->state) {
    case 1:
        ((TUnk_804B0BB8 *)arg0)->play_door_sound();
        d->flags |= 0xF0001;
        d->count = 4;
        break;
    case 2:
        d->flags &= 0xFFF0FFFF;
        d->count = 4 - d->num;
        for (i = 0; i < d->num; i++) {
            if (is_current_floor_switch_set(d->base + i) == 1) {
                d->count++;
            }
        }
        for (i = 0; i < d->count; i++) {
            d->flags |= 1 << (i + 0x10);
        }
        if (d->count == 4) {
            ((TUnk_804B0BB8 *)arg0)->play_door_sound();
            d->flags |= 1;
        } else {
            d->flags &= ~1;
        }
        break;
    case 3:
        if (d->flags & 1) {
            d->flags |= 0xF0000;
            break;
        }
        d->flags &= 0xFFF0FFFF;
        d->count = 4 - d->num;
        for (i = 0; i < d->num; i++) {
            if (is_current_floor_switch_set(d->base + i) == 1) {
                d->count++;
            }
        }
        for (i = 0; i < d->count; i++) {
            d->flags |= 1 << (i + 0x10);
        }
        if (d->count == 4) {
            ((TUnk_804B0BB8 *)arg0)->play_door_sound();
            d->flags |= 1;
            if (d->obj != NULL && ((TUnk_804AF8A0 *)arg0)->access_object_saved_state(&st, (s16)1) != 0) {
                st.a = 1;
                ((TODoorCave01 *)arg0)->send_state(&st);
                ((TUnk_804AF8A0 *)arg0)->access_object_saved_state(&st, (s16)0);
            }
        }
        break;
    default:
        d->flags &= 0xFFF0FFFE;
        break;
    }
}

}

struct VBase_801618fc { char pad[0x18]; };
struct VObj_801618fc : VBase_801618fc {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8(f32, f32);
};

extern "C" {
s32 push_matrix();
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 *TODoorCave01__texture_lists;
extern s32 model_render_flags;
s32 post_translate_matrix(void *);
s32 draw_ginja_model_with_motion(void *, int, f32);
s32 rotate_matrix_y(int, int);
void *__nw__7TObjectFUl(int);

s32 TODoorCave01::draw_door_model(void *p0, int p1, int arg2) {
    s32 temp_r4;
    u8 *temp_r31;
    u8 *temp_r31_2;
    TObjFish::set_global_param((int) (*(s32 *)((s8 *)TODoorCave01__texture_lists + (arg2 * 4))));
    push_matrix();
    translate_matrix(0, (f32) (*(f32 *)((s8 *)((u8 *) p1) + 8)), (f32) (*(f32 *)((s8 *)((u8 *) p1) + 0xC)), (f32) (*(f32 *)((s8 *)((u8 *) p1) + 0x10)));
    draw_ginja_model((*(s32 *)((s8 *)((u8 *) p1) + 4)));
    temp_r31 = *(u8 **)((s8 *)((u8 *) p1) + 0x2C);
    if (arg2 != 1) {
        temp_r4 = model_render_flags;
        saved_model_render_flags = temp_r4;
        model_render_flags = temp_r4 | 0x10;
        ((void (*)(void *, s32))set_constant_material)((void *) (((s32) p0) + 0xDC), temp_r4);
    }
    TParticleCtrl::begin_effect_render();
    push_matrix();
    translate_matrix(0, (f32) (*(f32 *)((s8 *)temp_r31 + 8)), (f32) (*(f32 *)((s8 *)temp_r31 + 0xC)), (f32) (*(f32 *)((s8 *)temp_r31 + 0x10)));
    draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
    temp_r31_2 = *(u8 **)((s8 *)temp_r31 + 0x2C);
    push_matrix();
    translate_matrix(0, (f32) (*(f32 *)((s8 *)temp_r31_2 + 8)), (f32) (*(f32 *)((s8 *)temp_r31_2 + 0xC)), (f32) (*(f32 *)((s8 *)temp_r31_2 + 0x10)));
    draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
    pop_matrix();
    pop_matrix();
    TParticleCtrl::end_effect_render();
    if (arg2 != 1) {
        set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
    }
    pop_matrix();
}

void render__12TODoorCave01Fv(TODoorCave01 *arg0) {
    u8 *var_r30;
    s32 var_r29;

    if ((((VObj_801618fc *) arg0)->m8(arg0->m_c0, *(f32 *)((s8 *)arg0 + 0xC4)) != 0) && (((TUnk_804AFBF8 *)arg0)->is_in_view_depth(3e+01f) != 0)) {
        push_matrix();
        post_translate_matrix((u8 *)arg0 + 0x38);
        rotate_matrix_y(0, arg0->rotation_y);
        if ((s32) arg0->m_ac == 0) {
            var_r29 = 0;
            var_r30 = (unsigned char *) (*(void **)((s8 *)arg0->model + 0x2C));
            do {
                TODoorCave01::draw_door_model((void *)arg0, (int)var_r30, (int)(arg0->m_d0 & (1 << (var_r29 + 0x10)) ? 1 : 0));
                var_r29 += 1;
                var_r30 = (unsigned char *) (*(void **)((s8 *)var_r30 + 0x30));
            } while (var_r29 < 4);
        } else {
            TObjFish::set_global_param((int) (*(s32 *)((s8 *)TODoorCave01__texture_lists + 4)));
            draw_ginja_model_with_motion(arg0->model, arg0->m_bc, arg0->m_b0);
        }
        pop_matrix();
    }
}

extern void *tl_05;

void *TODoorCave01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xEC);
    if (o != NULL) {
        o = TODoorCave01__ct((TODoorCave01 *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

}

extern "C" {
extern char lbl_80440D10[];
extern char lbl_80440D24[];
extern char lbl_80440D38[];
extern char lbl_80440D50[];
__declspec(section ".data") const char *bm_fs_obj_do_doa01_model_names[2] = { lbl_80440D10, NULL };
__declspec(section ".data") const char *bm_fs_obj_do_doa01_motion_names[2] = { lbl_80440D24, NULL };
BmlResourceDescriptor TODoorCave01__resource_descriptor = { lbl_80440D38, bm_fs_obj_do_doa01_model_names, bm_fs_obj_do_doa01_motion_names, 1, 1 };
__declspec(section ".data") const char *bm_fs_obj_do_doa01_a_model_names[2] = { lbl_80440D10, NULL };
__declspec(section ".data") const char *bm_fs_obj_do_doa01_a_motion_names[2] = { lbl_80440D24, NULL };
BmlResourceDescriptor cave_door01_resource_descriptor = { lbl_80440D50, bm_fs_obj_do_doa01_a_model_names, bm_fs_obj_do_doa01_a_motion_names, 1, 1 };
}

struct RecoveredGlobal_80161BE4_lbl_804B13C8 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80161BE4___vt__12TODoorCave01 {
    s32 value;
    u8 remaining[0x50];
};

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
void *init_door_base(void *a0);
extern RecoveredGlobal_80161BE4_lbl_804B13C8 TODoorCave01__collision_body_template;
extern s32 __vt__12TODoorCave01[];
extern s32 lbl_805D2F60;
extern u32 door_cave_shared_bml_archive;

void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern u8 lbl_80440D7C[];
extern u8 lbl_80440D94[];

extern s32 enable_v2_features;
extern s32 *TODoorCave01__texture_lists;
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void mem_free(void *p);

void TODoorCave01::free_resources() {
    if ((s32 *) TODoorCave01__texture_lists != NULL) {
        TObjPlayer::free_if_valid(*TODoorCave01__texture_lists);
        if ((s32 *) TODoorCave01__texture_lists != NULL) {
            mem_free(TODoorCave01__texture_lists);
            TODoorCave01__texture_lists = NULL;
        }
    }
    if ((u32) door_cave_shared_bml_archive != 0U) {
        TLobby__sub_8001FE7C((void*)door_cave_shared_bml_archive, 1);
        door_cave_shared_bml_archive = 0U;
    }
}

void TODoorCave01::load_resources() {
    void *o;
    TODoorCave01__texture_lists = (s32 *)mem_alloc(8);
    if (enable_v2_features != 0 && TLobby::is_online_ready() != 0) {
        o = ::operator new(0x440);
        if (o != NULL) {
            o = load_resource_from_descriptor(o, 1, &cave_door01_resource_descriptor, 0, 0, 0);
        }
        door_cave_shared_bml_archive = (u32)o;
        TODoorCave01__texture_lists[0] = (s32)load_gvm_texture_file((s32)lbl_80440D7C);
    } else {
        o = ::operator new(0x440);
        if (o != NULL) {
            o = load_resource_from_descriptor(o, 1, &TODoorCave01__resource_descriptor, 0, 0, 0);
        }
        door_cave_shared_bml_archive = (u32)o;
        TODoorCave01__texture_lists[0] = (s32)load_gvm_texture_file((s32)lbl_80440D94);
    }
    TODoorCave01__texture_lists[1] = *(s32 *)((s8 *)(*(void **)((s8 *)door_cave_shared_bml_archive + 0x42C)) + 0xC);
}

void *__dt__12TODoorCave01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TODoorCave01;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B0BB8 *)arg0)->destroy_ancient_door_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80161BE4_lbl_804B13C8_size[sizeof(RecoveredGlobal_80161BE4_lbl_804B13C8) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80161BE4___vt__12TODoorCave01_size[sizeof(RecoveredGlobal_80161BE4___vt__12TODoorCave01) == 0x54 ? 1 : -1];
u8 *TODoorCave01__ct(TODoorCave01 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    init_door_base((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80161BE4___vt__12TODoorCave01 *)&__vt__12TODoorCave01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2F60;
    ((TODoorCave01 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&door_cave_shared_bml_archive) + 0x42C)) + 8);
    arg0->texture_id = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&door_cave_shared_bml_archive) + 0x42C)) + 0xC);
    *(u8 **)((s8 *)arg0 + 0xBC) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&door_cave_shared_bml_archive) + 0x430)) + 4));
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xBC)) + 4) - 1.0f);
    arg0->m_b8 = (f32) 0.5f;
    init_collision_body_parts(arg0, &TODoorCave01__collision_body_template.value, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    ((TODoorCave01 *)(arg0))->init_door_switch_binding();
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x88);
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)arg0 + 0x88) = 0;
    } else if (temp_r0 > 4) {
        *(s32 *)((s8 *)arg0 + 0x88) = 4;
    }
    arg0->m_d4 = (s32) *(s32 *)((s8 *)arg0 + 0x88);
    arg0->m_d8 = (s32) (4 - arg0->m_d4);
    *(f32 *)((s8 *)arg0 + 0xDC) = (f32) 1.0f;
    arg0->m_e0 = (f32) 1.0f;
    *(f32 *)((s8 *)arg0 + 0xE4) = (f32) 1.0f;
    arg0->m_e8 = (f32) 1.0f;
    return (u8 *)arg0;
}

}
