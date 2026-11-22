#define TOBJECT_OUT_OF_LINE_HELPERS

#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/camera/TCameraCtrl.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/dd/TObjEneDD_800BB804.h"


#include "pso/unk/text_803D96A8.h"

#include "pso/unk/text_803E2D70.h"

#include "pso/system/vector.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/enemy/recon/TObjEneRecobox.h"

#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/render/reflection.h"

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/enemy/dd/TObjEneDD.h"

#include "pso/enemy/berura/TObjEneRe7Berura.h"

#include "pso/render/RenderFadeState.h"

#include "pso/object/ambient/TObjFish.h"

#include "pso/player/TObjPlayer.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/player/TObjPlayer_80011014.h"

#include "pso/system/MatrixOps.h"

#include "pso/unk/text_803D853C.h"

#include "pso/system/task/TObject.h"

#include "pso/map/CsnQuery.h"

#include "pso/object/TObjChip.h"

#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"

#include "pso/system/task/TMainTask.h"


#include "pso/system/task/TObject_80019A50.h"



#include "pso/render/TUnk_80494938.h"

#include "pso/enemy/dd/TObjEneDD_ST.h"

#include "pso/object/base/TObjChara.h"

#include "pso/map/FloorArea.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"

#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"

#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/unk/TLobby.h"

#include "pso/system/SoundEffect.h"

#include "pso/math/AngleLookup.h"


#include "pso/ui/window/TWindowSubComCard.h"

struct FadeBase_8031EA70 { char pad[0x14]; };

struct Fade_8031EA70 : FadeBase_8031EA70 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8();
    u8 pad18[4];
};

struct Holder_8031EA70 { u8 pad[0x460]; Fade_8031EA70 arr[4]; };

extern "C" {



s32 post_translate_matrix(void *);

extern saddr debug_chunk_object;


extern s32 saved_model_render_flags;

extern s32 saved_chunk_polygon_flags_and_mask;

extern s32 saved_chunk_polygon_flags_or_mask;

extern s32 chunk_polygon_flags_or_mask;

extern s32 chunk_polygon_flags_and_mask;

extern s32 model_render_flags;

extern const f32 lbl_805D9E84;

extern const f32 lbl_805D9E88;

}

struct Stack_8031EE54 {
    s32 sp8;
    f32 spC;
};

struct T_8031EDBC { u8 pad[0x424]; u16 ids[30]; };

struct Rec_8031EDF8
{
  u8 pad0[0x1C];
  u16 base;
  u8 pad1[0x3F4 - 0x1E];
  s32 count;
  u8 pad2[0x424 - 0x3F8];
  u16 ids[1];
};

extern s32 actor_frame_tick;

typedef struct Rec_8031EDF8 Rec_8031EDF8;

struct Obj_8031EF14 { u8 pad[0x410]; s32 count; u8 pad2[4]; u16 ids[6]; };

struct Obj_8031F0F0 { u8 pad[0x410]; s32 count; u8 pad2[4]; u16 ids[6]; };

struct Obj_8031EFAC { u8 pad[0x410]; s32 count; s32 f414; u16 ids[6]; };

struct Obj_8031F070 { u8 pad[0x410]; s32 count; u8 pad2[4]; u16 ids[6]; };

extern "C" {


u16 TObjEneRecon__sub_8031D878();

void remove_tracked_target__14TObjEneRecoboxFPvPv(Obj_8031EFAC *o, u8 *target);

s32 is_anim_5__12TObjEneReconFv();





s32 is_out_of_range__14TObjEneRecoboxFv();

}

struct Base_8031F600 { char pad[0x18]; };

struct VObj_8031F600 : Base_8031F600 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(); virtual void m94(s32);
    virtual void m95(); virtual void m96(); virtual void m97();
    virtual void m98(); virtual void m99(); virtual void m100(); virtual void m101();
    virtual s32 m102(f32);
};

extern "C" {

struct Obj_8031FACC;

s32 TObjEneRecon__sub_8031FACC(Obj_8031FACC *ene_dd);

}

struct Base_8031F6C0 { char pad[0x18]; };

struct VObj_8031F6C0 : Base_8031F6C0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(s32);
};

#define CAT(a, b) CAT2(a, b)
#define CAT2(a, b) a##b
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();

struct Base_Sub_8031f748 { char pad[0x14]; };

struct V_Sub_8031f748 : Base_Sub_8031f748 {
    PADV4
    PADV
    virtual s32 m5();
};

struct Recon_8031F8C4 {
    u8 pad0[0x1C];
    u16 f1C;
    u8 pad1E[2];
    u8 pad20[0x2C - 0x20];
    s16 f2C;
    u8 pad2E[0x38 - 0x2E];
    u8 pos38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x3DC - 0x64];
    s32 f3DC;
    u8 pad3E0[0x3F4 - 0x3E0];
    s32 f3F4;
    s32 f3F8;
    u8 pad3FC[0x410 - 0x3FC];
    s32 f410;
    s32 f414;
    u16 ids[(0x4D8 - 0x418) / 2];
    s32 f4D8;
    s32 f4DC;
};

extern "C" {

u32 create__12TObjEneReconFPvPvPvPvPv(void *, u16, s32, Vec *, Vec *);


s32 remap_area_sound_id__14TObjEneRecoboxFUl(s32, s32, s32);



}

struct Stack_8031FB6C {
    s32 sp8;
    f32 spC;
};

struct Obj_8031FACC { u8 pad[0x3F4]; s32 f3F4; s32 f3F8; u8 pad2[0x410 - 0x3FC]; s32 f410; s32 f414; };


extern "C" void has_flag_0x800__9TObjCharaFv();

extern "C" void test_flag30_512__9TObjCharaFv();

extern "C" void test_flag_1000__9TObjCharaFv();

extern "C" void test_flag_256__9TObjCharaFv();

