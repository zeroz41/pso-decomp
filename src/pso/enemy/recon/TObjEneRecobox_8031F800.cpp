#define TOBJECT_OUT_OF_LINE_HELPERS

#include "types.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/dd/TObjEneDD_800BB804.h"

#include "pso/enemy/recon/TObjEneRecobox_8031E88C.h"

#include "pso/unk/text_803D96A8.h"

#include "pso/unk/text_803E2D70.h"

#include "pso/system/vector.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/enemy/recon/TObjEneRecobox.h"

#include "pso/enemy/recon/TObjEneRecon.h"

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

#include "pso/unk/text_80087278.h"

#include "pso/system/task/TObject_80019A50.h"

#include "pso/enemy/recon/TObjEneRecon_8031F408.h"

#include "pso/enemy/recon/TObjEneRecon_8031F600.h"

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

#include "pso/enemy/recon/TObjEneRecon_8031FACC.h"

#include "pso/ui/window/TWindowSubComCard.h"

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct FadeBase_8031EA70 { char pad[0x14]; };

struct Fade_8031EA70 : FadeBase_8031EA70 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8();
    u8 pad18[4];
};

struct ObjBase_8031EA70 { char pad[0x18]; };

struct Obj_8031EA70 : ObjBase_8031EA70 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
    virtual s32 m9(f32, f32, f32);
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
};

struct Holder_8031EA70 { u8 pad[0x460]; Fade_8031EA70 arr[4]; };

extern "C" {

s32 get_target_info__9TObjEneDDFv();

s32 push_matrix();

s32 post_translate_matrix(void *);

extern s32 debug_chunk_object;

s32 get_camera_mode__11TCameraCtrlFv();

s32 is_main_phase_15__9TObjEneDDFv();

s32 update__15RenderFadeStateFv(int);

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

u8 *find_entity_by_id(u16);

u16 TObjEneRecon__sub_8031D878();

void remove_tracked_target__12TObjEneReconFPvPv(Obj_8031EFAC *o, u8 *target);

s32 is_anim_5__12TObjEneReconFv();

s32 refresh_lobby_state__10TObjPlayerFv();

s32 send_entity_set_flags__9TObjEnemyFv();

s32 get_flag_b4__9TObjEneDDFv();

s32 get_flag_b4__9TObjEneDDFv();

s32 is_out_of_range__12TObjEneReconFv();

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

s32 TObjEneRecon__sub_8031FACC(Obj_8031FACC *arg0);

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

struct Vec_8031F8C4 { f32 x, y, z; };

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

u32 create__12TObjEneReconFPvPvPvPvPv(void *, u16, s32, Vec_8031F8C4 *, Vec_8031F8C4 *);

s32 alloc_child_id__12TObjEneReconFv(void *);

s32 remap_area_sound_id__14TObjEneRecoboxFUl(s32, s32, s32);

Vec_8031F8C4 *get_field_38_ptr__12TObjEneReconFv(void *, s32);

s32 has_child_in_anim_5__12TObjEneReconFv();

}

struct Stack_8031FB6C {
    s32 sp8;
    f32 spC;
};

struct Obj_8031FACC { u8 pad[0x3F4]; s32 f3F4; s32 f3F8; u8 pad2[0x410 - 0x3FC]; s32 f410; s32 f414; };

extern "C" {

s32 has_child_in_anim_5__12TObjEneReconFv();

}

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

void reset_hp__9TObjEneDDFPUcPUcPUc(void *, s32, s32, s32);

void init_model__9TObjEneDDFP13CollisionBodyl(void *, void *, int);

void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);

void *__dt__15RenderFadeStateFv(void *arg0, s16 arg1);

void __ct__15RenderFadeStateFv();

void free_collision_body_parts(void *);

void __dl__7TObjectFPv(void *);

void TObjEneRecon__sub_8031F408(void *arg0, s32 arg1);

void TObjEneRecon__sub_8031F600(void *arg0, s32 arg1);

