#include "types.h"
#include "pso/system/debug_print.h"
#include "pso/misc/TQuestListVM_8007EAF8.h"
#include "pso/misc/TQuestListVM.h"
#include "pso/player/TObjChara.h"

u8 *TObjChara::get_stats() { return m_2b0; }

extern "C" {

void TLobby__sub_8007EB20(s32 arg0, ...);
s32 xfree__FPv();

    extern int TQuestListVM__decrypted_quest_buffer;
int TQuestListVM::get_instance() {  return TQuestListVM__decrypted_quest_buffer; }

void TQuestListVM::reset() { TQuestListVM__decrypted_quest_buffer = 0; }

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
