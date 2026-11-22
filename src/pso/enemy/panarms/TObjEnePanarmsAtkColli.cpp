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

// Stored in the object name field by the constructor.
const char *TObjEnePanarmsAtkColli_class_name = "TObjEnePanarmsAtkColli";
struct Entry_800E31C4 { s32 id; u8 data[0xC]; };

__declspec(section ".data") s32 TObjEnePanarmsAtkColli__type_index_table[2] = {1, 2};
Vec panarms_atk_zero_vec = {0.0f, 0.0f, 0.0f};

struct Obj_800E31C4 { Entry_800E31C4 *list; Vec *vecs; };

struct Base_800E32C0 { u8 pad[0x18]; };

struct Pair_800E32C0 { s32 a; f32 b; };

struct V_800E32C0 : Base_800E32C0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual f32 m21(s32, void *, s32, s32, s32);
    virtual void v22();
    virtual void m23(void *);
};

struct Obj_800E32C0 { u8 pad0[0x10]; s32 f10; u8 pad1[0x388-0x14]; V_800E32C0 *f388; f32 f38C; };

struct Base_800E3374 { u8 pad[0x18]; };

struct Pair_800E3374 { s32 a; f32 b; };

struct V_800E3374 : Base_800E3374 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual f32 m21(s32, void *, s32, s32, s32);
    virtual void v22();
    virtual void m23(void *);
};

struct Obj_800E3374 { u8 pad0[0x10]; s32 f10; u8 pad1[0x384-0x14]; V_800E3374 *f384; u8 pad2[4]; f32 f38C; };

struct Obj_800E35C8 { u8 pad0[0x38]; Vec pos; u8 pad1[0x378 - 0x44]; f32 f378; };

struct Player_800E35C8 { u8 pad0[0x30]; u32 f30; };

struct Obj_800E3428 { u8 pad0[0x38]; Vec pos; Vec dir; u8 pad1[0x378 - 0x50]; f32 f378; };

struct Obj_800E322C { u8 pad0[0x10]; u32 f10; u8 pad1[0x38 - 0x14]; Vec pos; u8 pad2[0x378 - 0x44]; f32 f378; };

extern "C" {
__declspec(section ".rodata") Pair_800E3374 lbl_8043CDF0[] = { 0 };
__declspec(section ".rodata") Pair_800E32C0 lbl_8043CDF8[] = { 0 };
void fn_800E3374(Obj_800E3374 *target, V_800E3374 *arg1);
f32 horizontal_distance_squared(void *, void *);
extern s32 registered_player_count;
void check_radius_collisions(Obj_800E35C8 *target);
void fn_800E322C(void *p, void *t);
void vec3_add_to(void *, void *);
f32 vector_length(void *);
void subtract_vector(void *, void *);
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
            ((TObjEnePanarmsAtkColli *)target)->sub_800E32C0((V_800E32C0 *)ent);
        }
    }
    VecCopy((Vec *)&target->pos, (const Vec *)&sp);
}

void TObjEnePanarmsAtkColli::sub_800E32C0(void *ent) {
    Pair_800E32C0 sp10 = lbl_8043CDF8[0];
    Pair_800E32C0 sp8;
    sp10.b = ((Obj_800E32C0 *)this)->f38C;
    if (((Obj_800E32C0 *)this)->f388 != ((V_800E32C0 *)ent)) {
        sp8.a = sp10.a; *(s32 *)&sp8.b = *(s32 *)&sp10.b;
        if (0.0f != ((V_800E32C0 *)ent)->m21(((Obj_800E32C0 *)this)->f10, &sp8, 0, -1, -1)) {
            ((V_800E32C0 *)ent)->m23(this);
        }
        ((Obj_800E32C0 *)this)->f388 = ((V_800E32C0 *)ent);
    }
}
void fn_800E3374(Obj_800E3374 *target, V_800E3374 *arg1) {
    Pair_800E3374 sp10 = lbl_8043CDF0[0];
    Pair_800E3374 sp8;
    sp10.b = target->f38C;
    if (target->f384 != arg1) {
        sp8.a = sp10.a; *(s32 *)&sp8.b = *(s32 *)&sp10.b;
        if (0.0f != arg1->m21(target->f10, &sp8, 0, -1, -1)) {
            arg1->m23(target);
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
                    fn_800E3374((Obj_800E3374 *)self, (V_800E3374 *)p);
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
            fn_800E3374((Obj_800E3374 *)(target), (V_800E3374 *)(p));
        }
    }
    fn_800E322C(target, &target->pos);
}

}

struct VBase_18_beae68
{
  char pad[0x18];
};

struct VObj_18_beae68 : VBase_18_beae68 {
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual s32 m92();
};

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
int play_sound_effect(s32, void *, void *, void *);

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

typedef struct VBase_18_beae68 VBase_18_beae68;
typedef struct VObj_18_beae68 VObj_18_beae68;

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


