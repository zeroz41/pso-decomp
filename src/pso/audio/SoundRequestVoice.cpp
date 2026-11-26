#include "pso/network/protocol/packet_classes.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/system/memory.h"
#include "types.h"
#include <string.h>
#include "pso/network/TProtocol.h"
#include "pso/audio/SoundRequestVoice.h"
#include "pso/unk/GuildCardRecord.h"
#include "pso/network/TLobby.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/TLobby_8023F734.h"
#include "pso/unk/TLobby_80242910.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "dolphin/mtx.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/math/AngleLookup.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"
#include <dolphin/os/OSInterrupt.h>


void SoundRequestVoice::set_field0(SoundControlState *owner) { this->owner = owner; }


void SoundRequestVoice::clamp_reverb(f32 scale) {
    f32 reverb_value;

    reverb_value = scale;
    if (reverb_value < 0.0f) {
        reverb = -1.0f;
        return;
    }
    if (reverb_value > 1.0f) {
        reverb_value = 1.0f;
    }
    reverb = reverb_value;
}

void sound_request_voice_set_refresh(SoundRequestVoice *voice) { voice->refresh = 5; }

extern "C" s32 sndFXCtrl14(u32 vid, u8 ctrl, u16 value);

void sound_request_voice_update_pitch(SoundRequestVoice *v) {
    switch (v->kind) {
    case 0:
        if (v->previousPitch != v->pitch) {
            sndFXCtrl14(v->token, 0x80, v->pitch);
            v->previousPitch = v->pitch;
        }
        break;
    }
}

void SoundRequestVoice::update() {
    s32 remaining;
    s32 duration;

    if ((u32) (pitchDuration + 0x77780000) == 0x8888U) {
        pitchRemaining = 0;
        pitchDuration = 0;
        pitchSlide = (s32) pitchTarget;
    }
    duration = pitchDuration;
    if (duration > 0) {
        remaining = pitchRemaining;
        if (remaining <= 0) {
            pitchRemaining = 0;
            pitchDuration = 0;
            pitchSlide = (s32) pitchTarget;
        } else {
            pitchSlide = (s32) ((s32) (pitchTarget * (duration - remaining)) / duration);
            pitchRemaining = (s32) (pitchRemaining - owner->get_field_308());
        }
    }
    pitch = (s32) (pitchStatic + pitchMoving + pitchSlide);
    pitch = (s32) (pitch + 0x2000);
    if ((s32) pitch < 0) {
        pitch = 0;
    }
    if ((s32) pitch > 0x3FFF) {
        pitch = 0x3FFF;
    }
}

#undef sound_request_voices
#pragma push


extern "C" {
s32 sndFXCtrl(int, int, int);
s32 sndFXKeyOff(int);
void TLobby__sub_80240F3C(SoundRequestVoice *);
extern s8 gba_joyboot_states[];
void TLobby__sub_80241798(SoundRequestVoice *sound);
}
void calc_sound_spatial_params(SoundRequestVoice *);
void send_voice_controller_updates(SoundRequestVoice *voice);

s32 set_voice_pitch_slide(SoundRequestVoice *voice, s32 target, s32 duration) {
    s32 duration_ticks;
    duration_ticks = duration;
    if (duration_ticks <= 0) {
        duration_ticks = 0x88888888;
    }
    voice->pitchTarget = target;
    voice->pitchDuration = duration_ticks;
    voice->pitchRemaining = duration_ticks;
    return 0;
}

