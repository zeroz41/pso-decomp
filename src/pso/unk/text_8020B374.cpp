#include "types.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_8020B3E4_TLobby__data_80513C80 {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_8020B374_TLobby__data_80513CC8 {
    s32 value;
    u8 remaining[0x8C];
};

extern "C" {
s32 load_floor_enemy_group_entries__6TLobbyFiPvUi(s32, void *, u32);
extern RecoveredGlobal_8020B3E4_TLobby__data_80513C80 TLobby__data_80513C80;
s32 init_quest_floor_enemies(s32, void *, u32);
extern RecoveredGlobal_8020B374_TLobby__data_80513CC8 TLobby__data_80513CC8;
typedef char RecoveredGlobal_8020B3E4_TLobby__data_80513C80_size[sizeof(RecoveredGlobal_8020B3E4_TLobby__data_80513C80) == 0x48 ? 1 : -1];

typedef char RecoveredGlobal_8020B374_TLobby__data_80513CC8_size[sizeof(RecoveredGlobal_8020B374_TLobby__data_80513CC8) == 0x90 ? 1 : -1];
s32 TLobby::init_floor_enemy_count(s32 arg0, u8 *arg1, u32 arg2) {
    if (init_quest_floor_enemies(arg0, arg1, arg2) == 1) {
        *(s32 *)((s8 *)&TLobby__data_80513CC8.value + (arg0 * 4)) = arg2 / 72U;
        return 1;
    }
    *(s32 *)((s8 *)&TLobby__data_80513CC8.value + (arg0 * 4)) = -1;
    return 0;
}

s32 TLobby::load_object_set_entries(s32 arg0, u8 *arg1, u32 arg2) {
    if (load_floor_enemy_group_entries__6TLobbyFiPvUi(arg0, arg1, arg2) == 1) {
        *(s32 *)((s8 *)&TLobby__data_80513C80.value + (arg0 * 4)) = arg2 / 68U;
        return 1;
    }
    *(s32 *)((s8 *)&TLobby__data_80513C80.value + (arg0 * 4)) = -1;
    return 0;
}

int TLobby::get_object_type(int a0) {  return ((int *)&TLobby__data_80513CC8)[a0]; }

int TLobby::get_obj_table_entry(int a0) {  return ((int *)&TLobby__data_80513C80)[a0]; }

}
