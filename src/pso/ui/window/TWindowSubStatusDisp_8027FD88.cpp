#include "types.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80071774.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/player/TObjPlayer_800A7764.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/window/TWindowSubStatusDisp_8027FD88.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/object/TObjLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"

const char *TWindowSubStatusDisp__class_name = "TWindowSubStatusDisp";

extern "C" {
extern "C" u8 lbl_805DD6E0[];
extern "C" u8 lbl_805DD6E4[2];
extern "C" u8 lbl_805DD6E8[];
extern "C" u8 lbl_805DD6EC[];
extern "C" u8 lbl_805DD6F0[];
void *TWindowSubStatusDisp__summary_page_layout[135] = {
    (void *)0x12, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x43520000, (void *)0x0,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E0,
    (void *)0x4, (void *)0x43868000, (void *)0x0, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x1, (void *)0x3,
    (void *)0x0, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x0,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x7, (void *)0x43878000, (void *)0x41a00000,
    (void *)0x42000000, (void *)0x42000000, (void *)0x0, (void *)0x0,
    (void *)0x3f800000, (void *)0x3f800000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x4, (void *)0x3,
    (void *)0x0, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43000000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)&lbl_805DD6E4, (void *)0x4, (void *)0x43670000, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43670000, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E8, (void *)0x3,
    (void *)0x0, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43000000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)&lbl_805DD6E4, (void *)0x4, (void *)0x43670000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43670000, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E8, (void *)0x3,
    (void *)0x0, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43000000,
    (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)&lbl_805DD6E4, (void *)0x4, (void *)0x43670000, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43670000, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0,
};
void *TWindowSubStatusDisp__stat_page_layout[254] = {
    (void *)0x24, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x0,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E4,
    (void *)0x4, (void *)0x42e20000, (void *)0x0, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x0, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6EC, (void *)0x4, (void *)0x432b0000,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x0,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6F0,
    (void *)0x3, (void *)0x0, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6E4, (void *)0x4, (void *)0x42e20000,
    (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42e60000, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6EC,
    (void *)0x4, (void *)0x432b0000, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x432b0000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6F0, (void *)0x3, (void *)0x0,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E4,
    (void *)0x4, (void *)0x42e20000, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6EC, (void *)0x4, (void *)0x432b0000,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6F0,
    (void *)0x3, (void *)0x0, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6E4, (void *)0x4, (void *)0x42e20000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42e60000, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6EC,
    (void *)0x4, (void *)0x432b0000, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x432b0000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6F0, (void *)0x3, (void *)0x0,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E4,
    (void *)0x4, (void *)0x42e20000, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6EC, (void *)0x4, (void *)0x432b0000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6F0,
    (void *)0x3, (void *)0x0, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6E4, (void *)0x4, (void *)0x42e20000,
    (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42e60000, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6EC,
    (void *)0x4, (void *)0x432b0000, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x432b0000, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6F0,
};
void *TWindowSubStatusDisp__resistance_layout[212] = {
    (void *)0x1e, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x0,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E4,
    (void *)0x4, (void *)0x42e20000, (void *)0x0, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x0, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6EC, (void *)0x4, (void *)0x432b0000,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x0,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6F0,
    (void *)0x3, (void *)0x0, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6E4, (void *)0x4, (void *)0x42e20000,
    (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42e60000, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6EC,
    (void *)0x4, (void *)0x432b0000, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x432b0000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6F0, (void *)0x3, (void *)0x0,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E4,
    (void *)0x4, (void *)0x42e20000, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6EC, (void *)0x4, (void *)0x432b0000,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6F0,
    (void *)0x3, (void *)0x0, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6E4, (void *)0x4, (void *)0x42e20000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42e60000, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6EC,
    (void *)0x4, (void *)0x432b0000, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x432b0000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6F0, (void *)0x3, (void *)0x0,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E4,
    (void *)0x4, (void *)0x42e20000, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6EC, (void *)0x4, (void *)0x432b0000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6F0,
};
void *TWindowSubStatusDisp__record_summary_layout[114] = {
    (void *)0x10, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x42600000, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E4, (void *)0x4,
    (void *)0x430a0000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x0,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E4,
    (void *)0x4, (void *)0x430a0000, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x0, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x42600000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)&lbl_805DD6E4, (void *)0x4, (void *)0x430a0000, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x0, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DD6E4, (void *)0x4, (void *)0x430a0000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43060000, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DD6E4, (void *)0x4,
    (void *)0x43580000, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0,
};
void *TWindowSubStatusDisp__rank_time_records_layout[114] = {
    (void *)0x10, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x2, (void *)0x0,
    (void *)0x3, (void *)0x42d40000, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x2, (void *)&lbl_805DD6E4, (void *)0x3,
    (void *)0x42e80000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x2, (void *)0x0, (void *)0x3, (void *)0x0,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x2,
    (void *)0x0, (void *)0x3, (void *)0x42d40000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x2, (void *)&lbl_805DD6E4,
    (void *)0x3, (void *)0x42e80000, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x2, (void *)0x0, (void *)0x3,
    (void *)0x0, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x2, (void *)0x0, (void *)0x3, (void *)0x42d40000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x2,
    (void *)&lbl_805DD6E4, (void *)0x3, (void *)0x42e80000, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x2, (void *)0x0,
    (void *)0x3, (void *)0x0, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x2, (void *)0x0, (void *)0x3,
    (void *)0x42d40000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x2, (void *)&lbl_805DD6E4, (void *)0x3, (void *)0x42e80000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x2,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x2, (void *)0x0,
    (void *)0x3, (void *)0x42d40000, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x2, (void *)&lbl_805DD6E4, (void *)0x3,
    (void *)0x42e80000, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x2, (void *)0x0,
};
void *TWindowSubStatusDisp__numbered_times_layout[72] = {
    (void *)0xa, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x2, (void *)0x0,
    (void *)0x3, (void *)0x0, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x2, (void *)0x0, (void *)0x3,
    (void *)0x0, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x2, (void *)0x0, (void *)0x3, (void *)0x0,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x2,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x2, (void *)0x0,
    (void *)0x3, (void *)0x43200000, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x2, (void *)0x0, (void *)0x3,
    (void *)0x43200000, (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x2, (void *)0x0, (void *)0x3, (void *)0x43200000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x2,
    (void *)0x0, (void *)0x3, (void *)0x43200000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x2, (void *)0x0,
};
void *TWindowSubStatusDisp__window_layout[5] = {
    (void *)0x439c0000, (void *)0x43200000, (void *)0x47438200, (void *)0x0,
    (void *)0x3,
};

}


struct VBase_18_eecf68 { char pad[0x18]; };

struct VObj_18_eecf68 : VBase_18_eecf68 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual s32 m14();
};

struct En_80280F14 { u8 pad[0x20]; s32 v; };

struct Q_80280F14 { u8 pad[0x1C]; s32 a; s32 b; };

struct Wn_80280F14 { u8 pad[0x20]; s16 f20; };

struct VBase_80280FD0 { char pad[0x18]; };

struct VObj_80280FD0 : VBase_80280FD0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual s32 m10();
};

