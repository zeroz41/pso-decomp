#ifndef PSO_UNK_TUNK_80499970_H
#define PSO_UNK_TUNK_80499970_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_80499970 : public TObject {
public:
    virtual ~TUnk_80499970();
    virtual void render();
    void step_fade_opacity_decrease();
    u8 unk_1C[0x8];
    s32 m_24;
    u8 unk_28[0x4];
};
typedef char TUnk_80499970_size[sizeof(TUnk_80499970) == 0x2C ? 1 : -1];

#endif
