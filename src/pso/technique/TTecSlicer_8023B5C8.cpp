#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/item/TItem.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/technique/TSlicerHistory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/render/render_util.h"

#include "pso/technique/TTecSlicer.h"
#include "pso/system/task/TObject.h"
#include "pso/math/AngleLookup.h"


typedef struct { f32 r, g, b, a; } Col_8023B220;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;

// The z rotation init_launch_angles gives a slicer, by remaining count + 3 * has_valid_handle.
const s32 TTecSlicer__launch_angle_table[18] = {
    -0x1555, 0x4000, 0x7555, 0x2000, -0x6000, -0x1555, 0x0AAA, 0x4000, -0x0AAA,
    -0x1555, 0x4000, 0x7555, 0x2000, -0x6000, -0x1555, 0x2000, -0x6000, -0x1555,
};

const char *TTecSlicer__name = "TTecSlicer";
const char *TSlicerHistory__name = "TSlicerHistory";

extern "C" {

void TSlicerHistory::render() {
    u8 *arg0 = (u8 *)this;
    if ((s32)this->all_parents_unqueued_for_destruction() == 0 || find_equipped_item((int) (*(s32 *)((s8 *)arg0 + 0x58))) == 0U) {
        return;
    }
    {
        saved_model_render_flags = model_render_flags;
        Col_8023B220 col = *(Col_8023B220 *)((s8 *)arg0 + 0x3C);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x5C) != 0) {
            model_render_flags |= 0x10;
        } else {
            model_render_flags |= 0x20;
            col.r -= 1.0f;
        }
        if (((u32) *(u32 *)((s8 *)arg0 + 0x38) != 0U) && ((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U)) {
            set_texlist(*(u32 *)((s8 *)arg0 + 0x38));
            TParticleCtrl::begin_effect_render();
            push_matrix();
            post_translate_matrix((f32 *)(arg0 + 0x28));
            rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x20)));
            rotate_matrix_z(0, (int) (*(s32 *)((s8 *)arg0 + 0x24)));
            rotate_matrix_x(0, (int) (*(s32 *)((s8 *)arg0 + 0x1C)));
            scale_current_matrix((f32 *)(arg0 + 0x4C));
            set_constant_material((const NJS_ARGB *)(((f32 *)&col)));
            draw_ginja_object((void *)(*(uaddr *)((s8 *)arg0 + 0x34)));
            set_constant_material(&chunk_material_color_half_alpha_f32);
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
        model_render_flags = saved_model_render_flags;
    }
}

void TSlicerHistory::run_task() {
    u8 *arg0 = (u8 *)this;
  *((f32 *) (((s8 *) arg0) + 0x3c)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x3c))) - 0.2f);
  if ((*((f32 *) (((s8 *) arg0) + 0x3c))) < 0.0f)
  {
    *((f32 *) (((s8 *) arg0) + 0x3c)) = 0.0f;
    ((TObject *)arg0)->queue_destruction();
  }
}

s32 __ct__7TObjectFP7TObject();

extern s32 __vt__14TSlicerHistory[];

u8 *__ct__14TSlicerHistoryFv(u8 *object, u8 *tec_slicer, s32 arg2, u8 *arg3, s32 arg4) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)object + 0x18) = __vt__14TSlicerHistory;
    ((TObject *)object)->m_name = TSlicerHistory__name;
    copy_xyz(object + 0x1C, tec_slicer + 0x5C);
    VecCopy((Vec *)(object + 0x28), (const Vec *)(tec_slicer + 0x38));
    *(s32 *)((s8 *)object + 0x38) = arg2;
    if (arg3 != 0U) {
        *(s32 *)((s8 *)object + 0x5C) = 1;
        copy_argb((NJS_ARGB *)(object + 0x3C), (NJS_ARGB *)arg3);
    } else {
        *(s32 *)((s8 *)object + 0x5C) = 0;
        *(f32 *)((s8 *)object + 0x3C) = 1.0f;
        *(f32 *)((s8 *)object + 0x40) = 0.0f;
        *(f32 *)((s8 *)object + 0x44) = 0.0f;
        *(f32 *)((s8 *)object + 0x48) = 0.0f;
    }
    *(s32 *)((s8 *)object + 0x34) = ((TTecSlicer *)tec_slicer)->get_field_110();
    VecCopy((Vec *)(object + 0x4C), (const Vec *)(tec_slicer + 0x68));
    *(s32 *)((s8 *)object + 0x58) = arg4;
    return object;
}

}


