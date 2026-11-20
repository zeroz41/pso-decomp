#ifndef PSO_OBJECT_WARP_TOBJWARPBASE_H
#define PSO_OBJECT_WARP_TOBJWARPBASE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TAdVIConfigGC;
struct TObjPlayer;

struct TObjWarpBase : public TObjCollidable {
    TObjWarpBase(TObject *parent, void *set_data);
    virtual ~TObjWarpBase();
    virtual void vfunc_14();
    virtual void open_confirm_window(s32) = 0;
    virtual u8 is_warp_enabled();
    virtual s32 vfunc_17();
    // Nonzero once the user confirmed (handle_area_selection tests the result per player).
    virtual s32 vfunc_18(s32);
    static void free_globals();
    f32 warp_range;        // how close a player must come (the range find_warp_player_in_range tests)
    u32 menu_window;       // the menu window open for the user; vfunc_14 closes it
    void *field_collider;  // the TUnk_804CC9D4 selectable field the constructor news
    u16 user_client_id;    // client id of the player using the warp, 0xFFFF for none
    u8 pad_ba[2];
};
typedef char TObjWarpBase_size[sizeof(TObjWarpBase) == 0xBC ? 1 : -1];

extern "C" TObjPlayer *find_warp_player_in_range(TObjWarpBase *warp, u16 client_id, f32 range);

#endif
