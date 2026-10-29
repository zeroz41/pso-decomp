#ifndef PSO_OBJECT_TOBJKABOCHALOBBY_H
#define PSO_OBJECT_TOBJKABOCHALOBBY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct BmlResource;

// The lobby pumpkin: grows in while the Halloween lobby theme (5) runs and
// shrinks away when it ends.
struct TObjKabochaLobby : public TObjMapObject {
    TObjKabochaLobby(TObject *parent, void *set_data);
    virtual ~TObjKabochaLobby();
    s32 state;  // 0 hidden, 2 growing, 3 shown, 1 shrinking
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
    static void unload_static_data();
    static void load_resources();
    f32 scale;  // the scale it grows and shrinks by

    static BmlResource *model_resource;
    static u32 lobby_texlist;  // the lobby's shared texture list
};

typedef char TObjKabochaLobby_size[sizeof(TObjKabochaLobby) == 0xD0 ? 1 : -1];

#endif
