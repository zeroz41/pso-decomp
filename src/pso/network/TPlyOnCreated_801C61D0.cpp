#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TPlayerReadyCallback.h"
#include "pso/player/TObjPlayer.h"

#include "types.h"
#include "pso/network/TPlyOnCreated.h"

extern "C" {

void *get_player_by_client_id(s32 i);
void *__ct__13TPlyOnCreatedFv(void *, void *, void *);
void *__nw__7TObjectFUl(int);

void *TPlyOnCreated::create(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        o = __ct__13TPlyOnCreatedFv(o, arg0, arg1);
    }
    return o;
}

}
void TPlayerReadyCallback::run_task() {
    TObjPlayer* player = (TObjPlayer*)get_player_by_client_id(player_id);
    if (player != NULL && player->m_cfc == 0) {
        void (*fn)(TObjPlayer*) = callback;
        if (fn != NULL) {
            fn(player);
        }
        queue_destruction();
    }
}
