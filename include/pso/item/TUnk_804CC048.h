#ifndef PSO_ITEM_TUNK_804CC048_H
#define PSO_ITEM_TUNK_804CC048_H
#include "types.h"
#include "pso/TObject.h"

class TUnk_804CC048 : public TObject {
public:
    TUnk_804CC048(TObject *parent, void *arg2, void *arg3);
    // render is declared before the destructor: the vtable is emitted with render (0x8022884C), the destructor
    // (0x80076B64) lives in another TU.
    virtual void render();
    virtual ~TUnk_804CC048();
    u8 unk_1C[0x1080];
    u32 m_109c;
    u8 unk_10A0[0x4];
    void * m_10a4;
};
typedef char TUnk_804CC048_size[sizeof(TUnk_804CC048) == 0x10A8 ? 1 : -1];

#endif
