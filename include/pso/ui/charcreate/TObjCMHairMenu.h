#ifndef PSO_UI_CHARCREATE_TOBJCMHAIRMENU_H
#define PSO_UI_CHARCREATE_TOBJCMHAIRMENU_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/ui/charcreate/CharacterAppearance.h"

class TObjCMHairMenu : public TObject {
public:
    CharacterAppearanceFields* appearance;
    s32 initialized, selection, count, ticks, active;
    f32 fade;
    s32 trailing[3];
    virtual ~TObjCMHairMenu();
    virtual void render();
    virtual void run_task();
public:
    void draw_tri_fan_2d(s32 count, s32 flags, f32 scale);
    void *create();
};

#endif
