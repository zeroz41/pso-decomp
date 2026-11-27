#ifndef PSO_UI_FRONTEND_TADVICONFIGGC_H
#define PSO_UI_FRONTEND_TADVICONFIGGC_H

#include "types.h"

struct NJS_POINT2;
class TWindowCheckBox;
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"

struct TAdVIConfigGC : public TAdYesNoBaseGC {
    static const char *class_name;
    TAdVIConfigGC(TObject *parent);
    virtual ~TAdVIConfigGC();
    u32 answered;
    u8 *init(const Vec *position, f32 radius);
    virtual void render();
    void mark_answered();
    s32 is_answered();
    void enable_progressive_mode();
    static void disable_progressive_mode();
    virtual void run_task();
    void set_default_choice(s32 v);
    void open_player_names_window();
    s32 get_field_14();
    void update_visibility();
    virtual void on_accept();
    virtual void on_cancel();
    virtual const char *get_message_text();
    static void *destroy(void *, s16);
};

// The block init() fills: who of the party stands within radius of a spot (warps).
struct WarpPartyCheck {
    f32 radius_sq;
    s32 member_count;      // count_members() when the window was last built
    Vec center;
    s32 all_in_range;
    s32 any_in_range;
    s32 confirmed_mask;    // in_range_mask of the last pass that left someone out
    s32 in_range_mask;     // bit per client
    TWindowCheckBox *win;  // the player-name check boxes
    char names[4][0x18];
};

LAYOUT_ASSERT(TAdVIConfigGC_size, sizeof(TAdVIConfigGC) == 0x4C);

extern s32 logo_clear_flag;

#endif
