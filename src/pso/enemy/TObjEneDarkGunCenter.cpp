#include "types.h"
#include "pso/enemy/TObjEneDarkGunCenter.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();

extern "C" void render__20TObjEneDarkGunCenterFv();

struct VBase_800A0B20 { u8 pad[0x18]; };

struct Gun_800A0B20 : VBase_800A0B20 {
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
    virtual s32 m17(s32);
    u8 pad1c[0x38 - 0x1c];
    f32 f38;
    u8 pad3c[0x40 - 0x3c];
    f32 f40;
    u8 pad44[0x2a8 - 0x44];
    u8 *target;
    u8 pad2ac[0x374 - 0x2ac];
    s32 state;
    s32 timer;
    s32 count;
    u8 pad380[0x384 - 0x380];
    u16 ids[16];
    s32 f3a4;
};

extern "C" {
u16 find_nearest_visible_player(void *, s32, f32);
f32 atan2_float(f32, f32);
void queue_destruction__7TObjectFv(void *);
void TObjPlayer__sub_800A0654(void *);
s32 TObjPlayer__sub_800A06B4(void *);
void fn_800A0798(void *);
void fn_800A0884(void *);
void TObjEneDarkGunCenter__sub_800A0B18(void);
u8 *get_enemy_entity(u16);
void *get_player_by_client_id(s32 i);
extern const f64 lbl_8043A488[];
extern const f32 lbl_805D9970;
extern const f32 lbl_805D9974;
void run_task__20TObjEneDarkGunCenterFv(Gun_800A0B20 *self);
void TObjEneDarkGunCenter__sub_800A0E7C(void);
void TObjEneDarkGunCenter__sub_800A0E80(void);
void *__dt__20TObjEneDarkGunCenterFv(void *arg0, s16 arg1);
void *TObjControl__ct(void *, void *);
u8 *TObjEneDarkGunCenter__ct(u8 *arg0, s32 arg1, s32 arg2);
void __dl__7TObjectFPv(void *);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void TObjEneDarkGunCenter__sub_800A0B18(void) {  }
void TObjEneDarkGunCenter::render() {  }

extern void *tl_04;

void vfunc_6__13TUnk_804B9870FPsl();
void vfunc_29__13TUnk_804806E8Fv();
void vfunc_73__13TUnk_804806E8Fv();
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
void vfunc_74__9TObjEnemyFl();
void apply_hit_message_flags__9TObjEnemyFPv();
void add_actor_exp__13TUnk_804806E8Fl();
void apply_action_hold_status__13TUnk_804806E8Ff();
void apply_anti_technique__13TUnk_804806E8Fl();
void apply_attack_stat_status__13TUnk_804806E8FPv();
void apply_confusion_status__13TUnk_804806E8Fv();
void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
void apply_movement_ailment__13TUnk_804806E8Fl();
void apply_object_set_data__13TUnk_804B9870FPv();
void apply_paralysis__13TUnk_804806E8Fv();
void apply_poison_status__13TUnk_804806E8Fv();
void apply_set_data__9TObjEnemyFPv();
void apply_shock_status__13TUnk_804806E8Fv();
void apply_switch_attack__13TUnk_804806E8Fv();
void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
void vfunc_79__9TObjEnemyFv();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void clear_all_status_effects__13TUnk_804806E8Fv();
void clear_harmful_statuses__13TUnk_804806E8Fv();
void cure_paralysis__13TUnk_804806E8Fv();
void cure_poison_ailment__13TUnk_804806E8Fv();
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
void vfunc_78__13TUnk_804806E8Fl();
void vfunc_77__13TUnk_804806E8Fv();
void vfunc_76__13TUnk_804806E8Fv();
void vfunc_75__13TUnk_804806E8Ff();
void clear_lobby_object_state__9TObjEnemyFv();
void vfunc_9__13TUnk_804806E8Fv();
void get_actor_level_index__13TUnk_804806E8Fv();
void get_name__9TObjEnemyFv();
void get_pos__13TUnk_804806E8Fl();
void is_actor_cadence_frame__13TUnk_804806E8Fl();
void is_target_in_attack_range__13TUnk_804806E8Fv();
void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
void receive_physical_attack__13TUnk_804806E8FPvf();
void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
void render_shadows__9TObjEnemyFv(u8 *arg0);
void reset_motion_fields__13TUnk_804806E8Fv();
void reset_pose__13TUnk_804806E8Fv();
void roll_physical_accuracy__13TUnk_804806E8FPvlf();
void select_melee_contact_body__13TUnk_804806E8FPvf();
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
void try_start_action__13TUnk_804806E8Fll();
void update_action_hold_status__13TUnk_804806E8Fv();
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
void update_actor_ground_y__13TUnk_804806E8Fv();
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
void update_flag30_timer__13TUnk_804806E8Fv();
void update_movement_status__13TUnk_804806E8Fv();
void update_object_view_visibility__13TUnk_804B9870Fff();
void update_poison_status__13TUnk_804806E8Fv();

void *__vt__20TObjEneDarkGunCenter[83] = {
    0,
    0,
    (void *)__dt__20TObjEneDarkGunCenterFv,
    (void *)run_task__20TObjEneDarkGunCenterFv,
    (void *)&render__20TObjEneDarkGunCenterFv,
    (void *)render_shadows__9TObjEnemyFv,
    (void *)vfunc_6__13TUnk_804B9870FPsl,
    (void *)apply_object_set_data__13TUnk_804B9870FPv,
    (void *)reset_motion_fields__13TUnk_804806E8Fv,
    (void *)vfunc_9__13TUnk_804806E8Fv,
    (void *)update_object_view_visibility__13TUnk_804B9870Fff,
    (void *)classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)get_name__9TObjEnemyFv,
    (void *)interact__13TUnk_804AF8A0Fl,
    (void *)add_actor_exp__13TUnk_804806E8Fl,
    (void *)consume_timer_field__13TUnk_804806E8Fl,
    (void *)get_actor_level_index__13TUnk_804806E8Fv,
    (void *)update_actor_ground_y__13TUnk_804806E8Fv,
    (void *)vfunc_18__13TUnk_804806E8FPUc,
    (void *)is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)select_melee_contact_body__13TUnk_804806E8FPvf,
    (void *)calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf,
    (void *)receive_physical_attack__13TUnk_804806E8FPvf,
    (void *)receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__13TUnk_804806E8FPvPv,
    (void *)apply_knockback_from_attacker__13TUnk_804806E8FPUc,
    (void *)try_start_action__13TUnk_804806E8Fll,
    (void *)roll_physical_accuracy__13TUnk_804806E8FPvlf,
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
    (void *)vfunc_73__13TUnk_804806E8Fv,
    (void *)vfunc_74__9TObjEnemyFl,
    (void *)vfunc_75__13TUnk_804806E8Ff,
    (void *)vfunc_76__13TUnk_804806E8Fv,
    (void *)vfunc_77__13TUnk_804806E8Fv,
    (void *)vfunc_78__13TUnk_804806E8Fl,
    (void *)vfunc_79__9TObjEnemyFv,
    (void *)apply_hit_message_flags__9TObjEnemyFPv,
    (void *)apply_set_data__9TObjEnemyFPv,
    (void *)clear_lobby_object_state__9TObjEnemyFv,
};

