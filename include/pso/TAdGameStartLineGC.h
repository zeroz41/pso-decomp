#ifndef PSO_TADGAMESTARTLINEGC_H
#define PSO_TADGAMESTARTLINEGC_H
#include "pso/TObject.h"
#include "types.h"

struct StartLineQuad {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

class TAdGameStartLineGC : public TObject {
public:
    virtual ~TAdGameStartLineGC();
    virtual void run_task();
    virtual void render();
    void fn_80320DE8();

    StartLineQuad base[4];
    StartLineQuad cur[4];
    u8 m_11c[0x3C];
    s32 m_158;
    s32 m_15c;
};

#endif
