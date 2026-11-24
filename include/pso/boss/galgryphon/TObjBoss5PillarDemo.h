#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARDEMO_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARDEMO_H

#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"

struct TObjBoss5PillarDemo : public TObjBoss5Pillar {
    TObjBoss5PillarDemo(TObject *parent, Vec *pos);
    virtual ~TObjBoss5PillarDemo();
    static void update_active_pillar();
    static TObjBoss5PillarDemo *create();
};

LAYOUT_ASSERT(TObjBoss5PillarDemo_size, sizeof(TObjBoss5PillarDemo) == 0x4C);

extern "C" {
void TObjBoss5PillarDemo__sub_8028AB38(void);
void TObjBoss5PillarDemo__sub_8028ACE0(void);
void TObjBoss5PillarDemo__sub_8028ACE4(void);
}

struct NJS_OBJECT;
extern "C" {
void clear_child_target_refs(NJS_OBJECT *root, NJS_OBJECT *target);
void clear_chain_flags(NJS_OBJECT *root, NJS_OBJECT *target);
}

#endif