void dispatch_state__12TObjEneReconFiUii(s32 arg0, u32 arg1, s32 arg2);

void run_task__14TObjEneRecoboxFv(u8 *arg0);

Obj_8031FE14 * fn_8031FE14(Obj_8031FE14 *arg0, s16 arg1);

void __destroy_arr(void *, void *, int, int);

void __construct_array(void *, void *, void *, int, int);

s32 recobox_boss_register_id;

s32 lbl_805D6B14;

s32 TObjEneRecobox__shared_object_handle;

extern "C" void vfunc_6__8TObjBaseFPsl();

extern "C" void vfunc_103__9TObjEneDDFPUc();

extern "C" void vfunc_79__9TObjEneDDFPl();

extern "C" void vfunc_84__9TObjEneDDFv();

extern "C" void vfunc_85__9TObjEneDDFv();

extern "C" void vfunc_86__9TObjEneDDFv();

extern "C" void vfunc_89__9TObjEneDDFv();

extern "C" void vfunc_90__9TObjEneDDFv();

extern "C" void vfunc_91__9TObjEneDDFv();

extern "C" void vfunc_92__9TObjEneDDFv();

extern "C" void vfunc_93__9TObjEneDDFv();

extern "C" void vfunc_94__9TObjEneDDFv();

extern "C" void vfunc_95__9TObjEneDDFv();

extern "C" void vfunc_96__9TObjEneDDFv();

extern "C" void vfunc_97__9TObjEneDDFv();

extern "C" void vfunc_98__9TObjEneDDFv();

extern "C" void vfunc_99__9TObjEneDDFv();

extern "C" void vfunc_100__9TObjEneDDFv();

extern "C" void vfunc_101__9TObjEneDDFPUc();

extern "C" void vfunc_102__9TObjEneDDFv();

extern "C" int vfunc_104__12TObjEneDD_STFf(void *p);

extern "C" void vfunc_83__12TObjEneDD_STFv();

extern "C" void draw_with_debug_info__14TObjEneRecoboxFv();

extern "C" void render__14TObjEneRecoboxFv(u8 *arg0);

extern "C" void TObjEneRecon__sub_8031FB6C(u8 *arg0);

extern "C" void vfunc_61__14TObjEneRecoboxFv();

extern "C" void vfunc_62__14TObjEneRecoboxFv();

extern "C" void vfunc_28__14TObjEneRecoboxFv();

extern "C" void vfunc_29__9TObjCharaFv();

extern "C" void recalc_stats__9TObjCharaFv();

extern "C" void consume_timer_field__9TObjCharaFl();

extern "C" void vfunc_67__9TObjCharaFf();

extern "C" void vfunc_66__9TObjCharaFv();

extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();

extern "C" void vfunc_60__9TObjCharaFv();

extern "C" void vfunc_59__9TObjCharaFv();

extern "C" void vfunc_58__9TObjCharaFv();

extern "C" void apply_slow_status__9TObjCharaFv();

extern "C" void update_shock_clock__9TObjCharaFv();

extern "C" void vfunc_43__9TObjCharaFv();

extern "C" void vfunc_18__9TObjCharaFPUc();

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

extern "C" void vfunc_77__9TObjCharaFv();

extern "C" void vfunc_76__9TObjCharaFf();

extern "C" void vfunc_75__9TObjCharaFf();

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

extern "C" void vfunc_63__14TObjEneRecoboxFv();

extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);

extern "C" void try_start_action__9TObjCharaFll();

extern "C" void update_action_hold_status__9TObjCharaFv();

extern "C" s32 vfunc_37__9TObjCharaFv(u8 *arg0);

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

void *TObjEneRecobox__animation_entries[16] = {
    (void *)0x10000, (void *)0x1, (void *)0x3dcccccd, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10000, (void *)0x3, (void *)0x3dcccccd, (void *)0x0,
    (void *)0x30000, (void *)0x0, (void *)0x3f19999a, (void *)0x0,
};

