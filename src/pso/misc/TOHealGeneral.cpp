#include "types.h"
#include "pso/misc/TOHealGeneral.h"
#include "pso/misc/TOHangerMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/item/TItemProShield.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/TObject.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"

extern "C" {

s32 add_actor_tp(u8 *arg0, s32 arg1);
s32 add_actor_hp(u8 *arg0, s16 arg1);
s32 obj_testFlags30__14TObjCollidableFUl(s32, s32);
f32 horizontal_distance_squared(s32, void *);
s32 get_player_by_client_id(u32);

s16 get_actor_hp(void *);
void send_6x2F_change_player_hp(u16, u16, s16);

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TOHealGeneral::update_closing() {
    s16 temp_r3_2;
    u8 *player;
    apply_heal_to_target();
    this->m_cc = (this->m_cc + 0x147);
    this->ring_drop = (f32) (this->ring_drop - 0.37166664f);
    this->effect_pos[1].y = (f32) ((22.3f + this->position.y) - this->ring_drop);
    if (this->ring_drop <= 0.0f) {
        this->ring_drop = (f32) 0.0f;
        this->m_ac = 0;
        if (TOHangerMachine01::is_valid_slot((s32) this, this->heal_target) != 0) {
            player = (u8 *)(get_player_by_client_id((u32) this->heal_target));
            if (player != NULL) {
                temp_r3_2 = get_actor_hp(player);
                if (temp_r3_2 > 0) {
                    send_6x2F_change_player_hp(0xFFFFU, this->heal_target, temp_r3_2);
                }
            }
        }
    }
}
#pragma pop

void TOHealGeneral::update_opening() {
    apply_heal_to_target();
    this->m_cc = (this->m_cc + 0x147);
    this->ring_drop += 0.37166664f;
    this->effect_pos[1].y = (f32) ((22.3f + this->position.y) - this->ring_drop);
    if (22.3f <= this->ring_drop) {
        this->ring_drop = (f32) 22.3f;
        this->m_ac = 2;
    }
}
void TOHealGeneral::apply_heal_to_target() {
    s32 temp_r3_2;
    u32 id = this->heal_target;
    if ((id != 0xFFFF) && (id < 0x1000U)) {
        temp_r3_2 = get_player_by_client_id(id);
        if ((temp_r3_2 != 0) && (obj_testFlags30__14TObjCollidableFUl(temp_r3_2, 0x800) == 0) && (horizontal_distance_squared(temp_r3_2 + 0x38, (u8 *)&this->position) < 225.0f)) {
            add_actor_hp((u8 *)temp_r3_2, 9);
            add_actor_tp((u8 *)temp_r3_2, 9);
        }
    }
}

}

struct VBase_80169334 { char pad[0x18]; };

struct Actor_80169334 : VBase_80169334 {
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
};

extern "C" {
int get_player_data__10TObjPlayerFi(int a0);
s32 get_entity_id(void *obj);
f32 get_collision_body_radius(void *, s32);

s16 obj_getS16_2BA(u8 *p);
s16 get_actor_tp(u8 *p);
u32 get_recovery_need_flags__10TObjPlayerFv(void *);
void send_6x2C_impose_hold(void *, void *, s32, s32, f32);
void *spawn_particle_effect_with_flags(void *, s32, s32);
s32 play_sound_effect(s32, void *, s32, s32);
extern s32 registered_player_count;

void find_heal_target__13TOHealGeneralFPv(TOHealGeneral *self);
#pragma push
#pragma opt_common_subs off
void find_heal_target__13TOHealGeneralFPv(TOHealGeneral *self) {
    Actor_80169334 *actor;
    s32 i;
    s32 id;
    f32 r;
    self->m_cc += 0x147;
    self->heal_target = 0xFFFF;
    for (i = 0; i < registered_player_count; i++) {
        actor = (Actor_80169334 *)get_player_data__10TObjPlayerFi(i);
        id = get_entity_id(actor);
        if (actor == 0) {
            continue;
        }
        if ((u16)id >= 0x1000) {
            continue;
        }
        r = 1e+01f - get_collision_body_radius(actor, 0);
        if (!(horizontal_distance_squared((s32)((u8 *)actor + 0x38), &self->position) < r * r)) {
            continue;
        }
        self->heal_target = id;
        if (get_actor_hp((u8 *)actor) < ((TItemProShield *)actor)->get_field_2b8() ||
            get_actor_tp((u8 *)actor) < obj_getS16_2BA((u8 *)actor) ||
            get_recovery_need_flags__10TObjPlayerFv(actor) != 0 ||
            (((TObjPlayer *)actor)->is_alive_and_ready() != 0 && ((TObjPlayer *)actor)->are_traps_full() == 0)) {
            void *e;
            self->m_ac = 1;
            if (TOHangerMachine01::is_valid_slot((int)self, self->heal_target) != 0) {
                send_6x2C_impose_hold(actor, &self->position, 0x3C, 0, r);
                actor->m48();
            }
            if (((TObjPlayer *)actor)->is_alive_and_ready() != 0) {
                ((TObjPlayer *)actor)->refill_traps();
            }
            e = spawn_particle_effect_with_flags((u8 *)actor + 0x2FC, 0x1F6, 0x10);
            if (e != 0) {
                ((TParticleCtrl *)e)->set_owner_id(self->heal_target);
            }
            e = spawn_particle_effect_with_flags((u8 *)actor + 0x2FC, 0x1F7, 0x10);
            if (e != 0) {
                ((TParticleCtrl *)e)->set_owner_id(self->heal_target);
            }
            play_sound_effect(0x4002AB0E, &self->position, 0, 0);
            break;
        }
    }
}
#pragma pop

}