typedef struct Stats_80280B1C {
    s16 v[12];
} Stats_80280B1C;

typedef struct Entry_80280B1C {
    u8 pad0[0x1C];
    s32 color;
    s32 value;
} Entry_80280B1C;

extern "C" {
s32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 TLobby__sub_801C2614();
void *get_array_entry__11TWindowBaseFi(void *, s32);
s32 init_window_layout_entries(void *, void *, s16);
void *get_player_by_client_id(s32 i);
void vt11__20TWindowSubStatusDispFv(Wn_80280F14 *arg0);
}
void set_text_entry_string(u8 *arg0, u32 str, s32 arg2);
extern const f32 TWindowSubStatusDisp__data_805DD708;
s32 get_class_name_text(s32);
extern "C" {
s32 build_player_class_stat_template(s32 arg0, s32 arg1);
s32 build_player_equipment_requirement_stats(int, void *);
s32 get_shared_text_buffer();
s32 get_layout_id__20TWindowSubStatusDispFv(s32);
const s32 status_disp_vt5_message_ids[4] = {0x91, 0x92, 0x91, 0x92};

void fn_8027FD88(void* p, f32 a, f32 b) { *(f32*)((char*)p + 0x6c) = a; *(f32*)((char*)p + 0x70) = b; }
void fn_8027FD94(void* p, s16 v) { *(s16*)((char*)p + 0x62) = v; }

// The record set this page shows: page 2 shows the split-screen sets.
s32 TWindowSubStatusDisp::get_display_mode() {
    s32 r;
    if (page == 2) {
        s8 t = ((TWindowSubStatusDisp *)m_68)->get_type();
        r = RECORD_SET_EP2_SPLIT;
        if (t == 2) r = RECORD_SET_EP1_SPLIT;
        return r;
    }
    return ((TWindowSubStatusDisp *)m_68)->get_type() != 2 ? RECORD_SET_EP2 : RECORD_SET_EP1;
}

void TWindowSubStatusDisp::vt16() {  }

// rank letters by clear rank: "", "B", "A", "S"
extern char *lbl_804D2B20[];

void vt5__20TWindowSubStatusDispFv(u8 *window_base) {
  s32 type;
  s32 n;
  u16 *e;
  s32 r;
  u8 *new_var;
  int new_var2;
  s32 i;
  if (((f32) (*((s32 *) (((s8 *) window_base) + 0x5C)))) > TWindowSubStatusDisp__data_805DD708)
  {
    *((s32 *) (((s8 *) window_base) + 0x5C)) = 7;
  }
  init_window_layout_entries(window_base + 0x24, TWindowSubStatusDisp__numbered_times_layout, *((s16 *) (((s8 *) window_base) + 0x20)));
  new_var = window_base;
  type = ((TWindowSubStatusDisp *)new_var)->get_display_mode();
  e = (u16 *) get_array_entry__11TWindowBaseFi(window_base, 0);
  set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(status_disp_vt5_message_ids[type]), 0);
  n = get_layout_id__20TWindowSubStatusDispFv(type);
  i = 0;
  do
  {
    e = (u16 *) get_array_entry__11TWindowBaseFi(window_base, i + 1);
    new_var2 = n > i;
    if (!new_var2)
    {
      *e |= 2;
    }
    else
    {
      r = TWindowSubStatusDisp__sub_80071A24(i, *((s16 *) (((s8 *) window_base) + 0x20)), type);
      if (r == 0)
      {
        *e |= 2;
      }
      else
      {
        *e &= ~2;
        text_builder_reset();
        append_padded_number(i + 1, 2);
        text_builder_append((u8 *)lbl_805DD6E4);
        TWindowSubStatusDisp::append_play_time(r);
        set_text_entry_string((u8 *)e, get_shared_text_buffer(), 0x20);
      }
    }
    i++;
  }
  while (i < 9);
}

