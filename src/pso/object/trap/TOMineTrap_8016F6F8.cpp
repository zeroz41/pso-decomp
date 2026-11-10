#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/trap/TOMine.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/object/trap/TOMineDisp.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"

struct Trap_8016F704 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x84 - 0x44]; s32 delay; u8 pad88[0x2A8 - 0x88]; void *target; u8 pad2AC[0x34C - 0x2AC]; f32 range; u8 pad350[0x35C - 0x350]; u16 targetId; };

extern "C" {
s32 obj_testFlags30__14TObjCollidableFUl(void *, u32);
s32 get_current_floor(void);
f32 horizontal_distance_squared(void *, void *);
extern u8 lobby_rule_settings[];
u16 get_entity_id(void *);
extern s32 enable_v2_features;
s32 create_placed_trap__10TOMineTrapFUiss(u32 arg0, s16 arg1, s16 arg2);
s32 is_split_screen();
extern s32 local_client_id;
}

struct VBase_18_33b813
{
  char pad[0x18];
};

struct VObj_18_33b813 : VBase_18_33b813 {
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
    virtual s32 m20(s32, f32);
};

struct Stack_80170AC8
{
  f32 sp8;
  f32 spC;
  f32 sp10;
};

struct Node_801702C8 { u8 pad[0xC]; Node_801702C8 *next; };

struct VBase_18_1da615 { char pad[0x18]; };

struct VObj_18_1da615 : VBase_18_1da615 {
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
    virtual s32 m20(s32, f32);
    virtual f32 m21(void *, void *, s32, s32, s32);
    virtual void m22();
    virtual s32 m23(void *, f32);
};

