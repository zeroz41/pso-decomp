#include "types.h"
#include "pso/enemy/TObjEnemy.h"

#include <stddef.h>
#include "pso/unk/TLobby.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/ui/window/TWindowLockOn.h"
struct Stack_800F5D80 {
    s32 sp8;
    u8 pad_C[0x2];
    s16 spE;
};

extern "C" {
s32 exchange_object_state__9TObjEnemyFls(void *, void *, int);
void *mem_alloc(u32 size);
s32 collect_model_strips_by_texture(void *, s32, s32, s32);
s32 count_model_strips_by_texture();

extern s32 plist_strip_write_ptr;
extern s32 plist_strip_uv_write_ptr;
extern s32 plist_texture_matches_filter;

void *TLobby::alloc_tables(s32 arg1, s32 arg2) {
    s32 temp_r6;

    *(s32 *)&this->m_flags = 0;
    *(s32 *)&this->m_name = 0;
    plist_texture_matches_filter = 0;
    count_model_strips_by_texture();
    *(s32 *)&this->m_prev = (s32)mem_alloc(*(s32 *)&this->m_flags * 8);
    *(s32 *)&this->m_next = (s32)mem_alloc(*(s32 *)&this->m_name * 4);
    plist_strip_write_ptr = *(s32 *)&this->m_prev;
    temp_r6 = *(s32 *)&this->m_next;
    plist_strip_uv_write_ptr = temp_r6;
    plist_texture_matches_filter = 0;
    collect_model_strips_by_texture(this, arg1, arg2, temp_r6);
    return this;
}
void TObjEnemy::clear_lobby_object_state() {
    s32 arg0 = (s32)this;
    typedef char sp8_offset[(offsetof(Stack_800F5D80, sp8) == 0x0) ? 1 : -1];
    typedef char spE_offset[(offsetof(Stack_800F5D80, spE) == 0x6) ? 1 : -1];
    Stack_800F5D80 stack;
    if (exchange_object_state__9TObjEnemyFls((void *)arg0, &stack.sp8, 1) != 0) {
        stack.sp8 = 0;
        stack.spE = 0;
        exchange_object_state__9TObjEnemyFls((void *)arg0, &stack.sp8, 0);
    }
}

}
