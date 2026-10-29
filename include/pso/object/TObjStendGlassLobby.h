#ifndef PSO_OBJECT_TOBJSTENDGLASSLOBBY_H
#define PSO_OBJECT_TOBJSTENDGLASSLOBBY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct TObjStendGlassLobby : public TObjMapObject {
    TObjStendGlassLobby(TObject *parent, void *set_data);
    virtual ~TObjStendGlassLobby();
    s32 fade_state;  // 0 hidden, 2 fading in, 3 shown, 1 fading out
    f32 fade_scale;  // 0..1, the xz scale it fades in and out with
    s32 event_theme;  // the event theme it shows for
    virtual void render();
    virtual void run_task();
    void update_state();
    static void *create(void *arg0);
    static void free_static_model();
    static void load_resources();
};

typedef char TObjStendGlassLobby_size[sizeof(TObjStendGlassLobby) == 0xD4 ? 1 : -1];

extern "C" {
void TObjStendGlassLobby__sub_803596C0(void);
}

#endif
