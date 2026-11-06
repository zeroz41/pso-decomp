#include "types.h"
#include "pso/item/TItemLockCountCtrl.h"
#include "pso/item/TItemLockCountCtrl_8011E184.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void *__nw__7TObjectFUl(int);

void notify_if_active__15TItemTimerEventFi(int);
void check_battle_ctrl__15TItemTimerEventFi(int);
extern void *item_timer_event_instance;

void TItemLockCountCtrl::create_instance() {
    void *o;
    o = __nw__7TObjectFUl(0x2C);
    if (o != NULL) {
        o = TItemLockCountCtrl__ct((void *)o, 0, 12, notify_if_active__15TItemTimerEventFi, check_battle_ctrl__15TItemTimerEventFi);
    }
    item_timer_event_instance = o;
}

void fn_8011E1D4(TObjPlayer *player) {
    if (!(player->class_flags & CLASS_FLAG_ANDROID)) {
        ((TObjPlayer *)player)->sub_8011E204(0x10000);
    }
}
void TObjPlayer::sub_8011E204(s32 arg1) {
  s32 *new_var;
  int new_var2;
    TObjPlayer *arg0 = (TObjPlayer *)this;
  new_var2 = ~arg1;
  new_var = (s32 *) (((s8 *) arg0) + 0x334);
  *new_var = (s32) ((arg0->m_334) & new_var2);
}

}
