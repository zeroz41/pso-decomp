#include "types.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A4238.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/system/task/TMainTask.h"

struct Owner_801293FC { u8 pad[0x60]; s32 f60; };

struct Self_801293FC { u8 pad0[0x24]; s32 f24; u8 pad28[0xF0 - 0x28]; Owner_801293FC *owner; u8 padF4[0x188 - 0xF4]; s32 f188; };

struct Vec_801293FC { f32 x, y, z; };

struct Tec_801293FC {
    s16 id;
    u8 pad2[2];
    s32 f4;
    s32 f8;
    s32 fC;
    s16 f10;
    s16 f12;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    s32 f28;
    u8 pad2C[4];
    Vec_801293FC pos;
    Vec_801293FC dir;
};

extern "C" {
s16 get_entity_id(void *);
f32 query_extended_state__10TObjPlayerFv(void *);
void TObjPlayer__sub_80128A70(void);
void init_slicer_launch_state(void *);
s16 get_validated_attack_stage(u8 *arg0);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
}
void enlarge_s_rank_j_cutter_blade(void *arg0);

void TUnk_804A4238::emit_marker_effects() {
    Self_801293FC *self = (Self_801293FC *)this;
    Tec_801293FC tec;
    TObjPlayer__sub_80128A70();
    init_slicer_launch_state(&tec);
    tec.id = get_entity_id(self->owner);
    tec.fC = ((TItem *)self)->get_item_id();
    tec.f4 = self->f24;
    tec.f8 = self->f188;
    tec.f10 = TObjPlayer__sub_801D2F4C((s16 *)((u8 *)self->owner + 0x7CC));
    tec.f12 = get_validated_attack_stage((u8 *)self->owner + 0x7CC);
    tec.f14 = query_extended_state__10TObjPlayerFv(self->owner);
    tec.f18 = 1.0f;
    tec.f1C = 0.6f;
    tec.f20 = 0.5f;
    tec.f24 = 0.3f;
    tec.f28 = self->owner->f60;
    ((TItemWeapon *)self)->get_joint_position(3, &tec.pos);
    ((TItemWeapon *)self)->get_joint_position(2, &tec.dir);
    TItemAttacker::spawn_item_timer((TObject *)TTecSlicer::create((u16*)&tec), (ItemTimerCallback)enlarge_s_rank_j_cutter_blade, 3);
}

TUnk_804A4238::~TUnk_804A4238() {}

TUnk_804A4238::TUnk_804A4238(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(2);
}

u8 *create_s_rank_j_cutter_weapon(u8 *owner) {
    if (owner != NULL) {
        return (u8 *)new TUnk_804A4238(tl_05, owner);
    }
    return NULL;
}

void enlarge_s_rank_j_cutter_blade(void *arg0) {
    if (arg0 != NULL) {
        *(f32 *)((s8 *)arg0 + 0x68) = 1.6f;
        *(f32 *)((s8 *)arg0 + 0x6C) = 1.6f;
        *(f32 *)((s8 *)arg0 + 0x70) = 1.6f;
    }
}

struct SlicerState_801295FC {
    u16 id;
    u8 pad0[2];
    s32 count;
    u8 pad1[4];
    s32 owner;
    s16 a;
    s16 b;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    u8 pad2[4];
    s32 angle;
};

extern "C" {
void init_slicer_launch_state(void *arg0) {
    SlicerState_801295FC *s = (SlicerState_801295FC *)arg0;
    s->id = 0xFFFF;
    s->owner = -1;
    s->count = 0;
    s->a = -1;
    s->b = -1;
    s->f14 = 1.0f;
    s->f24 = 0.0f;
    s->f20 = 0.0f;
    s->f1C = 0.0f;
    s->f18 = 0.0f;
    s->angle = -0x2AAA;
}
}
