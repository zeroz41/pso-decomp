#ifndef PSO_UI_HUD_TMAINCURSOR_H
#define PSO_UI_HUD_TMAINCURSOR_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/window/ActionPaletteTag.h"
#include "pso/ui/hud/MarkerColor.h"

struct NJS_OBJECT;
class LockOnActionSlot;
struct TObjPlayer;
class TPlyDispConfigSmth;
class LockOnNearestTarget;

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
    void set_entity_id(u16 id);
    u16 get_entity_id();
    int matches_id(u16 id);
    int is_same_target(CursorTarget *other);
};

struct TMainCursor : public TObject {
    TMainCursor(TObject *parent, u16 entity_id, s32 target_id, s32 action_palette, s32 active, u16 client_id, f32 size);
    virtual ~TMainCursor();
    void bind_action_channels();
    void sub_8013E724(f32);
    u32 m_1c;
    FlagWord unk_20;
    CursorOwner owner;
    u8 pad_26[0x2];
    u8 unk_28[0x4];
    f32 m_2c;
    u8 unk_30[0x4];
    s32 m_34;
    u8 unk_38[0x4];
    f32 m_3c;
    void* m_40;
    u8 _pad44[0x8];
    MarkerColor marker;
    CursorTarget target;
    void update_position();
    s32 sort_actions_by_priority();
    void update_photon_chair();
    virtual void render();
    virtual void run_task();
    void reset_slots();
    void init_slots();
    void set_cursor_pos(u16 arg1, s32 arg2);
    static s32 get_action_cursor_priority(void *arg0, saddr player, s32 index);
    static void set_cursor_color(s32 arg0, saddr player, saddr main_cursor);
    static void set_display_flags(s32 arg0, saddr player, saddr main_cursor);
    static void setup_flags(s32 arg0, s32 player, saddr main_cursor);
    s32 is_channel_active();
    static s32 check_visible(TPlyDispConfigSmth *palette, TObjPlayer *player, s16 type, s32 enabled);
    saddr get_index();
    void set_type(s32 v);
    static NJS_OBJECT *get_cursor_model();
    TObjPlayer *get_owner_player();
    void update_target_sub();
    u16 get_client_id();
    int test_flag_2_at_20();
    int init_render_flags();
    int update();
    int check_flag_1();
    u8 is_position_moved();
    void check_flag_4();
    u8 forward_13E338_at_60();
    u8 update_sub_60();
    void set_client_id(u16 id);
    void init_field_60(u8 v);
    int get_selected_entry();
    u8 get_active();
    int is_cursor_clear();
    void set_color_mode(s32 v);
    void set_color(s32 v);
    void set_field_0c(s32 v);
    void set_flags(s32 v);
    void refresh_target_marker();
    void update_chair();
    void validate_target();
    void set_target_id_at_60(u8 target_id);
    void set_entity_id(u16 id);
    void init_slot(s32 i);
    s32 test_button(s32 arg1, u16 arg2);
    void set_flag_bit(s32 arg1, u16 arg2);
    s32 check_can_pickup();
    void setup_action_channel(u8 *player, s32 slot, s32 kind, s32 id);
    static s32 try_add_target_candidate(LockOnActionSlot *entry, void *candidate, TObjPlayer *owner, LockOnNearestTarget *best);
};

LAYOUT_ASSERT(TMainCursor_size, sizeof(TMainCursor) == 0x68);

s32 target_in_vertical_cone(Vec *p, Vec *q, s32 yaw, f32 range, f32 dist);
s32 target_in_xz_cone(Vec *p, Vec *q, Vec *r, s32 yaw, f32 range, f32 dist);

void set_cursor_action_palette_mode(TMainCursor *cursor, u8 mode);
void set_cursor_palette_slot(ActionPaletteTag *tag, u8 slot);
void set_cursor_palette_mode(ActionPaletteTag *tag, u8 mode);
u8 get_cursor_palette_mode(void *p);
s16 get_action_entry_index(void *p);
void set_action_entry_index(void *p, s16 v);
void set_action_entry_priority(void *p, s16 v);
void set_target_part(u8 *arg0, u16 arg1, s32 arg2, s32 arg3);
void set_cursor_slot(void *p, u8 v);
void set_cursor_mode(void *p, u8 v);
void load_target_cursor_models(void);
extern "C" {
void render__11TMainCursorFPv(TMainCursor *main_cursor);
void init_target_vector__11TMainCursorFiii(s32 arg0, saddr to, saddr from);
s32 try_move__11TMainCursorFiii(saddr cursor, u8 type, u8 enabled);
void TObjPlayer__sub_8013DEF8(u8 *arg0);
void TMainCursor__sub_8013DFC4(u8 *arg0);
s16 TMainCursor__sub_8013E298(void *p);
s32 TMainCursor__sub_8013E2A0(void *p);
int TMainCursor__get_lock_on_cursor_model(void);
void TMainCursor__sub_8013E310(void *p);
u8 TMainCursor__sub_8013E338(void *p);
u8 TMainCursor__sub_8013E358(void *p);
s16 TMainCursor__sub_8013E570(void *p);
void TMainCursor__sub_8013E8A0(void *p);
void TMainCursor__sub_8013E9A0(void *p);
void TMainCursor__sub_8013F104(void *p, s32 v);
void TMainCursor__sub_8013F10C(void *p, s32 v);
void TMainCursor__sub_8013F22C(void *a0);
int TMainCursor__sub_8013F244(void);
int TLockOnCursor__sub_8013EB34(void);
void TLockOnCursor__sub_8013EB80(void *p);
void TLockOnCursor__sub_8013EB8C(void *p);
}
#endif