extern "C" {

struct Obj_8031FE14 { u8 pad[0x18]; void *vt; };

struct VBase_18_b2458f { char pad[0x18]; };

struct VObj_18_b2458f : VBase_18_b2458f {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual s32 m85(s16, s32);
    virtual s32 m86();
};

struct Sub_8031FE98 { u8 b[0x1C]; };

struct Self_8031FE98 { u8 pad[0x3FC]; s32 f3fc[4]; u8 pad40c[0x418 - 0x40C]; u16 f418[6]; u16 f424[30]; Sub_8031FE98 subs[4]; };

void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);

void __ct__12TObjEneDD_STFP7TObject(void *, s32, void *);


void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);

void *__dt__15RenderFadeStateFv(void *arg0, s16 arg1);

void __ct__15RenderFadeStateFv();

void free_collision_body_parts(void *);


void TObjEneRecon__sub_8031F408(void *arg0, s32 arg1);

void TObjEneRecon__sub_8031F600(void *arg0, s32 arg1);

void dispatch_state__14TObjEneRecoboxFiUii(saddr arg0, u32 arg1, s32 arg2);

void run_task__14TObjEneRecoboxFv(u8 *arg0);

Obj_8031FE14 * fn_8031FE14(Obj_8031FE14 *arg0, s16 arg1);

void __destroy_arr(void *, void *, int, int);

void __construct_array(void *, void *, void *, int, int);

saddr recobox_boss_register_id;

saddr lbl_805D6B14;

saddr TObjEneRecobox__shared_object_handle;

extern "C" void vfunc_6__8TObjBaseFPsl();

extern "C" void snap_to_ground_at__9TObjEneDDFPUc();

extern "C" void apply_enemy_state__9TObjEneDDFPl();

extern "C" void update_immobilizing_statuses__9TObjEneDDFv();

extern "C" void update_action_state__9TObjEneDDFv();

extern "C" void has_action_state_changed__9TObjEneDDFv();

extern "C" void check_collisions__9TObjEneDDFv();

extern "C" void vfunc_90__9TObjEneDDFv();

extern "C" void set_invulnerable__9TObjEneDDFv();

extern "C" void clear_invulnerable__9TObjEneDDFv();

extern "C" void enable_body_collision__9TObjEneDDFv();

extern "C" void disable_body_collision__9TObjEneDDFv();

extern "C" void set_intangible__9TObjEneDDFv();

extern "C" void clear_intangible__9TObjEneDDFv();

extern "C" void set_colliders_contact_high__9TObjEneDDFv();

extern "C" void set_colliders_contact_low__9TObjEneDDFv();

extern "C" void is_confused__9TObjEneDDFv();

extern "C" void render_minimap_dot__9TObjEneDDFv();

extern "C" void move_xz_on_ground__9TObjEneDDFPUc();

extern "C" void update_ground_contact__9TObjEneDDFv();

extern "C" int acquire_target__12TObjEneDD_STFf(void *p);

extern "C" void update_status_effects__12TObjEneDD_STFv();

extern "C" void draw_with_debug_info__14TObjEneRecoboxFv();

extern "C" void render__14TObjEneRecoboxFv(u8 *arg0);

extern "C" void TObjEneRecon__sub_8031FB6C(u8 *arg0);

extern "C" void run_miss_reaction__14TObjEneRecoboxFv();

extern "C" void run_hit_reaction__14TObjEneRecoboxFv();

extern "C" void refresh_target__14TObjEneRecoboxFv();

extern "C" void has_no_target__9TObjCharaFv();

extern "C" void recalc_stats__9TObjCharaFv();

extern "C" void consume_timer_field__9TObjCharaFl();

extern "C" void deliver_attack_hits__9TObjCharaFf();

extern "C" void vfunc_66__9TObjCharaFv();

extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();

extern "C" void run_attack_action__9TObjCharaFv();

extern "C" void run_move_action__9TObjCharaFv();

extern "C" void run_idle_action__9TObjCharaFv();

extern "C" void apply_slow_status__9TObjCharaFv();

extern "C" void update_shock_clock__9TObjCharaFv();

extern "C" void vfunc_43__9TObjCharaFv();

extern "C" void update_actor_ground_y_at__9TObjCharaFP3Vec();

extern "C" void interact__14TObjCollidableFl();

extern "C" void vfunc_74__9TObjEnemyFl();

extern "C" void apply_hit_message_flags__9TObjEnemyFPv();

extern "C" void add_actor_exp__9TObjCharaFl();

extern "C" void apply_action_hold_status__9TObjCharaFf();

extern "C" void apply_anti_technique__9TObjCharaFl();

extern "C" void apply_attack_stat_status__9TObjCharaFPv();

extern "C" void apply_confusion_status__9TObjCharaFv();

extern "C" void apply_knockback_from_attacker__9TObjCharaFPUcf();

extern "C" void apply_movement_ailment__9TObjCharaFl();

extern "C" void apply_object_set_data__8TObjBaseFPv();

extern "C" void apply_paralysis__9TObjCharaFv();

extern "C" void apply_poison_status__9TObjCharaFv();

extern "C" void apply_set_data__9TObjEnemyFPv();

extern "C" void apply_shock_status__9TObjCharaFv();

extern "C" void apply_switch_attack__9TObjCharaFv();

extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();

extern "C" void classify_actor_view_detail__8TObjBaseFfff();

extern "C" void clear_all_status_effects__9TObjCharaFv();

extern "C" void clear_harmful_statuses__9TObjCharaFv();

extern "C" void cure_paralysis__9TObjCharaFv();

extern "C" void cure_poison_ailment__9TObjCharaFv();

extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();

extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();

extern "C" void vfunc_78__9TObjCharaFl();

extern "C" void gain_photon_blast_chain_charge__9TObjCharaFv();

extern "C" void spend_photon_blast_charge__9TObjCharaFf();

extern "C" void gain_photon_blast_charge__9TObjCharaFf();

extern "C" void clear_lobby_object_state__9TObjEnemyFv();

extern "C" void get_center__9TObjCharaFv();

extern "C" void get_actor_level_index__9TObjCharaFv();

extern "C" void get_name__9TObjEnemyFv();

extern "C" void get_pos__9TObjCharaFl();

extern "C" void is_actor_cadence_frame__9TObjCharaFl();