void *TObjEneRecobox__vtable[107] = {
    (void *)0x0, (void *)0x0, (void *)&fn_8031FE14, (void *)&run_task__14TObjEneRecoboxFv,
    (void *)&render__14TObjEneRecoboxFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__14TObjEneRecoboxFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__14TObjEneRecoboxFv, (void *)&vfunc_62__14TObjEneRecoboxFv, (void *)&vfunc_63__14TObjEneRecoboxFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFf, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&vfunc_84__9TObjEneDDFv, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_state__12TObjEneReconFiUii,
    (void *)&TObjEneRecon__sub_8031FB6C, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&vfunc_104__12TObjEneDD_STFf, (void *)&update_if_800BB858__14TObjEneRecoboxFv, (void *)&draw_with_debug_info__14TObjEneRecoboxFv,
};

}

#define TObjEneRecobox__attack_params ((u8 *)TObjEneRecobox__attack_params)
#define TObjEneRecobox__vtable ((u8 *)TObjEneRecobox__vtable)

extern "C" {

int TObjEneRecobox__sub_803201D0(void);

void *TObjEneRecobox__create(void *arg0);

void free_bin_model_request(void*, int);

void *__nw__7TObjectFUl(int);

struct V3_80320260 { f32 x, y, z; };

// inferred: field names follow MojaAnimationBinding (TObjEneMoja.h), the same 0x10 animation binding layout.
struct Spawn_80320260 { s32 motions; void **actions; u32 unknown_08; u16 action_count; u16 unknown_0E; };

struct Inner_80320260 { u8 pad[0x18]; s32 f18; NJS_TEXLIST *texlist; };

struct Box_80320260 { u8 pad[0x42C]; Inner_80320260 *f42C; s32 f430; };

struct Sub_80320260 { u8 pad[0xC]; f32 f0C; };

s32 dispatch_shared_handler_a__6TLobbyFl(s32);

s32 register_object__6TLobbyFl(s32);

s32 dispatch_shared_handler_b__6TLobbyFl(s32);

s32 register_boss__6TLobbyFl(s32);

s32 load_enemy_bml_resource(u8 *arg0);

}

extern "C" {

V3_80320260 lbl_80543000;

s32 lbl_805D6B1C;

BmlResource *TObjEneRecobox__static_instance;

const Spawn_80320260 recobox_resource_binding_desc = {0, TObjEneRecobox__animation_entries, 0, 4, 0};

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
            res = load_enemy_bml_resource((u8 *)&lbl_804EC750);
        } else {
            res = load_enemy_bml_resource((u8 *)&lbl_804EC6F8);
        }
        (*(u32 *)&TObjEneRecobox__static_instance) = res;
    }
    recobox_boss_register_id = register_boss__6TLobbyFl(0x41);
    lbl_805D6B14 = dispatch_shared_handler_b__6TLobbyFl(0x41);
    TObjEneRecobox__shared_object_handle = register_object__6TLobbyFl(0x41);
    lbl_805D6B1C = dispatch_shared_handler_a__6TLobbyFl(0x41);
    TObjEneRecon::load_resources();
    {
        Sub_80320260 *sp = (Sub_80320260 *)lbl_804EC684;
        Spawn_80320260 s = recobox_resource_binding_desc;
        box = (Box_80320260 *)(*(u32 *)&TObjEneRecobox__static_instance);
        s.motions = box->f430;
        TLobby::spawn_npc_enemy((s16)0xD, box->f42C->f18, box->f42C->texlist, &s, (f32)(getf_80320260(sp)), 0.0f);
    }
}

}

extern "C" {

u8 *TObjEneRecobox__ct(u8 *ene_recobox, s32 arg1, u8 *arg2);

void *TObjEneRecobox__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x4F4);
    if (o != NULL) {
        o = TObjEneRecobox__ct((u8 *)o, (s32)tl_04, (u8 *)arg0);
    }
    return o;
}

