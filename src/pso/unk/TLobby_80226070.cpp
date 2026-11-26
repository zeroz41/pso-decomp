#include "pso/system/SoundEffect.h"
#include "pso/unk/TLobby_8023F734.h"
#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/network/TLobby.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/unk/TLobby_80227AA0.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/unk/TLobby_80226C3C.h"
#include "pso/network/client_id.h"
#include "pso/object/trap/TOTrapAncient01.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/PlayerSlots.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/os/OSRtc.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/render/NinjaUtil.h"


s8 sound_mode_value = 1;
s32 last_sound_effect_slot = -1;

void TObjPlayer::play_effect_if_v2(s32 pitch) {
    if (TObjEneDD::check_v2_mode() != 0) {
        set_sound_pitch_request(last_sound_effect_slot, pitch, 0);
    }
}


struct SetSoundPitchRequestSndEnt {
    s32 flags;
    s32 id;
    const Vec *src;
    Vec pos;
    s16 timer; // frames left: 0x96 when played, 5 to fade out; the same id is not replayed while >= 0x94
    s16 volume;
    const void *actor;
    u8 pad[8];
};

s8 lbl_805D6278;
s8 lbl_805D6279;
s32 music_gain_offset;
s32 music_user_gain;
int music_gain_adjust;
s32 music_stream_base_gain;
s32 music_stream_gain;
s32 lbl_805D6290;
s32 cue_stream_user_gain;
int lobby_layout_offset_c;
s32 lbl_805D629C;
s32 lbl_805D62A0;
s32 lobby_layout_start_position;
s32 cue_stream_scaled_gain;
s32 cue_stream_gain;
s32 sound_requests_enabled;
int lbl_805D62B4;
int lbl_805D62B8;
s32 lbl_805D62BC;
s32 lbl_805D62C0;
s32 lbl_805D62C4;
s32 lbl_805D62C8;
s16 lbl_805D62CC;
s8 lbl_805D62CE;
s8 lbl_805D62CF;
s8 lbl_805D62D0;
s8 lbl_805D62D1;
extern "C" {

void TLobby::set_and_notify(int a0) { music_gain_adjust = a0; update_music_stream_gain(music_user_gain); }

void TLobby::reset_global() { lobby_layout_offset_c = 0; set_cue_stream_user_gain(cue_stream_user_gain); }

void TLobby::close_option_window() { music_gain_adjust = 0; update_music_stream_gain(music_user_gain); }

void TLobby::init_layout_positions() {
    music_gain_offset = -0x50;
    lobby_layout_start_position = -0x5A;
    if (TLobby::init_sound_mode() == 1) {
        music_gain_offset -= 0x32;
    }
    lbl_805D6290 = -0xA;
    TLobby::close_option_window();
    TLobby::reset_global();
}
}

int TLobby::get_lobby_data() {  return music_user_gain; }
void set_cue_stream_user_gain(s32 gain) {
    TLobby::set_menu_index_main(gain);
    cue_stream_user_gain = gain;
    lbl_805D629C = lbl_805D6290 + cue_stream_user_gain + lobby_layout_offset_c;
    lbl_805D62A0 = lbl_805D6290 + lobby_layout_offset_c;
    cue_stream_scaled_gain = (s32)(2.3622048f * (f32)gain);
    cue_stream_gain = lobby_layout_start_position + cue_stream_scaled_gain;
    set_cue_stream_gain(cue_stream_gain);
}

void update_music_stream_gain(s32 user) {
  unsigned int offset;
  s32 total;
  offset = music_gain_offset;
  total = user + (music_gain_adjust);
  if (music_gain_offset && music_gain_offset)
  {
  }
  total = offset + total;
  music_user_gain = user;
  music_stream_base_gain = total;
  music_stream_gain = (s32) (0.42333332f * ((f32) total));
  set_music_streams_volume(total);
}
void TTecRaFoie__sub_80226254(void) {  }

void set_sound_pitch_request(s32 slot, s32 pitch, s32 duration) {
    if ((sound_requests_enabled != 0) && (slot >= 0) && (slot < 0x28)) {
        set_sound_slot_pitch(slot, pitch, duration);
    }
}
extern SetSoundPitchRequestSndEnt sound_pitch_requests[];
// Defined here: CodeWarrior emits it in definition order.
const u32 lbl_805DC748 = 1;

void stop_sound_request(s32 idx) {
    if (sound_requests_enabled != 0 && idx >= 0 && idx < 0x28) {
        release_sound_with_fade(idx);
        sound_pitch_requests[idx].flags &= lbl_805DC748;
        sound_pitch_requests[idx].timer = 0;
        sound_pitch_requests[idx].src = 0;
    }
}

int TLobby__sub_80226308(void) { return TLobby::init_sound_mode(); }

