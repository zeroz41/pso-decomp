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
s32 is_locally_controlled__10TObjPlayerFPv();
s32 __destroy_arr(void *, void *, int, int);
void __register_global_object(void *, void *, void *);
void __construct_array(void *, void *, void *, u32, u32);
u8 lbl_80543978[0xC];
u8 lbl_80543984[0x24];

void TObjPlayer__sub_80354BE4(s32 arg0) {
    if (TObjPlayer__sub_80354E3C(arg0) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[(u16)arg0])->finish_quest_thread();
    }
}
void TObjPlayer__sub_80354C2C(s32 arg0, s32 arg1) {
    if (TObjPlayer__sub_80354E3C(arg0) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[(u16)arg0])->set_player_index(arg1);
    }
}
u8 TObjPlayer__sub_80354C7C(s32 arg0) {
    if (TObjPlayer__sub_80354E3C(arg0) != 0) {
        return TObjPlayer__sub_80354F8C(&((E_80354E7C *)lbl_80543984)[(u16)arg0]);
    }
    return 0;
}
void TObjPlayer__sub_80354CCC(s32 arg0) {
    if (TObjPlayer__sub_80354E3C(arg0) != 0) {
        TObjPlayer__sub_80354FB0(&((E_80354E7C *)lbl_80543984)[(u16)arg0]);
    }
}
void TObjPlayer__sub_80354D14(s32 arg0) {
    if (TObjPlayer__sub_80354E3C(arg0) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[(u16)arg0])->set_flag0_bits01();
    }
}
s32 TObjPlayer__sub_80354D5C(s32 arg0) {
    if (TObjPlayer__sub_80354E3C(arg0) != 0) {
        return ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[(u16)arg0])->clear_lock_flag();
    }
    return 0;
}
void TObjPlayer__sub_80354DAC(s32 arg0) {
    if (TObjPlayer__sub_80354E3C(arg0) != 0) {
        TObjPlayer__sub_8035501C(&((E_80354E7C *)lbl_80543984)[(u16)arg0]);
    }
}
void TObjPlayer__sub_80354DF4(s32 arg0) {
    if (TObjPlayer__sub_80354E3C(arg0) != 0) {
        ((TObjPlayer *)&((E_80354E7C *)lbl_80543984)[(u16)arg0])->set_flag1();
    }
}
s32 TObjPlayer__sub_80354E3C(s32 arg0) {
    if (get_player_by_client_id((u16)arg0) == NULL) {
        return 0;
    }
    if (is_locally_controlled__10TObjPlayerFPv() != 0) {
        return 1;
    }
    return 0;
}
void TObjPlayer__sub_80354E7C(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((TObjPlayer *)(&((E_80354E7C *)lbl_80543984)[i]))->reset_field4();
    }
}
void TObjPlayer::finish_quest_thread() { TQuestThread::create_in_root(get_quest_thread_id__10TObjPlayerFPv(this)); }

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

extern "C" {

int set__8FlagWordFUl(void*, int);
int clear__8FlagWordFUl(void*, int);
int test_flags_any(void*, int);

s32 get_quest_thread_id__10TObjPlayerFPv(void* p) { return *(s32*)((char*)p + 0x4); }
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
