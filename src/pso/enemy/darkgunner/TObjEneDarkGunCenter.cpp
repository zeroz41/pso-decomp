#include "types.h"
#include "pso/enemy/darkgunner/TObjEneDarkGunCenter.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/TObjControl.h"
#include "pso/enemy/darkgunner/DarkGunner.h"
struct EBase_800A0798 { u8 pad[0x18]; };

struct Ent_800A0798 : EBase_800A0798 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
};



struct Player_800A0994 {
    u8 pad0[0x28];
    s16 f28;
    u8 pad2A[0x354 - 0x2A];
    f32 f354;
    u8 pad358[0x428 - 0x358];
    u16 f428;
};

struct Ene_800A0994 {
    u8 pad0[0x358];
    f32 f358;
};

struct Gunner_800A0994 {
    u8 pad0[0x1C];
    u16 f1C;
    u8 pad1E[0x28 - 0x1E];
    s16 f28;
    u8 pad2A[0x354 - 0x2A];
    f32 f354;
    u8 pad358[0x37C - 0x358];
    s32 count;
    u8 pad380[0x384 - 0x380];
    u16 ids[16];
};


extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();

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
    s32 sel;
    u16 ids[16];
    s32 f3a4;
};

extern "C" {
u16 find_nearest_visible_player(void *, s32, f32);
f32 atan2_float(f32, f32);
void queue_destruction__7TObjectFv(void *);
void TObjPlayer__sub_800A0654(void *);
s32 TObjPlayer__sub_800A06B4(void *);
void fn_800A0798(Gun_800A0B20 *self);
s32 fn_800A0884(Gun_800A0B20 *o);
void TObjEneDarkGunCenter__sub_800A0B18(void);
void run_task__20TObjEneDarkGunCenterFv(Gun_800A0B20 *self);
void TObjEneDarkGunCenter__sub_800A0E7C(void);
void TObjEneDarkGunCenter__sub_800A0E80(void);
void *__dt__20TObjEneDarkGunCenterFv(void *arg0, s16 arg1);
void *__ct__11TObjControlFP7TObject(void *, void *);
u8 *TObjEneDarkGunCenter__ct(u8 *arg0, s32 arg1, s32 arg2);
void __dl__7TObjectFPv(void *);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

int get_player_data__10TObjPlayerFi(int a0);
s16 get_entity_id(void *);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
extern const char *TObjEneDarkGunner__class_name;
extern s32 registered_player_count;
extern s32 lbl_805D5870;

void fn_800A0798(Gun_800A0B20 *self) {
    s32 i;
    self->timer = 0x1a4;
    self->state = 5;
    for (i = 0; i < self->count; i++) {
        Ent_800A0798 *e = (Ent_800A0798 *)get_enemy_entity(self->ids[i]);
        if (e != 0) {
            e->v58();
        }
    }
}

void TObjEneDarkGunCenter::hide_linked_enemies() {
    Gun_800A0B20 *self = (Gun_800A0B20 *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        void *e = get_enemy_entity(self->ids[i]);
        if (e != 0) {
            ((TObjPlayer *)e)->set_hidden_flag();
        }
    }
    self->timer = 0x78;
    self->state = 4;
}

s32 fn_800A0884(Gun_800A0B20 *o) {
    void *ents[16];
    s32 n;
    s32 i;
    s32 j;
    n = 0;
    for (i = 0; i < o->count; i++) {
        ents[i] = get_enemy_entity(o->ids[i]);
        if (ents[i] != NULL) {
            n++;
        }
    }
    if (n == 0) {
        return 0;
    }
    do {
        o->sel++;
        if (o->sel >= o->count) {
            o->sel = 0;
        }
    } while (ents[o->sel] == NULL);
    for (j = 0; j < o->count; j++) {
        if (ents[j] != NULL) {
            if (j == o->sel) {
                fn_800A0FDC((TObjEneLappy *)((u8 *)ents[j]));
            } else {
                clear_lappy_flag_set_param((TObjEneLappy *)((u8 *)ents[j]));
            }
        }
    }
    return 1;
}

void TObjEneDarkGunCenter::sub_800A0994() {
    Gunner_800A0994 *self = (Gunner_800A0994 *)this;
    s32 k;
    Ene_800A0994 *a;
    Player_800A0994 *p;
    s32 m;
    Ene_800A0994 *b;
    s32 i;
    s32 j;
    self->count = 0;
    for (k = registered_player_count; k < registered_player_count + lbl_805D5870; k++) {
        p = (Player_800A0994 *)get_player_data__10TObjPlayerFi(k);
        if (p != NULL && check_value_equals__13TUnk_804B6C24Fl(p, (s32)TObjEneDarkGunner__class_name) != 0 &&
            self->f354 == p->f354 && self->f28 == p->f28) {
            p->f428 = self->f1C;
            self->ids[self->count++] = get_entity_id(p);
            if (self->count >= 16) {
                break;
            }
        }
    }
    for (m = self->count; m < 16; m++) {
        self->ids[m] = 0xFFFF;
    }
    for (i = 0; i < self->count - 1; i++) {
        for (j = i + 1; j < self->count; j++) {
            a = (Ene_800A0994 *)get_enemy_entity(self->ids[i]);
            b = (Ene_800A0994 *)get_enemy_entity(self->ids[j]);
            if (a != NULL && b != NULL && a->f358 > b->f358) {
                u16 t = self->ids[i];
                self->ids[i] = self->ids[j];
                self->ids[j] = t;
            }
        }
    }
}

void TObjEneDarkGunCenter__sub_800A0B18(void) {  }
void TObjEneDarkGunCenter::render() {  }

extern void *tl_04;

void vfunc_6__8TObjBaseFPsl();
void vfunc_29__9TObjCharaFv();
void recalc_stats__9TObjCharaFv();
void vfunc_28__9TObjCharaFv();
void consume_timer_field__9TObjCharaFl();
void vfunc_67__9TObjCharaFf();
void vfunc_66__9TObjCharaFv();
void get_anim_node_position__9TObjCharaFlP3Vec();
void vfunc_63__9TObjCharaFv();
void vfunc_62__9TObjCharaFv();
void vfunc_61__9TObjCharaFv();
void vfunc_60__9TObjCharaFv();
void vfunc_59__9TObjCharaFv();
void vfunc_58__9TObjCharaFv();
void apply_slow_status__9TObjCharaFv();
void update_shock_clock__9TObjCharaFv();
void vfunc_43__9TObjCharaFv();
void vfunc_18__9TObjCharaFPUc();
void interact__14TObjCollidableFl();
void vfunc_74__9TObjEnemyFl();
void apply_hit_message_flags__9TObjEnemyFPv();
void add_actor_exp__9TObjCharaFl();
void apply_action_hold_status__9TObjCharaFf();
void apply_anti_technique__9TObjCharaFl();
void apply_attack_stat_status__9TObjCharaFPv();
void apply_confusion_status__9TObjCharaFv();
void apply_knockback_from_attacker__9TObjCharaFPUcf();
void apply_movement_ailment__9TObjCharaFl();
void apply_object_set_data__8TObjBaseFPv();
void apply_paralysis__9TObjCharaFv();
void apply_poison_status__9TObjCharaFv();
void apply_set_data__9TObjEnemyFPv();
void apply_shock_status__9TObjCharaFv();
void apply_switch_attack__9TObjCharaFv();
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
void vfunc_79__9TObjEnemyFPl();
void classify_actor_view_detail__8TObjBaseFfff();
void clear_all_status_effects__9TObjCharaFv();
void clear_harmful_statuses__9TObjCharaFv();
void cure_paralysis__9TObjCharaFv();
void cure_poison_ailment__9TObjCharaFv();
void enemy_spawn_jellen_effect__9TObjCharaFv();
void enemy_spawn_zalure_effect__9TObjCharaFv();
void vfunc_78__9TObjCharaFl();
void vfunc_77__9TObjCharaFv();
void vfunc_76__9TObjCharaFf();
void vfunc_75__9TObjCharaFf();
void clear_lobby_object_state__9TObjEnemyFv();
void get_center__9TObjCharaFv();
void get_actor_level_index__9TObjCharaFv();
void get_name__9TObjEnemyFv();
void get_pos__9TObjCharaFl();
void is_actor_cadence_frame__9TObjCharaFl();
void is_target_in_attack_range__9TObjCharaFv();
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
void receive_physical_attack__9TObjCharaFPvf();
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
void render_shadows__9TObjEnemyFv(u8 *arg0);
void reset_motion_fields__9TObjCharaFv();
void reset_pose__9TObjCharaFv();
void roll_physical_accuracy__9TObjCharaFPvlf();
void select_melee_contact_body__9TObjCharaFPvf();
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void try_start_action__9TObjCharaFll();
void update_action_hold_status__9TObjCharaFv();
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
void update_actor_ground_y__9TObjCharaFv();
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void update_flag30_timer__9TObjCharaFv();
void update_movement_status__9TObjCharaFv();
void update_object_view_visibility__8TObjBaseFff();
void update_poison_status__9TObjCharaFv();

void *__vt__20TObjEneDarkGunCenter[83] = {
    0,
    0,
    (void *)__dt__20TObjEneDarkGunCenterFv,
    (void *)run_task__20TObjEneDarkGunCenterFv,
    (void *)&render__20TObjEneDarkGunCenterFv,
    (void *)render_shadows__9TObjEnemyFv,
    (void *)vfunc_6__8TObjBaseFPsl,
    (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__9TObjCharaFv,
    (void *)get_center__9TObjCharaFv,
    (void *)update_object_view_visibility__8TObjBaseFff,
    (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__9TObjEnemyFv,
    (void *)interact__14TObjCollidableFl,
    (void *)add_actor_exp__9TObjCharaFl,
    (void *)consume_timer_field__9TObjCharaFl,
    (void *)get_actor_level_index__9TObjCharaFv,
    (void *)update_actor_ground_y__9TObjCharaFv,
    (void *)vfunc_18__9TObjCharaFPUc,
    (void *)is_actor_cadence_frame__9TObjCharaFl,
    (void *)select_melee_contact_body__9TObjCharaFPvf,
    (void *)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf,
    (void *)receive_physical_attack__9TObjCharaFPvf,
    (void *)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__9TObjCharaFPvPv,
    (void *)apply_knockback_from_attacker__9TObjCharaFPUcf,
    (void *)try_start_action__9TObjCharaFll,
    (void *)roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)vfunc_28__9TObjCharaFv,
    (void *)vfunc_29__9TObjCharaFv,
    (void *)is_target_in_attack_range__9TObjCharaFv,
    (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv,
    (void *)&has_flag_0x800__9TObjCharaFv,
    (void *)&test_flag_1000__9TObjCharaFv,
    (void *)update_poison_status__9TObjCharaFv,
    (void *)update_action_hold_status__9TObjCharaFv,
    (void *)vfunc_37__9TObjCharaFv,
    (void *)update_flag30_timer__9TObjCharaFv,
    (void *)update_movement_status__9TObjCharaFv,
    (void *)update_shock_clock__9TObjCharaFv,
    (void *)update_attack_stat_status__9TObjCharaFv,
    (void *)update_defense_stat_status__9TObjCharaFv,
    (void *)vfunc_43__9TObjCharaFv,
    (void *)apply_poison_status__9TObjCharaFv,
    (void *)apply_paralysis__9TObjCharaFv,
    (void *)apply_slow_status__9TObjCharaFv,
    (void *)apply_confusion_status__9TObjCharaFv,
    (void *)apply_movement_ailment__9TObjCharaFl,
    (void *)apply_shock_status__9TObjCharaFv,
    (void *)clear_harmful_statuses__9TObjCharaFv,
    (void *)apply_attack_stat_status__9TObjCharaFPv,
    (void *)apply_defense_stat_status__9TObjCharaFPv,
    (void *)cure_poison_ailment__9TObjCharaFv,
    (void *)cure_paralysis__9TObjCharaFv,
    (void *)clear_all_status_effects__9TObjCharaFv,
    (void *)apply_action_hold_status__9TObjCharaFf,
    (void *)apply_anti_technique__9TObjCharaFl,
    (void *)vfunc_58__9TObjCharaFv,
    (void *)vfunc_59__9TObjCharaFv,
    (void *)vfunc_60__9TObjCharaFv,
    (void *)vfunc_61__9TObjCharaFv,
    (void *)vfunc_62__9TObjCharaFv,
    (void *)vfunc_63__9TObjCharaFv,
    (void *)reset_pose__9TObjCharaFv,
    (void *)get_anim_node_position__9TObjCharaFlP3Vec,
    (void *)vfunc_66__9TObjCharaFv,
    (void *)vfunc_67__9TObjCharaFf,
    (void *)get_pos__9TObjCharaFl,
    (void *)apply_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_jellen_effect__9TObjCharaFv,
    (void *)trigger_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_zalure_effect__9TObjCharaFv,
    (void *)recalc_stats__9TObjCharaFv,
    (void *)vfunc_74__9TObjEnemyFl,
    (void *)vfunc_75__9TObjCharaFf,
    (void *)vfunc_76__9TObjCharaFf,
    (void *)vfunc_77__9TObjCharaFv,
    (void *)vfunc_78__9TObjCharaFl,
    (void *)vfunc_79__9TObjEnemyFPl,
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
            id = find_nearest_visible_player(self, 0, 1000.0f);
            if (id != 0xFFFF) {
                self->target = (u8 *)get_player_by_client_id(id);
                ang = (s32)(10430.38043493439 * atan2_float(*(f32 *)(self->target + 0x40) - self->f40, *(f32 *)(self->target + 0x38) - self->f38)) + 0x4000;
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
        if (find_nearest_visible_player(self, 0, 1000.0f) != 0xFFFF) {
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
            if ((f32)(t - 1) <= -30.0f) {
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
        o = __ct__11TObjControlFP7TObject(o, tl_04);
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