extern "C" {
s32 is_locally_controlled__10TObjPlayerFPv(u32 a0);
s32 get_localized_text_entry(s32 arg0, s32 arg1);
s32 get_main_phase();
s32 play_sound_effect(s32, s32, s32, s32);
extern s8 mine_trap_effect_table[];
extern s8 mine_trap_keymachine_table[];
extern f32 lbl_805DB864;
extern const f32 lbl_805DB85C;
extern const f32 TOMineTrap__data_805DB868;
void TOMineTrap__sub_80170CD4(void* p);
void record_attack_source(void *object, u16 id);
extern const f32 lbl_805DB884;
extern const f32 lbl_805DB888;
f32 atan2_float(f32 y, f32 x);
f32 vec3_add_to(void *, void *);
f32 vec_squared_length(u8 *arg0);
f32 subtract_vector(void *, void *);
f32 normalize_vector(void *);
extern const f64 lbl_80442200;
extern const f32 lbl_805DB870;
void queue_destruction__7TObjectFv(void *arg0);
int get_player_data__10TObjPlayerFi(int a0);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
extern s32 TOMineTrap__data_805D3080;
extern s32 registered_player_count;
extern s32 lbl_805D5870;
extern s32 lbl_805D5868;
extern s32 TOMineIcon01__name;
extern s32 TOMineIcon02__name;
extern s32 TOMineIcon03__name;
extern s32 TOMineIcon04__name;
u8 *get_battle_param__10TObjPlayerFi(s32);
extern const f32 lbl_805DB874;
void *__dt__10TOMineTrapFv(void *arg0, s16 arg1);
extern s32 game_difficulty_selection;
extern BmlResource *lbl_805D5A50;
extern CollisionBody mine_collision_body_parts[];
extern f32 lbl_805D307C;
extern const f32 lbl_80442138[];
extern const f32 lbl_805DB86C;
extern const f32 lbl_805DB878;
extern const f32 lbl_805DB87C;
extern const f32 lbl_805DB880;
s32 is_locally_controlled__10TObjPlayerFPv(u32 a0 = 0);
s32 __dl__7TObjectFPv(void *);
void *__dt__6TOMineFv(void *arg0, s16 arg1);

void TOMineTrap::set_state() { this->mode = 4; }

s32 TOMineTrap::find_target_in_range() {
    Trap_8016F704 *self = (Trap_8016F704 *)this;
    u8 *p;
    s32 i;
    u16 id;

    self->targetId = 0xFFFF;
    self->target = 0;
    if (self->delay > 0) {
        self->delay--;
        return 0;
    }
    for (i = 0; i < registered_player_count + lbl_805D5870; i++) {
        p = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (p == 0 || p == (u8 *)self || obj_testFlags30__14TObjCollidableFUl(p, 0x800) != 0) {
            continue;
        }
        id = get_entity_id(p);
        if (id == 0xFFFF) {
            continue;
        }
        if (id == ((TOMineTrap *)self)->get_trap_type() && TOMineTrap::get_trap_count() != 1 &&
            ((TLobby *)lobby_rule_settings)->get_rule_field_0() != 0) {
            continue;
        }
        if (id < 0x1000) {
            if (((TObjPlayer *)p)->get_floor() != get_current_floor()) {
                continue;
            }
            if (horizontal_distance_squared(self->pos, p + 0x38) < self->range * self->range) {
                self->targetId = id;
                self->target = p;
                return 1;
            }
        } else if (id < 0x4000) {
            if (horizontal_distance_squared(self->pos, p + 0x38) < self->range * self->range) {
                self->targetId = id;
                self->target = p;
                return 1;
            }
        }
    }
    return 0;
}

void TOMineTrap::set_triggered() {
    u8 *arg0 = (u8 *)this;
    this->mode = 3;
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
}

void TOMineTrap::run_task() {
    TObjChara *attacker;
    s32 i;
    TObjPlayer *p;
    u16 id;

    update_float_height();
    switch (mode) {
    case 0:
    case 2:
        if (find_target_in_range() == 1) {
            set_triggered();
        }
        VecCopy((Vec *)&m_2fc, &float_position);
        VecCopy(&bodies->center, &float_position);
        break;
    case 3:
        if (set_params[1]-- < 0) {
            set_state();
            send_state_packet(2);
        }
        TOMineTrap__sub_80170CD4(this);
        submit_cursor_candidate(this, -1);
        break;
    case 4:
        attacker = get_player_by_client_id(get_trap_type());
        if (attacker == NULL) {
            attacker = this;
        }
        for (i = 0; i < lbl_805D5868; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p == NULL || p == (TObjChara *)this || p->obj_testFlags30(0x4000800) != 0) {
                continue;
            }
            if (p->alt_room != alt_room && p->room != room && p->room != alt_room) {
                continue;
            }
            id = get_entity_id(p);
            if (id == 0xFFFF) {
                continue;
            }
            if (id == get_trap_type() && TOMineTrap::get_trap_count() != 1) {
                continue;
            }
            if (id < 0x1000) {
                if (TObjPlayer::get_player_count() == 1 && p->get_floor() == get_current_floor() &&
                    horizontal_distance_squared(&position, &p->position) < m_350 * m_350) {
                    if (p->obj_isState2_324() == 0) {
                        target = (u8 *)p;
                        switch (attack.kind) {
                        case 2:
                            ((TObjChara *)target)->apply_movement_ailment(0);
                            break;
                        default:
                            ((TObjChara *)target)->receive_direct_attack(this, attack, 0, -1, -1);
                            break;
                        }
                        record_attack_source(target, get_trap_type());
                    }
                    if (m_380 != 1) {
                        m_380 = show_owner_message((s32)this, (u32)p);
                    }
                }
            } else if (id < 0x4000) {
                if (horizontal_distance_squared(&position, &p->position) < m_350 * m_350) {
                    target = (u8 *)p;
                    switch (attack.kind) {
                    case 2:
                        ((TObjChara *)target)->apply_movement_ailment(0);
                        ((TObjChara *)target)->vfunc_74(0);
                        break;
                    default:
                        ((TObjChara *)target)->receive_direct_attack(attacker, attack, 0, -1, -1);
                        break;
                    }
                    record_attack_source(target, get_trap_type());
                }
            } else if (check_value_equals__13TUnk_804B6C24Fl(p, TOMineTrap__data_805D3080) != 0) {
                if (horizontal_distance_squared(&position, &p->position) < m_350 * m_350) {
                    target = (u8 *)p;
                    ((TObjChara *)target)->receive_physical_attack(this, TOMineTrap__data_805DB868);
                }
            }
        }
        mode = 5;
        clear_player_status_flag(0, 1);
        sub_8017070C();
        queue_destruction();
        break;
    }
}

void TOMineTrap::vfunc_86() {
    u8 *arg0 = (u8 *)this;
    this->mode = 2;
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
}

