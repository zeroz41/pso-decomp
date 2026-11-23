#ifndef PSO_PLAYER_TOBJPLAYER_801D3554_H
#define PSO_PLAYER_TOBJPLAYER_801D3554_H

#include "types.h"

class TUnk_804C4450;
class TUnk_804C445C;
struct TObjBase;
struct TObjPlayer;
struct PendingItemDrop;
struct Vec;

u8 *copy_drop_node(u8 *arg0, u8 *arg1);
extern "C" {
void fn_801D371C(void *p, void *q);
void create_drop_nodes__9TItemListFPvPvPvPvi(TUnk_804C445C *pool, Vec *position, TObjPlayer *owner,
                                             PendingItemDrop *records, s32 count);
}
void start_placement_search(TUnk_804C4450 *pool, Vec *pos, TObjBase *source);

#endif
