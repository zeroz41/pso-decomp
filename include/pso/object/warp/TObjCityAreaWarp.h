#ifndef PSO_OBJECT_WARP_TOBJCITYAREAWARP_H
#define PSO_OBJECT_WARP_TOBJCITYAREAWARP_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjCityAreaWarp : public TObjAreaWarp {
    TObjCityAreaWarp(TObject *parent, void *set_data);
    virtual ~TObjCityAreaWarp();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(s32);
    void render();
    void do_warp();
    void run_task();
    static void *create(void *arg0);
    f32 m_c4;
};

typedef char TObjCityAreaWarp_size[sizeof(TObjCityAreaWarp) == 0xC8 ? 1 : -1];
#endif
