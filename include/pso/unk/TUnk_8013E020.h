#ifndef PSO_UNK_TUNK_8013E020_H
#define PSO_UNK_TUNK_8013E020_H
#include "types.h"

// The 8-byte target record TForceOperate and TUnk_804A7260 embed at +0x1C. The ctor at 0x8013E020 sets
// a = b = 0xFFFF and c = 0; the owners' ctors then store an entity or lock-on target id with set_field_0,
// whose u16 parameter is passed through without an extsh. The dtor at 0x8013DFDC is the empty out-of-line
// dtor (the owners' dtors call it with -1).
class TUnk_8013E020 {
public:
    TUnk_8013E020();
    ~TUnk_8013E020();
    void set_field_0(u16 v);

    u16 a;
    u16 b;
    s32 c;
};
LAYOUT_ASSERT(TUnk_8013E020_size, sizeof(TUnk_8013E020) == 0x8);

#endif
