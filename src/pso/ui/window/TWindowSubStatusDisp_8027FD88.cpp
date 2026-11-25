#include "pso/player/TPlyDispData.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/PageIndicator.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80071774.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/enemy/dimedian/TObjEneDimedian.h"
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
#include "pso/ui/window/WindowLayout.h"
#include "pso/unk/text_8026C7AC.h"
#include "pso/player/PlayerRequirementStats.h"

const char *TWindowSubStatusDisp__class_name = "TWindowSubStatusDisp";
void *TWindowSubStatusDisp::summary_page_layout[135] = {
    (void *)0x12, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x43520000, (void *)0x0,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)"Lv",
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
    (void *)":", (void *)0x4, (void *)0x43670000, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43670000, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)"pt", (void *)0x3,
    (void *)0x0, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43000000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)":", (void *)0x4, (void *)0x43670000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43670000, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)"pt", (void *)0x3,
    (void *)0x0, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43000000,
    (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)":", (void *)0x4, (void *)0x43670000, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43670000, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0,
};
void *TWindowSubStatusDisp::stat_page_layout[254] = {
    (void *)0x24, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x0,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)":",
    (void *)0x4, (void *)0x42e20000, (void *)0x0, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x0, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)"(", (void *)0x4, (void *)0x432b0000,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x0,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)")",
    (void *)0x3, (void *)0x0, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)":", (void *)0x4, (void *)0x42e20000,
    (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42e60000, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)"(",
    (void *)0x4, (void *)0x432b0000, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x432b0000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)")", (void *)0x3, (void *)0x0,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)":",
    (void *)0x4, (void *)0x42e20000, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)"(", (void *)0x4, (void *)0x432b0000,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)")",
    (void *)0x3, (void *)0x0, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)":", (void *)0x4, (void *)0x42e20000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42e60000, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)"(",
    (void *)0x4, (void *)0x432b0000, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x432b0000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)")", (void *)0x3, (void *)0x0,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)":",
    (void *)0x4, (void *)0x42e20000, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)"(", (void *)0x4, (void *)0x432b0000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)")",
    (void *)0x3, (void *)0x0, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)":", (void *)0x4, (void *)0x42e20000,
    (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42e60000, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)"(",
    (void *)0x4, (void *)0x432b0000, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x432b0000, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)")",
};
void *TWindowSubStatusDisp::resistance_layout[212] = {
    (void *)0x1e, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x0,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)":",
    (void *)0x4, (void *)0x42e20000, (void *)0x0, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x0, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)"(", (void *)0x4, (void *)0x432b0000,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x0,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)")",
    (void *)0x3, (void *)0x0, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)":", (void *)0x4, (void *)0x42e20000,
    (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42e60000, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)"(",
    (void *)0x4, (void *)0x432b0000, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x432b0000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)")", (void *)0x3, (void *)0x0,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)":",
    (void *)0x4, (void *)0x42e20000, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)"(", (void *)0x4, (void *)0x432b0000,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)")",
    (void *)0x3, (void *)0x0, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)":", (void *)0x4, (void *)0x42e20000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42e60000, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)"(",
    (void *)0x4, (void *)0x432b0000, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x432b0000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)")", (void *)0x3, (void *)0x0,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)":",
    (void *)0x4, (void *)0x42e20000, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42e60000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)"(", (void *)0x4, (void *)0x432b0000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x432b0000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)")",
};
void *TWindowSubStatusDisp::record_summary_layout[114] = {
    (void *)0x10, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x42600000, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)":", (void *)0x4,
    (void *)0x430a0000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x0,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x42600000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)":",
    (void *)0x4, (void *)0x430a0000, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x0, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x42600000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)":", (void *)0x4, (void *)0x430a0000, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x0, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x42600000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)":", (void *)0x4, (void *)0x430a0000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43060000, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)":", (void *)0x4,
    (void *)0x43580000, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0,
};
void *TWindowSubStatusDisp::rank_time_records_layout[114] = {
    (void *)0x10, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x2, (void *)0x0,
    (void *)0x3, (void *)0x42d40000, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x2, (void *)":", (void *)0x3,
    (void *)0x42e80000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x2, (void *)0x0, (void *)0x3, (void *)0x0,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x2,
    (void *)0x0, (void *)0x3, (void *)0x42d40000, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x2, (void *)":",
    (void *)0x3, (void *)0x42e80000, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x2, (void *)0x0, (void *)0x3,
    (void *)0x0, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x2, (void *)0x0, (void *)0x3, (void *)0x42d40000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x2,
    (void *)":", (void *)0x3, (void *)0x42e80000, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x2, (void *)0x0,
    (void *)0x3, (void *)0x0, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x2, (void *)0x0, (void *)0x3,
    (void *)0x42d40000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x2, (void *)":", (void *)0x3, (void *)0x42e80000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x2,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x2, (void *)0x0,
    (void *)0x3, (void *)0x42d40000, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x2, (void *)":", (void *)0x3,
    (void *)0x42e80000, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x2, (void *)0x0,
};
void *TWindowSubStatusDisp::numbered_times_layout[72] = {
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
void *TWindowSubStatusDisp::window_layout[5] = {
    (void *)0x439c0000, (void *)0x43200000, (void *)0x47438200, (void *)0x0,
    (void *)0x3,
};

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

typedef struct Entry_80280B1C {
    u8 pad0[0x1C];
    s32 color;
    s32 value;
} Entry_80280B1C;
extern "C" {
s32 is_battle_mode_running();
}
void set_text_entry_string(u8 *arg0, uaddr str, s32 arg2);
s32 get_class_name_text(s32);
extern "C" {
s32 get_shared_text_buffer();
const s32 status_disp_vt5_message_ids[4] = {0x91, 0x92, 0x91, 0x92};
}

#include "types.h"
#include "pso/player/PlayerSlots.h"


// list type of m_68 per page: the page-flip list kind passed to fn_8026C7AC
const u8 lbl_805DD6F4[4] = {3, 4, 4, 0};

TWindowSubStatusDisp::TWindowSubStatusDisp(s32 client)
    : TWindowBase((u8 *)TWindowSubStatusDisp::window_layout, client, (u8 *)get_window_layout_position(0x19)) {
    m_name = TWindowSubStatusDisp__class_name;
    client_index = client;
    page = 0;
    requested_page = page;
    scale_x = 1.0f;
    scale_y = 1.0f;
    m_68 = new PageIndicator(0, 3, client);
    dispatch_page_init();
}

TWindowSubStatusDisp::~TWindowSubStatusDisp() {
    delete_if_allocated(m_68, 1);
}

void TWindowSubStatusDisp::run_task() {
  if (!((this->window_flags) & 2))
  {
    this->open_tick = 0x01000000;
  }
  if ((handle_list_page_flip_input(this->m_68) != 0) || ((this->page) != (this->requested_page)))
  {
    if ((this->page) != (this->requested_page))
    {
      this->page = this->requested_page;
      fn_8026C7AC(this->m_68, lbl_805DD6F4[this->page]);
    }
    this->entry_list.destroy_all_items();
    this->dispatch_page_init();
  }
  this->dispatch_page_update();
  update_window();
  ((TWindowBase *)this)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((void *) (((u8 *) this) + 0x24)));
}

