#include "pso/enemy/TObjEnemy.h"
#include "pso/render/RenderFadeState.h"
#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/recon/TObjEneRecobox.h"
#include "pso/map/FloorArea.h"
#include "pso/system/vector.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/unk/TLobby.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/map/CsnQuery.h"
#include "pso/enemy/recon/TObjEneRecon_8031FACC.h"
#include "pso/ui/window/TWindowSubComCard.h"

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
extern const f32 lbl_805DF44C;
u32 create__12TObjEneReconFPvPvPvPvPv(void *, u16, s32, Vec_8031F8C4 *, Vec_8031F8C4 *);
s32 alloc_child_id__12TObjEneReconFv(void *);
s32 remap_area_sound_id__14TObjEneRecoboxFUl(s32, s32, s32);
Vec_8031F8C4 *get_field_38_ptr__12TObjEneReconFv(void *, s32);
extern Vec_8031F8C4 lbl_804762E4;
extern const f32 lbl_805DF450;
extern const f32 lbl_805DF454;
extern const f32 lbl_805DF458;
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
    if (*(f32 *)((s8 *)arg0 + 0x4D4) <= lbl_805DF44C) {
        *(f32 *)((s8 *)arg0 + 0x4D4) = (f32) lbl_805DF44C;
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

void TObjEneRecon::update_child_spawn() {
    Recon_8031F8C4 *o = (Recon_8031F8C4 *)this;
    Vec_8031F8C4 dir = lbl_804762E4;
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
        dir.y = lbl_805DF450;
        break;
    case 1:
        dir.y = lbl_805DF454;
        break;
    case 2:
        dir.x = lbl_805DF458 * sin_table_lookup(o->f60);
        dir.z = lbl_805DF458 * cos_table_lookup(o->f60);
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

}

extern "C" {

s32 has_child_in_anim_5__12TObjEneReconFv();

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

}

struct Stack_8031FB6C {
    s32 sp8;
    f32 spC;
};

struct Obj_8031FACC { u8 pad[0x3F4]; s32 f3F4; s32 f3F8; u8 pad2[0x410 - 0x3FC]; s32 f410; s32 f414; };

extern "C" {
extern const f32 lbl_805DF450;
extern const f32 lbl_805DF460;
s32 has_child_in_anim_5__12TObjEneReconFv();
extern const f32 lbl_805DF45C;
u8 TObjEneRecon__sub_8031FACC(Obj_8031FACC *arg0);

u8 TObjEneRecon__sub_8031FACC(Obj_8031FACC *arg0) {
    s32 r;
    s32 t;
    if (has_child_in_anim_5__12TObjEneReconFv() == 1) {
        return 0;
    }
    t = (s32)TWindowSubComCard::trunc_float((f32)arg0->f3F8 * lbl_805DF45C);
    r = 0;
    if (arg0->f410 <= t && arg0->f414 < arg0->f3F4) {
        r = 1;
    }
    return (u8)r;
}

void TObjEneRecon__sub_8031FB6C(u8 *ene_recobox) {
    Stack_8031FB6C stack;
    u8 *temp_r3;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(ene_recobox + 0x2FC));
    if ((s32) ((TObjEneRecobox *)ene_recobox)->m_3f8 == 1) {
        stack.spC -= lbl_805DF450;
    } else {
        stack.spC += lbl_805DF450;
    }
    temp_r3 = (u8 *)(csnVectorUnder((Vec *)&stack.sp8, (u32 *)(ene_recobox + 0x120), 0x15));
    if ((temp_r3 == NULL) || (((TObjEneRecobox *)ene_recobox)->m_300 >= (lbl_805DF460 + *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 4)))) {
        ((TObjEneRecobox *)(ene_recobox))->vfunc_97();
    }
    ((TObjEneDD *)ene_recobox)->set_part_local_pos(ene_recobox + 0x2FC, 0);
}

}

void TObjEneRecon::restore_position() { VecCopy((Vec *)((char*)this + 0x74), (const Vec *)((char*)this + 0x2fc)); }
void TObjEneRecobox::vfunc_61() {  }
void TObjEneRecobox::vfunc_62() { clear_attack_receipts(); }
void TObjEneRecobox::vfunc_63() { if (this->mode != 6) { transition_enemy_state((s16)((void*)6)); } }
void TObjEneRecobox::vfunc_28() {  }

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

