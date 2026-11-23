#ifndef PSO_EFFECT_PHOTON_TPHOTONGOLLA_H
#define PSO_EFFECT_PHOTON_TPHOTONGOLLA_H
#include "types.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/effect/photon/TPhotonConcentrate.h"

// Golla, the photon blast summon that fires concentrated beams at the nearest enemy in front of its owner.
class TPhotonGolla : public TPhotonBlastSummon {
public:
    static const char *class_name;

    TPhotonGolla(PhotonSummonParams *params);
    virtual ~TPhotonGolla();
    // The constructor passes the chain's summon count; the body ignores it.
    void reset_material_color(u8 count);
    void spawn_concentrate();
    void collect_hit_targets();
    virtual void render();
    virtual void run_task();

    u16 owner_id;
    u8 pad_15A[2];
    NJS_ARGB material_color;
    u8 pad_16C[0x30];
    TObjChara *hit_target;      // the target collect_hit_targets queued a hit on
    u8 pad_1A0[4];
    TObjCollidable *owner;
    TObjChara *target;          // the nearest enemy inside the owner's front arc
    Vec beam_origin;            // the muzzle the beams leave from (attachment 2)
    s16 last_action;
    u8 pad_1BA[2];
    s32 is_first;
    s32 has_more;
    s32 visible;
    s32 frame;
};
LAYOUT_ASSERT(TPhotonGolla_size, sizeof(TPhotonGolla) == 0x1CC);

void destroy_golla_photon_blast_model(void);
void create_golla_photon_blast_model(void);

#endif
