#ifndef PSO_PLAYER_PLAYERSCALESTATE_H
#define PSO_PLAYER_PLAYERSCALESTATE_H

#include "types.h"
#include "pso/network/protocol/protocol_types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/data/FlagWord.h"
#include <stddef.h>

// One of the follow-camera offsets a shrunken player's camera uses.
struct PlayerCameraOffset : Vec {
    PlayerCameraOffset();
    void set(f32 x, f32 y, f32 z);
    Vec *get();
};

struct PlayerCameraOffsets {
    PlayerCameraOffsets();

    PlayerCameraOffset position;
    PlayerCameraOffset target;
};

// TObjPlayer + 0x5B0: the shrink state (quest opcodes shrink/unshrink, packets 6x87/6x88).
struct PlayerScaleState {
    PlayerScaleState();
    void init();
    void set_scalar(f32 scalar);
    void set_scale(f32 scale);
    Vec *get_scale();
    void set_actor_id(u16 id);
    u16 get_actor_id();
    // Bit 0: the player is drawn at scalar times its size.
    int is_scaled();
    f32 get_scalar();
    void shrink(f32 scalar);
    void clear_shrink_flag();
    void request_shrink();
    void request_size_restore();
    void update_camera();

    u16 actor_id;
    u16 padding;
    FlagWord flags;
    f32 scalar;
    Vec scale;
    PlayerCameraOffsets camera;
};

LAYOUT_ASSERT(PlayerScaleState_size, sizeof(PlayerScaleState) == 0x30);
LAYOUT_ASSERT(PlayerScaleFlagsOffset, offsetof(PlayerScaleState, flags) == 4);
LAYOUT_ASSERT(PlayerScaleCameraOffset, offsetof(PlayerScaleState, camera) == 0x18);

struct PlayerShrinkPacket {
    void initialize();
    PlayerShrinkPacket *copy_from(const PlayerShrinkPacket &source);
    void byte_swap();
    void send();

    G_ClientIDHeader header;
    f32 scalar;
};

struct PlayerRestoreSizePacket {
    void initialize();
    PlayerRestoreSizePacket *copy_from(const PlayerRestoreSizePacket &source);
    void send();

    G_ClientIDHeader header;
};

LAYOUT_ASSERT(PlayerShrinkPacketSize, sizeof(PlayerShrinkPacket) == 8);
LAYOUT_ASSERT(PlayerShrinkPacketScalarOffset, offsetof(PlayerShrinkPacket, scalar) == 4);
LAYOUT_ASSERT(PlayerRestoreSizePacketSize, sizeof(PlayerRestoreSizePacket) == 4);

#endif
