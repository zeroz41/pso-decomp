#ifndef PSO_UNK_TUNK_804A7254_H
#define PSO_UNK_TUNK_804A7254_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// A colour (ahead of the vptr) that TMainCursor::get_rader_map fills with copy_argb.
// Members of TMainCursor (+0x4C), TLockOnCursor (+0x48) and TPlyPhotonChair (+0xD0).
class TUnk_804A7254 {
public:
    NJS_ARGB color;

    TUnk_804A7254();
    virtual ~TUnk_804A7254();
    void get_color(NJS_ARGB *out);
};


LAYOUT_ASSERT(TUnk_804A7254_size, sizeof(TUnk_804A7254) == 0x14);

#endif
