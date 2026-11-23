#ifndef PSO_EFFECT_PHOTON_TPHOTONESTLLA_H
#define PSO_EFFECT_PHOTON_TPHOTONESTLLA_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/photon/PhotonBlastSummon.h"

// The Estlla photon blast summon: it fires a photon line along its
// summoner's facing.
class TPhotonEstlla : public TPhotonBlastSummon {
public:
    static const char *class_name;

    TPhotonEstlla(PhotonSummonParams *params);
    virtual ~TPhotonEstlla();
    void reset_color(u8 summon_count);
    void spawn_line();
    virtual void render();
    virtual void run_task();

    u8 pad_158[0x24];
    u16 owner_id;            // entity id of the player who summoned it
    NJS_ARGB color;          // constant material colour of its model
    s16 last_action;
    s32 is_first;            // PhotonSummonParams::is_first, 1 once the summon camera has started
    s32 has_more;            // PhotonSummonParams::has_more
    s32 started;             // its model is shown
    s32 timer;               // frames since the last phase change
};

LAYOUT_ASSERT(TPhotonEstlla_size, sizeof(TPhotonEstlla) == 0x1A4);

void create_estlla_photon_blast_model(void);
void destroy_estlla_photon_blast_model(void);

#endif
