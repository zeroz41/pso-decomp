#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMO4_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMO4_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"
#include "pso/unk/text_8004AA04.h"

class TParticleCtrl;
struct TObjFish;

struct TObjDFDemo4 : public TObjBase {
    TObjDFDemo4(TObject *parent, const Vec *pos, s32 angle);
    virtual ~TObjDFDemo4();
    void sub_8004F2A8();
    void sub_8004F1FC();
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0, void *arg1, void *arg2);

    ModelNodeTables node_tables;
    TParticleCtrl *particle_emitters[2];
    TObjDFDemo5Part zanzo_parts[2];
    TObjDFDemo5Part body_parts[3];
    Vec pos;
    s32 angle;
    s32 timer;
    f32 frame;
    TObjFish *node_list; // tracks node_positions
    Vec node_positions[2];
};

typedef char TObjDFDemo4_size[sizeof(TObjDFDemo4) == 0x11C ? 1 : -1];
#endif
