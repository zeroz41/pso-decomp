#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_801BD384.h"
#include "pso/player/TObjPlayer_801BDD8C.h"

void *create_remote_player_object(void *record) {
    void *o;

    decode_remote_player_inventory(record);
    o = (void *)new TObjPlayer(tl_03, (void *)record);
    return o;
}
