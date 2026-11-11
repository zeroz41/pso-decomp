#ifndef PSO_UI_CHARCREATE_TOBJCMAUTOMKDATA_H
#define PSO_UI_CHARCREATE_TOBJCMAUTOMKDATA_H
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
class TObjCMAutoMkData : public TObject {
public:
    CharacterAppearanceFields* appearance;
    s32 state,ticks;
    s16 red,green,blue,padding;
    f32 width,height,fade;
    TObjCMAutoMkData(TObject *parent);
    virtual ~TObjCMAutoMkData();
    virtual void run_task();
    virtual void render();
    static TObjCMAutoMkData *create(TObject *parent);
};
#endif
