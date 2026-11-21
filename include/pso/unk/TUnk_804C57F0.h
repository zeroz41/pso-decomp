#ifndef PSO_UNK_TUNK_804C57F0_H
#define PSO_UNK_TUNK_804C57F0_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct ParticleDefinition;

class TUnk_804C57F0 : public TObject {
public:
    TUnk_804C57F0(TObject *arg_r4, void *arg2);
    virtual ~TUnk_804C57F0();
    void quad_sprite_reset_entries();
    virtual void render();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
    ParticleDefinition *definition;
};

#endif
