#ifndef PSO_OBJECT_TOBJCURTAINLOBBY_H
#define PSO_OBJECT_TOBJCURTAINLOBBY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct BmlResource;

// The lobby red-and-white curtain pillars: grow in while event theme 12 (or
// 13, clamped to 12) runs and shrink away when it ends.
struct TObjCurtainLobby : public TObjMapObject {
    TObjCurtainLobby(TObject *parent, void *set_data);
    virtual ~TObjCurtainLobby();
    s32 state;  // 0 hidden, 2 growing, 3 shown, 1 shrinking
    // The filtered event theme with 13 folded into 12.
    s32 get_lobby_theme_clamped();
    // run_task's demo-mode step, empty in this build.
    void demo_step();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
    static void free_resources();
    static void load_resources();
    f32 scale;  // the scale it grows and shrinks by

    static BmlResource *model_resource;
    static u32 lobby_texlist;  // the lobby's shared texture list
};

typedef char TObjCurtainLobby_size[sizeof(TObjCurtainLobby) == 0xD0 ? 1 : -1];

#endif