s32 tick_sound_voice(SoundRequestVoice *v) {
    SND_PARAMETER_INFO params;
    SND_PARAMETER ctl[6];
    s32 level;
    s32 fade;
    s32 step;
    switch (v->kind) {
    case 0:
    switch (v->state) {
    case -1:
        v->age++;
        v->effect = resolve_sound_effect_bank(v->owner, v->kind, v->bank, v->index);
        if (v->effect < 0) {
            v->state = 0;
            return 0;
        }
        if (v->delay != 0) {
            v->delay--;
            break;
        }
        ((void (*)(SoundRequestVoice *))TLobby__sub_80241A0C)(v);
        TLobby__sub_80241798(v);
    start:
        ((void (*)(SoundRequestVoice *))TLobby__sub_80240F38)(v);
        TLobby__sub_80240F3C(v);
        calc_sound_spatial_params(v);
        v->clamp_params();
        v->update();
        params.numPara = 1;
        params.paraArray = ctl;
        ctl[0].ctrl = 0x80;
        ctl[0].paraData.value14 = v->pitch;
        if (!(lobby_state_flags & 2) && gba_joyboot_states[7] == 0) {
            level = OSDisableInterrupts();
        }
        v->token = sndFXStartParaInfo(v->effect, 0x7F, v->pan, v->studio, &params);
        send_voice_controller_updates(v);
        if (!(lobby_state_flags & 2) && gba_joyboot_states[7] == 0) {
            OSRestoreInterrupts(level);
        }
        send_sound_request_reverb((v));
        v->state = 1;
        break;
    case 0:
        break;
    case 1:
        if (v->flags & 0x80) {
            v->pitchMoving += v->pitchVelocity;
            if (v->pitchVelocity > 0) {
                if (v->pitchMoving > v->pitchLimit) {
                    v->pitchVelocity = -v->pitchVelocity;
                }
            } else if (v->pitchMoving < -v->pitchLimit) {
                v->pitchVelocity = -v->pitchVelocity;
            }
        }
        v->age++;
        fade = v->fade;
        if (fade <= -0x7F) {
            sndFXKeyOff(v->token);
            v->state = 0;
            break;
        }
        step = v->fadeStep;
        if (step != 0) {
            v->fade = fade - step;
        }
        if (v->flags & 1) {
            if (v->refresh >= 5) {
                calc_sound_spatial_params(v);
            }
        } else {
            calc_sound_spatial_params(v);
        }
        v->refresh--;
        send_sound_request_reverb((v));
        v->clamp_params();
        v->update();
        if (sndFXCheck(v->token) == 0xFFFFFFFF) {
            if ((v->flags & 1) && v->refresh >= 0) {
                sndFXKeyOff(v->token);
                v->previousPan = v->previousSurround = v->previousVolume = 0x88888888;
                goto start;
            }
            v->state = 0;
        } else {
            send_voice_controller_updates(v);
            sound_request_voice_update_pitch(v);
            if ((v->flags & 1) && v->refresh < 0) {
                sndFXKeyOff(v->token);
                v->state = 0;
            }
        }
        break;
    }
        break;
    }
    return 0;
}

void SoundRequestVoice::update_random_flip_flag() {
    switch (bank) {
    case 0:
        switch (index) {
        case 0: case 1: case 2: case 3: case 4:
        case 7: case 8: case 9:
        case 21:
        case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
            flags |= 0x100;
            break;
        }
        break;
    }
    if (flags & 0x100) {
        delay = (s16)(owner->advance_rng() & 1);
    }
}

void TLobby__sub_80240F38(void) {  }

