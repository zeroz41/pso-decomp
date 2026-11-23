#ifndef PSO_OBJECT_TUNK_804B5C08_H
#define PSO_OBJECT_TUNK_804B5C08_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

// City model that rises and sinks along y every 300 frames.
class TUnk_804B5C08 : public TObjBase {
public:
    TUnk_804B5C08(TObject *parent, void *set_data);
    virtual ~TUnk_804B5C08();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_13(s32);
    s32 state;
    s32 last_state;
    s32 wait_timer;
    f32 y_offset;
};
LAYOUT_ASSERT(TUnk_804B5C08_size, sizeof(TUnk_804B5C08) == 0xA0);

#endif
