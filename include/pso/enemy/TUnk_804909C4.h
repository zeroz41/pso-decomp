#ifndef PSO_ENEMY_TUNK_804909C4_H
#define PSO_ENEMY_TUNK_804909C4_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_804909C4 : public TObjCollidable {
public:
    TUnk_804909C4(u8 *player, s32 arg2, s32 arg3);
    virtual ~TUnk_804909C4();
    s32 sub_800A3290(s32);
    virtual void run_task();
    u8 unk_AC[0x4];
    f32 m_b0;
    u8 unk_B4[0x4];
    s32 m_b8;
    u8 unk_BC[0x4];
    s32 m_c0;
    s32 m_c4;
    u8 unk_C8[0x4];
    s32 m_cc;
    void * m_d0;
};
typedef char TUnk_804909C4_size[sizeof(TUnk_804909C4) == 0xD4 ? 1 : -1];

#endif
