#ifndef PSO_OBJECT_TOBJCHIP_H
#define PSO_OBJECT_TOBJCHIP_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

#include "pso/object/TObjChipParams.h"

// One debris piece of a TObjChip.
struct TObjChipPiece {
    Vec pos;
    Vec velocity;
    s32 rotation[3];  // x, y, z
    s32 angular_velocity[3];
    f32 alpha;
    s32 life;
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
    virtual s32 spawn_chips(s32 *rotation);
    virtual s32 vfunc_8();
    virtual void tick_chips();
    virtual s32 is_in_view(Vec *center, f32 max_depth, f32 radius);
    // What render() draws through.
    virtual void render_chips();
    virtual void vfunc_12();
    virtual void draw_chips();
    static void copy_debris_params(TObjChipParams *dst, const TObjChipParams *src);
    static TObjChipSpawnParams *copy_transform(TObjChipSpawnParams *spawn, TObjChipParams *params);

    f32 pad_1c;
    f32 pad_20;
    TObjChipParams params;  // params.count pieces, of params.model
    TObjChipPiece pieces[8];
    s32 pad_230;  // cleared when no piece is left
};

LAYOUT_ASSERT(TObjChip_size, sizeof(TObjChip) == 0x234);

#endif
