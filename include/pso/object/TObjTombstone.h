#ifndef PSO_OBJECT_TOBJTOMBSTONE_H
#define PSO_OBJECT_TOBJTOMBSTONE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

// The challenge-mode drop chances of a tombstone (inferred: quest opcode
// qst_op_set_cmode_grave_rates passes its registers to TObjTombstone__sub_80074E74,
// which checks and stores them here). count[n]: chance of dropping n + 1 items;
// kind[k]: chance the drops are entry k of the item templates.
struct TObjTombstoneDropRates {
    void copy_matrix(f32 *src);
    f32 count[4];
    f32 kind[6];
};

extern "C" void TObjTombstone__sub_80074E74(f32 *w);

// What TLobby::create_tombstone spawns a tombstone from (inferred layout:
// three bytes copied to the record, then its position).
struct TObjTombstoneSpot {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    Vec position;
};

// What a tombstone is set up from (setup copies it whole; the copy is the
// compiler's assignment operator, 0x80076390).
struct TObjTombstoneRecord {
    u8 unk_0;
    u8 unk_1;
    u8 floor;  // compared with get_current_floor
    u8 unk_3;
    s16 unk_4;
    s16 unk_6;
    u32 date;      // year-2000 << 28 | month << 24 | day << 16 | hour << 8 | minute
    s32 rt_index;  // passed to enemy_name_for_rt_index
    Vec position;
    char unk_1C[0x14];
    char unk_30[0x20];
};

struct TObjTombstone : public TObjCollidable {
    TObjTombstone(TObject *parent, s32 client, TObjTombstoneSpot *spot);
    TObjTombstone(TObject *parent, s32 client, TObjTombstoneRecord *src);
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
    static s32 project_to_screen(void *arg0, f32 *arg1, Vec *arg2);
    void update_fade_by_distance();
    void draw_name_labels();
    void update_render_flags();
    s32 check_all_players_active();
    s32 check_height_ready();
    void init_parts();
    s32 is_player_nearby();
    void update_rise();
    virtual void run_task();
    void setup(s32 client, TObjTombstoneRecord *src);
    static void destroy();
    static void load_resources();
    static void *create(void *arg0, void *arg1, void *arg2);
};

typedef char TObjTombstone_size[sizeof(TObjTombstone) == 0x238 ? 1 : -1];
#endif
