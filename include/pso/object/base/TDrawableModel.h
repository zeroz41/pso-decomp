#ifndef PSO_OBJECT_BASE_TDRAWABLEMODEL_H
#define PSO_OBJECT_BASE_TDRAWABLEMODEL_H
#include "types.h"

struct NJS_OBJECT;

// A chunk model drawn as it is; the vtable pointer follows the model.
class TDrawableModel {
public:
    NJS_OBJECT *model;
    virtual ~TDrawableModel() {}
    virtual void draw_model();
    NJS_OBJECT *get_model();
    TDrawableModel();
    void reset();
    void set_model(NJS_OBJECT *model);
};

#endif
