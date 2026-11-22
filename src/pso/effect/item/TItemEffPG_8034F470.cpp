#include "pso/unk/TUnk_804CCB28.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "pso/weapon/TItemWeapon.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804F0A00.h"
#include "pso/weapon/TUnk_804F0AF8.h"
#include "pso/weapon/TUnk_804F0908.h"
#include "pso/weapon/TUnk_804F0810.h"
#include "pso/player/TUnk_804A2548.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/item/TUnk_804F0BF0.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/render_util.h"
#include "pso/effect/item/TUnk_804F0C08.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_80120908.h"
#include "pso/system/MatrixOps.h"

struct Elem_80125628 { u8 pad[0x1c]; u8 f1c[0x2c - 0x1c]; };

struct Obj_80125628 { u8 pad[0xa4]; Elem_80125628 *elems; };

struct Ctx_80125628 { Obj_80125628 *obj; s32 idx; };


// Gi Gue bazooka (TUnk_804F0A00), TUnk_804F0AF8 and the fire-explosion spawners: its own
// TU, since its 10.0f literal at 0x805DFE00 sits between two 4-byte pads.
// Built with -inline off,deferred like TItemEffPG.cpp: functions are written last to first.

TItem *TUnk_804F0AF8::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F0AF8(tl_05, item);
    }
    return NULL;
}

TUnk_804F0AF8::TUnk_804F0AF8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
    unk_1F8 = -30947;
    m_1fc = -7281;
}

TUnk_804F0AF8::~TUnk_804F0AF8() {}

void TUnk_804F0AF8::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (saddr)((void*)((void*)16384)), (saddr)((void*)((void*)0))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (saddr)((void*)((void*)3640)), (saddr)((void*)((void*)0))); }

void TUnk_804F0AF8::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (saddr)((void*)((void*)-8192)), (saddr)((void*)((void*)-30947))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (saddr)((void*)((void*)-1820)), (saddr)((void*)((void*)-7281))); }

void TUnk_804F0AF8::reserved_53() { draw_weapon_at_joint((saddr)this, 49); update_trail_slot(0); update_trail_slot(1); }

void TUnk_804F0AF8::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 2:
        rotate_matrix_z(0, this->unk_1F8);
        return;
    case 8:
        rotate_matrix_z(0, this->m_1fc);
        return;
    }
}

TItem *TObjPlayer::create_gi_gue_bazooka(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F0A00(tl_05, item);
    }
    return NULL;
}

TUnk_804F0A00::TUnk_804F0A00(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x8000);
    unk_1F8 = -0x1C71;
    m_1fc = -0x1555;
    unk_200 = 0x238E;
}

TUnk_804F0A00::~TUnk_804F0A00() {}

void TUnk_804F0A00::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (saddr)((void*)((void*)-3640)), (saddr)((void*)((void*)0))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (saddr)((void*)((void*)2730)), (saddr)((void*)((void*)0))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x200), (saddr)((void*)((void*)-1820)), (saddr)((void*)((void*)0))); }

void TUnk_804F0A00::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (saddr)((void*)((void*)1820)), (saddr)((void*)((void*)7281))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (saddr)((void*)((void*)-1820)), (saddr)((void*)((void*)-5461))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x200), (saddr)((void*)((void*)1820)), (saddr)((void*)((void*)9102))); }

void TUnk_804F0A00::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 2:
        rotate_matrix_x(0, this->unk_1F8);
        return;
    case 3:
        rotate_matrix_x(0, this->m_1fc);
        return;
    case 5:
        rotate_matrix_z(0, this->unk_200);
        return;
    case 4:
        rotate_matrix_z(0, -this->unk_200);
        return;
    }
}

void TUnk_804F0A00::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    desc->hit_effect = (void *)TObjPlayer::spawn_fire_explosion_at_item;
    desc->wall_effect = (void *)TObjPlayer::spawn_fire_explosion_for_item;
    desc->flags |= 0x80;
}

void TObjPlayer::spawn_fire_explosion(uaddr a0, saddr a1) {
    Desc_8011E5C4 info;
    void *o;
    TObjPlayer__sub_802E449C(&info);
    ((TItemWeapon *)a0)->fill_status_info(&info);
    VecCopy(&info.position, (const Vec *)a1);
    info.hits = 10;
    new TUnk_804A2548(tl_05, &info);
    o = TObject::operator new(0x64);
    if (o != NULL) {
        create_fire_explosion_effect((u8 *)o, 10.0f, &info.position, 0, tl_particle);
    }
}

void TObjPlayer::spawn_fire_explosion_at_item(s32 arg0, saddr arg1) {
    Ctx_80125628 *ctx = (Ctx_80125628 *)arg1;
    uaddr p = (uaddr)find_item_by_id(arg0);
    if (p != 0U) {
        TObjPlayer::spawn_fire_explosion(p, (s32)((saddr)ctx->obj->elems[ctx->idx].f1c));
    }
}

void TObjPlayer::spawn_fire_explosion_for_item(s32 arg0, s32 arg1) {
    uaddr temp_r3 = (uaddr)find_item_by_id(arg0);
    if (temp_r3 != 0U) {
        TObjPlayer::spawn_fire_explosion(temp_r3, arg1);
    }
}
