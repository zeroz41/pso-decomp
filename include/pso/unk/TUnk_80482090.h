#ifndef PSO_UNK_TUNK_80482090_H
#define PSO_UNK_TUNK_80482090_H
#include "types.h"
#include "pso/player/TUnk_804820C0.h"

// The 0x1C pieces TBoss2DeRolLe::run_task spawns from the breakup model in lbl_805D4B8C.
class TUnk_80482090 : public TUnk_804820C0 {
public:
    TUnk_80482090(TObject *parent, u32 matrix);
    virtual ~TUnk_80482090();
    virtual void render();
    virtual void run_task();
    BreakupPiece m_pieces[0x1C];
    u32 m_matrix;  // concatenated before each piece is drawn
    Vec m_origin;  // m_matrix applied to the origin
};
typedef char TUnk_80482090_size[sizeof(TUnk_80482090) == 0x500 ? 1 : -1];

#endif
