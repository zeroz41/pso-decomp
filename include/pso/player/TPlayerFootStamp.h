#ifndef PSO_PLAYER_TPLAYERFOOTSTAMP_H
#define PSO_PLAYER_TPLAYERFOOTSTAMP_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

struct TObjPlayer;

// One corner of the footprint quad that render() hands to draw_particle_strip.
struct FootStampVertex {
    Vec pos;
    f32 u;
    f32 v;
    u32 color;
};

// A footprint a player leaves on the ground (TObjPlayer::clear_foot_stamp and
// enable_foot_stamp make one per step); it fades out over its last 64 frames.
class TPlayerFootStamp : public TObject {
public:
    TPlayerFootStamp(TObjPlayer *player, s32 side);
    virtual ~TPlayerFootStamp();
    void sub_802B0204(s32);
public:
    static void *create(void *arg0, void *arg1);
    static void free_instance();
    void render();
    void run_task();

    static const char *class_name;

    FootStampVertex verts[4]; // 0x1C
    Vec position;             // 0x7C: the ground point under the foot
    Vec corners[4];           // 0x88: the quad's corners around position
    u32 color;                // 0xB8: the floor's footprint colour
    s16 side;                 // 0xBC: 0 or 1 (the caller's foot), else none is made
    s16 texture;              // 0xBE: set_texture_num index, 1 for android feet
    s32 timer;                // 0xC0: frames left
};

#endif
