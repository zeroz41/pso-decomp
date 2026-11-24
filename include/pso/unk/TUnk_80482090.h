#ifndef PSO_UNK_TUNK_80482090_H
#define PSO_UNK_TUNK_80482090_H
#include "types.h"
#include "dolphin/mtx/GeoTypes.h"
#include "pso/player/TUnk_804820C0.h"

// The 0x1C pieces TBoss2DeRolLe::run_task spawns from the breakup model in lbl_805D4B8C.
class TUnk_80482090 : public TUnk_804820C0 {
public:
    TUnk_80482090(TObject *parent, const f32 (*matrix)[4]);
    virtual ~TUnk_80482090();
    virtual void render();
    virtual void run_task();
    BreakupPiece m_pieces[0x1C];
    const f32 (*m_matrix)[4];  // concatenated before each piece is drawn
    Vec m_origin;  // m_matrix applied to the origin
};
LAYOUT_ASSERT(TUnk_80482090_size, sizeof(TUnk_80482090) == 0x500);

#endif