extern "C" void is_target_in_attack_range__9TObjCharaFv();

extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();

extern "C" void receive_physical_attack__9TObjCharaFPvf();

extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();

extern "C" void apply_defense_stat_status__9TObjCharaFPv();

extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);

extern "C" void reset_motion_fields__9TObjCharaFv();

extern "C" void reset_pose__9TObjCharaFv();

extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();

extern "C" void select_melee_contact_body__9TObjCharaFPvf();

extern "C" void run_death_reaction__14TObjEneRecoboxFv();

extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);

extern "C" void try_start_action__9TObjCharaFll();

extern "C" void update_action_hold_status__9TObjCharaFv();

extern "C" s32 update_slow_status__9TObjCharaFv(u8 *arg0);

extern "C" void update_actor_ground_y__9TObjCharaFv();

extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);

extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);

extern "C" void update_flag30_timer__9TObjCharaFv();

extern "C" void update_if_800BB858__14TObjEneRecoboxFv();

extern "C" void update_movement_status__9TObjCharaFv();

extern "C" void update_object_view_visibility__8TObjBaseFff();

extern "C" void update_poison_status__9TObjCharaFv();

void *TObjEneRecobox__attack_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};

void *lbl_804EC684[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};

const char *lbl_804EC6B0[7] = {
    "me7_all.nj", "me7_box_all.nj", "bomb_body.nj", "b_parts_b_parts01.gj",
    "b_parts_b_parts02.gj", "b_parts_b_parts03.gj", NULL,
};

const char *recobox_motion_name_table[11] = {
    "close_me7_box_all.njm", "close_only_me7_box_all.njm", "open_me7_box_all.njm", "open_only_me7_box_all.njm",
    "attack_me7_all.njm", "b_attack_me7_all.njm", "damage_me7_all.njm", "dethpose_me7_all.njm",
    "start_me7_all.njm", "wait_me7_all.njm", NULL,
};

BmlResourceDescriptor lbl_804EC6F8 = {
    "bm_ene_recobox.bml", lbl_804EC6B0, recobox_motion_name_table, 6, 10,
};

const char *lbl_804EC708[7] = {
    "lo_me7_all.nj", "lo_me7_box_all.nj", "bomb_body.nj", "b_parts_b_parts01.gj",
    "b_parts_b_parts02.gj", "b_parts_b_parts03.gj", NULL,
};

const char *TObjEneRecobox__resource_bundle[11] = {
    "close_me7_box_all.njm", "close_only_me7_box_all.njm", "open_me7_box_all.njm", "open_only_me7_box_all.njm",
    "attack_me7_all.njm", "b_attack_me7_all.njm", "damage_me7_all.njm", "dethpose_me7_all.njm",
    "start_me7_all.njm", "wait_me7_all.njm", NULL,
};

BmlResourceDescriptor lbl_804EC750 = {
    "bm_ene_recobox_low.bml", lbl_804EC708, TObjEneRecobox__resource_bundle, 6, 10,
};

const char *TObjEneRecobox_name_ref = "TObjEneRecobox";

TObjMotionAction TObjEneRecobox__animation_entries[4] = {
    {1, 0, 1, 0.1f, 0},
    {3, 0, 2, 0.6f, 0},
    {1, 0, 3, 0.1f, 0},
    {3, 0, 0, 0.6f, 0},
};

void *TObjEneRecobox__vtable[107] = {
    (void *)0x0, (void *)0x0, (void *)&fn_8031FE14, (void *)&run_task__14TObjEneRecoboxFv,
    (void *)&render__14TObjEneRecoboxFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&update_actor_ground_y_at__9TObjCharaFP3Vec, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&refresh_target__14TObjEneRecoboxFv, (void *)&has_no_target__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&update_slow_status__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&run_idle_action__9TObjCharaFv, (void *)&run_move_action__9TObjCharaFv,
    (void *)&run_attack_action__9TObjCharaFv, (void *)&run_miss_reaction__14TObjEneRecoboxFv, (void *)&run_hit_reaction__14TObjEneRecoboxFv, (void *)&run_death_reaction__14TObjEneRecoboxFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&deliver_attack_hits__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&gain_photon_blast_charge__9TObjCharaFf,
    (void *)&spend_photon_blast_charge__9TObjCharaFf, (void *)&gain_photon_blast_chain_charge__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&apply_enemy_state__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&update_status_effects__12TObjEneDD_STFv,
    (void *)&update_immobilizing_statuses__9TObjEneDDFv, (void *)&update_action_state__9TObjEneDDFv, (void *)&has_action_state_changed__9TObjEneDDFv, (void *)&dispatch_state__14TObjEneRecoboxFiUii,
    (void *)&TObjEneRecon__sub_8031FB6C, (void *)&check_collisions__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&set_invulnerable__9TObjEneDDFv,
    (void *)&clear_invulnerable__9TObjEneDDFv, (void *)&enable_body_collision__9TObjEneDDFv, (void *)&disable_body_collision__9TObjEneDDFv, (void *)&set_intangible__9TObjEneDDFv,
    (void *)&clear_intangible__9TObjEneDDFv, (void *)&set_colliders_contact_high__9TObjEneDDFv, (void *)&set_colliders_contact_low__9TObjEneDDFv, (void *)&is_confused__9TObjEneDDFv,
    (void *)&render_minimap_dot__9TObjEneDDFv, (void *)&move_xz_on_ground__9TObjEneDDFPUc, (void *)&update_ground_contact__9TObjEneDDFv, (void *)&snap_to_ground_at__9TObjEneDDFPUc,
    (void *)&acquire_target__12TObjEneDD_STFf, (void *)&update_if_800BB858__14TObjEneRecoboxFv, (void *)&draw_with_debug_info__14TObjEneRecoboxFv,
};

#define TObjEneRecobox__attack_params ((u8 *)TObjEneRecobox__attack_params)
#define TObjEneRecobox__vtable ((u8 *)TObjEneRecobox__vtable)



// inferred: field names follow MojaAnimationBinding (TObjEneMoja.h), the same 0x10 animation binding layout.

