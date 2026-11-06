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
    u32 m_90;
    NJS_ARGB color;  // the constant material colour render draws it with
    u32 m_a4;
    u16 m_a8;
    u8 unk_AA[0x2];
};

extern const char *TOMineDisp__name;

typedef char TOMineDisp_size[sizeof(TOMineDisp) == 0xAC ? 1 : -1];
#endif
