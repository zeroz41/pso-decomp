#ifndef PSO_UNK_TLOBBY_8013FFA8_H
#define PSO_UNK_TLOBBY_8013FFA8_H

#include "types.h"

extern "C" {
void TLobby__sub_80140308(void);
void TLobby__sub_801403B4(s32 _w0);
void TLobby__sub_801403B8(void);
}
void cleanup_dragon_area_scene(void);
s32 init_dragon_area_scene(void);
s32 init_ship_scene(void);
s32 load_scene_ship_b(void);
s32 ship_scene_update(void);

#endif
