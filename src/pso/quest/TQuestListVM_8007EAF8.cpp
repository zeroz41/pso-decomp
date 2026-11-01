#include "types.h"
#include "pso/system/debug_print.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/player/TObjChara.h"

u8 *TObjChara::get_stats() { return m_2b0; }

extern "C" {

void TLobby__sub_8007EB20(s32 arg0, ...);
s32 xfree__FPv();

u8 *TQuestListVM::get_quest_bin() { return decrypted_quest_buffer; }

void TQuestListVM::reset() { decrypted_quest_buffer = NULL; }

extern s32 TQuestVmDownLoadServer__instance;

s32 TQuestVmDownLoadServer__sub_8007EB14(void) {
    return TQuestVmDownLoadServer__instance;
}

}

void debug_print(const char *text) {

}

extern "C" {

void TLobby__sub_8007EB20(s32 arg0, ...) {}
void TLobby__sub_8007EB70(void) {  }

void __dl__FPv(void) {
    xfree__FPv();
}

}
