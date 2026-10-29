#ifndef PSO_OBJECT_TOBJWEDDINGLOBBY_H
#define PSO_OBJECT_TOBJWEDDINGLOBBY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct BmlResource;

// The lobby wedding bell: shown while the wedding lobby theme (10) runs,
// its roof drawn still and the bell swinging on a looped motion.
struct TObjWeddingLobby : public TObjMapObject {
    TObjWeddingLobby(TObject *parent, void *set_data);
    virtual ~TObjWeddingLobby();
    s32 fade_state;  // 0 hidden, 2 fading in, 3 shown, 1 fading out
    // run_task's demo-mode step, empty in this build.
    void demo_step();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
    static void release();
    static void load_resources();
    f32 fade_scale;  // 0..1, the xz scale it fades in and out with
    u8 pad_d0[0x4];

    static BmlResource *resource_bundle;
    static u32 lobby_texlist;  // the lobby's shared texture list
};

typedef char TObjWeddingLobby_size[sizeof(TObjWeddingLobby) == 0xD4 ? 1 : -1];

#endif
