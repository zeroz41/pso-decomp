#ifndef PSO_TOBJCHIP_H
#define PSO_TOBJCHIP_H
#include "pso/TObject.h"
#include "pso/object/TObjChip.h"
#include "types.h"
#include <dolphin/mtx.h>

// TObjChipParams followed by the data spawn_chips reads (at +0x4C).
struct TObjChipSpawnParams;

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
    TObjChip(TObject *parent, TObjChipParams *params);
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

    f32 pad_1c;
    f32 pad_20;
    TObjChipParams params;  // params.pad_30[0] pieces, of params.model
    TObjChipPiece pieces[8];
    s32 pad_230;
};

typedef char TObjChip_size[sizeof(TObjChip) == 0x234 ? 1 : -1];
#endif
