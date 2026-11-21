#ifndef PSO_EFFECT_PHOTON_TPHOTONLINE_H
#define PSO_EFFECT_PHOTON_TPHOTONLINE_H

#include "types.h"
#include "pso/object/base/TObjChara.h"

// What a photon blast passes to the line it fires.
struct PhotonLineParams {
    Vec pos;
    Vec dir;
    f32 scale;
    f32 power;
};

struct TPhotonLine : public TObjChara {
    TPhotonLine(PhotonLineParams *params, TObject *parent, u16 target_id);
    virtual ~TPhotonLine();
    virtual void run_task();
    void* m_334;
    u8 _pad338[0x18];
    u32 m_350;
    u8 _pad354[0x14];
    u16 m_368;
    virtual void render();
    u8 unk_36A[0xE];
};

LAYOUT_ASSERT(TPhotonLine_size, sizeof(TPhotonLine) == 0x378);
#endif