extern u8 *TObjEneRecobox__static_instance;
extern s32 TObjEneRecobox_name_ref;
s32 recobox_boss_register_id;
s32 lbl_805D6B14;
s32 TObjEneRecobox__shared_object_handle;
extern const f32 lbl_805DF464;
extern const f32 lbl_805DF468;
extern const f32 lbl_805DF46C;

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
extern "C" u8 lbl_80476118[];
extern "C" u8 lbl_80476124[];
extern "C" u8 lbl_80476134[];
extern "C" u8 lbl_80476144[];
extern "C" u8 lbl_8047615C[];
extern "C" u8 lbl_80476174[];
extern "C" u8 lbl_8047618C[];
extern "C" u8 lbl_804761A4[];
extern "C" u8 lbl_804761C0[];
extern "C" u8 lbl_804761D8[];
extern "C" u8 lbl_804761F4[];
extern "C" u8 lbl_80476208[];
extern "C" u8 lbl_80476220[];
extern "C" u8 lbl_80476234[];
extern "C" u8 lbl_8047624C[];
extern "C" u8 lbl_80476260[];
extern "C" u8 lbl_80476274[];
extern "C" u8 lbl_80476288[];
extern "C" u8 lbl_80476298[];
extern "C" u8 lbl_804762AC[];
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
extern void *lbl_804EC6B0[7];
extern void *recobox_motion_name_table[11];
extern void *lbl_804EC708[7];
extern void *TObjEneRecobox__resource_bundle[11];
void *TObjEneRecobox__attack_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804EC684[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804EC6B0[7] = {
    (void *)&lbl_80476118, (void *)&lbl_80476124, (void *)&lbl_80476134, (void *)&lbl_80476144,
    (void *)&lbl_8047615C, (void *)&lbl_80476174, (void *)0x0,
};
void *recobox_motion_name_table[11] = {
    (void *)&lbl_8047618C, (void *)&lbl_804761A4, (void *)&lbl_804761C0, (void *)&lbl_804761D8,
    (void *)&lbl_804761F4, (void *)&lbl_80476208, (void *)&lbl_80476220, (void *)&lbl_80476234,
    (void *)&lbl_8047624C, (void *)&lbl_80476260, (void *)0x0,
};
void *lbl_804EC6F8[4] = {
    (void *)&lbl_80476274, (void *)&lbl_804EC6B0, (void *)&recobox_motion_name_table, (void *)0x6000a,
};
void *lbl_804EC708[7] = {
    (void *)&lbl_80476288, (void *)&lbl_80476298, (void *)&lbl_80476134, (void *)&lbl_80476144,
    (void *)&lbl_8047615C, (void *)&lbl_80476174, (void *)0x0,
};
void *TObjEneRecobox__resource_bundle[11] = {
    (void *)&lbl_8047618C, (void *)&lbl_804761A4, (void *)&lbl_804761C0, (void *)&lbl_804761D8,
    (void *)&lbl_804761F4, (void *)&lbl_80476208, (void *)&lbl_80476220, (void *)&lbl_80476234,
    (void *)&lbl_8047624C, (void *)&lbl_80476260, (void *)0x0,
};
void *lbl_804EC750[4] = {
    (void *)&lbl_804762AC, (void *)&lbl_804EC708, (void *)&TObjEneRecobox__resource_bundle, (void *)0x6000a,
};
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
#define TObjEneRecobox__attack_params ((u8 *)TObjEneRecobox__attack_params)
#define TObjEneRecobox__vtable ((u8 *)TObjEneRecobox__vtable)

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

u8 *TObjEneRecobox__ct(u8 *ene_recobox, s32 arg1, u8 *arg2) {
    Self_8031FE98 *S = (Self_8031FE98 *)ene_recobox;
    s32 i;
    s32 n;
    __ct__12TObjEneDD_STFP7TObject(ene_recobox, arg1, arg2);
    *(u8 **)((s8 *)ene_recobox + 0x18) = TObjEneRecobox__vtable;
    __ct__13TUnk_80494938Fv((ene_recobox + 0x3C0));
    __construct_array(ene_recobox + 0x460, (void *)&__ct__15RenderFadeStateFv, (void *)&__dt__15RenderFadeStateFv, 0x1C, 4);
    *(s32 *)((s8 *)ene_recobox + 0) = TObjEneRecobox_name_ref;
    ((TObjEneDD *)ene_recobox)->invoke_initialization_hook(arg2);
    ((TObjEneDD *)ene_recobox)->init_position_vectors();
    *(s32 *)((s8 *)ene_recobox + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneRecobox__static_instance + 0x42C)) + 0x18);
    ((TObjEneRecobox *)ene_recobox)->texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneRecobox__static_instance + 0x42C)) + 0x1C);
    init_model__9TObjEneDDFP13CollisionBodyl(ene_recobox, lbl_804EC684, 1);
    ((TObjEneRecobox *)ene_recobox)->m_300 = lbl_805DF464 + *(f32 *)((s8 *)ene_recobox + 0x3C);
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
    ((TObjEneRecobox *)ene_recobox)->m_37c = lbl_805DF468;
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
    ((TObjEneRecobox *)ene_recobox)->m_4f0 = lbl_805DF46C;
    ((TObjEneRecobox *)ene_recobox)->mode = 0;
    ((VObj_18_b2458f *)ene_recobox)->m85(((TObjEneRecobox *)ene_recobox)->mode, 4);
    return ene_recobox;
}

