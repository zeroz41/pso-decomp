#ifndef PSO_UNK_TUNK_804A5D10_H
#define PSO_UNK_TUNK_804A5D10_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804A5D10 : public TObject {
public:
    virtual ~TUnk_804A5D10();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x8];
    f32 m_24;
    u8 unk_28[0x10];
    s32 m_38;
    u8 unk_3C[0x4];
    s32 m_40;
};
typedef char TUnk_804A5D10_size[sizeof(TUnk_804A5D10) == 0x44 ? 1 : -1];

#endif
