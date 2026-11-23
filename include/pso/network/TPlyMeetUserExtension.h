#ifndef PSO_NETWORK_TPLYMEETUSEREXTENSION_H
#define PSO_NETWORK_TPLYMEETUSEREXTENSION_H

#include "types.h"
#include "pso/macros.h"
#include "pso/player/TPlyGuildCardTag.h"

class TPlyMeetUserExtension {
public:
    TPlyMeetUserExtension();

    TPlyGuildCardTag tags[8];
    u32 mbr_0x40;
    char player_name[16];
    char player_name2[16];
public:
    void bswap();
};
LAYOUT_ASSERT(TPlyMeetUserExtensionSize, sizeof(TPlyMeetUserExtension) == 0x64);

#endif
