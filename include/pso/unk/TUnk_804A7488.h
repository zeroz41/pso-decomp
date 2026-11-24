#ifndef PSO_UNK_TUNK_804A7488_H
#define PSO_UNK_TUNK_804A7488_H
#include "types.h"

// A model part drawn on its own (TPlyPhotonChair holds two of the derived
// TUnk_804A7478); the vtable pointer follows the model.
class TUnk_804A7488 {
public:
    void *model;
    virtual ~TUnk_804A7488() {}
    virtual void draw_model();
    void *get_model();
    TUnk_804A7488();
    void reset();
    void set_model(void *model);
};

#endif