void TWindowSubStatusDisp::vt15() {  }

// Best-time records page: page == 2 shows the split-screen record sets.
void TWindowSubStatusDisp::vt4() {
    if ((f32)(s32)m_5c > TWindowSubStatusDisp__data_805DD708) {
        m_5c = 7;
    }
    init_window_layout_entries(&m_24, TWindowSubStatusDisp__rank_time_records_layout, m_20);
    ((TWindowSubStatusDisp *)m_68)->get_type();
    s32 slot = page == 2 ? RECORD_SET_EP1_SPLIT : RECORD_SET_EP1;
    u16 *entry = (u16 *)get_array_entry(0);
    if (slot == RECORD_SET_EP1) {
        set_text_entry_string((u8 *)entry, (u32)TWindowSubStatusDisp::get_message_10(0x90), 0);
    } else {
        set_text_entry_string((u8 *)entry, (u32)TWindowSubStatusDisp::get_message_10(0x93), 0);
    }

    entry = (u16 *)get_array_entry(1);
    u16 *value = (u16 *)get_array_entry(2);
    u16 *label = (u16 *)get_array_entry(3);
    s8 *player_name = (s8 *)TWindowSubStatusDisp::get_status_window(m_20);
    if (slot != RECORD_SET_EP1 || player_name == NULL || *player_name == 0) {
        *entry |= 2;
        *value |= 2;
        *label |= 2;
    } else {
        *entry &= ~2;
        *value &= ~2;
        *label &= ~2;
        set_text_entry_string((u8 *)entry, (u32)TWindowSubStatusDisp::get_message_10(0x9B), 0);
        set_text_entry_string((u8 *)label, (u32)player_name, 0x20);
        *(s32 *)((u8 *)label + 0x24) = TWindowSubStatusDisp::get_status_index(m_20);
    }

    entry = (u16 *)get_array_entry(4);
    value = (u16 *)get_array_entry(5);
    label = (u16 *)get_array_entry(6);
    s32 rank = TWindowSubStatusDisp__sub_80071868(m_20, slot);
    if (rank == 0) {
        *entry |= 2;
        *value |= 2;
        *label |= 2;
    } else {
        *entry &= ~2;
        *value &= ~2;
        *label &= ~2;
        if (slot == RECORD_SET_EP1) {
            set_text_entry_string((u8 *)entry, (u32)TWindowSubStatusDisp::get_message_10(0x98), 0);
        } else {
            set_text_entry_string((u8 *)entry, (u32)TWindowSubStatusDisp::get_message_10(0x9A), 0);
        }
        set_text_entry_string((u8 *)label, (u32)lbl_804D2B20[rank], 0);
    }

    entry = (u16 *)get_array_entry(7);
    value = (u16 *)get_array_entry(8);
    label = (u16 *)get_array_entry(9);
    s32 time = TWindowSubStatusDisp__sub_80071988(m_20, slot);
    if (time == 0) {
        *entry |= 2;
        *value |= 2;
        *label |= 2;
    } else {
        *entry &= ~2;
        *value &= ~2;
        *label &= ~2;
        if (slot == RECORD_SET_EP1) {
            set_text_entry_string((u8 *)entry, (u32)TWindowSubStatusDisp::get_message_10(0x95), 0);
        } else {
            set_text_entry_string((u8 *)entry, (u32)TWindowSubStatusDisp::get_message_10(0x97), 0);
        }
        text_builder_reset();
        TWindowSubStatusDisp::append_play_time(time);
        set_text_entry_string((u8 *)label, get_shared_text_buffer(), 0x20);
    }

    slot = RECORD_SET_EP2;
    if (page == 2) {
        slot = RECORD_SET_EP2_SPLIT;
    }
    entry = (u16 *)get_array_entry(0xA);
    value = (u16 *)get_array_entry(0xB);
    label = (u16 *)get_array_entry(0xC);
    rank = TWindowSubStatusDisp__sub_80071868(m_20, slot);
    if (rank == 0) {
        *entry |= 2;
        *value |= 2;
        *label |= 2;
    } else {
        *entry &= ~2;
        *value &= ~2;
        *label &= ~2;
        set_text_entry_string((u8 *)entry, (u32)TWindowSubStatusDisp::get_message_10(0x99), 0);
        set_text_entry_string((u8 *)label, (u32)lbl_804D2B20[rank], 0);
    }

    entry = (u16 *)get_array_entry(0xD);
    value = (u16 *)get_array_entry(0xE);
    label = (u16 *)get_array_entry(0xF);
    time = TWindowSubStatusDisp__sub_80071988(m_20, slot);
    if (time == 0) {
        *entry |= 2;
        *value |= 2;
        *label |= 2;
    } else {
        *entry &= ~2;
        *value &= ~2;
        *label &= ~2;
        set_text_entry_string((u8 *)entry, (u32)TWindowSubStatusDisp::get_message_10(0x96), 0);
        text_builder_reset();
        TWindowSubStatusDisp::append_play_time(time);
        set_text_entry_string((u8 *)label, get_shared_text_buffer(), 0x20);
    }
}

