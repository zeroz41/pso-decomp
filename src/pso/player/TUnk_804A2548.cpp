#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TUnk_804A2548.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/unk/text_801255EC.h"
#include "pso/item/TItem.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer_80125780.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/weapon/TUnk_804A2564.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"

// Built with -inline off,deferred: functions are written last to first.

extern "C" {
void *TObjPlayer__sub_802E449C(void *a0);
}
void spawn_faust_explosion(u32 a0, const Vec &pos);

u8 *create_panzer_faust(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A2564(tl_05, (u8 *)arg0);
    }
    return NULL;
}

TUnk_804A2564::TUnk_804A2564(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    pad_200 = 0.1f;
    pad_1fc = 0.1f;
    pad_1f8 = 0.1f;
    reload_timer = 0;
    shot_speed = 10.0f;
    set_weapon_flags(0x8000);
    if (get_item_index() == 1) {
        pad_238 = 10.0f;
        descriptor_flags = 0x80;
    } else {
        pad_238 = 2.5f;
        descriptor_flags = 0;
    }
}

TUnk_804A2564::~TUnk_804A2564() {}

void TUnk_804A2564::vfunc_57() { reload_timer = 0; }

void TUnk_804A2564::update_weapon() {
    if (reload_timer > 0) {
        reload_timer--;
    }
}

void TUnk_804A2564::emit_marker_effects() { reload_timer = 60; }

void TUnk_804A2564::vfunc_60() {
    NJS_OBJECT *child;

    if (TObjPlayer::get_player_list() == 1) {
        if (second_model != NULL && reload_timer == 0) {
            child = second_model->child;
            if (child != NULL) {
                child->scl[0] = 0.1f;
                child->scl[1] = 0.1f;
                child->scl[2] = 0.1f;
                child->evalflags &= ~4;
                draw_ginja_object(second_model);
                child->evalflags |= 4;
                child->scl[0] = 1.0f;
                child->scl[1] = 1.0f;
                child->scl[2] = 1.0f;
            }
        }
    }
}

void TUnk_804A2564::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    desc->pad_74 = (void *)spawn_faust_hit_explosion;
    desc->pad_70 = (void *)TObjPlayer::spawn_faust_wall_explosion;
    desc->pad_50 = -0x4000;
    desc->flags |= descriptor_flags;
    desc->pad_78 = 0x1bb;
    desc->pad_7c = 0x1bc;
}

void spawn_faust_explosion(u32 a0, const Vec &pos) {
    if (((TItem *)a0)->get_item_index() == 1) {
        S_802E449C info;
        TObjPlayer__sub_802E449C(&info);
        ((TObjPlayer *)a0)->fill_status_info(&info);
        VecCopy(&info.position, &pos);
        info.hits = 10;
        new TUnk_804A2548(tl_05, &info);
        create_timed_particle_emitter(&info, 0x17F, 0, 10);
    } else {
        Vec v = pos;
        create_timed_particle_emitter(&v, 0x17E, 0, 10);
    }
}

struct Elem_80125628 { u8 pad[0x1c]; u8 f1c[0x2c - 0x1c]; };

struct Obj_80125628 { u8 pad[0xa4]; Elem_80125628 *elems; };

struct Ctx_80125628 { Obj_80125628 *obj; s32 idx; };

void spawn_faust_hit_explosion(s32 arg0, s32 arg1) {
    Ctx_80125628 *ctx = (Ctx_80125628 *)arg1;
    u32 p = (u32)find_item_by_id(arg0);
    if (p != 0U) {
        spawn_faust_explosion(p, *(const Vec *)ctx->obj->elems[ctx->idx].f1c);
    }
}

void TObjPlayer::spawn_faust_wall_explosion(s32 arg0, s32 arg1) {
    u32 temp_r3 = (u32)find_item_by_id(arg0);
    if (temp_r3 != 0U) {
        spawn_faust_explosion(temp_r3, *(const Vec *)arg1);
    }
}

TUnk_804A2548::TUnk_804A2548(TObject *parent, S_802E451C *params) : TUnk_804E355C(parent, params) {
    pad_C4 = 50.0f;
}

TUnk_804A2548::~TUnk_804A2548() {}

void TUnk_804A2548::run_task() {
    f32 radius;

    if (has_game_join_id() != 0) {
        radius = body.radius;
        if (radius < pad_C4) {
            body.radius += 10.0f;
            radius = pad_C4;
            if (radius < body.radius) {
                body.radius = radius;
            }
        } else {
            queue_destruction();
        }
        check_hits();
    }
}
