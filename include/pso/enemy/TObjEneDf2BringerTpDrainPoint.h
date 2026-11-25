#ifndef PSO_ENEMY_TOBJENEDF2BRINGERTPDRAINPOINT_H
#define PSO_ENEMY_TOBJENEDF2BRINGERTPDRAINPOINT_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

// A point the Bringer's TP drain sends from each hit player to the Bringer: it moves from start
// to end at 6 units a frame, then destroys itself.
class TObjEneDf2BringerTpDrainPoint : public TObject {
public:
    TObjEneDf2BringerTpDrainPoint(TObject *parent, const Vec *from, const Vec *to);
    virtual ~TObjEneDf2BringerTpDrainPoint();
    virtual void run_task();
    virtual void render();
    Vec position;
    Vec start;
    Vec end;
    Vec delta;  // end - start
    f32 length;
    f32 frames;
};
LAYOUT_ASSERT(TObjEneDf2BringerTpDrainPoint_size, sizeof(TObjEneDf2BringerTpDrainPoint) == 0x54);

#endif
