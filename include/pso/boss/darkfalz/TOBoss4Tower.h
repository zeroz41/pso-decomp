#ifndef PSO_BOSS_DARKFALZ_TOBOSS4TOWER_H
#define PSO_BOSS_DARKFALZ_TOBOSS4TOWER_H

#include "types.h"
#include "pso/boss/darkfalz/TOBoss4.h"

struct TOBoss4Tower : public TOBoss4 {
    TOBoss4Tower(void *set_data);
    virtual ~TOBoss4Tower();
    virtual void render();
    static void *create(void *set_data);
    static const char *class_name;
};

typedef char TOBoss4Tower_size[sizeof(TOBoss4Tower) == 0x98 ? 1 : -1];
#endif
