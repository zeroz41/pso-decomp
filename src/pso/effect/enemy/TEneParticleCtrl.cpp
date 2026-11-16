#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/enemy/TEneParticleCtrl.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80338C88___vt__16TEneParticleCtrl {
    s32 value;
    u8 remaining[0x38];
};

// inferred: TEneParticleCtrl__collision_body, the one body TEneParticleCtrl__ct registers.
CollisionBody TEneParticleCtrl__collision_body = {{0.0f, 0.0f, 0.0f}, 20.0f, 0.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};

const char *TEneParticleCtrl__name = "TEneParticleCtrl";

extern "C" {
u16 get_entity_id(void *);
TParticleCtrl *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
s32 init_collision_body_parts(void *, void *, int);
s32 __ct__14TObjCollidableFP7TObject(void *, void *);
extern s32 __vt__16TEneParticleCtrl[];
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);

void TEneParticleCtrl::set_param(s32 index) { void* m = *(void* *)&this->m_c0; if (m) ((TParticleCtrl *)m)->set_param_ptr(index); }
void TEneParticleCtrl::free_particle_ctrl() { void* m = *(void* *)&this->m_c0; if (m) ((TParticleCtrl *)m)->enable(); }

void *__dt__16TEneParticleCtrlFv(void *collidable, s16 arg1) {
    if (collidable != NULL) {
        *(s32 **)((s8 *)collidable + 0x18) = __vt__16TEneParticleCtrl;
        if (*(void **)((s8 *)collidable + 0xC0) != NULL) { TParticleCtrl::release(*(void **)((s8 *)collidable + 0xC0)); }
        ((TObjCollidable *)collidable)->unregister_object_by_id();
        free_collision_body_parts(collidable);
        __dt__14TObjCollidableFv(collidable, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(collidable);
        }
    }
    return collidable;
}

typedef char RecoveredGlobal_80338C88___vt__16TEneParticleCtrl_size[sizeof(RecoveredGlobal_80338C88___vt__16TEneParticleCtrl) == 0x3C ? 1 : -1];
u8 *TEneParticleCtrl__ct(u8 *arg0, s32 arg1, s32 arg2) {
    u32 temp_r3;
    u8 *temp_r4;
    __ct__14TObjCollidableFP7TObject((void *)arg0, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80338C88___vt__16TEneParticleCtrl *)&__vt__16TEneParticleCtrl).value;
    ((TObject *)arg0)->m_name = TEneParticleCtrl__name;
    init_collision_body_parts(arg0, &TEneParticleCtrl__collision_body, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    temp_r4 = (u8 *)(((TEneParticleCtrl *)arg0)->bodies);
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
    ((TEneParticleCtrl *)arg0)->m_ac = get_entity_id((void *)arg1);
    ((TObjBase *)arg0)->set_position_from((void *)(arg1 + 0x74));
    VecCopy((Vec *)(arg0 + 0xB4), (const Vec *)(arg1 + 0x2FC));
    ((TEneParticleCtrl *)arg0)->m_b0 = arg2;
    ((TEneParticleCtrl *)arg0)->m_c0 = (u32)spawn_continuous_particle_effect_with_flags((arg0 + 0xB4), (((TEneParticleCtrl *)arg0)->m_b0), 0x10);
    temp_r3 = ((TEneParticleCtrl *)arg0)->m_c0;
    if (temp_r3 != 0U) {
        ((TParticleCtrl *)temp_r3)->set_owner_id((int) (((TEneParticleCtrl *)arg0)->entity_id));
    }
    return arg0;
}

void*TEneParticleCtrl::get_field_38_ptr() { return (char*)this + 0x38; }
}
