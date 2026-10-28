#ifndef PSO_PLAYER_TOBJPLAYER_8023E480_H
#define PSO_PLAYER_TOBJPLAYER_8023E480_H

#include "types.h"
#include "pso/system/GinjaMaterialState.h"

extern "C" {
s32 bind_gvm_texture_list(const char *name, GinjaTextureList *texlist);
s32 TLobby__sub_8023E4B4(s32 arg0, s32 arg1);
s32 TLobby__sub_8023E554(s32 arg0, s32 arg1);
s32 fn_8023E734(u32 arg0);
s32 free_texture_if_valid(u32 arg0);
void init_buffers(void);
}

// Makes texlist the current texture list; 0 when texlist is null.
s32 set_texlist(u32 texlist);

#endif
