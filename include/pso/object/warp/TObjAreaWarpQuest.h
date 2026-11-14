#ifndef PSO_OBJECT_WARP_TOBJAREAWARPQUEST_H
#define PSO_OBJECT_WARP_TOBJAREAWARPQUEST_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjAreaWarpQuest : public TObjAreaWarp {
    TObjAreaWarpQuest(TObject *parent, void *set_data);
    virtual ~TObjAreaWarpQuest();
    virtual void debug_print_area_num();
    void render();
    void run_task();
    s32 get_dest_area();
    u8 unk_C4[0x1C];
};

typedef char TObjAreaWarpQuest_size[sizeof(TObjAreaWarpQuest) == 0xE0 ? 1 : -1];
#endif
