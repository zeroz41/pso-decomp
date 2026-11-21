#ifndef PSO_UNK_TLOC_LISTCLEAR_H
#define PSO_UNK_TLOC_LISTCLEAR_H
#include "types.h"
#include "pso/unk/TUnk_804A7260.h"

// The table at 0x804A71C4 is TLOC_ListClear's vtable, but it sits in the TU's user data ahead of the jump
// tables, where no CW-emitted vtable can go (CW writes every vtable at the TU end, after the jump tables).
// So the original spelled the table out, and the ctor (0x8013AF0C) and dtor (0x8013AE78) that store it
// are plain functions which call the TUnk_804A7260 ctor and dtor directly (the dtor with flag 0, which no
// C++ dtor call passes).
class TLOC_ListClear : public TUnk_804A7260 {
public:
    virtual ~TLOC_ListClear();
    void *init_lockon(TObject *parent, u16 id);
    virtual void run_task();
};
LAYOUT_ASSERT(TLOC_ListClear_size, sizeof(TLOC_ListClear) == 0x24);

extern "C" {
void *__ct__13TUnk_804A7260FP7TObjectUs(void *self, TObject *parent, u16 id);
void *__dt__13TUnk_804A7260Fv(void *self, s16 flags);
}

#endif
