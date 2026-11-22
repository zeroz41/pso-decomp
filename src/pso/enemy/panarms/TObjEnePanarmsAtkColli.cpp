#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/enemy/EnemyTargeting.h"
#include "types.h"
#include "pso/enemy/panarms/TObjEnePanarmsAtkColli.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaMirage.h"

#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjControl.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/SoundEffect.h"

// Stored in the object name field by the constructor.
const char *TObjEnePanarmsAtkColli_class_name = "TObjEnePanarmsAtkColli";

__declspec(section ".data") s32 TObjEnePanarmsAtkColli__type_index_table[2] = {1, 2};
Vec panarms_atk_zero_vec = {0.0f, 0.0f, 0.0f};


struct Obj_800E32C0 { u8 pad0[0x10]; s32 f10; u8 pad1[0x388-0x14]; TObjChara *f388; f32 f38C; };

struct Obj_800E3374 { u8 pad0[0x10]; s32 f10; u8 pad1[0x384-0x14]; TObjChara *f384; u8 pad2[4]; f32 f38C; };

struct Obj_800E35C8 { u8 pad0[0x38]; Vec pos; u8 pad1[0x378 - 0x44]; f32 f378; };

struct Player_800E35C8 { u8 pad0[0x30]; u32 f30; };

struct Obj_800E3428 { u8 pad0[0x38]; Vec pos; Vec dir; u8 pad1[0x378 - 0x50]; f32 f378; };

struct Obj_800E322C { u8 pad0[0x10]; u32 f10; u8 pad1[0x38 - 0x14]; Vec pos; u8 pad2[0x378 - 0x44]; f32 f378; };

extern "C" {
__declspec(section ".rodata") DirectAttackPayload lbl_8043CDF0[] = { 0 };
__declspec(section ".rodata") DirectAttackPayload lbl_8043CDF8[] = { 0 };
void fn_800E3374(Obj_800E3374 *target, TObjChara *arg1);
f32 horizontal_distance_squared(void *, void *);
extern s32 registered_player_count;
void check_radius_collisions(Obj_800E35C8 *target);
void fn_800E322C(void *p, void *t);
void vec3_add_to(void *, void *);
ModelNodePositionCapture::ModelNodePositionCapture(const ModelNodePositionEntry *entries, Vec *positions) {
    this->entries = entries;
    this->positions = positions;
    const ModelNodePositionEntry *entry = this->entries;
    Vec *point = this->positions;
    while (entry->node_index != -1) {
        VecCopy(point, &panarms_atk_zero_vec);
        entry++;
        point++;
    }
}

void fn_800E322C(void *p, void *t) {
    Obj_800E322C *target = (Obj_800E322C *)p;
    Vec sp = target->pos;
    s32 r;
    uaddr ent;
    VecCopy((Vec *)&target->pos, (const Vec *)t);
    if ((r = find_nearest_hittable_enemy__10TObjPlayerFiPvf(reinterpret_cast<saddr>(target), NULL, target->f378)) != 0xFFFF) {
        if ((ent = (uaddr)get_enemy_entity(r)) != 0 && ent != target->f10) {
            ((TObjEnePanarmsAtkColli *)target)->sub_800E32C0((TObjChara *)ent);
        }
    }
    VecCopy((Vec *)&target->pos, (const Vec *)&sp);
}

void TObjEnePanarmsAtkColli::sub_800E32C0(void *ent) {
    DirectAttackPayload attack = lbl_8043CDF8[0];
    attack.power = ((Obj_800E32C0 *)this)->f38C;
    if (((Obj_800E32C0 *)this)->f388 != (TObjChara *)ent) {
        f32 damage = ((TObjChara *)ent)->receive_direct_attack((void *)((Obj_800E32C0 *)this)->f10, attack, NULL, -1, -1);
        if (0.0f != damage) {
            ((TObjChara *)ent)->apply_knockback_from_attacker((u8 *)this, damage);
        }
        ((Obj_800E32C0 *)this)->f388 = (TObjChara *)ent;
    }
}
void fn_800E3374(Obj_800E3374 *target, TObjChara *arg1) {
    DirectAttackPayload attack = lbl_8043CDF0[0];
    attack.power = target->f38C;
    if (target->f384 != arg1) {
        f32 damage = arg1->receive_direct_attack((void *)target->f10, attack, NULL, -1, -1);
        if (0.0f != damage) {
            arg1->apply_knockback_from_attacker((u8 *)target, damage);
        }
        target->f384 = arg1;
    }
}
#pragma push
#pragma opt_loop_invariants off
void sweep_segment_collisions(Obj_800E3428 *self) {
    Vec d;
    f32 len;
    f32 lim;
    f32 dist;
    s32 i;
    Player_800E35C8 *p;

    lim = self->f378 * self->f378;
    VecCopy((Vec *)&d, (const Vec *)&self->dir);
    subtract_vector(&d, &self->pos);
    len = vector_length(&d);
    if (0.0f == len) {
        d.x = (1.0f);
    }
    normalize_vector(&d);
    d.x *= self->f378;
    d.z *= self->f378;
    for (i = 0; i < registered_player_count; i++) {
        p = (Player_800E35C8 *)TObjPlayer::get_player_data(i);
        if (p != NULL && !(p->f30 & 0x02000A00)) {
            Vec v = self->pos;
            for (dist = 0.0f; dist < len; ) {
                if (!(horizontal_distance_squared(&v, (u8 *)p + 0x2FC) > lim)) {
                    fn_800E3374((Obj_800E3374 *)self, (TObjChara *)p);
                    break;
                }
                dist += self->f378;
                vec3_add_to(&v, &d);
            }
        }
    }
    {
    Vec w = self->pos;
    f32 dist2;
    for (dist2 = 0.0f; dist2 < len; ) {
        fn_800E322C(self, &w);
        dist2 += self->f378;
        vec3_add_to(&w, &d);
    }
    }
}

#pragma pop

void check_radius_collisions(Obj_800E35C8 *target) {
    s32 i;
    Player_800E35C8 *p;
    f32 lim = target->f378 * target->f378;
    for (i = 0; i < registered_player_count; i++) {
        p = (Player_800E35C8 *)TObjPlayer::get_player_data(i);
        if (p != NULL && !(p->f30 & 0x02000A00) && !(horizontal_distance_squared(&target->pos, (u8 *) p + 0x2FC) > lim)) {
            fn_800E3374((Obj_800E3374 *)(target), (TObjChara *)(p));
        }
    }
    fn_800E322C(target, &target->pos);
}

}