struct Inner_80320260 { u8 pad[0x18]; s32 f18; NJS_TEXLIST *texlist; };

struct Box_80320260 { u8 pad[0x42C]; Inner_80320260 *f42C; s32 f430; };

struct Sub_80320260 { u8 pad[0xC]; f32 f0C; };






Vec lbl_80543000;

s32 lbl_805D6B1C;

BmlResource *TObjEneRecobox__static_instance;

const NpcAnimationBinding recobox_resource_binding_desc = { NULL, TObjEneRecobox__animation_entries, 0, 0, 4 };

#pragma dont_inline off
#pragma inline_depth(4)
static inline f32 getf_80320260(Sub_80320260 *p) { return p->f0C; }
void TObjEneRecobox::load_resources() {
    Box_80320260 *box;

    lbl_80543000.x = 0.0f;
    lbl_80543000.y = 0.0f;
    lbl_80543000.z = 0.0f;
    {
        u32 res;
        if (is_split_screen() != 0) {
            res = (uaddr)load_enemy_bml_resource(&lbl_804EC750);
        } else {
            res = (uaddr)load_enemy_bml_resource(&lbl_804EC6F8);
        }
        (*(u32 *)&TObjEneRecobox__static_instance) = res;
    }
    recobox_boss_register_id = (saddr)TLobby::register_boss(0x41);
    lbl_805D6B14 = (saddr)TLobby::dispatch_shared_handler_b(0x41);
    TObjEneRecobox__shared_object_handle = (saddr)TLobby::register_object(0x41);
    lbl_805D6B1C = (saddr)TLobby::dispatch_shared_handler_a(0x41);
    TObjEneRecon::load_resources();
    {
        Sub_80320260 *sp = (Sub_80320260 *)lbl_804EC684;
        NpcAnimationBinding s = recobox_resource_binding_desc;
        box = (Box_80320260 *)(*(uaddr *)&TObjEneRecobox__static_instance);
        s.motions = reinterpret_cast<BmlMotionEntry *>(box->f430);
        NpcModelRegistry::register_animated_chunk((s16)0xD, reinterpret_cast<void *>(box->f42C->f18), reinterpret_cast<void *>(box->f42C->texlist), &s, (f32)(getf_80320260(sp)), 0.0f);
    }
}

u8 *TObjEneRecobox__ct(u8 *ene_recobox, s32 arg1, u8 *arg2);

void *TObjEneRecobox::create(void *set_data) {
    void *o = TObject::operator new(0x4F4);
    if (o != NULL) {
        o = TObjEneRecobox__ct((u8 *)o, (saddr)tl_04, (u8 *)set_data);
    }
    return o;
}

void TObjEneRecobox::release_static_instance() {
    TObjEneRecon::release_static_instance();
    if ((u32) (*(u32 *)&TObjEneRecobox__static_instance) != 0U) {
        delete (BmlResource *)(*(uaddr *)&TObjEneRecobox__static_instance);
        (*(u32 *)&TObjEneRecobox__static_instance) = 0U;
    }
}

BmlResource *TObjEneRecobox::get_bml_resource() { return TObjEneRecobox__static_instance; }

u32 TObjEneRecobox::remap_area_sound_id(u32 arg0) {
    u32 ret;
    if (((s32)(arg0 & 0xBFFF00FF) >> 16 << 16) != 0x30000) {
        return arg0;
    }
    ret = get_current_floor_area();
    switch (ret) {
    case 0x22:
        ret = arg0 - 0x40010000 + 0x4E19;
        break;
    case 0x23:
        ret = arg0 - 0x40010000 + 0x4E28;
        break;
    default:
        return arg0;
    }
    ret |= arg0 & 0x8FFFFF00;
    return ret;
}