typedef struct TObjPlayer_8023B454 {
    u8 pad0[0xA4];
    f32 (*bodies)[11];
} TObjPlayer_8023B454;

extern "C" {
void *resolve_hittable_target(u16 actorId, s16 collider);
s32 get_next_captured_target(TTecSlicerTargets_8023B454 *self, Vec *out_pos, u16 *out_id, s8 *out_part, f32 *out_f) {
    TObjPlayer_8023B454 *hit;
    s32 found;
    if (out_pos == NULL) {
        goto fail;
    }
    while (self->idx < self->count && self->idx < 10) {
        found = 0;
        hit = (TObjPlayer_8023B454 *)resolve_hittable_target(self->ids[self->idx], self->parts[self->idx]);
        if (hit != NULL) {
            *out_id = self->ids[self->idx];
            *out_part = self->parts[self->idx];
            VecCopy(out_pos, (const Vec *)&hit->bodies[self->parts[self->idx]][7]);
            found = 1;
            *out_f = hit->bodies[self->parts[self->idx]][3];
        }
        self->idx++;
        if (found != 0) {
            return 1;
        }
    }
fail:
    *out_id = 0xFFFF;
    *out_part = 0;
    return 0;
}

void fn_8023B590(TTecSlicerTargets_8023B454 *o, u16 v, s8 b) {
    if (o->count < 10) {
        o->ids[o->count] = v;
        o->parts[o->count] = b;
        o->count++;
    }
}

}

#include "pso/effect/TEffStarLight2D.h"


#include "pso/unk/text_801036CC.h"
#include "pso/system/data/FlagWord.h"


#include "pso/technique/TTecSlicer_8023B5C8.h"


#include "pso/weapon/TItemAttacker.h"
#include "pso/system/task/TMainTask.h"


struct RecoveredFields_8023B770_var_r29
{
  u8 unknown_0[0x5C];
  s32 field_5C;
  s32 field_60;
  s32 field_64;
};

struct Obj_8023B72C { u8 pad[0x38]; Vec mid; };

struct VBase_18_ed5691 { char pad[0x18]; };

struct VObj_18_ed5691 : VBase_18_ed5691 {
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
    virtual s32 m59(s32, s32, s16, s32, f32);
};

struct VBase_18_8023B900 { char pad[0x18]; };

