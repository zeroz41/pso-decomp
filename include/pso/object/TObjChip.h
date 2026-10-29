#ifndef PSO_OBJECT_TOBJCHIP_H
#define PSO_OBJECT_TOBJCHIP_H

#include "types.h"

// What TObjChip::construct_debris copies into a new debris chip.
struct TObjChipParams {
    f32 pad_0[3];
    f32 pos[3];
    f32 pad_18[3];
    s32 pad_24[3];
    s32 pad_30[2];
    f32 pad_38[2];
    s32 model;
    s32 textures;
    s32 pad_48;
};

extern "C" {
void vfunc_12__8TObjChipFv(u8 *arg0);
int vfunc_8__8TObjChipFv(void *p);
u8 *__ct__8TObjChipFP7TObjectP19TObjChipSpawnParams(u8 *arg0, u8 *arg1, u8 *arg2);
u8 *__ct__8TObjChipFP7TObjectP14TObjChipParams(u8 *arg0, u8 *arg1, u8 *arg2);
void copy_debris_params__8TObjChipFPvPv(u8 *arg0, u8 *arg1);
u8 *copy_transform__8TObjChipFPvPv(u8 *arg0, u8 *arg1);
void render__8TObjChipFv(void *arg0);
s32 init_chips__8TObjChipFv(u8 *arg0);
void render_chips__8TObjChipFv(u8 *arg0);
s32 spawn_chips__8TObjChipFPv(u8 *arg0, u8 *arg1);
void tick_chips__8TObjChipFv(u8 *arg0);
void run_task__8TObjChipFv(void *arg0);
}

#endif
