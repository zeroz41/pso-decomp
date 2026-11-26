#ifndef PSO_UI_CHAT_CHATKEYWORD_H
#define PSO_UI_CHAT_CHATKEYWORD_H

#include "types.h"

// Returns the index of the first of names (a list ending in an empty name)
// found in s with a space added on each side, or -1. lower != 0 folds the
// letters of s to lower case first.
s32 find_chat_keyword(char *s, char (*names)[0x20], s32 lower);

#endif
