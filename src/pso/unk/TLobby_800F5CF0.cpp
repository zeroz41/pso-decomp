#include "types.h"
#include "pso/enemy/TObjEnemy.h"

#include "pso/unk/TLobby.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

extern "C" {
s32 collect_model_strips_by_texture(void *, s32, s32, s32);
s32 count_model_strips_by_texture();

extern s32 plist_strip_write_ptr;
extern s32 plist_strip_uv_write_ptr;
extern s32 plist_texture_matches_filter;

void *TLobby::alloc_tables(s32 ctx, s32 arg2) {
    s32 temp_r6;

    *(s32 *)&this->m_flags = 0;
    *(s32 *)&this->m_name = 0;
    plist_texture_matches_filter = 0;
    count_model_strips_by_texture();
    *(s32 *)&this->m_prev = (saddr)mem_alloc(*(s32 *)&this->m_flags * 8);
    *(s32 *)&this->m_next = (saddr)mem_alloc(*(s32 *)&this->m_name * 4);
    plist_strip_write_ptr = *(s32 *)&this->m_prev;
    temp_r6 = *(s32 *)&this->m_next;
    plist_strip_uv_write_ptr = temp_r6;
    plist_texture_matches_filter = 0;
    collect_model_strips_by_texture(this, ctx, arg2, temp_r6);
    return this;
}
void TObjEnemy::clear_lobby_object_state() {
    EnemyStateRecord record;
    if (this->exchange_object_state(&record, 1) != 0) {
        record.flags = 0;
        record.damage = 0;
        this->exchange_object_state(&record, 0);
    }
}

}
