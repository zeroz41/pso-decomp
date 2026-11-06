#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar_8028B714.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/system/memory.h"

extern "C" {

s32 is_unloaded__12TChCrLoadAfsFv();
}

struct SubBase { char pad[0x18]; };
struct SubObj : SubBase { virtual void m0(int); virtual void m1(int); virtual void m2(int); };

u8 *free_chcr_resources(u8 *arg0, s16 arg1) {
    SubObj *temp_r3;

    if (arg0 != NULL) {
        if (((void *) *(void **)((s8 *)arg0 + 0) != NULL) && (is_unloaded__12TChCrLoadAfsFv() == 0)) {
            temp_r3 = (SubObj *) (*(void **)((s8 *)arg0 + 0));
            if (temp_r3 != NULL) {
                temp_r3->m0(1);
            }
            *(void **)((s8 *)arg0 + 0) = NULL;
        }
        if ((s32) *(s32 *)((s8 *)arg0 + 0x54) != 0) {
            if (!(*(s32 *)((s8 *)arg0 + 0x4A8) & 1)) {
                free_texture_if_valid((u32)(arg0 + 0x1B8));
            }
            *(s32 *)((s8 *)arg0 + 0x54) = 0;
        }
        if ((s32) *(s32 *)((s8 *)arg0 + 0x1C0) != 0) {
            if (!(*(s32 *)((s8 *)arg0 + 0x4A8) & 2)) {
                free_texture_if_valid((u32)(arg0 + 0x324));
            }
            *(s32 *)((s8 *)arg0 + 0x1C0) = 0;
        }
        if ((s32) *(s32 *)((s8 *)arg0 + 0x32C) != 0) {
            if (!(*(s32 *)((s8 *)arg0 + 0x4A8) & 4)) {
                free_texture_if_valid((u32)(arg0 + 0x490));
            }
            *(s32 *)((s8 *)arg0 + 0x32C) = 0;
        }
        if (arg1 > 0) {
            ::operator delete((arg0));
        }
    }
    return arg0;
}
