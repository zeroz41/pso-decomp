#include "types.h"
#include "pso/TObject.h"
#include "pso/misc/TOMine.h"
#include "pso/misc/TOMineIcon04.h"
#include "pso/misc/TOMineTrap.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/map/CurrentArea.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();

extern "C" void get_name__6TOMineFv();

#include "pso/misc/TOKeyMachine01.h"

struct Base_80171E7C { char pad[0x18]; };

struct VIcon_80171E7C : Base_80171E7C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4();
    virtual void m5(void *);
};

struct Icon_80171E7C {
    s32 f0;
    u8 pad4[0x18 - 4];
    void **vt;
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x30 - 0x28];
    u32 f30;
    s32 f34;
    u8 pad38[0x68 - 0x38];
    f32 f68;
    f32 f6C;
    u8 pad70[0x84 - 0x70];
    s32 f84;
    s32 f88;
    s32 f8C;
    u8 pad90[0x326 - 0x90];
    s16 f326;
    u8 pad328[0x34C - 0x328];
    f32 f34C;
    f32 f350;
    s32 f354;
    f32 f358;
    u16 f35C;
    u8 pad35E[0x374 - 0x35E];
    s32 f374;
    s32 f378;
};

extern "C" {
s32 play_sound_effect(int, void *, int, int);
void vfunc_80__12TOMineIcon04Fv(s32 arg0);
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
void init_collision_body_parts(void *, void *, s32);
void TOMine__ct(void *, void *, void *);
extern u8 mine_collision_body_parts[];
extern void *__vt__12TOMineIcon04[];
extern s32 TOMineIcon04__name;
extern s32 game_difficulty_selection;
extern void *lbl_805D5A50;
extern const f32 lbl_805DB8D8;
extern const f32 lbl_805DB8DC;
extern const f32 lbl_805DB8E0;
extern const f32 lbl_805DB8E4;
extern const f32 lbl_805DB8E8;
void *TOMineIcon04__ct(void *arg0, void *arg1, void *arg2);
int vfunc_82__12TOMineIcon04Fv(void* p);
void vfunc_84__12TOMineIcon04Fv(void);
void *__dt__12TOMineIcon04Fv(void *arg0, s16 arg1);
void *spawn_particle_effect(void *pos, s32 id);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__dt__6TOMineFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void TOMineIcon04::vfunc_84() {  }
void TOMineIcon04::vfunc_82() { spawn_particle_effect((char*)this + 0x2fc, 140); }

extern void *tl_05;

void roll_physical_accuracy__6TOMineFPvlf();
void try_start_action__6TOMineFll();
void apply_knockback_from_attacker__6TOMineFPUc();
void vfunc_79__6TOMineFv();
void spawn_disp_objects__6TOMineFv(u8 *arg0);
void apply_object_set_data__6TOMineFPv();
void vfunc_85__6TOMineFv();
void vfunc_6__6TOMineFPsl();
void receive_direct_attack__6TOMineFPv19DirectAttackPayloadPvll();
void vfunc_86__6TOMineFv();
void render__6TOMineFv();
void vfunc_29__13TUnk_804806E8Fv();
void vfunc_74__13TUnk_804806E8Fl();
void recalc_stats__13TUnk_804806E8Fv();
void vfunc_28__13TUnk_804806E8Fv();
void consume_timer_field__13TUnk_804806E8Fl();
void vfunc_67__13TUnk_804806E8Ff();
void vfunc_66__13TUnk_804806E8Fv();
void get_anim_node_position__13TUnk_804806E8FlP3Vec();
void vfunc_63__13TUnk_804806E8Fv();
void vfunc_62__13TUnk_804806E8Fv();
void vfunc_61__13TUnk_804806E8Fv();
void vfunc_60__13TUnk_804806E8Fv();
void vfunc_59__13TUnk_804806E8Fv();
void vfunc_58__13TUnk_804806E8Fv();
void apply_slow_status__13TUnk_804806E8Fv();
void update_shock_clock__13TUnk_804806E8Fv();
void vfunc_43__13TUnk_804806E8Fv();
void vfunc_18__13TUnk_804806E8FPUc();
void interact__13TUnk_804AF8A0Fl();
void add_actor_exp__13TUnk_804806E8Fl();
void apply_action_hold_status__13TUnk_804806E8Ff();
void apply_anti_technique__13TUnk_804806E8Fl();
void apply_attack_stat_status__13TUnk_804806E8FPv();
void apply_confusion_status__13TUnk_804806E8Fv();
void apply_movement_ailment__13TUnk_804806E8Fl();
void apply_paralysis__13TUnk_804806E8Fv();
void apply_poison_status__13TUnk_804806E8Fv();
void apply_shock_status__13TUnk_804806E8Fv();
void apply_switch_attack__13TUnk_804806E8Fv();
void receive_weapon_special_attack__6TOMineFPvPv();
void can_trigger__10TOMineTrapFUl();
void check_trigger__10TOMineTrapFUl();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void clear_all_status_effects__13TUnk_804806E8Fv();
void clear_harmful_statuses__13TUnk_804806E8Fv();
void cure_paralysis__13TUnk_804806E8Fv();
void cure_poison_ailment__13TUnk_804806E8Fv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
void vfunc_78__13TUnk_804806E8Fl();
void vfunc_77__13TUnk_804806E8Fv();
void vfunc_76__13TUnk_804806E8Fv();
void vfunc_75__13TUnk_804806E8Ff();
void vfunc_9__13TUnk_804806E8Fv();
void get_actor_level_index__13TUnk_804806E8Fv();
void get_pos__13TUnk_804806E8Fl();
void is_actor_cadence_frame__13TUnk_804806E8Fl();
void is_target_in_attack_range__13TUnk_804806E8Fv();
void render_shadows__7TObjectFv();
void reset_motion_fields__13TUnk_804806E8Fv();
void reset_pose__13TUnk_804806E8Fv();
void run_task__6TOMineFv();
void spawn_effect__10TOMineTrapFv();
void receive_physical_attack__6TOMineFPvf();
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
void update_action_hold_status__13TUnk_804806E8Fv();
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
void update_actor_ground_y__13TUnk_804806E8Fv();
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
void update_flag30_timer__13TUnk_804806E8Fv();
void update_movement_status__13TUnk_804806E8Fv();
void update_object_view_visibility__13TUnk_804B9870Fff();
void update_poison_status__13TUnk_804806E8Fv();

void *__vt__12TOMineIcon04[87] = {
    0,
    0,
    (void *)__dt__12TOMineIcon04Fv,
    (void *)run_task__6TOMineFv,
    (void *)render__6TOMineFv,
    (void *)render_shadows__7TObjectFv,
    (void *)vfunc_6__6TOMineFPsl,
    (void *)apply_object_set_data__6TOMineFPv,
    (void *)reset_motion_fields__13TUnk_804806E8Fv,
    (void *)vfunc_9__13TUnk_804806E8Fv,
    (void *)update_object_view_visibility__13TUnk_804B9870Fff,
    (void *)classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__6TOMineFv,
    (void *)interact__13TUnk_804AF8A0Fl,
    (void *)add_actor_exp__13TUnk_804806E8Fl,
    (void *)consume_timer_field__13TUnk_804806E8Fl,
    (void *)get_actor_level_index__13TUnk_804806E8Fv,
    (void *)update_actor_ground_y__13TUnk_804806E8Fv,
    (void *)vfunc_18__13TUnk_804806E8FPUc,
    (void *)is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)can_trigger__10TOMineTrapFUl,
    (void *)check_trigger__10TOMineTrapFUl,
    (void *)receive_physical_attack__6TOMineFPvf,
    (void *)receive_direct_attack__6TOMineFPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__6TOMineFPvPv,
    (void *)apply_knockback_from_attacker__6TOMineFPUc,
    (void *)try_start_action__6TOMineFll,
    (void *)roll_physical_accuracy__6TOMineFPvlf,
    (void *)vfunc_28__13TUnk_804806E8Fv,
    (void *)vfunc_29__13TUnk_804806E8Fv,
    (void *)is_target_in_attack_range__13TUnk_804806E8Fv,
    (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv,
    (void *)&has_flag_0x800__13TUnk_804806E8Fv,
    (void *)&test_flag_1000__13TUnk_804806E8Fv,
    (void *)update_poison_status__13TUnk_804806E8Fv,
    (void *)update_action_hold_status__13TUnk_804806E8Fv,
    (void *)vfunc_37__13TUnk_804806E8Fv,
    (void *)update_flag30_timer__13TUnk_804806E8Fv,
    (void *)update_movement_status__13TUnk_804806E8Fv,
    (void *)update_shock_clock__13TUnk_804806E8Fv,
    (void *)update_attack_stat_status__13TUnk_804806E8Fv,
    (void *)update_defense_stat_status__13TUnk_804806E8Fv,
    (void *)vfunc_43__13TUnk_804806E8Fv,
    (void *)apply_poison_status__13TUnk_804806E8Fv,
    (void *)apply_paralysis__13TUnk_804806E8Fv,
    (void *)apply_slow_status__13TUnk_804806E8Fv,
    (void *)apply_confusion_status__13TUnk_804806E8Fv,
    (void *)apply_movement_ailment__13TUnk_804806E8Fl,
    (void *)apply_shock_status__13TUnk_804806E8Fv,
    (void *)clear_harmful_statuses__13TUnk_804806E8Fv,
    (void *)apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)apply_defense_stat_status__13TUnk_804806E8FPv,
    (void *)cure_poison_ailment__13TUnk_804806E8Fv,
    (void *)cure_paralysis__13TUnk_804806E8Fv,
    (void *)clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)apply_action_hold_status__13TUnk_804806E8Ff,
    (void *)apply_anti_technique__13TUnk_804806E8Fl,
    (void *)vfunc_58__13TUnk_804806E8Fv,
    (void *)vfunc_59__13TUnk_804806E8Fv,
    (void *)vfunc_60__13TUnk_804806E8Fv,
    (void *)vfunc_61__13TUnk_804806E8Fv,
    (void *)vfunc_62__13TUnk_804806E8Fv,
    (void *)vfunc_63__13TUnk_804806E8Fv,
    (void *)reset_pose__13TUnk_804806E8Fv,
    (void *)get_anim_node_position__13TUnk_804806E8FlP3Vec,
    (void *)vfunc_66__13TUnk_804806E8Fv,
    (void *)vfunc_67__13TUnk_804806E8Ff,
    (void *)get_pos__13TUnk_804806E8Fl,
    (void *)apply_switch_attack__13TUnk_804806E8Fv,
    (void *)enemy_spawn_jellen_effect__13TUnk_804806E8Fv,
    (void *)trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)enemy_spawn_zalure_effect__13TUnk_804806E8Fv,
    (void *)recalc_stats__13TUnk_804806E8Fv,
    (void *)vfunc_74__13TUnk_804806E8Fl,
    (void *)vfunc_75__13TUnk_804806E8Ff,
    (void *)vfunc_76__13TUnk_804806E8Fv,
    (void *)vfunc_77__13TUnk_804806E8Fv,
    (void *)vfunc_78__13TUnk_804806E8Fl,
    (void *)vfunc_79__6TOMineFv,
    (void *)vfunc_80__12TOMineIcon04Fv,
    (void *)spawn_effect__10TOMineTrapFv,
    (void *)vfunc_82__12TOMineIcon04Fv,
    (void *)spawn_disp_objects__6TOMineFv,
    (void *)vfunc_84__12TOMineIcon04Fv,
    (void *)vfunc_85__6TOMineFv,
    (void *)vfunc_86__6TOMineFv,
};

