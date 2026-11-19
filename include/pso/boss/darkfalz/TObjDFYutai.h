#ifndef PSO_BOSS_DARKFALZ_TOBJDFYUTAI_H
#define PSO_BOSS_DARKFALZ_TOBJDFYUTAI_H

#include "pso/system/task/TObject.h"
#include "types.h"

// Fades a player's model in or out over its life (TBoss4Type3::create_yutai).
class TObjDFYutai : public TObject {
public:
    TObjDFYutai(TObject *parent, s32 kind, u16 player_id);
    virtual ~TObjDFYutai();
    virtual void run_task();
    virtual void render();

    s32 kind;      // 0 and 2 fade out (slow, fast), 1 fades in
    u16 player_id; // client id of the player it draws
    f32 t;         // 1 -> 0 or 0 -> 1 by rate a frame; it ends at either end
    f32 rate;
};

#endif
