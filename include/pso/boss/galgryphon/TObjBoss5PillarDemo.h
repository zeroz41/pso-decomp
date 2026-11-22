#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARDEMO_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARDEMO_H

#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"

struct TObjBoss5PillarDemo : public TObjBoss5Pillar {
    virtual ~TObjBoss5PillarDemo();
    static void update_active_pillar();
    static TObjBoss5PillarDemo *create();
};

LAYOUT_ASSERT(TObjBoss5PillarDemo_size, sizeof(TObjBoss5PillarDemo) == 0x4C);

extern "C" {
u8 *TObjBoss5PillarDemo__ct(TObjBoss5PillarDemo *arg0, saddr parent, saddr arg2);
void TObjBoss5PillarDemo__sub_8028AB38(void);
void TObjBoss5PillarDemo__sub_8028ACE0(void);
void TObjBoss5PillarDemo__sub_8028ACE4(void);
void *__dt__19TObjBoss5PillarDemoFv(void *arg0, s16 arg1);
}

#endif