void TObjEneRecobox::release_static_instance() {
    TObjEneRecon::release_static_instance();
    if ((u32) (*(u32 *)&TObjEneRecobox__static_instance) != 0U) {
        free_bin_model_request((void*)(*(u32 *)&TObjEneRecobox__static_instance), 1);
        (*(u32 *)&TObjEneRecobox__static_instance) = 0U;
    }
}

int TObjEneRecobox__sub_803201D0(void) {  return (*(int *)&TObjEneRecobox__static_instance); }

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

u8 *TObjEneRecobox__ct(u8 *ene_recobox, s32 arg1, u8 *arg2) {
    Self_8031FE98 *S = (Self_8031FE98 *)ene_recobox;
    s32 i;
    s32 n;
    __ct__12TObjEneDD_STFP7TObject(ene_recobox, arg1, arg2);
    *(u8 **)((s8 *)ene_recobox + 0x18) = TObjEneRecobox__vtable;
    __ct__13TUnk_80494938Fv((ene_recobox + 0x3C0));
    __construct_array(ene_recobox + 0x460, (void *)&__ct__15RenderFadeStateFv, (void *)&__dt__15RenderFadeStateFv, 0x1C, 4);
    ((TObject *)ene_recobox)->m_name = TObjEneRecobox_name_ref;
    ((TObjEneDD *)ene_recobox)->invoke_initialization_hook(arg2);
    ((TObjEneDD *)ene_recobox)->init_position_vectors();
    *(s32 *)((s8 *)ene_recobox + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneRecobox__static_instance + 0x42C)) + 0x18);
    ((TObjEneRecobox *)ene_recobox)->texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneRecobox__static_instance + 0x42C)) + 0x1C);
    init_model__9TObjEneDDFP13CollisionBodyl(ene_recobox, lbl_804EC684, 1);
    ((TObjEneRecobox *)ene_recobox)->m_300 = 20.0f + *(f32 *)((s8 *)ene_recobox + 0x3C);
    ((TObjEneRecobox *)ene_recobox)->vfunc_88();
    ((TObjMotion *)ene_recobox)->set_field_d8((s32)TObjEneRecobox__animation_entries);
    ((TObjMotion *)ene_recobox)->set_field_dc(*(s32 *)((s8 *)TObjEneRecobox__static_instance + 0x430));
    ((TObjEneRecobox *)ene_recobox)->requested_action = 0;
    ((TObjMotion *)ene_recobox)->set_animation(((TObjEneRecobox *)ene_recobox)->requested_action);
    ((TObjMotion *)ene_recobox)->set_field_b8(((TObjEneRecobox *)ene_recobox)->requested_action);
    reset_hp__9TObjEneDDFPUcPUcPUc(ene_recobox, recobox_boss_register_id, lbl_805D6B14, TObjEneRecobox__shared_object_handle);
    ((TObjEneDD *)ene_recobox)->check_state_flag_4();
    *(u8 * *)&((TObjEneRecobox *)ene_recobox)->movementParameters = TObjEneRecobox__attack_params;
    ((TObjEneDD *)ene_recobox)->initialize_enemy_state(0x43);
    ((TObjEneRecobox *)ene_recobox)->m_37c = 10.0f;
    ((TObjEneRecobox *)ene_recobox)->sub_8031F800();
    n = *(s16 *)((s8 *)arg2 + 2);
    if (n <= 1) {
        *(s32 *)&((TObjEneRecobox *)ene_recobox)->m_410 = 0;
    } else if (*(s32 *)&((TObjEneRecobox *)ene_recobox)->m_410 >= n) {
        *(s32 *)&((TObjEneRecobox *)ene_recobox)->m_410 = n - 1;
    }
    if (*(s32 *)&((TObjEneRecobox *)ene_recobox)->m_414 > *(s32 *)&((TObjEneRecobox *)ene_recobox)->m_410) {
        *(s32 *)&((TObjEneRecobox *)ene_recobox)->m_414 = *(s32 *)&((TObjEneRecobox *)ene_recobox)->m_410;
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
    *(s32 *)((s8 *)ene_recobox + 0x4D8) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x4DC) = 0;
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
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjEneRecobox::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->update_if_800BB858();
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
    } else if ((s16) this->mode == 1) {
        transition_enemy_state(0);
    }
    this->vfunc_88();
    ((TObjEneRecon *)((u8 *)this))->restore_position();
    ((TObjEnemy *)((u8 *)this))->submit_default_cursor_candidate();
    this->vfunc_100();
    this->update_floor_probe();
}