struct VObj_18_8023B900 : VBase_18_8023B900 {
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

struct Init_8023BBB4 {
    u16 f0;
    u8 pad2[2];
    s32 f4;
    s32 f8;
    s32 fc;
    s16 f10;
    s16 f12;
    f32 f14;
    u8 color[0x10];
    s32 f28;
    s32 f2c;
    Vec a;
    Vec b;
};

struct Slicer_8023BBB4 {
    const char *name;
    u8 pad4[0x14];
    void *vt;
    u8 pad1c[8];
    s32 f24;
    u8 pad28[0x10];
    Vec pos;
    u8 pad44[0x4C];
    Vec dir;
    Vec v9c;
    Vec va8;
    f32 fb4;
    f32 fb8;
    f32 fbc;
    u8 fwd[4];
    u16 fc4;
    s8 fc6;
    u8 pad_c7;
    u8 fc8[0x20];
    u8 fe8[0x20];
    s32 f108;
    saddr f10c;
    s32 f110;
    u16 f114;
    u8 pad116[2];
    s32 f118;
    s16 f11c;
    s16 f11e;
    f32 f120;
    s32 f124;
    u8 color[0x10];
    s32 f138;
    s32 f13c;
};

extern "C" {
s32 subtract_vector(s32, s32);
s32 test_flags_any(s32 *flags, s32 mask);
void *get_player_by_client_id(s32 i);

void destroy_if_set__10TTecSlicerFv(u32);

f32 *get_weapon_range_record(s32, s32);
s8 get_captured_target_collider_index(s32);
s32 get_captured_target_entry(s32, s32);
s32 get_captured_target_count(s32);
f32 vector_length(void *);
u32 csnVector(s32, s32, s32);

TTecSlicerTargets_8023B454::TTecSlicerTargets_8023B454() { count = 0; idx = 0; }

void TTecSlicer::deliver_target_hit() {
    u8 *arg0 = (u8 *)this;
    f32 dist;
    f32 range;
    s32 temp_r3;
    if (this->targetId != 0xFFFF) {
        dist = horizontal_distance_squared((const Vec *)(arg0 + 0x9C), (const Vec *)(arg0 + 0x38));
        range = *(f32 *)((s8 *)arg0 + 0xB8) + *(f32 *)((s8 *)arg0 + 0xBC);
        if (dist < range * range) {
            temp_r3 = (saddr)resolve_hittable_target(this->targetId, *(s8 *)((s8 *)arg0 + 0xC6));
            if (temp_r3 != 0) {
                ((VObj_18_ed5691 *)(*(u8 * *)&this->currentWeapon))->m59(*(s32 *)&this->currentPlayer, temp_r3, *(s16 *)((s8 *)arg0 + 0x11C), *(s8 *)((s8 *)arg0 + 0xC6), this->damageMultiplier);
            }
        }
    }
}

void destroy_on_collision__10TTecSlicerFi(saddr arg0, s32 _w1) {
    if (csnVector(arg0 + 0x44, arg0 + 0x38, 0x8100) != 0U) {
        ((TObject *)arg0)->queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
void TTecSlicer::advance_position() {
    u8 *arg0 = (u8 *)this;
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) ((*(f32 *)((s8 *)arg0 + 0x90) * *(f32 *)((s8 *)arg0 + 0xB4)) + *(f32 *)((s8 *)arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) ((*(f32 *)((s8 *)arg0 + 0x94) * *(f32 *)((s8 *)arg0 + 0xB4)) + *(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) ((*(f32 *)((s8 *)arg0 + 0x98) * *(f32 *)((s8 *)arg0 + 0xB4)) + *(f32 *)((s8 *)arg0 + 0x40));
}
#pragma pop

typedef struct RecoveredFields_8023B770_var_r29 RecoveredFields_8023B770_var_r29;

void TTecSlicer::set_launch_midpoint(void *unused, void *a_arg, void *b_arg) {
    Obj_8023B72C *self = (Obj_8023B72C *)this;
    Vec *a = (Vec *)a_arg;
    Vec *b = (Vec *)b_arg;
    f32 t;
    t = a->x + b->x;
    t *= 0.5f;
    self->mid.x = t;
    t = a->y + b->y;
    t *= 0.5f;
    self->mid.y = t;
    t = a->z + b->z;
    t *= 0.5f;
    self->mid.z = t;
}

void TTecSlicer::init_launch_angles(s32 *arg0, s32 *arg1, s32 arg2) {
  s32 *var_r29;
  s32 *var_r30;
  s32 *var_r3;
  s32 var_r31;
  var_r29 = arg0;
  var_r30 = (s32 *) arg1;
  var_r31 = arg2;
  push_matrix();
  ((RecoveredFields_8023B770_var_r29 *) var_r29)->field_60 = var_r31;
  var_r3 = (s32 *) var_r29;
  ((RecoveredFields_8023B770_var_r29 *) var_r29)->field_5C = -0x4000;
  var_r31 = (s32) ((TTecSlicer *)var_r3)->get_remain_count();
  var_r3 = (s32 *) var_r30;
  ((RecoveredFields_8023B770_var_r29 *) var_r29)->field_64 = TTecSlicer__launch_angle_table[var_r31 + (((TObjPlayer *)var_r3)->has_valid_handle() * 3)];
  pop_matrix();
}

void TTecSlicer::update() {
    saddr arg0 = (saddr)this;
    if (horizontal_distance_squared(&this->position, (const Vec *)this->destination) < 100.0f) {
        deliver_target_hit();
        if (get_next_captured_target(&this->capturedTargets, (Vec *)this->destination, &this->targetId, (s8 *)&this->targetPart, &this->radius) == 0) {
            ((FlagWord *)(arg0 + 0xC0))->set(1);
        } else {
            VecCopy((Vec *)(arg0 + 0x90), (const Vec *)(arg0 + 0xA8));
            subtract_vector(arg0 + 0x90, arg0 + 0x38);
        }
        normalize_vector((Vec *)this->direction);
    }
}

}

saddr TTecSlicer::create(u16 *arg0) {
    saddr var_r31;
    u8 *player;
    var_r31 = 0;
    if (arg0 != NULL) {
        player = (u8 *)(((u8 *)get_player_by_client_id(*(u16 *)((s8 *)arg0 + 0))));
        if (player != NULL) {
            var_r31 = (saddr)new TTecSlicer(arg0, player, (Vec *)(player + 0x38), *(s32 *)((s8 *)player + 0x60));
            TItemAttacker::spawn_item_timer((TObject *)var_r31, (ItemTimerCallback)destroy_if_set__10TTecSlicerFv, 0x5A);
        }
    }
    return var_r31;
}

void TTecSlicer::render() {
    u8 *arg0 = (u8 *)this;
    if ((s32)this->all_parents_unqueued_for_destruction() == 0 ||
        ((VObj_18_8023B900 *)arg0)->m8(400.0f, 20.0f) == 0 ||
        find_equipped_item(this->weaponHandle) == 0U) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    if (this->useColorOverride != 0) {
        model_render_flags |= 0x10;
        set_constant_material((const NJS_ARGB *)(((f32 *)&this->argb)));
    }
    if (this->texlist != 0U && this->model != 0U) {
        set_texlist(this->texlist);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        post_translate_matrix((f32 *)&this->position);
        rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x60));
        rotate_matrix_z(0, *(s32 *)((s8 *)arg0 + 0x64));
        rotate_matrix_x(0, *(s32 *)((s8 *)arg0 + 0x5C));
        scale_current_matrix((f32 *)&this->scale);
        draw_ginja_object(this->model);
        set_constant_material(&chunk_material_color_half_alpha_f32);
        TParticleCtrl::end_effect_render();
    }
    pop_matrix();
    model_render_flags = saved_model_render_flags;
}

#pragma push
#pragma opt_common_subs off
#define object ((u8 *)this)
void TTecSlicer::run_task() {
    s32 temp_r4;
    u8 *var_r31;
    void *new_obj;
    *(u32 *)((s8 *)object + 0x10C) = (uaddr)get_player_by_client_id(*(u16 *)((s8 *)object + 0x114));
    *(u32 *)((s8 *)object + 0x108) = (saddr)find_equipped_item(((TTecSlicer *)object)->weaponHandle);
    if (((u32) *(u32 *)((s8 *)object + 0x108) == 0U) || ((u32) *(u32 *)((s8 *)object + 0x10C) == 0U)) {
        ((TObject *)object)->queue_destruction();
        return;
    }
    ((TObject *)object)->allow_rendering();
    if ((s32) ((TTecSlicer *)object)->useColorOverride != 0) {
        var_r31 = object + 0x128;
    } else {
        var_r31 = NULL;
    }
    new_obj = (void *)TObject::operator new(0x60);
    if (new_obj != 0U) {
        __ct__14TSlicerHistoryFv((u8 *)new_obj, object, ((TTecSlicer *)object)->texlist, var_r31, ((TTecSlicer *)object)->weaponHandle);
    }
    if (test_flags_any((s32 *)(object + 0xC0), 1) == 0) {
        ((TTecSlicer *)object)->update();
    }
    ((TTecSlicer *)object)->advance_position();
    if ((u32) *(u32 *)((s8 *)object + 0x124) != 0U) {
        ((TEffStarLight2D *)((TTecSlicer *)object)->star)->copy_position((const Vec *)(object + 0x38));
    }
    if (test_flags_any((s32 *)(object + 0xC0), 2) != 0) {
        ((TObject *)object)->queue_destruction();
        return;
    }
    temp_r4 = *(s32 *)((s8 *)object + 0x5C);
    *(s32 *)((s8 *)object + 0x5C) = (s32) (temp_r4 + ((TTecSlicer *)object)->spinVelocity);
    destroy_on_collision__10TTecSlicerFi((saddr)object, (s32)temp_r4);
    *(u32 *)((s8 *)object + 0x108) = 0U;
    *(u32 *)((s8 *)object + 0x10C) = 0U;
}
#undef object
#pragma pop

TTecSlicer::~TTecSlicer() {
    if (star != NULL) { ((TObject *)star)->queue_destruction(); }
}

#define self ((Slicer_8023BBB4 *)this)
#define init ((Init_8023BBB4 *)launch)
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
TTecSlicer::TTecSlicer(u16 *launch, void *player, Vec *position, int angle) : TObjBase(tl_05) {
    s32 c;
    saddr ext;
    s32 i;
    saddr e;
    self->name = TTecSlicer__name;
    ((TObject *)((TObject *)self))->TObject::disallow_rendering();
    ((TObjBase *)self)->set_entity_id(pop_free_entity_id());
    self->f110 = init->f8;
    self->f24 = init->f4;
    self->f114 = init->f0;
    self->f118 = init->fc;
    self->f11c = init->f10;
    self->f11e = init->f12;
    self->f120 = init->f14;
    copy_argb((NJS_ARGB *)self->color, (NJS_ARGB *)init->color);
    self->f138 = init->f2c;
    self->f13c = 1;
    self->dir.x = sin_table_lookup(angle);
    self->dir.y = 0.0f;
    self->dir.z = cos_table_lookup(angle);
    if (0.0f != vector_length(&self->dir)) {
        normalize_vector(&self->dir);
    }
    self->f10c = (saddr)player;
    self->f108 = (saddr)find_item_by_id(self->f118);
    TTecSlicer::init_launch_angles((s32 *)self, (s32 *)self->f10c, init->f28);
    ((TTecSlicer *)self)->set_launch_midpoint((void *)self->f10c, &init->a, &init->b);
    self->fb8 = *get_weapon_range_record(self->f108, 0);
    self->fb4 = 6.0f;
    VecCopy((Vec *)((saddr)self + 0x9C), (const Vec *)((saddr)self + 0x38));
    VecCopy((Vec *)((saddr)self + 0xA8), (const Vec *)((saddr)self + 0x38));
    self->fbc = 0.0f;
    ext = (saddr)((TObjPlayer *)self->f10c)->get_extended_state();
    if (ext != 0) {
        if (get_captured_target_count(ext) == 0) {
            ((FlagWord *)((saddr)self->fwd))->set(1);
        } else {
            for (i = 0; i != get_captured_target_count(ext); i++) {
                e = get_captured_target_entry(ext, i);
                c = get_captured_target_collider_index(e);
                fn_8023B590((TTecSlicerTargets_8023B454 *)self->fc8, ((TObjPlayer *)e)->get_uid(), c);
            }
        }
    }
    self->f124 = 0;
    self->f10c = 0;
    self->f108 = 0;
    self->fc4 = 0xFFFF;
    self->fc6 = 0;
}
#pragma pop
#undef self
#undef init

TSlicerHistory::~TSlicerHistory() {}

s32 TTecSlicer::get_field_110() { return *(s32 *)&this->model; }
s16 TTecSlicer::get_remain_count() { return *(s16*)((char*)this + 0x11e); }
void TTecSlicer::destroy_if_set() {
    uaddr arg0 = (uaddr)this;
    if (arg0 != 0U) {
        ((TObject *)arg0)->queue_destruction();
    }
}
TTecSlicerTargets_8023B454::~TTecSlicerTargets_8023B454() {}
