#ifndef PSO_OBJECT_TOBJTOMBSTONE_H
#define PSO_OBJECT_TOBJTOMBSTONE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjTombstone : public TObjCollidable {
    virtual ~TObjTombstone();
    u8 unk_AC[0x4];
    f32 m_b0;
    u8 unk_B4[0x4];
    f32 m_b8;
    u8 unk_BC[0x6];
    u8 m_c2;
    u8 unk_C3[0x1];
    s16 m_c4;
    u8 unk_C6[0x16A];
    u32 m_230;
    u32 m_234;
    virtual void render();
    f32 get_distance_to_local_player_xz(void * _w1);
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
    static s32 project_to_screen(void *arg0, f32 *arg1, void *arg2);
    void update_fade_by_distance();
    static s32 draw_name_labels(void *arg0_);
    void update_render_flags();
    static s32 check_all_players_active();
    s32 check_height_ready();
    void init_parts();
    s32 is_player_nearby();
    void update_rise();
    virtual void run_task();
    void setup(s32 arg1, s32 arg2);
    static s32 copy_record(void *arg0, s32 arg1);
    void *init(s32 arg1, s32 arg2, s32 arg3);
    static void destroy();
    static void load_resources();
    static void *create(void *arg0, void *arg1, void *arg2);
};

typedef char TObjTombstone_size[sizeof(TObjTombstone) == 0x238 ? 1 : -1];
#endif