struct Obj_800E37E4 {
    const char *name;
    u8 pad4[0x14];
    void *vt;
    u8 pad1C[0x1C];
    Vec pos;
    u8 pad44[0x308 - 0x44];
    Vec scale;
    u8 pad314[0x374 - 0x314];
    s32 type;
    f32 f378;
    f32 f37C;
    s32 f380;
    s32 f384;
    s32 f388;
    f32 f38C;
};

extern "C" {
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);

void TObjEnePanarmsAtkColli::run_task() {
    u8 *self = (u8 *)this;
    if (--*(s32 *)&this->m_380 < 0) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    VecCopy(&this->prev_position, (const Vec *)&this->position);
    vec3_add_to((u8 *)&this->position, (u8 *)&this->unk_308);
    *(f32 *)&this->unk_378 = (f32) (*(f32 *)&this->unk_378 + this->m_37c);
    switch (*(s32 *)&this->m_374) {
    case 0:
        ((void (*)(void *))check_radius_collisions)(self);
        return;
    case 1:
        play_persistent_sound((s32)(((TObjEnemy *)(self))->remap_sound_for_area(0x4003BA2A)), (saddr)self, (uaddr)&this->position, 0, 0);
        ((void (*)(void *))sweep_segment_collisions)(self);
        return;
    }
}

void *TObjEnePanarmsAtkColli::create(void *arg1, void *arg2, void *arg3) {
    return new TObjEnePanarmsAtkColli((TObject *)this, arg1, arg2, arg3);
}

}
TObjEnePanarmsAtkColli::~TObjEnePanarmsAtkColli() {

}


#define self ((Obj_800E37E4 *)this)
extern const f32 lbl_805DA5A8 = 10.0f;
extern const f32 lbl_805DA5AC = 2.8f;
TObjEnePanarmsAtkColli::TObjEnePanarmsAtkColli(TObject *parent, void *arg2, void *arg3, void *arg4) : TObjEnemy(parent) {
    f32 scale;
    self->name = TObjEnePanarmsAtkColli_class_name;
    VecCopy((Vec *)&self->pos, (const Vec *)arg2);
    VecCopy((Vec *)&self->scale, (const Vec *)arg3);
    self->type = (saddr)arg4;
    self->f384 = 0;
    self->f388 = 0;
    ((TObjEnemy *)self)->set_param(0x15);
    self->f38C = ((f32 *)TLobby::dispatch_shared_handler_a(0x31))[TObjEnePanarmsAtkColli__type_index_table[self->type]];
    if (self->f38C < 0.0f) {
        self->f38C = 0.0f;
    }
    self->scale.y = (0.0f);
    if ((0.0f) == vector_length(&self->scale)) {
        self->scale.x = (1.0f);
    }
    normalize_vector(&self->scale);
    switch (self->type) {
    case 0:
        play_sound_effect(((TObjEnemy *)(self))->remap_sound_for_area(0x4003BC2B), &self->pos, 0, 0);
        self->f378 = (5.0f);
        self->f37C = (1.0416666f);
        self->f380 = 0xC;
        scale = *(const volatile f32 *)&lbl_805DA5AC;
        break;
    case 1:
        self->f378 = (5.0f);
        self->f37C = (0.0f);
        self->f380 = 0xC;
        scale = *(const volatile f32 *)&lbl_805DA5A8;
        break;
    }
    self->scale.x *= scale;
    self->scale.z *= scale;
}
#undef self