u8 *TObjEneRecobox__ct(u8 *ene_recobox, s32 arg1, u8 *set_data) {
    Self_8031FE98 *S = (Self_8031FE98 *)ene_recobox;
    s32 i;
    s32 n;
    __ct__12TObjEneDD_STFP7TObject(ene_recobox, arg1, set_data);
    *(u8 **)((s8 *)ene_recobox + 0x18) = TObjEneRecobox__vtable;
    __ct__13TUnk_80494938Fv((ene_recobox + 0x3C0));
    __construct_array(ene_recobox + 0x460, (void *)&__ct__15RenderFadeStateFv, (void *)&__dt__15RenderFadeStateFv, 0x1C, 4);
    ((TObject *)ene_recobox)->m_name = TObjEneRecobox_name_ref;
    ((TObjEneDD *)ene_recobox)->invoke_initialization_hook(set_data);
    ((TObjEneDD *)ene_recobox)->init_position_vectors();
    *(s32 *)((s8 *)ene_recobox + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneRecobox__static_instance + 0x42C)) + 0x18);
    ((TObjEneRecobox *)ene_recobox)->texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneRecobox__static_instance + 0x42C)) + 0x1C);
    ((TObjEneDD *)ene_recobox)->init_model((CollisionBody *)lbl_804EC684, (s32)1);
    ((TObjEneRecobox *)ene_recobox)->body_center.y = 20.0f + *(f32 *)((s8 *)ene_recobox + 0x3C);
    ((TObjEneRecobox *)ene_recobox)->update_body_colliders();
    ((TObjMotion *)ene_recobox)->set_field_d8((saddr)TObjEneRecobox__animation_entries);
    ((TObjMotion *)ene_recobox)->set_field_dc(*(s32 *)((s8 *)TObjEneRecobox__static_instance + 0x430));
    ((TObjEneRecobox *)ene_recobox)->requested_action = 0;
    ((TObjMotion *)ene_recobox)->set_animation(((TObjEneRecobox *)ene_recobox)->requested_action);
    ((TObjMotion *)ene_recobox)->set_field_b8(((TObjEneRecobox *)ene_recobox)->requested_action);
    ((TObjEneDD *)ene_recobox)->reset_hp((u8 *)recobox_boss_register_id, (u8 *)lbl_805D6B14, (u8 *)TObjEneRecobox__shared_object_handle);
    ((TObjEneDD *)ene_recobox)->set_state_flag_4();
    *(u8 * *)&((TObjEneRecobox *)ene_recobox)->movementParameters = TObjEneRecobox__attack_params;
    ((TObjEneDD *)ene_recobox)->initialize_enemy_state(0x43);
    ((TObjEneRecobox *)ene_recobox)->wall_reach = 10.0f;
    ((TObjEneRecobox *)ene_recobox)->sub_8031F800();
    n = *(s16 *)((s8 *)set_data + 2);
    if (n <= 1) {
        *(s32 *)&((TObjEneRecobox *)ene_recobox)->recon_total = 0;
    } else if (*(s32 *)&((TObjEneRecobox *)ene_recobox)->recon_total >= n) {
        *(s32 *)&((TObjEneRecobox *)ene_recobox)->recon_total = n - 1;
    }
    if (*(s32 *)&((TObjEneRecobox *)ene_recobox)->recon_max > *(s32 *)&((TObjEneRecobox *)ene_recobox)->recon_total) {
        *(s32 *)&((TObjEneRecobox *)ene_recobox)->recon_max = *(s32 *)&((TObjEneRecobox *)ene_recobox)->recon_total;
    }
    for (i = 0; i < 4; i++) {
        S->f3fc[i] = 0;
    }
    *(s32 *)((s8 *)ene_recobox + 0x40C) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x40C) |= 1;
    ((TUnk_80494938 *)(ene_recobox + 0x3C0))->start_fade_in();
    *(s32 *)((s8 *)ene_recobox + 0x410) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x414) = 0;
    for (i = 0; i < 30; i++) {
        S->f424[i] = 0xFFFF;
    }
    for (i = 0; i < 6; i++) {
        S->f418[i] = 0xFFFF;
    }
    for (i = 0; i < 4; i++) {
        ((RenderFadeState *)(&S->subs[i]))->activate_and_dispatch();
    }
    ((TObjEneRecobox *)ene_recobox)->spawn_timer = 0;
    ((TObjEneRecobox *)ene_recobox)->spawn_interval = 0;
    *(s32 *)((s8 *)ene_recobox + 0x3E0) = 0;
    VecCopy((Vec *)(ene_recobox + 0x3E4), (const Vec *)(ene_recobox + 0x38));
    *(s32 *)((s8 *)ene_recobox + 0x4E0) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x4E4) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x4E8) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x4EC) = 0;
    ((TObjEneRecobox *)ene_recobox)->m_4f0 = 0.0f;
    ((TObjEneRecobox *)ene_recobox)->mode = 0;
    ((VObj_18_b2458f *)ene_recobox)->m85(((TObjEneRecobox *)ene_recobox)->mode, 4);
    return ene_recobox;
}

Obj_8031FE14 *fn_8031FE14(Obj_8031FE14 *arg0, s16 arg1) {
    if (arg0 != 0) {
        arg0->vt = TObjEneRecobox__vtable;
        free_collision_body_parts(arg0);
        __destroy_arr((u8 *)arg0 + 0x460, ((u8 *)__dt__15RenderFadeStateFv), 0x1C, 4);
        __dt__13TUnk_80494938Fv((u8 *)arg0 + 0x3C0, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

void TObjEneRecobox::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->update_if_800BB858();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
    } else if ((s16) this->mode == 1) {
        transition_enemy_state(0);
    }
    this->update_body_colliders();
    this->restore_position();
    this->submit_default_cursor_candidate();
    this->render_minimap_dot();
    this->update_floor_probe();
}

void dispatch_state__14TObjEneRecoboxFiUii(saddr ene_dd, u32 arg1, s32 reason) {
    switch (arg1) {
    case 0:
        ((TObjEneRecobox *)ene_dd)->sub_8031F6C0(reason);
        return;
    case 1:
        ((TObjEneRecobox *)ene_dd)->handle_state(reason);
        return;
    case 2:
        TObjEneRecon__sub_8031F600((void *)ene_dd, (reason));
        return;
    case 3:
        ((TObjEneRecobox *)ene_dd)->update_state(reason);
        return;
    case 4:
        ((TObjEneRecobox *)ene_dd)->handle_action_state(reason);
        return;
    case 5:
        TObjEneRecon__sub_8031F408((void *)ene_dd, (reason));
        return;
    case 6:
        ((TObjEneRecobox *)ene_dd)->handle_death_state(reason);
    default:
        return;
    }
}

}

void TObjEneRecobox::refresh_target() {  }

void TObjEneRecobox::run_death_reaction() { if (this->mode != 6) { transition_enemy_state(6); } }

void TObjEneRecobox::run_hit_reaction() { clear_attack_receipts(); }

void TObjEneRecobox::run_miss_reaction() {  }

void TObjEneRecobox::restore_position() { VecCopy((Vec *)((char*)this + 0x74), (const Vec *)((char*)this + 0x2fc)); }


void TObjEneRecon__sub_8031FB6C(u8 *ene_recobox) {
    Stack_8031FB6C stack;
    u8 *temp_r3;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(ene_recobox + 0x2FC));
    if ((s32) ((TObjEneRecobox *)ene_recobox)->mount_type == 1) {
        stack.spC -= 5.0f;
    } else {
        stack.spC += 5.0f;
    }
    temp_r3 = (u8 *)(csnVectorUnder((Vec *)&stack.sp8, (CsnGroup **)(ene_recobox + 0x120), 0x15));
    if ((temp_r3 == NULL) || (((TObjEneRecobox *)ene_recobox)->body_center.y >= (40.0f + *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 4)))) {
        ((TObjEneRecobox *)(ene_recobox))->set_colliders_contact_high();
    }
    ((TObjEneDD *)ene_recobox)->set_part_local_pos(ene_recobox + 0x2FC, 0);
}

s32 TObjEneRecon__sub_8031FACC(Obj_8031FACC *ene_dd) {
    u8 r;
    s32 t;
    if (((TObjEneRecobox *)ene_dd)->has_child_in_anim_5() == 1) {
        return 0;
    }
    t = (s32)TWindowSubComCard::trunc_float(ene_dd->f3F8 / 2.0f);
    r = 0;
    if (ene_dd->f410 <= t && ene_dd->f414 < ene_dd->f3F4) {
        r = 1;
    }
    return r;
}

