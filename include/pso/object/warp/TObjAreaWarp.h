#ifndef PSO_OBJECT_WARP_TOBJAREAWARP_H
#define PSO_OBJECT_WARP_TOBJAREAWARP_H

#include "types.h"
#include "pso/object/warp/TObjWarpBase.h"

struct TObjAreaWarp : public TObjWarpBase {
    static const char *class_name;
    TObjAreaWarp(TObject *parent, void *set_data);
    virtual ~TObjAreaWarp();
    void handle_area_selection();
    virtual void confirm_area_transfer(TObjPlayer *player);  // player: who confirmed (find_warp_player_in_range)
    virtual void debug_print_area_num();
    virtual void open_confirm_window(s32 client_id);
    s32 find_active_player();
    virtual s32 is_warp_enabled();
    s32 dest_floor;            // set data value, or the current floor + 1 while lobby_quest_progress_flag is set
    TAdVIConfigGC *vi_config;  // created by derived constructors, destroyed by ~TObjAreaWarp
};
LAYOUT_ASSERT(TObjAreaWarp_size, sizeof(TObjAreaWarp) == 0xC4);

extern "C" TObjPlayer *find_local_city_warp_player(TObjAreaWarp *warp, f32 range);

#endif
