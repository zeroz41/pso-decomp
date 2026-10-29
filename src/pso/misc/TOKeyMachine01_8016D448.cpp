#include "types.h"
#include "pso/misc/TOKeyGenericSw.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOKeyMachine01_8016D448.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"

struct RecoveredGlobal_8016D1A8_lbl_80441D84 {
    s32 value;
    u8 remaining[0x8C];
};

struct RecoveredGlobal_8016D2A4_lbl_80441D84 {
    s32 value;
    u8 remaining[0x8C];
};

struct Pkt_8016D148 { u8 code, words; u16 object, zero, reserved, switchId; u8 area, flags; };

extern "C" {
s32 is_split_screen();

s32 play_sound_effect(s32, u32, s16, s32);
extern RecoveredGlobal_8016D1A8_lbl_80441D84 key_machine01_state_table;
extern s32 enable_v2_features;

s32 get_current_floor();
extern s32 local_client_id;

void TOKeyMachine01::vfunc_25() {  }
s32 TOKeyMachine01::is_confirm_pressed() {
    s32 temp_r0;
    s32 var_r31;
    s32 var_r3;
    var_r31 = 0;
    temp_r0 = this->m_d0;
    switch (temp_r0) {
    case 0:
        if (is_split_screen() == 1) {
            var_r3 = this->is_any_player_in_range();
        } else {
            var_r3 = this->is_local_player_in_range();
        }
        if (((s32) this->m_d4 == 1) || (var_r3 == 1)) {
            var_r31 = 1;
        }
        break;
    case 1:
        var_r31 = this->is_any_player_in_range();
        break;
    }
    return var_r31;
}

typedef char RecoveredGlobal_8016D1A8_lbl_80441D84_size[sizeof(RecoveredGlobal_8016D1A8_lbl_80441D84) == 0x90 ? 1 : -1];

void TOKeyMachine01::send_switch_changed(s32 flags) {
    TOKeyMachine01 *self = this;
    Pkt_8016D148 pkt;
    ((TLobby *)(&pkt))->init_6x05_switch_changed();
    pkt.object = self->entity_id;
    pkt.zero = local_client_id;
    pkt.switchId = self->m_e4;
    pkt.area = get_current_floor();
    pkt.flags = flags;
    ((TLobby *)(&pkt))->finalize_and_send_60();
}

void TOKeyMachine01::vfunc_19() {
    s32 arg0 = (s32)this;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    if (((s32) enable_v2_features == 1) && ((get_current_floor_area() == AREA_BATTLE1) || (get_current_floor_area() == AREA_BATTLE2))) {
        temp_r3 = *(s32 *)((s8 *)&key_machine01_state_table.value + (get_current_floor_area() * 4));
        if (temp_r3 >= 0) {
            play_sound_effect(temp_r3, arg0 + 0x38, 0, 0);
        }
    } else if (((s32) enable_v2_features == 1) && ((get_current_floor_area() == AREA_FOREST1) || (get_current_floor_area() == AREA_FOREST2))) {
        temp_r3_2 = *(s32 *)((s8 *)&key_machine01_state_table.value + (get_current_floor_area() * 4));
        if (temp_r3_2 >= 0) {
            play_sound_effect(temp_r3_2, arg0 + 0x38, 0, 0);
        }
    } else {
        temp_r3_3 = *(s32 *)((s8 *)&key_machine01_state_table.value + (get_current_floor_area() * 4));
        if (temp_r3_3 >= 0) {
            play_sound_effect(temp_r3_3, arg0 + 0x38, 0, 0);
        }
    }
}

typedef char RecoveredGlobal_8016D2A4_lbl_80441D84_size[sizeof(RecoveredGlobal_8016D2A4_lbl_80441D84) == 0x90 ? 1 : -1];
void TOKeyMachine01::trigger_activate_sound() {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 arg0 = (s32)this;
    if (((s32) enable_v2_features == 1) && ((get_current_floor_area() == AREA_BATTLE1) || (get_current_floor_area() == AREA_BATTLE2))) {
        temp_r3 = *(s32 *)((s8 *)(&(*(RecoveredGlobal_8016D2A4_lbl_80441D84 *)&key_machine01_state_table).value) + (get_current_floor_area() * 4));
        if (temp_r3 >= 0) {
            play_sound_effect(temp_r3, arg0 + 0x38, 0, 0);
        }
    } else if (((s32) enable_v2_features == 1) && ((get_current_floor_area() == AREA_FOREST1) || (get_current_floor_area() == AREA_FOREST2))) {
        temp_r3_2 = *(s32 *)((s8 *)(&(*(RecoveredGlobal_8016D2A4_lbl_80441D84 *)&key_machine01_state_table).value) + (get_current_floor_area() * 4));
        if (temp_r3_2 >= 0) {
            play_sound_effect(temp_r3_2, arg0 + 0x38, 0, 0);
        }
    } else {
        temp_r3_3 = *(s32 *)((s8 *)(&(*(RecoveredGlobal_8016D2A4_lbl_80441D84 *)&key_machine01_state_table).value) + (get_current_floor_area() * 4));
        if (temp_r3_3 >= 0) {
            play_sound_effect(temp_r3_3, arg0 + 0x38, 0, 0);
        }
    }
}

void TOKeyMachine01::vfunc_17() {
    f32 temp_f1;
    if ((s32) this->m_f8 == 1) {
        this->m_ec += 0.1f;
        if (1.0f <= this->m_ec) {
            this->m_f8 = 0;
        }
    } else {
        this->m_ec = (f32) (this->m_ec - 0.1f);
        if (this->m_ec <= 0.0f) {
            this->m_f8 = 1;
        }
    }
    temp_f1 = this->scale.y;
    if (temp_f1 < 0.0f) {
        this->scale.y = (f32) (temp_f1 - (-0.023333333f));
    }
}
void TOKeyMachine01::vfunc_16() {
    TOKeyMachine01 *self = this;
    if ((-0.7f) < self->scale.y) {
        self->scale.y += (-0.023333333f);
    }
}

}

