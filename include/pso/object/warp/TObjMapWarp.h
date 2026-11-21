#ifndef PSO_OBJECT_WARP_TOBJMAPWARP_H
#define PSO_OBJECT_WARP_TOBJMAPWARP_H
#include <stddef.h>
#include "types.h"
#include "pso/object/warp/TObjWarpBase.h"
class TWindowMenu;

struct TObjMapWarp : public TObjWarpBase {
    TObjMapWarp(TObject *parent, void *set_data);
    virtual ~TObjMapWarp();
    virtual void vfunc_14();
    virtual void draw_debug_destinations();
    virtual void closePlayerWindow(u16);
    Vec destinations[4];
    TWindowMenu *playerPopups[4];
    static u8 can_warp(s32 arg0, u16 arg1);
    virtual void open_confirm_window(s32 player);  // the slot TObjWarpBase leaves pure; opens player's warp menu
    void process_player_warps();
};
typedef char TObjMapWarpDestinationsOffset[offsetof(TObjMapWarp, destinations) == 0xBC ? 1 : -1];
typedef char TObjMapWarpPopupsOffset[offsetof(TObjMapWarp, playerPopups) == 0xEC ? 1 : -1];
#endif
