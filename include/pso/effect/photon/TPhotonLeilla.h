#ifndef PSO_EFFECT_PHOTON_TPHOTONLEILLA_H
#define PSO_EFFECT_PHOTON_TPHOTONLEILLA_H

#include "types.h"
#include "pso/effect/photon/PhotonBlastSummon.h"

// Leilla, the photon blast summon of blast 4.
class TPhotonLeilla : public TPhotonBlastSummon {
public:
    static const char *class_name;

    TPhotonLeilla(PhotonSummonParams *params);
    virtual ~TPhotonLeilla();
    // The constructor passes the chain's summon count; the body ignores it.
    void reset_material_color(u8 count);
    virtual void render();
    virtual void run_task();

    u8 pad_158[0x24];
    u16 owner_id;
    u8 pad_17E[2];
    NJS_ARGB material_color;  // run_task fades its alpha out at the end
    s16 last_action;
    u8 pad_192[2];
    s32 is_first;
    s32 has_more;
    s32 visible;
    u8 pad_1A0[0xC];
    s32 frame;
};

LAYOUT_ASSERT(TPhotonLeilla_color_offset, offsetof(TPhotonLeilla, material_color) == 0x180);
LAYOUT_ASSERT(TPhotonLeilla_size, sizeof(TPhotonLeilla) == 0x1B0);

// TPhotonLaser's slot in the photon blast load callback table; the laser keeps no resources.
void release_photon_laser_resources(void);
void load_photon_laser_resources(void);

void destroy_leilla_photon_blast_model(void);
void create_leilla_photon_blast_model(void);

#endif
