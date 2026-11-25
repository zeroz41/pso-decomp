#ifndef PSO_OBJECT_CITY_CITYSEASONRESOURCES_H
#define PSO_OBJECT_CITY_CITYSEASONRESOURCES_H

#include "types.h"

struct BmlResource;
struct NJS_TEXLIST;
struct NJS_OBJECT;
struct StripBufferPair;

extern BmlResource *city_season_resources[6];
extern NJS_TEXLIST *city_season_texlists[6];
extern StripBufferPair *city_season_strips;
extern BmlResource *city_season_board_resource;
extern NJS_OBJECT *city_season_board_model;
extern NJS_OBJECT *city_season_board_pillar_model;
extern NJS_TEXLIST *city_season_board_texlist;
extern StripBufferPair *city_season_board_strips;

NJS_TEXLIST *get_city_season_texlist(s32 season);
BmlResource *get_city_season_resource(s32 season);
s32 is_city_season_active();
s32 is_city_season_enabled(s32 season);
void enable_city_season_for_event_theme();
void disable_city_seasons();
void clear_city_season_flags();
void free_city_season_resources();
void load_city_season_resources();

#endif
