#ifndef PSO_UNK_TUNK_8048E728_H
#define PSO_UNK_TUNK_8048E728_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_8048E728 : public TObject {
public:
    virtual ~TUnk_8048E728();
    void free_from_heap();
    void apply_particle_model_fade_color(s32);
    void draw_particle_refraction_quad();
    s32 is_particle_sprite_additive();
    u8 unk_1C[0x4];
    void * m_20;
    u8 unk_24[0x4];
    f32 m_28;
    u8 unk_2C[0x4];
    f32 m_30;
    u8 unk_34[0x4];
    f32 m_38;
    f32 m_3c;
    u8 unk_40[0x4];
    f32 m_44;
    u8 unk_48[0x10];
    f32 m_58;
    u8 unk_5C[0x14];
    f32 m_70;
    u8 unk_74[0x4];
    f32 m_78;
    u8 unk_7C[0x4];
    f32 m_80;
    u8 unk_84[0x4];
    f32 m_88;
    u8 unk_8C[0xA];
    s16 m_96;
    u8 unk_98[0x4];
    s32 m_9c;
    u8 unk_A0[0x4];
    f32 m_a4;
    u8 unk_A8[0x8];
    u32 m_b0;
    u8 unk_B4[0x4];
    u32 m_b8;
    u8 unk_BC[0x4];
};

#endif
