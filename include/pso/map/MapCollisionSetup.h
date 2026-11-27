#ifndef PSO_MAP_MAPCOLLISIONSETUP_H
#define PSO_MAP_MAPCOLLISIONSETUP_H

#include "types.h"
#include "pso/player/LocalClientId.h"

struct CsnGroup;
struct TObjMapCsn;
class TMapCsnCtrl;

CsnGroup *get_map_collision_group(TObjMapCsn *object);

// Floor prepare_adventure_maps (TSceneSora) sets up next through initialize_floor_transition; -1 = none.
extern s32 pending_adventure_map_floor;

extern TMapCsnCtrl *map_csn_ctrl_instance;

void create_map_csn_ctrl();

#endif
