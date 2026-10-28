#ifndef PSO_MISC_TRADERMAPCORE_H
#define PSO_MISC_TRADERMAPCORE_H

#include "types.h"
#include <stddef.h>
#include "pso/object/TObjMotion.h"

struct RadarViewportParameters
{
    u8 unknown00[0x8];
    f32 center_x;
    f32 center_y;
    u8 unknown10[0x8];
    f32 value18;
    u8 unknown1C[0xC];
    f32 screen_width;
    f32 screen_height;
};

struct TRaderMapCore : public TUnk_804B9870 {
    virtual ~TRaderMapCore();
    void update_follow_projection(s32);
    virtual void run_task();
    s32 m_90;
    u8 player_marker_records[0xA0];
    s32 m_134;
    u8 unknown138[0x8];
    f32 m_140;
    f32 m_144;
    u8 unknown148[0x8];
    f32 m_150;
    u8 unknown154[0xC];
    f32 m_160;
    f32 m_164;
    s32 m_168;
    s32 m_16c;
    f32 m_170;
    s32 m_174;
    void* m_178;
    void* m_17c;
    void* m_180;
    void* m_184;
    f32 m_188;
    f32 m_18c;
    f32 m_190;
    u32 m_194;
    s32 m_198;
    f32 m_19c;
    f32 m_1a0;

    void configure_viewport(const RadarViewportParameters* view);
    void set_map_position(void *arg1);
    s32 is_render_admitted_default();
    static s32 is_active();
    void reset_counter();
    static void hide_radar();
    static void show_radar();
    static s32 set_view_scissor(void *self, int mode, void *arg2);
    static void free_map_data();
    static void free_heap();
    static void set_piece_flags(s32 arg0);
    static void add_zoom_distance(f32 farg0);
    static void open_free_map_view();
    static void pan_vertical(f32 farg0);
    static void pan_horizontal(f32 farg0);
    static s32 block_region_by_id(s16 id);
    static s32 reveal_region_by_id(s16 id);
    void draw_player_markers();
    void copy_transform(void* q);
    void setup_view(s32 arg1);
    void render_region_records(void * _w1);
    virtual void render();
    s32 is_render_admitted(void *arg1);
    void update_pan_zoom_input();
    void update_target();
    static s32 pack_color_bits(s32 arg1, s32 arg2);
    u8 has_flag();
    static void set_mode(int a0);
    void advance_scroll();
    static void create();
    static void unload_floor_map();
    static void load_map_resources();
    static s32 apply_compass_param();
    static void free_statics();
    static void load_frame_texture();
    void reset();
    static void init_map_ptr();
    static s32 is_not_split_screen();
    static void clear();
    static void apply_packed_flags(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void gather_player_markers();
    void draw_enemy_gate_markers();
    s32 get_map_id();
    static void draw_backdrop(TRaderMapCore *self, s32 mode);
};

typedef char RadarViewportSize[(sizeof(RadarViewportParameters) == 0x30) ? 1 : -1];
typedef char RadarViewportCenterX[(offsetof(RadarViewportParameters, center_x) == 0x8) ? 1 : -1];
typedef char RadarViewportCenterY[(offsetof(RadarViewportParameters, center_y) == 0xC) ? 1 : -1];
typedef char RadarViewportValue18[(offsetof(RadarViewportParameters, value18) == 0x18) ? 1 : -1];
typedef char RadarViewportWidth[(offsetof(RadarViewportParameters, screen_width) == 0x28) ? 1 : -1];
typedef char RadarViewportHeight[(offsetof(RadarViewportParameters, screen_height) == 0x2C) ? 1 : -1];
typedef char RaderMapCoreSize[(sizeof(TRaderMapCore) == 0x1A4) ? 1 : -1];
typedef char RaderMapCoreDelay[(offsetof(TRaderMapCore, m_90) == 0x90) ? 1 : -1];
typedef char RaderMapCoreMarkers[(offsetof(TRaderMapCore, player_marker_records) == 0x94) ? 1 : -1];
typedef char RaderMapCoreSelectedPlayer[(offsetof(TRaderMapCore, m_134) == 0x134) ? 1 : -1];
typedef char RaderMapCoreViewportWidth[(offsetof(TRaderMapCore, m_160) == 0x160) ? 1 : -1];
typedef char RaderMapCoreTarget[(offsetof(TRaderMapCore, m_184) == 0x184) ? 1 : -1];
typedef char RaderMapCoreTail[(offsetof(TRaderMapCore, m_1a0) == 0x1A0) ? 1 : -1];

#endif
