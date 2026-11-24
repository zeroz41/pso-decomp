#include "pso/player/TargetCursorList.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TTecZondeEff.h"
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecShot.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TUnk_804CCD78.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

struct Part_80231C58 { u8 pad0[0x1C]; Vec pos; u8 pad28[0x2C - 0x28]; };

struct EntBase_80231C58 { u8 pad[0x18]; };

struct Ent_80231C58 : EntBase_80231C58 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30();
    virtual s32 m31();
    u8 pad1C[0x30 - 0x1C];
    u32 flags;
    u8 pad34[0xA4 - 0x34];
    Part_80231C58 *parts;
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


typedef struct RecoveredFields_8023C558_arg0 RecoveredFields_8023C558_arg0;
#pragma readonly_strings on

const char *TTecGiZonde_name_ref = "TTecGiZonde";

void TTecGiZonde::init_parameters() {
    u8 *arg0 = (u8 *)this;
  TechniqueParams *new_var;
  new_var = calc_technique_parameters(0x7, (int) ((RecoveredFields_8023C558_arg0 *) arg0)->field_C4, 0xFFFF);
  ((TechniqueParams *)(arg0 + 0xCC))->copy((TechniqueParams *)new_var);
  if ((((s16) ((RecoveredFields_8023C558_arg0 *) arg0)->field_C4) >= 0xF) && (TTecCtrl::is_technique_ready() == 0))
  {
    ((RecoveredFields_8023C558_arg0 *) arg0)->field_CC = (f32) (tech_high_level_linear_power_table[7].base + (tech_high_level_linear_power_table[7].per_level * ((RecoveredFields_8023C558_arg0 *) arg0)->field_C4));
    return;
  }
  ((RecoveredFields_8023C558_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_8023C558_arg0 *) arg0)->field_CC + ((f32) (((RecoveredFields_8023C558_arg0 *) arg0)->field_F0 * ((RecoveredFields_8023C558_arg0 *) arg0)->field_C4)));
  if (TTecCtrl::is_technique_ready())
  {
    ((RecoveredFields_8023C558_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_8023C558_arg0 *) arg0)->field_CC * technique_scale_table[7].power);
  }
}


struct Elec_80238E14 { s32 type; f32 val; };

struct VBase_18_9c98dd { char pad[0x18]; };

struct VObj_18_9c98dd : VBase_18_9c98dd {
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
    virtual s32 m21(s32, Elec_80238E14, s32, s32, s32);
};

void TTecGiZonde::vfunc_8(void *arg1_arg) {
    u8 *arg1 = (u8 *)arg1_arg;
    Elec_80238E14 d;
    d.type = 3;
    d.val = this->power;
    ((VObj_18_9c98dd *)(arg1))->m21(this->source, d, 0, 0x7, -1);
}

