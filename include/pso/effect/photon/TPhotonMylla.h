#ifndef PSO_EFFECT_PHOTON_TPHOTONMYLLA_H
#define PSO_EFFECT_PHOTON_TPHOTONMYLLA_H

#include "types.h"
#include "pso/effect/photon/PhotonBlastSummon.h"

// Mylla, the photon blast summon that comes with Youlla and strikes the area around its owner.
class TPhotonMylla : public TPhotonBlastSummon {
public:
    static const char *class_name;

    TPhotonMylla(PhotonSummonParams *params);
    virtual ~TPhotonMylla();
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

LAYOUT_ASSERT(TPhotonMylla_color_offset, offsetof(TPhotonMylla, material_color) == 0x184);
LAYOUT_ASSERT(TPhotonMylla_size, sizeof(TPhotonMylla) == 0x1A8);

void destroy_mylla_photon_blast_model(void);
void create_mylla_photon_blast_model(void);

#endif
