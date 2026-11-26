#ifndef PSO_PLAYER_TPLAYERFOOTSTAMP_H
#define PSO_PLAYER_TPLAYERFOOTSTAMP_H
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

struct TObjPlayer;

// A footprint a player leaves on the ground (TObjPlayer::clear_foot_stamp and
// enable_foot_stamp make one per step); it fades out over its last 64 frames.
class TPlayerFootStamp : public TObject {
public:
    TPlayerFootStamp(TObjPlayer *player, s32 side);
    virtual ~TPlayerFootStamp();
    void select_texture(s32);
public:
    static void *create(void *slot, void *side);
    static void free_instance();
    void render();
    void run_task();

    static const char *class_name;

    ParticleStripVertex verts[4]; // 0x1C
    Vec position;             // 0x7C: the ground point under the foot
    Vec corners[4];           // 0x88: the quad's corners around position
    u32 color;                // 0xB8: the floor's footprint colour
    s16 side;                 // 0xBC: 0 or 1 (the caller's foot), else none is made
    s16 texture;              // 0xBE: select_texture index, 1 for android feet
    s32 timer;                // 0xC0: frames left
};

void load_player_footstamp(void);

// Per player class: the TObjPlayer::base_stats.proportions value the sizes above are for and
// how much the footprint grows per unit above it.
struct FootStampHeightScale {
    f32 base;
    f32 rate;
};

#endif
