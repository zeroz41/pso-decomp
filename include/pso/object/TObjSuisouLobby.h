#ifndef PSO_OBJECT_TOBJSUISOULOBBY_H
#define PSO_OBJECT_TOBJSUISOULOBBY_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

class TParticleCtrl;

struct TObjSuisouLobby : public TUnk_804AFBF8 {
    TObjSuisouLobby(TObject *parent, void *set_data);
    virtual ~TObjSuisouLobby();
    virtual void render();
    virtual void run_task();
    s32 fade_state;  // 0 hidden, 2 fading in, 3 shown, 1 fading out
    f32 fade_scale;  // 0..1, the xz scale it fades in and out with
    u8 pad_d0[0x4];
    TParticleCtrl *emitter0;  // the bubbles in front of it
    TParticleCtrl *emitter1;  // the bubbles behind it
    void update_particle();
    void *create();
    static void destroy_instance();
    static void load_resources();
};

typedef char TObjSuisouLobby_size[sizeof(TObjSuisouLobby) == 0xDC ? 1 : -1];

extern "C" {
void TObjSuisouLobby__sub_80369B5C(void);
void TObjSuisouLobby__sub_80369D68(void);
}

#endif