void TLobby__sub_80240F3C(SoundRequestVoice *v) {
    s32 num = 1;
    s32 den = 1;
    s32 extra = 0;
    switch (v->bank) {
    case 0:
        switch (v->index) {
        case 0: case 1: case 2: case 3: case 4:
        case 7: case 9:
        case 18: case 21:
        case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
            v->flags |= 0x40;
            break;
        }
        break;
    case 3:
        switch (v->owner->group_state) {
        case 2:
            switch (v->index) {
            case 12:
                den = 1;
                v->flags |= 0x40;
                break;
            case 1: case 24:
                den = 4;
                v->flags |= 0x40;
                break;
            }
            break;
        case 8:
            switch (v->index) {
            case 31:
                v->flags |= 0x40;
                break;
            }
            break;
        case 12:
            switch (v->index) {
            case 33: case 43: case 64: case 65:
                v->flags |= 0x40;
                break;
            }
            break;
        case 16:
            switch (v->index) {
            case 17: case 51: case 52:
                v->flags |= 0x40;
                break;
            }
            break;
        }
        switch (v->owner->group_state) {
        case 2:
            switch (v->index) {
            case 13:
                v->flags |= 0x40;
                break;
            case 36:
                den = 2;
                v->flags |= 0x40;
                break;
            case 47:
                den = 6;
                extra = 0x1C00;
                v->flags |= 0x40;
                break;
            }
            break;
        case 10:
            switch (v->index) {
            case 1:
                den = 4;
                v->flags |= 0x40;
                break;
            case 13:
                den = 2;
                v->flags |= 0x40;
                break;
            case 32:
                den = 3;
                v->flags |= 0x40;
                break;
            case 34:
                v->flags |= 0x40;
                break;
            case 41:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 11:
            switch (v->index) {
            case 1:
                den = 4;
                v->flags |= 0x40;
                break;
            case 13:
                den = 2;
                v->flags |= 0x40;
                break;
            case 32:
                den = 3;
                v->flags |= 0x40;
                break;
            case 34:
                v->flags |= 0x40;
                break;
            case 41:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 14:
            switch (v->index) {
            case 1:
                den = 1;
                v->flags |= 0x40;
                break;
            case 2:
                v->flags |= 0x40;
                break;
            case 10:
                den = 4;
                v->flags |= 0x40;
                break;
            case 22:
                v->flags |= 0x40;
                break;
            case 36:
                den = 3;
                v->flags |= 0x40;
                break;
            case 42:
                den = 2;
                v->flags |= 0x40;
                break;
            case 54:
                den = 6;
                v->flags |= 0x40;
                break;
            case 57:
                v->flags |= 0x40;
                break;
            case 64:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 15:
            switch (v->index) {
            case 3: case 15:
                num = 2;
                v->flags |= 0x40;
                break;
            case 17:
                den = 4;
                v->flags |= 0x40;
                break;
            case 37: case 38:
                v->flags |= 0x40;
                break;
            case 16:
                break;
            }
            break;
        case 19:
            switch (v->index) {
            case 2: case 8: case 22:
                num = 2;
                v->flags |= 0x40;
                break;
            case 15:
                v->flags |= 0x40;
                break;
            case 27: case 28:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 4:
            switch (v->index) {
            case 11: case 19:
                den = 3;
                v->flags |= 0x40;
                break;
            case 13: case 51: case 52:
                v->flags |= 0x40;
                break;
            case 12:
                break;
            }
            break;
        case 5:
            switch (v->index) {
            case 1: case 6:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 6:
            switch (v->index) {
            case 3: case 15: case 24:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 7:
            switch (v->index) {
            case 31:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 8:
            switch (v->index) {
            case 38: case 45: case 50: case 51:
                num = 2;
                v->flags |= 0x40;
                break;
            case 63:
                den = 12;
                v->flags |= 0x40;
                break;
            }
            break;
        case 9:
            switch (v->index) {
            case 34:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 18:
            switch (v->index) {
            case 13: case 14:
                v->flags |= 0x40;
                break;
            }
            break;
        case 12:
            switch (v->index) {
            case 2: case 12: case 19: case 21: case 40: case 48: case 57:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 16:
            switch (v->index) {
            case 2: case 3: case 37: case 39: case 45:
                num = 2;
                v->flags |= 0x40;
                break;
            case 38:
                break;
            }
            break;
        case 20:
            switch (v->index) {
            case 5: case 28: case 62:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        }
        break;
    case 6:
        switch (v->owner->group_state) {
        case 17:
            switch (v->index) {
            case 22: case 30: case 31:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        }
        break;
    }
    if (v->flags & 0x40) {
        v->pitchMoving = num * ((s32)((v->owner->advance_rng() >> 16) & 0x3F00) - 0x2000 + extra) / den;
    }
}

void TLobby__sub_80241798(SoundRequestVoice *sound) {
    s32 num = 1;
    s32 den = 1;
    s32 mask = 0;
    s32 min = 0;
    switch (sound->owner->group_state) {
    case 16:
        switch (sound->bank) {
        case 4:
            switch (sound->index) {
            case 5: case 6: case 7: case 8: case 9:
                mask = 0x3F;
                min = 0x40;
                sound->flags |= 0x80;
                break;
            }
            break;
        }
        break;
    case 2:
        switch (sound->bank) {
        case 4:
            switch (sound->index) {
            case 6:
                mask = 0x3F;
                min = 0x20;
                sound->flags |= 0x80;
                break;
            }
            break;
        }
        break;
    case 9:
        switch (sound->bank) {
        case 3:
            switch (sound->index) {
            case 0: case 1:
                mask = 0x3F;
                min = 0x80;
                sound->flags |= 0x80;
                break;
            }
            break;
        }
        break;
    case 12:
        switch (sound->bank) {
        case 4:
            switch (sound->index) {
            case 11:
                mask = 0x3F;
                min = 0x20;
                sound->flags |= 0x80;
                break;
            case 12: case 13:
                mask = 0x3F;
                min = 0x60;
                sound->flags |= 0x80;
                break;
            }
            break;
        case 3:
            switch (sound->index) {
            case 20:
                den = 6;
                mask = 0x3F;
                min = 0x20;
                sound->flags |= 0x80;
                sound->pitchLimit = 0x1000;
                break;
            }
            break;
        }
        break;
    case 13:
        switch (sound->bank) {
        case 3:
            switch (sound->index) {
            case 5:
                num = 2;
                mask = 0x3F;
                min = 0xC0;
                sound->flags |= 0x80;
                break;
            case 21: case 22:
                mask = 0x3F;
                min = 0x40;
                sound->flags |= 0x80;
                break;
            }
            break;
        }
        break;
    }
    if (sound->flags & 0x80) {
        sound->pitchMoving = num * ((s32)((sound->owner->advance_rng() >> 16) & 0x3FFF) - 0x2000) / den;
        sound->pitchVelocity = min + (mask & sound->owner->advance_rng());
        if ((s32)(sound->owner->advance_rng() & 0x3F) < 0x20) {
            sound->pitchVelocity = -sound->pitchVelocity;
        }
    }
}

void TLobby__sub_80241A0C(void) {  }


void send_sound_request_reverb(SoundRequestVoice *voice) {
    f32 request = voice->reverb;
    s32 amount;
    if (request < 0.0f) {
        if (voice->bank == 5 || (voice->flags & 0x10)) amount = 0;
        else amount = s32(127.0f * voice->owner->reverb_level);
    } else amount = s32(127.0f * request);
    if (voice->bank == 6) {
        switch (voice->index) {
        case 12:
        case 25:
            return;
        default:
            break;
        }
    }
    if (voice->previousReverb != u8(amount))
        sndFXCtrl(voice->token, 91, amount);
}

void send_voice_controller_updates(SoundRequestVoice *voice) {
    switch (voice->kind) {
    case 0:
    if ((voice->previousVolume) != voice->volume) {
        voice->previousVolume = voice->volume;
        sndFXCtrl((int) (voice->token), 7, (int) ((u8) voice->volume));
    }
    if ((voice->previousPan) != voice->pan) {
        voice->previousPan = voice->pan;
        sndFXCtrl((int) (voice->token), 0xA, (int) ((u8) voice->pan));
    }
    if (voice->bank == 5) {
        sndFXCtrl((int) (voice->token), 0x83, (int) (0U));
        return;
    }
    if ((voice->previousSurround) != voice->surround) {
        voice->previousSurround = voice->surround;
        sndFXCtrl((int) (voice->token), 0x83, (int) ((u8) voice->surround));
    }
        break;
    }
}

void SoundRequestVoice::clamp_params() {
    volume = (((fade + extra) + base) + spatial) + 0x7F;
    pan = (s32) (0x40 - (panExtra + panSpatial));
    surround = (s32) ((surroundExtra + surroundSpatial) + 0x40);
    volume = (s32) (volume + owner->voice_volume_adjustment);
    if (volume < 0) {
        volume = 0;
    }
    if (volume > 0x7F) {
        volume = 0x7F;
    }
    if (pan < 0) {
        pan = 0;
    }
    if (pan > 0x7F) {
        pan = 0x7F;
    }
    if (surround < 0) {
        surround = 0;
    }
    if (surround > 0x7F) {
        surround = 0x7F;
    }
}

// Volume, pan and surround of a positioned voice from the listener: the camera,
// or in split screen the nearest viewed player. Dark Falz and Olga Flow double
// the hearing range.
void calc_sound_spatial_params(SoundRequestVoice *v) {
    s32 pan = 0;
    s32 volume = 0;
    s32 surround = 0;
    if (camera_ctrl_instance != NULL) {
        Vec listener;
        Vec source;
        listener.x = camera_ctrl_instance->pos.x;
        listener.y = 0.0f;
        listener.z = camera_ctrl_instance->pos.z;
        if (v->position != NULL) {
            f32 dist;
            f32 range = 300.0f;
            if (get_current_floor_area() == AREA_DARK_FALZ || get_current_floor_area() == AREA_OLGA_FLOW) {
                range *= 2.0f;
            }
            source.x = v->position->x;
            source.y = 0.0f;
            source.z = v->position->z;
            if (is_split_screen()) {
                dist = 10000.0f;
                TCameraCtrl::get_camera_id();
                for (s32 i = 0; i < TCameraCtrl::get_camera_id(); i++) {
                    s32 id = TCameraCtrl::get_nth_view_player_id(i);
                    if (id < 12) {
                        TObjPlayer *player = get_player_by_client_id(id);
                        if (player != NULL) {
                            listener.x = player->position.x;
                            listener.y = 0.0f;
                            listener.z = player->position.z;
                        }
                        f32 d = horizontal_distance_squared(&listener, &source);
                        if (dist > d) {
                            dist = d;
                        }
                    }
                }
                if (dist != 10000.0f) {
                    dist = newton_sqrtf(dist);
                }
            } else {
                if (TLobby::is_camera_state_active()) {
                    listener.x = camera_ctrl_instance->pos.x;
                    listener.y = 0.0f;
                    listener.z = camera_ctrl_instance->pos.z;
                } else {
                    TObjPlayer *player = get_player_by_client_id(local_client_id);
                    if (player != NULL) {
                        listener.x = player->position.x;
                        listener.y = 0.0f;
                        listener.z = player->position.z;
                    }
                }
                dist = PSVECDistance(&listener, &source);
            }
            if (is_split_screen() || (v->flags & 2)) {
                pan = 0;
            } else if (dist > 0.0f) {
                // inferred: direction to the source, 0x10000 units per turn
                f64 direction = 10430.38043493439 * atan2_float(v->position->z - camera_ctrl_instance->pos.z,
                                                                v->position->x - camera_ctrl_instance->pos.x);
                pan = (s8)(127.0f * -sin_table_lookup((s32)direction + camera_ctrl_instance->yaw + 0x4000));
            }
            if (is_split_screen() || (v->flags & 8)) {
                surround = 0;
            } else {
                const Vec *pos = v->position;
                f64 direction = 10430.38043493439 * atan2_float(pos->z - listener.z, pos->x - listener.x);
                s32 angle = (s32)direction + camera_ctrl_instance->yaw - 0x4000;
                surround = (s32)(dist * (cos_table_lookup(angle) * ((TLobby *)(v->owner))->get_field_2a4()));
            }
            if (v->flags & 4) {
                volume = 0;
            } else {
                f32 t = (dist - 40.0f) / (range - 40.0f);
                if (t < 0.0f) {
                    t = 0.0f;
                }
                t *= 127.0f;
                volume = -(s32)t;
            }
        }
    }
    v->spatial = volume;
    v->panSpatial = pan;
    v->surroundSpatial = surround;
}

s32 start_voice_fade(SoundRequestVoice *v, s32 step) {
    switch (v->kind) {
    case 0:
        if (v->fadeStep == 0) {
            if (step != 0) {
                v->fadeStep = step;
                v->fade = -step;
            } else {
                if (step == 0 && v->state == 1) {
                    sndFXKeyOff(v->token);
                }
                v->state = 0;
            }
        }
        break;
    }
    return 0;
}

#pragma push
s32 SoundRequestVoice::init_sound_voice(s32 kind, s32 bank, s32 index, s32 flags) {
    state = 0;
    this->flags = flags;
    this->kind = kind;
    this->bank = bank;
    this->index = index;
    actor = NULL;
    token = 0;
    volume = 0x7F;
    previousVolume = 0x88888888;
    pan = 0x40;
    previousPan = 0x88888888;
    surround = 0;
    previousSurround = 0x88888888;
    base = 0;
    extra = 0;
    spatial = 0;
    fade = 0;
    fadeStep = 0;
    panExtra = 0;
    panSpatial = 0;
    surroundExtra = 0;
    surroundSpatial = 0;
    pitch = 0;
    previousPitch = 0x88888888;
    pitchStatic = 0;
    pitchMoving = 0;
    pitchVelocity = 0;
    pitchSlide = 0;
    pitchTarget = 0;
    pitchDuration = 0;
    pitchRemaining = 0;
    pitchLimit = 0x3F00;
    age = 0;
    delay = 0;
    refresh = 0;
    studio = 0;
    reverb = -1.0f;
    position = NULL;
    switch (this->kind) {
    case 0:
        state = -1;
        update_random_flip_flag();
        break;
    }
    return 0;
}
#pragma pop

#pragma pop

SoundRequestVoice::~SoundRequestVoice() {
    state = 0;
}
SoundRequestVoice::SoundRequestVoice() {
    owner = NULL;
    state = 0;
}
s32 SoundControlState::get_field_308() { return ms; }
