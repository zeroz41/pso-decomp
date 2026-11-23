#ifndef PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXMOVE_H
#define PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXMOVE_H

#include "pso/system/task/TObject.h"
#include <stddef.h>
#include "types.h"

// inferred: the speed, scale, angle and point count of the ending's hex lines,
// named after TObjOnlineEndingHexLine__hex_line_params.
struct EndingHexLineParams {
    f32 speed;
    f32 scale;
    s32 angle;
    f32 count;
};

class TObjOnlineEndingHexMove : public TObject {
public:
    TObjOnlineEndingHexMove(TObject *parent);
    virtual ~TObjOnlineEndingHexMove();
    virtual void run_task();

    s32 timer;

    void update_line_params();
    static EndingHexLineParams *copy_move_params(EndingHexLineParams *dest, const EndingHexLineParams *src);
    static void *create(void *parent);
};

LAYOUT_ASSERT(EndingHexMoveSize, sizeof(TObjOnlineEndingHexMove) == 0x20);

#endif
