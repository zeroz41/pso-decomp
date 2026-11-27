#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_H

struct GuildCardRecord;

#include "types.h"
#include <stddef.h>
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/WindowLayoutRecord.h"

struct PageIndicator;
struct MenuGlyphEntry;
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

    static const char *get_message_10(s32 index);
    static void render_forward();
    static void end_render_forward();
    static void begin_render();
    static const char *get_meseta_unit();
    static u32 calc_text_width(const char *s);
    static s32 is_alpha_char(u16 code);
    static s32 upload_glyph_if_needed(u16 code, MenuGlyphEntry *free_slot, MenuGlyphEntry **pending_slot);
    static void set_gauge_param(s32 gauge_param);
    static void reset_gauge(void* p);
    static f32 get_card_window_scale(s32 client_id);
    static s32 get_card_window_flags(s32 client_id);
    static void append_play_time(u32 time);
    void fill_card_text_entries(GuildCardRecord *record);
    void set_entry_display_value(const char *str);
    s32 get_display_mode();
    void update_entry_visibility();
    static MenuGlyphEntry *find_cached_glyph(u16 code);
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

void release_bg_multi_textures();

void load_bg_multi_textures();

void draw_split_screen_hud();

void draw_split_screen_dividers();

void draw_tiled_background();

void draw_scanline_sweep();

void draw_bottom_bar();

class WindowTextEntry;
struct TextLayoutRecord;

void set_text_entry_string(WindowTextEntry *entry, const char *str, s32 flags);
extern "C" void measure_message_text_width(WindowTextEntry *entry, f32 max_width);

#endif
