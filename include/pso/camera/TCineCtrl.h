#ifndef PSO_CAMERA_TCINECTRL_H
#define PSO_CAMERA_TCINECTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

// Cinema letterbox: two bars over the top and bottom of the screen that grow
// in and fade up, or shrink and fade out, for quest cutscenes.
class TCineCtrl : public TObject {
public:
    // Called once a show or hide has finished.
    typedef void (*Callback)(TCineCtrl *cine);

    enum State {
        STATE_IDLE,
        STATE_SHOW,
        STATE_HIDE,
    };

    TCineCtrl(TObject *parent);
    virtual ~TCineCtrl();
    void update_letterbox_show();
    void render();
    static void begin_letterbox_hide(Callback on_done);
    static void begin_letterbox_show(Callback on_done);
    void run_task();
    void update_letterbox_hide();

    f32 alpha;       // 0 .. 255
    f32 bar_height;  // 0 .. 70 lines
    // Bar colour; one word per vertex of draw_polygon_2d.
    union {
        u32 color;
        struct {
            u8 r, g, b, a;
        } rgba;
    };
    s32 state;  // State
    Callback on_done;

    static TCineCtrl *instance;
    static const char *class_name;
};

LAYOUT_ASSERT(TCineCtrl_size, sizeof(TCineCtrl) == 0x30);

#endif
