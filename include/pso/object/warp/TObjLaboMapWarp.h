#ifndef PSO_OBJECT_WARP_TOBJLABOMAPWARP_H
#define PSO_OBJECT_WARP_TOBJLABOMAPWARP_H

#include "types.h"
#include "pso/object/warp/TObjMapWarp.h"

struct TObjLaboMapWarp : public TObjMapWarp {
    static const char *class_name;
    TObjLaboMapWarp(TObject *parent, void *set_data);
    virtual ~TObjLaboMapWarp();
    virtual void open_confirm_window(s32 client_id);
    virtual void draw_debug_destinations();
    virtual void run_task();
    virtual void render();
    int is_field88_zero();
    void clamp_index();
    static void release_static_resource();
    static void load_static_resource();
    static void *create(void *set_data);
    f32 animation_frame;
};

LAYOUT_ASSERT(TObjLaboMapWarp_size, sizeof(TObjLaboMapWarp) == 0x100);
#endif
