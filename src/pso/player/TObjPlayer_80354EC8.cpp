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

void run_palettex_callback(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[client_index])->finish_quest_thread();
    }
}
void set_palettex_callback(u16 client_index, s32 arg1) {
    if (is_local_client(client_index) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[client_index])->set_player_index(arg1);
    }
}
u8 TObjPlayer__sub_80354C7C(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        return TObjPlayer__sub_80354F8C(&((E_80354E7C *)lbl_80543984)[client_index]);
    }
    return 0;
}
void TObjPlayer__sub_80354CCC(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        TObjPlayer__sub_80354FB0(&((E_80354E7C *)lbl_80543984)[client_index]);
    }
}
void TObjPlayer__sub_80354D14(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[client_index])->set_flag0_bits01();
    }
}
s32 is_palettex_activated(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        return ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[client_index])->clear_lock_flag();
    }
    return 0;
}
void TObjPlayer__sub_80354DAC(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        TObjPlayer__sub_8035501C(&((E_80354E7C *)lbl_80543984)[client_index]);
    }
}
void activate_palettex(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[client_index])->set_flag1();
    }
}
s32 is_local_client(u16 client_index) {
    void *player = get_player_by_client_id(client_index);
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
    __construct_array(lbl_80543984, (void *)init_and_reset_forward__10TObjPlayerFPv, (void *)TObjPlayer__sub_80355098, 8, 4);
    __register_global_object(0, (void *)TObjPlayer::destroy_static_array, lbl_80543978);
}

void TObjPlayer::destroy_static_array() {
    __destroy_arr(lbl_80543984, (void *)TObjPlayer__sub_80355098, 8, 4);
}

}

__declspec(section ".ctors") static void *const __sinit_TObjPlayer_80354EC8_cpp_ref = (void *)__sinit_TObjPlayer_80354EC8_cpp;

#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/player/PlayerSlots.h"

extern "C" {

int test_flags_any(void*, int);

s32 TObjPlayer::get_quest_thread_id() { return *(s32*)((char*)this + 0x4); }
void TObjPlayer::set_player_index(s32 v) { *(s32*)((char*)this + 0x4) = v; }
u8 TObjPlayer__sub_80354F8C(void *p) { return fn_8035510C((s32 *)p, 3); }
void TObjPlayer__sub_80354FB0(void* p) { ((FlagWord *)p)->clear(2); }
void TObjPlayer::set_flag0_bits01() { ((FlagWord *)this)->set(3); }
int TObjPlayer::clear_lock_flag() { return test_flags_any(this, 1); }
void TObjPlayer__sub_8035501C(void* p) { ((FlagWord *)p)->clear(3); }
void TObjPlayer::set_flag1() { ((FlagWord *)this)->set(1); }
void TObjPlayer::reset_field4() { ((FlagWord *)this)->reset(); *(int*)((char*)this + 0x4) = 0; }
s32 TObjPlayer__sub_80355098(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
void* init_and_reset_forward__10TObjPlayerFPv(void* p) { __ct__8FlagWordFv(p); ((TObjPlayer *)p)->reset_field4(); return p; }

}
