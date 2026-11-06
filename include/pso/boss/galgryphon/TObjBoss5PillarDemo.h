#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARDEMO_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARDEMO_H

#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"

struct TObjBoss5PillarDemo : public TObjBoss5Pillar {
    virtual ~TObjBoss5PillarDemo();
    static void update_active_pillar();
    static s32 create();
};

typedef char TObjBoss5PillarDemo_size[sizeof(TObjBoss5PillarDemo) == 0x4C ? 1 : -1];

extern "C" {
u8 *TObjBoss5PillarDemo__ct(TObjBoss5PillarDemo *arg0, s32 arg1, s32 arg2);
void TObjBoss5PillarDemo__sub_8028AB38(void);
void TObjBoss5PillarDemo__sub_8028ACE0(void);
void TObjBoss5PillarDemo__sub_8028ACE4(void);
void TObjBoss5PillarDemo__sub_8028AD88(void *a0);
void TObjBoss5PillarDemo__sub_8028ADB0(u32 arg0);
void *__dt__19TObjBoss5PillarDemoFv(void *arg0, s16 arg1);
}

extern "C" {
void fn_8028ADDC(void *p);
}

#endif
