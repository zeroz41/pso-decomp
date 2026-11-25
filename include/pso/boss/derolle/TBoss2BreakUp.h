#ifndef PSO_BOSS_DEROLLE_TBOSS2BREAKUP_H
#define PSO_BOSS_DEROLLE_TBOSS2BREAKUP_H

#include "types.h"
#include <dolphin/mtx.h>
#include "dolphin/mtx/GeoTypes.h"
#include "pso/system/task/TObject.h"

class TBreakUpMdlData;

// One flying piece of the De Rol Le breakup effects (TBoss2BodyBreakUp, TBoss2JointBreakUp).
// TBoss2BreakUp::move_piece moves it: state 0 falls (vel.y -= 0.2, angles spin), 1 sinks, 2 fades alpha, 3 done.
struct BreakupPiece {
    Vec pos;
    Vec vel;
    s32 ang_x;
    s32 spin;   // added to ang_x, twice to ang_z, each frame
    s32 ang_z;
    f32 alpha;
    s32 state;
};

class TBoss2BreakUp : public TObject {
public:
    TBoss2BreakUp(TObject *parent);
    virtual ~TBoss2BreakUp();
    // Returns 1 on the frame the piece misses the platform and starts sinking.
    static s32 move_piece(BreakupPiece *piece);
    // Scales the first n piece positions of model by boss2_model_scale.
    static void scale_piece_positions(TBreakUpMdlData *model, s32 n);
    // Scales the first n piece velocities of model by breakup_spread_scale in x and z and flattens y.
    static void spread_piece_velocities(TBreakUpMdlData *model, s32 n);
    s32 m_frames;  // the subclasses' run_task destroy the effect after 0xA0 frames
};

// The 0x1C pieces TBoss2DeRolLe::run_task spawns from body_breakup_model.
class TBoss2BodyBreakUp : public TBoss2BreakUp {
public:
    TBoss2BodyBreakUp(TObject *parent, const f32 (*matrix)[4]);
    virtual ~TBoss2BodyBreakUp();
    virtual void render();
    virtual void run_task();
    static void create_model();
    static void free_model();
    BreakupPiece m_pieces[0x1C];
    const f32 (*m_matrix)[4];  // concatenated before each piece is drawn
    Vec m_origin;  // m_matrix applied to the origin
};
LAYOUT_ASSERT(TBoss2BodyBreakUp_size, sizeof(TBoss2BodyBreakUp) == 0x500);

// The 19 pieces TBoss2Joint spawns from joint_breakup_model.
class TBoss2JointBreakUp : public TBoss2BreakUp {
public:
    TBoss2JointBreakUp(TObject *parent, const Vec *pos);
    virtual ~TBoss2JointBreakUp();
    virtual void run_task();
    virtual void render();
    static void create_model();
    static void free_model();
    BreakupPiece m_pieces[19];
};
LAYOUT_ASSERT(TBoss2JointBreakUp_size, sizeof(TBoss2JointBreakUp) == 0x364);

// Breakup debris that misses the platform starts sinking below this height.
extern const f32 boss2_water_level;
extern const f32 boss2_tunnel_splash_y;
extern const f32 boss2_model_scale;
// Debris bounces and photon bullets hit inside [boss2_platform_min, boss2_platform_max].
extern const f32 boss2_platform_max;
extern const f32 boss2_platform_min;

#endif
