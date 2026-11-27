#ifndef PSO_UI_HUD_TMAINCURSOR_H
#define PSO_UI_HUD_TMAINCURSOR_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/window/ActionPaletteTag.h"
#include "pso/ui/hud/MarkerColor.h"

struct NJS_OBJECT;
class LockOnActionSlot;
class TObjCollidable;
struct TObjPlayer;
class TPlyDispConfigSmth;
class LockOnNearestTarget;
class LockOnPaletteOverride;

// TMainCursor +0x24: the client id of the player whose lock-on cursor made the cursor.
class CursorOwner {
public:
    u16 client_id;

    CursorOwner();
    ~CursorOwner();
    void set_client_id(u16 id);
    u16 get_client_id();
    TObjPlayer *get_player();
};

// TMainCursor +0x60; LockOnSelection holds two.
class CursorTarget {
public:
    ActionPaletteTag palette_tag;
    u16 entity_id;  // 0xFFFF when there is no target
    s16 target_id;

    CursorTarget();
    ~CursorTarget();
    void reset_target();
    CursorTarget *copy_from(CursorTarget *src);
    void set_target_id(s16 id);
    s16 get_target_id();
    void set_entity_id(u16 id);
    u16 get_entity_id();
    int matches_id(u16 id);
    int is_same_target(CursorTarget *other);
};

class LockOnActionSlot;

struct TMainCursor : public TObject {
    TMainCursor(TObject *parent, u16 entity_id, s32 target_id, s32 action_palette, s32 active, u16 client_id, f32 size);
    virtual ~TMainCursor();
    void set_size(f32);
    // 0 = ring shrinking onto the target, 1 = steady, 2 = fading out.
    u32 phase;
    FlagWord state_flags;
    CursorOwner owner;
    u8 pad_26[0x2];
    // Resting height of the ring above the target, the minimum it shrinks to, and the height it starts from.
    f32 rest_height;
    f32 size;
    f32 height;
    f32 min_height;
    f32 start_height;
    f32 m_3c;
    Vec position;
    MarkerColor marker;
    CursorTarget target;
    void update_position();
    void update_photon_chair();
    virtual void render();
    virtual void run_task();
    static s32 check_visible(TPlyDispConfigSmth *palette, TObjPlayer *player, s16 type, s32 enabled);
    static NJS_OBJECT *get_cursor_model();
    TObjPlayer *get_owner_player();
    void update_target_sub();
    u16 get_client_id();
    int is_hidden();
    void hide();
    int init_render_flags();
    int update();
    int check_flag_1();
    u8 is_position_moved();
    void check_flag_4();
    u8 get_palette_slot();
    u8 get_palette_mode();
    void set_client_id(u16 id);
    void set_palette_slot(u8 slot);
    void refresh_target_marker();
    void update_chair();
    void validate_target();
    void set_target_id(u8 target_id);
    void set_entity_id(u16 id);
    s32 check_can_pickup();
    static s32 try_add_target_candidate(LockOnActionSlot *entry, TObjCollidable *candidate, TObjPlayer *owner, LockOnNearestTarget *best);
};

LAYOUT_ASSERT(TMainCursor_size, sizeof(TMainCursor) == 0x68);

s32 target_in_vertical_cone(Vec *p, Vec *q, s32 yaw, f32 range, f32 dist);
s32 target_in_xz_cone(Vec *p, Vec *q, Vec *r, s32 yaw, f32 range, f32 dist);

void set_cursor_action_palette_mode(TMainCursor *cursor, u8 mode);
void set_cursor_palette_slot(ActionPaletteTag *tag, u8 slot);
void set_cursor_palette_mode(ActionPaletteTag *tag, u8 mode);
u8 get_cursor_palette_mode(LockOnActionSlot *slot);
void set_target_part(class LockOnTargetPart *target, u16 part, s32 index, s32 flag);
void set_cursor_slot(LockOnActionSlot *slot, u8 v);
void set_cursor_mode(LockOnActionSlot *slot, u8 v);
void load_target_cursor_models(void);
void render_marker(TMainCursor *main_cursor);
struct CsnHit *is_target_obstructed(class LockOnActionSlot *unused, const Vec *to, const Vec *from);
s32 is_active_channel_matching(LockOnActionSlot *slot, u8 type, u8 enabled);
s32 is_channel_active(const gc_tag *tag);
s32 canSetMenuCursorAction(LockOnPaletteOverride *cursor, TObjPlayer *player, u8 kind, u8 parameter);
void set_action_channel_inactive(gc_tag *tag);
void set_action_channel_active(gc_tag *tag);
NJS_OBJECT *get_lock_on_cursor_model(void);
u8 get_target_palette_slot(ActionPaletteTag *p);
u8 get_target_palette_mode(ActionPaletteTag *p);
void deactivate_action_channel(LockOnActionSlot *slot);
void activate_action_channel(LockOnActionSlot *slot);
void clear_marker_color(MarkerColor *marker);
int get_empty_action_entry(void);
NJS_OBJECT *get_target_cursor_model(void);

struct TechniqueCursorParams { u8 pad0[8]; f32 reach; f32 apex_offset; u8 pad10[0x18 - 0x10]; s32 horizontal_angle; s32 vertical_angle; u8 pad20[2]; s8 cursor_type; };

#endif
