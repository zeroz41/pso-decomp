#ifndef PSO_ITEM_TUNK_804B97C0_H
#define PSO_ITEM_TUNK_804B97C0_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TUnk_804B97C0 : public TObjCollidable {
public:
    TUnk_804B97C0(TObject *parent);
    virtual ~TUnk_804B97C0();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void render();
    virtual void run_task();
    // The far_depth and radius render passes to update_object_view_visibility.
    f32 view_far_depth;
    f32 view_radius;
};

#endif
