#ifndef PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PLAYERTYPES_H
#define PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PLAYERTYPES_H

#include "types.h"

struct LobbyAnimationState { G_ClientIDHeader header; s16 animation_number; u16 unused; u32 player_flags; f32 animation_timer; };

#endif
