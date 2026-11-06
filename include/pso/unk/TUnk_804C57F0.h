#ifndef PSO_UNK_TUNK_804C57F0_H
#define PSO_UNK_TUNK_804C57F0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804C57F0 : public TObject {
public:
    virtual ~TUnk_804C57F0();
    void quad_sprite_reset_entries();
    virtual void render();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
    void * m_28;
};

#endif
