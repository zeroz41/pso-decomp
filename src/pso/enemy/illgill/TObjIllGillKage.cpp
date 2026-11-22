#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/illgill/TObjIllGillKage.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_801AF2F0.h"


extern "C" {
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
u16 get_entity_id(void *);
extern s32 __vt__15TObjIllGillKage[];
extern const char *TObjIllGillKage__class_name;
void *__dt__15TObjIllGillKageFv(void *arg0, s16 arg1);

void TObjIllGillKage::queue_destruction() { TObject::queue_destruction(); }

void TObjIllGillKage::tick_persistent_sound() {
    s32 temp_r3;
    play_persistent_sound(0x4003A357, (saddr)this, (uaddr)(((u8 *)this) + 0x38), 0, 0);
    temp_r3 = this->m_94;
    this->m_94 = (temp_r3 - 1);
    if (temp_r3 < 0) {
        this->m_90 = 2;
    }
}

void TObjIllGillKage::attack_target() {
    saddr player;

    this->m_90 = 1;
    player = (saddr)get_player_by_client_id(this->m_98);
    if ((player != 0) && (TObjPlayer::is_locally_controlled((void *)player) != 0) && (((TObject *)player)->all_parents_unqueued_for_destruction() != 0) && (((TObjCollidable *)player)->obj_testFlags30(0x800) == 0)) {
        TObjPlayer::play_effect(player, this->m_94, 3);
    }
}

void TObjIllGillKage::run_task() {
    switch (this->m_90) {
    case 0:
        this->attack_target();
        return;
    case 1:
        tick_persistent_sound();
        return;
    default:
        this->queue_destruction();
        return;
    }
}

void TObjIllGillKage::render() {  }

void *__dt__15TObjIllGillKageFv(void *base, s16 arg1) {
    if (base != NULL) {
        *(s32 **)((s8 *)base + 0x18) = __vt__15TObjIllGillKage;
        __dt__8TObjBaseFv(base, 0);
        if (arg1 > 0) {
            TObject::operator delete(base);
        }
    }
    return base;
}
}
TObjIllGillKage::TObjIllGillKage(saddr parent, uaddr target) : TObjBase((TObject *)parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjIllGillKage__class_name;
    if (target != 0U) {
        VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(target + 0x38));
        this->m_98 = get_entity_id((void *)target);
        this->m_94 = 0xB4;
        this->m_90 = 0;
    } else {
        this->m_98 = 0xFFFFU;
        ((TObject *)this)->queue_destruction();
    }
}
