#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include <stdlib.h>
#include "pso/technique/TechniqueParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecZonde.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/unk/TLobby_80226070.h"

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
typedef struct RecoveredFields_8023C558_arg0 RecoveredFields_8023C558_arg0;
#pragma readonly_strings on

const char *lbl_805D3838 = "TTecZonde"; // TTecZonde__name

void TTecZonde::init_parameters() {
  TechniqueParams *new_var;
  new_var = calc_technique_parameters(6, (int) ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_C4, 0xFFFF);
  ((TechniqueParams *)(((u8 *)this) + 0xCC))->copy((TechniqueParams *)new_var);
  if ((((s16) ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_C4) >= 0xF) && (TTecCtrl::is_technique_ready() == 0))
  {
    ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC = (f32) (tech_high_level_linear_power_table[6].base + (tech_high_level_linear_power_table[6].per_level * ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_C4));
    return;
  }
  ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC = (f32) (((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC + ((f32) (((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_F0 * ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_C4)));
  if (TTecCtrl::is_technique_ready())
  {
    ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC = (f32) (((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC * lbl_804CC55C[6].pad_00);
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

void TObjPlayer::create_tec_zonde(void *source, void *origin, void *targets, s32 level) {
    new TTecZonde((saddr)source, (u8 *)origin, (u8 *)targets, level);
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

#include "pso/technique/TTecLuker.h"
#include "pso/unk/text_803D96A8.h"
extern "C" void *__ct__16TargetCursorListFv(void *list);

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

extern "C" {
u16 get_entity_id(void *);
void copy_technique_target_list(void *, void *);

TTecZonde::~TTecZonde() {
}

void TTecZonde::render() {  }

#pragma push
#pragma fp_contract on

void *find_entity_by_id(u16 id);
s32 play_sound_effect(s32, void *, s32, s32);
u8 *construct_helper_effect__11TTecGiZondeFPvPvPvPvi(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4);
f32 vector_length(void *);
extern u8 *tl_07;

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
        ((TObject *)self)->queue_destruction();
        return;
    }
    if (self->f130 == 0) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    t = (Tgt_8023C79C *)find_entity_by_id(self->f134);
    if (TTecLuker::is_parents_unqueued((uaddr)t) != 0) {
        for (i = 0; i < 14; i++) {
            s = &segs[i];
            s->a[1] = 100.0f + t->y;
            if (self->level == 5 && i == 0) {
                s->a[1] = 500.0f + t->y;
            }
            s->a[0] = 13.0f * ((f32)i * (3.0517578e-05f * (f32)rand())) + t->x;
            s->a[2] = 13.0f * ((f32)i * (3.0517578e-05f * (f32)rand())) + t->z;
            s->b[0] = t->x - s->a[0];
            s->b[1] = t->y - s->a[1];
            pb = s->b;
            s->b[2] = t->z - s->a[2];
            s->len = vector_length(pb);
            if (0.0f != s->len) {
                normalize_vector((Vec *)pb);
            }
        }
        scale = 0.5f;
        switch (self->level) {
        case 0:
            o = TObject::operator new(0x260);
            if (o != NULL) {
                ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[0].a, (u8 *)segs[0].b, 0x14000000, 0x14, segs[0].len, 0.5f);
            }
            break;
        case 1:
            scale *= 1.2f;
            o = TObject::operator new(0x260);
            if (o != NULL) {
                ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[0].a, (u8 *)segs[0].b, 0x14000000, 0x14, segs[0].len, scale);
            }
            break;
        case 2:
            scale *= 1.4f;
            o = TObject::operator new(0x260);
            if (o != NULL) {
                ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[0].a, (u8 *)segs[0].b, 0x14000000, 0x14, segs[0].len, scale);
            }
            break;
        case 3:
            for (j = 0; j < 3; j++) {
                o = TObject::operator new(0x260);
                if (o != NULL) {
                    ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[j].a, (u8 *)segs[j].b, 0x14000000, 0x14, segs[j].len, 0.5f);
                }
            }
            break;
        case 4:
            scale *= 1.4f;
            for (k = 0; k < 3; k++) {
                o = TObject::operator new(0x260);
                if (o != NULL) {
                    ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[k].a, (u8 *)segs[k].b, 0x14000000, 0x14, segs[k].len, scale);
                }
            }
            break;
        case 5:
            for (l = 0; l < 14; l++) {
                if (l == 0) {
                    o = TObject::operator new(0x260);
                    if (o != NULL) {
                        ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[l].a, (u8 *)segs[l].b, 0x14000000, 0x14, segs[l].len, 5.0f);
                    }
                } else {
                    o = TObject::operator new(0x260);
                    if (o != NULL) {
                        ((TTecZonde *)o)->construct_bolt_effect(tl_07, (u8 *)segs[l].a, (u8 *)segs[l].b, 0x14000000, 0x14, segs[l].len, 0.5f);
                    }
                }
            }
            break;
        }
        if (self->level != 5) {
            o = TObject::operator new(0x40);
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
                    set_sound_pitch_request(h, 0x100, 0);
                }
                break;
            case 1:
                play_sound_effect(0x4002A408, &t->x, 0, 0);
                break;
            case 2:
            case 3:
                h = play_sound_effect(0x4002A408, &t->x, 0, 0);
                if (h >= 0) {
                    set_sound_pitch_request(h, -0x180, 0);
                }
                break;
            case 4:
                h = play_sound_effect(0x4002A408, &t->x, 0, 0);
                if (h >= 0) {
                    set_sound_pitch_request(h, -0x250, 0);
                }
                break;
            case 5:
                h = play_sound_effect(0x4002A408, &t->x, 0, 0);
                if (h >= 0) {
                    set_sound_pitch_request(h, -0x100, 0);
                }
                break;
            }
        }
    }
    if (t != NULL && TTecLuker::is_parents_unqueued((uaddr)t) != 0 && TObjPlayer::is_valid_and_active((uaddr)t) != 0) {
        this->vfunc_8(t);
    }
    ((TObject *)self)->queue_destruction();
}

#pragma pop
#define arg0 ((u8 *)this)
TTecZonde::TTecZonde(s32 arg1, u8 *arg2, u8 *arg3, s32 arg4) : TUnk_804CCC68(arg1, (Vec *)arg2, 0, arg4) {
    u8 *temp_r3;
    __ct__16TargetCursorListFv((arg0 + 0x130));
    *(s32 *)((s8 *)arg0 + 0) = (saddr) lbl_805D3838;
    ((TTecZonde *)arg0)->init_parameters();
    copy_technique_target_list(arg0 + 0x130, arg3);
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x1C));
    if (temp_r3 != NULL) {
        ((TTecZonde *)arg0)->sourceId = get_entity_id(temp_r3);
    }
}
#undef arg0

}