void TOMineTrap::destroy_matching_traps() {
    void *p;
    s32 i;
    for (i = registered_player_count + lbl_805D5870; i < lbl_805D5868; i++) {
        p = (void *)get_player_data__10TObjPlayerFi(i);
        if (p != 0 && check_value_equals__13TUnk_804B6C24Fl(p, TOMineTrap__data_805D3080) != 0) {
            queue_destruction__7TObjectFv(p);
        }
    }
}

s32 create_placed_trap__10TOMineTrapFUiss(u32 arg0, s16 arg1, s16 arg2) {
    u16 id;
    void *player;
    void *obj;
    if (enable_v2_features != 1 || arg0 == 0 || (id = get_entity_id((void *)arg0)) == 0xFFFF || id >= 0x1000 ||
        (player = (void *)get_player_by_client_id(id)) == 0 || ((TObjPlayer *)player)->get_floor() != get_current_floor() ||
        arg1 < 0 || arg1 >= 4 || arg2 < 0 || arg2 > 0x14) {
        return 0;
    }
    if (is_boss_area() == 1 || is_current_area_item_enabled() == 0) {
        return 0;
    }
    obj = new TOMineTrap((TObjBase *)arg0, arg1, arg2);
    return (s32)obj;
}

void *TOMineTrap::get_mine_data_ptr() { return &float_position; }

extern s32 __vt__10TOMineTrap[];

void *__dt__10TOMineTrapFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TOMineTrap;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts((TObjCollidable *)arg0);
        __dt__6TOMineFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
TOMineTrap::TOMineTrap(TObjBase *owner, s16 kind, s16 slot) : TOMine(tl_05) {
    TObjPlayer *player;
    s32 floor;
    f32 area_scale;

    m_name = (const char *)TOMineTrap__data_805D3080;
    m_380 = 0;
    if (owner != NULL) {
        sub_80171348(get_entity_id(owner));
    } else {
        m_2d8 = 0xFFFF;
    }
    player = NULL;
    if (get_trap_type() != 0xFFFF && get_trap_type() < 0x1000) {
        player = get_player_by_client_id(get_trap_type());
    }
    get_current_floor_area();
    floor = get_current_floor();
    if (enable_v2_features == 1 && owner != NULL && player != NULL && floor == player->get_floor() &&
        is_current_area_item_enabled() == 1 && is_boss_area() == 0) {
        switch (kind) {
        default:
            kind = 0;
        case 0:
            attack.kind = 1;
            if (((TLobby *)lobby_rule_settings)->get_rule_field_0() == 1) {
                attack.power = lbl_805D307C;
            } else {
                area_scale = lbl_80442138[get_current_floor_area()];
                attack.power = lbl_805DB86C * area_scale *
                               (lbl_805DB870 * (lbl_805DB878 * (f32)player->get_actor_level_index() + lbl_805DB874));
            }
            if (attack.power < lbl_805DB85C) {
                attack.power = lbl_805DB85C;
            }
            break;
        case 1:
            attack.kind = 2;
            attack.power = lbl_805DB85C;
            break;
        case 2:
            attack.kind = 17;
            attack.power = lbl_805DB85C;
            break;
        case 3:
            attack.kind = 18;
            attack.power = lbl_805DB85C;
            break;
        }
        m_37e = slot + (kind * 20 + get_trap_type() * 80);
        VecCopy(&float_position, VecCopy(&home_position, VecCopy(&position, &owner->position)));
        ((TObjPlayer *)this)->init_position_vectors();
        calc_attach_pos();
        spawn_disp_objects();
        m_370 = owner->rotation_y;
        alt_room = owner->alt_room;
        room = owner->room;
        switch (attack.kind) {
        default:
            attack.kind = 1;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 19:
            model = (void *)get_bml_model(lbl_805D5A50, 4);
            texlist = TObjFish__sub_8001EDB0(lbl_805D5A50, 4);
            m_374 = get_bml_model(lbl_805D5A50, 1);
            m_378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 1);
            break;
        case 15:
        case 16:
        case 17:
        case 18:
            model = (void *)get_bml_model(lbl_805D5A50, 5);
            texlist = TObjFish__sub_8001EDB0(lbl_805D5A50, 5);
            m_374 = get_bml_model(lbl_805D5A50, 0);
            m_378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 0);
            break;
        }
        mode = 0;
        pad_34C = lbl_805DB87C;
        m_350 = lbl_805DB87C;
        set_params[0] = 150;
        set_params[1] = 30;
        if (game_difficulty_selection == 3 && ((TLobby *)lobby_rule_settings)->get_rule_field_0() == 0) {
            set_params[0] = 60;
            m_350 = lbl_805DB880;
            set_trap_count(0);
            set_instance(1);
        }
        m_344 = 0;
        m_35c = 0xFFFF;
        actorFlags |= 0x60000000;
        init_collision_body_parts(this, mine_collision_body_parts, 1);
        register_object_by_id();
    } else {
        queue_destruction();
    }
}
#pragma pop