void TWindowSubStatusDisp::vt18() {  }

void vt7__20TWindowSubStatusDispFv(u8 *window_base) {
    u8 *temp_r30;
    if ((f32) *(s32 *)((s8 *)window_base + 0x5C) > TWindowSubStatusDisp__data_805DD708) {
        *(s32 *)((s8 *)window_base + 0x5C) = 7;
    }
    init_window_layout_entries(window_base + 0x24, TWindowSubStatusDisp__record_summary_layout, *(s16 *)((s8 *)window_base + 0x20));
    temp_r30 = (u8 *)get_array_entry__11TWindowBaseFi(window_base, 0);
    set_text_entry_string(temp_r30, get_message_10__20TWindowSubStatusDispFl(0x8F), 0);
    temp_r30 = (u8 *)get_array_entry__11TWindowBaseFi(window_base, 1);
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 6), 0);
    temp_r30 = (u8 *)get_array_entry__11TWindowBaseFi(window_base, 4);
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 7), 0);
    temp_r30 = (u8 *)get_array_entry__11TWindowBaseFi(window_base, 7);
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 8), 0);
    temp_r30 = (u8 *)get_array_entry__11TWindowBaseFi(window_base, 0xA);
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 9), 0);
    ((TWindowHelpItem *)(get_array_entry__11TWindowBaseFi(window_base, 0xD)))->set_flag0_bit2();
    ((TWindowHelpItem *)(get_array_entry__11TWindowBaseFi(window_base, 0xE)))->set_flag0_bit2();
    temp_r30 = (u8 *)get_array_entry__11TWindowBaseFi(window_base, 3);
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_state((u16) *(s16 *)((s8 *)window_base + 0x20));
    temp_r30 = (u8 *)get_array_entry__11TWindowBaseFi(window_base, 6);
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC__sub_801FC36C((u16) *(s16 *)((s8 *)window_base + 0x20));
    temp_r30 = (u8 *)get_array_entry__11TWindowBaseFi(window_base, 9);
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_window_status((u16) *(s16 *)((s8 *)window_base + 0x20));
    temp_r30 = (u8 *)get_array_entry__11TWindowBaseFi(window_base, 0xC);
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_window_field((u16) *(s16 *)((s8 *)window_base + 0x20));
    ((TWindowHelpItem *)(get_array_entry__11TWindowBaseFi(window_base, 0xF)))->set_flag0_bit2();
}

