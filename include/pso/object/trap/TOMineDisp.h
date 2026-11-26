#ifndef PSO_OBJECT_TRAP_TOMINEDISP_H
#define PSO_OBJECT_TRAP_TOMINEDISP_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/NinjaTypes.h"

// One mine's view for one player (spawn_disp_objects makes one per view);
// its parent is the mine it draws.
struct TOMineDisp : public TObjBase {
    TOMineDisp(TObject *parent, u16 client);
    virtual ~TOMineDisp();
    virtual void render();
    virtual void run_task();
    // Whether this is player `id`'s view of the mine and that view has not gone (state 2).
    s32 matches_id(u16 id);
    u32 m_90;
    NJS_ARGB color;  // the constant material colour render draws it with
    s32 state;
    u16 client_id;
    u8 pad_AA[0x2];
};

extern const char *mine_disp_name;

LAYOUT_ASSERT(TOMineDisp_size, sizeof(TOMineDisp) == 0xAC);
#endif
