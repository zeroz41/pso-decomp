#include "types.h"
#include "pso/ui/window/TWindowActionPalette_801C1890.h"
#include "pso/unk/TUnk_804ED7D0.h"
#include "pso/unk/TUnk_804DDBF0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"


extern const f32 TObjPlayer__data_805DC278;
#pragma push
#pragma fp_contract on
void TObjPlayer::release_child_object() {
    delete action_provider;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjPlayer::init_action_provider() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::get_hold_effect_count() == 1) {
        action_provider = new TUnk_804DDBF0;
    } else if (TObjPlayer::get_hold_effect_count() == 0) {
        action_provider = new TUnk_804ED7D0;
    }
    this->m_33b = 0;
    *(s8 *)&this->unk_33A = 0;
    this->m_339 = 0;
    *(s8 *)&this->unk_338 = 0;
    this->action_state = 0;
    this->m_36c = 0;
    this->pad_370 = 0;
    this->reset_entrance_id();
    ((TObjPlayer *)(arg0 + 0x66C))->set_vec3_const();
    *(f32 *)&this->frame_timer = (f32) TObjPlayer__data_805DC278;
    *(s32 *)&this->state_flags = 0;
    this->set_input_mode(0);
    this->set_move_mode(0);
    this->lobby_animation = -1;
    *(f32 *)&this->m_3c4 = (f32) TObjPlayer__data_805DC278;
    this->set_battle_flag(0);
    this->controller_input = NULL;
    *(s32 *)&this->inventory_objects = 0;
    this->lock_on_cursor = NULL;
    (*(s32 *)&this->joint_matrices) = 0;
    this->item_node_matrices = NULL;
    this->set_floor_index(0xF);
    this->set_floor(0xF);
    this->m_54c = 0;
    *(s32 *)&this->unk_3B8 = 0;
    *(s32 *)&this->unk_420 = 0;
    this->controller_port = 0;
    this->reset_state();
    ::set_flag_400000(this);
    if (TObjPlayer::get_player_count() == 1) {
        set_player_pk_mode_flag(((u8 *)&this->m_828));
    }
}
#pragma pop
