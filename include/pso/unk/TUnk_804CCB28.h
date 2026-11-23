#ifndef PSO_UNK_TUNK_804CCB28_H
#define PSO_UNK_TUNK_804CCB28_H
#include "types.h"
#include <stddef.h>
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"

struct TEffIndirect;

class TUnk_804CCB28 : public TObject {
public:
    virtual ~TUnk_804CCB28();
    void spawn_rafoie_explosion_bursts();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    s16 m_20;
    u8 unk_22[0x2];
    TEffIndirect *indirect_effect;
    Vec position;
    f32 m_34;
    f32 m_38;
    f32 m_3c;
    f32 m_40;
    f32 m_44;
    f32 m_48;
    f32 m_4c;
    f32 m_50;
    f32 m_54;
    s32 m_58;
    s32 m_5c;
    s32 m_60;
};
LAYOUT_ASSERT(TUnk_804CCB28_size, sizeof(TUnk_804CCB28) == 0x64);

LAYOUT_ASSERT(FireExplosionPositionOffset, offsetof(TUnk_804CCB28, position) == 0x28);

// Initializes the previously allocated 0x64-byte effect and returns it.
extern "C" TUnk_804CCB28 *create_fire_explosion_effect(u8 *storage, f32 radius, const Vec *position, s16 kind, TObject *parent);

#endif
