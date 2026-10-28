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
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 add_actor_tp(u8 *arg0, s32 arg1);
s32 add_actor_hp(u8 *arg0, s16 arg1);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(s32, s32);
f32 horizontal_distance_squared(s32, void *);
s32 get_player_by_client_id(u32);

s16 obj_getS16_32C(void *);
void send_6x2F_change_player_hp(u16, u16, s16);

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TOHealGeneral::update_closing() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r3_2;
    u8 *player;
    apply_heal_to_target();
    this->m_cc = (this->m_cc + 0x147);
    *(f32 *)&this->_padD0 = (f32) (*(f32 *)&this->_padD0 - 0.37166664f);
    *(f32 *)((s8 *)arg0 + 0xE4) = (f32) ((22.3f + *(f32 *)((s8 *)arg0 + 0x3C)) - *(f32 *)&this->_padD0);
    if (*(f32 *)&this->_padD0 <= 0.0f) {
        *(f32 *)&this->_padD0 = (f32) 0.0f;
        this->m_ac = 0;
        if (TOHangerMachine01::is_valid_slot((s32) arg0, this->m_f4) != 0) {
            player = (u8 *)(get_player_by_client_id((u32) this->m_f4));
            if (player != NULL) {
                temp_r3_2 = obj_getS16_32C(player);
                if (temp_r3_2 > 0) {
                    send_6x2F_change_player_hp(0xFFFFU, this->m_f4, temp_r3_2);
                }
            }
        }
    }
}
#pragma pop

