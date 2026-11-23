#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/item/TItemLockCountCtrl_8011E184.h"
#include "pso/player/TObjPlayer_801BF918.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdRicoRing.h"

extern const f32 TObjPlayer__data_805DC278;

void TObjPlayer::reset_state() {
    u8 *arg0 = (u8 *)this;
    ((FlagWord *)(arg0 + 0x858))->clear(2);
    battle_music.reset_counter_field4();
    protection.reset_type();
    ((TObjPlayer *)(arg0 + 0x7CC))->reset_movement_state();
    movement_hold.reset();
    ((TObjPlayer *)(arg0 + 0x608))->set_vec4_const();
    *(s32 *)&this->unk_548 = 0;
    ((TObjPlayer *)(arg0 + 0x340))->init_tag();
    *(s32 *)((s8 *)arg0 + 0x3D4) = 0;
    this->clear_state_flags(0x283);
    this->m_3f4 = 0;
    *(s32 *)&this->unk_3F0 = 0;
    this->m_3ec = 0;
    this->move_target.z = (f32) TObjPlayer__data_805DC278;
    this->move_target.y = (f32) TObjPlayer__data_805DC278;
    this->move_target.x = (f32) TObjPlayer__data_805DC278;
    this->velocity.z = (f32) TObjPlayer__data_805DC278;
    this->velocity.y = (f32) TObjPlayer__data_805DC278;
    this->velocity.x = (f32) TObjPlayer__data_805DC278;
    zero_vec3(&this->pad_5fc);
}
