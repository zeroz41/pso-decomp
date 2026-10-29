#ifndef PSO_OBJECT_TOBJRAINBOWLOBBY_H
#define PSO_OBJECT_TOBJRAINBOWLOBBY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct BmlResource;

// The lobby rainbow: shown while a lobby event runs, it grows in when the
// lobby connects and shrinks away when a lobby object takes over.
struct TObjRainbowLobby : public TObjMapObject {
    TObjRainbowLobby(TObject *parent, void *set_data);
    virtual ~TObjRainbowLobby();
    s32 state;  // 0 hidden, 2 fading in, 3 shown, 1 fading out
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
    static void free_static_data();
    static void load_shared_resource();
    f32 scale;

    static BmlResource *shared_model_resource;
};

typedef char TObjRainbowLobby_size[sizeof(TObjRainbowLobby) == 0xD0 ? 1 : -1];

#endif
