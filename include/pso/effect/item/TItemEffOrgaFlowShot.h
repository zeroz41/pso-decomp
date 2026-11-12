#ifndef PSO_EFFECT_ITEM_TITEMEFFORGAFLOWSHOT_H
#define PSO_EFFECT_ITEM_TITEMEFFORGAFLOWSHOT_H

#include "types.h"
#include "pso/item/TUnk_804E355C.h"

// The spawn parameters TUnk_804F14A8::emit_marker_effects fills after
// reset_field28 (0x80357734) and hands to create.
struct S_80357734 : S_802E451C {
    S_80357734 *reset_field28();
    s32 rotation_y;
    Vec joints[5];
};

struct TItemEffOrgaFlowShot : public TUnk_804E355C {
    TItemEffOrgaFlowShot(TObject *parent, S_80357734 *params);
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
    Vec pad_164;  // params joint 0 - joint 1, normalized
    Vec pad_170;  // params joint 4 - joint 3, normalized
    f32 pad_17C;  // sin(pad_188)
    f32 pad_180;
    f32 pad_184;  // cos(pad_188)
    s32 pad_188;  // params->rotation_y
    f32 pad_18C;
    f32 pad_190;
    f32 pad_194;
    f32 pad_198;
    s32 pad_19C;  // counted down by run_task
    static void approach_value(f32 *arg0, f32 farg0, f32 farg1);
    void bswap_6xAD_subordinate_action();
    void update_segments();
    void update_position_from_velocity();
    virtual void render();
    static void create(void *arg0, void *arg1);
};

typedef char TItemEffOrgaFlowShot_size[sizeof(TItemEffOrgaFlowShot) == 0x1A0 ? 1 : -1];
#endif
