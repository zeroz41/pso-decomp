#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecAnti.h"
#include "pso/misc/TTecZonde.h"

struct RecoveredGlobal_8023C558_lbl_804CC510
{
  s32 value;
  u8 remaining[0x48];
};

struct RecoveredGlobal_8023C558_lbl_804CC55C
{
  s32 value;
  u8 remaining[0x94];
};

struct RecoveredFields_8023C558_arg0
{
  u8 unknown_0[0xC4];
  s16 field_C4;
  u8 unknown_C6[0x6];
  f32 field_CC;
  u8 unknown_D0[0x20];
  s16 field_F0;
};

extern "C" {
s32 calc_technique_parameters(int, int, int);
s32 is_technique_ready__8TTecCtrlFv();
extern RecoveredGlobal_8023C558_lbl_804CC510 tech_high_level_linear_power_table;
extern RecoveredGlobal_8023C558_lbl_804CC55C lbl_804CC55C;
typedef struct RecoveredFields_8023C558_arg0 RecoveredFields_8023C558_arg0;
typedef struct RecoveredGlobal_8023C558_lbl_804CC510 RecoveredGlobal_8023C558_lbl_804CC510;
typedef struct RecoveredGlobal_8023C558_lbl_804CC55C RecoveredGlobal_8023C558_lbl_804CC55C;
typedef char RecoveredGlobal_8023C558_lbl_804CC510_size[((sizeof(RecoveredGlobal_8023C558_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_8023C558_lbl_804CC55C_size[((sizeof(RecoveredGlobal_8023C558_lbl_804CC55C)) == 0x98) ? (1) : (-1)];
void TTecZonde::init_parameters() {
  s32 new_var;
  new_var = calc_technique_parameters(6, (int) ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_C4, 0xFFFF);
  ((TTecAnti *)(((u8 *)this) + 0xCC))->copy_params((u8 *)new_var);
  if ((((s16) ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_C4) >= 0xF) && (is_technique_ready__8TTecCtrlFv() == 0))
  {
    ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC = (f32) ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0x18))) + ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0x1A))) * ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_C4));
    return;
  }
  ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC = (f32) (((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC + ((f32) (((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_F0 * ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_C4)));
  if (is_technique_ready__8TTecCtrlFv())
  {
    ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC = (f32) (((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC * (*((f32 *) (((s8 *)&lbl_804CC55C.value) + 0x30))));
  }
}

}

struct VBase_18_0c879f { char pad[0x18]; };

struct HitInfo_8023C6B4 { s32 type; f32 power; };

struct VObj_18_0c879f : VBase_18_0c879f {
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
    virtual void m21(void *, HitInfo_8023C6B4 *, void *, s32, s32);
};

struct Obj_8023C6B4 { u8 pad[0x1C]; void *source; u8 pad20[0xCC - 0x20]; f32 power; };

extern "C" {
s32 test_elt_flag__13TUnk_80493450Fll(void *, s32, s32);
u8 *TTecZonde__ct(u8 *arg0, s32 arg1, u8 *arg2, u8 *arg3, s16 arg4);
void *__nw__7TObjectFUl(int);

void TObjPlayer::create_tec_zonde(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x18C);
    if (o != NULL) {
        ((void *(*)(void *, void *, void *, void *, void *))TTecZonde__ct)(o, arg0, arg1, arg2, arg3);
    }
}
void TTecZonde::vfunc_8(void *arg1_arg) {
    VObj_18_0c879f *arg1 = (VObj_18_0c879f *)arg1_arg;
    HitInfo_8023C6B4 h;
    h.type = 3;
    h.power = this->power;
    if (test_elt_flag__13TUnk_80493450Fll(arg1, 0, 0x80) == 0) {
        HitInfo_8023C6B4 c = h;
        arg1->m21(((Obj_8023C6B4 *)this)->source, &c, 0, 6, -1);
    }
}

}

#include "pso/misc/TTecLuker.h"

struct Seg_8023C79C { f32 a[3]; f32 b[3]; f32 len; };
struct Tgt_8023C79C { u8 pad[0x38]; f32 x, y, z; };
struct Zonde_8023C79C {
    u8 pad0[0x18];
    void *vt;
    void *target;
    u8 pad20[0xC6 - 0x20];
    s16 level;
    u16 id;
    u8 padca[0x130 - 0xCA];
    s32 f130;
    u16 f134;
};

struct RecoveredGlobal_8023CD48___vt__9TTecZonde { s32 value; u8 remaining[0x24]; };
typedef char RecoveredGlobal_8023CD48___vt__9TTecZonde_size[sizeof(RecoveredGlobal_8023CD48___vt__9TTecZonde) == 0x28 ? 1 : -1];

extern "C" {
u16 get_entity_id(void *);
void copy_technique_target_list(void *, void *);
u8 * construct_facing_technique__10TObjPlayerFPviPvii(void *, s32, void *, s32, s16);
extern s32 __vt__9TTecZonde[];
extern s32 lbl_805D3838;
void *__dt__9TTecZondeFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

void *__dt__9TTecZondeFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__9TTecZonde;
        ((TObjPlayer *)arg0)->destroy_technique_effect_resources(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TTecZonde::render() {  }

#pragma push
#pragma fp_contract on

void queue_destruction__7TObjectFv(void *arg0);
void *find_entity_by_id(u16 id);
void update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(s32, void *, s32, s32);
u8 *construct_helper_effect__11TTecGiZondeFPvPvPvPvi(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4);
s32 rand();
f32 vector_length(void *);
void normalize_vector(void *);
extern u8 *tl_07;
extern const f32 lbl_805DC968;
extern const f32 lbl_805DC96C;
extern const f32 lbl_805DC970;
extern const f32 lbl_805DC974;
extern const f32 lbl_805DC978;
extern const f32 lbl_805DC97C;
extern const f32 lbl_805DC980;
extern const f32 lbl_805DC984;
extern const f32 lbl_805DC988;

void TTecZonde::run_task() {
    Zonde_8023C79C *self = (Zonde_8023C79C *)this;
    Seg_8023C79C segs[14];
    Seg_8023C79C *s;
    f32 *pb;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    Tgt_8023C79C *t;
    void *o;
    f32 scale;

    self->target = find_entity_by_id(self->id);
    if (self->target == NULL) {
        queue_destruction__7TObjectFv(self);
        return;
    }
    if (self->f130 == 0) {
        queue_destruction__7TObjectFv(self);
        return;
    }
    t = (Tgt_8023C79C *)find_entity_by_id(self->f134);
    if (TTecLuker::is_parents_unqueued((u32)t) != 0) {
        for (i = 0; i < 14; i++) {
            s = &segs[i];
            s->a[1] = lbl_805DC968 + t->y;
            if (self->level == 5 && i == 0) {
                s->a[1] = lbl_805DC96C + t->y;
            }
            s->a[0] = lbl_805DC970 * ((f32)i * (lbl_805DC974 * (f32)rand())) + t->x;
            s->a[2] = lbl_805DC970 * ((f32)i * (lbl_805DC974 * (f32)rand())) + t->z;
            s->b[0] = t->x - s->a[0];
            s->b[1] = t->y - s->a[1];
            pb = s->b;
            s->b[2] = t->z - s->a[2];
            s->len = vector_length(pb);
            if (lbl_805DC978 != s->len) {
                normalize_vector(pb);
            }
        }
        scale = lbl_805DC97C;
        switch (self->level) {
        case 0:
            o = __nw__7TObjectFUl(0x260);
            if (o != NULL) {
                ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[0].a, (u8 *)segs[0].b, 0x14000000, 0x14, segs[0].len, lbl_805DC97C);
            }
            break;
        case 1:
            scale *= lbl_805DC980;
            o = __nw__7TObjectFUl(0x260);
            if (o != NULL) {
                ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[0].a, (u8 *)segs[0].b, 0x14000000, 0x14, segs[0].len, scale);
            }
            break;
        case 2:
            scale *= lbl_805DC984;
            o = __nw__7TObjectFUl(0x260);
            if (o != NULL) {
                ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[0].a, (u8 *)segs[0].b, 0x14000000, 0x14, segs[0].len, scale);
            }
            break;
        case 3:
            for (j = 0; j < 3; j++) {
                o = __nw__7TObjectFUl(0x260);
                if (o != NULL) {
                    ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[j].a, (u8 *)segs[j].b, 0x14000000, 0x14, segs[j].len, lbl_805DC97C);
                }
            }
            break;
        case 4:
            scale *= lbl_805DC984;
            for (k = 0; k < 3; k++) {
                o = __nw__7TObjectFUl(0x260);
                if (o != NULL) {
                    ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[k].a, (u8 *)segs[k].b, 0x14000000, 0x14, segs[k].len, scale);
                }
            }
            break;
        case 5:
            for (l = 0; l < 14; l++) {
                if (l == 0) {
                    o = __nw__7TObjectFUl(0x260);
                    if (o != NULL) {
                        ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[l].a, (u8 *)segs[l].b, 0x14000000, 0x14, segs[l].len, lbl_805DC988);
                    }
                } else {
                    o = __nw__7TObjectFUl(0x260);
                    if (o != NULL) {
                        ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[l].a, (u8 *)segs[l].b, 0x14000000, 0x14, segs[l].len, lbl_805DC97C);
                    }
                }
            }
            break;
        }
        if (self->level != 5) {
            o = __nw__7TObjectFUl(0x40);
            if (o != NULL) {
                construct_helper_effect__11TTecGiZondeFPvPvPvPvi((u8 *)o, (u8 *)segs, (u8 *)&t->x, tl_07, 0x19F);
            }
        }
        {
            s32 h;
            switch (self->level) {
            case 0:
                h = play_sound_effect(0x4002A408, &t->x, 0, 0);
                if (h >= 0) {
                    update_technique_slot__10TTecRaFoieFl(h, 0x100, 0);
                }
                break;
            case 1:
                play_sound_effect(0x4002A408, &t->x, 0, 0);
                break;
            case 2:
            case 3:
                h = play_sound_effect(0x4002A408, &t->x, 0, 0);
                if (h >= 0) {
                    update_technique_slot__10TTecRaFoieFl(h, -0x180, 0);
                }
                break;
            case 4:
                h = play_sound_effect(0x4002A408, &t->x, 0, 0);
                if (h >= 0) {
                    update_technique_slot__10TTecRaFoieFl(h, -0x250, 0);
                }
                break;
            case 5:
                h = play_sound_effect(0x4002A408, &t->x, 0, 0);
                if (h >= 0) {
                    update_technique_slot__10TTecRaFoieFl(h, -0x100, 0);
                }
                break;
            }
        }
    }
    if (t != NULL && TTecLuker::is_parents_unqueued((u32)t) != 0 && TObjPlayer::is_valid_and_active((u32)t) != 0) {
        this->vfunc_8(t);
    }
    queue_destruction__7TObjectFv(self);
}

#pragma pop
u8 *TTecZonde__ct(u8 *arg0, s32 arg1, u8 *arg2, u8 *arg3, s16 arg4) {
    u8 *temp_r3;
    construct_facing_technique__10TObjPlayerFPviPvii(arg0, arg1, arg2, 0, arg4);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8023CD48___vt__9TTecZonde *)&__vt__9TTecZonde).value;
    ((TObjPlayer *)(arg0 + 0x130))->construct_target_cursor_records();
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D3838;
    ((TTecZonde *)arg0)->init_parameters();
    copy_technique_target_list(arg0 + 0x130, arg3);
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x1C));
    if (temp_r3 != NULL) {
        ((TTecZonde *)arg0)->sourceId = get_entity_id(temp_r3);
    }
    return arg0;
}

}