int TObjEneRecobox__sub_803201D0(void);

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

int TObjEneRecobox__sub_803201D0(void) {  return (*(int *)&TObjEneRecobox__static_instance); }

void *TObjEneRecobox__create(void *arg0);
void free_bin_model_request(void*, int);
void *__nw__7TObjectFUl(int);

void TObjEneRecobox::release_static_instance() {
    TObjEneRecon::release_static_instance();
    if ((u32) (*(u32 *)&TObjEneRecobox__static_instance) != 0U) {
        free_bin_model_request((void*)(*(u32 *)&TObjEneRecobox__static_instance), 1);
        (*(u32 *)&TObjEneRecobox__static_instance) = 0U;
    }
}

extern void *tl_04;

void *TObjEneRecobox__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x4F4);
    if (o != NULL) {
        o = TObjEneRecobox__ct((u8 *)o, (s32)tl_04, (u8 *)arg0);
    }
    return o;
}

extern "C" {
struct V3_80320260 { f32 x, y, z; };
struct Spawn_80320260 { s32 a, b, c, d; };
struct Inner_80320260 { u8 pad[0x18]; s32 f18; NJS_TEXLIST *texlist; };
struct Box_80320260 { u8 pad[0x42C]; Inner_80320260 *f42C; s32 f430; };
struct Sub_80320260 { u8 pad[0xC]; f32 f0C; };

s32 is_split_screen(void *);
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
s32 load_enemy_bml_resource(u8 *arg0);
extern Spawn_80320260 recobox_resource_binding_desc;
extern "C" u8 lbl_80476118[];
extern "C" u8 lbl_80476124[];
extern "C" u8 lbl_80476134[];
extern "C" u8 lbl_80476144[];
extern "C" u8 lbl_8047615C[];
extern "C" u8 lbl_80476174[];
extern "C" u8 lbl_8047618C[];
extern "C" u8 lbl_804761A4[];
extern "C" u8 lbl_804761C0[];
extern "C" u8 lbl_804761D8[];
extern "C" u8 lbl_804761F4[];
extern "C" u8 lbl_80476208[];
extern "C" u8 lbl_80476220[];
extern "C" u8 lbl_80476234[];
extern "C" u8 lbl_8047624C[];
extern "C" u8 lbl_80476260[];
extern "C" u8 lbl_80476274[];
extern "C" u8 lbl_80476288[];
extern "C" u8 lbl_80476298[];
extern "C" u8 lbl_804762AC[];
#define lbl_804EC684 (*(Sub_80320260 *)lbl_804EC684)
V3_80320260 lbl_80543000;
s32 lbl_805D6B1C;

#pragma dont_inline off
#pragma inline_depth(4)
static inline f32 getf_80320260(Sub_80320260 *p) { return p->f0C; }
void TObjEneRecobox::load_resources() {
    Box_80320260 *box;

    lbl_80543000.x = lbl_805DF46C;
    lbl_80543000.y = lbl_805DF46C;
    lbl_80543000.z = lbl_805DF46C;
    {
        u32 res;
        if (is_split_screen(&lbl_80543000) != 0) {
            res = load_enemy_bml_resource((u8 *)lbl_804EC750);
        } else {
            res = load_enemy_bml_resource((u8 *)lbl_804EC6F8);
        }
        (*(u32 *)&TObjEneRecobox__static_instance) = res;
    }
    recobox_boss_register_id = register_boss__6TLobbyFl(0x41);
    lbl_805D6B14 = dispatch_shared_handler_b__6TLobbyFl(0x41);
    TObjEneRecobox__shared_object_handle = register_object__6TLobbyFl(0x41);
    lbl_805D6B1C = dispatch_shared_handler_a__6TLobbyFl(0x41);
    TObjEneRecon::load_resources();
    {
        Sub_80320260 *sp = &lbl_804EC684;
        Spawn_80320260 s = recobox_resource_binding_desc;
        box = (Box_80320260 *)(*(u32 *)&TObjEneRecobox__static_instance);
        s.a = box->f430;
        TLobby::spawn_npc_enemy((s16)0xD, box->f42C->f18, box->f42C->texlist, &s, (f32)(getf_80320260(sp)), (f32)lbl_805DF46C);
    }
}

}
}
