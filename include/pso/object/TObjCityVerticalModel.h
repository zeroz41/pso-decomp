#ifndef PSO_OBJECT_TOBJCITYVERTICALMODEL_H
#define PSO_OBJECT_TOBJCITYVERTICALMODEL_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

// City model that rises and sinks along y every 300 frames.
class TObjCityVerticalModel : public TObjBase {
public:
    TObjCityVerticalModel(TObject *parent, void *set_data);
    virtual ~TObjCityVerticalModel();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_13(s32);
    s32 state;
    s32 last_state;
    s32 wait_timer;
    f32 y_offset;
};
LAYOUT_ASSERT(TObjCityVerticalModel_size, sizeof(TObjCityVerticalModel) == 0xA0);

#endif
