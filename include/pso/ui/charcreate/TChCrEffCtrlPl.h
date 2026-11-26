#ifndef PSO_UI_CHARCREATE_TCHCREFFCTRLPL_H
#define PSO_UI_CHARCREATE_TCHCREFFCTRLPL_H

#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"
#include "types.h"

class TChCrEffCtrlPl : public TObject {
public:
    TChCrEffCtrlPl(TObject *parent);
    virtual ~TChCrEffCtrlPl();
    virtual void run_task();
    virtual void render();
public:
    static const char *name;
    static s32 get_clamped_player_index();
    static TChCrEffCtrlPl *create(TObject *parent);

    s32 sprite_id;
    s32 overlay_sprite_id;
    vec2f pos;
    f32 fade;
    f32 overlay_alpha;
    s32 blink_angle;
};

LAYOUT_ASSERT(TChCrEffCtrlPl_size, sizeof(TChCrEffCtrlPl) == 0x38);

extern "C" {
int is_controller_plate_shown();
}

#endif
