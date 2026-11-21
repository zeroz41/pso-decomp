#ifndef PSO_MAP_CHALLENGE_ENEMY_SET_H
#define PSO_MAP_CHALLENGE_ENEMY_SET_H

#include "types.h"
#include <stddef.h>

enum {
    ChallengeEnemyBufferSize = 0x9000,
    ChallengeEventBufferSize = 0x1400,
    ChallengeCommandBufferSize = 0x1000,
};

struct ChallengeEventHeader {
    s32 commandOffset;
    s32 eventOffset;
    s32 eventCount;
    u32 format;

    void swap_endian();
};

struct ChallengeRandomEvent {
    s32 id;
    s16 flags;
    s16 eventType;
    s16 room;
    s16 wave;
    s16 minDelay;
    s16 maxDelay;
    u8 minEnemies;
    u8 maxEnemies;
    s16 maxWaves;
    s32 commandOffset;

    void swap_endian();
};

struct ChallengeFixedEvent {
    s32 id;
    s16 flags;
    s16 eventType;
    s16 room;
    s16 wave;
    s32 delay;
    s32 commandOffset;
};

struct ChallengeEventCommand {
    enum {
        Stop = 0x01,
        TriggerEvent = 0x0C,
    };

    u8 opcode;

    void append() const;
};

LAYOUT_ASSERT(ChallengeEventHeaderSize, sizeof(ChallengeEventHeader) == 0x10);
LAYOUT_ASSERT(ChallengeRandomEventSize, sizeof(ChallengeRandomEvent) == 0x18);
LAYOUT_ASSERT(ChallengeFixedEventSize, sizeof(ChallengeFixedEvent) == 0x14);
LAYOUT_ASSERT(ChallengeFixedEventCommandOffset, offsetof(ChallengeFixedEvent, commandOffset) == 0x10);

extern "C" {
extern u8 *challenge_event_source;
extern u8 *challenge_enemy_buffer;
extern ChallengeFixedEvent *challenge_event_buffer;
extern s32 challenge_event_count;
extern u8 *challenge_action_buffer;
extern s32 challenge_action_size;
extern s32 challenge_event_source_size;
}

void build_challenge_enemy_set(s32 floor);

#endif
