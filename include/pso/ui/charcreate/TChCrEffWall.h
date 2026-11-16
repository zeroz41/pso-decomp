#ifndef PSO_UI_CHARCREATE_TCHCREFFWALL_H
#define PSO_UI_CHARCREATE_TCHCREFFWALL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrEffWall : public TObject {
public:
    TChCrEffWall(TObject *_w1);
    virtual ~TChCrEffWall();
    virtual void render();
    static void draw_default_sprite();
};

extern "C" {
void *fn_8029AE88(void *arg0);
}

// --- C functions defined in TChCrEffWall.cpp ---
extern "C" {
void *fn_8029AE88(void *arg0);
}
// --- end of C functions

#endif
