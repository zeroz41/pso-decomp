#include "types.h"
#include "pso/system/PadRumble.h"
#include "dolphin/pad.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/misc/TWindowKeyBoardHard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

extern s32 local_client_id;

static PadRumbleEffect pad_rumble_effect_slots[PAD_RUMBLE_EFFECT_COUNT];
static PadRumbleChannel pad_rumble_channel_states[PAD_RUMBLE_CHANNEL_COUNT];

void PadRumbleLevel::accumulate(s32 client_id, s32 channel) {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player != NULL) {
        PadRumbleEffect *effect = get_pad_rumble_effect_slots();
        s32 i = 0;
        do {
            if (effect->is_active() && ((effect->flags & PAD_RUMBLE_ALL_CLIENTS) || client_id == effect->client_id)) {
                if (effect->flags & PAD_RUMBLE_POSITIONAL) {
                    Vec offset;
                    offset.x = effect->pos.x - player->position.x;
                    offset.y = effect->pos.y - player->position.y;
                    offset.z = effect->pos.z - player->position.z;
                    s16 felt = effect->strength - 0.1f * ((TObjBoss2Tunnel *)&offset)->update_scale();
                    if (felt < 10) {
                        felt = 10;
                    }
                    strength += felt;
                } else {
                    strength += effect->strength;
                }
            }
            i++;
            effect++;
        } while (i < PAD_RUMBLE_EFFECT_COUNT);
    }
}

f32 PadRumbleLevel::on_rate() {
    s16 level = strength;
    if (level <= 0) {
        return 0.0f;
    }
    if (level >= 0x80) {
        return 256.0f;
    }
    return 256.0f * level / 128.0f;
}

f32 PadRumbleLevel::off_rate() {
    s16 level = strength;
    if (level >= 0x100) {
        return 0.0f;
    }
    if (level <= 0x80) {
        return 256.0f;
    }
    return 256.0f * (0x100 - level) / 128.0f;
}

void PadRumbleLevel::clear() {
    strength = 0;
}

