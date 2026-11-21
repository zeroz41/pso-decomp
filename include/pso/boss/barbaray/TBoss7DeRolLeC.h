#ifndef PSO_BOSS_BARBARAY_TBOSS7DEROLLEC_H
#define PSO_BOSS_BARBARAY_TBOSS7DEROLLEC_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/derolle/TUnk_80036250.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/ControllerInputState.h"
#include <dolphin/mtx.h>

struct AnimationMotion;
struct GinjaTextureList;
struct TBoss7Joint;
class TBoss7Tentacle;
class TBoss7LaserLight;
class AreaAttackHistory;
class TUnk_804F1C58;
class TParticleCtrl;

// Boss parameter block 15 from TLobby::dispatch_shared_handler_a.
struct TBoss7DeRolLeCParams {
    u8 pad_00[0x18];
    s32 unk_18;
    u8 pad_1C[0x4];
    s32 unk_20;
};

struct TBoss7DeRolLeC : public TObjEneDD_ST {
    TBoss7DeRolLeC(TObject *parent, void *set_data);
    virtual ~TBoss7DeRolLeC();
    void update_projectile_spawns();
    virtual void run_task();
    virtual void render();
    virtual void dispatch_action(u32 state, s32 reason);
    void update_or_dispatch();
    void flee_if_disturbed();
    void set_state_and_send(s32);
    static GinjaTextureList *get_archive_textures();
    static NJS_OBJECT *get_archive_model(s32 index);
    void emit_hit_effect(const Vec *position);
    s32 sub_802ECB10();
    void sub_802ECAA4();
    void sub_802EB270(u32 event, s32 mode, s32 next_mode);
    void advance_action_sequence();
    void sub_802E8234();
    void set_flag_800();
    virtual void vfunc_88();
    virtual void render_shadows();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void clear_harmful_statuses();
    void apply_shock_status();
    void apply_movement_ailment(s32);
    void apply_confusion_status();
    void apply_slow_status();
    void apply_paralysis();
    void apply_poison_status();
    void vfunc_28();
    void sync_position_vectors();
    void update_wobble_angle();
    s32 is_all_parts_done();
    u32 update_anim_state();
    u32 update_phase_settling();
    u32 update_tail_anim_state();
    u32 update_phase_rising();
    void turn_on_laser_light();
    void turn_off_laser_light();
    void pick_random_target();
    void sub_802ECC44();
    void sub_802ECBDC();
    void apply_damage_and_set_effect(s32 damage, u16);
    void set_hooked_effect_target();
    void play_sound_at(s32 id, Vec *pos);
    void play_persistent_sound_at(s32 id, Vec *pos);
    void spawn_particle_201(Vec *pos);
    void set_position_index(s32 index);
    void set_swim_direction(s32);
    f32 sub_802ED3E4();
    void destroy_child();
    void update_attached_orientation();
    void handle_death_state(u32 event);
    void sub_802E8AD4(u32 event);
    u8 pad_374[0x8];
    f32 unk_37C;                  // 20.0 (the joints set 3.0)
    u8 pad_380[0xC];
    u16 unk_38C;
    u8 pad_38E[0x32];
    CollisionBody unk_3C0;        // copy of lbl_80473C3C, the body's collision sphere
    Vec unk_3EC[20];
    Vec unk_4DC[4];
    Vec unk_50C[3];               // effect source passed to TObjFish::set_effect_target_position
    Vec unk_530[10];              // joint positions, one per TBoss7Joint in unk_5F8
    s32 unk_5A8[10];              // read by TObjPlayer__sub_802E7EA0
    s32 unk_5D0[10];
    TBoss7Joint *unk_5F8[10];
    TBoss7DeRolLeCParams *unk_620; // TLobby::dispatch_shared_handler_a(15)
    ControllerInputContext *unk_624; // controller_input_state.controllers[1]
    s32 unk_628;                  // state flags (0x4, 0x8, 0x40, 0x80, 0x8000 tested)
    s32 unk_62C;
    TUnk_80036250 motion_x;       // drives position.x (sub_802EB270)
    TUnk_80036250 motion_y;       // drives position.y
    TUnk_80036250 motion_z;       // drives position.z
    TObject unk_690;              // embedded task group: the ctor builds it with TObject(TObject *), run_task/render walk it
    s32 unk_6AC;
    s32 unk_6B0;
    s32 action_index;             // step in lbl_804E3C2C[difficulty][], advanced by advance_action_sequence
    s32 unk_6B8;
    s32 unk_6BC;
    s32 unk_6C0;                  // index into lbl_80472D04 (sub_802EB270: from)
    s32 unk_6C4;                  // index into lbl_80472D04 (sub_802EB270: to)
    s32 unk_6C8;
    s32 unk_6CC;
    s32 unk_6D0;
    GC_Mtx *unk_6D4;                 // 12 matrices, mem_alloc'd by the ctor (freed by the destructor)
    GC_Mtx *unk_6D8;                 // 4 matrices, one per tentacle root (freed by the destructor)
    TBoss7Tentacle *unk_6DC[4];   // released by the destructor
    Vec unk_6EC;
    s32 unk_6F8;
    s32 unk_6FC;
    s32 unk_700;
    s32 unk_704;
    TBoss7LaserLight *unk_708;
    Vec unk_70C;                  // the laser light's position
    AreaAttackHistory *unk_718;
    TObject *unk_71C;
    TObject *unk_720;
    s32 unk_724;
    s32 unk_728;                  // state step (sub_802EB270: 1 = arrived)
    s32 unk_72C;
    s32 unk_730;
    s32 unk_734;
    s32 unk_738;
    s32 unk_73C;
    s32 unk_740;
    f32 unk_744;
    f32 unk_748;
    f32 unk_74C;
    f32 unk_750;
    f32 unk_754;
    f32 unk_758;
    f32 unk_75C;
    f32 unk_760;
    f32 unk_764;
    f32 unk_768;
    f32 unk_76C;
    f32 unk_770;
    f32 unk_774;
    f32 unk_778;
    f32 unk_77C;
    f32 unk_780;
    TObject *unk_784;             // released by the destructor
    TObject *unk_788[6];          // released by the destructor
    s32 unk_7A0;
    TObject *crawfish_parent;     // the group spawned crawfish are children of
    s32 unk_7A8;
    TUnk_804F1C58 *unk_7AC;
    TParticleCtrl *unk_7B0;       // destroy_child releases it, update_attached_orientation aims it
    Vec unk_7B4;                  // where unk_7B0 sits
    Vec unk_7C0;                  // the point unk_7B0 is aimed away from
    u16 unk_7CC;
    u16 unk_7CE;
    u16 unk_7D0;
    u16 unk_7D2;
    static void run_exit_callbacks();
    static void *create(void *arg0);
};

