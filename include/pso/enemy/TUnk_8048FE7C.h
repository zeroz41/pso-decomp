#ifndef PSO_ENEMY_TUNK_8048FE7C_H
#define PSO_ENEMY_TUNK_8048FE7C_H
#include "types.h"
#include "pso/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

// The Bringer's expanding ring: radius grows from 10 to max_radius, then the ring fades out.
// Drawn as two 6-vertex strips of (outer, inner) pairs.
class TUnk_8048FE7C : public TObject {
public:
    struct Vertex {
        Vec pos;
        u32 color;
    };
    TUnk_8048FE7C(TObject *parent, const Vec *pos, f32 max_radius);
    virtual ~TUnk_8048FE7C();
    virtual void run_task();
    virtual void render();
    void sub_8009A598();
    void sub_8009A640();
    s32 state;  // 0 growing, 1 fading
    Vec position;
    f32 alpha;
    s32 frame;  // 0..11, rotates the color table
    s32 angle;
    f32 radius;
    f32 max_radius;
    Vertex vertices[12];
};
typedef char TUnk_8048FE7C_size[sizeof(TUnk_8048FE7C) == 0x100 ? 1 : -1];

#endif
