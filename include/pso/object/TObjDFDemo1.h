#ifndef PSO_OBJECT_TOBJDFDEMO1_H
#define PSO_OBJECT_TOBJDFDEMO1_H
#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/text_8004AA04.h"

class TParticleCtrl;
struct AnimationMotion;

// One model of the scene: its model, texture list and motion.
struct TObjDFDemo1Part {
    s32 model;
    s32 texlist;
    AnimationMotion *motion;
};

class TObjDFDemo1 : public TObjBase {
public:
    TObjDFDemo1(TObject *parent, const Vec *pos, s32 angle);
    virtual ~TObjDFDemo1();
    virtual void run_task();
    void draw_fading_model();
    void sub_8004E068();
    virtual void render();

    TParticleCtrl *particle_emitters[4];
    // Models from lbl_80485EB0 (TBoss4Type1's body models), drawn fading out.
    TObjDFDemo1Part body_parts[6];
    // Models from boss4_zanzo_bml_index_table, drawn fading in.
    TObjDFDemo1Part zanzo_parts[2];
    Vec pos;
    s32 angle;
    s32 timer;
    f32 frame;
    f32 scroll;  // 0..1, advanced by 1/45 a frame
    ModelNodeTables strips;
};
typedef char TObjDFDemo1_size[sizeof(TObjDFDemo1) == 0x130 ? 1 : -1];

#endif