LAYOUT_ASSERT(TBoss7DeRolLeC_size, sizeof(TBoss7DeRolLeC) == 0x7D4);

// Light pool element (0x38 bytes): TObjPlayer__sub_802EE574 initialises 11 of them as a linked free list.
struct Light_802EE574 {
    s32 type;
    s32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    Light_802EE574 *next;
    s32 f30;
    u8 pad34[4];
};

// Globals of the De Rol Le C translation unit (802E7888-802EE814; .sbss/.bss).
extern "C" {
extern Light_802EE574 boss7_derolle_light_pool[11];

void TObjPlayer__sub_802ED984(void);
void TObjPlayer__sub_802EE574(void);
}

// Functions defined in TBoss7DeRolLeC.cpp.
struct TObjEneDD;
extern "C" {
void TBoss7DeRolLeC__handle_crawfish_spawn_state(u8 *self, u32 event, s32 variant);
void TBoss7DeRolLeC__sub_802EC994(void *p);
}
s32 TBoss7Joint_get_shell_max_hp(void);
extern "C" {
void TBoss7LaserPtcl__sub_802E8FCC(u8 *arg0, u32 arg1);
void TBoss7LaserPtcl__sub_802ECE28(u8 *arg0);
void TBoss7PhotonBullet__sub_802ED5A0(void *arg0, int arg1);
void TObjFish__sub_802E8528(void *o, u32 k);
void TObjFish__sub_802E8584(void *o, u32 k);
void TObjFish__sub_802E85E0(u8 *arg0, u32 arg1, s32 arg2);
void TObjFish__sub_802E88F8(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8990(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8E34(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8EEC(u8 *arg0, u32 arg1, s32 _w2);
void TObjFish__sub_802E9458(u8 *arg0, u32 arg1);
void TObjFish__sub_802E95F8(u8 *arg0, u32 arg1, s32 arg2);
void TObjFish__sub_802E9DBC(u8 *arg0, u32 arg1, s32 arg2);
void TObjFish__sub_802EA4D8(u8 *arg0, u32 arg1);
void TObjFish__sub_802EAAC8(u8 *arg0, u32 arg1, s32 arg2, s32 arg3);
void TObjFish__sub_802EBBC8(u8 *arg0, u32 arg1);
void TObjFish__sub_802EBE50(void *o, u32 k);
void TObjFish__sub_802EC32C(TBoss7DeRolLeC *self);
void TObjFish__sub_802EC468(saddr arg0, f32 farg0, f32 farg1);
void TObjPlayer__sub_802E7F30(void *unused, s32 arg1);
void render__14TBoss7DeRolLeCFv(u8 *unused);
void TObjPlayer__sub_802E8274(NJS_OBJECT *);
void fn_802EC52C(s32 arg0, saddr arg1);
void fn_802EC9A4(void *arg0, void *arg1);
void fn_802EC9F0(TObjEneDD *arg0, void *arg1);
}
void handle_6xA9_barba_ray_boss_actions(void *arg0);
void handle_6xAA_barba_ray_boss_actions(void *arg0);
extern "C" {
AnimationMotion *get_boss7_motion(s32 kind);
}

#endif