int TLobby::init_sound_mode() {
    u8 *p;
    if (OSGetSoundMode() == 0U) {
        sound_mode_value = 1;
        TLobby::set_mode(0);
    } else {
        TLobby::set_mode(1);
        sound_mode_value = 0;
        p = TAdSinglePlyChrSelectGC::get_global_state();
        if (p != NULL && p != NULL && *(s16 *)((s8 *)p + 0xE) != 0) {
            sound_mode_value = 2;
            TLobby::set_mode(2);
        }
    }
    return sound_mode_value;
}

void TLobby::set_sound_output_mode(s32 mode) {
    s32 mode_id;
    u8 *global_state;
    global_state = TAdSinglePlyChrSelectGC::get_global_state();
    if (global_state != NULL) {
        *(s16 *)((s8 *)global_state + 0xE) = 0;
    }
    switch (mode) {
    case 0:
        mode_id = 1;
        OSSetSoundMode(1);
        break;
    case 2:
        OSSetSoundMode(1);
        if (global_state != NULL) {
            *(s16 *)((s8 *)global_state + 0xE) = 1;
        }
        mode_id = 2;
        break;
    case 1:
        OSSetSoundMode(0);
        mode_id = 0;
        break;
    }
    TLobby::set_mode(mode_id);
}
void reset_sound_pitch_requests(void) {
    s32 i;
    if (sound_requests_enabled != 0) {
        TLobby__sub_80227D38();
    }
    for (i = 0; i < 0x28; i++) {
        sound_pitch_requests[i].flags &= lbl_805DC748;
        sound_pitch_requests[i].timer = 0;
        sound_pitch_requests[i].src = 0;
    }
}
s32 check_sound_admission_range(const Vec *pos);
s32 check_sound_pitch_request_range(s32 slot, s32) {
    s32 r;
    if (sound_pitch_requests[slot].flags & 0x2000) {
        r = 0;
    } else {
        r = check_sound_admission_range(sound_pitch_requests[slot].src);
    }
    if (r == -0x100) {
        sound_pitch_requests[slot].flags |= 0x100;
        return 0;
    }
    sound_pitch_requests[slot].flags &= ~0x100;
    return 1;
}

SetSoundPitchRequestSndEnt sound_pitch_requests[40];
u8 lbl_80514C30[0x20];
f32 sound_listener_position[4];

s32 check_sound_admission(const Vec *position, s32 flags) {
    s32 range;

    if (flags & 0x2000) {
        range = 0;
    } else {
        range = check_sound_admission_range(position);
    }
    if (range == -0x100) {
        return 0;
    }
    return 1;
}
s32 play_persistent_sound(s32 id, const void *actor, const Vec *position, s32 volume, s32 flags) {
    s32 idx = -1;
    s32 i;
    s32 ok;
    SetSoundPitchRequestSndEnt *e;

    last_sound_effect_slot = -1;
    if (sound_requests_enabled == 0) {
        return -1;
    }
    if (id == 0xF0000) {
        return -1;
    }
    for (i = 0; i < 40; i++) {
        if ((sound_pitch_requests[i].flags & 0x400) && id == sound_pitch_requests[i].id) {
            idx = i;
            break;
        }
    }
    if (idx >= 0) {
        if (position != NULL) {
            ok = check_sound_admission(position, sound_pitch_requests[idx].flags);
        } else {
            ok = check_sound_pitch_request_range(idx, 1);
        }
        last_sound_effect_slot = idx;
        if (ok != 0) {
            e = &sound_pitch_requests[idx];
            e->src = position;
            e->volume = volume;
            e->timer = 5;
            idx = normalize_sound_request(id, e->actor, e->src, e->volume, flags);
        }
        return idx;
    }
    if (check_sound_admission(position, flags) != 0) {
        idx = normalize_sound_request(id, actor, position, volume, flags);
        last_sound_effect_slot = idx;
        if (idx >= 0) {
            sound_pitch_requests[idx].flags &= lbl_805DC748;
            if (flags & 1) {
                sound_pitch_requests[idx].flags |= 0x2000;
            }
            sound_pitch_requests[idx].src = position;
            sound_pitch_requests[idx].volume = volume;
            sound_pitch_requests[idx].id = id;
            sound_pitch_requests[idx].actor = actor;
            sound_pitch_requests[idx].timer = 5;
            sound_pitch_requests[idx].flags |= 0x1600;
        } else {
            return -1;
        }
    }
    return idx;
}
s32 play_sound_effect(s32 id, const Vec *position, s32 volume, s32 flags) {
    s32 i;
    s32 idx;
    Vec *pos;
    last_sound_effect_slot = -1;
    if (sound_requests_enabled == 0) {
        return -1;
    }
    if (id == 0xF0000) {
        return -1;
    }
    idx = -1;
    for (i = 0; i < 40; i++) {
        if ((sound_pitch_requests[i].flags & 0x400) && id == sound_pitch_requests[i].id && sound_pitch_requests[i].timer >= 0x94) {
            return -1;
        }
    }
    if (idx < 0) {
        idx = play_packed_sound_once(id, (saddr)position, volume, flags);
    }
    if (idx >= 0) {
        if (position != NULL) {
            pos = &sound_pitch_requests[idx].pos;
            VecCopy(pos, position);
            set_sound_request_position(idx, pos);
        }
        sound_pitch_requests[idx].flags &= lbl_805DC748;
        if (flags & 1) {
            sound_pitch_requests[idx].flags |= 0x2000;
        }
        sound_pitch_requests[idx].src = position;
        sound_pitch_requests[idx].timer = 0x96;
        sound_pitch_requests[idx].volume = volume;
        sound_pitch_requests[idx].id = id;
        sound_pitch_requests[idx].actor = NULL;
        if (check_sound_pitch_request_range(idx, 0) == 1) {
            last_sound_effect_slot = idx;
            sound_pitch_requests[idx].flags |= 0x600;
            return idx;
        }
    }
    return -1;
}