void TWindowSubStatusDisp::vt14() {  }

void vt3__20TWindowSubStatusDispFv(u8 *window_base) {
    s32 card_flag;
    u8 *temp_r30;
    if ((f32) *(s32 *)((s8 *)window_base + 0x5C) > TWindowSubStatusDisp__data_805DD708) {
        *(s32 *)((s8 *)window_base + 0x5C) = 7;
    }
    init_window_layout_entries(window_base + 0x24, TWindowSubStatusDisp__record_summary_layout, *(s16 *)((s8 *)window_base + 0x20));
    temp_r30 = ((u8 *)get_array_entry__11TWindowBaseFi(window_base, 0));
    set_text_entry_string(temp_r30, get_message_10__20TWindowSubStatusDispFl(0x8E), 0);
    temp_r30 = ((u8 *)get_array_entry__11TWindowBaseFi(window_base, 1));
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 6), 0);
    temp_r30 = ((u8 *)get_array_entry__11TWindowBaseFi(window_base, 4));
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 7), 0);
    temp_r30 = ((u8 *)get_array_entry__11TWindowBaseFi(window_base, 7));
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 8), 0);
    temp_r30 = ((u8 *)get_array_entry__11TWindowBaseFi(window_base, 0xA));
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 9), 0);
    temp_r30 = ((u8 *)get_array_entry__11TWindowBaseFi(window_base, 0xD));
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 0xE), 0);
    temp_r30 = ((u8 *)get_array_entry__11TWindowBaseFi(window_base, 3));
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_field_21a8((u16) *(s16 *)((s8 *)window_base + 0x20));
    temp_r30 = ((u8 *)get_array_entry__11TWindowBaseFi(window_base, 6));
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_value((u16) *(s16 *)((s8 *)window_base + 0x20));
    temp_r30 = ((u8 *)get_array_entry__11TWindowBaseFi(window_base, 9));
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_status((u16) *(s16 *)((s8 *)window_base + 0x20));
    temp_r30 = ((u8 *)get_array_entry__11TWindowBaseFi(window_base, 0xC));
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_field((u16) *(s16 *)((s8 *)window_base + 0x20));
    card_flag = TAdSinglePlyChrSelectGC::get_card_flag((u16) *(s16 *)((s8 *)window_base + 0x20));
    if (TLobby__sub_801C2614() != 0) {
        card_flag -= 1;
    }
    *(s32 *)((s8 *)((u8 *)get_array_entry__11TWindowBaseFi(window_base, 0xF)) + 0x20) = (s32) card_flag;
}

void TWindowSubStatusDisp::vt13() {
    s32 player;
    void *temp_r31;
    void *temp_r31_2;
    void *temp_r31_3;
    void *temp_r31_4;
    void *temp_r31_5;

    player = (s32)get_player_by_client_id(this->m_20);
    if (player != 0) {
        temp_r31 = get_array_entry__11TWindowBaseFi(this, 2);
        *(s32 *)((s8 *)temp_r31 + 0x20) = (s32) ((TWindowSubStatusDisp *)player)->get_stat();
        temp_r31_2 = get_array_entry__11TWindowBaseFi(this, 8);
        *(s32 *)((s8 *)temp_r31_2 + 0x20) = (s32) ((TObjPlayer *)player)->get_class_id();
        temp_r31_3 = get_array_entry__11TWindowBaseFi(this, 0xE);
        *(s32 *)((s8 *)temp_r31_3 + 0x20) = (s32) ((TObjPlayer *)player)->get_item_index();
        temp_r31_4 = get_array_entry__11TWindowBaseFi(this, 0x14);
        *(s32 *)((s8 *)temp_r31_4 + 0x20) = (s32) ((TWindowSubStatusDisp *)player)->get_field_2F8();
        temp_r31_5 = get_array_entry__11TWindowBaseFi(this, 0x1A);
        *(s32 *)((s8 *)temp_r31_5 + 0x20) = (s32) ((TWindowSubStatusDisp *)player)->get_item_type();
    }
}
void vt2__20TWindowSubStatusDispFv(u8 *window_base) {
    s32 temp_r30;
    if ((f32) *(s32 *)((s8 *)window_base + 0x5C) > TWindowSubStatusDisp__data_805DD708) {
        *(s32 *)((s8 *)window_base + 0x5C) = 7;
    }
    init_window_layout_entries(window_base + 0x24, TWindowSubStatusDisp__resistance_layout, *(s16 *)((s8 *)window_base + 0x20));
    temp_r30 = ((s32)get_array_entry__11TWindowBaseFi(window_base, 0));
    set_text_entry_string((u8 *)temp_r30, (get_message_10__20TWindowSubStatusDispFl(0x89)), 0x20);
    temp_r30 = ((s32)get_array_entry__11TWindowBaseFi(window_base, 6));
    set_text_entry_string((u8 *)temp_r30, (get_message_10__20TWindowSubStatusDispFl(0x8A)), 0x20);
    temp_r30 = ((s32)get_array_entry__11TWindowBaseFi(window_base, 0xC));
    set_text_entry_string((u8 *)temp_r30, (get_message_10__20TWindowSubStatusDispFl(0x8B)), 0x20);
    temp_r30 = ((s32)get_array_entry__11TWindowBaseFi(window_base, 0x12));
    set_text_entry_string((u8 *)temp_r30, (get_message_10__20TWindowSubStatusDispFl(0x8C)), 0x20);
    temp_r30 = ((s32)get_array_entry__11TWindowBaseFi(window_base, 0x18));
    set_text_entry_string((u8 *)temp_r30, (get_message_10__20TWindowSubStatusDispFl(0x8D)), 0x20);
}

