#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_801BD384.h"
#include "pso/player/TObjPlayer_801BDD8C.h"

extern void *tl_03;

void *create_remote_player_object(void *arg0) {
    void *o;

    decode_remote_player_inventory(arg0);
    o = (void *)new TObjPlayer((TObject *)tl_03, (void *)arg0);
    return o;
}
