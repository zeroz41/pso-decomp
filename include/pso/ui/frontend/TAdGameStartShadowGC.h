#ifndef PSO_UI_FRONTEND_TADGAMESTARTSHADOWGC_H
#define PSO_UI_FRONTEND_TADGAMESTARTSHADOWGC_H
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdGameStartGC.h"
#include "types.h"

// The dark band behind the GAME START banner: five quads that fade in over
// ten frames and out after frame 28.
class TAdGameStartShadowGC : public TObject {
public:
    TAdGameStartShadowGC(TObject *parent);
    virtual ~TAdGameStartShadowGC();
    virtual void run_task();
    virtual void render();

    void draw_band();

    GameStartQuad m_quads[5];
    s32 m_color;
    s32 m_alpha;
    s32 m_frame;
};

LAYOUT_ASSERT(TAdGameStartShadowGC_size, sizeof(TAdGameStartShadowGC) == 0xC8);

#endif
