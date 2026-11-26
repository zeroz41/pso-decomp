#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_H

struct GuildCardRecord;

#include "types.h"
#include <stddef.h>
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/WindowLayoutRecord.h"

struct PageIndicator;
struct NumberedTimesLayout;
struct RankTimeRecordsLayout;
struct RecordSummaryLayout;
struct ResistanceLayout;
struct StatPageLayout;
struct SummaryPageLayout;
class ItemListRow;

struct TWindowSubStatusDisp : public TWindowBase {
    static s32 count_ratio_value;
    static void * window_layout[5];
    static NumberedTimesLayout numbered_times_layout;
    static RankTimeRecordsLayout rank_time_records_layout;
    static RecordSummaryLayout record_summary_layout;
    static ResistanceLayout resistance_layout;
    static StatPageLayout stat_page_layout;
    static SummaryPageLayout summary_page_layout;
    TWindowSubStatusDisp(s32 client);
    virtual ~TWindowSubStatusDisp();
    static const char *class_name;
    virtual void run_task();
    virtual void render();
    s16 page; // index into the dispatch_page_init/update page tables
    s16 requested_page;  // the page the owner wants shown (set_requested_page); run_task switches to it
    NJS_TEXLIST *body_textures; // the shown player's body textures, drawn by the summary page's portrait sprite
    PageIndicator *page_indicator;
    f32 scale_x;
    f32 scale_y;

    void set_requested_page(s16 value);
    void set_scale(f32 x, f32 y);
    void vt0();
    void vt1();
    void vt2();
    void vt3();
    void vt4();
    void vt5();
    void vt7();
    void vt11();
    void vt12();
    void vt13();
    void vt14();
    void vt15();
    void vt16();
    void vt18();

    void dispatch_page_update();
    void dispatch_page_init();
    void set_count_ratio_text(s32 count, s32 total);

    static void *get_message_10(s32 index);
    static void draw_number_digits(void *color, s16 value, u16 digits, f32 x, f32 y, f32 scale);
    static void render_forward();
    static void end_render_forward();
    static void begin_render();
    static saddr get_download_server();
    static u32 calc_text_width(char *s);
    static s32 is_alpha_char(u16 arg0);
    void pack_status_flags(u32 arg1);
    static s32 upload_glyph_if_needed(u16 code, u8 *free_slot, void **arg2);
    static void set_gauge_param(s32 gauge_param);
    static void reset_gauge(void* p);
    static f32 get_card_window_scale(s32 client_id);
    static s32 get_card_window_flags(s32 client_id);
    static void append_play_time(u32 time);
    static void append_comma();
    s8 *copy_message_page_text();
    void fill_card_text_entries(GuildCardRecord *record);
    static void draw_split_screen_dividers();
    static void draw_tiled_background();
    static void draw_bottom_bar();
    static void draw_split_screen_hud();
    void set_entry_display_value(s32 str);
    s32 get_display_mode();
    static s32 build_status_text(s32 client_id);
    void update_entry_visibility();
    static void *find_cached_glyph(u16 code);
    static u8 calc_gauge_scale(u16 glyph, void *arg1, s32 color);
};

LAYOUT_ASSERT(TWindowSubStatusDisp_offset_page, offsetof(TWindowSubStatusDisp, page) == 0x60);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_requested_page, offsetof(TWindowSubStatusDisp, requested_page) == 0x62);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_page_indicator, offsetof(TWindowSubStatusDisp, page_indicator) == 0x68);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_scale_x, offsetof(TWindowSubStatusDisp, scale_x) == 0x6C);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_scale_y, offsetof(TWindowSubStatusDisp, scale_y) == 0x70);

LAYOUT_ASSERT(TWindowSubStatusDisp_size, sizeof(TWindowSubStatusDisp) == 0x74);
s32 measure_string_len(const char *str);

struct SummaryPageLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
    TextLayoutRecord rec_3;
    TextLayoutRecord rec_4;
    DirectSpritePartLayoutRecord rec_5;
    TextLayoutRecord rec_6;
    TextLayoutRecord rec_7;
    ValueLayoutRecord rec_8;
    TextLayoutRecord rec_9;
    TextLayoutRecord rec_10;
    TextLayoutRecord rec_11;
    ValueLayoutRecord rec_12;
    TextLayoutRecord rec_13;
    TextLayoutRecord rec_14;
    TextLayoutRecord rec_15;
    ValueLayoutRecord rec_16;
    TextLayoutRecord rec_17;
};

