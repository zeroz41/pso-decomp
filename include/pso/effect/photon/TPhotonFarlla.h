#ifndef PSO_EFFECT_PHOTON_TPHOTONFARLLA_H
#define PSO_EFFECT_PHOTON_TPHOTONFARLLA_H
#include "types.h"
#include "pso/effect/photon/PhotonBlastSummon.h"

// Farlla, the photon blast summon that strikes every enemy inside its collision body.
class TPhotonFarlla : public TPhotonBlastSummon {
public:
    static const char *class_name;

    TPhotonFarlla(PhotonSummonParams *params);
    virtual ~TPhotonFarlla();
    // The constructor passes the chain's summon count; the body ignores it.
    void reset_material_color(u8 count);
    void collect_hit_targets();
    virtual void render();
    virtual void run_task();

    u8 pad_158[0x24];
    u16 owner_id;
    u8 pad_17E[2];
    TObjCollidable *owner;
    NJS_ARGB material_color;  // run_task fades its alpha out at the end
    s16 last_action;
    u8 pad_196[2];
    s32 is_first;
    s32 has_more;
    s32 visible;
    s32 frame;
};
LAYOUT_ASSERT(TPhotonFarlla_size, sizeof(TPhotonFarlla) == 0x1A8);

void destroy_farlla_photon_blast_model(void);
void create_farlla_photon_blast_model(void);

#endif
