#ifndef PSO_ENEMY_MORFOS_TOBJENEMORFOS_H
#define PSO_ENEMY_MORFOS_TOBJENEMORFOS_H

#include "types.h"

struct BmlResource;
struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/render/TUnk_80494938.h"

class TObject;

struct TObjEneMorfos : public TObjEneDD_ST {
    TObjEneMorfos(TObject *parent, void *set_data);
    virtual ~TObjEneMorfos();
    virtual f32 receive_physical_attack(void *attacker, f32 scale);
    virtual void dispatch_action(u32 state, s32 reason);
    s32 render_model_if_visible();
    virtual void refresh_target();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual void render();
    virtual void run_task();
    u32 m_3c0;
    u32 m_3c4;
    u8 _pad3C8[0xC];
    u32 m_3d4;
    u8 _pad3D8[0x14];
    TUnk_80490470 m_3ec;
    TUnk_80494938 m_408;
    RenderFadeState m_424[4];
    TObject *m_494;
    void* m_498;
    static BmlResource *get_instance();
    void draw_body();
    static void record_camera_path_point(NJS_OBJECT *);
    void state_death(s32 arg1);
    void state_patrol(s32 ev);
    void state_appear(s32 ev);
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
    static s32 snap_to_ground(s32 arg0, saddr arg1);
    void update_ground_probe();
    static u8 check_value_in_range(void *arg0, u16 arg1, u16 arg2, u16 arg3);
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
    void state_rotating_projectile_burst(s32 ev);
    s32 select_target_in_view();
};

#include <stddef.h>
LAYOUT_ASSERT(TObjEneMorfos_size, sizeof(TObjEneMorfos) == 0x4D8);
LAYOUT_ASSERT(TObjEneMorfos_fades, offsetof(TObjEneMorfos, m_3ec) == 0x3EC);

extern "C" {
void TObjEneMorfos__sub_80332DBC(u8 *ene_morfos, s32 ev);
void TObjEneMorfos__sub_80332FD4(TObjEneMorfos *arg0, s32 ev);
void TObjEneMorfos__sub_80333690(TObjEneMorfos *owner, s32 ev);
void TObjEneMorfos__sub_80333AD0(u8 *ene_morfos, s32 ev);
void TObjEneMorfos__sub_80333E48(u8 *ene_dd_st, s32 ev);
void TObjEneMorfos__sub_80334030(u8 *ene_dd, s32 ev);
void TObjEneMorfos__sub_803342B8(u8 *ene_dd, s32 ev);
s32 TObjEneMorfos__sub_803344F0(void *arg0);
int TObjEneMorfos__sub_80334704(void);
void state_rotating_projectile_burst__13TObjEneMorfosFl(u8 *arg0, s32 arg1);
}

#endif
