#ifndef PSO_UNK_TEXT_8006EF90_H
#define PSO_UNK_TEXT_8006EF90_H

#include "types.h"
#include "versions.h"

extern "C" {
#if VERSION == VERSION_GPOP8P
void TLobby__sub_8006EF90(void);
void fn_8006F00C(void);
#else
int TLobby__sub_8006EF90(void);
#endif
}

// --- C functions defined in text_8006EF90.cpp ---
extern "C" {
#if VERSION == VERSION_GPOP8P
void TLobby__sub_8006EF90(void);
void fn_8006F00C(void);
#else
int TLobby__sub_8006EF90(void);
#endif
}
// --- end of C functions

#endif
