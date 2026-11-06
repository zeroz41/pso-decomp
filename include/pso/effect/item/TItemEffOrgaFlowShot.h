#ifndef PSO_EFFECT_ITEM_TITEMEFFORGAFLOWSHOT_H
#define PSO_EFFECT_ITEM_TITEMEFFORGAFLOWSHOT_H

#include "types.h"
#include "pso/item/TUnk_804E355C.h"

struct TItemEffOrgaFlowShot : public TUnk_804E355C {
    virtual ~TItemEffOrgaFlowShot();
    virtual void run_task();
    void* m_c4;
    u8 _padC8[0x18];
    u32 m_e0;
    u8 unk_E4[0x10];
    f32 m_f4;
    u8 unk_F8[0x4];
    f32 m_fc;
    u32 m_100;
    u8 unk_104[0x10];
    f32 m_114;
    u8 unk_118[0x4];
    f32 m_11c;
    u32 m_120;
    u8 unk_124[0x10];
    f32 m_134;
    u8 unk_138[0x4];
    f32 m_13c;
    u32 m_140;
    u8 _pad144[0x1C];
    u32 m_160;
    void* m_164;
    u8 unk_168[0x4];
    f32 m_16c;
    void* m_170;
    u8 unk_174[0x4];
    f32 m_178;
    f32 m_17c;
    u8 unk_180[0x4];
    f32 m_184;
    u32 m_188;
    u8 _pad18C[0x4];
    void* m_190;
    void* m_194;
    u8 _pad198[0x4];
    u32 m_19c;
    static void approach_value(f32 *arg0, f32 farg0, f32 farg1);
    void bswap_6xAD_subordinate_action();
    void update_segments();
    void update_position_from_velocity();
    virtual void render();
    static void create(void *arg0, void *arg1);
};

typedef char TItemEffOrgaFlowShot_size[sizeof(TItemEffOrgaFlowShot) == 0x1A0 ? 1 : -1];
#endif
