#ifndef PSO_ITEM_TUNK_804EDD44_H
#define PSO_ITEM_TUNK_804EDD44_H
#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TObjMotion.h"

class TUnk_804EDD44 : public TObject {
public:
    TUnk_804EDD44(TObject *parent, f32 *position, f32 *direction, s32 tint, s32 item_id);
    TUnk_804EDD44(TObject *parent, ActorBodyHit *hit, f32 *direction, s32 tint, s32 item_id);
    virtual ~TUnk_804EDD44();
    void anchor_card_effect();
    virtual void run_task();
    virtual void start_card_effect_flash();
    virtual void start_card_effect_trail();
    virtual void vfunc_8();
    void sub_8032E294();
    void destroy_effect_objects();
    void *particles[3];  // queued for destruction by destroy_effect_objects
    u8 unk_28[0x4];
    s32 m_2c;
    u8 unk_30[0x4];
    u16 m_34;
    u8 unk_36[0xE];
    f32 m_44;
    u8 unk_48[0x4];
    f32 m_4c;
    u32 m_50;
    u8 unk_54[0xC];
    s32 m_60;
    u8 unk_64[0x4];
    f32 m_68;
    u8 unk_6C[0x4];
};
typedef char TUnk_804EDD44_size[sizeof(TUnk_804EDD44) == 0x70 ? 1 : -1];

#endif
