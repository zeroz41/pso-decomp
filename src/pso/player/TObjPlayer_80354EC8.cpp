#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/data/FlagWord.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/player/TObjPlayer_80354EC8.h"
#include "pso/unk/text_80354BE4.h"
#include "pso/ui/frontend/TAdPlyPltAnimCtrlGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

// One per-client quest-thread slot: a FlagWord and the slot's quest thread id (+0x4).
struct E_80354E7C { u8 b[8]; };

extern "C" {
s32 __destroy_arr(void *, void *, int, int);
void __register_global_object(void *, void *, void *);
void __construct_array(void *, void *, void *, u32, u32);
u8 lbl_80543978[0xC];
u8 lbl_80543984[0x24];

void finish_client_quest_thread(s32 arg0) {
    if (is_client_quest_slot_local(arg0) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[(u16)arg0])->finish_quest_thread();
    }
}
void set_client_quest_slot_player_index(s32 arg0, s32 arg1) {
    if (is_client_quest_slot_local(arg0) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[(u16)arg0])->set_player_index(arg1);
    }
}
u8 test_client_quest_slot_bits01(s32 arg0) {
    if (is_client_quest_slot_local(arg0) != 0) {
        return test_quest_slot_bits01(&((E_80354E7C *)lbl_80543984)[(u16)arg0]);
    }
    return 0;
}
void clear_client_quest_slot_bit1(s32 arg0) {
    if (is_client_quest_slot_local(arg0) != 0) {
        clear_quest_slot_bit1(&((E_80354E7C *)lbl_80543984)[(u16)arg0]);
    }
}
void set_client_quest_slot_bits01(s32 arg0) {
    if (is_client_quest_slot_local(arg0) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[(u16)arg0])->set_flag0_bits01();
    }
}
s32 test_client_quest_slot_lock_flag(s32 arg0) {
    if (is_client_quest_slot_local(arg0) != 0) {
        return ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[(u16)arg0])->clear_lock_flag();
    }
    return 0;
}
void clear_client_quest_slot_bits01(s32 arg0) {
    if (is_client_quest_slot_local(arg0) != 0) {
        clear_quest_slot_bits01(&((E_80354E7C *)lbl_80543984)[(u16)arg0]);
    }
}
void set_client_quest_slot_flag1(s32 arg0) {
    if (is_client_quest_slot_local(arg0) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[(u16)arg0])->set_flag1();
    }
}
s32 is_client_quest_slot_local(s32 arg0) {
    void *player = get_player_by_client_id((u16)arg0);
    if (player == NULL) {
        return 0;
    }
    if (TObjPlayer::is_locally_controlled(player) != 0) {
        return 1;
    }
    return 0;
}
void reset_client_quest_slot_table(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((TObjPlayer *)(&((E_80354E7C *)lbl_80543984)[i]))->reset_field4();
    }
}
void TObjPlayer::finish_quest_thread() { TQuestThread::create_in_root(get_quest_thread_id()); }

void __sinit_TObjPlayer_80354EC8_cpp(void) {
    __construct_array(lbl_80543984, (void *)init_and_reset_forward__10TObjPlayerFPv, (void *)delete_quest_slot_if_array_flag, 8, 4);
    __register_global_object(0, (void *)TObjPlayer::destroy_static_array, lbl_80543978);
}

void TObjPlayer::destroy_static_array() {
    __destroy_arr(lbl_80543984, (void *)delete_quest_slot_if_array_flag, 8, 4);
}

}

__declspec(section ".ctors") static void *const __sinit_TObjPlayer_80354EC8_cpp_ref = (void *)__sinit_TObjPlayer_80354EC8_cpp;

#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"

extern "C" {

int test_flags_any(void*, int);

s32 TObjPlayer::get_quest_thread_id() { return *(s32*)((char*)this + 0x4); }
void TObjPlayer::set_player_index(s32 v) { *(s32*)((char*)this + 0x4) = v; }
u8 test_quest_slot_bits01(void *p) { return fn_8035510C((s32 *)p, 3); }
void clear_quest_slot_bit1(void* p) { ((FlagWord *)p)->clear(2); }
void TObjPlayer::set_flag0_bits01() { ((FlagWord *)this)->set(3); }
int TObjPlayer::clear_lock_flag() { return test_flags_any(this, 1); }
void clear_quest_slot_bits01(void* p) { ((FlagWord *)p)->clear(3); }
void TObjPlayer::set_flag1() { ((FlagWord *)this)->set(1); }
void TObjPlayer::reset_field4() { ((FlagWord *)this)->reset(); *(int*)((char*)this + 0x4) = 0; }
s32 delete_quest_slot_if_array_flag(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
void* init_and_reset_forward__10TObjPlayerFPv(void* p) { __ct__8FlagWordFv(p); ((TObjPlayer *)p)->reset_field4(); return p; }

}
