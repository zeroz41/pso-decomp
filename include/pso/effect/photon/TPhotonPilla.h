#ifndef PSO_EFFECT_PHOTON_TPHOTONPILLA_H
#define PSO_EFFECT_PHOTON_TPHOTONPILLA_H
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/photon/PhotonBlastSummon.h"

// The Pilla photon blast summon: it raises a pillar of lasers around its
// summoner and hits every player in battle.
class TPhotonPilla : public TPhotonBlastSummon {
public:
    static const char *class_name;

    TPhotonPilla(PhotonSummonParams *params);
    virtual ~TPhotonPilla();
    void spawn_laser();
    void apply_photon_blast_effects();
    void reset_color(u8 summon_count);
    virtual void render();
    virtual void run_task();

    u8 pad_158[0x24];
    u16 owner_id;            // entity id of the player who summoned it
    NJS_ARGB color;          // constant material colour of its model
    TObjCollidable *owner;   // find_entity_by_id(owner_id) at creation
    s32 laser_count;         // lasers spawn_laser has fired
    s16 last_action;
    s32 is_first;            // PhotonSummonParams::is_first, 1 once the summon camera has started
    s32 has_more;            // PhotonSummonParams::has_more
    s32 started;             // its model is shown
    s32 timer;               // frames since the last phase change
};
LAYOUT_ASSERT(TPhotonPilla_size, sizeof(TPhotonPilla) == 0x1AC);

void create_pilla_photon_blast_model(void);
void destroy_pilla_photon_blast_model(void);

#endif
