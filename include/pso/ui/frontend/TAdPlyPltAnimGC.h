#ifndef PSO_UI_FRONTEND_TADPLYPLTANIMGC_H
#define PSO_UI_FRONTEND_TADPLYPLTANIMGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdPlyPltAnimCtrlGC.h"

// One textured screen quad: position rect, then texture-coordinate rect
struct PlyPltAnimQuad {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

// Flash of one player plate (0-4) on the player select screen
class TAdPlyPltAnimGC : public TObject {
public:
    PlyPltAnimQuad quad;   // drawn by render(), position set by run_task()
    PlyPltAnimQuad target; // position set by start_anim_rect
    f32 center_x;          // centre of the target rect
    f32 center_y;
    f32 scale_x;           // size relative to the target rect
    f32 scale_y;
    u8 alpha;
    u8 _pad6D[0x3];
    s32 index;             // plate index (ctor argument)
    s32 state;             // set_anim_state: 1 while animating, 0 stopped
    s32 frame;             // animation frame, -1 when stopped

    TAdPlyPltAnimGC(TObject *parent, s32 plate);
    virtual ~TAdPlyPltAnimGC();
    virtual void run_task();
    virtual void render();
    void set_anim_state(s32 new_state);
    void sub_80355D38();
    void start_anim_rect(PlyPltAnimVec2 *pos);
    static TAdPlyPltAnimGC *get_or_create(TObject *parent, s32 index);
};

typedef char TAdPlyPltAnimGC_size[sizeof(TAdPlyPltAnimGC) == 0x7C ? 1 : -1];

extern TAdPlyPltAnimGC *TAdPlyPltAnimGC__instances[5];

extern "C" {
void TAdPlyPltAnimGC__sub_8035615C(void);
}
void register_player_prate(void);

#endif
