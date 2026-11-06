#ifndef PSO_UNK_TUNK_804C3248_H
#define PSO_UNK_TUNK_804C3248_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TUnk_804C3248 : public TObjMotion {
public:
    TUnk_804C3248();
    virtual ~TUnk_804C3248();
    virtual void enter_scene();
    virtual void update_if_active();
    void setup_photon_blast_camera();
    void update_state();
    void free_photon();
    void update_photon_blast_attachments();
    void set_photon_blast_joint_callback();
    void begin_photon_summon_camera(s8);
    u8 unk_FC[0x4];
    u32 m_100;
    u8 unk_104[0x4];
    f32 m_108;
    u8 unk_10C[0x4];
    f32 m_110;
    u8 unk_114[0x4];
    f32 m_118;
    u8 unk_11C[0x4];
    f32 m_120;
    u8 unk_124[0x4];
    f32 m_128;
    u8 unk_12C[0x4];
    f32 m_130;
    s32 m_134;
    u8 unk_138[0x4];
    f32 m_13c;
    u8 unk_140[0x4];
    f32 m_144;
    s32 m_148;
    u8 unk_14C[0x4];
    f32 m_150;
    u8 unk_154[0x4];
};

#endif
