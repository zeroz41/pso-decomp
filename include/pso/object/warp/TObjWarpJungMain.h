#ifndef PSO_OBJECT_WARP_TOBJWARPJUNGMAIN_H
#define PSO_OBJECT_WARP_TOBJWARPJUNGMAIN_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjWarpJungMain : public TObjAreaWarp {
    // Declared first: it is the key function (defined last in TObjWarpJungMain.cpp), which puts
    // __vt__16TObjWarpJungMain before __vt__12TObjWarpJung in .data as in the original.
    virtual void debug_print_area_num();
    TObjWarpJungMain(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjWarpJungMain();
    virtual void close_menu();
    virtual void open_confirm_window(s32 client_id);
    virtual s32 is_choice_confirmed_by(s32);
    virtual void confirm_area_transfer(TObjPlayer *player);
    void render();
    void run_task();
    f32 beam_frame;  // frame of the beam motion, advanced 4 a task
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjWarpJungMain_size, sizeof(TObjWarpJungMain) == 0xC8);
#endif
