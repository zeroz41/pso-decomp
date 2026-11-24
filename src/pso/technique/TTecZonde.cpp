#include "pso/player/TargetCursorList.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TTecZondeEff.h"
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


#pragma readonly_strings on

const char *lbl_805D3838 = "TTecZonde"; // TTecZonde__name

void TTecZonde::init_parameters() {
    TechniqueParams *scaled = calc_technique_parameters(6, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        params.power = (f32)(tech_high_level_linear_power_table[6].base + tech_high_level_linear_power_table[6].per_level * level);
        return;
    }
    params.power = params.power + (f32)(params.power_per_level * level);
    if (TTecCtrl::is_technique_ready()) {
        params.power = params.power * technique_scale_table[6].power;
    }

}



extern "C" {

void TObjPlayer::create_tec_zonde(void *source, void *origin, void *targets, s32 level) {
    new TTecZonde((saddr)source, (u8 *)origin, (u8 *)targets, level);
}
void TTecZonde::apply_to_target(TObjChara *target) {
    DirectAttackPayload hit;
    hit.kind = 3;
    hit.power = this->params.power;
    if (static_cast<TUnk_80493450 *>(target)->test_elt_flag(0, 0x80) == 0) {
        target->receive_direct_attack((void *)source, hit, 0, 6, -1);
    }
}

}

#include "pso/technique/TTecLuker.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/technique/TTecZondeHitEffect.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/CollisionActorLookup.h"

struct Seg_8023C79C { f32 a[3]; f32 b[3]; f32 len; };
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
    TObjChara *t;
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
    t = static_cast<TObjChara *>(find_entity_by_id(self->f134));
    if (TTecLuker::is_parents_unqueued((uaddr)t) != 0) {
        for (i = 0; i < 14; i++) {
            s = &segs[i];
            s->a[1] = 100.0f + t->position.y;
            if (self->level == 5 && i == 0) {
                s->a[1] = 500.0f + t->position.y;
            }
            s->a[0] = 13.0f * ((f32)i * (3.0517578e-05f * (f32)rand())) + t->position.x;
            s->a[2] = 13.0f * ((f32)i * (3.0517578e-05f * (f32)rand())) + t->position.z;
            s->b[0] = t->position.x - s->a[0];
            s->b[1] = t->position.y - s->a[1];
            pb = s->b;
            s->b[2] = t->position.z - s->a[2];
            s->len = vector_length(pb);
            if (0.0f != s->len) {
                normalize_vector((Vec *)pb);
            }
        }
        scale = 0.5f;
        switch (self->level) {
        case 0:
            new TTecZondeEff((TObject *)tl_07, (Vec *)segs[0].a, (Vec *)segs[0].b, 0x14000000, 0x14, segs[0].len, 0.5f);
            break;
        case 1:
            scale *= 1.2f;
            new TTecZondeEff((TObject *)tl_07, (Vec *)segs[0].a, (Vec *)segs[0].b, 0x14000000, 0x14, segs[0].len, scale);
            break;
        case 2:
            scale *= 1.4f;
            new TTecZondeEff((TObject *)tl_07, (Vec *)segs[0].a, (Vec *)segs[0].b, 0x14000000, 0x14, segs[0].len, scale);
            break;
        case 3:
            for (j = 0; j < 3; j++) {
                new TTecZondeEff((TObject *)tl_07, (Vec *)segs[j].a, (Vec *)segs[j].b, 0x14000000, 0x14, segs[j].len, 0.5f);
            }
            break;
        case 4:
            scale *= 1.4f;
            for (k = 0; k < 3; k++) {
                new TTecZondeEff((TObject *)tl_07, (Vec *)segs[k].a, (Vec *)segs[k].b, 0x14000000, 0x14, segs[k].len, scale);
            }
            break;
        case 5:
            for (l = 0; l < 14; l++) {
                if (l == 0) {
                    new TTecZondeEff((TObject *)tl_07, (Vec *)segs[l].a, (Vec *)segs[l].b, 0x14000000, 0x14, segs[l].len, 5.0f);
                } else {
                    new TTecZondeEff((TObject *)tl_07, (Vec *)segs[l].a, (Vec *)segs[l].b, 0x14000000, 0x14, segs[l].len, 0.5f);
                }
            }
            break;
        }
        if (self->level != 5) {
            new TTecZondeHitEffect((Vec *)segs[0].a, &t->position, (TObject *)tl_07, 0x19F);
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
        apply_to_target(t);
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
