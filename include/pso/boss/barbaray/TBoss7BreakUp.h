#ifndef PSO_BOSS_BARBARAY_TBOSS7BREAKUP_H
#define PSO_BOSS_BARBARAY_TBOSS7BREAKUP_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TBreakUpMdlData;
struct NJS_OBJECT;

struct BarbaRayBreakupPiece {
    Vec position;
    Vec velocity;
    s32 angles[3];
    f32 opacity;
    s32 state;
};
LAYOUT_ASSERT(BarbaRayBreakupPiece_size, sizeof(BarbaRayBreakupPiece) == 0x2C);

// Base of the De Rol Le breakup effects: a TBreakUpMdlData and one 0x2C piece record per node.
class TBoss7BreakUp : public TObject {
public:
    TBoss7BreakUp(TObject *parent);
    virtual ~TBoss7BreakUp();
    void scale_node_velocities_xz();
    void alloc_breakup_model(NJS_OBJECT *root);
    TBreakUpMdlData *model;
    s32 age;        // frames alive; run_task destroys the effect at 0xA0
    s32 count;      // node count, copied from model->m_count
    BarbaRayBreakupPiece *pieces;
};

#endif
