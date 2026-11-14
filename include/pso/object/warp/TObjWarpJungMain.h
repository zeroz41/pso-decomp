#ifndef PSO_OBJECT_WARP_TOBJWARPJUNGMAIN_H
#define PSO_OBJECT_WARP_TOBJWARPJUNGMAIN_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjWarpJungMain : public TObjAreaWarp {
    TObjWarpJungMain(TObject *parent, void *set_data);
    virtual ~TObjWarpJungMain();
    virtual void vfunc_14();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(s32);
    void render();
    void run_task();
    f32 m_c4;
};

typedef char TObjWarpJungMain_size[sizeof(TObjWarpJungMain) == 0xC8 ? 1 : -1];
#endif