struct RecoveredGlobal_8016D714_lbl_80441E24 { char value[0x1A]; };
typedef char RecoveredGlobal_8016D714_lbl_80441E24_size[sizeof(RecoveredGlobal_8016D714_lbl_80441E24) == 0x1A ? 1 : -1];

struct RecoveredGlobal_8016D714_lbl_804B2DD8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8016D714_lbl_804B2DD8_size[sizeof(RecoveredGlobal_8016D714_lbl_804B2DD8) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8016D7F0___vt__14TOKeyMachine01 { s32 value; u8 remaining[0x6C]; };

struct VBase_8016D540 { char pad[0x18]; };

struct VObj_8016D540 : VBase_8016D540 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual s32 m8(f32, f32); };

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32 size);
extern RecoveredGlobal_8016D714_lbl_80441E24 lbl_80441E24;
extern RecoveredGlobal_8016D714_lbl_804B2DD8 bm_fs_obj_ki_doa_panel_resource_descriptor;
extern u32 key_machine_model_archive;
extern s32 *TOKeyMachine01__texture_lists;
s32 is_split_screen(void);
u8 * __ct__5TOKeyFP7TObject(void *);

extern s32 __vt__14TOKeyMachine01[];
extern s32 TOKeyMachine01__name;

s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void TLobby__sub_8001FE7C(void*, int);
void *__nw__7TObjectFUl(int);
void mem_free(void *p);

extern void *tl_05;

void TOKeyMachine01::run_task() {
    u8 *arg0 = (u8 *)this;
    this->update_lock_state();
    if ((s32) this->m_d4 != 1) {
        this->vfunc_17();
        if (this->is_confirm_pressed() == 1) {
            ((TOKeyMachine01 *)arg0)->send_switch_changed(1);
            this->trigger_activate_sound();
            this->m_d4 = 1;
        }
    } else {
        this->vfunc_16();
        if (this->is_confirm_pressed() != 1) {
            ((TOKeyMachine01 *)arg0)->send_switch_changed(0);
            this->vfunc_19();
            this->m_d4 = 0;
        }
    }
}

