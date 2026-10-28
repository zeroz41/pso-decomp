#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TItemLockCountCtrl_8011E184.h"
#include "pso/player/TObjPlayer_801BF548.h"
#include "pso/player/TObjPlayer_801BF918.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TAdRicoRing.h"

extern const f32 TObjPlayer__data_805DC278;

void TObjPlayer::reset_state() {
    u8 *arg0 = (u8 *)this;
    ((FlagWord *)(arg0 + 0x858))->clear(2);
    ((TObjPlayer *)(arg0 + 0x63C))->reset_counter_field4();
    ((TObjPlayer *)(arg0 + 0x644))->reset_type();
    ((TObjPlayer *)(arg0 + 0x7CC))->reset_movement_state();
    TObjPlayer__sub_801BF690((u8 *)&this->m_730);
    ((TObjPlayer *)(arg0 + 0x608))->set_vec4_const();
    *(s32 *)&this->unk_548 = 0;
    ((TObjPlayer *)(arg0 + 0x340))->init_tag();
    *(s32 *)((s8 *)arg0 + 0x3D4) = 0;
    ((TObjPlayer *)arg0)->sub_8011E204(0x283);
    this->m_3f4 = 0;
    *(s32 *)&this->unk_3F0 = 0;
    this->m_3ec = 0;
    *(f32 *)((s8 *)arg0 + 0x400) = (f32) TObjPlayer__data_805DC278;
    this->m_3fc = (f32) TObjPlayer__data_805DC278;
    *(f32 *)&this->unk_3F8 = (f32) TObjPlayer__data_805DC278;
    *(f32 *)&this->m_310 = (f32) TObjPlayer__data_805DC278;
    this->y_speed = (f32) TObjPlayer__data_805DC278;
    *(f32 *)&this->unk_308 = (f32) TObjPlayer__data_805DC278;
    zero_vec3(&this->m_5fc);
}
