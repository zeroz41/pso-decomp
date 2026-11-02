#ifndef PSO_PLAYER_TUNK_804E21F8_H
#define PSO_PLAYER_TUNK_804E21F8_H
#include "types.h"
#include "pso/player/TUnk_804E23F0.h"

class TUnk_804E21F8 : public TUnk_804E23F0 {
public:
    virtual ~TUnk_804E21F8();
    virtual void activate_effect(s32);
    virtual void reserved_53();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    void sub_802D577C();
    u8 unk_204[0x44];
    s16 m_248;
    u8 unk_24A[0x2];
    f32 m_24c;
    u8 unk_250[0x4];
};

#endif
