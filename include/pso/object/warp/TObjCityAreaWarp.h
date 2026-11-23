#ifndef PSO_OBJECT_WARP_TOBJCITYAREAWARP_H
#define PSO_OBJECT_WARP_TOBJCITYAREAWARP_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjCityAreaWarp : public TObjAreaWarp {
    static const char *class_name;
    TObjCityAreaWarp(TObject *parent, void *set_data);
    virtual ~TObjCityAreaWarp();
    virtual void open_confirm_window(s32 client_id);
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(TObjPlayer *player);
    void render();
    void do_warp();
    void run_task();
    static void *create(void *set_data);
    f32 frame;
};

LAYOUT_ASSERT(TObjCityAreaWarp_size, sizeof(TObjCityAreaWarp) == 0xC8);
#endif
