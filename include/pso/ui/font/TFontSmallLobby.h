#ifndef PSO_UI_FONT_TFONTSMALLLOBBY_H
#define PSO_UI_FONT_TFONTSMALLLOBBY_H

#include "types.h"

// Class name of the lobby player label TObject (TObjPlayer checks its m_54c object by it).
extern const char *TFontSmallLobby__name;

struct TFontSmallLobby
{
    static void *create(s32 id);
    static s32 is_lobby_floor_15();
    static void draw_small_label(int line);
};


#endif