u8 TObjEneRecobox::is_out_of_range() {
    int var_r4;

    if (has_child_in_anim_5() == 1) {
        return 1;
    }
    var_r4 = 0;
    if (((s32) *(s32 *)((s8 *)this + 0x410) >= (s32) *(s32 *)((s8 *)this + 0x3F8)) || ((s32) *(s32 *)((s8 *)this + 0x414) >= (s32) *(s32 *)((s8 *)this + 0x3F4))) {
        var_r4 = 1;
    }
    return (u8) var_r4;
}

void TObjEneRecobox::update_child_spawn() {
    Recon_8031F8C4 *o = (Recon_8031F8C4 *)this;
    Vec dir = {0.0f, 0.0f, 0.0f};
    Vec pos;
    s32 id;
    s32 arg;
    s32 n;
    o->f4D8++;
    if (o->f4D8 < o->f4DC) {
        return;
    }
    o->f4D8 = 0;
    if (o->f410 >= o->f3F8 || o->f414 >= o->f3F4) {
        return;
    }
    switch (o->f3DC) {
    case 0:
        dir.y = 5.0f;
        break;
    case 1:
        dir.y = -5.0f;
        break;
    case 2:
        dir.x = 2.0f * sin_table_lookup(o->f60);
        dir.z = 2.0f * cos_table_lookup(o->f60);
        break;
    }
    id = ((TObjEneRecobox *)o)->alloc_child_id();
    arg = o->f2C + (id - o->f1C);
    VecCopy((Vec *)&pos, (const Vec *)(((TObjEneRecon *)o)->get_field_38_ptr()));
    if (id == 0xFFFF) {
        o->f414 = o->f3F4;
        return;
    }
    if (create__12TObjEneReconFPvPvPvPvPv(o, id, arg, &pos, &dir) != 0) {
        n = o->f410++;
        o->ids[n] = id;
        play_sound_effect(remap_area_sound_id__14TObjEneRecoboxFUl(0x4003A80F, o->f414++, n), o->pos38, 0, 0);
    }
}

#pragma push
#pragma opt_common_subs off
void TObjEneRecobox::sub_8031F800() {
    u8 *self = (u8 *)this;
    s32 temp_r0;
    *(s32 *)&this->mount_type = (s32) *(s32 *)&this->variant;
    if ((s32) *(s32 *)&this->mount_type <= 0) {
        *(s32 *)&this->mount_type = 0;
    } else if ((s32) *(s32 *)&this->variant >= 2) {
        *(s32 *)&this->mount_type = 2;
    }
    *(f32 *)&this->m_4d0 = (f32) *(f32 *)((s8 *)self + 0x354);
    *(f32 *)((s8 *)self + 0x4D4) = (f32) *(f32 *)((s8 *)self + 0x358);
    if (*(f32 *)((s8 *)self + 0x4D4) <= -30.0f) {
        *(f32 *)((s8 *)self + 0x4D4) = -30.0f;
    }
    *(s32 *)&this->recon_max = (s32) *(f32 *)((s8 *)self + 0x360);
    temp_r0 = *(s32 *)&this->recon_max;
    if (temp_r0 < 0) {
        *(s32 *)&this->recon_max = 0;
    } else if (temp_r0 > 6) {
        *(s32 *)&this->recon_max = 6;
    }
    if ((s32) *(s32 *)&this->recon_max == 0) {
        *(s32 *)&this->recon_total = 0;
        return;
    }
    *(s32 *)&this->recon_total = 0x1E;
}
#pragma pop

void TObjEneRecobox::handle_state(s32 arg1) {
    u8 *self = (u8 *)this;

    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)self + 0x40C) = (*(s32 *)((s8 *)self + 0x40C) & 0xFFFFFFFE);
        *(s16 *)((s8 *)self + 0xB8) = 0;
        this->set_intangible();
        ((TObjEneDD *)self)->set_field_378(0);
        ((TUnk_80494938 *)(self + 0x3C0))->start_fade_in();
        return;
    case 3:
        if (((V_Sub_8031f748 *) (self + 0x3C0))->m5() != 0) {
            ((TObjEneDD *)self)->transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        break;
    }
}

void TObjEneRecobox::sub_8031F6C0(s32 reason) {
    s32 temp_r4;

    switch (reason) {
    case 4:
        temp_r4 = *(s32 *)((s8 *)this + 0x40C) | 1;
        *(s32 *)((s8 *)this + 0x40C) = temp_r4;
        this->requested_action = 0;
        ((VObj_8031F6C0 *)this)->m93(temp_r4);
        set_field_378(0);
        return;
    case 3:
        transition_enemy_state(1);
    case 5:
    case 0:
        return;
    }
}

void TObjEneRecon__sub_8031F600(void *ene_dd, s32 arg1) {
    s32 temp_r4;

    switch (arg1) {
    case 4:
        temp_r4 = *(s32 *)((s8 *)ene_dd + 0x40C) & 0xFFFFFFFE;
        *(s32 *)((s8 *)ene_dd + 0x40C) = temp_r4;
        ((TObjEneDD *)ene_dd)->requested_action = 0;
        ((VObj_8031F600 *)ene_dd)->m94(temp_r4);
        ((TObjEneDD *)ene_dd)->set_field_378(2);
        return;
    case 3:
        if ((((VObj_8031F600 *)ene_dd)->m102(500.0f) != 0) && (TObjEneRecon__sub_8031FACC((Obj_8031FACC *)ene_dd) != 0)) {
            ((TObjEneDD *)ene_dd)->transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)ene_dd)->advance_animation();
        break;
    }
}

void TObjEneRecobox::update_state(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s32 *)&this->status_flags = *(s32 *)&this->status_flags & 0xFFFFFFFE;
        this->requested_action = 1;
        this->clear_intangible();
        set_field_378(3);
        return;
    case 3:
        if (get_flag_b4() != 0) {
            this->spawn_timer = 0;
            this->spawn_interval = 0x1E;
            transition_enemy_state(4);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        break;
    }
}

