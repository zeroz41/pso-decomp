#ifndef PSO_OBJECT_TOBJTOMBSTONE_H
#define PSO_OBJECT_TOBJTOMBSTONE_H

#include "types.h"
#include <stddef.h>
#include "pso/object/base/TObjMotion.h"
#include "pso/object/TObjTombstoneRecord.h"

// The challenge-mode drop chances of a tombstone (inferred: quest opcode
// qst_op_set_cmode_grave_rates passes its registers to set_tombstone_drop_rates,
// which checks and stores them here). count[n]: chance of dropping n + 1 items;
// kind[k]: chance the drops are entry k of the item templates.
struct TObjTombstoneDropRates {
    void copy_matrix(const TObjTombstoneDropRates *src);
    f32 count[4];
    f32 kind[6];
};

extern "C" void set_tombstone_drop_rates(TObjTombstoneDropRates *rates);


void copy_tombstone_spot(TObjTombstoneSpot *destination, const TObjTombstoneSpot *source);

struct TObjTombstone : public TObjCollidable {
    TObjTombstone(TObject *parent, s32 client, const TObjTombstoneSpot *spot);
    TObjTombstone(TObject *parent, s32 client, const TObjTombstoneRecord *src);
    virtual ~TObjTombstone();
    s32 client_id;  // the player it stands for (get_player_by_client_id)
    f32 local_distance;  // xz distance to the local player
    f32 label_fade;      // 0-1: how much of the name label shows (near the camera player)
    f32 outline_fade;    // the label outline's own fade (off-screen it fades fast)
    f32 text_fade;       // the label text's own fade (off-screen it fades slowly)
    TObjTombstoneRecord record;
    char labels[6][0x30];  // the lines draw_name_labels draws
    u32 age;             // frames since it was made
    s32 items_dropped;   // 1 once its recovery items are dropped or the drop is another client's
    virtual void render();
    f32 get_distance_to_local_player_xz();
    void format_date_text();
    void format_quoted_name();
    void format_enemy_text();
    void build_name_text();
    void format_label();
    void format_player_name();
    void reset_entries_and_format_name();
    void copy_matrix(void* q);
    static void reset_matrix();
    s32 check_owner();
    s32 is_other_tombstone_closer();
    static s32 project_to_screen(const TObjTombstone *tombstone, NJS_POINT2 *screen, const Vec *point);
    void update_fade_by_distance();
    void drop_recovery_items();  // once: a chance-rolled set of Monomate/Monofluid family items
    void draw_name_labels();
    void update_render_flags();
    s32 check_all_players_active();
    s32 check_height_ready();
    void init_parts();
    s32 is_player_nearby();
    void update_rise();
    virtual void run_task();
    void setup(s32 client, const TObjTombstoneRecord *src);
    static void destroy();
    static void load_resources();
    static TObjTombstone *create(TObject *parent, s32 client, const TObjTombstoneRecord *record);
    static TObjTombstone *create_tombstone(TObject *parent, s32 client, const TObjTombstoneSpot *spot);
};

LAYOUT_ASSERT(TObjTombstone_size, sizeof(TObjTombstone) == 0x238);

void handle_6x96(void);

void reset_tombstone_values();

#endif
