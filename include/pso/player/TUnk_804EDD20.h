#ifndef PSO_PLAYER_TUNK_804EDD20_H
#define PSO_PLAYER_TUNK_804EDD20_H
#include "types.h"
#include "pso/item/TUnk_804EDD44.h"
#include "pso/system/NinjaTypes.h"

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
    u32 card_flags;     // bit 0 while the card fades in (start_card_effect_flash)
    Vec scale;
    NJS_ARGB color;     // the constant material colour render draws the card with; a fades between -1 and 0
};
LAYOUT_ASSERT(TUnk_804EDD20_size, sizeof(TUnk_804EDD20) == 0x90);

#endif
