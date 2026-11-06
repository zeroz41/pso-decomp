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

extern "C" {

s32 has_game_join_id__13TUnk_804E355CFv();

extern const f32 lbl_805DAD50;

void TUnk_804A2548::run_task() {
    f32 temp_f1;
    f32 temp_f1_2;

    if (has_game_join_id__13TUnk_804E355CFv() != 0) {
        temp_f1 = this->m_40;
        if (temp_f1 < *(f32 *)&this->unk_C4) {
            this->m_40 = (f32) (temp_f1 + lbl_805DAD50);
            temp_f1_2 = *(f32 *)&this->unk_C4;
            if (temp_f1_2 < this->m_40) {
                this->m_40 = temp_f1_2;
            }
        } else {
            queue_destruction__7TObjectFv(this);
        }
        check_hits();
    }
}

}

extern "C" {

void __dl__7TObjectFPv(void *);

extern s32 __vt__13TUnk_804A2548[];

void *__dt__13TUnk_804A2548Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804A2548;
        ((TUnk_804E355C *)arg0)->destroy_attack_collision(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

extern "C" {

int construct_attack_collision(void);

    extern const float lbl_805DAD54;
void*TUnk_804A2548::construct_explosion_collider() { construct_attack_collision(); *(int*)((char*)this + 0x18) = (int)__vt__13TUnk_804A2548; *(float *)&this->unk_C4 = lbl_805DAD54; return this; }

}

struct Elem_80125628 { u8 pad[0x1c]; u8 f1c[0x2c - 0x1c]; };

struct Obj_80125628 { u8 pad[0xa4]; Elem_80125628 *elems; };

struct Ctx_80125628 { Obj_80125628 *obj; s32 idx; };

struct Info_80125678 {
    Vec pos;
    u8 pad0c[0x10 - 0xC];
    s32 f10;
    u8 pad14[0x80 - 0x14];
};

struct Self_8012573C { u8 pad[0x23c]; u32 f23c; };

struct Out_8012573C { u8 pad[0x40]; u32 f40; u8 pad44[0x50 - 0x44]; s32 f50; u8 pad54[0x70 - 0x54]; void *f70; void *f74; s32 f78; s32 f7c; };

extern "C" {
void config_faust_attack_collider__10TObjPlayerFPvPv(Self_8012573C *self, Out_8012573C *out);
}
s32 spawn_faust_explosion(u32 a0, const Vec &pos);
void TObjPlayer::spawn_faust_wall_explosion(s32 arg0, s32 arg1) {
    u32 temp_r3 = (u32)find_item_by_id(arg0);
    if (temp_r3 != 0U) {
        spawn_faust_explosion(temp_r3, *(const Vec *)arg1);
    }
}
void spawn_faust_hit_explosion(s32 arg0, s32 arg1) {
    Ctx_80125628 *ctx = (Ctx_80125628 *)arg1;
    u32 p = (u32)find_item_by_id(arg0);
    if (p != 0U) {
        spawn_faust_explosion(p, *(const Vec *)ctx->obj->elems[ctx->idx].f1c);
    }
}

extern "C" {
void *TObjPlayer__sub_802E449C(void *a0);
void *__nw__7TObjectFUl(u32);
s32 construct_explosion_collider__13TUnk_804A2548Fv(void *, TObject *, void *);
extern TObject *tl_05;
}

s32 spawn_faust_explosion(u32 a0, const Vec &pos) {
    if (((TItem *)a0)->get_item_index() == 1) {
        Info_80125678 info;
        void *o;
        TObjPlayer__sub_802E449C(&info);
        ((TObjPlayer *)a0)->fill_status_info(&info);
        VecCopy(&info.pos, &pos);
        info.f10 = 0xA;
        o = __nw__7TObjectFUl(0xC8);
        if (o != NULL) {
            construct_explosion_collider__13TUnk_804A2548Fv(o, tl_05, &info);
        }
        create_timed_particle_emitter(&info, 0x17F, 0, 10);
    } else {
        Vec v = pos;
        create_timed_particle_emitter(&v, 0x17E, 0, 10);
    }
}

void config_faust_attack_collider__10TObjPlayerFPvPv(Self_8012573C *self, Out_8012573C *out) {
    out->f74 = (void *)spawn_faust_hit_explosion;
    out->f70 = (void *)TObjPlayer::spawn_faust_wall_explosion;
    out->f50 = -0x4000;
    out->f40 |= self->f23c;
    out->f78 = 0x1bb;
    out->f7c = 0x1bc;
}

extern "C" {
u8 *__nw__5TItemFUl(s32);
u8 * __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
}

void TObjPlayer::draw_faust_loaded_projectile() {
    void *temp_r31;
    void *temp_r3;

    if (TObjPlayer::get_player_list() == 1) {
        temp_r3 = *(void **)((s8 *)this + 0x188);
        if ((temp_r3 != NULL) && ((s32) *(s32 *)((s8 *)this + 0x234) == 0)) {
            temp_r31 = *(void **)((s8 *)temp_r3 + 0x2C);
            if (temp_r31 != NULL) {
                *(f32 *)((s8 *)temp_r31 + 0x20) = 0.1f;
                *(f32 *)((s8 *)temp_r31 + 0x24) = 0.1f;
                *(f32 *)((s8 *)temp_r31 + 0x28) = 0.1f;
                *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) & 0xFFFFFFFB);
                draw_ginja_object(*(void **)((s8 *)this + 0x188));
                *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) | 4);
                *(f32 *)((s8 *)temp_r31 + 0x20) = 1.0f;
                *(f32 *)((s8 *)temp_r31 + 0x24) = 1.0f;
                *(f32 *)((s8 *)temp_r31 + 0x28) = 1.0f;
            }
        }
    }
}

void TUnk_804A2564::emit_marker_effects() { *(s32*)((char*)this + 0x234) = 60; }

void TUnk_804A2564::update_weapon() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x234);
    if (temp_r4 > 0) {
        *(s32 *)((s8 *)arg0 + 0x234) = (temp_r4 - 1);
    }
}

void clear_faust_reload_timer(void* p) { *(s32*)((char*)p + 0x234) = 0; }

extern s32 lbl_804A2564[];

void *__dt__13TUnk_804A2564Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A2564;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *construct_panzer_faust(u8 *arg0, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A2564;
    *(f32 *)((s8 *)arg0 + 0x200) = 0.1f;
    ((TUnk_804A2564 *)arg0)->m_1fc = 0.1f;
    *(f32 *)((s8 *)arg0 + 0x1F8) = 0.1f;
    ((TUnk_804A2564 *)arg0)->m_234 = 0;
    *(f32 *)((s8 *)arg0 + 0x1E4) = (f32) lbl_805DAD50;
    ((TItemWeapon *)arg0)->set_weapon_flags(0x8000);
    if (((TItem *)arg0)->get_item_index() == 1) {
        *(f32 *)((s8 *)arg0 + 0x238) = (f32) lbl_805DAD50;
        ((TUnk_804A2564 *)arg0)->m_23c = 0x80;
    } else {
        *(f32 *)((s8 *)arg0 + 0x238) = 2.5f;
        ((TUnk_804A2564 *)arg0)->m_23c = 0;
    }
    return arg0;
}

u8 *create_panzer_faust(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x240));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_panzer_faust((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}
