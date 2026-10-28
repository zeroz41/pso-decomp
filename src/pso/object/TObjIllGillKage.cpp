#include "types.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjIllGillKage.h"
#include "pso/TObject.h"
#include "pso/object/TObjMotion.h"

struct RecoveredGlobal_803655F8___vt__15TObjIllGillKage { s32 value; u8 remaining[0x30]; };
typedef char RecoveredGlobal_803655F8___vt__15TObjIllGillKage_size[sizeof(RecoveredGlobal_803655F8___vt__15TObjIllGillKage) == 0x34 ? 1 : -1];

extern "C" {
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
u16 get_entity_id(void *);
int queue_destruction__7TObjectFv(void*);
s32 __ct__8TObjBaseFP7TObject(void *);
extern s32 __vt__15TObjIllGillKage[];
extern s32 lbl_805D44AC;
u8 *TObjIllGillKage__ct(u8 *arg0, s32 arg1, u32 arg2);
void *__dt__15TObjIllGillKageFv(void *arg0, s16 arg1);
s32 is_locally_controlled__10TObjPlayerFPv();
void *get_player_by_client_id(s32 i);
void __dl__7TObjectFPv(void *);
s32 obj_testFlags30__14TObjCollidableFUl(s32, s32);

int TObjIllGillKage::queue_destruction() { return queue_destruction__7TObjectFv(this); }

void TObjIllGillKage::tick_persistent_sound() {
    s32 temp_r3;
    play_persistent_sound(0x4003A357, (s32)this, (u32)(((u8 *)this) + 0x38), 0, 0);
    temp_r3 = this->m_94;
    this->m_94 = (temp_r3 - 1);
    if (temp_r3 < 0) {
        this->m_90 = 2;
    }
}

void TObjIllGillKage::attack_target() {
    s32 temp_r3;

    this->m_90 = 1;
    temp_r3 = (s32)get_player_by_client_id(this->m_98);
    if ((temp_r3 != 0) && (is_locally_controlled__10TObjPlayerFPv() != 0) && (((TObject *)temp_r3)->all_parents_unqueued_for_destruction() != 0) && (obj_testFlags30__14TObjCollidableFUl(temp_r3, 0x800) == 0)) {
        TObjPlayer::play_effect(temp_r3, this->m_94, 3);
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

void *__dt__15TObjIllGillKageFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TObjIllGillKage;
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TObjIllGillKage__ct(u8 *ill_gill_kage, s32 arg1, u32 arg2) {
    __ct__8TObjBaseFP7TObject(ill_gill_kage);
    *(s32 **)((s8 *)ill_gill_kage + 0x18) = &(*(RecoveredGlobal_803655F8___vt__15TObjIllGillKage *)&__vt__15TObjIllGillKage).value;
    *(s32 *)((s8 *)ill_gill_kage + 0) = (s32) lbl_805D44AC;
    if (arg2 != 0U) {
        VecCopy((Vec *)(ill_gill_kage + 0x38), (const Vec *)(arg2 + 0x38));
        ((TObjIllGillKage *)ill_gill_kage)->m_98 = get_entity_id((void *)arg2);
        ((TObjIllGillKage *)ill_gill_kage)->m_94 = 0xB4;
        ((TObjIllGillKage *)ill_gill_kage)->m_90 = 0;
    } else {
        ((TObjIllGillKage *)ill_gill_kage)->m_98 = 0xFFFFU;
        queue_destruction__7TObjectFv(ill_gill_kage);
    }
    return ill_gill_kage;
}

}