s32 TOMine::is_target_in_list(void *obj) {
    TOMine *self = this;
    if (obj != 0) {
        u32 id = get_entity_id(obj);
        if (id < 4) {
            Node_801702C8 *n;
            for (n = *(Node_801702C8 * *)&self->m_down; n != 0; n = n->next) {
                if (((TOMineTrap *)n)->matches_id(id) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 TOMine::roll_physical_accuracy(void *, s32, f32) { return 1; }
s32 TOMine::try_start_action(s32, s32) { return 1; }
void TOMine::apply_knockback_from_attacker(u8 *, f32) {  }
void TOMine::vfunc_79() {  }
s32 TOMineTrap::check_trigger(u32 arg1) {
    if (is_target_in_list((void *)arg1) == 1) {
        return 0;
    }
    if (((s32) this->m_344 == 2) && (arg1 == (u32) this->target)) {
        return 0;
    }
    if (is_locally_controlled__10TObjPlayerFPv(arg1) != 0) {
        return 1;
    }
    return 0;
}
s32 TOMineTrap::can_trigger(u32 arg1) {
    if (is_target_in_list((void *)arg1) == 1) {
        return 0;
    }
    if (((s32) this->m_344 == 2) && (arg1 == (u32) this->target)) {
        return 0;
    }
    if (is_locally_controlled__10TObjPlayerFPv(arg1) != 0) {
        return 1;
    }
    return 0;
}

void TOMine::spawn_disp_objects() {
    TOMineDisp *disp;
    u16 i;
    if (is_split_screen() == 0) {
        disp = new TOMineDisp(this, local_client_id);
        if (disp != NULL) {
            VecCopy(&disp->home_position, &home_position);
            VecCopy(&disp->position, &position);
        }
    } else {
        for (i = 0; i != 4; i++) {
            disp = new TOMineDisp(this, i);
            if (disp != NULL) {
                VecCopy(&disp->home_position, &home_position);
                VecCopy(&disp->position, &position);
            }
        }
    }
}

void TOMine::apply_object_set_data(void *set_data) {
    u8 *arg0 = (u8 *)this;
    TObjBase::apply_object_set_data(set_data);
    this->spawn_disp_objects();
    VecCopy(&float_position, &position);
}
void TOMine::vfunc_85() {  }
const char *TOMine::get_name() { return (const char *)get_localized_text_entry(16, 16); }
void TOMine::update_state() {
    s32 temp_r0;
    *(s32 *)((s8 *)this + 0x348) = (s32) this->scale.z;
    temp_r0 = *(s32 *)((s8 *)this + 0x348);
    if (temp_r0 < 0) {
        *(s32 *)&this->m_344 = 0;
        return;
    }
    if (temp_r0 > 0) {
        *(s32 *)&this->m_344 = 1;
        return;
    }
    if (get_main_phase() == 0xE) {
        *(s32 *)&this->m_344 = 0;
        *(s32 *)&this->set_params[2] = 0x1E;
        return;
    }
    *(s32 *)&this->m_344 = 2;
}
void TOMineTrap::spawn_effect() {
    s32 arg0 = (s32)this;
    s32 area = get_current_floor_area();
    s32 elem = *(s32 *)(mine_trap_effect_table + area * 4);
    if (elem != -1) {
        play_sound_effect(elem, arg0 + 0x38, 0, 0);
    }
}
void TOMineTrap::attach_to_keymachine() {
    s32 arg0 = (s32)this;
    s32 area = get_current_floor_area();
    s32 elem = *(s32 *)(mine_trap_keymachine_table + area * 4);
    if (elem != -1) {
        play_sound_effect(elem, arg0 + 0x38, 0, 0);
    }
}
void TOMineTrap::detonate_if_triggered() {
    s32 arg0 = (s32)this;
    {
        TParticleCtrl *particle = (TParticleCtrl *)spawn_particle_effect((void *)(arg0 + 0x2FC), 0x45);
        if (particle != NULL) {
            particle->set_scale(lbl_805DB864, lbl_805DB864);
        }
    }
}
void TOMine::sub_8017070C() {
    spawn_particle_effect(((void *) (((u8 *)this) + 0x2FC)), 0x47);
    this->vfunc_82();
    this->vfunc_80();
}

void TOMine::vfunc_6(s16 *arg1, s32 arg2) {
    s16 temp_r0;
    temp_r0 = *(s16 *)((s8 *)arg1 + 0);
    if (temp_r0 == 5) {
        if (arg2 == 1) {
            sub_8017070C();
        }
        set_flag8();
        queue_destruction__7TObjectFv((this));
        access_object_saved_state(arg1, 0);
        return;
    }
    if (temp_r0 == 3) {
        this->mode = temp_r0;
        set_indexed_flags(0, 1);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
        this->calc_attach_pos();
        refresh_collision_body_centers();
        this->vfunc_81();
        access_object_saved_state(arg1, 0);
        this->queue_destruction_for_each_node();
    }
}

f32 TOMine::receive_physical_attack(void *, f32) {
    s16 sp8;
    if (((u16) this->entity_id >= 0x4000U) && ((u32) this->set_entry != 0U) && (access_object_saved_state(&sp8, 1) != 0)) {
        this->mode = 5;
        sp8 = this->mode;
        send_object_state_update(&sp8);
    }
    return lbl_805DB85C;
}
f32 TOMine::receive_weapon_special_attack(void *arg1, void *) {
    if (is_target_in_list(arg1) == 1) {
        return lbl_805DB85C;
    }
    if ((is_locally_controlled__10TObjPlayerFPv((u32)arg1) != 0) && (((TObjPlayer *)arg1)->obj_getS16_116() != 0)) {
        this->receive_physical_attack(0, TOMineTrap__data_805DB868);
    }
    return lbl_805DB85C;
}

typedef struct VBase_18_33b813 VBase_18_33b813;
typedef struct VObj_18_33b813 VObj_18_33b813;
f32 TOMine::receive_direct_attack(void *arg1, DirectAttackPayload payload, void *, s32, s32) {
  s32 temp_r0;
  s32 var_r31;
  if (arg1 == 0)
  {
    return (*(const f32 *)&lbl_805DB85C);
  }
  if (this->is_target_in_list(arg1) == 1)
  {
    return (*(const f32 *)&lbl_805DB85C);
  }
  var_r31 = 0;
  if ((get_entity_id((void *) arg1) < 4U) && (is_locally_controlled__10TObjPlayerFPv((u32)((void *) arg1)) != 0))
  {
    var_r31 = 1;
  }
  if (var_r31 != 0)
  {
    temp_r0 = payload.kind;
    if (temp_r0 != 0x13)
    {
      if ((temp_r0 < 0x13) && (temp_r0 < 5))
      {
        if (temp_r0 < 0)
        {
          if ((temp_r0 && temp_r0) && temp_r0)
          {
          }
        }
        else
        {
          goto block_13;
        }
      }
    }
    else
    {
      block_13:
      (this->receive_physical_attack(0, ((*(const f32 *)&TOMineTrap__data_805DB868))));
    }
  }
  return (*(const f32 *)&lbl_805DB85C);
}

void TOMine::update_trigger() {
    s16 sp8;
    if (((u16) this->entity_id >= 0x4000U) && ((u32) this->set_entry != 0U) && (access_object_saved_state(&sp8, 1) != 0)) {
        this->mode = 3;
        sp8 = this->mode;
        send_object_state_update(&sp8);
    }
}
void TOMine::vfunc_86() {
    u8 *arg0 = (u8 *)this;
    this->mode = 2;
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
    ((TObjChara *)arg0)->calc_attach_pos();
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TOMine *)(arg0))->vfunc_81();
}

typedef struct Stack_80170AC8 Stack_80170AC8;
#pragma fp_contract on
void TOMine::follow_target() {
    u8 *arg0 = (u8 *)this;
  unsigned short new_var;
  Stack_80170AC8 stack;
  f32 temp_f2;
  new_var = -1U;
  if (((this->m_35c) == new_var) || ((this->target) == 0))
  {
    this->mode = 2;
    return;
  }
  VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
  VecCopy((Vec *)(&stack.sp8), (const Vec *)((this->target) + 0x38));
  stack.spC = *((f32 *) (((s8 *) arg0) + 0x3C));
  subtract_vector(&stack.sp8, (u8 *)&this->position);
  if (lbl_805DB870 < vec_squared_length((u8 *)&stack.sp8))
  {
    normalize_vector(&stack.sp8);
    stack.sp8 *= lbl_805DB870;
    stack.sp10 *= lbl_805DB870;
  }
  vec3_add_to((u8 *)&this->position, &stack.sp8);
  ((TObjPlayer *)arg0)->update_enemy_collision_flags();
  temp_f2 = *((f32 *) (((s8 *) arg0) + 0x48));
  *((f32 *) (((s8 *) arg0) + 0x3C)) = (f32) ((lbl_805DB884 * ((lbl_805DB888 + (*((f32 *) ((this->target) + 0x3C)))) - temp_f2)) + temp_f2);
  ((TObjChara *)arg0)->calc_attach_pos();
  this->rotation_y = (s32) (lbl_80442200 * atan2_float((f64) stack.sp8, (f64) stack.sp10));
  ((TObjCollidable *)arg0)->refresh_collision_body_centers();
}

void TOMine::sub_80170BEC() {
    u8 *p;
    s32 i;
    switch (this->phase) {
    case 0:
        this->phase = 1;
        for (i = lbl_805D5870; i < lbl_805D5868; i++) {
            p = (u8 *)get_player_data__10TObjPlayerFi(i);
            if (p != NULL && p != ((u8 *)this) &&
                (check_value_equals__13TUnk_804B6C24Fl(p, TOMineIcon01__name) != 0 ||
                 check_value_equals__13TUnk_804B6C24Fl(p, TOMineIcon02__name) != 0 ||
                 check_value_equals__13TUnk_804B6C24Fl(p, TOMineIcon03__name) != 0 ||
                 check_value_equals__13TUnk_804B6C24Fl(p, TOMineIcon04__name) != 0) &&
                *(s32 *)(p + 0x344) == 1 && *(s32 *)(p + 0x348) == *(s32 *)(((u8 *)this) + 0x348)) {
                ((TOMine *)p)->update_trigger();
            }
        }
        break;
    }
    ((TOMineTrap *)((u8 *)this))->sync_position();
}

void TOMineTrap__sub_80170CD4(void* p) { ((TOMineTrap *)p)->sync_position(); }

#pragma push
#pragma fp_contract on
void TOMine::update_float_height() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f4;
    if (!(this->m_340 & 2)) {
        temp_f4 = float_position.y;
        float_position.y = (f32) (temp_f4 + ((lbl_805DB884 * ((lbl_805DB888 + this->home_position.y) - temp_f4)) + (*(const f32 *)&TOMineTrap__data_805DB868)));
        temp_f1 = lbl_805DB888 + this->home_position.y;
        if (temp_f1 <= float_position.y) {
            float_position.y = temp_f1;
            this->m_340 = (s32) (this->m_340 | 2);
        }
    } else {
        *(s32 *)&this->rotation_x = (s32) (*(s32 *)&this->rotation_x + 0x800);
        float_position.y = (f32) (float_position.y + sin_table_lookup(*(s32 *)&this->rotation_x));
    }
}
#pragma pop

void TOMineTrap::sync_position() { VecCopy(&position, &float_position); refresh_collision_body_centers(); }
void TOMine::detonate() {
    s32 i;
    u8 *obj;
    set_indexed_flags(0, 2);
    *(f32 *)(*(u8 * *)&this->bodies + 0xC) = this->m_350;
    TObjPlayer::init_all_slots();
    ((TObjPlayer *)((u8 *)this))->check_object_collisions();
    check_enemy_body_collisions(this);
    for (i = 0; i < 0x10; i++) {
        obj = get_battle_param__10TObjPlayerFi(i);
        if (TObjPlayer::is_valid_and_active((u32)obj) != 0) {
            DirectAttackPayload pair = attack;
            f32 r = ((VObj_18_1da615 *)obj)->m21(this, &pair, 0, -1, -1);
            if (attack.kind < 5) {
                ((VObj_18_1da615 *)obj)->m23(this, lbl_805DB874 * r);
            }
        }
    }
    this->mode = 6;
    this->clear_player_status_flag(0, 1);
    this->receive_physical_attack(0, TOMineTrap__data_805DB868);
}

}