void TObjEneRecobox::handle_action_state(s32 reason) {

    switch (reason) {
    case 4:
        *(s32 *)&this->status_flags = (*(s32 *)&this->status_flags & 0xFFFFFFFE);
        this->requested_action = 2;
        this->clear_intangible();
        set_field_378(2);
        return;
    case 3:
        if (is_out_of_range__14TObjEneRecoboxFv() != 0) {
            transition_enemy_state(5);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        update_child_spawn();
        break;
    }
}

void TObjEneRecon__sub_8031F408(void *ene_dd, s32 arg1) {

    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)ene_dd + 0x40C) = (*(s32 *)((s8 *)ene_dd + 0x40C) & 0xFFFFFFFE);
        ((TObjEneDD *)ene_dd)->requested_action = 3;
        ((TObjEneDD *)ene_dd)->clear_intangible();
        ((TObjEneDD *)ene_dd)->set_field_378(5);
        break;
    case 3:
        if (((TObjEneDD *)ene_dd)->get_flag_b4() != 0) {
            ((TObjEneDD *)ene_dd)->transition_enemy_state(2);
        }
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)ene_dd)->advance_animation();
        break;
    }
}

void TObjEneRecobox::handle_death_state(s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjPlayer *)this)->refresh_lobby_state();
        *(s32 *)&this->status_flags = (s32) (*(s32 *)&this->status_flags | 1);
        spawn_debris_chips();
        this->set_intangible();
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)this + 0x410) == 0) {
            send_entity_set_flags();
            queue_destruction();
        }
    case 5:
    case 0:
        return;
    }
}

#pragma push
#pragma pool_data off
// Called from handle_death_state: breaks the box into three
// debris chips (models 3-5 of the Recobox archive, textures of model 3).
void TObjEneRecobox::spawn_debris_chips() {
    const TObjChipParams chip0 = {
        {0.5f, 0.07f, 0.26f}, {this->position.x, this->position.y, this->position.z},
        {5.0f, 5.0f, 5.0f}, {0x400, 0x100, 0x400}, {5, 50}, {this->position.y, 0.6f},
        (saddr)TObjEneRecobox__static_instance->models[3].model, (saddr)TObjEneRecobox__static_instance->models[3].m_c, 20,
    };
    const TObjChipParams chip1 = {
        {0.5f, 0.07f, 0.26f}, {this->position.x, this->position.y, this->position.z},
        {4.0f, 4.5f, 4.0f}, {0x200, 0x100, 0x200}, {6, 50}, {this->position.y, 0.5f},
        (saddr)TObjEneRecobox__static_instance->models[4].model, (saddr)TObjEneRecobox__static_instance->models[3].m_c, 20,
    };
    const TObjChipParams chip2 = {
        {0.5f, 0.07f, 0.26f}, {this->position.x, this->position.y, this->position.z},
        {4.0f, 4.5f, 4.0f}, {0x200, 0x100, 0x200}, {6, 50}, {this->position.y, 0.5f},
        (saddr)TObjEneRecobox__static_instance->models[5].model, (saddr)TObjEneRecobox__static_instance->models[3].m_c, 20,
    };
    spawn_particle_effect_with_flags(&this->position, 0x45, 0x40);
    spawn_particle_effect_with_flags(&this->position, 0x46, 0x40);
    new TObjChip(tl_05, (TObjChipParams *)&chip0);
    new TObjChip(tl_05, (TObjChipParams *)&chip1);
    new TObjChip(tl_05, (TObjChipParams *)&chip2);
}
#pragma pop

s32 TObjEneRecobox::is_below_child_limit(u16 id) {
    Obj_8031F0F0 *self = (Obj_8031F0F0 *)this;
    s32 n = 0;
    s32 i;
    for (i = 0; i < self->count; i++) {
        if (find_entity_by_id(self->ids[i]) != NULL && id == TObjEneRecon__sub_8031D878()) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode() != 0) {
        return n < 4;
    }
    return n < 2;
}

s32 TObjEneRecobox::has_child_in_anim_5() {
    Obj_8031F070 *self = (Obj_8031F070 *)this;
    s32 i;
    if (self->count <= 0) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(self->ids[i]) != NULL && is_anim_5__12TObjEneReconFv() == 1) {
            return 1;
        }
    }
    return 0;
}

void remove_tracked_target__14TObjEneRecoboxFPvPv(Obj_8031EFAC *o, u8 *target) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(o->ids[i]) == reinterpret_cast<TObjCollidable *>(target)) {
            ((TObjEneRecobox *)o)->remove_tracked_id(o->ids[i]);
            o->count--;
            o->ids[i] = o->ids[o->count];
            o->ids[o->count] = 0xFFFF;
            o->f414--;
            if (o->f414 < 0) {
                o->f414 = 0;
            }
            return;
        }
    }
}

void TObjEneRecobox::remove_child_entity(u8 *arg1) {
    Obj_8031EF14 *self = (Obj_8031EF14 *)this;
    s32 i;
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(self->ids[i]) == reinterpret_cast<TObjCollidable *>(arg1)) {
            self->count--;
            self->ids[i] = self->ids[self->count];
            self->ids[self->count] = 0xFFFF;
            return;
        }
    }
}


s32 TObjEneRecobox::is_anim_6() {
    return (u8)((u8) (this->mode == 6));
}

void TObjEneRecobox::update_floor_probe() {
    u8 *self = (u8 *)this;
    Stack_8031EE54 stack;
    u8 *temp_r3;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy((Vec *)&stack.sp8, (const Vec *)&this->position);
        stack.spC += 15.0f;
        temp_r3 = (u8 *)(csnVectorUnder((Vec *)&stack.sp8, (CsnGroup **)&this->m_120, 0x4000));
        if (temp_r3 != NULL) {
            *(s32 *)((s8 *)self + 0x3E0) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 0x18);
            VecCopy((Vec *)(self + 0x3E4), (const Vec *)(*(u8 **)((s8 *)temp_r3 + 4)));
        } else {
            VecCopy((Vec *)(self + 0x3E4), (const Vec *)&this->position);
        }
    }
    if (*(s32 *)((s8 *)self + 0x3E0) & 0x4000) {
        request_reflection_render();
    }
}

