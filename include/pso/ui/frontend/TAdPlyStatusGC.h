#ifndef PSO_UI_FRONTEND_TADPLYSTATUSGC_H
#define PSO_UI_FRONTEND_TADPLYSTATUSGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdGuideButtonGC.h"

class TWindowBase;
class CharacterPreview;
struct NJS_POINT2;

// The eight floats draw_textured_quad_at_depth reads: x0, y0, x1, y1, then the uvs u0, v0, u1, v1.
struct StatusPortraitQuad {
    f32 values[8];
};

struct TAdPlyStatusGC : public TObject {
    static const char *class_name;
    static s32 is_shown;
    static s32 window_offset_index;
    TAdPlyStatusGC(TObject *parent, s32 offset_index);
    virtual ~TAdPlyStatusGC();
    virtual void render();
    virtual void run_task();
    s32 state; // indexes run_task's close/shown/hidden handler table
    s32 prev_state;
    GuideButtonSpec buttons[2];
    TWindowBase *window;
    // Shows preview's character in the status window once it has loaded.
    void set_status_param(CharacterPreview *preview);
    static TAdPlyStatusGC *get_index();
    static void set_status_index(int a0, int a1);
    void close_window(s32 index);
    void close_window();
    void update_shown();
    void update_hidden();
    static TAdPlyStatusGC *get_instance(TObject *parent, s32 window_offset_index);
    static TAdGuideButtonGC *get_player_index(); // the guide button, or NULL
    // Fills text with the class, section id and play time lines of the shown character.
    static void format_status_strings(char (*text)[16]);
    // The status window's draw callback: portrait, labels and format_status_strings' values.
    static void draw_status_window(void *window, void *context);
    TWindowBase *create_status_window(const NJS_POINT2 *position);
    void set_load_state(s32 load_result);
};

LAYOUT_ASSERT(TAdPlyStatusGC_size, sizeof(TAdPlyStatusGC) == 0x70);

extern "C" TAdPlyStatusGC *ply_status_gc_instance;
// The character the status window shows (set_status_param).
extern "C" CharacterPreview *ply_status_preview;
extern "C" u32 ply_status_index;
#endif
