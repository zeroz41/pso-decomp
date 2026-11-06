#ifndef PSO_ENEMY_TUNK_8048FE64_H
#define PSO_ENEMY_TUNK_8048FE64_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

// A point the Bringer's TP drain sends from each hit player to the Bringer: it moves from start
// to end at 6 units a frame, then destroys itself.
class TUnk_8048FE64 : public TObject {
public:
    TUnk_8048FE64(TObject *parent, const Vec *from, const Vec *to);
    virtual ~TUnk_8048FE64();
    virtual void run_task();
    virtual void render();
    Vec position;
    Vec start;
    Vec end;
    Vec delta;  // end - start
    f32 length;
    f32 frames;
};
typedef char TUnk_8048FE64_size[sizeof(TUnk_8048FE64) == 0x54 ? 1 : -1];

#endif
