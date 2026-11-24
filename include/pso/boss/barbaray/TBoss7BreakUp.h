#ifndef PSO_BOSS_BARBARAY_TBOSS7BREAKUP_H
#define PSO_BOSS_BARBARAY_TBOSS7BREAKUP_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"

class TBreakUpMdlData;
struct NJS_OBJECT;

// One flying piece of a De Rol Le breakup.
struct BarbaRayBreakupPiece {
    Vec position;
    Vec velocity;
    s32 angles[3];  // x, y, z; angles[1] is also the spin added to x (and twice to z) every frame
    f32 opacity;    // fades out after the piece lands on the deck
    s32 state;      // 0 flying, 1 sinking into the sea, 2 fading on the deck, 3 faded

    s32 update();
};
LAYOUT_ASSERT(BarbaRayBreakupPiece_size, sizeof(BarbaRayBreakupPiece) == 0x2C);

// Base of the De Rol Le breakup effects: a TBreakUpMdlData and one piece per node.
class TBoss7BreakUp : public TObject {
public:
    TBoss7BreakUp(TObject *parent);
    virtual ~TBoss7BreakUp();
    void scale_node_velocities_xz();
    void alloc_breakup_model(NJS_OBJECT *root);

    TBreakUpMdlData *model;
    s32 age;        // frames alive; run_task destroys the effect at 0xA0
    s32 count;      // node count, copied from model->m_count
    BarbaRayBreakupPiece *pieces;
};

// The breakup's tuning values, and the deck bounds and sea level the pieces (and the photon bullets,
// laser particles and tunnel splashes) test against.
extern const f32 boss7_breakup_one;
extern const f32 boss7_breakup_zero;
extern const f32 boss7_breakup_bounce;      // vertical speed kept, reversed, when a piece lands on the deck
extern const f32 boss7_breakup_rise_min;
extern const f32 boss7_breakup_rise_max;    // range of a piece's starting upward speed
extern const f32 boss7_breakup_drift_max;   // a piece's starting z speed drops by 1 to this much
extern const f32 boss7_breakup_spin_scale;
extern const f32 boss7_breakup_spread_xz;   // the node velocities' x and z are scaled by this
extern const f32 boss7_breakup_gravity;
extern const f32 boss7_breakup_fade_step;   // alpha lost per frame once landed
extern const f32 boss7_sea_level_y;
extern const f32 boss7_tunnel_splash_y;
extern const f32 boss7_joint_breakup_scale;
extern const f32 boss7_deck_y;
extern const f32 boss7_deck_max_x;
extern const f32 boss7_deck_min_x;

#endif
