#include "pso/system/NinjaTypes.h"
#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/unk/text_801036CC.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/misc/TTecSlicer_8023B5C8.h"
#include "pso/system/vector.h"
#include "pso/misc/TTecSlicer.h"
#include "pso/TItemAttacker.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8023E480.h"

struct RecoveredGlobal_8023B770_lbl_8044DC20
{
  s32 value;
  u8 remaining[0x44];
};

struct RecoveredFields_8023B770_var_r29
{
  u8 unknown_0[0x5C];
  s32 field_5C;
  s32 field_60;
  s32 field_64;
};

struct Vec_8023B72C { f32 x, y, z; };

struct Obj_8023B72C { u8 pad[0x38]; Vec_8023B72C mid; };

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
    Vec_8023B72C a;
    Vec_8023B72C b;
};

struct Slicer_8023BBB4 {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    u8 pad1c[8];
    s32 f24;
    u8 pad28[0x10];
    Vec_8023B72C pos;
    u8 pad44[0x4C];
    Vec_8023B72C dir;
    Vec_8023B72C v9c;
    Vec_8023B72C va8;
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
    s32 f10c;
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
s32 normalize_vector(s32);
f32 horizontal_distance_squared(s32, s32);
s32 get_next_captured_target(s32, s32, s32, s32, s32);
extern f32 lbl_805DC958;
s32 test_flags_any(void *, s32);
u32 get_player_by_client_id(u16);
s32 __ct__14TSlicerHistoryFv(void *, void *, s32, void *, s32);
u32 __nw__7TObjectFUl(s32);
s32 allow_rendering__7TObjectFv(void *);
s32 copy_position__15TEffStarLight2DFPv(void *, void *);
s32 queue_destruction__7TObjectFv(s32);
void __dl__7TObjectFPv(void *);
void dt__10TTecSlicerFls(void *, int);
extern s32 __vt__10TTecSlicer[];
s32 push_matrix(void);
s32 pop_matrix(void);
extern RecoveredGlobal_8023B770_lbl_8044DC20 TTecSlicer__launch_angle_table;
void destroy_if_set__10TTecSlicerFv(u32);

extern const f32 lbl_805DC954;
void *resolve_hittable_target(u16 actorId, s16 collider);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 rotate_matrix_y(s32, s32);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
void draw_ginja_object(void *child);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805DC95C;
extern const f32 lbl_805DC960;
void disallow_rendering__7TObjectFv(TObject *);
void set_entity_id__8TObjBaseFUs(void *, s32);
f32 *get_weapon_range_record(s32, s32);
s32 get_extended_state__10TObjPlayerFv(s32);
s8 get_captured_target_collider_index(s32);
s32 get_uid__10TObjPlayerFv(s32);
s32 get_captured_target_entry(s32, s32);
s32 get_captured_target_count(s32);
void __ct__8TObjBaseFP7TObject(void *, s32);
void fn_8023B590(void *, s32, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
f32 vector_length(void *);
extern s32 lbl_805D3828;
extern s32 tl_05;
extern const f32 lbl_805DC950;
extern const f32 lbl_805DC964;
u32 csnVector(s32, s32, s32);

void TTecSlicer::reset_fields_1e() { *(u8*)((char*)this + 0x1e) = 0; *(u8*)((char*)this + 0x1f) = 0; }

void TTecSlicer::deliver_target_hit() {
    u8 *arg0 = (u8 *)this;
    f32 dist;
    f32 range;
    s32 temp_r3;
    if (this->targetId != 0xFFFF) {
        dist = horizontal_distance_squared((s32)(arg0 + 0x9C), (s32)(arg0 + 0x38));
        range = *(f32 *)((s8 *)arg0 + 0xB8) + *(f32 *)((s8 *)arg0 + 0xBC);
        if (dist < range * range) {
            temp_r3 = (s32)resolve_hittable_target(this->targetId, *(s8 *)((s8 *)arg0 + 0xC6));
            if (temp_r3 != 0) {
                ((VObj_18_ed5691 *)(*(u8 * *)&this->currentWeapon))->m59(*(s32 *)&this->currentPlayer, temp_r3, *(s16 *)((s8 *)arg0 + 0x11C), *(s8 *)((s8 *)arg0 + 0xC6), this->damageMultiplier);
            }
        }
    }
}

void destroy_on_collision__10TTecSlicerFi(s32 arg0, s32 _w1) {
    if (csnVector(arg0 + 0x44, arg0 + 0x38, 0x8100) != 0U) {
        queue_destruction__7TObjectFv(arg0);
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
typedef struct RecoveredGlobal_8023B770_lbl_8044DC20 RecoveredGlobal_8023B770_lbl_8044DC20;
typedef char RecoveredGlobal_8023B770_lbl_8044DC20_size[((sizeof(RecoveredGlobal_8023B770_lbl_8044DC20)) == 0x48) ? (1) : (-1)];

void TTecSlicer::set_launch_midpoint(void *unused, void *a_arg, void *b_arg) {
    Obj_8023B72C *self = (Obj_8023B72C *)this;
    Vec_8023B72C *a = (Vec_8023B72C *)a_arg;
    Vec_8023B72C *b = (Vec_8023B72C *)b_arg;
    f32 t;
    t = a->x + b->x;
    t *= lbl_805DC954;
    self->mid.x = t;
    t = a->y + b->y;
    t *= lbl_805DC954;
    self->mid.y = t;
    t = a->z + b->z;
    t *= lbl_805DC954;
    self->mid.z = t;
}

void TTecSlicer::init_launch_angles(s32 *arg0, s32 *arg1, s32 arg2) {
  s32 *var_r29;
  s32 *var_r30;
  s32 *var_r3;
  s32 temp_r0;
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
  temp_r0 = ((TObjPlayer *)var_r3)->has_valid_handle() * 3;
  var_r3 = (s32 *)&TTecSlicer__launch_angle_table.value;
  var_r3 = (s32 *)&TTecSlicer__launch_angle_table.value;
  ((RecoveredFields_8023B770_var_r29 *) var_r29)->field_64 = (s32) (*((s32 *) (((s8 *)&TTecSlicer__launch_angle_table.value) + ((var_r31 + temp_r0) * 4))));
  pop_matrix();
}

void TTecSlicer::update() {
    s32 arg0 = (s32)this;
    if (horizontal_distance_squared(arg0 + 0x38, arg0 + 0xA8) < lbl_805DC958) {
        deliver_target_hit();
        if (get_next_captured_target(arg0 + 0xC8, arg0 + 0xA8, arg0 + 0xC4, arg0 + 0xC6, arg0 + 0xBC) == 0) {
            ((FlagWord *)(arg0 + 0xC0))->set(1);
        } else {
            VecCopy((Vec *)(arg0 + 0x90), (const Vec *)(arg0 + 0xA8));
            subtract_vector(arg0 + 0x90, arg0 + 0x38);
        }
        normalize_vector(arg0 + 0x90);
    }
}

}

s32 TTecSlicer::create(u16 *arg0) {
    s32 var_r0;
    s32 var_r31;
    u8 *player;
    var_r31 = 0;
    if (arg0 != NULL) {
        player = (u8 *)(((u8 *)get_player_by_client_id(*(u16 *)((s8 *)arg0 + 0))));
        if (player != NULL) {
            var_r0 = ((s32)__nw__7TObjectFUl(0x140));
            if (var_r0 != 0) {
                var_r0 = TTecSlicer__ct((void *)((void *)var_r0), (void *)((void *)arg0), (void *)((void *)player), player + 0x38, (int)((int) (*(s32 *)((s8 *)player + 0x60))));
            }
            var_r31 = var_r0;
            TItemAttacker::spawn_item_timer(var_r0, (s32)&destroy_if_set__10TTecSlicerFv, 0x5A);
        }
    }
    return var_r31;
}

void TTecSlicer::render() {
    u8 *arg0 = (u8 *)this;
    if (all_parents_unqueued_for_destruction__7TObjectFv() == 0 ||
        ((VObj_18_8023B900 *)arg0)->m8(lbl_805DC95C, lbl_805DC960) == 0 ||
        find_equipped_item(this->weaponHandle) == 0U) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    if (this->useColorOverride != 0) {
        model_render_flags |= 0x10;
        set_constant_material((const NJS_ARGB *)(((f32 *)&this->argb)));
    }
    if (this->textureHandle != 0U && this->model != 0U) {
        set_texlist(this->textureHandle);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x60));
        rotate_matrix_z(0, *(s32 *)((s8 *)arg0 + 0x64));
        rotate_matrix_x(0, *(s32 *)((s8 *)arg0 + 0x5C));
        scale_current_matrix((u8 *)&this->scale);
        draw_ginja_object(this->model);
        set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        TParticleCtrl::end_effect_render();
    }
    pop_matrix();
    model_render_flags = saved_model_render_flags;
}

void run_task__10TTecSlicerFv(u8 *object) {
    s32 temp_r4;
    u8 *var_r31;
    void *new_obj;
    *(u32 *)((s8 *)object + 0x10C) = get_player_by_client_id(*(u16 *)((s8 *)object + 0x114));
    *(u32 *)((s8 *)object + 0x108) = (s32)find_equipped_item(((TTecSlicer *)object)->weaponHandle);
    if (((u32) *(u32 *)((s8 *)object + 0x108) == 0U) || ((u32) *(u32 *)((s8 *)object + 0x10C) == 0U)) {
        queue_destruction__7TObjectFv((s32)object);
        return;
    }
    allow_rendering__7TObjectFv(object);
    if ((s32) ((TTecSlicer *)object)->useColorOverride != 0) {
        var_r31 = object + 0x128;
    } else {
        var_r31 = NULL;
    }
    new_obj = (void *)__nw__7TObjectFUl(0x60);
    if (new_obj != 0U) {
        __ct__14TSlicerHistoryFv(new_obj, object, ((TTecSlicer *)object)->textureHandle, var_r31, ((TTecSlicer *)object)->weaponHandle);
    }
    if (test_flags_any(object + 0xC0, 1) == 0) {
        ((TTecSlicer *)object)->update();
    }
    ((TTecSlicer *)object)->advance_position();
    if ((u32) *(u32 *)((s8 *)object + 0x124) != 0U) {
        copy_position__15TEffStarLight2DFPv(((TTecSlicer *)object)->star, object + 0x38);
    }
    if (test_flags_any(object + 0xC0, 2) != 0) {
        queue_destruction__7TObjectFv((s32)object);
        return;
    }
    temp_r4 = *(s32 *)((s8 *)object + 0x5C);
    *(s32 *)((s8 *)object + 0x5C) = (s32) (temp_r4 + ((TTecSlicer *)object)->spinVelocity);
    destroy_on_collision__10TTecSlicerFi((s32)object, (s32)temp_r4);
    *(u32 *)((s8 *)object + 0x108) = 0U;
    *(u32 *)((s8 *)object + 0x10C) = 0U;
}
void *__dt__10TTecSlicerFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TTecSlicer;
        if (((TTecSlicer *)arg0)->star != NULL) { queue_destruction__7TObjectFv((s32)((void *)(((TTecSlicer *)arg0)->star))); }
        dt__10TTecSlicerFls((s8 *)arg0 + 0xE8, -1);
        dt__10TTecSlicerFls((s8 *)arg0 + 0xC8, -1);
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#define self ((Slicer_8023BBB4 *)arg0)
#define init ((Init_8023BBB4 *)arg1)
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
s32 TTecSlicer__ct(void *arg0, void *arg1, void *arg2, void *arg3, int arg4) {
    s32 c;
    s32 ext;
    s32 i;
    s32 e;
    __ct__8TObjBaseFP7TObject(self, tl_05);
    self->vt = __vt__10TTecSlicer;
    __ct__8FlagWordFv((self->fwd));
    ((TTecSlicer *)(self->fc8))->reset_fields_1e();
    ((TTecSlicer *)(self->fe8))->reset_fields_1e();
    self->f0 = lbl_805D3828;
    disallow_rendering__7TObjectFv((TObject *)self);
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
    self->dir.x = sin_table_lookup(arg4);
    self->dir.y = lbl_805DC950;
    self->dir.z = cos_table_lookup(arg4);
    if (lbl_805DC950 != vector_length(&self->dir)) {
        normalize_vector((s32)&self->dir);
    }
    self->f10c = (s32)arg2;
    self->f108 = (s32)find_item_by_id(self->f118);
    TTecSlicer::init_launch_angles((s32 *)self, (s32 *)self->f10c, init->f28);
    ((TTecSlicer *)self)->set_launch_midpoint((void *)self->f10c, &init->a, &init->b);
    self->fb8 = *get_weapon_range_record(self->f108, 0);
    self->fb4 = lbl_805DC964;
    VecCopy((Vec *)((s32)self + 0x9C), (const Vec *)((s32)self + 0x38));
    VecCopy((Vec *)((s32)self + 0xA8), (const Vec *)((s32)self + 0x38));
    self->fbc = lbl_805DC950;
    ext = get_extended_state__10TObjPlayerFv(self->f10c);
    if (ext != 0) {
        if (get_captured_target_count(ext) == 0) {
            ((FlagWord *)((s32)self->fwd))->set(1);
        } else {
            for (i = 0; i != get_captured_target_count(ext); i++) {
                e = get_captured_target_entry(ext, i);
                c = get_captured_target_collider_index(e);
                fn_8023B590(self->fc8, get_uid__10TObjPlayerFv(e), c);
            }
        }
    }
    self->f124 = 0;
    self->f10c = 0;
    self->f108 = 0;
    self->fc4 = 0xFFFF;
    self->fc6 = 0;
    return (s32)self;
}
#pragma pop
#undef self
#undef init