void dispatch_state__12TObjEneReconFiUii(s32 ene_dd, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        ((TObjEneRecobox *)ene_dd)->sub_8031F6C0(arg2);
        return;
    case 1:
        ((TObjEneRecon *)ene_dd)->handle_state(arg2);
        return;
    case 2:
        TObjEneRecon__sub_8031F600((void *)ene_dd, (arg2));
        return;
    case 3:
        ((TObjEneRecon *)ene_dd)->update_state(arg2);
        return;
    case 4:
        ((TObjEneRecon *)ene_dd)->handle_action_state(arg2);
        return;
    case 5:
        TObjEneRecon__sub_8031F408((void *)ene_dd, (arg2));
        return;
    case 6:
        ((TObjEneRecon *)ene_dd)->handle_death_state(arg2);
    default:
        return;
    }
}

}

void TObjEneRecobox::vfunc_28() {  }

void TObjEneRecobox::vfunc_63() { if (this->mode != 6) { transition_enemy_state((s16)((void*)6)); } }

void TObjEneRecobox::vfunc_62() { clear_attack_receipts(); }

void TObjEneRecobox::vfunc_61() {  }

void TObjEneRecon::restore_position() { VecCopy((Vec *)((char*)this + 0x74), (const Vec *)((char*)this + 0x2fc)); }

extern "C" {

void TObjEneRecon__sub_8031FB6C(u8 *ene_recobox) {
    Stack_8031FB6C stack;
    u8 *temp_r3;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(ene_recobox + 0x2FC));
    if ((s32) ((TObjEneRecobox *)ene_recobox)->m_3f8 == 1) {
        stack.spC -= 5.0f;
    } else {
        stack.spC += 5.0f;
    }
    temp_r3 = (u8 *)(csnVectorUnder((Vec *)&stack.sp8, (u32 *)(ene_recobox + 0x120), 0x15));
    if ((temp_r3 == NULL) || (((TObjEneRecobox *)ene_recobox)->m_300 >= (40.0f + *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 4)))) {
        ((TObjEneRecobox *)(ene_recobox))->vfunc_97();
    }
    ((TObjEneDD *)ene_recobox)->set_part_local_pos(ene_recobox + 0x2FC, 0);
}

s32 TObjEneRecon__sub_8031FACC(Obj_8031FACC *arg0) {
    u8 r;
    s32 t;
    if (has_child_in_anim_5__12TObjEneReconFv() == 1) {
        return 0;
    }
    t = (s32)TWindowSubComCard::trunc_float(arg0->f3F8 / 2.0f);
    r = 0;
    if (arg0->f410 <= t && arg0->f414 < arg0->f3F4) {
        r = 1;
    }
    return r;
}

u8 TObjEneRecon::is_out_of_range() {
    int var_r4;

    if (has_child_in_anim_5__12TObjEneReconFv() == 1) {
        return 1;
    }
    var_r4 = 0;
    if (((s32) *(s32 *)((s8 *)this + 0x410) >= (s32) *(s32 *)((s8 *)this + 0x3F8)) || ((s32) *(s32 *)((s8 *)this + 0x414) >= (s32) *(s32 *)((s8 *)this + 0x3F4))) {
        var_r4 = 1;
    }
    return (u8) var_r4;
}

