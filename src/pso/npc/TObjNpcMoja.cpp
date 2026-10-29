#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/npc/TObjNpcMoja.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();

#include "pso/npc/TObjNpcNFM00.h"
#include "pso/misc/TLobby.h"

#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct VBase_8014C780 { char pad[0x18]; };
struct VObj_8014C780 : VBase_8014C780 {
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
    virtual s32 m79(s32);
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual s32 m85(s32, s32);
};

s32 create_named_object(s32 arg0);
extern "C" {
u8 *load_gvm_texture_file(s32 arg0);
extern u32 TObjNpcNFM00__shared_named_model_object;
extern u32 TObjNpcNFM00__texture_gvm_handle;
extern char lbl_8043FD20[];
extern char lbl_8043FD34[];
void * TObjNpcNFM00__create(void *arg0);
void *dt__11TObjNpcMojaFPvs(void *arg0, s16 arg1);
void release_texture_list(void*);
void *__ct__11TObjControlFP7TObject(void *, void *);
void *TObjNpcMoja__ct(void *, void *, void *);
u8 *TObjNpcNFM00__ct(u8 *arg0, s32 arg1, s32 arg2);
void __dl__7TObjectFPv(void *);
void *__dt__11TObjNpcBaseFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
void TObjNpcBase__ct(void *, void *);
void init_collision_body_parts(void *, void *, s32);
extern u8 npc_default_battle_stats[];
extern u8 npc_movement_parameters[];
extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void draw_debug_info__11TObjNpcBaseFv();
extern "C" void is_target_in_attack_range__11TObjNpcBaseFv();
extern "C" void vfunc_92__11TObjNpcBaseFv();
extern "C" void vfunc_91__11TObjNpcBaseFv();
extern "C" void debug_draw_talk__11TObjNpcBaseFv();
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void vfunc_63__9TObjCharaFv();
extern "C" void vfunc_62__9TObjCharaFv();
extern "C" void vfunc_61__9TObjCharaFv();
extern "C" void vfunc_60__9TObjCharaFv();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void vfunc_83__11TObjNpcBaseFv();
extern "C" void vfunc_58__11TObjNpcBaseFv();
extern "C" void vfunc_88__11TObjNpcMojaFv();
extern "C" void vfunc_59__11TObjNpcBaseFv();
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
extern "C" void apply_set_params__11TObjNpcBaseFll();
extern "C" void apply_shock_status__9TObjCharaFv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void vfunc_79__9TObjEnemyFPl();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void draw_if_visible__10TObjPlayerFv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void vfunc_77__9TObjCharaFv();
extern "C" void vfunc_76__9TObjCharaFv();
extern "C" void vfunc_75__9TObjCharaFf();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void handle_message_event__17TObjNpcFemaleBaseFUs();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void play_voice__11TObjNpcBaseFv();
extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__9TObjCharaFPvf();
extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void run_task__11TObjNpcBaseFv(u8 *arg0);
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__9TObjCharaFv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *arg0);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void vfunc_28__11TObjNpcBaseFv();
extern "C" void update_conversation__11TObjNpcBaseFv();
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_movement_status__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern "C" void update_standing__11TObjNpcBaseFv();
extern "C" void update_wandering__11TObjNpcBaseFv();
void *lbl_804AABB8[8] = {
    (void *)0x10000, (void *)0x0, (void *)0x3f000000, (void *)0x1,
    (void *)0x10000, (void *)0x1, (void *)0x3f19999a, (void *)0x1,
};
void *lbl_804AABD8[11] = {
    (void *)0x0, (void *)0x40f00000, (void *)0x0, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x30203, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *__vt__11TObjNpcMoja[95] = {
    (void *)0x0, (void *)0x0, (void *)&dt__11TObjNpcMojaFPvs, (void *)&run_task__11TObjNpcBaseFv,
    (void *)&draw_if_visible__10TObjPlayerFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&handle_message_event__17TObjNpcFemaleBaseFUs, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__11TObjNpcBaseFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__11TObjNpcBaseFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__11TObjNpcBaseFv, (void *)&vfunc_59__11TObjNpcBaseFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__9TObjCharaFv, (void *)&vfunc_62__9TObjCharaFv, (void *)&vfunc_63__9TObjCharaFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEnemyFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__11TObjNpcBaseFv,
    (void *)&update_standing__11TObjNpcBaseFv, (void *)&update_wandering__11TObjNpcBaseFv, (void *)&update_conversation__11TObjNpcBaseFv, (void *)&apply_set_params__11TObjNpcBaseFll,
    (void *)&vfunc_88__11TObjNpcMojaFv, (void *)&debug_draw_talk__11TObjNpcBaseFv, (void *)&play_voice__11TObjNpcBaseFv, (void *)&vfunc_91__11TObjNpcBaseFv,
    (void *)&vfunc_92__11TObjNpcBaseFv, (void *)&draw_debug_info__11TObjNpcBaseFv, (void *)0x0,
};
extern s32 TObjNpcMoja__name;
extern u8 *lbl_805D50D8;

extern void *tl_04;

void *TObjNpcMoja::create(void *arg2v) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcMoja__ct(o2, o, arg2v);
    }
    return o2;
}

void *dt__11TObjNpcMojaFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__11TObjNpcMoja;
        __dt__11TObjNpcBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define self ((u8 *)selfv)
#define arg2 ((s32)arg2v)
void *TObjNpcMoja__ct(void *selfv, void *parent, void *arg2v) {
    TObjNpcBase__ct(self, parent);
    *(u8 **)(self + 0x18) = (u8 *)__vt__11TObjNpcMoja;
    *(s32 *)(self + 0) = TObjNpcMoja__name;
    ((VObj_8014C780 *)self)->m79(arg2);
    ((TObjPlayer *)self)->init_position_vectors();
    ((VObj_8014C780 *)self)->m85(0, 1);
    *(s32 *)(self + 0x34) = get_bml_model(lbl_805D50D8, 0);
    *(s32 *)(self + 0x24) = TObjFish__sub_8001EDB0(lbl_805D50D8, 0);
    ((TObjMotion *)self)->init_motion((TObjMotionAction *)lbl_804AABB8, (BmlMotionEntry *)*(s32 *)(lbl_805D50D8 + 0x430), *(s16 *)(self + 0xB8));
    *(u8 **)(self + 0x350) = npc_movement_parameters;
    ((TObjChara *)self)->set_motion_params(npc_default_battle_stats);
    init_collision_body_parts(self, lbl_804AABD8, 1);
    ((TObjPlayer *)self)->register_object_by_id();
    ((TObjEnemy *)self)->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    return self;
}

#undef self
#undef arg2

void * TObjNpcNFM00__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcNFM00__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjNpcNFM00::free_resources() {
    if ((u32) TObjNpcNFM00__texture_gvm_handle != 0U) {
        release_texture_list((void*)TObjNpcNFM00__texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcNFM00__texture_gvm_handle);
        TObjNpcNFM00__texture_gvm_handle = 0U;
    }
    if ((u32) TObjNpcNFM00__shared_named_model_object != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TObjNpcNFM00__shared_named_model_object));
        TObjNpcNFM00__shared_named_model_object = 0U;
    }
}
void TObjNpcNFM00::load_assets() {
    TObjNpcNFM00__shared_named_model_object = (u32)create_named_object((s32)lbl_8043FD20);
    TObjNpcNFM00__texture_gvm_handle = (u32)load_gvm_texture_file((s32)lbl_8043FD34);
}
}
