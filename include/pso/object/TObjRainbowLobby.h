#ifndef PSO_OBJECT_TOBJRAINBOWLOBBY_H
#define PSO_OBJECT_TOBJRAINBOWLOBBY_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TObjRainbowLobby : public TUnk_804AFBF8 {
    TObjRainbowLobby(TObject *parent, void *set_data);
    virtual ~TObjRainbowLobby();
    s32 state;  // 0 hidden, 2 fading in, 3 shown, 1 fading out
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0);
    static void free_static_data();
    static void load_shared_resource();
    f32 scale;
};

typedef char TObjRainbowLobby_size[sizeof(TObjRainbowLobby) == 0xD0 ? 1 : -1];


#endif
