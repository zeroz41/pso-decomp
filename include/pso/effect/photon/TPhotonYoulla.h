#ifndef PSO_EFFECT_PHOTON_TPHOTONYOULLA_H
#define PSO_EFFECT_PHOTON_TPHOTONYOULLA_H

#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/effect/photon/PhotonBlastSummon.h"

// Youlla, the photon blast summon that plays the attachment effects of blast 6 and fades out.
class TPhotonYoulla : public TPhotonBlastSummon {
public:
    static const char *class_name;

    TPhotonYoulla(PhotonSummonParams *params);
    virtual ~TPhotonYoulla();
    // The constructor passes the chain's summon count; the body ignores it.
    void reset_material_color(u8 count);
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

LAYOUT_ASSERT(TPhotonYoulla_size, sizeof(TPhotonYoulla) == 0x1A8);

void destroy_youlla_photon_blast_model(void);
void create_youlla_photon_blast_model(void);

#endif
