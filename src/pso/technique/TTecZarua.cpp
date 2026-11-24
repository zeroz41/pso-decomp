#include "pso/player/TargetCursorList.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecZarua.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecCircle.h"

#include <stddef.h>

#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

const char *TTecZarua__name = "TTecZarua";

struct Damage_802386F8 { s32 kind; f32 power; };

struct VBase_802386F8 { char pad[0x18]; };

struct VObj_802386F8 : VBase_802386F8 {
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
    virtual s32 m21(s32, Damage_802386F8, s32, s32, s32, void *);
};

extern "C" {
}

void TTecZarua::calc_range() {
    u8 *arg0 = (u8 *)this;
    TechniqueParams *params = calc_technique_parameters(0xC, this->level, 0xFFFF);
    ((TechniqueParams *)(arg0 + 0x88))->copy(params);
    this->power = (f32)(this->base_power * this->level);
}

void TTecZarua::vfunc_6(void *target_arg) {
    u8 *self = (u8 *)this;
    u8 *target = (u8 *)target_arg;
    Damage_802386F8 d;
    d.kind = 0xc;
    d.power = this->power;
    ((VObj_802386F8 *)target)->m21((s32)this->source, d, (s32)this->attack_context, 0xc, -1, self);
}

void TTecZarua::create_instance(saddr source, Vec *pos, Vec *target, saddr level) {
    new TTecZarua(source, pos, target, level);
}
void TTecZarua::render() {  }

void TTecZarua::run_task() {
    s32 i;
    uaddr id;
    source = (uaddr)find_entity_by_id(sourceId);
    if (source == 0) {
        queue_destruction();
        return;
    }
    if (has_targets != 0) {
        for (i = 0; i < targets.count; i++) {
            id = (uaddr)find_entity_by_id(targets.records[i].id);
            if (TTecLuker::is_parents_unqueued(id) != 0) {
                vfunc_6((void *)id);
            }
        }
    } else {
        apply_technique_to_area_targets();
    }
    queue_destruction();
}

TTecZarua::~TTecZarua() {

}

TTecZarua::TTecZarua(saddr source, Vec *pos, TargetCursorList *list, s32 level) : TTecCircle(source, (saddr)pos, level) {
    s32 r;
    m_name = TTecZarua__name;
    has_targets = 1;
    copy_technique_target_list(&targets, list);
    calc_range();
    VecCopy(&position, pos);
    if (collidable != NULL) {
        collidable->bodies->radius = scope;
    }
    switch (band) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002A817, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002A817, &position, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002A817, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}

TTecZarua::TTecZarua(saddr source, Vec *pos, Vec *target, s32 level) : TTecCircle(source, pos, target, level) {
    s32 r;
    m_name = TTecZarua__name;
    has_targets = 0;
    calc_range();
    VecCopy(&position, &this->target);
    if (collidable != NULL) {
        collidable->bodies->radius = scope;
    }
    switch (band) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002A817, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002A817, &position, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002A817, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}
