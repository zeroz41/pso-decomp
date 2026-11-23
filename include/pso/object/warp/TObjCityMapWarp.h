#ifndef PSO_OBJECT_WARP_TOBJCITYMAPWARP_H
#define PSO_OBJECT_WARP_TOBJCITYMAPWARP_H

#include "types.h"
#include "pso/object/warp/TObjMapWarp.h"

struct TObjCityMapWarp : public TObjMapWarp {
    static const char *class_name;
    TObjCityMapWarp(TObject *parent, void *set_data);
    virtual ~TObjCityMapWarp();
    virtual void open_confirm_window(s32 client_id);
    virtual void draw_debug_destinations();
    virtual void render();
    virtual void run_task();
    int is_field88_zero();
    void clamp_destination_index();
    static void *create(void *set_data);
    f32 animation_frame;
};

LAYOUT_ASSERT(TObjCityMapWarp_size, sizeof(TObjCityMapWarp) == 0x100);
#endif
