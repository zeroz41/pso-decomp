#ifndef PSO_ENEMY_TOBJENERE7BERURA_H
#define PSO_ENEMY_TOBJENERE7BERURA_H

#include "types.h"
#include "pso/enemy/TObjEneDD_ST.h"

struct TObjEneRe7Berura : public TObjEneDD_ST {
    virtual ~TObjEneRe7Berura();
    virtual void vfunc_88();
    virtual void vfunc_83();
    virtual void vfunc_105();
    virtual void vfunc_106();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    u8 unk_374[0x1C];
    u32 m_390;
    u8 unk_394[0x8];
    void* m_39c;
    u8 unk_3A0[0x4];
    u32 m_3c0;
    u32 m_3c4;
    u32 m_3c8;
    u32 m_3cc;
    u32 m_3d0;
    u8 _pad3D4[0x4];
    void* m_3d8;
    u8 _pad3DC[0x10];
    u32 m_3ec;
    u8 _pad3F0[0xC];
    void* m_3fc;
    u8 _pad400[0x18];
    u32 m_418;
    u32 m_41c;
    void* m_420;
    u8 _pad424[0x24];
    void* m_448;
    void state_attack(s32 arg1);
    void handle_message_transition(s32 msg);
    s32 check_death_trigger();
    void play_band_sound();
    void reload_stats_from_tables();
    void destroy_parts();
    u8 is_over_limit();
    s32 step_toward_target(s32 arg1, s32 arg2);
    void init_fields4B8();
    static void init_part(s32 arg0);
    static s32 collect_node_matrices(void *arg0, int idx);
    void update_collision_center();
    void init_enemy();
    static void destroy_children();
    void *create();
    static void load_static_resources();
    static void advance_state();
    static void demo_frame_callback();
    void run_flash_warning_state(s32 arg1);
    void handle_state(s32 arg1);
    static void *spawn_punch(void *arg0);
    u8 unk_430[0x88];
    s32 m_4b8;
    s32 m_4bc;
    u8 unk_4C0[0x4];
    s32 m_4c4;
    u8 unk_4C8[0x8];
    f32 m_4d0;
    u8 unk_4D4[0x4];
    f32 m_4d8;
    u8 unk_4DC[0x4];
    f32 m_4e0;
    void update_death_state(s32 mode);
    s32 acquire_target_in_view();
};

typedef char TObjEneRe7Berura_size[sizeof(TObjEneRe7Berura) == 0x4E4 ? 1 : -1];
#endif