void TObjEneDarkGunCenter::run_task() {
    Gun_800A0B20 *self = (Gun_800A0B20 *)this;
    s32 ang;
    s32 i;
    s32 off;
    s32 t;
    s32 id;
    u8 *e;
    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(void *))TObjEneDarkGunCenter__sub_800A0B18)(self);
        return;
    }
    ((TObjEneDarkGunCenter *)self)->sub_800A0994();
    switch (self->state) {
    case 0:
        if (self->m17(0x1e) != 0) {
            id = find_nearest_visible_player(self, 0, lbl_805D9970);
            if (id != 0xFFFF) {
                self->target = (u8 *)get_player_by_client_id(id);
                ang = (s32)(lbl_8043A488[0] * atan2_float(*(f32 *)(self->target + 0x40) - self->f40, *(f32 *)(self->target + 0x38) - self->f38)) + 0x4000;
                for (i = 0; i < self->count; i++) {
                    e = get_enemy_entity(self->ids[i]);
                    if (e != NULL) {
                        *(s32 *)(e + 0x60) = ang;
                    }
                    ang += 0x1555;
                }
                self->timer = 0x5a;
                self->state = 1;
            } else {
                TObjPlayer__sub_800A0654(self);
            }
        }
        break;
    case 1:
        self->timer--;
        if (self->timer <= 0) {
            ((TObjEneDarkGunCenter *)self)->hide_linked_enemies();
            self->timer = 0xd2;
            self->state = 2;
        }
        break;
    case 2:
        self->timer--;
        if (TObjPlayer__sub_800A06B4(self) != 0 || self->timer <= 0) {
            self->state = 3;
        }
        break;
    case 3:
        if (find_nearest_visible_player(self, 0, lbl_805D9970) != 0xFFFF) {
            ((TObjEneDarkGunCenter *)self)->hide_linked_enemies();
            fn_800A0884(self);
        } else {
            self->state = 0;
        }
        break;
    case 4:
        self->timer--;
        if (self->timer <= 0) {
            fn_800A0798(self);
        }
        break;
    case 5:
        self->timer--;
        if (self->timer <= 0) {
            self->state = 3;
        }
        break;
    case 6:
        self->timer--;
        if (self->timer <= 0) {
            self->state = 3;
        }
        break;
    }
    t = self->f3a4;
    if (t < 0) {
        if (self->count > 0) {
            self->f3a4 = 0x5a;
        } else {
            self->f3a4 = t - 1;
            if ((f32)(t - 1) <= lbl_805D9974) {
                self->f3a4 = 0x5a;
            }
        }
    } else {
        if (self->count > 0) {
            self->f3a4 = 0x5a;
        } else if ((self->f3a4 = t - 1) <= 0) {
            ((TObjEnemy *)self)->send_entity_set_flags();
            queue_destruction__7TObjectFv(self);
        }
    }
}

void *TObjEneDarkGunCenter::create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3A8);
    if (o2 != NULL) {
        o2 = TObjEneDarkGunCenter__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjEneDarkGunCenter__sub_800A0E7C(void) {  }
void TObjEneDarkGunCenter__sub_800A0E80(void) {  }

extern void *__vt__20TObjEneDarkGunCenter[];

void *__dt__20TObjEneDarkGunCenterFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__20TObjEneDarkGunCenter;
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
