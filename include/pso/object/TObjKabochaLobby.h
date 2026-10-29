#ifndef PSO_OBJECT_TOBJKABOCHALOBBY_H
#define PSO_OBJECT_TOBJKABOCHALOBBY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct TObjKabochaLobby : public TObjMapObject {
    TObjKabochaLobby(TObject *parent, void *set_data);
    virtual ~TObjKabochaLobby();
    s32 state;  // 0 hidden, 2 growing, 3 shown, 1 shrinking
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0);
    static void unload_static_data();
    static void load_resources();
    f32 scale;  // the scale it grows and shrinks by
};

typedef char TObjKabochaLobby_size[sizeof(TObjKabochaLobby) == 0xD0 ? 1 : -1];


#endif
