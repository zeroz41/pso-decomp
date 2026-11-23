#ifndef PSO_UNK_TEXT_80184C2C_H
#define PSO_UNK_TEXT_80184C2C_H

#include "types.h"

struct BmlResource;
struct NJS_TEXLIST;
struct NJS_OBJECT;
struct StripBufferPair;

extern "C" {
extern BmlResource *city_season_easter_egg_model_table[6];
extern NJS_TEXLIST *city_season_xmas_model_table[6];
NJS_TEXLIST *TLobby__sub_80184C2C(int a0);
s32 TLobby__sub_80184C54(void);
int TLobby__sub_80184C6C(int a0);
void TLobby__sub_80184C80(void *p);
void TLobby__sub_80184CE0(void *p);
}
BmlResource *get_season_model_resource(int a0);

extern StripBufferPair *lbl_805D5B34;
extern BmlResource *lbl_805D5B38;
extern saddr lbl_805D5B3C;
extern saddr lbl_805D5B40;
extern NJS_TEXLIST *lbl_805D5B44;
extern StripBufferPair *lbl_805D5B48;


#endif
