#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARSMOKE_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARSMOKE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TObjBoss5PillarSmoke : public TObject {
    virtual ~TObjBoss5PillarSmoke();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    virtual void render();
    virtual void run_task();
};

typedef char TObjBoss5PillarSmoke_size[sizeof(TObjBoss5PillarSmoke) == 0x28 ? 1 : -1];

// The model-node callback TObjBoss5Pillar::render installs (fn_8028ADDC) and clears (sub_8028ADB0) for a smoke.
extern "C" {
void TObjBoss5PillarDemo__sub_8028AD88(void *a0);
void TObjBoss5PillarDemo__sub_8028ADB0(u32 arg0);
void fn_8028ADDC(void *p);
}
#endif