void TWindowSubStatusDisp::render() {
    saddr context;

    if (get_player_by_client_id(this->client_index) != 0U) {
        context = reinterpret_cast<saddr>(this->setup_window_draw_context(&this->scale_x));
        draw_window_frame((void *)context);
        draw_visible_window_entries(
            this,
            reinterpret_cast<const WindowLayoutEntries *>(((u8 *)this) + 0x24),
            reinterpret_cast<WindowDrawContext *>(context));
        draw_list_page_indicator(m_68, reinterpret_cast<WindowDrawContext *>(context));
    }
}

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
        (this->*page0[m_68->get_type()])();
        break;
    case 1:
        (this->*page1[m_68->get_type()])();
        break;
    case 2:
        (this->*page2[m_68->get_type()])();
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
        (this->*page0[m_68->get_type()])();
        break;
    case 1:
        (this->*page1[m_68->get_type()])();
        break;
    case 2:
        (this->*page2[m_68->get_type()])();
        break;
    }
}
extern "C" {
void TWindowSubStatusDisp::vt0() {
    void *e;
    u8 *pl;
    s32 v;
    s8 *st;
    if ((f32) this->open_tick > 7.5f) {
        this->open_tick = 7;
    }
    init_window_layout_entries(
        &this->entry_list,
        reinterpret_cast<const void *>(TWindowSubStatusDisp::summary_page_layout),
        this->client_index);
    e = (void *)get_array_entry(6);
    set_text_entry_string((u8 *)e, (saddr)TWindowSubStatusDisp::get_message_10(0x80), 0x20);
    e = (void *)get_array_entry(0xA);
    set_text_entry_string((u8 *)e, (saddr)TWindowSubStatusDisp::get_message_10(0x81), 0x20);
    e = (void *)get_array_entry(0xE);
    set_text_entry_string((u8 *)e, (saddr)TWindowSubStatusDisp::get_message_10(0x82), 0x20);
    e = (void *)get_array_entry(0x11);
    set_text_entry_string((u8 *)e, TWindowSubStatusDisp::get_download_server(), 0x20);
    pl = (u8 *)get_player_by_client_id(this->client_index);
    if (pl != NULL) {
        st = (s8 *)(pl + 0x85C);
        if (st != NULL) {
            v = ((VObj_80280FD0 *)pl)->m10();
            set_text_entry_string((u8 *)((void *)get_array_entry(0)), v, 0x20);
            v = get_class_name_text(st[0x31]);
            set_text_entry_string((u8 *)((void *)get_array_entry(3)), v, 0);
            v = (saddr)TObjLuker::get_stat_table_entry(st[0x30]);
            set_text_entry_string((u8 *)((void *)get_array_entry(4)), v, 0);
        }
        e = (void *)get_array_entry(5);
        *(u8 **)((s8 *)e + 0x30) = (u8 *)this + 0x64;
        *(u8 **)((s8 *)this + 0x64) = pl + 0xCF4;
    }
}

void vt11__20TWindowSubStatusDispFv(Wn_80280F14 *arg0) {
    VObj_18_eecf68 *p;
    player_stats *q;
    En_80280F14 *e;
    p = (VObj_18_eecf68 *)get_player_by_client_id(arg0->f20);
    if (p != NULL) {
        q = ((TObjPlayer *)p)->get_stats();
        if (q != NULL) {
            e = ((En_80280F14 *)(void *)((TWindowBase *)arg0)->get_array_entry(2));
            e->v = p->m14() + 1;
            e = ((En_80280F14 *)(void *)((TWindowBase *)arg0)->get_array_entry(0x10));
            e->v = q->meseta;
            e = ((En_80280F14 *)(void *)((TWindowBase *)arg0)->get_array_entry(8));
            e->v = q->exp;
            e = ((En_80280F14 *)(void *)((TWindowBase *)arg0)->get_array_entry(0xC));
            e->v = ((TObjPlayer *)p)->get_next_level_exp() - q->exp;
        }
    }
}

void TWindowSubStatusDisp::vt1() {
    void *e;
    if ((f32) this->open_tick > 7.5f) {
        this->open_tick = 7;
    }
    init_window_layout_entries(
        &this->entry_list,
        reinterpret_cast<const void *>(TWindowSubStatusDisp::stat_page_layout),
        this->client_index);
    e = (void *)get_array_entry(0);
    set_text_entry_string((u8 *)e, (saddr)TWindowSubStatusDisp::get_message_10(0x83), 0x20);
    e = (void *)get_array_entry(6);
    set_text_entry_string((u8 *)e, (saddr)TWindowSubStatusDisp::get_message_10(0x84), 0x20);
    e = (void *)get_array_entry(0xC);
    set_text_entry_string((u8 *)e, (saddr)TWindowSubStatusDisp::get_message_10(0x85), 0x20);
    e = (void *)get_array_entry(0x12);
    set_text_entry_string((u8 *)e, (saddr)TWindowSubStatusDisp::get_message_10(0x86), 0x20);
    e = (void *)get_array_entry(0x18);
    set_text_entry_string((u8 *)e, (saddr)TWindowSubStatusDisp::get_message_10(0x87), 0x20);
    e = (void *)get_array_entry(0x1E);
    set_text_entry_string((u8 *)e, (saddr)TWindowSubStatusDisp::get_message_10(0x88), 0x20);
}

void TWindowSubStatusDisp::vt12() {
    PlayerRequirementStats cur;
    PlayerRequirementStats req;
    Entry_80280B1C *e2;
    TObjPlayer *pl;
    Entry_80280B1C *e;
    player_stats *q;
    cur.clear_fields();
    req.clear_fields();
    pl = get_player_by_client_id(this->client_index);
    if (pl != NULL) {
        e2 = (Entry_80280B1C *)(void *)get_array_entry(2);
        e2->value = pl->get_atp_range() + (pl->get_atp() + pl->get_actor_attack_params_atp_min());
        e = (Entry_80280B1C *)(void *)get_array_entry(8);
        e->value = pl->get_dfp();
        e = (Entry_80280B1C *)(void *)get_array_entry(0x14);
        e->value = pl->get_ata();
        e = (Entry_80280B1C *)(void *)get_array_entry(0x1A);
        e->value = pl->get_evp();
        q = pl->get_stats();
        if (q != NULL) {
            e = (Entry_80280B1C *)(void *)get_array_entry(0xE);
            e->value = q->stats.mst;
            e = (Entry_80280B1C *)(void *)get_array_entry(0x20);
            e->value = q->stats.lck;
        }
    }
    if (build_player_equipment_requirement_stats(pl, &cur) != 0) {
        build_player_class_stat_template(pl, &req);
#define ROW(idx, k) \
        e = (Entry_80280B1C *)(void *)get_array_entry(idx); \
        e->value = cur.k; \
        if (req.k <= cur.k) { e->color = -0x100; } else { e->color = -1; }
        ROW(4, atp)
        ROW(0xA, dfp)
        ROW(0x16, ata)
        ROW(0x1C, evp)
        ROW(0x10, mst)
        ROW(0x22, lck)
#undef ROW
    }
}
void TWindowSubStatusDisp::vt2() {
    saddr array_entry;
    if ((f32) this->open_tick > 7.5f) {
        this->open_tick = 7;
    }
    init_window_layout_entries(
        &this->entry_list,
        reinterpret_cast<const void *>(TWindowSubStatusDisp::resistance_layout),
        this->client_index);
    array_entry = ((saddr)(void *)get_array_entry(0));
    set_text_entry_string((u8 *)array_entry, ((saddr)TWindowSubStatusDisp::get_message_10(0x89)), 0x20);
    array_entry = ((saddr)(void *)get_array_entry(6));
    set_text_entry_string((u8 *)array_entry, ((saddr)TWindowSubStatusDisp::get_message_10(0x8A)), 0x20);
    array_entry = ((saddr)(void *)get_array_entry(0xC));
    set_text_entry_string((u8 *)array_entry, ((saddr)TWindowSubStatusDisp::get_message_10(0x8B)), 0x20);
    array_entry = ((saddr)(void *)get_array_entry(0x12));
    set_text_entry_string((u8 *)array_entry, ((saddr)TWindowSubStatusDisp::get_message_10(0x8C)), 0x20);
    array_entry = ((saddr)(void *)get_array_entry(0x18));
    set_text_entry_string((u8 *)array_entry, ((saddr)TWindowSubStatusDisp::get_message_10(0x8D)), 0x20);
}

void TWindowSubStatusDisp::vt13() {
    saddr player;
    void *array_entry;
    void *temp_r31_2;
    void *temp_r31_3;
    void *temp_r31_4;
    void *temp_r31_5;

    player = (saddr)get_player_by_client_id(this->client_index);
    if (player != 0) {
        array_entry = (void *)this->get_array_entry(2);
        *(s32 *)((s8 *)array_entry + 0x20) = (s32) ((TWindowSubStatusDisp *)player)->get_stat();
        temp_r31_2 = (void *)this->get_array_entry(8);
        *(s32 *)((s8 *)temp_r31_2 + 0x20) = (s32) ((TObjPlayer *)player)->get_class_id();
        temp_r31_3 = (void *)this->get_array_entry(0xE);
        *(s32 *)((s8 *)temp_r31_3 + 0x20) = (s32) ((TObjPlayer *)player)->get_item_index();
        temp_r31_4 = (void *)this->get_array_entry(0x14);
        *(s32 *)((s8 *)temp_r31_4 + 0x20) = (s32) ((TWindowSubStatusDisp *)player)->get_field_2F8();
        temp_r31_5 = (void *)this->get_array_entry(0x1A);
        *(s32 *)((s8 *)temp_r31_5 + 0x20) = (s32) ((TWindowSubStatusDisp *)player)->get_item_type();
    }
}

void TWindowSubStatusDisp::vt3() {
    s32 card_flag;
    u8 *array_entry;
    if ((f32) this->open_tick > 7.5f) {
        this->open_tick = 7;
    }
    init_window_layout_entries(
        &this->entry_list,
        reinterpret_cast<const void *>(TWindowSubStatusDisp::record_summary_layout),
        this->client_index);
    array_entry = ((u8 *)(void *)get_array_entry(0));
    set_text_entry_string(array_entry, (saddr)TWindowSubStatusDisp::get_message_10(0x8E), 0);
    array_entry = ((u8 *)(void *)get_array_entry(1));
    set_text_entry_string(array_entry, get_localized_text_entry(0x10, 6), 0);
    array_entry = ((u8 *)(void *)get_array_entry(4));
    set_text_entry_string(array_entry, get_localized_text_entry(0x10, 7), 0);
    array_entry = ((u8 *)(void *)get_array_entry(7));
    set_text_entry_string(array_entry, get_localized_text_entry(0x10, 8), 0);
    array_entry = ((u8 *)(void *)get_array_entry(0xA));
    set_text_entry_string(array_entry, get_localized_text_entry(0x10, 9), 0);
    array_entry = ((u8 *)(void *)get_array_entry(0xD));
    set_text_entry_string(array_entry, get_localized_text_entry(0x10, 0xE), 0);
    array_entry = ((u8 *)(void *)get_array_entry(3));
    *(s32 *)((s8 *)array_entry + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_field_21a8((u16) this->client_index);
    array_entry = ((u8 *)(void *)get_array_entry(6));
    *(s32 *)((s8 *)array_entry + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_value((u16) this->client_index);
    array_entry = ((u8 *)(void *)get_array_entry(9));
    *(s32 *)((s8 *)array_entry + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_status((u16) this->client_index);
    array_entry = ((u8 *)(void *)get_array_entry(0xC));
    *(s32 *)((s8 *)array_entry + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_field((u16) this->client_index);
    card_flag = TAdSinglePlyChrSelectGC::get_card_flag((u16) this->client_index);
    if (is_battle_mode_running() != 0) {
        card_flag -= 1;
    }
    *(s32 *)((s8 *)((u8 *)(void *)get_array_entry(0xF)) + 0x20) = (s32) card_flag;
}

void TWindowSubStatusDisp::vt14() {  }

void TWindowSubStatusDisp::vt7() {
    u8 *entry;
    if ((f32) this->open_tick > 7.5f) {
        this->open_tick = 7;
    }
    init_window_layout_entries(
        &this->entry_list,
        reinterpret_cast<const void *>(TWindowSubStatusDisp::record_summary_layout),
        this->client_index);
    entry = (u8 *)(void *)get_array_entry(0);
    set_text_entry_string(entry, (saddr)TWindowSubStatusDisp::get_message_10(0x8F), 0);
    entry = (u8 *)(void *)get_array_entry(1);
    set_text_entry_string(entry, get_localized_text_entry(0x10, 6), 0);
    entry = (u8 *)(void *)get_array_entry(4);
    set_text_entry_string(entry, get_localized_text_entry(0x10, 7), 0);
    entry = (u8 *)(void *)get_array_entry(7);
    set_text_entry_string(entry, get_localized_text_entry(0x10, 8), 0);
    entry = (u8 *)(void *)get_array_entry(0xA);
    set_text_entry_string(entry, get_localized_text_entry(0x10, 9), 0);
    ((TWindowHelpItem *)((void *)get_array_entry(0xD)))->set_flag0_bit2();
    ((TWindowHelpItem *)((void *)get_array_entry(0xE)))->set_flag0_bit2();
    entry = (u8 *)(void *)get_array_entry(3);
    *(s32 *)((s8 *)entry + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_state((u16) this->client_index);
    entry = (u8 *)(void *)get_array_entry(6);
    *(s32 *)((s8 *)entry + 0x20) = (s32) TAdSinglePlyChrSelectGC__sub_801FC36C((u16) this->client_index);
    entry = (u8 *)(void *)get_array_entry(9);
    *(s32 *)((s8 *)entry + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_window_status((u16) this->client_index);
    entry = (u8 *)(void *)get_array_entry(0xC);
    *(s32 *)((s8 *)entry + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_window_field((u16) this->client_index);
    ((TWindowHelpItem *)((void *)get_array_entry(0xF)))->set_flag0_bit2();
}

void TWindowSubStatusDisp::vt18() {  }

// rank letters by clear rank
const char *lbl_804D2B20[4] = {"", "B", "A", "S"};

// Best-time records page: page == 2 shows the split-screen record sets.
void TWindowSubStatusDisp::vt4() {
    enum { RecordEntryHidden = 2 };
    if ((f32)(s32)open_tick > 7.5f) {
        open_tick = 7;
    }
    init_window_layout_entries(&entry_list, reinterpret_cast<const void *>(TWindowSubStatusDisp::rank_time_records_layout), client_index);
    m_68->get_type();
    s32 slot = page == 2 ? RECORD_SET_EP1_SPLIT : RECORD_SET_EP1;
    WindowTextEntry *title = (WindowTextEntry *)get_array_entry(0);
    if (slot == RECORD_SET_EP1) {
        set_text_entry_string((u8 *)title, (uaddr)TWindowSubStatusDisp::get_message_10(0x90), 0);
    } else {
        set_text_entry_string((u8 *)title, (uaddr)TWindowSubStatusDisp::get_message_10(0x93), 0);
    }

    title = (WindowTextEntry *)get_array_entry(1);
    WindowTextEntry *spacer = (WindowTextEntry *)get_array_entry(2);
    WindowTextEntry *value = (WindowTextEntry *)get_array_entry(3);
    const char *player_name = (const char *)get_challenge_rank_title(client_index);
    if (slot != RECORD_SET_EP1 || player_name == NULL || *player_name == 0) {
        title->flags |= RecordEntryHidden;
        spacer->flags |= RecordEntryHidden;
        value->flags |= RecordEntryHidden;
    } else {
        title->flags &= ~RecordEntryHidden;
        spacer->flags &= ~RecordEntryHidden;
        value->flags &= ~RecordEntryHidden;
        set_text_entry_string((u8 *)title, (uaddr)TWindowSubStatusDisp::get_message_10(0x9B), 0);
        set_text_entry_string((u8 *)value, (uaddr)player_name, 0x20);
        value->color = get_challenge_title_color(client_index);
    }

    title = (WindowTextEntry *)get_array_entry(4);
    spacer = (WindowTextEntry *)get_array_entry(5);
    value = (WindowTextEntry *)get_array_entry(6);
    s32 rank = get_challenge_rank(client_index, slot);
    if (rank == 0) {
        title->flags |= RecordEntryHidden;
        spacer->flags |= RecordEntryHidden;
        value->flags |= RecordEntryHidden;
    } else {
        title->flags &= ~RecordEntryHidden;
        spacer->flags &= ~RecordEntryHidden;
        value->flags &= ~RecordEntryHidden;
        if (slot == RECORD_SET_EP1) {
            set_text_entry_string((u8 *)title, (uaddr)TWindowSubStatusDisp::get_message_10(0x98), 0);
        } else {
            set_text_entry_string((u8 *)title, (uaddr)TWindowSubStatusDisp::get_message_10(0x9A), 0);
        }
        set_text_entry_string((u8 *)value, (uaddr)lbl_804D2B20[rank], 0);
    }

    title = (WindowTextEntry *)get_array_entry(7);
    spacer = (WindowTextEntry *)get_array_entry(8);
    value = (WindowTextEntry *)get_array_entry(9);
    s32 time = get_challenge_set_time(client_index, slot);
    if (time == 0) {
        title->flags |= RecordEntryHidden;
        spacer->flags |= RecordEntryHidden;
        value->flags |= RecordEntryHidden;
    } else {
        title->flags &= ~RecordEntryHidden;
        spacer->flags &= ~RecordEntryHidden;
        value->flags &= ~RecordEntryHidden;
        if (slot == RECORD_SET_EP1) {
            set_text_entry_string((u8 *)title, (uaddr)TWindowSubStatusDisp::get_message_10(0x95), 0);
        } else {
            set_text_entry_string((u8 *)title, (uaddr)TWindowSubStatusDisp::get_message_10(0x97), 0);
        }
        text_builder_reset();
        TWindowSubStatusDisp::append_play_time(time);
        set_text_entry_string((u8 *)value, get_shared_text_buffer(), 0x20);
    }

    slot = RECORD_SET_EP2;
    if (page == 2) {
        slot = RECORD_SET_EP2_SPLIT;
    }
    title = (WindowTextEntry *)get_array_entry(0xA);
    spacer = (WindowTextEntry *)get_array_entry(0xB);
    value = (WindowTextEntry *)get_array_entry(0xC);
    rank = get_challenge_rank(client_index, slot);
    if (rank == 0) {
        title->flags |= RecordEntryHidden;
        spacer->flags |= RecordEntryHidden;
        value->flags |= RecordEntryHidden;
    } else {
        title->flags &= ~RecordEntryHidden;
        spacer->flags &= ~RecordEntryHidden;
        value->flags &= ~RecordEntryHidden;
        set_text_entry_string((u8 *)title, (uaddr)TWindowSubStatusDisp::get_message_10(0x99), 0);
        set_text_entry_string((u8 *)value, (uaddr)lbl_804D2B20[rank], 0);
    }

    title = (WindowTextEntry *)get_array_entry(0xD);
    spacer = (WindowTextEntry *)get_array_entry(0xE);
    value = (WindowTextEntry *)get_array_entry(0xF);
    time = get_challenge_set_time(client_index, slot);
    if (time == 0) {
        title->flags |= RecordEntryHidden;
        spacer->flags |= RecordEntryHidden;
        value->flags |= RecordEntryHidden;
    } else {
        title->flags &= ~RecordEntryHidden;
        spacer->flags &= ~RecordEntryHidden;
        value->flags &= ~RecordEntryHidden;
        set_text_entry_string((u8 *)title, (uaddr)TWindowSubStatusDisp::get_message_10(0x96), 0);
        text_builder_reset();
        TWindowSubStatusDisp::append_play_time(time);
        set_text_entry_string((u8 *)value, get_shared_text_buffer(), 0x20);
    }
}

void TWindowSubStatusDisp::vt15() {  }

void vt5__20TWindowSubStatusDispFv(u8 *window_base) {
  s32 type;
  s32 n;
  u16 *e;
  s32 r;
  u8 *new_var;
  int new_var2;
  s32 i;
  if (((f32) (*((s32 *) (((s8 *) window_base) + 0x5C)))) > 7.5f)
  {
    *((s32 *) (((s8 *) window_base) + 0x5C)) = 7;
  }
  init_window_layout_entries(
      reinterpret_cast<WindowLayoutEntries *>(window_base + 0x24),
      reinterpret_cast<const void *>(TWindowSubStatusDisp::numbered_times_layout),
      *((s16 *) (((s8 *) window_base) + 0x20)));
  new_var = window_base;
  type = ((TWindowSubStatusDisp *)new_var)->get_display_mode();
  e = (u16 *) (void *)((TWindowBase *)window_base)->get_array_entry(0);
  set_text_entry_string((u8 *)e, (saddr)TWindowSubStatusDisp::get_message_10(status_disp_vt5_message_ids[type]), 0);
  n = challenge_set_stage_count(type);
  i = 0;
  do
  {
    e = (u16 *) (void *)((TWindowBase *)window_base)->get_array_entry(i + 1);
    new_var2 = n > i;
    if (!new_var2)
    {
      *e |= 2;
    }
    else
    {
      r = get_challenge_stage_time(i, *((s16 *) (((s8 *) window_base) + 0x20)), type);
      if (r == 0)
      {
        *e |= 2;
      }
      else
      {
        *e &= ~2;
        text_builder_reset();
        append_padded_number(i + 1, 2);
        text_builder_append((u8 *)":");
        TWindowSubStatusDisp::append_play_time(r);
        set_text_entry_string((u8 *)e, get_shared_text_buffer(), 0x20);
      }
    }
    i++;
  }
  while (i < 9);
}

void TWindowSubStatusDisp::vt16() {  }

// The record set this page shows: page 2 shows the split-screen sets.
s32 TWindowSubStatusDisp::get_display_mode() {
    s32 r;
    if (page == 2) {
        s8 t = m_68->get_type();
        r = RECORD_SET_EP2_SPLIT;
        if (t == 2) r = RECORD_SET_EP1_SPLIT;
        return r;
    }
    return m_68->get_type() != 2 ? RECORD_SET_EP2 : RECORD_SET_EP1;
}
}

void TWindowSubStatusDisp::set_requested_page(s16 value) { requested_page = value; }

void TWindowSubStatusDisp::set_scale(f32 x, f32 y) { scale_x = x; scale_y = y; }
