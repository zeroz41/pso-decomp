#ifndef PSO_OBJECT_WARP_TOBJMAPFORCEWARP_H
#define PSO_OBJECT_WARP_TOBJMAPFORCEWARP_H

#include "types.h"
#include "pso/object/warp/TObjMapWarp.h"

struct TObjMapForceWarp : public TObjMapWarp {
    static const char *class_name;
    TObjMapForceWarp(TObject *parent, void *set_data);
    virtual ~TObjMapForceWarp();
    virtual void run_task();
    void create_warp_id_string(u16 client_id);
    virtual void open_confirm_window(s32);
    virtual s32 is_choice_confirmed_by(s32 client_id);
    virtual void draw_debug_destinations();
    s32 display_number;  // inferred: 0 when set_params[2] > 0; printed as "<- DISP NUMBER"
    virtual void render();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjMapForceWarp_size, sizeof(TObjMapForceWarp) == 0x100);
#endif
