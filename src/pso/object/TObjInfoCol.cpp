#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/object/TObjInfoCol.h"
#include "pso/misc/TPlyJoinLobbyEntry.h"
#include "pso/system/byteswap.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjInfoCol.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80191E28_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_80191EC0___vt__11TObjInfoCol {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
s32 is_idle__6TLobbyFv();
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 check_flag_100__10TObjPlayerFPv();
void *get_player_by_client_id(s32 i);
extern RecoveredGlobal_80191E28_lbl_8050E208 controller_input_state;
extern s32 local_client_id;
s32 __ct__14TObjCollidableFP7TObject(void *, void *);
extern s32 __vt__11TObjInfoCol[];
extern s32 TObjInfoCol__class_name;
void __dl__7TObjectFPv(void *);
f32 xyz_distance_squared(u8 *arg0, u8 *arg1);

void TObjInfoCol::bswap_6x78() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }

}

s32 TObjInfoCol::is_target_in_range(f32 radius_squared) {
    u32 player = (u32)get_player_by_client_id(local_client_id);
    if (player != 0 &&
        xyz_distance_squared((u8 *)((const Vec *) (player + 0x38)), (u8 *)((const Vec *)&position)) < radius_squared) {
        return 1;
    }
    return 0;
}

typedef char RecoveredGlobal_80191E28_lbl_8050E208_size[sizeof(RecoveredGlobal_80191E28_lbl_8050E208) == 0x1B0 ? 1 : -1];

void TObjInfoCol::run_task() {
    f32 radius = interaction_radius;
    u32 player;
    if (is_target_in_range(radius * radius) == 1 &&
        TWindowShortListCtrl__check_controller_button((u8 *) &controller_input_state.value + 0x20, 4) != 0 &&
        ((player = (u32)get_player_by_client_id(local_client_id), player == 0) ||
         check_flag_100__10TObjPlayerFPv() == 0) &&
        (player == 0 || ((TObjPlayer *)player)->is_inactive() != 0) &&
        is_idle__6TLobbyFv() != 0) {
        open_lobby_warp_menu__6TLobbyFv();
    }
}

typedef char RecoveredGlobal_80191EC0___vt__11TObjInfoCol_size[sizeof(RecoveredGlobal_80191EC0___vt__11TObjInfoCol) == 0x38 ? 1 : -1];
u8 *TObjInfoCol__ct(u8 *info_col, s32 arg1, s32 arg2) {
    __ct__14TObjCollidableFP7TObject((void *)info_col, (void *)arg1);
    *(s32 **)((s8 *)info_col + 0x18) = &(*(RecoveredGlobal_80191EC0___vt__11TObjInfoCol *)&__vt__11TObjInfoCol).value;
    *(s32 *)((s8 *)info_col + 0) = (s32) TObjInfoCol__class_name;
    ((TObjInfoCol *)(info_col))->apply_object_set_data((void *)arg2);
    ((TObjInfoCol *)info_col)->interaction_radius = (f32) ((TObjInfoCol *)info_col)->scale.x;
    return info_col;
}

TObjInfoCol::~TObjInfoCol() {

}
