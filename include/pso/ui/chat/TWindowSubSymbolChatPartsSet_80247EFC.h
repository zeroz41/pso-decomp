#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTSSET_80247EFC_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTSSET_80247EFC_H

#include "types.h"

struct WindowLayoutEntries;

extern "C" {
void get_symbol_chat_frame_size(int a0, void *a1);
void apply_face_appearance_sprite(WindowLayoutEntries *entries, u8 appearance);
}
int set_symbol_chat_face_sprite(void *sprite, u8 b);
void set_symbol_chat_parts(WindowLayoutEntries *entries, void *data);

// --- C functions defined in TWindowSubSymbolChatPartsSet_80247EFC.cpp ---
extern "C" {
void get_symbol_chat_frame_size(int a0, void *a1);
void apply_face_appearance_sprite(WindowLayoutEntries *entries, u8 appearance);
}
// --- end of C functions

#endif
