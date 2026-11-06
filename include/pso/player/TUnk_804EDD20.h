#ifndef PSO_PLAYER_TUNK_804EDD20_H
#define PSO_PLAYER_TUNK_804EDD20_H
#include "types.h"
#include "pso/item/TUnk_804EDD44.h"

class TUnk_804EDD20 : public TUnk_804EDD44 {
public:
    TUnk_804EDD20(TObject *parent, f32 *position, f32 *direction, s32 tint, s32 item_id);
    TUnk_804EDD20(TObject *parent, ActorBodyHit *hit, f32 *direction, s32 tint, s32 item_id);
    virtual ~TUnk_804EDD20();
    void init_offset_vectors();
    virtual void render();
    virtual void vfunc_8();
    virtual void start_card_effect_trail();
    virtual void start_card_effect_flash();
    u8 unk_70[0x4];
    void * m_74;
    u8 unk_78[0x4];
    void * m_7c;
    f32 m_80;
    u8 unk_84[0x4];
    u8 * m_88;
    u8 unk_8C[0x4];
};
typedef char TUnk_804EDD20_size[sizeof(TUnk_804EDD20) == 0x90 ? 1 : -1];

#endif
