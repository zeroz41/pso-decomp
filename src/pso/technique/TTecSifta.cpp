#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecSifta.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/technique/TTecShot.h"

#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"

#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TargetCursorList.h"

#pragma readonly_strings on


const char *TTecSifta__name = "TTecSifta";


struct Obj_8023ACA8 { u8 pad[0xA6]; s16 state; };

struct VBase_18_b27ba1 { char pad[0x18]; };

struct HitInfo_8023AE8C { s32 type; f32 power; };

struct VObj_18_b27ba1 : VBase_18_b27ba1 {
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
    virtual void m21(void *, HitInfo_8023AE8C *, void *, s32, s32);
};

struct Obj_8023AE8C { u8 pad[0x1C]; u8 *source; u8 pad20[0x74 - 0x20]; f32 power; };



extern "C" {
saddr get_entity_id(int);
int TTecSifta__spawn_sifta_range_effect(void* p);
s32 is_split_screen();
void deliver_technique_to_party_targets(void *);
int spawn_support_tec_range_effect(void*);

int TTecSifta__spawn_sifta_range_effect(void* p) { return spawn_support_tec_range_effect(p); }

void TTecSifta::play_sifta_cast_sound() {
    Obj_8023ACA8 *arg0 = (Obj_8023ACA8 *)this;
    s32 r;
    switch (*(s16 *)&this->m_a6) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002AD14, (u8 *)arg0 + 0x20, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002AD14, (u8 *)arg0 + 0x20, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002AD14, (u8 *)arg0 + 0x20, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
}

void TTecSifta::update_effect_params() {
    u8 *arg0 = (u8 *)this;
    TechniqueParams *res;
    res = calc_technique_parameters(0xD, this->m_a4, 0xFFFF);
    ((TechniqueParams *)(arg0 + 0x74))->copy(res);
    this->m_74 = (f32) (this->m_98 * this->m_a4);
}

void TTecSifta::create_instance(void *source, void *origin, void *targets, s32 level) {
    new TTecSifta(source, origin, targets, level);
}

void TTecSifta::create(void *owner, void *pos, s32 level) {
    new TTecSifta(owner, pos, level);
}

void TTecSifta::vfunc_7(void *arg1_arg) {
    Obj_8023AE8C *arg0 = (Obj_8023AE8C *)this;
    VObj_18_b27ba1 *player = (VObj_18_b27ba1 *)arg1_arg;
    HitInfo_8023AE8C h;
    if (((TObjPlayer *)player)->is_script_controlled() == 0) {
        h.type = 9;
        h.power = arg0->power;
        if (is_split_screen() == 0) {
            TWindowCtrl::show_party_effect((void*)(get_entity_id((saddr)arg0->source)), (void*)(get_entity_id((saddr)player)), (void*)9);
        }
        HitInfo_8023AE8C c = h;
        player->m21(arg0->source, &c, 0, 0xD, -1);
    }
}

}
TTecSifta::~TTecSifta() {

}


void TTecSifta::run_task() {
    uaddr member;
    s32 i;
    source = (uaddr)find_entity_by_id(m_a8);
    if (source == 0) {
        queue_destruction();
        return;
    }
    if (m_13c != 0) {
        if (m_a4 <= 1) {
            vfunc_7((void *)source);
        } else {
            vfunc_7((void *)source);
            if (targets.count != 0) {
                for (i = 0; i < targets.count; i++) {
                    member = (uaddr)find_entity_by_id(targets.records[i].id);
                    if (TTecLuker::is_parents_unqueued(member) != 0) {
                        vfunc_7((void *)member);
                    }
                }
            }
        }
    } else if (m_a4 <= 1) {
        vfunc_7((void *)source);
    } else {
        deliver_technique_to_party_targets(this);
    }
    queue_destruction();
}

#pragma push
#pragma opt_common_subs off
struct Obj_8023ACA8;
TTecSifta::TTecSifta(void *owner, void *pos, void *target_list, s32 level) : TTecPlayerInfluence(owner, pos, level) {
    TObjCollidable *t;
    m_name = TTecSifta__name;
    m_13c = 1;
    copy_technique_target_list(&targets, (TargetCursorList *)target_list);
    update_effect_params();
    t = target;
    if (t != NULL) {
        t->bodies->radius = 5.0f + m_7c;
    }
    if (source != 0U) {
        m_a8 = get_entity_id(source);
    }
    if (m_ac != 0) {
        TTecSifta__spawn_sifta_range_effect(this);
        play_sifta_cast_sound();
    }
}
#pragma pop

TTecSifta::TTecSifta(void *owner, void *pos, s32 level) : TTecPlayerInfluence(owner, pos, level) {
    TObjCollidable *t;
    m_name = TTecSifta__name;
    m_13c = 0;
    update_effect_params();
    t = target;
    if (t != NULL) {
        t->bodies->radius = 5.0f + m_7c;
    }
    if (source != 0U) {
        m_a8 = get_entity_id(source);
    }
    TTecSifta__spawn_sifta_range_effect(this);
    play_sifta_cast_sound();
}

void TTecSifta::render() {  }

