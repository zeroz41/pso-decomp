#include "types.h"
#include "pso/unk/TLobby_803CD804.h"
#include "pso/unk/TLobby.h"

extern s32 lobby_adxf_current_file_id;
extern s32 lobby_adxf_open_file_handle;
extern s32 lobby_afs_toc_entry_index;
extern s32 lbl_805D75E8;

void TLobby__sub_803CD804(void) {
    ((TLobby *)lobby_adxf_open_file_handle)->close_adxf_handle();
    lobby_adxf_open_file_handle = 0;
    lobby_adxf_current_file_id = -1;
    lobby_afs_toc_entry_index = 0;
    lbl_805D75E8 = 0;
}
