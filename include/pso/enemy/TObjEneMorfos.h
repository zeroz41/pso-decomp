#ifndef PSO_ENEMY_TOBJENEMORFOS_H
#define PSO_ENEMY_TOBJENEMORFOS_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneDD_ST.h"

struct TObjEneMorfos : public TObjEneDD_ST {
    virtual ~TObjEneMorfos();
    s32 render_model_if_visible();
    virtual void vfunc_28();
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void vfunc_61();
    virtual void vfunc_88();
    virtual s32 vfunc_83();
    virtual void vfunc_106();
    void render();
    void run_task();
    u8 unk_374[0x4];
    s32 m_378;
    u8 unk_37C[0x14];
    u8 * m_390;
    u8 unk_394[0xC];
    f32 m_3a0;
    u32 m_3c0;
    u32 m_3c4;
    u8 _pad3C8[0xC];
    u32 m_3d4;
    u8 _pad3D8[0x14];
    void* m_3ec;
    u8 _pad3F0[0x18];
    void* m_408;
    u8 _pad40C[0x18];

    MaterialOpacityFade fade;
    u8 _padAfterFade[0x54];

    u32 m_494;
    void* m_498;
    static int get_instance();
    void draw_body();
    static void record_camera_path_point();
    void state_death(s32 arg1);
    void state_patrol(s32 arg1);
    void state_appear(s32 arg1);
    void handle_event_transition(s32 ev);
    void play_sound_in_band();
    void init_target_offsets();
    void set_hover_target_position();
    s32 approach_value(s32 arg1, s32 arg2);
    s32 try_enter_low_hp_state();
    s32 check_low_hp_trigger();
    void init_instance();
    static void unload_static_data();
    void *create();
    static s32 snap_to_ground(s32 arg0, s32 arg1);
    void update_ground_probe();
    static u8 check_value_in_range(void *arg0, u16 arg1, u16 arg2, u16 arg3);
    u8 unk_480[0x1C];
    f32 m_49c;
    u8 unk_4A0[0x4];
    f32 m_4a4;
    u8 unk_4A8[0x4];
    f32 m_4ac;
    u8 unk_4B0[0x4];
    s32 m_4b4;
    u8 unk_4B8[0x4];
    s32 m_4bc;
    u8 unk_4C0[0x4];
    f32 m_4c4;
    u8 unk_4C8[0x4];
    f32 m_4cc;
    u8 unk_4D0[0x4];
    f32 m_4d4;
    void render_part(s32 idx, s32 mode);
    void state_rotating_projectile_burst(s32 arg1);
    s32 select_target_in_view();
};

typedef char TObjEneMorfosFadeOffset[offsetof(TObjEneMorfos, fade) == 0x408 ? 1 : -1];

typedef char TObjEneMorfos_size[sizeof(TObjEneMorfos) == 0x4D8 ? 1 : -1];

extern "C" {
void *TObjEneMorfos__ct(void *arg0, void *arg1, void *arg2);
void TObjEneMorfos__sub_80332DBC(u8 *arg0, s32 arg1);
void TObjEneMorfos__sub_80332FD4(TObjEneMorfos *arg0, s32 arg1);
void TObjEneMorfos__sub_80333690(TObjEneMorfos *arg0, s32 arg1);
void TObjEneMorfos__sub_80333AD0(u8 *arg0, s32 arg1);
void TObjEneMorfos__sub_80333E48(u8 *arg0, s32 arg1);
void TObjEneMorfos__sub_80334030(u8 *arg0, s32 arg1);
void TObjEneMorfos__sub_803342B8(u8 *arg0, s32 arg1);
s32 TObjEneMorfos__sub_803344F0(void *arg0);
int TObjEneMorfos__sub_80334704(void);
void TObjEneMorfos__vt85(u8 *arg0, u32 arg1, s32 ev);
u8 *__dt__13TObjEneMorfosFv(u8 *arg0, s16 arg1);
void render__13TObjEneMorfosFv(u8 *arg0);
void run_task__13TObjEneMorfosFv(u8 *arg0);
void state_rotating_projectile_burst__13TObjEneMorfosFl(u8 *arg0, s32 arg1);
}

#endif
