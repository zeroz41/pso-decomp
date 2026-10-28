#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_801BD384.h"
#include "pso/player/TObjPlayer_801BDD8C.h"

extern "C" {

void *__nw__7TObjectFUl(int);
}

extern void *tl_03;

void *create_remote_player_object(void *arg0) {
    void *o;

    decode_remote_player_inventory(arg0);
    o = __nw__7TObjectFUl(0xDB8);
    if (o != NULL) {
        o = __ct__10TObjPlayerFPvPvPv((TObjPlayer *)o, tl_03, arg0);
    }
    return o;
}
