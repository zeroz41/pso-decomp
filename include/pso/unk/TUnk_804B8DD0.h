#ifndef PSO_UNK_TUNK_804B8DD0_H
#define PSO_UNK_TUNK_804B8DD0_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Gogo-ball goal marker, spawned in pairs by TGoGoBallGame::run_task.
class TUnk_804B8DD0 : public TObject {
public:
    TUnk_804B8DD0(Vec *pos, s32 team0, s32 three_point, s32 lifetime, TObject *parent);
    TUnk_804B8DD0(Vec *pos, s32 team0, s32 lifetime, TObject *parent);
    virtual ~TUnk_804B8DD0();
    void update_effects();
    virtual void render();
    virtual void run_task();
    Vec pos;
    s32 team0;        // the goal scores for team 0 (sync goal flags 1/0x10), else team 1 (2/0x20)
    s32 age;      // inferred: counts frames up to lifetime
    s32 m_30;
    s32 lifetime; // inferred: run_task destroys the marker when age reaches it
    s32 m_38;
    s32 active;   // inferred: set while the sync flags select this marker
    s32 three_point;  // a three-point goal
};
LAYOUT_ASSERT(TUnk_804B8DD0_size, sizeof(TUnk_804B8DD0) == 0x44);

#endif
