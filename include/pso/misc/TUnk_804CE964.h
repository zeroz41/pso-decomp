#ifndef PSO_MISC_TUNK_804CE964_H
#define PSO_MISC_TUNK_804CE964_H
#include "types.h"
#include "pso/misc/TWindowBase.h"

class TUnk_804CE964 : public TWindowBase {
public:
    virtual ~TUnk_804CE964();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x18];
    f32 m_34;
    u8 unk_38[0xC];
    f32 m_44;
    u8 unk_48[0x18];
    void * m_60;
    u8 unk_64[0x4];
    f32 m_68;
    u8 unk_6C[0x8];
};
typedef char TUnk_804CE964_size[sizeof(TUnk_804CE964) == 0x74 ? 1 : -1];

#endif
