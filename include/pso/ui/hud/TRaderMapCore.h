#ifndef PSO_UI_HUD_TRADERMAPCORE_H
#define PSO_UI_HUD_TRADERMAPCORE_H

#include "types.h"
#include <stddef.h>
#include "pso/object/base/TObjMotion.h"
#include "pso/system/NinjaTypes.h"

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

// One player marker on the radar. draw_player_markers translates it to (x, z), turns it by rot_y,
// scales it by scale and tints it with color; id -1 marks an empty slot.
struct RadarPlayerMarker {
    f32 x;
    f32 y;
    f32 z;
    s32 rot_y;
    f32 scale;
    u8 pad_14[2];
    s16 id;
    NJS_ARGB color;
};

struct TObjPlayer;
struct RadarMapViewState;
struct RadarScissorRect;

struct TRaderMapCore : public TObjBase {
    TRaderMapCore(TObject *parent);
    virtual ~TRaderMapCore();
    void update_follow_projection(s32);
    virtual void run_task();
    s32 m_90;
    RadarPlayerMarker player_marker_records[4];
    s32 m_134;
    u8 unknown138[0x8];
    f32 m_140;
    f32 m_144;
    u8 unknown148[0x8];
    f32 m_150;
    u8 unknown154[0xC];
    f32 viewport_width;
    f32 viewport_height;
    s32 m_168;
    s32 m_16c;
    f32 m_170;
    s32 m_174;
    NJS_OBJECT *m_178;
    NJS_OBJECT *m_17c;
    NJS_OBJECT *m_180;
    TObjPlayer *target_player;
    f32 pan_x_speed;
    f32 pan_z_speed;
    f32 zoom_speed;
    u32 m_194;
    s32 angle;
    f32 m_19c;
    f32 m_1a0;

    void configure_viewport(const RadarViewportParameters* view);
    void set_map_position(void *arg1);
    s32 is_render_admitted_default();
    static s32 is_active();
    void reset_counter();
    static void hide_radar();
    static void show_radar();
    void set_view_scissor(int mode, const RadarScissorRect *rect);
    static s32 save_floor_discovery(int floor, void *map_data);
    static void free_map_data();
    static void free_heap();
    static void set_piece_flags(s32 piece_flags);
    static void add_zoom_distance(f32 farg0);
    static void open_free_map_view();
    static void pan_vertical(f32 farg0);
    static void pan_horizontal(f32 farg0);
    void reset_marker_scale();
    static s32 block_region_by_id(s16 id);
    static s32 reveal_region_by_id(s16 id);
    void set_marker_shown(s32 slot, s32 shown);
    void set_target_flag();
    void draw_player_markers();
    void setup_overhead_projection(RadarMapViewState *view);
    void begin_map_view(int mode);
    void setup_view(s32 mode);
    void render_region_records(s32 mode);
    void set_default_view_size();
    virtual void render();
    s32 is_render_admitted(s32 mode);
    void update_pan_zoom_input();
    void update_target();
    static s32 pack_color_bits(s32 input, s32 mask);
    static void set_mode(int mode);
    void advance_scroll();
    static void create();
    static void unload_floor_map();
    static void load_map_resources();
    static s32 apply_compass_param(const s32 *counter);
    void draw_compass(s32 mode);
    static void free_statics();
    static void load_frame_texture();
    void reset();
    static NJS_OBJECT *init_map_ptr(const s32 *counter, s32 index);
    static s32 is_not_split_screen();
    static void clear();
    static s32 apply_packed_flags(saddr input, s32 buttons, s32 delay, s32 period);
    void gather_player_markers();
    void draw_enemy_gate_markers();
    static void draw_backdrop(TRaderMapCore *self, s32 mode);
    static void pick_target_position(void *, void *);
    static s32 should_show_map();
};

// A TObject subclass of this unit: its destructor (0x801FB9C8) is the unit's last function and its
// vtable (0x804C88A8) follows TRaderMapCore's. Nothing in the DOL constructs it.
class TUnk_804C88A8 : public TObject {
public:
    virtual ~TUnk_804C88A8();
};

LAYOUT_ASSERT(RadarPlayerMarkerSize, sizeof(RadarPlayerMarker) == 0x28);
LAYOUT_ASSERT(RadarViewportSize, sizeof(RadarViewportParameters) == 0x30);
LAYOUT_ASSERT(RadarViewportCenterX, offsetof(RadarViewportParameters, center_x) == 0x8);
LAYOUT_ASSERT(RadarViewportCenterY, offsetof(RadarViewportParameters, center_y) == 0xC);
LAYOUT_ASSERT(RadarViewportValue18, offsetof(RadarViewportParameters, value18) == 0x18);
LAYOUT_ASSERT(RadarViewportWidth, offsetof(RadarViewportParameters, screen_width) == 0x28);
LAYOUT_ASSERT(RadarViewportHeight, offsetof(RadarViewportParameters, screen_height) == 0x2C);
LAYOUT_ASSERT(RaderMapCoreSize, sizeof(TRaderMapCore) == 0x1A4);
LAYOUT_ASSERT(RaderMapCoreDelay, offsetof(TRaderMapCore, m_90) == 0x90);
LAYOUT_ASSERT(RaderMapCoreMarkers, offsetof(TRaderMapCore, player_marker_records) == 0x94);
LAYOUT_ASSERT(RaderMapCoreSelectedPlayer, offsetof(TRaderMapCore, m_134) == 0x134);
LAYOUT_ASSERT(RaderMapCoreViewportWidth, offsetof(TRaderMapCore, viewport_width) == 0x160);
LAYOUT_ASSERT(RaderMapCoreTarget, offsetof(TRaderMapCore, target_player) == 0x184);
LAYOUT_ASSERT(RaderMapCoreTail, offsetof(TRaderMapCore, m_1a0) == 0x1A0);

// Draws a door or gate marker on the radar: green when it is open to the
// player, red when it is locked.
extern "C" s32 minimap_render_gate(Vec *pos, u32 color, u16 rot, s16 kind, s32 flags);
extern "C" s32 add_radar_scaled_gate(Vec *pos, u32 color, u16 rot, s16 kind, s32 flags, f32 scale);

// Queues a radar dot of the given colour and kind at pos, drawn at scale. Unless bit 0 of flags is
// set, a dot more than 300 units from the radar's view centre is dropped. Returns 0 when dropped or
// when all 128 marker slots are taken.
extern "C" s32 minimap_render_dot(Vec *pos, s32 color, s16 kind, s32 flags);
extern "C" s32 add_radar_scaled_marker(Vec *pos, s32 color, s16 kind, s32 flags, f32 scale);

extern "C" void TRaderMapCore__sub_801F95CC(void);

#endif