void TOHealGeneral::update_opening() {
    u8 *arg0 = (u8 *)this;
    apply_heal_to_target();
    this->m_cc = (this->m_cc + 0x147);
    *(f32 *)&this->_padD0 += 0.37166664f;
    *(f32 *)((s8 *)arg0 + 0xE4) = (f32) ((22.3f + *(f32 *)((s8 *)arg0 + 0x3C)) - *(f32 *)&this->_padD0);
    if (22.3f <= *(f32 *)&this->_padD0) {
        *(f32 *)&this->_padD0 = (f32) 22.3f;
        this->m_ac = 2;
    }
}
void TOHealGeneral::apply_heal_to_target() {
    s32 temp_r3_2;
    u32 id = this->m_f4;
    if ((id != 0xFFFF) && (id < 0x1000U)) {
        temp_r3_2 = get_player_by_client_id(id);
        if ((temp_r3_2 != 0) && (obj_testFlags30__13TUnk_804AF8A0FUl(temp_r3_2, 0x800) == 0) && (horizontal_distance_squared(temp_r3_2 + 0x38, (u8 *)&this->position) < 225.0f)) {
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
s16 obj_getS16_32E(u8 *p);
u32 get_recovery_need_flags__10TObjPlayerFv(void *);
void send_6x2C_impose_hold(void *, void *, s32, s32, f32);
void *spawn_particle_effect_with_flags(void *, s32, s32);
s32 play_sound_effect(s32, void *, s32, s32);
extern s32 lbl_805D586C;

void find_heal_target__13TOHealGeneralFPv(TOHealGeneral *self);
#pragma push
#pragma opt_common_subs off
void find_heal_target__13TOHealGeneralFPv(TOHealGeneral *self) {
    Actor_80169334 *actor;
    s32 i;
    s32 id;
    f32 r;
    self->m_cc += 0x147;
    self->m_f4 = 0xFFFF;
    for (i = 0; i < lbl_805D586C; i++) {
        actor = (Actor_80169334 *)get_player_data__10TObjPlayerFi(i);
        id = get_entity_id(actor);
        if (actor == 0) {
            continue;
        }
        if ((u16)id >= 0x1000) {
            continue;
        }
        r = 1e+01f - get_collision_body_radius(actor, 0);
        if (!(horizontal_distance_squared((s32)((u8 *)actor + 0x38), self->position) < r * r)) {
            continue;
        }
        self->m_f4 = id;
        if (obj_getS16_32C((u8 *)actor) < ((TItemProShield *)actor)->get_field_2b8() ||
            obj_getS16_32E((u8 *)actor) < obj_getS16_2BA((u8 *)actor) ||
            get_recovery_need_flags__10TObjPlayerFv(actor) != 0 ||
            (((TObjPlayer *)actor)->is_alive_and_ready() != 0 && ((TObjPlayer *)actor)->are_traps_full() == 0)) {
            void *e;
            self->m_ac = 1;
            if (TOHangerMachine01::is_valid_slot((int)self, self->m_f4) != 0) {
                send_6x2C_impose_hold(actor, self->position, 0x3C, 0, r);
                actor->m48();
            }
            if (((TObjPlayer *)actor)->is_alive_and_ready() != 0) {
                ((TObjPlayer *)actor)->refill_traps();
            }
            e = spawn_particle_effect_with_flags((u8 *)actor + 0x2FC, 0x1F6, 0x10);
            if (e != 0) {
                ((TParticleCtrl *)e)->set_owner_id(self->m_f4);
            }
            e = spawn_particle_effect_with_flags((u8 *)actor + 0x2FC, 0x1F7, 0x10);
            if (e != 0) {
                ((TParticleCtrl *)e)->set_owner_id(self->m_f4);
            }
            play_sound_effect(0x4002AB0E, self->position, 0, 0);
            break;
        }
    }
}
#pragma pop

}

struct Base_801695a8_80169520 { char pad[0x18]; };
struct VObj_801695a8_80169520 : Base_801695a8_80169520 {
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

typedef struct TOHealGeneral_801697C0 {
    u8 pad0[0x18];
    void **vtable;
    u8 pad1C[0xEC - 0x1C];
    u32 handles[2];
} TOHealGeneral_801697C0;

struct Vec_80169858 { f32 x, y, z; };

struct Heal_80169858 {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void **vtable;
    u16 f1c;
    u8 pad1e[0x24 - 0x1E];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    Vec_80169858 pos;
    u8 pad44[0xC4 - 0x44];
    f32 fC4;
    u8 padC8[0xCC - 0xC8];
    s32 fCC;
    f32 fD0;
    Vec_80169858 pts[2];
    u32 handles[2];
    u16 fF4;
};

extern "C" {
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80169710_lbl_804B2748 bm_fe_obj_kaifuku_moto_resource_descriptor;
extern RecoveredGlobal_80169710_lbl_804B2760 fe_obj_kaifuku_moto_2_resource_descriptor;
extern u32 TOHealGeneral__model_archive;
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
extern void *__vt__13TOHealGeneral[];
TOHealGeneral_801697C0 *__dt__13TOHealGeneralFv(TOHealGeneral_801697C0 *self, s16 flag);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
void *create_particle_emitter(void *pos, s32 id);
void init_collision_body_parts(void *, void *, s32, void *);
void init_map_object_base(void *, s32);
extern u8 heal_general_collision_body_part[];
extern s32 TOHealGeneral__class_name;
extern s32 tl_05;

void *TOHealGeneral__ct(void *arg0, void *arg1);
void TLobby__sub_8001FE7C(void*, int);
s32 post_translate_matrix(void *);
void draw_ginja_model(s32 model);
s32 rotate_matrix_y(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
s32 pop_matrix();
void *__nw__7TObjectFUl(int);

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
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;

    if (((VObj_801695a8_80169520 *)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texture_id);
        temp_r31 = (unsigned char *) (*(void * *)&this->model);
        post_translate_matrix(temp_r31 + 8);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
        push_matrix();
        temp_r31_2 = (unsigned char *) (*(void **)((s8 *)temp_r31 + 0x2C));
        post_translate_matrix(temp_r31_2 + 8);
        rotate_matrix_y(0, (int) (*(s32 *)&this->m_cc));
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
        pop_matrix();
        push_matrix();
        temp_r31_3 = (unsigned char *) (*(void **)((s8 *)temp_r31_2 + 0x30));
        translate_matrix(0, (f32) (*(f32 *)((s8 *)temp_r31_3 + 8)), (f32) (*(f32 *)((s8 *)temp_r31_3 + 0xC) - *(f32 *)&this->_padD0), (f32) (*(f32 *)((s8 *)temp_r31_3 + 0x10)));
        rotate_matrix_y(0, (int) (-*(s32 *)&this->m_cc));
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
        pop_matrix();
        pop_matrix();
    }
}

void *TOHealGeneral::create() {
    void *o = __nw__7TObjectFUl(0xF8);
    if (o != NULL) {
        o = TOHealGeneral__ct(o, this);
    }
    return o;
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
  s32 global_state;
  s32 temp_r3_2;
  s32 temp_r3_3;
  s32 var_r0;
  s32 var_r0_2;
  int new_var;
  global_state = TOKeyMachine01::get_global_state();
  if (global_state < 0x22)
  {
    if (global_state < 0x1E)
    {
      if (global_state < 0x17)
      {
        temp_r3_2++;
        temp_r3_2--;
        goto block_8;
      }
      goto block_5;
    }
    goto block_8;
  }
  if (global_state < 0x24)
  {
    block_5:
    temp_r3_2 = ((TAdSinglePlyChrSelectGC *)((void *) 0x440))->alloc();
    var_r0 = temp_r3_2;
    if (var_r0 != 0)
    {
      var_r0 = (long) load_resource_from_descriptor((void *) temp_r3_2, 1, &fe_obj_kaifuku_moto_2_resource_descriptor.value, 0, 0, 0);
    }
    (*(s32 *)&TOHealGeneral__model_archive) = var_r0;
    return;
  }
  block_8:
  temp_r3_3 = (new_var = ((TAdSinglePlyChrSelectGC *)((void *) 0x440))->alloc());
  var_r0_2 = temp_r3_3;
  if (var_r0_2 != 0)
  {
    var_r0_2 = (long) load_resource_from_descriptor((void *) temp_r3_3, 1, &bm_fe_obj_kaifuku_moto_resource_descriptor.value, 0, 0, 0);
  }
  (*(s32 *)&TOHealGeneral__model_archive) = var_r0_2;
}

TOHealGeneral_801697C0 *__dt__13TOHealGeneralFv(TOHealGeneral_801697C0 *self, s16 flag) {
    s32 i;
    if (self != NULL) {
        self->vtable = __vt__13TOHealGeneral;
        for (i = 0; i < 2; i++) {
            if (self->handles[i] != 0) {
                TBoss4Type2::request_destroy(self->handles[i]);
            }
        }
        ((TUnk_804AF8A0 *)self)->unregister_object_by_id();
        free_collision_body_parts(self);
        ((TUnk_804AFBF8 *)self)->destroy_key_base(0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

void *TOHealGeneral__ct(void *arg0, void *arg1) {
    Heal_80169858 *self = (Heal_80169858 *)arg0;
    s32 i;
    u8 *model;
    init_map_object_base(self, tl_05);
    self->vtable = __vt__13TOHealGeneral;
    self->f0 = TOHealGeneral__class_name;
    ((TOHealGeneral *)self)->apply_object_set_data(arg1);
    self->f34 = *(s32 *)((s8 *)(*(u8 **)((s8 *)TOHealGeneral__model_archive + 0x42C)) + 8);
    model = *(u8 **)((s8 *)TOHealGeneral__model_archive + 0x42C);
    self->f24 = *(s32 *)((s8 *)model + 0xC);
    self->fC4 = 4e+01f;
    init_collision_body_parts(self, heal_general_collision_body_part, 1, model);
    ((TUnk_804AF8A0 *)self)->refresh_collision_body_centers();
    ((TObjPlayer *)self)->reset_photon_effect();
    ((TUnk_804AF8A0 *)self)->clear_player_status_flag(0, 1);
    self->fCC = 0;
    self->fD0 = 0.0f;
    for (i = 0; i < 2; i++) {
        VecCopy((Vec *)&self->pts[i], (const Vec *)&self->pos);
    }
    self->pts[0].y += 26.100002f;
    self->pts[1].y += 22.3f;
    self->handles[0] = (u32)create_particle_emitter(&self->pts[0], 0x63);
    if (self->handles[0] != 0 && ((TObject *)(self->handles[0]))->all_parents_unqueued_for_destruction() == 0) {
        self->handles[0] = 0;
    }
    self->handles[1] = (u32)spawn_continuous_particle_effect_with_flags(&self->pts[1], 0x63, 0x10);
    if (self->handles[1] != 0 && ((TObject *)(self->handles[1]))->all_parents_unqueued_for_destruction() != 0) {
        ((TParticleCtrl *)(self->handles[1]))->set_owner_id(self->f1c);
    } else {
        self->handles[1] = 0;
    }
    self->fF4 = 0xFFFF;
    return self;
}

void*TOHealGeneral::vfunc_9() { return (char*)this + 0xe0; }

}
