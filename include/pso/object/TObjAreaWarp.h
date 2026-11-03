#ifndef PSO_OBJECT_TOBJAREAWARP_H
#define PSO_OBJECT_TOBJAREAWARP_H

#include "types.h"
#include "pso/object/TObjWarpBase.h"

struct TObjAreaWarp : public TObjWarpBase {
    virtual ~TObjAreaWarp();
    void handle_area_selection();
    virtual void confirm_area_transfer(s32);
    virtual void debug_print_area_num();
    virtual void open_confirm_window(u16 arg1);
    u16 find_active_player();
    virtual u8 is_warp_enabled();
};

#endif