struct StatPageLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
    TextLayoutRecord rec_3;
    ValueLayoutRecord rec_4;
    TextLayoutRecord rec_5;
    TextLayoutRecord rec_6;
    TextLayoutRecord rec_7;
    ValueLayoutRecord rec_8;
    TextLayoutRecord rec_9;
    ValueLayoutRecord rec_10;
    TextLayoutRecord rec_11;
    TextLayoutRecord rec_12;
    TextLayoutRecord rec_13;
    ValueLayoutRecord rec_14;
    TextLayoutRecord rec_15;
    ValueLayoutRecord rec_16;
    TextLayoutRecord rec_17;
    TextLayoutRecord rec_18;
    TextLayoutRecord rec_19;
    ValueLayoutRecord rec_20;
    TextLayoutRecord rec_21;
    ValueLayoutRecord rec_22;
    TextLayoutRecord rec_23;
    TextLayoutRecord rec_24;
    TextLayoutRecord rec_25;
    ValueLayoutRecord rec_26;
    TextLayoutRecord rec_27;
    ValueLayoutRecord rec_28;
    TextLayoutRecord rec_29;
    TextLayoutRecord rec_30;
    TextLayoutRecord rec_31;
    ValueLayoutRecord rec_32;
    TextLayoutRecord rec_33;
    ValueLayoutRecord rec_34;
    TextLayoutRecord rec_35;
};

struct ResistanceLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
    TextLayoutRecord rec_3;
    ValueLayoutRecord rec_4;
    TextLayoutRecord rec_5;
    TextLayoutRecord rec_6;
    TextLayoutRecord rec_7;
    ValueLayoutRecord rec_8;
    TextLayoutRecord rec_9;
    ValueLayoutRecord rec_10;
    TextLayoutRecord rec_11;
    TextLayoutRecord rec_12;
    TextLayoutRecord rec_13;
    ValueLayoutRecord rec_14;
    TextLayoutRecord rec_15;
    ValueLayoutRecord rec_16;
    TextLayoutRecord rec_17;
    TextLayoutRecord rec_18;
    TextLayoutRecord rec_19;
    ValueLayoutRecord rec_20;
    TextLayoutRecord rec_21;
    ValueLayoutRecord rec_22;
    TextLayoutRecord rec_23;
    TextLayoutRecord rec_24;
    TextLayoutRecord rec_25;
    ValueLayoutRecord rec_26;
    TextLayoutRecord rec_27;
    ValueLayoutRecord rec_28;
    TextLayoutRecord rec_29;
};

struct RecordSummaryLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    TextLayoutRecord rec_2;
    ValueLayoutRecord rec_3;
    TextLayoutRecord rec_4;
    TextLayoutRecord rec_5;
    ValueLayoutRecord rec_6;
    TextLayoutRecord rec_7;
    TextLayoutRecord rec_8;
    ValueLayoutRecord rec_9;
    TextLayoutRecord rec_10;
    TextLayoutRecord rec_11;
    ValueLayoutRecord rec_12;
    TextLayoutRecord rec_13;
    TextLayoutRecord rec_14;
    ValueLayoutRecord rec_15;
};

struct RankTimeRecordsLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    TextLayoutRecord rec_2;
    TextLayoutRecord rec_3;
    TextLayoutRecord rec_4;
    TextLayoutRecord rec_5;
    TextLayoutRecord rec_6;
    TextLayoutRecord rec_7;
    TextLayoutRecord rec_8;
    TextLayoutRecord rec_9;
    TextLayoutRecord rec_10;
    TextLayoutRecord rec_11;
    TextLayoutRecord rec_12;
    TextLayoutRecord rec_13;
    TextLayoutRecord rec_14;
    TextLayoutRecord rec_15;
};

struct NumberedTimesLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    TextLayoutRecord rec_2;
    TextLayoutRecord rec_3;
    TextLayoutRecord rec_4;
    TextLayoutRecord rec_5;
    TextLayoutRecord rec_6;
    TextLayoutRecord rec_7;
    TextLayoutRecord rec_8;
    TextLayoutRecord rec_9;
};


#endif