void vt12__20TWindowSubStatusDispFv(u8 *window_base) {
    Stats_80280B1C cur;
    Stats_80280B1C req;
    Entry_80280B1C *e2;
    s32 pl;
    Entry_80280B1C *e;
    u8 *q;
    ((TWindowSubStatusDisp *)(&cur))->clear_fields();
    ((TWindowSubStatusDisp *)(&req))->clear_fields();
    pl = (s32)get_player_by_client_id(*(s16 *)(window_base + 0x20));
    if (pl != 0) {
        e2 = (Entry_80280B1C *)get_array_entry__11TWindowBaseFi(window_base, 2);
        e2->value = TObjPlayer__sub_800A776C((void *)pl) + (((TObjPlayer *)pl)->get_field_2c8() + ((TObjPlayer *)pl)->get_actor_attack_params_atp_min());
        e = (Entry_80280B1C *)get_array_entry__11TWindowBaseFi(window_base, 8);
        e->value = ((TWindowSubStatusDisp *)pl)->get_value();
        e = (Entry_80280B1C *)get_array_entry__11TWindowBaseFi(window_base, 0x14);
        e->value = ((TObjPlayer *)pl)->get_ata();
        e = (Entry_80280B1C *)get_array_entry__11TWindowBaseFi(window_base, 0x1A);
        e->value = ((TObjPlayer *)pl)->get_hp();
        q = ((TObjPlayer *)pl)->get_stats();
        if (q != NULL) {
            e = (Entry_80280B1C *)get_array_entry__11TWindowBaseFi(window_base, 0xE);
            e->value = *(s16 *)(q + 2);
            e = (Entry_80280B1C *)get_array_entry__11TWindowBaseFi(window_base, 0x20);
            e->value = *(s16 *)(q + 0xC);
        }
    }
    if (build_player_equipment_requirement_stats(pl, &cur) != 0) {
        build_player_class_stat_template(pl, (s32)&req);
#define ROW(idx, k) \
        e = (Entry_80280B1C *)get_array_entry__11TWindowBaseFi(window_base, idx); \
        e->value = cur.v[k]; \
        if (req.v[k] <= cur.v[k]) { e->color = -0x100; } else { e->color = -1; }
        ROW(4, 0)
        ROW(0xA, 1)
        ROW(0x16, 3)
        ROW(0x1C, 4)
        ROW(0x10, 2)
        ROW(0x22, 5)
#undef ROW
    }
}

void vt1__20TWindowSubStatusDispFv(u8 *window_base) {
    void *e;
    if ((f32) *(s32 *)((s8 *)window_base + 0x5C) > TWindowSubStatusDisp__data_805DD708) {
        *(s32 *)((s8 *)window_base + 0x5C) = 7;
    }
    init_window_layout_entries(window_base + 0x24, TWindowSubStatusDisp__stat_page_layout, *(s16 *)((s8 *)window_base + 0x20));
    e = get_array_entry__11TWindowBaseFi(window_base, 0);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x83), 0x20);
    e = get_array_entry__11TWindowBaseFi(window_base, 6);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x84), 0x20);
    e = get_array_entry__11TWindowBaseFi(window_base, 0xC);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x85), 0x20);
    e = get_array_entry__11TWindowBaseFi(window_base, 0x12);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x86), 0x20);
    e = get_array_entry__11TWindowBaseFi(window_base, 0x18);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x87), 0x20);
    e = get_array_entry__11TWindowBaseFi(window_base, 0x1E);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x88), 0x20);
}

