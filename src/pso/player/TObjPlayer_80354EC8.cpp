#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/player/TObjPlayer_80354EC8.h"
#include "pso/ui/TAdPlyPltAnimCtrlGC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestThread.h"

extern "C" {
s32 __destroy_arr(void *, void *, int, int);
extern u8 lbl_80543984[];
void __register_global_object(void *, void *, void *);
void __construct_array(void *, void *, void *, u32, u32);
extern u8 lbl_80543978[];

void TObjPlayer::finish_quest_thread() { TQuestThread::create_in_root(((int (*)())get_quest_thread_id__10TObjPlayerFPv)()); }

void TObjPlayer__sub_80354EEC(void) {
    __construct_array(lbl_80543984, (void *)init_and_reset_forward__10TObjPlayerFPv, (void *)TObjPlayer__sub_80355098, 8, 4);
    __register_global_object(0, (void *)TObjPlayer::destroy_static_array, lbl_80543978);
}

void TObjPlayer::destroy_static_array() {
    __destroy_arr(lbl_80543984, (void *)TObjPlayer__sub_80355098, 8, 4);
}

}

__declspec(section ".ctors") static void *const __sinit_TObjPlayer_80354EC8_80354EC8_cpp_ref = (void *)TObjPlayer__sub_80354EEC;

#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

extern "C" {

int set__8FlagWordFUl(void*, int);
int clear__8FlagWordFUl(void*, int);
int test_flags_any(void*, int);

s32 get_quest_thread_id__10TObjPlayerFPv(void* p) { return *(s32*)((char*)p + 0x4); }
void TObjPlayer::set_player_index(s32 v) { *(s32*)((char*)this + 0x4) = v; }
void TObjPlayer__sub_80354F8C(void* p) { fn_8035510C((s32 *)p, (s32)((void*)3)); }
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
