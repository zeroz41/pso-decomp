#ifndef PSO_OBJECT_TOBJSUISOULOBBY_H
#define PSO_OBJECT_TOBJSUISOULOBBY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

class TParticleCtrl;

struct BmlResource;

// The lobby fish tank: shown while a lobby event runs, it fades in when the
// lobby connects and out when a lobby object takes over, with bubbles rising
// in front of and behind it while it is not fully shown.
struct TObjSuisouLobby : public TObjMapObject {
    TObjSuisouLobby(TObject *parent, void *set_data);
    virtual ~TObjSuisouLobby();
    virtual void render();
    virtual void run_task();
    s32 fade_state;  // 0 hidden, 2 fading in, 3 shown, 1 fading out
    f32 fade_scale;  // 0..1, the xz scale it fades in and out with
    u8 pad_d0[0x4];
    TParticleCtrl *emitter0;  // the bubbles in front of it
    TParticleCtrl *emitter1;  // the bubbles behind it
    void demo_step();
    void update_particle();
    void sub_80369D68();
    static void *create(void *set_data);
    static void free_resources();
    static void load_resources();

    static BmlResource *model_resource;
    static u32 lobby_texlist;  // the lobby's shared texture list
};

typedef char TObjSuisouLobby_size[sizeof(TObjSuisouLobby) == 0xDC ? 1 : -1];

#endif
