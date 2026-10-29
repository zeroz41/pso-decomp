#ifndef PSO_OBJECT_TOBJSTENDGLASSLOBBY_H
#define PSO_OBJECT_TOBJSTENDGLASSLOBBY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct BmlResource;

// A lobby stained-glass window frame: shown while the event theme its set
// data picks (0 or 1) runs, fading in and out on the xz axes.
struct TObjStendGlassLobby : public TObjMapObject {
    TObjStendGlassLobby(TObject *parent, void *set_data);
    virtual ~TObjStendGlassLobby();
    s32 fade_state;  // 0 hidden, 2 fading in, 3 shown, 1 fading out
    f32 fade_scale;  // 0..1, the xz scale it fades in and out with
    s32 event_theme;  // the event theme it shows for
    // run_task's demo-mode step, empty in this build.
    void demo_step();
    virtual void render();
    virtual void run_task();
    void update_state();
    static void *create(void *set_data);
    static void free_static_model();
    static void load_resources();

    static BmlResource *static_model_resource;
    static u32 lobby_texlist;  // the lobby's shared texture list
};

typedef char TObjStendGlassLobby_size[sizeof(TObjStendGlassLobby) == 0xD4 ? 1 : -1];

#endif
