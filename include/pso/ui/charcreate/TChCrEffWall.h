#ifndef PSO_UI_CHARCREATE_TCHCREFFWALL_H
#define PSO_UI_CHARCREATE_TCHCREFFWALL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/math/TMath.h"

class TChCrEffWall : public TObject {
public:
    TChCrEffWall(TObject *_w1);
    virtual ~TChCrEffWall();
    virtual void render();
    static void draw_default_sprite(s32 sprite_id, const vec2f *position, f32 depth);
};

extern "C" TChCrEffWall *fn_8029AE88(TObject *parent);

#endif