BOOL PadRumbleChannel::update(PadRumbleLevel *level) {
    if (level->strength <= 0) {
        off_time = 0.0f;
        on_time = 256.0f;
        phase = 2;
        return FALSE;
    }
    switch (phase) {
    case 1:
        off_time += level->off_rate();
        if (off_time >= 256.0f) {
            phase = 2;
            off_time -= 256.0f;
            return FALSE;
        }
        return TRUE;
    case 0:
    case 2:
    case 3:
        on_time += level->on_rate();
        if (on_time >= 256.0f) {
            phase = 1;
            on_time -= 256.0f;
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}

BOOL PadRumbleEffect::is_active() {
    return flags & PAD_RUMBLE_ACTIVE;
}

void PadRumbleEffect::update() {
    if (is_active()) {
        if (flags & PAD_RUMBLE_ONE_SHOT) {
            if (flags & PAD_RUMBLE_FIRST_FRAME) {
                flags &= ~PAD_RUMBLE_FIRST_FRAME;
            } else {
                clear();
                return;
            }
        }
        if (flags & PAD_RUMBLE_TIMED) {
            if (flags & PAD_RUMBLE_FADE) {
                strength -= strength / duration;
            }
            duration--;
            if (duration <= 0) {
                clear();
            }
        }
    }
}

void PadRumbleEffect::clear() {
    flags = 0;
    pad_1 = 0;
    client_id = 0;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    strength = 0;
    duration = 0;
    id = 0;
}

void stop_pad_rumble() {
    s32 channel;

    reset_pad_rumble_effects_and_channels(2);
    channel = 0;
    do {
        PADControlMotor(channel, PAD_MOTOR_STOP);
        channel++;
    } while (channel < PAD_RUMBLE_CHANNEL_COUNT);
}

void cancel_pad_rumble(u32 id) {
    PadRumbleEffect *effect = find_active_pad_rumble_effect_by_id(id);
    if (effect != NULL) {
        effect->clear();
    }
}

void start_pad_rumble(s16 strength, u32 id) {
    PadRumbleEffect *effect = find_active_pad_rumble_effect_by_id(id);
    if (effect != NULL || (effect = find_free_pad_rumble_effect_slot()) != NULL) {
        effect->flags = PAD_RUMBLE_HAS_ID | PAD_RUMBLE_ALL_CLIENTS | PAD_RUMBLE_FADE | PAD_RUMBLE_ACTIVE;
        effect->strength = strength;
        effect->id = id;
    }
}

void start_pad_rumble_at(const Vec *pos, s16 strength, u32 id) {
    PadRumbleEffect *effect = find_active_pad_rumble_effect_by_id(id);
    if (effect != NULL || (effect = find_free_pad_rumble_effect_slot()) != NULL) {
        effect->flags = PAD_RUMBLE_HAS_ID | PAD_RUMBLE_FIRST_FRAME | PAD_RUMBLE_ONE_SHOT | PAD_RUMBLE_ALL_CLIENTS |
                        PAD_RUMBLE_FADE | PAD_RUMBLE_ACTIVE;
        if (pos != NULL) {
            effect->flags |= PAD_RUMBLE_POSITIONAL;
            VecCopy(&effect->pos, pos);
        }
        effect->strength = strength;
        effect->id = id;
    }
}

void start_pad_rumble_all(s16 strength, s16 duration) {
    PadRumbleEffect *effect = find_free_pad_rumble_effect_slot();
    if (effect != NULL) {
        effect->flags = PAD_RUMBLE_ALL_CLIENTS | PAD_RUMBLE_FADE | PAD_RUMBLE_TIMED | PAD_RUMBLE_ACTIVE;
        effect->strength = strength;
        effect->duration = duration;
    }
}

void start_pad_rumble_client(s16 strength, s16 duration, s16 client_id) {
    PadRumbleEffect *effect = find_free_pad_rumble_effect_slot();
    if (effect != NULL) {
        effect->flags = PAD_RUMBLE_FADE | PAD_RUMBLE_TIMED | PAD_RUMBLE_ACTIVE;
        effect->strength = strength;
        effect->duration = duration;
        effect->client_id = client_id;
    }
}

s32 get_pad_rumble_client(s32 channel) {
    switch (is_split_screen()) {
    case 0:
        if (channel != 0) {
            return PAD_RUMBLE_NO_CLIENT;
        }
        channel = local_client_id;
        break;
    }
    if (TWindowKeyBoardHard::test_card_flag_8(channel)) {
        return PAD_RUMBLE_NO_CLIENT;
    }
    if (get_player_by_client_id(channel) != NULL) {
        return channel;
    }
    return PAD_RUMBLE_NO_CLIENT;
}

PadRumbleEffect *find_active_pad_rumble_effect_by_id(u32 id) {
    PadRumbleEffect *effect = pad_rumble_effect_slots;
    s32 i = 0;
    do {
        if (effect->is_active() && (effect->flags & PAD_RUMBLE_HAS_ID) && effect->id == id) {
            return effect;
        }
        i++;
        effect++;
    } while (i < PAD_RUMBLE_EFFECT_COUNT);
    return NULL;
}

PadRumbleEffect *find_free_pad_rumble_effect_slot() {
    PadRumbleEffect *effect = pad_rumble_effect_slots;
    s32 i = 0;
    do {
        if (!effect->is_active()) {
            return effect;
        }
        i++;
        effect++;
    } while (i < PAD_RUMBLE_EFFECT_COUNT);
    return NULL;
}

void reset_pad_rumble_effects_and_channels(s16 phase) {
    PadRumbleEffect *effect = pad_rumble_effect_slots;
    PadRumbleChannel *channel;
    s32 i;
    for (i = 0; i < PAD_RUMBLE_EFFECT_COUNT; i++, effect++) {
        effect->clear();
    }
    channel = pad_rumble_channel_states;
    for (i = 0; i < PAD_RUMBLE_CHANNEL_COUNT; i++, channel++) {
        channel->phase = phase;
        channel->off_time = 0.0f;
        channel->on_time = 0.0f;
    }
}

PadRumbleEffect *get_pad_rumble_effect_slots() {
    return pad_rumble_effect_slots;
}

void update_pad_rumble() {
    s32 client_id;
    PadRumbleChannel *channel;
    PadRumbleEffect *effect;
    s32 i;
    channel = pad_rumble_channel_states;
    for (i = 0; i < PAD_RUMBLE_CHANNEL_COUNT; i++, channel++) {
        client_id = get_pad_rumble_client(i);
        if (client_id == PAD_RUMBLE_NO_CLIENT) {
            PADControlMotor(i, PAD_MOTOR_STOP);
        } else {
            PadRumbleLevel level;
            level.clear();
            level.accumulate(client_id, i);
            if (channel->update(&level)) {
                PADControlMotor(i, PAD_MOTOR_RUMBLE);
            } else {
                PADControlMotor(i, PAD_MOTOR_STOP);
            }
        }
    }
    effect = pad_rumble_effect_slots;
    for (i = 0; i < PAD_RUMBLE_EFFECT_COUNT; i++, effect++) {
        effect->update();
    }
}

void init_pad_rumble() {
    reset_pad_rumble_effects_and_channels(0);
}

s32 TWindowKeyBoardHard::test_card_flag_8(s32 client_id) {
    return test_card_flag(client_id, 8);
}
