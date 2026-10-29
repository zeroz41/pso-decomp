#ifndef PSO_OBJECT_TOBJCURTAINLOBBY_H
#define PSO_OBJECT_TOBJCURTAINLOBBY_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TObjCurtainLobby : public TUnk_804AFBF8 {
    TObjCurtainLobby(TObject *parent, void *set_data);
    virtual ~TObjCurtainLobby();
    s32 state;  // 0 hidden, 2 growing, 3 shown, 1 shrinking
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0);
    static void close_dialog_window();
    static void load_resources();
    f32 scale;  // the scale it grows and shrinks by
};

typedef char TObjCurtainLobby_size[sizeof(TObjCurtainLobby) == 0xD0 ? 1 : -1];
#endif