extern "C" {

#define UNQ(e) TTecLuker::is_parents_unqueued(e)
s32 TTecGiZonde::find_chain_targets() {
    Vec d;
    Vec d2;
    f32 scale = 0.5f;
    f32 len;
    f32 len2;
    Ent_80231C58 *e;
    s32 i;
    Ent_80231C58 *a;
    Ent_80231C58 *b;
    void *p;
    e = (Ent_80231C58 *) find_entity_by_id(targetList.records[0].id);
    if (UNQ((uaddr) e) == 0) {
        return 0;
    }
    d.x = e->parts[targetList.records[0].flag].pos.x - position.x;
    d.y = e->parts[targetList.records[0].flag].pos.y - position.y;
    d.z = e->parts[targetList.records[0].flag].pos.z - position.z;
    len = vector_length(&d);
    if (0.0f != len) {
        normalize_vector(&d);
    }
    switch (band) {
    case 0:
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, (f32)len, 0.5f);
        new TUnk_804CCD78(&e->parts[targetList.records[0].flag].pos, &position, tl_07, 0x19F);
        break;
    case 1:
        scale *= 1.2f;
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, (f32)len, (f32)scale);
        new TUnk_804CCD78(&e->parts[targetList.records[0].flag].pos, &position, tl_07, 0x19F);
        break;
    case 2:
        scale *= 1.4f;
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, (f32)len, (f32)scale);
        new TUnk_804CCD78(&e->parts[targetList.records[0].flag].pos, &position, tl_07, 0x19F);
        break;
    case 3:
        scale *= 1.2f;
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, (f32)len, (f32)scale);
        new TUnk_804CCD78(&e->parts[targetList.records[0].flag].pos, &position, tl_07, 0x19F);
        new TUnk_804CCD78(&e->parts[targetList.records[0].flag].pos, &position, tl_07, 0x188);
        break;
    case 4:
        scale *= 1.4f;
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, (f32)len, (f32)scale);
        new TUnk_804CCD78(&e->parts[targetList.records[0].flag].pos, &position, tl_07, 0x19F);
        new TUnk_804CCD78(&e->parts[targetList.records[0].flag].pos, &position, tl_07, 0x188);
        break;
    case 5:
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, (f32)len, 5.0f);
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, (f32)len, 0.5f);
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, (f32)len, 0.5f);
        new TUnk_804CCD78(&e->parts[targetList.records[0].flag].pos, &position, tl_07, 0x19F);
        new TUnk_804CCD78(&e->parts[targetList.records[0].flag].pos, &position, tl_07, 0x188);
        break;
    }
    if (targetList.count == 1) {
        return 1;
    }
    for (i = 0; i < targetList.count - 1; i++) {
        a = (Ent_80231C58 *) find_entity_by_id(targetList.records[i].id);
        b = (Ent_80231C58 *) find_entity_by_id(targetList.records[i + 1].id);
        if (UNQ((uaddr) a) != 0 && UNQ((uaddr) b) != 0) {
        if ((a->flags & 0x20000000) && (b->flags & 0x20000000) &&
            TObjPlayer::is_valid_and_active((uaddr) a) != 0 && TObjPlayer::is_valid_and_active((uaddr) b) != 0 &&
            a->m31() != 0 && b->m31() != 0) {
            return 0;
        }
        d2.x = b->parts[targetList.records[i].flag].pos.x - a->parts[targetList.records[i + 1].flag].pos.x;
        d2.y = b->parts[targetList.records[i].flag].pos.y - a->parts[targetList.records[i + 1].flag].pos.y;
        d2.z = b->parts[targetList.records[i].flag].pos.z - a->parts[targetList.records[i + 1].flag].pos.z;
        len2 = vector_length(&d2);
        if (0.0f != len2) {
            normalize_vector(&d2);
        }
        scale = 0.5f;
        switch (band) {
        case 0:
            new TTecZondeEff(tl_07, &a->parts[targetList.records[i].flag].pos, &d2, 0x14000000, 20, (f32)len2, 0.5f);
            break;
        case 1:
            scale *= 1.2f;
            new TTecZondeEff(tl_07, &a->parts[targetList.records[i].flag].pos, &d2, 0x14000000, 20, (f32)len2, (f32)scale);
            break;
        case 2:
            scale *= 1.4f;
            new TTecZondeEff(tl_07, &a->parts[targetList.records[i].flag].pos, &d2, 0x14000000, 20, (f32)len2, (f32)scale);
            break;
        case 3:
            scale *= 1.2f;
            new TTecZondeEff(tl_07, &a->parts[targetList.records[i].flag].pos, &d2, 0x14000000, 20, (f32)len2, (f32)scale);
            break;
        case 4:
            scale *= 1.4f;
            new TTecZondeEff(tl_07, &a->parts[targetList.records[i].flag].pos, &d2, 0x14000000, 20, (f32)len2, (f32)scale);
            break;
        case 5:
            new TTecZondeEff(tl_07, &a->parts[targetList.records[i].flag].pos, &d2, 0x14000000, 20, (f32)len2, 5.0f);
            new TTecZondeEff(tl_07, &a->parts[targetList.records[i].flag].pos, &d2, 0x14000000, 20, (f32)len2, 0.5f);
            new TTecZondeEff(tl_07, &a->parts[targetList.records[i].flag].pos, &d2, 0x14000000, 20, (f32)len2, 0.5f);
            break;
        }
        } else {
            return 0;
        }
    }
    return 1;
}

void TTecGiZonde::create(void *caster, Vec *pos, void *targets, s32 level) {
    new TTecGiZonde((saddr)caster, pos, targets, level);
}

TTecGiZonde::~TTecGiZonde() {}

void TTecGiZonde::deliver_chain_hits() {
    s32 i;
    uaddr actor;
    for (i = 0; i < targetList.count; i++) {
        actor = (uaddr)find_entity_by_id(targetList.records[i].id);
        if (TTecLuker::is_parents_unqueued(actor) != 0 && TObjPlayer::is_valid_and_active(actor) != 0) {
            this->vfunc_8((void *)actor);
        }
    }
}

void TTecGiZonde::run_task() {
    this->source = (uaddr)find_entity_by_id(this->sourceId);
    if ((u32) this->source == 0U) {
        queue_destruction();
        return;
    }
    if ((s32) this->targetList.count == 0) {
        queue_destruction();
        return;
    }
    if (find_chain_targets() == 1) {
        deliver_chain_hits();
    }
    queue_destruction();
}
// The chain starts at `pos` with no facing (angle 0).
TTecGiZonde::TTecGiZonde(saddr source, Vec *pos, void *targets, s32 level) : TTecShot(source, pos, 0, level) {
    s32 h;
    m_name = TTecGiZonde_name_ref;
    init_parameters();
    copy_technique_target_list(&this->targetList, (TargetCursorList *)targets);
    switch (band) {
    case 0:
        if ((h = play_sound_effect(0x4002A509, &position, 0, 0)) >= 0) {
            set_sound_pitch_request(h, 0x100, 0);
        }
        break;
    case 1:
        play_sound_effect(0x4002A509, &position, 0, 0);
        break;
    case 2:
    case 3:
        if ((h = play_sound_effect(0x4002A509, &position, 0, 0)) >= 0) {
            set_sound_pitch_request(h, -0x180, 0);
        }
        break;
    case 4:
        if ((h = play_sound_effect(0x4002A509, &position, 0, 0)) >= 0) {
            set_sound_pitch_request(h, -0x250, 0);
        }
        break;
    case 5:
        if ((h = play_sound_effect(0x4002A509, &position, 0, 0)) >= 0) {
            set_sound_pitch_request(h, -0x100, 0);
        }
        break;
    }
    if (this->source != 0U) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}

}
