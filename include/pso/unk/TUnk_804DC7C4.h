#ifndef PSO_UNK_TUNK_804DC7C4_H
#define PSO_UNK_TUNK_804DC7C4_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804DC7C4 : public TObject {
public:
    virtual ~TUnk_804DC7C4();
    void *destroy(s16);
    virtual void render_shadows();
    virtual void render();
    u8 unk_1C[0x4];
    u32 m_20;
    u8 unk_24[0x4];
    f32 m_28;
    u8 unk_2C[0x4];
    f32 m_30;
    u8 unk_34[0x4];
    f32 m_38;
};
typedef char TUnk_804DC7C4_size[sizeof(TUnk_804DC7C4) == 0x3C ? 1 : -1];

#endif
