#ifndef PSO_OBJECT_TOBJCHIP_H
#define PSO_OBJECT_TOBJCHIP_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

#include "pso/object/TObjChipParams.h"

extern "C" {
void vfunc_12__8TObjChipFv(u8 *arg0);
int vfunc_8__8TObjChipFv(void *p);
u8 *__ct__8TObjChipFP7TObjectP19TObjChipSpawnParams(u8 *arg0, u8 *parent, u8 *arg2);
u8 *__ct__8TObjChipFP7TObjectPC14TObjChipParams(u8 *arg0, u8 *parent, u8 *arg2);
void copy_debris_params__8TObjChipFPvPv(u8 *arg0, u8 *arg1);
void render__8TObjChipFv(void *arg0);
s32 init_chips__8TObjChipFv(u8 *arg0);
void render_chips__8TObjChipFv(u8 *arg0);
s32 spawn_chips__8TObjChipFPv(u8 *arg0, u8 *arg1);
void tick_chips__8TObjChipFv(u8 *arg0);
void run_task__8TObjChipFv(void *arg0);
}

// One debris piece of a TObjChip.
struct TObjChipPiece {
    Vec pos;
    u8 pad_c[0xC];
    s32 rotation[3];  // x, y, z
    u8 pad_24[0x14];
};

// Debris chips: a short-lived task that throws model pieces about.
class TObjChip : public TObject {
public:
    TObjChip(TObject *parent, TObjChipSpawnParams *params);
    TObjChip(TObject *parent, const TObjChipParams *params);
    virtual ~TObjChip();
    virtual void run_task();
    virtual void render();
    virtual s32 init_chips();
    virtual s32 spawn_chips(void *spawn);
    virtual s32 vfunc_8();
    virtual void tick_chips();
    virtual s32 vfunc_10(Vec *center);
    // What render() draws through.
    virtual void render_chips();
    virtual void vfunc_12();
    virtual void draw_chips();
    static TObjChipSpawnParams *copy_transform(TObjChipSpawnParams *spawn, TObjChipParams *params);

    f32 pad_1c;
    f32 pad_20;
    TObjChipParams params;  // params.pad_30[0] pieces, of params.model
    TObjChipPiece pieces[8];
    s32 pad_230;
};

LAYOUT_ASSERT(TObjChip_size, sizeof(TObjChip) == 0x234);

#endif
