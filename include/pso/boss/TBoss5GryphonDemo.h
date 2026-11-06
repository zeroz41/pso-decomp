#ifndef PSO_BOSS_TBOSS5GRYPHONDEMO_H
#define PSO_BOSS_TBOSS5GRYPHONDEMO_H

#include "pso/TObject.h"
#include "types.h"

class TBoss5GryphonDemo : public TObject {
public:
    TBoss5GryphonDemo(TObject *parent, s32 arg2, f32 farg0);
    virtual ~TBoss5GryphonDemo();
    virtual void run_task();
    virtual void render();
public:
    void draw_model(void* a1, s32 a2);
    void set_all_entry_flags();
    static void render();
public:
    int get_state();
    void draw_linked_model(void* position, s32 yaw);
};

extern "C" {
void TBoss5GryphonDemo__sub_8006626C(void *p);
}

#endif
