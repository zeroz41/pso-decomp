#ifndef PSO_OBJECT_TOBJHASHIBASE_H
#define PSO_OBJECT_TOBJHASHIBASE_H
#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

// A bridge that rises into place once its floor switch is set.
// m_ac is its phase: 0 waiting for the switch, 1 rising, 2 raised (its
// collision bodies get enabled), 3 done.
struct TObjHashiBase : public TUnk_804AFBF8 {
    TObjHashiBase(TObject *parent, void *set_data);
    virtual ~TObjHashiBase();
    virtual void run_task();
    virtual void render();
    virtual s32 update_object_view_visibility(f32, f32);
    s32 switchId;      // floor switch that raises it (set param 4)
    f32 raisedHeight;  // the y it rises to
    f32 riseSpeed;     // y step per frame while rising
};
#endif
