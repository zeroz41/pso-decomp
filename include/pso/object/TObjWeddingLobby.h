#ifndef PSO_OBJECT_TOBJWEDDINGLOBBY_H
#define PSO_OBJECT_TOBJWEDDINGLOBBY_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TObjWeddingLobby : public TUnk_804AFBF8 {
    TObjWeddingLobby(TObject *parent, void *set_data);
    virtual ~TObjWeddingLobby();
    s32 fade_state;  // 0 hidden, 2 fading in, 3 shown, 1 fading out
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0);
    static void release();
    static void load_resources();
    f32 fade_scale;  // 0..1, the xz scale it fades in and out with
    u8 pad_d0[0x4];
};

typedef char TObjWeddingLobby_size[sizeof(TObjWeddingLobby) == 0xD4 ? 1 : -1];

extern "C" {
void TObjWeddingLobby__sub_8035BC20(void);
}

#endif
