#ifndef PSO_UNK_TUNK_804A7254_H
#define PSO_UNK_TUNK_804A7254_H

#include "types.h"

// Vtable 0x804A7254 {0, 0, dtor}. Four floats ahead of the vptr; TMainCursor::get_rader_map
// copies them with copy_argb, so probably an ARGB colour (inferred, not named).
// Members of TMainCursor (+0x4C), TLockOnCursor (+0x48) and TPlyPhotonChair (+0xD0).
class TUnk_804A7254 {
public:
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_c;

    TUnk_804A7254();
    virtual ~TUnk_804A7254();
};

extern "C" {
// TUnk_804A7254::TUnk_804A7254(), for TPlyPhotonChair's free constructor, which builds the member in place.
TUnk_804A7254 *__ct__13TUnk_804A7254Fv(void *self);
}

LAYOUT_ASSERT(TUnk_804A7254_size, sizeof(TUnk_804A7254) == 0x14);

#endif
