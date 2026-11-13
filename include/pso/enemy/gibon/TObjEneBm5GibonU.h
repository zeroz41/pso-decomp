#ifndef PSO_ENEMY_GIBON_TOBJENEBM5GIBONU_H
#define PSO_ENEMY_GIBON_TOBJENEBM5GIBONU_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "dolphin/mtx.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80494938.h"

struct TObjPlayer;

struct TObjEneBm5GibonUMovementParameters {
    f32 range;
    f32 speed;
    s32 turn;
    u32 unknown[4];
};

// A link in one of the Gibbon lists, tagged with its owner's entity id.
struct TObjEneBm5GibonUNode {
    TObjEneBm5GibonUNode *prev;
    TObjEneBm5GibonUNode *next;
    u16 entity_id;
};

struct TObjEneBm5GibonUList {
    TObjEneBm5GibonUNode *head;
    TObjEneBm5GibonUNode *tail;
};

struct TObjEneBm5GibonU : public TObjEneDD_ST {
    virtual ~TObjEneBm5GibonU();
    void sub_800D10A0();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_88();
    virtual void vfunc_105();
    virtual void render_debug();
    void update_center_position();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    s32 m_374;
    s32 m_378;
    f32 m_37c;
    u8 unk_380[0x8];
    s32 m_388;
    u8 unk_38C[0x4];
    TObjPlayer *m_390;
    Vec m_394;
    f32 m_3a0;
    f32 m_3a4;
    f32 m_3a8;
    f32 m_3ac;
    u8 unk_3B0[0x10];
    TObjEneBm5GibonUNode m_3c0;
    TObjEneBm5GibonUNode m_3cc;
    TUnk_80494938 m_3d8;
    RenderFadeState m_3f4[4];
    s32 m_464;
    s32 m_468;
    s32 m_46c;
    s32 m_470;
    u16 m_474;
    u8 _pad476[0x2];
    s32 m_478;
    Vec m_47c;
    Vec m_488;
    f32 m_494;
    f32 m_498;
    f32 m_49c;
    f32 m_4a0;
    f32 m_4a4;
    f32 m_4a8;
    s32 m_4ac;
    s32 m_4b0;
    s16 m_4b4;
    s16 m_4b6;
    u8 unk_4B8[0x54];
    TObjCollidable *m_50c;
    s32 m_510;
    u16 m_514;
    u8 _pad516[0x2];
    s32 m_518;
    s32 m_51c;
    s32 m_520;
    s32 m_524;
    s32 m_528;
    s32 m_52c;
    f32 m_530;
    f32 m_534;
    f32 m_538;
    f32 m_53c;
    Vec m_540;
    Vec m_54c;
    f32 m_558;
    f32 m_55c;
    f32 m_560;
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
    s32 check_hit_sphere(int angle, f32 scale);
    int get_attack_state(void * _w1);
    int spawn_landing_effect(Vec *pos);
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
    void face_target();
    void forward_hit_to_enemy_list();
    void init_child_from_list();
};

typedef char TObjEneBm5GibonU_size[sizeof(TObjEneBm5GibonU) == 0x568 ? 1 : -1];
typedef char TObjEneBm5GibonU_m_3c0[offsetof(TObjEneBm5GibonU, m_3c0) == 0x3C0 ? 1 : -1];
typedef char TObjEneBm5GibonU_m_3d8[offsetof(TObjEneBm5GibonU, m_3d8) == 0x3D8 ? 1 : -1];
typedef char TObjEneBm5GibonU_m_464[offsetof(TObjEneBm5GibonU, m_464) == 0x464 ? 1 : -1];
typedef char TObjEneBm5GibonU_m_564[offsetof(TObjEneBm5GibonU, m_564) == 0x564 ? 1 : -1];

extern "C" {
TObjEneBm5GibonU *TObjEneBm5GibonU__ct(TObjEneBm5GibonU *self, s32 arg1, s32 arg2);
void TObjEneBm5GibonU__sub_800CCD8C(TObjEneBm5GibonU *self);
void TObjEneBm5GibonU__sub_800CCDE4(TObjEneBm5GibonU *self);
void TObjEneBm5GibonU__sub_800CCE28(TObjEneBm5GibonU *self);
void render__16TObjEneBm5GibonUFv(u8 *arg0);
void TObjEneBm5GibonU__sub_800CE060(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800CE370(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800CE694(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800CE978(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800CEBD8(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800CF4BC(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800CF7CC(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800CFE30(TObjEneBm5GibonU *self, s32 _w1);
void TObjEneBm5GibonU__sub_800CFE34(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800CFFBC(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800D00F0(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800D01DC(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800D0420(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800D0738(TObjEneBm5GibonU *self, u32 arg1, s32 msg);
void TObjEneBm5GibonU__sub_800D095C(TObjEneBm5GibonU *self, s32 arg1, s16 arg2);
s32 TObjEneBm5GibonU__sub_800D0968(TObjEneBm5GibonU *self, int _w1);
void run_task__16TObjEneBm5GibonUFv(u8 *arg0);
s32 TObjEneBm5GibonU__sub_800D1D70(TObjEneBm5GibonU *self);
Vec *TObjEneBm5GibonU__sub_800D1D78(TObjEneBm5GibonU *self);
s32 __dt__16TObjEneBm5GibonUFis(s32 arg0, s16 arg1);
void action__16TObjEneBm5GibonUFPvi(TObjEneBm5GibonU *arg0, s32 arg1);
void calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv(TObjEneBm5GibonU *self, s32 angle, Vec *out, s32 *rotation);
int is_active__16TObjEneBm5GibonUFPv(TObjEneBm5GibonU *self);
void *update_photon_mylla__16TObjEneBm5GibonUFPv(TObjEneBm5GibonUNode *node);
s32 update_target__16TObjEneBm5GibonUFPv(TObjEneBm5GibonU *self);
}

#endif