void TOKeyMachine01::render() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    if (((VObj_8016D540 *)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) {
        TObjFish::set_global_param(TOKeyMachine01__texture_lists[*(s32 *)&this->m_d4]);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        temp_r31 = *(u8 * *)&this->model;
        post_translate_matrix(temp_r31 + 8);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
        if ((s32) *(s32 *)&this->m_d4 != 1) {
            temp_r4 = model_render_flags;
            saved_model_render_flags = temp_r4;
            model_render_flags = temp_r4 | 0x10;
            set_constant_material((const NJS_ARGB *)((arg0 + 0xE8)));
        }
        TParticleCtrl::begin_effect_render();
        temp_r31_2 = *(u8 **)((s8 *)temp_r31 + 0x2C);
        push_matrix();
        post_translate_matrix((u8 *)&this->scale);
        post_translate_matrix(temp_r31_2 + 8);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
        temp_r31_3 = *(u8 **)((s8 *)temp_r31_2 + 0x2C);
        push_matrix();
        post_translate_matrix(temp_r31_3 + 8);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        if ((s32) *(s32 *)&this->m_d4 != 1) {
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
        }
        pop_matrix();
    }
}

void *TOKeyMachine01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xFC);
    if (o != NULL) {
        o = TOKeyMachine01__ct((TOKeyMachine01 *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOKeyMachine01::free_statics() {
    if ((s32 *) TOKeyMachine01__texture_lists != NULL) {
        TObjPlayer::free_if_valid(*TOKeyMachine01__texture_lists);
        *TOKeyMachine01__texture_lists = 0;
        if ((s32 *) TOKeyMachine01__texture_lists != NULL) {
            mem_free(TOKeyMachine01__texture_lists);
            TOKeyMachine01__texture_lists = NULL;
        }
    }
    if ((u32) key_machine_model_archive != 0U) {
        TLobby__sub_8001FE7C((void*)key_machine_model_archive, 1);
        key_machine_model_archive = 0U;
    }
}

void TOKeyMachine01::load_assets() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_ki_doa_panel_resource_descriptor.value, 0, 0, 0));
    }
    (*(u8 * *)&key_machine_model_archive) = (unsigned char *) ((void *) var_r0);
    (*(s32 *)&TOKeyMachine01__texture_lists) = (s32)mem_alloc((u32)((void *)8));
    *(u8 **)((s8 *)(*(s32 *)&TOKeyMachine01__texture_lists) + 0) = load_gvm_texture_file((s32) &lbl_80441E24.value);
    *(s32 *)((s8 *)(*(s32 *)&TOKeyMachine01__texture_lists) + 4) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&key_machine_model_archive) + 0x42C)) + 0xC);
}

}
TOKeyMachine01::~TOKeyMachine01() {

}

u8 *TOKeyMachine01__ct(TOKeyMachine01 *key_machine01, s32 arg1, s32 arg2) {
    __ct__5TOKeyFP7TObject(key_machine01);
    *(s32 **)((s8 *)key_machine01 + 0x18) = &(*(RecoveredGlobal_8016D7F0___vt__14TOKeyMachine01 *)&__vt__14TOKeyMachine01).value;
    *(s32 *)((s8 *)key_machine01 + 0) = (s32) TOKeyMachine01__name;
    ((TOKeyMachine01 *)(key_machine01))->apply_object_set_data((void *)arg2);
    ((TOKey *)key_machine01)->init_switch_id();
    key_machine01->texlist = (s32) *TOKeyMachine01__texture_lists;
    *(s32 *)((s8 *)key_machine01 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&key_machine_model_archive) + 0x42C)) + 8);
    key_machine01->m_c0 = (f32) 4e+02f;
    *(f32 *)((s8 *)key_machine01 + 0xC4) = (f32) 1e+01f;
    *(f32 *)((s8 *)key_machine01 + 0xCC) = (f32) 1e+01f;
    if (get_main_phase() != 0xF) {
        if (is_split_screen() == 1) {
            goto block_2;
        }
    } else {
block_2:
        if ((s32) key_machine01->m_d0 != 2) {
            if ((s32) *(s32 *)((s8 *)key_machine01 + 0x88) < 0) {
                key_machine01->m_d0 = 1;
            } else {
                goto block_5;
            }
        } else {
block_5:
            key_machine01->m_d0 = 0;
        }
    }
    key_machine01->m_e8 = (f32) 1.0f;
    key_machine01->m_ec = (f32) 1.0f;
    *(f32 *)((s8 *)key_machine01 + 0xF0) = (f32) 1.0f;
    key_machine01->m_f4 = (f32) 1.0f;
    key_machine01->m_f8 = 0;
    *(f32 *)((s8 *)key_machine01 + 0x70) = (f32) 0.0f;
    key_machine01->scale.y = (f32) 0.0f;
    key_machine01->scale.x = (f32) 0.0f;
    return (u8 *)key_machine01;
}
