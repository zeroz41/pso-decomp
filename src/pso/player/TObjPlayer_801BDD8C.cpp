#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_801BD384.h"
#include "pso/player/TObjPlayer_801BDD8C.h"

extern void *tl_03;

void *create_remote_player_object(void *record) {
    void *o;

    decode_remote_player_inventory(record);
    o = (void *)new TObjPlayer((TObject *)tl_03, (void *)record);
    return o;
}
