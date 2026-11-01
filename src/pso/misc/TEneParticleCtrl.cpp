#include "types.h"
#include "pso/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TEneParticleCtrl.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TUnk_804EF4E0.h"

struct RecoveredGlobal_80338C88_lbl_804EF458 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80338C88___vt__16TEneParticleCtrl {
    s32 value;
    u8 remaining[0x38];
};

struct O_80338D58 { u8 pad[0x72]; s16 idx; u8 pad2[2]; s16 count; };

extern "C" {
u16 get_entity_id(void *);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
s32 init_collision_body_parts(void *, void *, int);
s32 __ct__14TObjCollidableFP7TObject(void *, void *);
extern RecoveredGlobal_80338C88_lbl_804EF458 lbl_804EF458;
extern s32 __vt__16TEneParticleCtrl[];
extern s32 TEneParticleCtrl__name;
void *get_array_entry__11TWindowBaseFi(void *, s16);
s32 TWindowSubStatusDisp__sub_80338740(void *, void *, void *, void *, void *, void *, void *, void *, void *);
void fn_80338D58(O_80338D58 *arg0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7, void *a8);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);

void TEneParticleCtrl::set_param(s32 index) { void* m = *(void* *)&this->m_c0; if (m) ((TParticleCtrl *)m)->set_param_ptr(index); }
void TEneParticleCtrl::free_particle_ctrl() { void* m = *(void* *)&this->m_c0; if (m) ((TParticleCtrl *)m)->enable(); }

void *__dt__16TEneParticleCtrlFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TEneParticleCtrl;
        if (*(void **)((s8 *)arg0 + 0xC0) != NULL) { TParticleCtrl::release(*(void **)((s8 *)arg0 + 0xC0)); }
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80338C88_lbl_804EF458_size[sizeof(RecoveredGlobal_80338C88_lbl_804EF458) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80338C88___vt__16TEneParticleCtrl_size[sizeof(RecoveredGlobal_80338C88___vt__16TEneParticleCtrl) == 0x3C ? 1 : -1];
u8 *TEneParticleCtrl__ct(u8 *arg0, s32 arg1, s32 arg2) {
    u32 temp_r3;
    u8 *temp_r4;
    __ct__14TObjCollidableFP7TObject((void *)arg0, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80338C88___vt__16TEneParticleCtrl *)&__vt__16TEneParticleCtrl).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TEneParticleCtrl__name;
    init_collision_body_parts(arg0, &lbl_804EF458.value, 1);
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
void fn_80338D58(O_80338D58 *arg0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7, void *a8) {
    if (arg0->idx < arg0->count) {
        TWindowSubStatusDisp__sub_80338740(get_array_entry__11TWindowBaseFi(arg0, arg0->idx), a1, a2, a3, a4, a5, a6, a7, a8);
        arg0->idx += 1;
    }
}

}

extern "C" {
extern const char *lbl_805D4260;
}

void TUnk_804EF4E0::vfunc_6(u32 count, s32 id) {
    s32 i;
    TUnk_804EF4E0::Entry *entry;

    m_name = lbl_805D4260;
    m_20 = id;
    entry_count = 0;
    cursor = 0;
    entry_capacity = count;
    m_78 = 0;
    m_7c = 0;
    state_flags = 0;
    status_display = 0;
    unk_84 = 0;
    for (i = 0; i < (s32)count; i++) {
        entry = (TUnk_804EF4E0::Entry *)get_array_entry(i);
        entry->m_0c = i * 20;
    }
}
