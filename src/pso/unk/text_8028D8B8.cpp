#include "types.h"
#include "pso/menu/TChCrEffWall.h"
#include "pso/misc/TChCrEffTag_8029ACA8.h"
#include "pso/unk/text_8028D8B8.h"
#include "pso/misc/TQuestVmDownLoadServer.h"

struct RecoveredGlobal_8028D940_lbl_8051C070 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8028D8F4_lbl_8051C070 {
    s32 value;
    u8 remaining[0x8];
};

extern "C" {
s32 TChCrEffCtrlPl__sub_80298F6C(void);
s32 create__14TChCrEffCtrlPlFv(s32);
extern RecoveredGlobal_8028D940_lbl_8051C070 lbl_8051C070;
extern s32 tl_03;
void queue_destruction__7TObjectFv(void *arg0);
}
extern void *chr_select_load_buffer_base;
typedef char RecoveredGlobal_8028D940_lbl_8051C070_size[sizeof(RecoveredGlobal_8028D940_lbl_8051C070) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_8028D8F4_lbl_8051C070_size[sizeof(RecoveredGlobal_8028D8F4_lbl_8051C070) == 0xC ? 1 : -1];

void alloc_quest_download_buffer(void) {
    if (chr_select_load_buffer_base == 0) {
        if ((chr_select_load_buffer_base = TQuestVmDownLoadServer::alloc(0x28000)) == 0) return;
    }
}

void fn_8028D8F4(void) {
    if ((u32) *(u32 *)((s8 *)(&(*(RecoveredGlobal_8028D8F4_lbl_8051C070 *)&lbl_8051C070).value) + 0) != 0U) {
        queue_destruction__7TObjectFv((void *)(*(u32 *)((s8 *)(&(*(RecoveredGlobal_8028D8F4_lbl_8051C070 *)&lbl_8051C070).value) + 0)));
    }
    if ((u32) *(u32 *)((s8 *)(&(*(RecoveredGlobal_8028D8F4_lbl_8051C070 *)&lbl_8051C070).value) + 4) != 0U) {
        queue_destruction__7TObjectFv((void *)(*(u32 *)((s8 *)(&(*(RecoveredGlobal_8028D8F4_lbl_8051C070 *)&lbl_8051C070).value) + 4)));
    }
}

void fn_8028D940(void) {
    *(s32 *)((s8 *)&lbl_8051C070.value + 0) = (s32)fn_8029AE88((void *)tl_03);
    *(s32 *)((s8 *)&lbl_8051C070.value + 4) = (s32)create_TChCrEffTag((void *)tl_03);
    *(s32 *)((s8 *)&lbl_8051C070.value + 8) = 0;
    if (TChCrEffCtrlPl__sub_80298F6C() != 0) {
        *(s32 *)((s8 *)&lbl_8051C070.value + 8) = create__14TChCrEffCtrlPlFv(tl_03);
    }
}