void TObjEneRecon::update_child_spawn() {
    Recon_8031F8C4 *o = (Recon_8031F8C4 *)this;
    Vec_8031F8C4 dir = {0.0f, 0.0f, 0.0f};
    Vec_8031F8C4 pos;
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
    id = alloc_child_id__12TObjEneReconFv(o);
    arg = o->f2C + (id - o->f1C);
    VecCopy((Vec *)&pos, (const Vec *)(get_field_38_ptr__12TObjEneReconFv(o, o->f2C)));
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
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    *(s32 *)&this->m_3f8 = (s32) *(s32 *)&this->variant;
    if ((s32) *(s32 *)&this->m_3f8 <= 0) {
        *(s32 *)&this->m_3f8 = 0;
    } else if ((s32) *(s32 *)&this->variant >= 2) {
        *(s32 *)&this->m_3f8 = 2;
    }
    *(f32 *)&this->m_4ec = (f32) *(f32 *)((s8 *)arg0 + 0x354);
    *(f32 *)((s8 *)arg0 + 0x4D4) = (f32) *(f32 *)((s8 *)arg0 + 0x358);
    if (*(f32 *)((s8 *)arg0 + 0x4D4) <= -30.0f) {
        *(f32 *)((s8 *)arg0 + 0x4D4) = -30.0f;
    }
    *(s32 *)&this->m_414 = (s32) *(f32 *)((s8 *)arg0 + 0x360);
    temp_r0 = *(s32 *)&this->m_414;
    if (temp_r0 < 0) {
        *(s32 *)&this->m_414 = 0;
    } else if (temp_r0 > 6) {
        *(s32 *)&this->m_414 = 6;
    }
    if ((s32) *(s32 *)&this->m_414 == 0) {
        *(s32 *)&this->m_410 = 0;
        return;
    }
    *(s32 *)&this->m_410 = 0x1E;
}
#pragma pop

void TObjEneRecon::handle_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;

    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)arg0 + 0x40C) = (*(s32 *)((s8 *)arg0 + 0x40C) & 0xFFFFFFFE);
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        this->vfunc_95();
        ((TObjEneDD *)arg0)->set_field_378(0);
        ((TUnk_80494938 *)(arg0 + 0x3C0))->start_fade_in();
        return;
    case 3:
        if (((V_Sub_8031f748 *) (arg0 + 0x3C0))->m5() != 0) {
            ((TObjEneDD *)arg0)->transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        break;
    }
}

