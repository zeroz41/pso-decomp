#ifndef PSO_UI_HUD_TNOWLOADING_H
#define PSO_UI_HUD_TNOWLOADING_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

struct TNowLoading : public TObject {
    TNowLoading(TObject *parent, Vec *pos);
    virtual ~TNowLoading();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    void* pos;
    virtual void render();
    virtual void run_task();
    u8 unk_30[0x4];
    f32 m_34;
    u8 unk_38[0x4];
};

LAYOUT_ASSERT(TNowLoading_size, sizeof(TNowLoading) == 0x3C);

// Set while the ARAM transfer started by TLobby::aram_dma_blocking and friends is in flight; their DMA
// callback clears it.
extern volatile s32 aram_dma_pending;
#endif
