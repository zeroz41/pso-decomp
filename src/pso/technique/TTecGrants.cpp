#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/technique/TTecGrants.h"
#include "pso/unk/TUnk_804CC888.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject_80019A50.h"

#include "pso/technique/TTecCircle.h"
#include "pso/system/task/TObject.h"

#include <stddef.h>
#include "pso/technique/TTecLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TargetCursorList.h"
#include "pso/object/base/TObjBase.h"

struct RecoveredFields_80238D10_arg0
{
  u8 unknown_0[0x78];
  s16 field_78;
  u8 unknown_7A[0xE];
  f32 field_88;
  u8 unknown_8C[0x20];
  s16 field_AC;
};

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
extern s32 tec_grants_class_name;

void TTecGrants::render() {  }

void TTecGrants::vfunc_6(void *target_arg) {
    u8 *self = (u8 *)this;
    u8 *target = (u8 *)target_arg;
    Damage_802386F8 d;
    d.kind = 0x4;
    d.power = this->power;
    ((VObj_802386F8 *)target)->m21((s32)this->source, d, (s32)this->attack_context, 0x9, -1, self);
}
typedef struct RecoveredFields_80238D10_arg0 RecoveredFields_80238D10_arg0;

void TTecGrants::create(void *source, void *origin, void *targets, s32 level) {
    new TTecGrants((saddr)source, (saddr)origin, (saddr)targets, level);
}

void TTecGrants::run_task() {
    uaddr entity;
    source = (uaddr)find_entity_by_id(sourceId);
    if (source == 0) {
        queue_destruction();
        return;
    }
    if (targets.count == 0) {
        queue_destruction();
        return;
    }
    entity = (uaddr)find_entity_by_id(targets.records[0].id);
    if ((TTecLuker::is_parents_unqueued(entity) != 0) && (TObjPlayer::is_valid_and_active(entity) != 0) && (m_148 == 0)) {
        new TUnk_804CC888((u8 *)entity, level, tl_07);
    }
    m_148 = m_148 + 1;
    if (m_148 > 0x1E) {
        if ((entity != 0) && (TTecLuker::is_parents_unqueued(entity) != 0) && (TObjPlayer::is_valid_and_active(entity) != 0)) {
            vfunc_6((void *)entity);
        }
        queue_destruction();
    }
}

}
TTecGrants::~TTecGrants() {

}

TTecGrants::TTecGrants(saddr arg1, saddr origin, saddr target_list, saddr level) : TTecCircle(arg1, origin, level) {
    m_name = (const char *)tec_grants_class_name;
    init_parameters();
    copy_technique_target_list(&targets, (TargetCursorList *)target_list);
    m_148 = 0;
    if (source != 0U) {
        sourceId = ((TObjBase *)(saddr)source)->get_entity_id();
    }
}

