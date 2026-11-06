#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5CTRL_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5CTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjBoss5Ctrl : public TObject {
public:
 void* m_1c;
 void* m_20;
 void* m_24;
 void* m_28;
public:
    virtual ~TObjBoss5Ctrl();
    virtual void run_task();
public:
    static void play_pillar_sound();
    static void *create();
};

extern "C" {
void *TObjBoss5Ctrl__ct(void *boss5_pillar_ctrl, void *parent);
}

#endif