void TObjEneRecobox::sub_8031F6C0(s32 arg1) {
    s32 temp_r4;

    switch (arg1) {
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

}

extern "C" {

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

void TObjEneRecon::update_state(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s32 *)&this->m_428 = *(s32 *)&this->m_428 & 0xFFFFFFFE;
        this->requested_action = 1;
        this->vfunc_96();
        set_field_378(3);
        return;
    case 3:
        if (get_flag_b4__9TObjEneDDFv() != 0) {
            this->m_4d8 = 0;
            *(s32 *)((s8 *)this + 0x4DC) = 0x1E;
            transition_enemy_state(4);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        break;
    }
}

void TObjEneRecon::handle_action_state(s32 arg1) {

    switch (arg1) {
    case 4:
        *(s32 *)&this->m_428 = (*(s32 *)&this->m_428 & 0xFFFFFFFE);
        this->requested_action = 2;
        this->vfunc_96();
        set_field_378(2);
        return;
    case 3:
        if (is_out_of_range__12TObjEneReconFv() != 0) {
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
        ((TObjEneDD *)ene_dd)->vfunc_96();
        ((TObjEneDD *)ene_dd)->set_field_378(5);
        break;
    case 3:
        if (get_flag_b4__9TObjEneDDFv() != 0) {
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

void TObjEneRecon::handle_death_state(s32 arg1) {
    switch (arg1) {
    case 4:
        refresh_lobby_state__10TObjPlayerFv();
        *(s32 *)&this->m_428 = (s32) (*(s32 *)&this->m_428 | 1);
        TObjEneRecobox__sub_8031F1A8(this);
        this->vfunc_95();
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)this + 0x410) == 0) {
            send_entity_set_flags__9TObjEnemyFv();
            queue_destruction();
        }
    case 5:
    case 0:
        return;
    }
}

#pragma push
#pragma pool_data off
// Called from TObjEneRecon::handle_death_state: breaks the Recon into three
// debris chips (models 3-5 of the Recobox archive, textures of model 3).
void TObjEneRecobox__sub_8031F1A8(TObjEneRecon *recon) {
    const TObjChipParams chip0 = {
        {0.5f, 0.07f, 0.26f}, {recon->position.x, recon->position.y, recon->position.z},
        {5.0f, 5.0f, 5.0f}, {0x400, 0x100, 0x400}, {5, 50}, {recon->position.y, 0.6f},
        TObjEneRecobox__static_instance->models[3].model, TObjEneRecobox__static_instance->models[3].m_c, 20,
    };
    const TObjChipParams chip1 = {
        {0.5f, 0.07f, 0.26f}, {recon->position.x, recon->position.y, recon->position.z},
        {4.0f, 4.5f, 4.0f}, {0x200, 0x100, 0x200}, {6, 50}, {recon->position.y, 0.5f},
        TObjEneRecobox__static_instance->models[4].model, TObjEneRecobox__static_instance->models[3].m_c, 20,
    };
    const TObjChipParams chip2 = {
        {0.5f, 0.07f, 0.26f}, {recon->position.x, recon->position.y, recon->position.z},
        {4.0f, 4.5f, 4.0f}, {0x200, 0x100, 0x200}, {6, 50}, {recon->position.y, 0.5f},
        TObjEneRecobox__static_instance->models[5].model, TObjEneRecobox__static_instance->models[3].m_c, 20,
    };
    spawn_particle_effect_with_flags(&recon->position, 0x45, 0x40);
    spawn_particle_effect_with_flags(&recon->position, 0x46, 0x40);
    new TObjChip(tl_05, (TObjChipParams *)&chip0);
    new TObjChip(tl_05, (TObjChipParams *)&chip1);
    new TObjChip(tl_05, (TObjChipParams *)&chip2);
}
#pragma pop

s32 TObjEneRecon::is_below_child_limit(u16 arg1) {
    Obj_8031F0F0 *arg0 = (Obj_8031F0F0 *)this;
    s32 n = 0;
    s32 i;
    for (i = 0; i < arg0->count; i++) {
        if (find_entity_by_id(arg0->ids[i]) != NULL && arg1 == TObjEneRecon__sub_8031D878()) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode() != 0) {
        return n < 4;
    }
    return n < 2;
}

s32 TObjEneRecon::has_child_in_anim_5() {
    Obj_8031F070 *arg0 = (Obj_8031F070 *)this;
    s32 i;
    if (arg0->count <= 0) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(arg0->ids[i]) != NULL && is_anim_5__12TObjEneReconFv() == 1) {
            return 1;
        }
    }
    return 0;
}

void remove_tracked_target__12TObjEneReconFPvPv(Obj_8031EFAC *o, u8 *target) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(o->ids[i]) == target) {
            ((TObjEneRecon *)o)->remove_tracked_id(o->ids[i]);
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

void TObjEneRecon::remove_child_entity(u8 *arg1) {
    Obj_8031EF14 *arg0 = (Obj_8031EF14 *)this;
    s32 i;
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(arg0->ids[i]) == arg1) {
            arg0->count--;
            arg0->ids[i] = arg0->ids[arg0->count];
            arg0->ids[arg0->count] = 0xFFFF;
            return;
        }
    }
}

}

u8 TObjEneRecon::is_anim_6() {
    return (u8) (this->mode == 6);
}

void TObjEneRecobox::update_floor_probe() {
    u8 *arg0 = (u8 *)this;
    Stack_8031EE54 stack;
    u8 *temp_r3;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy((Vec *)&stack.sp8, (const Vec *)&this->position);
        stack.spC += 15.0f;
        temp_r3 = (u8 *)(csnVectorUnder((Vec *)&stack.sp8, (u32 *)&this->m_120, 0x4000));
        if (temp_r3 != NULL) {
            *(s32 *)((s8 *)arg0 + 0x3E0) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 0x18);
            VecCopy((Vec *)(arg0 + 0x3E4), (const Vec *)(*(u8 **)((s8 *)temp_r3 + 4)));
        } else {
            VecCopy((Vec *)(arg0 + 0x3E4), (const Vec *)&this->position);
        }
    }
    if (*(s32 *)((s8 *)arg0 + 0x3E0) & 0x4000) {
        TObjEneRecon::set_active();
    }
}