struct RecoveredGlobal_80169710_lbl_804B2748
{
  s32 value;
  u8 remaining[0xC];
};

struct RecoveredGlobal_80169710_lbl_804B2760
{
  s32 value;
  u8 remaining[0xC];
};

extern "C" {
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80169710_lbl_804B2748 bm_fe_obj_kaifuku_moto_resource_descriptor;
extern RecoveredGlobal_80169710_lbl_804B2760 fe_obj_kaifuku_moto_2_resource_descriptor;
extern u32 TOHealGeneral__model_archive;
void free_collision_body_parts(void *);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
void *create_particle_emitter(void *pos, s32 id);
void init_collision_body_parts(void *, void *, s32, void *);
extern u8 heal_general_collision_body_part[];
extern s32 TOHealGeneral__class_name;
extern s32 tl_05;

void TLobby__sub_8001FE7C(void*, int);
s32 post_translate_matrix(void *);
void draw_ginja_model(s32 model);
s32 rotate_matrix_y(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
s32 pop_matrix();
}

void TOHealGeneral::run_task() {

    if (TObjPlayer::check_demo_mode() == 1) {
        TOHangerMachine01__sub_80169168(this);
        return;
    }
    switch (this->m_ac) {
    case 0:
        find_heal_target__13TOHealGeneralFPv(this);
        return;
    case 1:
        update_opening();
        return;
    case 2:
        update_closing();
        return;
    }
}

void TOHealGeneral::render() {
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;

    if (update_object_view_visibility(this->m_c0, this->model_radius) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        temp_r31 = (unsigned char *) (*(void * *)&this->model);
        post_translate_matrix(temp_r31 + 8);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
        push_matrix();
        temp_r31_2 = (unsigned char *) (*(void **)((s8 *)temp_r31 + 0x2C));
        post_translate_matrix(temp_r31_2 + 8);
        rotate_matrix_y(0, (int) (s32)this->m_cc);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
        pop_matrix();
        push_matrix();
        temp_r31_3 = (unsigned char *) (*(void **)((s8 *)temp_r31_2 + 0x30));
        translate_matrix(0, (f32) (*(f32 *)((s8 *)temp_r31_3 + 8)), (f32) (*(f32 *)((s8 *)temp_r31_3 + 0xC) - this->ring_drop), (f32) (*(f32 *)((s8 *)temp_r31_3 + 0x10)));
        rotate_matrix_y(0, (int) (-(s32)this->m_cc));
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
        pop_matrix();
        pop_matrix();
    }
}

void *TOHealGeneral::create() {
    return new TOHealGeneral(this);
}

void TOHealGeneral::close_dialog_window() {
    if ((u32) TOHealGeneral__model_archive != 0U) {
        TLobby__sub_8001FE7C((void*)TOHealGeneral__model_archive, 1);
        TOHealGeneral__model_archive = 0U;
    }
}

typedef struct RecoveredGlobal_80169710_lbl_804B2748 RecoveredGlobal_80169710_lbl_804B2748;
typedef struct RecoveredGlobal_80169710_lbl_804B2760 RecoveredGlobal_80169710_lbl_804B2760;
void TOHealGeneral::load_resources() {
  s32 area;
  s32 temp_r3_2;
  s32 temp_r3_3;
  s32 var_r0;
  s32 var_r0_2;
  int new_var;
  area = get_current_floor_area();
  if (area < 0x22)
  {
    if (area < 0x1E)
    {
      if (area < 0x17)
      {
        temp_r3_2++;
        temp_r3_2--;
        goto block_8;
      }
      goto block_5;
    }
    goto block_8;
  }
  if (area < 0x24)
  {
    block_5:
    temp_r3_2 = (int)::operator new(0x440);
    var_r0 = temp_r3_2;
    if (var_r0 != 0)
    {
      var_r0 = (long) load_resource_from_descriptor((void *) temp_r3_2, 1, &fe_obj_kaifuku_moto_2_resource_descriptor.value, 0, 0, 0);
    }
    (*(s32 *)&TOHealGeneral__model_archive) = var_r0;
    return;
  }
  block_8:
  temp_r3_3 = (new_var = (int)::operator new(0x440));
  var_r0_2 = temp_r3_3;
  if (var_r0_2 != 0)
  {
    var_r0_2 = (long) load_resource_from_descriptor((void *) temp_r3_3, 1, &bm_fe_obj_kaifuku_moto_resource_descriptor.value, 0, 0, 0);
  }
  (*(s32 *)&TOHealGeneral__model_archive) = var_r0_2;
}

// The destructor is still written out by hand: compiled, its vtable would
// open the unit's .data, which the original fills first with the object's
// resource and collision tables (not owned by this unit yet).
extern "C" {
extern void *__vt__13TOHealGeneral[];
void __dl__7TObjectFPv(void *);

void *__dt__13TOHealGeneralFv(void *self, s16 del) {
    s32 i;
    if (self != NULL) {
        *(void **)((u8 *)self + 0x18) = __vt__13TOHealGeneral;
        for (i = 0; i < 2; i++) {
            if (((TOHealGeneral *)self)->effects[i] != 0) {
                TParticleCtrl::release((void *)((TOHealGeneral *)self)->effects[i]);
            }
        }
        ((TOHealGeneral *)self)->unregister_object_by_id();
        free_collision_body_parts((TOHealGeneral *)self);
        __dt__13TUnk_804AFBF8Fv(self, 0);
        if (del > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

TOHealGeneral::TOHealGeneral(void *set_data) : TUnk_804AFBF8((TObject *)tl_05) {
    s32 i;
    u8 *model;
    m_name = (const char *)TOHealGeneral__class_name;
    apply_object_set_data(set_data);
    this->model = (void *)*(s32 *)((s8 *)(*(u8 **)((s8 *)TOHealGeneral__model_archive + 0x42C)) + 8);
    model = *(u8 **)((s8 *)TOHealGeneral__model_archive + 0x42C);
    texlist = *(s32 *)((s8 *)model + 0xC);
    model_radius = 4e+01f;
    init_collision_body_parts(this, heal_general_collision_body_part, 1, model);
    refresh_collision_body_centers();
    register_object_by_id();
    clear_player_status_flag(0, 1);
    m_cc = 0;
    ring_drop = 0.0f;
    for (i = 0; i < 2; i++) {
        VecCopy(&effect_pos[i], &position);
    }
    effect_pos[0].y += 26.100002f;
    effect_pos[1].y += 22.3f;
    effects[0] = (u32)create_particle_emitter(&effect_pos[0], 0x63);
    if (effects[0] != 0 && ((TObject *)(effects[0]))->all_parents_unqueued_for_destruction() == 0) {
        effects[0] = 0;
    }
    effects[1] = (u32)spawn_continuous_particle_effect_with_flags(&effect_pos[1], 0x63, 0x10);
    if (effects[1] != 0 && ((TObject *)(effects[1]))->all_parents_unqueued_for_destruction() != 0) {
        ((TParticleCtrl *)(effects[1]))->set_owner_id(entity_id);
    } else {
        effects[1] = 0;
    }
    heal_target = 0xFFFF;
}

void *TOHealGeneral::get_center() { return &effect_pos[1]; }
