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
NJS_TEXLIST *get_city_season_xmas_model(int a0);
s32 TLobby__sub_80184C54(void);
int TLobby__sub_80184C6C(int a0);
void TLobby__sub_80184C80(void *p);
void TLobby__sub_80184CE0(void *p);
}
BmlResource *get_season_model_resource(int a0);

extern StripBufferPair *city_season_strips;
extern BmlResource *city_season_board_resource;
extern saddr city_season_board_model;
extern saddr city_season_board_aux;
extern NJS_TEXLIST *city_season_board_texlist;
extern StripBufferPair *city_season_board_strips;


#endif
