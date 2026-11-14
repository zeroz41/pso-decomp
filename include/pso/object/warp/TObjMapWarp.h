#ifndef PSO_OBJECT_WARP_TOBJMAPWARP_H
#define PSO_OBJECT_WARP_TOBJMAPWARP_H
#include "types.h"
#include "pso/object/warp/TObjWarpBase.h"
struct TObjMapWarp : public TObjWarpBase {
    TObjMapWarp(TObject *parent, void *set_data);
    virtual ~TObjMapWarp();
    virtual void vfunc_14();
    virtual void slot4C();
    virtual void closePlayerWindow(u16);
    f32 destinations[4][3];
    void* playerPopups[4];
    void draw_debug_destinations();
    static u8 can_warp(s32 arg0, u16 arg1);
    virtual void open_confirm_window(s32 player);  // the slot TObjWarpBase leaves pure; opens player's warp menu
    void process_player_warps();
};
#endif
