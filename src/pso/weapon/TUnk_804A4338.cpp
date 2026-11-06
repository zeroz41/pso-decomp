#include "types.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A4338.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/system/task/TMainTask.h"

struct Owner_80129648 { u8 pad[0x60]; s32 f60; };

struct Self_80129648 { u8 pad0[0x24]; s32 f24; u8 pad28[0xF0 - 0x28]; Owner_80129648 *owner; u8 padF4[0x188 - 0xF4]; s32 f188; };

struct Vec_80129648 { f32 x, y, z; };

struct Tec_80129648 {
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
    Vec_80129648 pos;
    Vec_80129648 dir;
};

extern "C" {
s16 get_entity_id(void *);
f32 query_extended_state__10TObjPlayerFv(void *);
void TObjPlayer__sub_80128A70(void);
void init_slicer_launch_state(void *);
s16 get_validated_attack_stage(u8 *arg0);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
}

void TUnk_804A4338::emit_marker_effects() {
    Self_80129648 *self = (Self_80129648 *)this;
    Tec_80129648 tec;
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
    ((TItemWeapon *)self)->get_joint_position(1, &tec.pos);
    ((TItemWeapon *)self)->get_joint_position(2, &tec.dir);
    TTecSlicer::create((u16*)&tec);
}

TUnk_804A4338::TUnk_804A4338(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(2);
}

u8 *create_s_rank_slicer_weapon(u8 *owner) {
    if (owner != NULL) {
        return (u8 *)new TUnk_804A4338(tl_05, owner);
    }
    return NULL;
}

TUnk_804A4338::~TUnk_804A4338() {}