#pragma push
#pragma opt_propagation off
u16 TObjEneRecon::alloc_child_id() {
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
      return o->ids[new_var];
    }
  }
  return 0xFFFF;
}
#pragma pop

void TObjEneRecon::remove_tracked_id(s32 id) {
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

extern "C" {

void TObjEneRecobox::render() {
    s32 temp_r30;
    Fade_8031EA70 *temp_r29;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneRecobox *)arg0)->draw_with_debug_info();
        return;
    }
    var_r29 = 0;
    if (is_split_screen() != 0) {
        var_r29 = get_camera_mode__11TCameraCtrlFv();
    }
    if (!(*(s32 *)((s8 *)arg0 + 0x40C) & 1)) {
        if (is_main_phase_15__9TObjEneDDFv() != 0) {
            var_r28 = ((Obj_8031EA70 *)arg0)->m9(25.0f + lbl_805D9E88, 50.0f + lbl_805D9E84, 120.0f);
        } else if (((Obj_8031EA70 *)arg0)->m8(500.0f, 120.0f) != 0) {
            var_r28 = 1;
        } else {
            var_r28 = 0;
        }
        if (var_r28 != 0) {
            var_r27 = 0;
            if (((TObjEneRecobox *)arg0)->render_trap_model_if_visible() == 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                if ((s16) ((TObjEneRecobox *)arg0)->mode == 1) {
                    if (((Fade_8031EA70 *)(arg0 + 0x3C0))->m8() != 0) {
                        if (((TObject *)arg0)->defer_render() != 0) {
                            model_render_flags = saved_model_render_flags;
                            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                            return;
                        }
                        var_r27 = 1;
                        ((Fade_8031EA70 *)(arg0 + 0x3C0))->m6();
                        goto block_18;
                    }
                    model_render_flags = saved_model_render_flags;
                    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                    return;
                }
block_18:
                temp_r29 = &((Holder_8031EA70 *)arg0)->arr[var_r29];
                update__15RenderFadeStateFv((int)temp_r29);
                temp_r30 = ((RenderFadeState *)temp_r29)->updateFromCamera((const f32*)(arg0 + 0x2FC));
                if ((var_r27 == 0) && (temp_r30 != 0)) {
                    if (((TObject *)arg0)->defer_render() != 0) {
                        model_render_flags = saved_model_render_flags;
                        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                        return;
                    }
                    temp_r29->m6();
                    goto block_23;
                }
block_23:
                ((TObjEneDD *)arg0)->update_secondary_light();
                TObjFish::set_global_param((int) (((TObjEneRecobox *)arg0)->texlist));
                push_matrix();
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_y(0, (int) (((TObjEneRecobox *)arg0)->rotation_y));
                switch (((TObjEneRecobox *)arg0)->m_3f8) {
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
                    ((TObjMotion *)arg0)->draw();
                } else {
                    ((TObjEnemy *)arg0)->draw_motion_model();
                }
                TParticleCtrl::end_effect_render();
                pop_matrix();
                ((TObjEneDD *)arg0)->update_primary_light();
                if (var_r27 != 0) {
                    ((Fade_8031EA70 *)(arg0 + 0x3C0))->m7();
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
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    }
}

// pool_data off: each debug string is reached with its own lis/addi.
#pragma push
#pragma pool_data off
void TObjEneRecobox::draw_with_debug_info() {
    u8 *arg0 = (u8 *)this;
    if (get_target_info__9TObjEneDDFv() != 0) {
        switch (this->m_3f8) {
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
    if (((VObj_18_26a62c *)(arg0))->m8(500.0f, 120.0f) != 0) {
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        switch (this->m_3f8) {
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

}

