#ifndef PSO_PLAYER_TUNK_80491478_H
#define PSO_PLAYER_TUNK_80491478_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_80491478 : public TObjCollidable {
public:
    virtual ~TUnk_80491478();
    virtual void run_task();
    void *destroy_with_particle_cleanup(s16);
    u8 unk_AC[0x2];
    s16 m_ae;
    u8 unk_B0[0x4];
    f32 m_b4;
    u8 unk_B8[0x10];
    s32 m_c8;
    u8 unk_CC[0x4];
    s32 m_d0;
    u8 unk_D4[0x4];
    s32 m_d8;
    u8 unk_DC[0xC];
    f32 m_e8;
    u8 unk_EC[0x4];
    f32 m_f0;
    u8 unk_F4[0x4];
    f32 m_f8;
};
typedef char TUnk_80491478_size[sizeof(TUnk_80491478) == 0xFC ? 1 : -1];

#endif
