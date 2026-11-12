#ifndef PSO_PLAYER_TUNK_80491460_H
#define PSO_PLAYER_TUNK_80491460_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TParticleCtrl;
class TObjPlayer;

// The shot a TObjEneDubchik fires (TObjPlayer__sub_800A8FB4 news one): it flies straight
// along the shooter's heading, stops at a wall or after 150 units, and hits the first
// player it passes within 7 units of.
class TUnk_80491460 : public TObject {
public:
    TUnk_80491460(void *start, s32 angle, s32 source, s32 power);
    virtual ~TUnk_80491460();
    virtual void run_task();
    void try_hit_target(TObjPlayer *player);
    Vec pos;
    Vec prev_pos;   // where the last wall check (every 4th frame) started
    Vec velocity;   // 7 units a frame along the shooter's heading
    u8 unk_40[0x18];
    f32 distance;   // how far it has flown
    TParticleCtrl *particle;
    s32 frame;
    s32 source;     // the shooter, passed to receive_direct_attack
    s32 power;
};
typedef char TUnk_80491460_size[sizeof(TUnk_80491460) == 0x6C ? 1 : -1];

#endif
