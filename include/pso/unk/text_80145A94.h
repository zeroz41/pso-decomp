#ifndef PSO_UNK_TEXT_80145A94_H
#define PSO_UNK_TEXT_80145A94_H

#include "types.h"
#include "versions.h"

#if VERSION == VERSION_GPOP8P
// "Insert the game disc" / "wrong disc" messages, two per language (Japanese uses the English ones).
struct DiscErrorTitles {
    const char *titles[10];
};

extern "C" const DiscErrorTitles lbl_8043F21C;
#endif

extern "C" {
s32 TLobby__sub_80145A94(void);
s32 TLobby__sub_80145DB4(s32 arg0);
}

#endif
