#ifndef PSO_OBJECT_TOBJTREELOBBY_H
#define PSO_OBJECT_TOBJTREELOBBY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct TObjTreeLobby : public TObjMapObject {
    TObjTreeLobby(TObject *parent, void *set_data);
    virtual ~TObjTreeLobby();
    s32 fade_state;  // 0 hidden, 2 fading in, 3 shown, 1 fading out
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0);
    static void destroy_static_instance();
    static void load_resources();
    f32 fade_scale;  // 0..1, the xz scale it fades in and out with
};

typedef char TObjTreeLobby_size[sizeof(TObjTreeLobby) == 0xD0 ? 1 : -1];

extern "C" {
void *__dt__13TUnk_804F2B60Fv(void *arg0, s16 arg1);
}

#endif
