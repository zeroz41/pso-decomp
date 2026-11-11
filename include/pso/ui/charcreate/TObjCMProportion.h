#ifndef PSO_UI_CHARCREATE_TOBJCMPROPORTION_H
#define PSO_UI_CHARCREATE_TOBJCMPROPORTION_H
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
class TObjCMProportion : public TObject {
public:
    CharacterAppearanceFields* appearance;
    s32 initialized,active;
    f32 fade;
    TObjCMProportion(TObject *parent);
    virtual ~TObjCMProportion();
    virtual void run_task();
    virtual void render();
    static TObjCMProportion *create(TObject *parent);
public:
    static f32 get_ratio();
    static f32 get_right_trigger_ratio();
    static void poll_pad_buttons();
};
#endif
