#ifndef PSO_PLAYER_TOBJPLAYER_803130BC_H
#define PSO_PLAYER_TOBJPLAYER_803130BC_H

#include "types.h"

struct PhotonBlastRequest;
struct PhotonBlastRegistry;
struct PhotonBlastRequestSlot;

extern "C" {
int TObjPlayer__sub_803131AC(const PhotonBlastRegistry *registry);
PhotonBlastRequestSlot *TObjPlayer__sub_803131B4(PhotonBlastRequest *slot, s32 index);
int TObjPlayer__sub_80313218(PhotonBlastRequest *slot);
void TObjPlayer__sub_80313250(PhotonBlastRequestSlot *entry, s32 amount);
}

#endif
