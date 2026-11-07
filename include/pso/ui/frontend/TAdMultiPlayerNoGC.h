#ifndef PSO_UI_FRONTEND_TADMULTIPLAYERNOGC_H
#define PSO_UI_FRONTEND_TADMULTIPLAYERNOGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

// Player-number plate drawn over a multiplayer character slot ("f128_player_ad").
class TAdMultiPlayerNoGC : public TObject {
public:
    u32 player_no;   // ctor argument; selects the plate row in the texture
    f32 quad[8];     // screen rect x0, y0, x1, y1 then uv u0, v0, u1, v1
    f32 x;           // plate position from the slot index
    f32 y;

    TAdMultiPlayerNoGC(TObject *parent, s32 player_count, u32 slot, u32 player_no);
    virtual ~TAdMultiPlayerNoGC();
    virtual void run_task();
    virtual void render();

    void render_status();
};

#endif
