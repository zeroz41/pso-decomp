#ifndef PSO_UI_CHARCREATE_TCHCREFFCTRLPL_H
#define PSO_UI_CHARCREATE_TCHCREFFCTRLPL_H

#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"
#include "types.h"

class TChCrEffCtrlPl : public TObject {
public:
    TChCrEffCtrlPl(TObject *_w1);
    virtual ~TChCrEffCtrlPl();
    virtual void run_task();
    virtual void render();
public:
    static s32 get_clamped_player_index();
    void *create();

    s32 sprite_id;
    s32 m_20;
    vec2f pos;
    f32 fade;
    f32 m_30;
    s32 m_34;
};

typedef char TChCrEffCtrlPl_size[sizeof(TChCrEffCtrlPl) == 0x38 ? 1 : -1];

extern "C" {
int TChCrEffCtrlPl__sub_80298F6C(void *p);
}

#endif
