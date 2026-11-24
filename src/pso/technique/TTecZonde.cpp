#include "pso/player/TargetCursorList.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TTecZondeEff.h"
#include "pso/math/MatrixVector.h"
#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include <stdlib.h>
#include "pso/technique/TechniqueParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecZonde.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/object/base/TObjBase.h"

struct RecoveredFields_8023C558_arg0
{
  u8 unknown_0[0xC4];
  s16 field_C4;
  u8 unknown_C6[0x6];
  f32 field_CC;
  u8 unknown_D0[0x20];
  s16 field_F0;
};


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
    ((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC = (f32) (((RecoveredFields_8023C558_arg0 *) ((u8 *)this))->field_CC * technique_scale_table[6].power);
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

void TObjPlayer::create_tec_zonde(void *source, void *origin, void *targets, s32 level) {
    new TTecZonde((saddr)source, (u8 *)origin, (u8 *)targets, level);
}
void TTecZonde::vfunc_8(void *arg1_arg) {
    VObj_18_0c879f *arg1 = (VObj_18_0c879f *)arg1_arg;
    HitInfo_8023C6B4 h;
    h.type = 3;
    h.power = this->power;
    if (((TUnk_80493450 *)arg1)->test_elt_flag(0, 0x80) == 0) {
        HitInfo_8023C6B4 c = h;
        arg1->m21(((Obj_8023C6B4 *)this)->source, &c, 0, 6, -1);
    }
}

}

#include "pso/technique/TTecLuker.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/TUnk_804CCD78.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/CollisionActorLookup.h"

struct Seg_8023C79C { Vec a; Vec b; f32 len; };
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

TTecZonde::~TTecZonde() {
}

void TTecZonde::render() {  }

#pragma push
#pragma fp_contract on

extern u8 *tl_07;

void TTecZonde::run_task() {
    Zonde_8023C79C *self = (Zonde_8023C79C *)this;
    Seg_8023C79C segs[14];
    Seg_8023C79C *s;
    Vec *pb;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    TObjBase *t;
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
    t = static_cast<TObjBase *>(find_entity_by_id(self->f134));
    if (TTecLuker::is_parents_unqueued((uaddr)t) != 0) {
        for (i = 0; i < 14; i++) {
            s = &segs[i];
            s->a.y = 100.0f + t->position.y;
            if (self->level == 5 && i == 0) {
                s->a.y = 500.0f + t->position.y;
            }
            s->a.x = 13.0f * ((f32)i * (3.0517578e-05f * (f32)rand())) + t->position.x;
            s->a.z = 13.0f * ((f32)i * (3.0517578e-05f * (f32)rand())) + t->position.z;
            s->b.x = t->position.x - s->a.x;
            s->b.y = t->position.y - s->a.y;
            pb = &s->b;
            s->b.z = t->position.z - s->a.z;
            s->len = vector_length(pb);
            if (0.0f != s->len) {
                normalize_vector(pb);
            }
        }
        scale = 0.5f;
        switch (self->level) {
        case 0:
            new TTecZondeEff((TObject *)tl_07, &segs[0].a, &segs[0].b, 0x14000000, 0x14, segs[0].len, 0.5f);
            break;
        case 1:
            scale *= 1.2f;
            new TTecZondeEff((TObject *)tl_07, &segs[0].a, &segs[0].b, 0x14000000, 0x14, segs[0].len, scale);
            break;
        case 2:
            scale *= 1.4f;
            new TTecZondeEff((TObject *)tl_07, &segs[0].a, &segs[0].b, 0x14000000, 0x14, segs[0].len, scale);
            break;
        case 3:
            for (j = 0; j < 3; j++) {
                new TTecZondeEff((TObject *)tl_07, &segs[j].a, &segs[j].b, 0x14000000, 0x14, segs[j].len, 0.5f);
            }
            break;
        case 4:
            scale *= 1.4f;
            for (k = 0; k < 3; k++) {
                new TTecZondeEff((TObject *)tl_07, &segs[k].a, &segs[k].b, 0x14000000, 0x14, segs[k].len, scale);
            }
            break;
        case 5:
            for (l = 0; l < 14; l++) {
                if (l == 0) {
                    new TTecZondeEff((TObject *)tl_07, &segs[l].a, &segs[l].b, 0x14000000, 0x14, segs[l].len, 5.0f);
                } else {
                    new TTecZondeEff((TObject *)tl_07, &segs[l].a, &segs[l].b, 0x14000000, 0x14, segs[l].len, 0.5f);
                }
            }
            break;
        }
        if (self->level != 5) {
            new TUnk_804CCD78(&segs[0].a, &t->position, (TObject *)tl_07, 0x19F);
        }
        {
            s32 h;
            switch (self->level) {
            case 0:
                h = play_sound_effect(0x4002A408, &t->position, 0, 0);
                if (h >= 0) {
                    set_sound_pitch_request(h, 0x100, 0);
                }
                break;
            case 1:
                play_sound_effect(0x4002A408, &t->position, 0, 0);
                break;
            case 2:
            case 3:
                h = play_sound_effect(0x4002A408, &t->position, 0, 0);
                if (h >= 0) {
                    set_sound_pitch_request(h, -0x180, 0);
                }
                break;
            case 4:
                h = play_sound_effect(0x4002A408, &t->position, 0, 0);
                if (h >= 0) {
                    set_sound_pitch_request(h, -0x250, 0);
                }
                break;
            case 5:
                h = play_sound_effect(0x4002A408, &t->position, 0, 0);
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
TTecZonde::TTecZonde(s32 source, u8 *arg2, u8 *target_list, s32 level) : TTecShot(source, (Vec *)arg2, 0, level) {
    m_name = lbl_805D3838;
    init_parameters();
    copy_technique_target_list(&targets, (TargetCursorList *)target_list);
    if (this->source != 0) {
        sourceId = ((TObjBase *)(saddr)this->source)->get_entity_id();
    }
}

}