void TOMineIcon04::vfunc_80() {
    s32 arg0 = (s32)this;
    u32 global_state;
    global_state = get_current_area();
    switch (global_state) {
    case 1:
    case 2:
        play_sound_effect(0x4C111, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 3:
    case 4:
    case 5:
        play_sound_effect(0x44110, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 6:
    case 7:
        play_sound_effect(0x4004C10A, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 8:
    case 9:
    case 10:
        play_sound_effect(0x4004C111, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 19:
    case 20:
        play_sound_effect(0x4BC07, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 21:
    case 22:
        play_sound_effect(0x4004BC07, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        play_sound_effect(0x4BC19, (void *)(arg0 + 0x38), 0, 0);
    case 28:
    case 29:
        play_sound_effect(0x4004BC19, (void *)(arg0 + 0x38), 0, 0);
    default:
        return;
    }
}

void *TOMineIcon04::create() {
    void *o = __nw__7TObjectFUl(0x37C);
    if (o != NULL) {
        o = TOMineIcon04__ct(o, tl_05, this);
    }
    return o;
}

void *__dt__12TOMineIcon04Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__12TOMineIcon04;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__6TOMineFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma fp_contract on
void *TOMineIcon04__ct(void *arg0, void *arg1, void *arg2) {
    TOMine__ct(arg0, arg1, arg2);
#define self ((Icon_80171E7C *)arg0)
    self->vt = ((void * *)&__vt__12TOMineIcon04);
    self->f0 = TOMineIcon04__name;
    ((VIcon_80171E7C *)self)->m5(arg2);
    ((TObjPlayer *)self)->init_position_vectors();
    ((TUnk_804806E8 *)self)->calc_attach_pos();
    self->f34 = get_bml_model(lbl_805D5A50, 7);
    self->f24 = TObjFish__sub_8001EDB0(lbl_805D5A50, 7);
    self->f374 = get_bml_model(lbl_805D5A50, 3);
    self->f378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 3);
    self->f326 = 0;
    if (self->f84 < 0) {
        self->f84 = 0;
    }
    if (self->f88 < 0) {
        self->f88 = 0;
    } else if (self->f88 > 5) {
        self->f88 = 5;
    }
    if (self->f8C < 0) {
        self->f8C = 0;
    }
    self->f358 = (f32)self->f84 * (lbl_805DB8DC * (f32)game_difficulty_selection + lbl_805DB8D8);
    if (game_difficulty_selection == 3) {
        self->f358 *= lbl_805DB8DC;
    }
    self->f354 = self->f88;
    self->f34C = lbl_805DB8E4 * self->f68 + lbl_805DB8E0;
    self->f350 = lbl_805DB8E4 * self->f6C + lbl_805DB8E8;
    ((TOMine *)self)->update_state();
    self->f35C = 0xFFFF;
    self->f30 |= 0x60000000;
    init_collision_body_parts(self, mine_collision_body_parts, 1);
    ((TUnk_804AF8A0 *)self)->refresh_collision_body_centers();
    ((TObjPlayer *)self)->reset_photon_effect();
    return self;
#undef self
}
#pragma pop

}
