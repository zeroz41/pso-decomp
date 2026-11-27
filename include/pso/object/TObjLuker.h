#ifndef PSO_OBJECT_TOBJLUKER_H
#define PSO_OBJECT_TOBJLUKER_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjLuker : public TObjBase {
    TObjLuker(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjLuker();
    TObject *windows[4];  // one per player, indexed by entity id
    s32 current_floor;     // the floor named in the destination windows
    TObject *effect;       // the telepipe effect, made when the warp is active
    u16 owner_id;          // client id of the player who opened it
    u16 partner_id;        // client id of the player who confirmed (split screen)
    s16 hold_frames;       // frames spent in state 1
    u16 warp_active;       // 1 while the owner's telepipe is open
    s16 state;             // 0 waiting for confirmation, 1 confirmed, 2 warping
    u8 _padB2[0x2];
    s32 effect_pending;    // 1 when the effect is to be made again
    s32 slots_locked;      // 1 while TWindowCtrl's slots are locked for the confirmation
    void show_part(u16 part_index);
    void hide_part(u16 part_index);
    void update_floor_name_windows();
    void open_destination_windows();
    void transfer_to_town();
    void close_windows();
    s32 is_player_in_range(f32 range);
    virtual void render();
    virtual void run_task();
    static const char *get_stat_table_entry(int a0);
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjLuker_size, sizeof(TObjLuker) == 0xBC);
s32 are_players_gathered_near(const Vec *center, s32 *confirming_view, f32 range);

#endif
