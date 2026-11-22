#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMO1_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMO1_H
#include "types.h"
#include "pso/boss/darkfalz/DarkFalzScenePart.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/ModelNodeTables.h"

class TParticleCtrl;
struct AnimationMotion;

class TObjDFDemo1 : public TObjBase {
public:
    TObjDFDemo1(TObject *parent, const Vec *pos, s32 angle);
    static TObjDFDemo1 *create(TObject *parent, const Vec *pos, s32 angle);
    virtual ~TObjDFDemo1();
    virtual void run_task();
    void draw_fading_model();
    void sub_8004E068();
    virtual void render();

    TParticleCtrl *particle_emitters[4];
    // Models from boss4_type1_model_ids (TBoss4Type1's body models), drawn fading out.
    DarkFalzScenePart body_parts[6];
    // Models from boss4_zanzo_bml_index_table, drawn fading in.
    DarkFalzScenePart zanzo_parts[2];
    Vec pos;
    s32 angle;
    s32 timer;
    f32 frame;
    f32 scroll;  // 0..1, advanced by 1/45 a frame
    ModelNodeTables strips;
};
LAYOUT_ASSERT(TObjDFDemo1_size, sizeof(TObjDFDemo1) == 0x130);

#endif
