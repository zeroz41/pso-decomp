#ifndef PSO_ENEMY_TOBJENEDF2BRINGERRING_H
#define PSO_ENEMY_TOBJENEDF2BRINGERRING_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

// The Bringer's expanding ring: radius grows from 10 to max_radius, then the ring fades out.
// Drawn as two 6-vertex strips of (outer, inner) pairs.
class TObjEneDf2BringerRing : public TObject {
public:
    struct Vertex {
        Vec pos;
        u32 color;
    };
    TObjEneDf2BringerRing(TObject *parent, const Vec *pos, f32 max_radius);
    virtual ~TObjEneDf2BringerRing();
    virtual void run_task();
    virtual void render();
    void update_vertex_colors();    // the color table rotated by frame, alpha in the top byte
    void update_vertex_positions(); // (outer, inner) pairs at radius +-3 along the direction table
    s32 state;  // 0 growing, 1 fading
    Vec position;
    f32 alpha;
    s32 frame;  // 0..11, rotates the color table
    s32 angle;
    f32 radius;
    f32 max_radius;
    Vertex vertices[12];
};
LAYOUT_ASSERT(TObjEneDf2BringerRing_size, sizeof(TObjEneDf2BringerRing) == 0x100);

#endif
