#include "types.h"
#include "pso/system/debug_print.h"
#include "pso/system/memory.h"
#include "pso/network/TProtocol.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TUnk_8048DF58.h"
#include "pso/unk/text_803DE864.h"
#include "pso/player/TPlyDispData.h"

// One TU .text 0x8007EAF8-0x8007ECF0: its .sdata holds enable_v2_features, its .data the TUnk_8048DF58 vtable.
int enable_v2_features = 1;

player_stats *TObjChara::get_stats() { return stat_block; }

u8 *TQuestListVM::get_quest_bin() { return decrypted_quest_buffer; }

void TQuestListVM::reset() { decrypted_quest_buffer = NULL; }

TQuestVmDownLoadServer *TQuestVmDownLoadServer__sub_8007EB14(void) {
    return TQuestVmDownLoadServer__instance;
}

void debug_print(const char *text) {

}

void TLobby__sub_8007EB20(const char *format, ...) {}

void TLobby__sub_8007EB70(void) {}

void operator delete(void *p) {
    xfree(p);
}

void *operator new(size_t size) { return xmalloc(size); }

void safe_free(void *allocation) {
    if (allocation != NULL) {
        xfree(allocation);
    }
}

u8 *TQuestVmDownLoadServer__sub_8007EBDC(s32 a, s32 b) { return fn_803DE864(a, b); }

void *TQuestVmDownLoadServer::alloc(u32 size) { return xmalloc(size); }

// The unit's global TUnk_8048DF58: __sinit constructs it and registers its destructor.
TUnk_8048DF58 lbl_805005A4;
#pragma push
#pragma force_active on
u8 lbl_805005C0[0x10];
CameraParams *demo_camera_params_table[16];
#pragma pop
