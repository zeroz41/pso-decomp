#ifndef PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXMOVE_H
#define PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXMOVE_H

#include "pso/system/task/TObject.h"
#include "pso/object/ending/TObjOnlineEndingHexLine.h"
#include <stddef.h>
#include "types.h"

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
