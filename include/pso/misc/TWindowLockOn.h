#ifndef PSO_MISC_TWINDOWLOCKON_H
#define PSO_MISC_TWINDOWLOCKON_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowLockOn : public TWindowBase {
    virtual ~TWindowLockOn();
    void request_close();
    virtual void render();
    u8 _pad1C[0x4];
    u16 m_20;
    u8 _pad22[0x2];
    void* m_24;
    u8 unk_28[0x4];
    u32 m_2c;
    f32 m_30;
    u8 unk_34[0x4];
    f32 m_38;
    u8 unk_3C[0x4];
    f32 m_40;
    u8 unk_44[0x4];
    f32 m_48;
    u8 unk_4C[0x4];
    u32 m_50;
    u8 _pad54[0x8];
    u32 m_5c;
    u16 m_60;
    u8 _pad62[0x2];
    u32 m_64;
    void* m_68;
    u8 _pad6C[0x4];
    u32 m_70;
    u32 m_74;
    u32 m_78;
    s32 get_target_id();
    static f32 get_target_distance();
    void validate_target();
    static void refresh_ground_item();
    void update_photon_blast_marker();
    static void *create_for_target(s32 arg0, u16 arg1);
    virtual void run_task();
    void update_for_player_index(s32 arg1);
    void refresh_enemy_statuses();
};

typedef char TWindowLockOn_size[sizeof(TWindowLockOn) == 0x7C ? 1 : -1];
#endif
