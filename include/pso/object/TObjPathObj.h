#ifndef PSO_OBJECT_TOBJPATHOBJ_H
#define PSO_OBJECT_TOBJPATHOBJ_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjPathObj : public TObjBase {
    TObjPathObj(TObject *parent, void *set_data);
    virtual ~TObjPathObj();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void render();
    virtual void run_task();
    f32 view_distance; // render's first update_object_view_visibility argument; 500 unless a subclass sets it
    f32 m_94;
};

LAYOUT_ASSERT(TObjPathObj_size, sizeof(TObjPathObj) == 0x98);
#endif