#pragma push
#pragma opt_propagation off
s32 TObjEneRecobox::alloc_child_id() {
    Rec_8031EDF8 *o = (Rec_8031EDF8 *)this;
  s32 new_var;
  s32 i;
  s32 v;
  for (i = 0; i < o->count; i++)
  {
    if (o->ids[i] == 0xFFFF)
    {
      v = (0, o->base + i);
      new_var = i;
      o->ids[new_var] = v + 1;
      return (u16)(o->ids[new_var]);
    }
  }
  return (u16)(0xFFFF);
}
#pragma pop

void TObjEneRecobox::remove_tracked_id(s32 id) {
    T_8031EDBC *self = (T_8031EDBC *)this;
    s32 i;
    for (i = 0; i < 30; i++) {
        if (self->ids[i] == id) {
            self->ids[i] = 0xFFFF;
            return;
        }
    }
}

void TObjEneRecobox::update_if_800BB858() { if (get_target_info() != 0) { sub_8031F800(); } }


void TObjEneRecobox::render() {
    s32 temp_r30;
    Fade_8031EA70 *temp_r29;
    s32 camera_mode;
    s32 var_r28;
    s32 var_r27;
    u8 *self = (u8 *)this;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneRecobox *)self)->draw_with_debug_info();
        return;
    }
    camera_mode = 0;
    if (is_split_screen() != 0) {
        camera_mode = TCameraCtrl::get_camera_mode();
    }
    if (!(*(s32 *)((s8 *)self + 0x40C) & 1)) {
        if (TObjEneDD::is_main_phase_15() != 0) {
            var_r28 = this->classify_actor_view_detail(25.0f + lbl_805D9E88, 50.0f + lbl_805D9E84, 120.0f);
        } else if (this->update_object_view_visibility(500.0f, 120.0f) != 0) {
            var_r28 = 1;
        } else {
            var_r28 = 0;
        }
        if (var_r28 != 0) {
            var_r27 = 0;
            if (((TObjEneRecobox *)self)->render_trap_model_if_visible() == 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                if ((s16) ((TObjEneRecobox *)self)->mode == 1) {
                    if (((Fade_8031EA70 *)(self + 0x3C0))->m8() != 0) {
                        if (((TObject *)self)->defer_render() != 0) {
                            model_render_flags = saved_model_render_flags;
                            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                            return;
                        }
                        var_r27 = 1;
                        ((Fade_8031EA70 *)(self + 0x3C0))->m6();
                        goto block_18;
                    }
                    model_render_flags = saved_model_render_flags;
                    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                    return;
                }
block_18:
                temp_r29 = &((Holder_8031EA70 *)self)->arr[camera_mode];
                ((RenderFadeState *)temp_r29)->update();
                temp_r30 = ((RenderFadeState *)temp_r29)->updateFromCamera((const f32*)(self + 0x2FC));
                if ((var_r27 == 0) && (temp_r30 != 0)) {
                    if (((TObject *)self)->defer_render() != 0) {
                        model_render_flags = saved_model_render_flags;
                        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                        return;
                    }
                    temp_r29->m6();
                    goto block_23;
                }
block_23:
                ((TObjEneDD *)self)->update_secondary_light();
                TObjFish::set_global_param((int) (((TObjEneRecobox *)self)->texlist));
                push_matrix();
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_y(0, (int) (((TObjEneRecobox *)self)->rotation_y));
                switch (((TObjEneRecobox *)self)->mount_type) {
                case 1:
                    rotate_matrix_x(0, 0x8000);
                    break;
                case 2:
                    rotate_matrix_x(0, 0x4000);
                    break;
                }
                TObjEneDD::clear_global_flag_400();
                TObjPlayer::toggle_particle_effect();
                if (var_r28 == 1) {
                    ((TObjMotion *)self)->draw();
                } else {
                    ((TObjEnemy *)self)->draw_motion_model();
                }
                TParticleCtrl::end_effect_render();
                pop_matrix();
                ((TObjEneDD *)self)->update_primary_light();
                if (var_r27 != 0) {
                    ((Fade_8031EA70 *)(self + 0x3C0))->m7();
                } else if (temp_r30 != 0) {
                    temp_r29->m7();
                }
                model_render_flags = saved_model_render_flags;
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                goto block_37;
            }
        } else {
            goto block_37;
        }
    } else {
block_37:
        VecCopy((Vec *)(self + 0x2FC), (const Vec *)(self + 0x38));
    }
}

// pool_data off: each debug string is reached with its own lis/addi.
#pragma push
#pragma pool_data off
void TObjEneRecobox::draw_with_debug_info() {
    if (get_target_info() != 0) {
        switch (this->mount_type) {
        case 0:
            debug_printf_at(pack_debug_text_position(0, 9), "TYPE : NORMAL");
            break;
        case 1:
            debug_printf_at(pack_debug_text_position(0, 9), "TYPE : BOTTOM");
            break;
        case 2:
            debug_printf_at(pack_debug_text_position(0, 9), "TYPE : SIDE");
            break;
        }
        debug_printf_at(pack_debug_text_position(0, 0xA), "RECON TOTAL + 1");
        debug_printf_at(pack_debug_text_position(0, 2), "RECON OFFSET MAX(+45.f)");
        debug_printf_at(pack_debug_text_position(0, 3), "RECON ROTATE RAD(+50.f)");
        debug_printf_at(pack_debug_text_position(0, 5), "RECON MAX(Min:0 Max:6)");
    }
    if (this->update_object_view_visibility(500.0f, 120.0f) != 0) {
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        switch (this->mount_type) {
        case 1:
            rotate_matrix_x(0, 0x8000);
            break;
        case 2:
            rotate_matrix_x(0, 0x4000);
            break;
        }
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(this->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    draw_chunk_object((void *)debug_chunk_object);
    pop_matrix();
}
#pragma pop


