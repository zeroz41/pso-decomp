#ifndef PSO_UNK_TUNK_804A7260_H
#define PSO_UNK_TUNK_804A7260_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TUnk_8013E020.h"

// Base of the lock-on cursor tasks TLOC_Start, TLOC_End and TLOC_ListClear (vtable 0x804A7260). Its ctor
// (0x8013E0D8) takes the parent task and the lock-on target id, which goes into the target record.
class TUnk_804A7260 : public TObject {
public:
    TUnk_804A7260(TObject *parent, u16 id);
    virtual ~TUnk_804A7260();
    TUnk_8013E020 m_target;
};
LAYOUT_ASSERT(TUnk_804A7260_size, sizeof(TUnk_804A7260) == 0x24);

#endif
