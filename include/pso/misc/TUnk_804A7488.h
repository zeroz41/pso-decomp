#ifndef PSO_MISC_TUNK_804A7488_H
#define PSO_MISC_TUNK_804A7488_H
#include "types.h"

// A model part drawn on its own (TPlyPhotonChair holds two of the derived
// TUnk_804A7478); the vtable pointer follows the model.
class TUnk_804A7488 {
public:
    void *model;
    virtual ~TUnk_804A7488();
    virtual void draw_model();
    void *get_id();
    u8 *init_parts();
    void sub_8035B66C();
};

extern "C" {
extern void *__vt__13TUnk_804A7488[];
void *__dt__13TUnk_804A7488Fv(TUnk_804A7488 *self, s16 del);
}

#endif
