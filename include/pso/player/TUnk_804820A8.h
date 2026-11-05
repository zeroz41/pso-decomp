#ifndef PSO_PLAYER_TUNK_804820A8_H
#define PSO_PLAYER_TUNK_804820A8_H
#include "types.h"
#include "pso/player/TUnk_804820C0.h"

// The 19 pieces TBoss2Joint spawns from shared_breakup_model.
class TUnk_804820A8 : public TUnk_804820C0 {
public:
    TUnk_804820A8(TObject *parent, const Vec *pos);
    virtual ~TUnk_804820A8();
    virtual void run_task();
    virtual void render();
    BreakupPiece m_pieces[19];
};
typedef char TUnk_804820A8_size[sizeof(TUnk_804820A8) == 0x364 ? 1 : -1];

#endif
