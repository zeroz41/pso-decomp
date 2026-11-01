#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowBase.h"
extern "C" {
s8 get_type__20TWindowSubStatusDispFv(s32);
extern "C" u8 lbl_805DD6E0[];
extern "C" u8 lbl_805DD6E4[];
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
#define TWindowSubStatusDisp__window_layout ((u8 *)TWindowSubStatusDisp__window_layout)

}

#include "types.h"

struct SD_80281760 { s32 f0; u8 pad4[0x14]; void *vt; u8 pad1c[4]; s16 f20; u8 pad22[0x3E]; s16 f60; s16 f62; u8 pad64[4]; void *f68; f32 f6c; f32 f70; };

extern "C" {
s32 fn_8026C7AC(void *arg0, s8 arg1);
s32 handle_list_page_flip_input(int);
extern s32 lbl_805DD6F4;
void *init__21TWindowSubComCardListFiii(void *, int, int, s32);
s32 get_window_layout_position(int);

extern s32 __vt__20TWindowSubStatusDisp[];
extern s32 TWindowSubStatusDisp__class_name;
extern const f32 lbl_805DD70C;
SD_80281760 *TWindowSubStatusDisp__ct(SD_80281760 *arg0, s32 arg1);
void *get_player_by_client_id(s32 i);
s32 draw_visible_window_entries(void *, void *, s32);
s32 draw_list_page_indicator(s32, s32);
void __dl__7TObjectFPv(void *);
void destroy_window_base__9TWindowDDFs(void *, int);
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

    switch (m_60) {
    case 0:
        (this->*page0[get_type__20TWindowSubStatusDispFv(m_68)])();
        break;
    case 1:
        (this->*page1[get_type__20TWindowSubStatusDispFv(m_68)])();
        break;
    case 2:
        (this->*page2[get_type__20TWindowSubStatusDispFv(m_68)])();
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

    switch (m_60) {
    case 0:
        (this->*page0[get_type__20TWindowSubStatusDispFv(m_68)])();
        break;
    case 1:
        (this->*page1[get_type__20TWindowSubStatusDispFv(m_68)])();
        break;
    case 2:
        (this->*page2[get_type__20TWindowSubStatusDispFv(m_68)])();
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
  if ((handle_list_page_flip_input((int) (*(s32 *)&arg0->m_68)) != 0) || ((arg0->m_60) != ((s16) (*(s16 *)&arg0->m_62))))
  {
    if ((arg0->m_60) != (*(s16 *)&arg0->m_62))
    {
      arg0->m_60 = *(s16 *)&arg0->m_62;
      fn_8026C7AC((void *)(*(s32 *)&arg0->m_68), ((s8) (*((u8 *) (((s8 *) (((u8 *)&lbl_805DD6F4) + (arg0->m_60))) + 0)))));
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
        destroy_window_base__9TWindowDDFs(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
SD_80281760 *TWindowSubStatusDisp__ct(SD_80281760 *arg0, s32 arg1) {
    void *w;
    ((TWindowDD *)arg0)->construct_base((u8 *)TWindowSubStatusDisp__window_layout, (s16)arg1, (u8 *)(get_window_layout_position(0x19)));
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
