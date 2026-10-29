#ifndef PSO_OBJECT_TOBJPARTICLELOBBY_H
#define PSO_OBJECT_TOBJPARTICLELOBBY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

class TParticleCtrl;

// A lobby set object that runs one particle effect while the lobby's event
// theme is the one its set data names, fading the effect in and out.
struct TObjParticleLobby : public TObjMapObject {
    TObjParticleLobby(TObject *parent, void *set_data);
    virtual ~TObjParticleLobby();
    virtual void render();
    virtual void run_task();
    s32 fade_state;    // 0 hidden, 2 fading in, 3 shown, 1 fading out
    f32 fade_scale;    // 0..1, the emitter scale it fades in and out with
    s32 event_theme;   // the event theme it shows for
    TParticleCtrl *emitter;
    s32 get_event_theme_index();
    void demo_step();
    void setup_emitter();
    static void *create(void *set_data);
    static void free_resources();
    static void load_resources();
};

typedef char TObjParticleLobby_size[sizeof(TObjParticleLobby) == 0xD8 ? 1 : -1];

#endif
