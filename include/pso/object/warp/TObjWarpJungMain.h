#ifndef PSO_OBJECT_WARP_TOBJWARPJUNGMAIN_H
#define PSO_OBJECT_WARP_TOBJWARPJUNGMAIN_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjWarpJungMain : public TObjAreaWarp {
    // Declared first: it is the key function (defined last in TObjWarpJungMain.cpp), which puts
    // __vt__16TObjWarpJungMain before __vt__12TObjWarpJung in .data as in the original.
    virtual void debug_print_area_num();
    TObjWarpJungMain(TObject *parent, void *set_data);
    virtual ~TObjWarpJungMain();
    virtual void vfunc_14();
    virtual void open_confirm_window(s32 client_id);
    virtual s32 vfunc_18(s32);
    virtual void confirm_area_transfer(s32);
    void render();
    void run_task();
    f32 m_c4;
};

typedef char TObjWarpJungMain_size[sizeof(TObjWarpJungMain) == 0xC8 ? 1 : -1];
#endif
