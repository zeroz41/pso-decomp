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
    f32 m_b0;
    f32 m_b4;
    f32 m_b8;
    f32 m_bc;
    TObjTombstoneRecord record;
    char labels[6][0x30];  // the lines draw_name_labels draws
    u32 m_230;
    s32 m_234;
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
};

LAYOUT_ASSERT(TObjTombstone_size, sizeof(TObjTombstone) == 0x238);

void handle_6x96(void);

#endif
