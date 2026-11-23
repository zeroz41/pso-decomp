#ifndef PSO_OBJECT_WARP_TOBJMAPWARP_H
#define PSO_OBJECT_WARP_TOBJMAPWARP_H
#include <stddef.h>
#include "types.h"
#include "pso/object/warp/TObjWarpBase.h"
class TWindowMenu;

struct TObjMapWarp : public TObjWarpBase {
    static const char *class_name;
    TObjMapWarp(TObject *parent, void *set_data);
    virtual ~TObjMapWarp();
    virtual void close_menu();
    virtual void draw_debug_destinations();
    virtual void closePlayerWindow(u16);
    Vec destinations[4];
    TWindowMenu *playerPopups[4];
    s32 can_warp(u16 client_id);
    virtual void open_confirm_window(s32 player);  // the slot TObjWarpBase leaves pure; opens player's warp menu
    void process_player_warps();
};
LAYOUT_ASSERT(TObjMapWarpDestinationsOffset, offsetof(TObjMapWarp, destinations) == 0xBC);
LAYOUT_ASSERT(TObjMapWarpPopupsOffset, offsetof(TObjMapWarp, playerPopups) == 0xEC);
#endif
