#ifndef PSO_ENEMY_TOBJENEBM5GIBONU_H
#define PSO_ENEMY_TOBJENEBM5GIBONU_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "dolphin/mtx.h"

struct TObjPlayer;

struct TObjEneBm5GibonU : public TObjEneDD_ST {
    virtual ~TObjEneBm5GibonU();
    void sub_800D10A0();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_88();
    virtual s32 vfunc_83();
    virtual void render_debug();
    void update_center_position();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    u8 unk_374[0x14];
    s32 m_388;
    u8 unk_38C[0x4];
    TObjPlayer *m_390;
    f32 m_394;
    u8 unk_398[0x4];
    f32 m_39c;
    u8 unk_3A0[0xC];
    f32 m_3ac;
    u8 unk_3B0[0x10];
    void* m_3c0;
    u8 _pad3C4[0x8];
    void* m_3cc;
    u8 _pad3D0[0x8];

    MaterialOpacityFade fade;

    void* m_3f4;
    u8 _pad3F8[0x6C];
    u32 m_464;
    u8 _pad468[0xC];
    u16 m_474;
    u8 _pad476[0x2];
    u32 m_478;
    void* m_47c;
    u8 _pad480[0x8];
    Vec m_488;
    f32 m_494;
    f32 m_498;
    u8 _pad49C[0x10];
    u32 m_4ac;
    void* m_4b0;
    u8 _pad4B4[0x58];
    u32 m_50c;
    u32 m_510;
    u16 m_514;
    u8 _pad516[0x2];
    s32 m_518;
    s32 m_51c;
    s32 m_520;
    u32 m_524;
    u32 m_528;
    u32 m_52c;
    f32 m_530;
    u8 _pad534[0x30];
    s32 m_564;
    void forward_hit_to_node_list();
    void init_child_node();
    static void release_static_resource();
    static void *create(void *arg0);
    static void load_resources();
    void forward_hit(void* a1);
    void init_child(void* a1);
    void reset_fields();
    void*reset();
    void set_field8_from_obj(s32 arg1);
    void push_list_node(void **arg1, void **arg2);
    void unlink_list_node(void ***arg1, void **arg2);
    static s32 destroy(s32 arg0, s16 arg1);
    static void register_global_objects();
    void clear_flag_and_update();
    s32 check_and_update();
    s32 try_activate();
    s32 get_clamped_level();
    int get_attack_state(void * _w1);
    static void advance_anim_frame();
    void handle_message(s32 msg);
    void state_cast_technique(s32 arg1);
    void run_idle_state(s32 arg1);
    void handle_state(s32 arg1);
    void damage_linked_entity();
    void damage_linked_entity_type10();
    s32 play_sound_variant();
    void set_flag();
    void set_anim_by_state();
    void select_attack_by_range();
    void approach_target(f32 farg0);
    s32 face_target();
    static void pick_wander_destination(void *actor);
    static void turn_toward_angle(void *actor, int angle);
    void forward_hit_to_enemy_list();
    void init_child_from_list();
};

typedef char TObjEneBm5GibonUFadeOffset[offsetof(TObjEneBm5GibonU, fade) == 0x3D8 ? 1 : -1];

typedef char TObjEneBm5GibonU_size[sizeof(TObjEneBm5GibonU) == 0x568 ? 1 : -1];
typedef char TObjEneBm5GibonU_m_3c0[offsetof(TObjEneBm5GibonU, m_3c0) == 0x3C0 ? 1 : -1];
typedef char TObjEneBm5GibonU_m_564[offsetof(TObjEneBm5GibonU, m_564) == 0x564 ? 1 : -1];

extern "C" {
u8 *TObjEneBm5GibonU__ct(u8 *arg0, s32 arg1, s32 arg2);
void TObjEneBm5GibonU__sub_800CCD8C(u8 *arg0);
void TObjEneBm5GibonU__sub_800CCDE4(u8 *arg0);
void TObjEneBm5GibonU__sub_800CCE28(u8 *arg0);
void render__16TObjEneBm5GibonUFv(u8 *arg0);
void TObjEneBm5GibonU__sub_800CE060(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800CE370(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800CE694(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800CE978(u8 *actor, s32 arg1);
void TObjEneBm5GibonU__sub_800CEBD8(u8 *actor, s32 arg1);
void TObjEneBm5GibonU__sub_800CF4BC(u8 *actor, s32 arg1);
void TObjEneBm5GibonU__sub_800CF7CC(u8 *actor, s32 arg1);
void TObjEneBm5GibonU__sub_800CFE30(u8 *_w0, s32 _w1);
void TObjEneBm5GibonU__sub_800CFE34(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800CFFBC(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800D00F0(u8 *actor, s32 arg1);
void TObjEneBm5GibonU__sub_800D01DC(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800D0420(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800D0738(u8 *actor, u32 arg1, s32 msg);
void TObjEneBm5GibonU__sub_800D095C(void *arg0, s32 arg1, s16 arg2);
s32 TObjEneBm5GibonU__sub_800D0968(u8 *arg0, int _w1);
void sub_800D10A0__16TObjEneBm5GibonUFv(u8 *arg0);
void run_task__16TObjEneBm5GibonUFv(u8 *arg0);
s32 TObjEneBm5GibonU__sub_800D1D70(void *p);
void *TObjEneBm5GibonU__sub_800D1D78(void *p);
s32 __dt__16TObjEneBm5GibonUFis(s32 arg0, s16 arg1);
void action__16TObjEneBm5GibonUFPvi(TObjEneBm5GibonU *arg0, s32 arg1);
void calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv(void *arg0, s32 arg1, void *arg2, s32 *arg3);
void forward_hit_to_enemy_list__16TObjEneBm5GibonUFv(s32 arg0);
void init_child_from_list__16TObjEneBm5GibonUFv(s32 arg0);
int is_active__16TObjEneBm5GibonUFPv(void *p);
void update_photon_mylla__16TObjEneBm5GibonUFPv(void *arg0);
void update_target__16TObjEneBm5GibonUFPv(void *arg0);
}

#endif