void vt11__20TWindowSubStatusDispFv(Wn_80280F14 *arg0) {
    VObj_18_eecf68 *p;
    Q_80280F14 *q;
    En_80280F14 *e;
    p = ((VObj_18_eecf68 *)get_player_by_client_id(arg0->f20));
    if (p != NULL) {
        q = (Q_80280F14 *)((TObjPlayer *)p)->get_stats();
        if (q != NULL) {
            e = ((En_80280F14 *)get_array_entry__11TWindowBaseFi(arg0, 2));
            e->v = p->m14() + 1;
            e = ((En_80280F14 *)get_array_entry__11TWindowBaseFi(arg0, 0x10));
            e->v = q->b;
            e = ((En_80280F14 *)get_array_entry__11TWindowBaseFi(arg0, 8));
            e->v = q->a;
            e = ((En_80280F14 *)get_array_entry__11TWindowBaseFi(arg0, 0xC));
            e->v = ((TObjPlayer *)p)->get_next_level_exp() - q->a;
        }
    }
}
void vt0__20TWindowSubStatusDispFv(u8 *window_base) {
    void *e;
    u8 *pl;
    s32 v;
    s8 *st;
    if ((f32) *(s32 *)((s8 *)window_base + 0x5C) > TWindowSubStatusDisp__data_805DD708) {
        *(s32 *)((s8 *)window_base + 0x5C) = 7;
    }
    init_window_layout_entries(window_base + 0x24, TWindowSubStatusDisp__summary_page_layout, *(s16 *)((s8 *)window_base + 0x20));
    e = get_array_entry__11TWindowBaseFi(window_base, 6);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x80), 0x20);
    e = get_array_entry__11TWindowBaseFi(window_base, 0xA);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x81), 0x20);
    e = get_array_entry__11TWindowBaseFi(window_base, 0xE);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x82), 0x20);
    e = get_array_entry__11TWindowBaseFi(window_base, 0x11);
    set_text_entry_string((u8 *)e, TWindowSubStatusDisp::get_download_server(), 0x20);
    pl = (u8 *)get_player_by_client_id(*(s16 *)((s8 *)window_base + 0x20));
    if (pl != NULL) {
        st = (s8 *)(pl + 0x85C);
        if (st != NULL) {
            v = ((VObj_80280FD0 *)pl)->m10();
            set_text_entry_string((u8 *)(get_array_entry__11TWindowBaseFi(window_base, 0)), v, 0x20);
            v = get_class_name_text(st[0x31]);
            set_text_entry_string((u8 *)(get_array_entry__11TWindowBaseFi(window_base, 3)), v, 0);
            v = TObjLuker::get_stat_table_entry(st[0x30]);
            set_text_entry_string((u8 *)(get_array_entry__11TWindowBaseFi(window_base, 4)), v, 0);
        }
        e = get_array_entry__11TWindowBaseFi(window_base, 5);
        *(u8 **)((s8 *)e + 0x30) = window_base + 0x64;
        *(u8 **)((s8 *)window_base + 0x64) = pl + 0xCF4;
    }
}
}


#include "types.h"

struct SD_80281760 { const char *f0; u8 pad4[0x14]; void *vt; u8 pad1c[4]; s16 f20; u8 pad22[0x3E]; s16 f60; s16 f62; u8 pad64[4]; void *f68; f32 f6c; f32 f70; };

extern "C" {
s32 fn_8026C7AC(void *arg0, s8 arg1);
s32 handle_list_page_flip_input(int);
extern s32 lbl_805DD6F4;
void *init__21TWindowSubComCardListFiii(void *, int, int, s32);
s32 get_window_layout_position(int);

extern s32 __vt__20TWindowSubStatusDisp[];
extern const f32 lbl_805DD70C;
SD_80281760 *TWindowSubStatusDisp__ct(SD_80281760 *arg0, s32 arg1);
void *get_player_by_client_id(s32 i);
s32 draw_visible_window_entries(void *, void *, s32);
s32 draw_list_page_indicator(s32, s32);
void __dl__7TObjectFPv(void *);
}
s32 delete_if_allocated(s32 arg0, s16 arg1);
#pragma defer_codegen on
void TWindowSubStatusDisp::dispatch_page_init() {
    static void (TWindowSubStatusDisp::*page0[3])() = {
        &TWindowSubStatusDisp::vt0, &TWindowSubStatusDisp::vt1, &TWindowSubStatusDisp::vt2,
    };
    static void (TWindowSubStatusDisp::*page1[4])() = {
        &TWindowSubStatusDisp::vt3, &TWindowSubStatusDisp::vt4, &TWindowSubStatusDisp::vt5,
        &TWindowSubStatusDisp::vt5,
    };
    static void (TWindowSubStatusDisp::*page2[4])() = {
        &TWindowSubStatusDisp::vt7, &TWindowSubStatusDisp::vt4, &TWindowSubStatusDisp::vt5,
        &TWindowSubStatusDisp::vt5,
    };

    switch (page) {
    case 0:
        (this->*page0[((TWindowSubStatusDisp *)m_68)->get_type()])();
        break;
    case 1:
        (this->*page1[((TWindowSubStatusDisp *)m_68)->get_type()])();
        break;
    case 2:
        (this->*page2[((TWindowSubStatusDisp *)m_68)->get_type()])();
        break;
    }
}

