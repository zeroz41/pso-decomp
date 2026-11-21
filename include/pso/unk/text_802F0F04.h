#ifndef PSO_UNK_TEXT_802F0F04_H
#define PSO_UNK_TEXT_802F0F04_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarpForest.h"

// A forest area warp that stays hidden until TObjBoss2Tunnel__sub_802F2070 reports true.
struct TUnk_804E48D8 : public TObjAreaWarpForest {
    TUnk_804E48D8(TObject *parent, void *set_data);
    virtual ~TUnk_804E48D8();
    virtual void run_task();
    virtual void render();
    s32 visible; // set once TObjBoss2Tunnel__sub_802F2070 passes; render is skipped until then
};

LAYOUT_ASSERT(TUnk_804E48D8_size, sizeof(TUnk_804E48D8) == 0xE0);
#endif
