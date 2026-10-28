#ifndef PSO_OBJECT_TUNK_8049442C_H
#define PSO_OBJECT_TUNK_8049442C_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_8049442C : public TObjCollidable {
public:
    virtual ~TUnk_8049442C();
    void sub_800D4200();
    void update_ground_fall(s32 *, f32);
    void *destroy(s16);
    virtual void render();
    virtual void run_task();
    u8 unk_AC[0x4];
    f32 m_b0;
    u8 unk_B4[0x4];
    s32 m_b8;
    s32 m_bc;
    u8 unk_C0[0x4];
    s32 m_c4;
    u8 unk_C8[0x4];
    s32 m_cc;
    u8 unk_D0[0x4];
    f32 m_d4;
    u8 unk_D8[0x4];
    s32 m_dc;
    u8 unk_E0[0x4];
    f32 m_e4;
    u8 unk_E8[0x4];
    s32 m_ec;
};
typedef char TUnk_8049442C_size[sizeof(TUnk_8049442C) == 0xF0 ? 1 : -1];

#endif