void TWindowSubStatusDisp::dispatch_page_update() {
    static void (TWindowSubStatusDisp::*page0[3])() = {
        &TWindowSubStatusDisp::vt11, &TWindowSubStatusDisp::vt12, &TWindowSubStatusDisp::vt13,
    };
    static void (TWindowSubStatusDisp::*page1[4])() = {
        &TWindowSubStatusDisp::vt14, &TWindowSubStatusDisp::vt15, &TWindowSubStatusDisp::vt16,
        &TWindowSubStatusDisp::vt16,
    };
    static void (TWindowSubStatusDisp::*page2[4])() = {
        &TWindowSubStatusDisp::vt18, &TWindowSubStatusDisp::vt15, &TWindowSubStatusDisp::vt16,
        &TWindowSubStatusDisp::vt16,
    };

    switch (page) {
    case 0:
        (this->*page0[((TWindowSubStatusDisp *)m_68)->get_type()])();
        break;
    case 1:
        (this->*page1[((TWindowSubStatusDisp *)m_68)->get_type()])();
        break;
    case 2:
        (this->*page2[((TWindowSubStatusDisp *)m_68)->get_type()])();
        break;
    }
}

#pragma defer_codegen off

void TWindowSubStatusDisp::render() {
    s32 temp_r3;

    if (get_player_by_client_id(this->m_20) != 0U) {
        temp_r3 = this->setup_window_draw_context((s32)(((u8 *)this) + 0x6C));
        draw_window_frame((void *)temp_r3);
        draw_visible_window_entries(this, ((u8 *)this) + 0x24, temp_r3);
        draw_list_page_indicator(this->m_68, temp_r3);
    }
}

void TWindowSubStatusDisp::run_task() {
    TWindowSubStatusDisp *arg0 = (TWindowSubStatusDisp *)this;
  if (!((arg0->m_2c) & 2))
  {
    *(s32 *)&arg0->m_5c = 0x01000000;
  }
  if ((handle_list_page_flip_input((int) (*(s32 *)&arg0->m_68)) != 0) || ((arg0->page) != ((s16) (*(s16 *)&arg0->m_62))))
  {
    if ((arg0->page) != (*(s16 *)&arg0->m_62))
    {
      arg0->page = *(s16 *)&arg0->m_62;
      fn_8026C7AC((void *)(*(s32 *)&arg0->m_68), ((s8) (*((u8 *) (((s8 *) (((u8 *)&lbl_805DD6F4) + (arg0->page))) + 0)))));
    }
    ((TWindowSubStatusDisp *)(((u8 *) arg0) + 0x24))->destroy_all_items();
    arg0->dispatch_page_init();
  }
  arg0->dispatch_page_update();
  ((TWindowDD *)arg0)->initialize_subwindow();
  ((TWindowBase *)arg0)->update_window_entry_list((void *) (((u8 *) arg0) + 0x24));
}

void *TWindowSubStatusDisp::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__20TWindowSubStatusDisp;
        delete_if_allocated(this->m_68, 1);
        __dt__11TWindowBaseFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
SD_80281760 *TWindowSubStatusDisp__ct(SD_80281760 *arg0, s32 arg1) {
    void *w;
    __ct__11TWindowBaseFPUcsPUc(arg0, (u8 *)TWindowSubStatusDisp__window_layout, (s16)arg1, (u8 *)(get_window_layout_position(0x19)));
    arg0->vt = ((u8 *)&__vt__20TWindowSubStatusDisp);
    arg0->f0 = TWindowSubStatusDisp__class_name;
    arg0->f20 = arg1;
    arg0->f60 = 0;
    arg0->f62 = arg0->f60;
    arg0->f6c = lbl_805DD70C;
    arg0->f70 = lbl_805DD70C;
    w = ::operator new(0xC);
    if (w != NULL) {
        w = init__21TWindowSubComCardListFiii(w, 0, 3, arg1);
    }
    arg0->f68 = w;
    ((TWindowSubStatusDisp *)arg0)->dispatch_page_init();
    return arg0;
}
