#ifndef PSO_OBJECT_WARP_TOBJAREAWARPQUEST_H
#define PSO_OBJECT_WARP_TOBJAREAWARPQUEST_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjAreaWarpQuest : public TObjAreaWarp {
    TObjAreaWarpQuest(TObject *parent, void *set_data);
    virtual ~TObjAreaWarpQuest();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(void *player);
    void render();
    void run_task();
    s32 get_dest_area();
    s32 player_set_id;  // inferred from "<- PLAYER SET ID : %d"
    u8 unk_C8[0x18];
};

typedef char TObjAreaWarpQuest_size[sizeof(TObjAreaWarpQuest) == 0xE0 ? 1 : -1];
#endif
