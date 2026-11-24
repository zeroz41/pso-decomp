#ifndef PSO_OBJECT_BASE_TDRAWABLEMODEL_H
#define PSO_OBJECT_BASE_TDRAWABLEMODEL_H
#include "types.h"

// A chunk model drawn as it is; the vtable pointer follows the model.
class TDrawableModel {
public:
    void *model;
    virtual ~TDrawableModel() {}
    virtual void draw_model();
    void *get_model();
    TDrawableModel();
    void reset();
    void set_model(void *model);
};

#endif
