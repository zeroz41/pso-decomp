#include "types.h"
#include "pso/misc/TWindowActionPalette_801C1890.h"
#include "pso/misc/TUnk_804ED7D0.h"
#include "pso/misc/TUnk_804DDBF0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"

struct Base_801BC688 { char pad[8]; };

struct VObj_801BC688 : Base_801BC688 { virtual void m0(); virtual void m1(int); };

extern "C" {
void set_flag_400000__10TObjPlayerFi(s32 arg0);
u8 *heap_alloc__10TObjPlayerFPv(s32);
extern const f32 TObjPlayer__data_805DC278;
#pragma push
#pragma fp_contract on
void TObjPlayer::release_child_object() {
    void *temp_r3;
    temp_r3 = *(void * *)&this->unk_380;
    if (temp_r3 != NULL) {
        ((VObj_801BC688 *)temp_r3)->m1(1);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjPlayer::init_action_provider() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *temp_r3_2;
    u8 *var_r0;
    u8 *var_r0_2;
    if (TObjPlayer::get_hold_effect_count() == 1) {
        temp_r3 = (u8 *)(heap_alloc__10TObjPlayerFPv(0x8C));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((TUnk_804DDBF0 *)temp_r3)->ct_variant());
        }
        *(u8 * *)&this->unk_380 = var_r0;
    } else if (TObjPlayer::get_hold_effect_count() == 0) {
        temp_r3_2 = (u8 *)(heap_alloc__10TObjPlayerFPv(0xC));
        var_r0_2 = temp_r3_2;
        if (var_r0_2 != NULL) {
            var_r0_2 = (u8 *)(((TUnk_804ED7D0 *)temp_r3_2)->init_vtable8());
        }
        *(u8 * *)&this->unk_380 = var_r0_2;
    }
    this->m_33b = 0;
    *(s8 *)&this->unk_33A = 0;
    this->m_339 = 0;
    *(s8 *)&this->unk_338 = 0;
    *(s32 *)&this->unk_33C = 0;
    this->m_36c = 0;
    *(s32 *)&this->unk_370 = 0;
    ((TObjPlayer *)arg0)->reset_entrance_id();
    ((TObjPlayer *)(arg0 + 0x66C))->set_vec3_const();
    *(f32 *)&this->m_2b4 = (f32) TObjPlayer__data_805DC278;
    *(s32 *)&this->m_334 = 0;
    ((TObjPlayer *)arg0)->set_input_mode(0);
    ((TObjPlayer *)arg0)->set_move_mode(0);
    *(s16 *)&this->unk_3C0 = -1;
    *(f32 *)&this->m_3c4 = (f32) TObjPlayer__data_805DC278;
    ((TObjPlayer *)arg0)->set_battle_flag(0);
    this->m_314 = 0;
    *(s32 *)&this->inventory_objects = 0;
    this->m_424 = 0;
    (*(s32 *)&this->joint_matrices) = 0;
    this->m_db4 = 0;
    ((TObjPlayer *)arg0)->set_floor_index(0xF);
    ((TObjPlayer *)arg0)->set_floor(0xF);
    this->m_54c = 0;
    *(s32 *)&this->unk_3B8 = 0;
    *(s32 *)&this->unk_420 = 0;
    this->m_3d0 = 0;
    ((TObjPlayer *)arg0)->reset_state();
    set_flag_400000__10TObjPlayerFi((s32)arg0);
    if (TObjPlayer::get_player_count() == 1) {
        fn_801C19F4(((u8 *)&this->m_828));
    }
}
#pragma pop

}
