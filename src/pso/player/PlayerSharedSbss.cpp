#include "pso/player/TObjPlayer.h"

// Data-only unit split off the shared player model buffers at 0x805D5D78.
// Plain uninitialized globals (-sdata 8) land in .sbss; the referencing unit
// keeps these extern.

u32 town_npc_shared_resource;
u32 lbl_805D5D7C;
u32 TObjPlayer__shared_model_buffer;
PlayerJointMatrixSet *player_shared_buffer_base;
u32 shared_state_flags[2];