void TLobby::update_lobby_subsystems() { reset_sound_pitch_requests(); stop_cue_stream(); }
// Dead-stripped from the DOL: no code of it survives. Minimal body: it clears the sound listener position the way
// update_sound_request_slots does when there is neither a player nor a camera.
// Name inferred from that role.
void clear_sound_listener_position(void) {
    sound_listener_position[2] = 0.0f;
    sound_listener_position[1] = 0.0f;
    sound_listener_position[0] = 0.0f;
}
s32 check_sound_admission_range(const Vec *pos) {
    if (pos == NULL) {
        return 0;
    }
    if (camera_ctrl_instance == NULL) {
        return 0;
    }
    f32 dist_sq = xz_distance_squared(pos, (const Vec *)sound_listener_position);
    if (dist_sq < 90000.0f) {
        f32 t = (newton_sqrtf(dist_sq) - 40.0f) / 260.0f;
        return (s32)-(127.0f * (t > 0.0f ? t : 0.0f));
    }
    return -0x100;
}

void update_sound_request_slots(void) {
    s32 i;
    s32 r;
    uaddr p;
    SetSoundPitchRequestSndEnt *e;
    s16 *t;
    if (sound_requests_enabled != 0) {
        p = (uaddr)get_player_by_client_id((local_client_id));
        if (p != 0U) {
            VecCopy((Vec *)sound_listener_position, (const Vec *)(p + 0x38));
        } else if (camera_ctrl_instance != NULL) {
            VecCopy((Vec *)sound_listener_position, &camera_ctrl_instance->pos);
        } else {
            sound_listener_position[2] = 0.0f;
            sound_listener_position[1] = 0.0f;
            sound_listener_position[0] = 0.0f;
        }
        if (lbl_805D6279 == 0) {
            for (i = 0; i < 0x28; i++) {
                r = TLobby__sub_8023F880(i);
                if (r == -1 || r == 1) {
                    e = &sound_pitch_requests[i];
                    t = &e->timer;
                    e->flags &= ~0x200;
                    if (*t > 0) {
                        (*t)--;
                        if ((e->flags & 0x1000) && e->src != NULL && check_sound_pitch_request_range(i, 1) == 0) {
                            *t = 0;
                            stop_sound_request(i);
                            e->flags &= ~0x400;
                        }
                    } else {
                        stop_sound_request(i);
                        e->flags &= ~0x400;
                    }
                } else {
                    e = &sound_pitch_requests[i];
                    if (!(e->flags & 0x200)) {
                        e->flags &= ~0x400;
                    } else {
                        e->timer--;
                        if (e->timer <= 0) {
                            e->flags &= ~0x600;
                            stop_sound_request(i);
                        }
                    }
                }
            }
        }
        update_music_fade();
    }
}

int TLobby__sub_80226B64(s32) { TLobby::update_lobby_subsystems(); TLobby::init_layout_positions(); TLobby__sub_80226308(); lbl_805D62B4 = 0; lbl_805D62B8 = 0; sound_requests_enabled = 1; return 0; }

s32 reset_sound_request_state(void) {
    s32 i;
    lbl_805D6278 = 0;
    lbl_805D62C4 = 0;
    lbl_805D62CC = 0;
    lbl_805D62C8 = 0;
    lbl_805D62C0 = 0;
    lbl_805D62BC = 0;
    lbl_805D62D0 = 0;
    lbl_805D62CE = 0;
    lbl_805D62CF = 0;
    lbl_805D62D1 = 0;
    sound_requests_enabled = 1;
    lbl_805D6279 = 0;
    lbl_805D62B8 = 0;
    lbl_80514C30[0] = 0;
    music_user_gain = 0;
    cue_stream_scaled_gain = 0;
    cue_stream_user_gain = 0;
    TLobby::init_layout_positions();
    for (i = 0; i < 40; i++) {
        sound_pitch_requests[i].flags = 1;
    }
    return 1;
}
