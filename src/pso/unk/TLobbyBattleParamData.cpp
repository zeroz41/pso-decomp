#include "types.h"

// Data-only unit split off TLobby_8001D6A0 at 0x805D4A98: the lobby battle
// parameter statics. Plain uninitialized globals (-sdata 8) land in .sbss; the
// referencing unit keeps them extern.

u8 auto_reply_flags[0x8];
u32 TLobby__battle_parameter_buffer;
u32 battle_param_stats;
u32 TLobby__battle_param_attacks;
u32 TLobby__battle_param_resistances;
u32 battle_param_movement;
u32 battle_parameter_difficulty;
u32 battle_param_lab_variant;
u32 TLobby__lobby_instance;
