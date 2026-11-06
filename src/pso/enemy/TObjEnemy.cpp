#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
extern "C" {
extern s32 __vt__9TObjEnemy[];
extern void* TObjEnemy_class_name;
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
int unregister_object_by_id__14TObjCollidableFv(void*);
s32 __dl__7TObjectFPv(void *);
s32 copy_header__6TLobbyFPv(s32);

}
TObjEnemy::~TObjEnemy() {
    u16 temp_r0;
    this->apply_player_54a00();
    if ((u32) *(u32 *)((s8 *)this + 0x80) != 0U) {
        temp_r0 = this->entity_id;
        if ((temp_r0 >= 0x1000U) && (temp_r0 < 0x4000U)) {
            this->mask_sub_flags(-3);
            *(u32 *)((s8 *)this + 0x80) = 0U;
        }
    }
}
extern "C" {

extern s32 TLobby__data_805D6144;

}

TObjEnemy::TObjEnemy(TObject *parent) : TObjChara(parent) {
    m_name = (const char *)TObjEnemy_class_name;
    targetId = 0xFFFF;
    variant = 0;
    state36C = 0;
    control = 0;
    subtype = 0;
    group = 0;
    previous = 0;
    next = 0;
    children = 0;
    movementParameters = 0;
    resetTimer = 0;
    timer = 0;
    referenceHp = hp;
    for (int i = 0; i < 5; ++i) {
        parameters[i] = 0.0f;
    }
    actorFlags |= 0x20000000;
    this->motion_flags |= 1;
}

s32 TObjEnemy::apply_by_index(s16 arg0) {
    if (arg0 > 0xB4F) {
        return 0;
    }
    copy_header__6TLobbyFPv(TLobby__data_805D6144 + (arg0 * 0xC));
    return 1;
}

int TObjEnemy::apply_player_54a00() { return unregister_object_by_id__14TObjCollidableFv(this); }
void TObjCollidable::clear_shadow_flag() { this->m_flags &= 0xfffffbff; }
void TObjCollidable::set_shadow_flag() { this->m_flags |= 0x400; }
