#include "pso/effect/TDPBShower.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TNowLoading.h"
#include "pso/TParticleCtrl.h"

struct RecoveredGlobal_8035D7D0___vt__10TDPBShower {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8035D7D0___vt__10TDPBShower __vt__10TDPBShower;
extern s32 TDPBShower__class_name;
extern const f32 lbl_805E01C4;
u8 *TDPBShower__ct(u8 *arg0, u8 *arg1, u8 *arg2);
int query_teammate_state__9TObjEneDDFv(void*);
extern const f32 lbl_805E01C0;
void* __nw__7TObjectFUl(int);
}

void TDPBShower::run_task() {
    if (query_teammate_state__9TObjEneDDFv(this) == 0) {
        m_position[1] += lbl_805E01C0;
        if (m_2c != NULL) {
            ((TParticleCtrl *)m_2c)->set_position(m_position);
        }
        if (--m_countdown < 0) {
            queue_destruction__7TObjectFv(this);
        }
    }
}

TDPBShower::~TDPBShower() {
    if (m_2c != nullptr) TParticleCtrl::release(m_2c);
}

typedef char RecoveredGlobal_8035D7D0___vt__10TDPBShower_size[sizeof(RecoveredGlobal_8035D7D0___vt__10TDPBShower) == 0x18 ? 1 : -1];
u8 *TDPBShower__ct(u8 *dpb_shower, u8 *arg1, u8 *arg2) {
    u8 *particle_emitter;
    __ct__7TObjectFP7TObject(dpb_shower, arg1);
    *(s32 **)((s8 *)dpb_shower + 0x18) = &__vt__10TDPBShower.value;
    *(s32 *)((s8 *)dpb_shower + 0) = (s32) TDPBShower__class_name;
    ((TDPBShower *)dpb_shower)->m_countdown = 5;
    VecCopy((Vec *)(dpb_shower + 0x1C), (const Vec *)arg2);
    *(f32 *)((s8 *)dpb_shower + 0x20) = (f32) (*(f32 *)((s8 *)dpb_shower + 0x20) + lbl_805E01C4);
    particle_emitter = (u8 *)(create_particle_emitter((dpb_shower + 0x1C), 0x134));
    ((TDPBShower *)dpb_shower)->m_2c = particle_emitter;
    if (particle_emitter != NULL) {
        ((TParticleCtrl *)(((TDPBShower *)dpb_shower)->m_2c))->set_flags(0x40);
    }
    return dpb_shower;
}

void* create_TDPBShower(void* arg0, void* arg1) {
    void* o = __nw__7TObjectFUl(0x30);
    if (o != NULL) {
        o = TDPBShower__ct((u8 *)o, (u8 *)arg0, (u8 *)arg1);
    }
    return o;
}
