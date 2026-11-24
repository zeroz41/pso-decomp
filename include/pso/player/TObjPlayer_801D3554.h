#ifndef PSO_PLAYER_TOBJPLAYER_801D3554_H
#define PSO_PLAYER_TOBJPLAYER_801D3554_H

#include "types.h"

class TUnk_804C4450;
class TUnk_804C445C;
struct TObjBase;
struct TObjPlayer;
struct PendingItemDrop;
struct Vec;

extern "C" {
void create_drop_nodes__9TItemListFPvPvPvPvi(TUnk_804C445C *pool, Vec *position, TObjPlayer *owner,
                                             PendingItemDrop *records, s32 count);
}
void start_placement_search(TUnk_804C4450 *pool, Vec *pos, TObjBase *source);

#endif
