#ifndef PSO_UI_FRONTEND_TADTITLETEXGC_H
#define PSO_UI_FRONTEND_TADTITLETEXGC_H

#include <stddef.h>
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "types.h"

struct TitleTexQuad {
    f32 x, y, x2, y2;
    f32 u0, v0, u1, v1;
};

class TAdTitleTexGC : public TObject {
public:
    TAdTitleTexGC(TObject *parent);
    virtual ~TAdTitleTexGC();
    void sub_802A4D74(s32, u8 *, u8 *);
    void render_status_pair(s32 color);
    virtual void run_task();
    virtual void render();
    void update_title_tex_positions();
    TAdTitleRect rects[3];   // 0x1C: the status plates; render_status_pair draws the first two
    u32 alpha;               // 0x7C: fades in by 0xC a frame up to 0xFF
    s32 frames;              // 0x80: slide-in frames, -1 up to 20
    NJS_POINT2 rest_pos[3];  // 0x84: where each plate stops sliding in from the right
};

LAYOUT_ASSERT(TAdTitleTexGC_size, sizeof(TAdTitleTexGC) == 0x9C);

extern "C" {
void TLobby__sub_802A5154(void);
}

#endif
