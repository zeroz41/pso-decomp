#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/network/client_id.h"
#include "pso/object/trap/TOTrapAncient01.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/PlayerSlots.h"


s8 sound_mode_value = 1;
s32 last_sound_effect_slot = -1;

void TObjPlayer::play_effect_if_v2(s32 pitch) {
    if (TObjEneDD::check_v2_mode() != 0) {
        set_sound_pitch_request(last_sound_effect_slot, pitch, 0);
    }
}


struct SndEnt_8022675C {
    s32 flags;
    s32 id;
    const Vec *src;
    Vec pos;
    s16 timer; // frames left: 0x96 when played, 5 to fade out; the same id is not replayed while >= 0x94
    s16 volume;
    const void *actor;
    u8 pad[8];
};

void set_music_streams_volume(s32);
s8 lbl_805D6278;
s8 lbl_805D6279;
s32 lbl_805D627C;
s32 lbl_805D6280;
int lbl_805D6284;
s32 music_stream_base_gain;
s32 music_stream_gain;
s32 lbl_805D6290;
s32 lbl_805D6294;
int lobby_layout_offset_c;
s32 lbl_805D629C;
s32 lbl_805D62A0;
s32 lobby_layout_start_position;
s32 lbl_805D62A8;
s32 lbl_805D62AC;
s32 lbl_805D62B0;
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
void update_music_stream_gain(s32 user);
void TLobby__sub_8022614C(s32 gain);

void TLobby::set_and_notify(int a0) { lbl_805D6284 = a0; update_music_stream_gain(lbl_805D6280); }

void TLobby::reset_global() { lobby_layout_offset_c = 0; TLobby__sub_8022614C(lbl_805D6294); }

void TLobby::close_option_window() { lbl_805D6284 = 0; update_music_stream_gain(lbl_805D6280); }

void TLobby::init_layout_positions() {
    lbl_805D627C = -0x50;
    lobby_layout_start_position = -0x5A;
    if (TLobby::init_sound_mode() == 1) {
        lbl_805D627C -= 0x32;
    }
    lbl_805D6290 = -0xA;
    TLobby::close_option_window();
    TLobby::reset_global();
}
s32 OSSetSoundMode(int);
void stop_sound_request(s32 idx);
u32 OSGetSoundMode();
int TLobby__sub_80227D38(void);
void TLobby__sub_8022644C(void);
void set_menu_index_main__6TLobbyFPUc(void);
int TLobby__sub_80226308(void);
void TTecRaFoie__sub_80226254(void);
void set_sound_slot_pitch(s32 slot, s32 pitch, s32 duration);

int TLobby::get_lobby_data() {  return lbl_805D6280; }

void TLobby__sub_8022614C(s32 gain) {
    set_menu_index_main__6TLobbyFPUc();
    lbl_805D6294 = gain;
    lbl_805D629C = lbl_805D6290 + lbl_805D6294 + lobby_layout_offset_c;
    lbl_805D62A0 = lbl_805D6290 + lobby_layout_offset_c;
    lbl_805D62A8 = (s32)(2.3622048f * (f32)gain);
    lbl_805D62AC = lobby_layout_start_position + lbl_805D62A8;
    set_cue_stream_gain(lbl_805D62AC);
}

void update_music_stream_gain(s32 user) {
  unsigned int new_var;
  s32 total;
  new_var = lbl_805D627C;
  total = user + (*(s32 *)&lbl_805D6284);
  if (lbl_805D627C && lbl_805D627C)
  {
  }
  total = new_var + total;
  lbl_805D6280 = user;
  music_stream_base_gain = total;
  music_stream_gain = (s32) (0.42333332f * ((f32) total));
  set_music_streams_volume(total);
}

void TTecRaFoie__sub_80226254(void) {  }

void set_sound_pitch_request(s32 slot, s32 pitch, s32 duration) {
    if (((s32) lbl_805D62B0 != 0) && (slot >= 0) && (slot < 0x28)) {
        set_sound_slot_pitch(slot, pitch, duration);
    }
}
}
extern SndEnt_8022675C lbl_805145F0[];
void release_sound_with_fade(s32 slot);
// Defined here: CodeWarrior emits it in definition order, and its .sdata2 slot
// (0x805DC748) lies between update_music_stream_gain's literal and the 0.0 below.
const u32 lbl_805DC748 = 1;

void stop_sound_request(s32 idx) {
    if (lbl_805D62B0 != 0 && idx >= 0 && idx < 0x28) {
        release_sound_with_fade(idx);
        lbl_805145F0[idx].flags &= lbl_805DC748;
        lbl_805145F0[idx].timer = 0;
        lbl_805145F0[idx].src = 0;
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

void TLobby::set_sound_output_mode(s32 arg0) {
    s32 var_r30;
    u8 *global_state;
    global_state = TAdSinglePlyChrSelectGC::get_global_state();
    if (global_state != NULL) {
        *(s16 *)((s8 *)global_state + 0xE) = 0;
    }
    switch (arg0) {
    case 0:
        var_r30 = 1;
        OSSetSoundMode(1);
        break;
    case 2:
        OSSetSoundMode(1);
        if (global_state != NULL) {
            *(s16 *)((s8 *)global_state + 0xE) = 1;
        }
        var_r30 = 2;
        break;
    case 1:
        OSSetSoundMode(0);
        var_r30 = 0;
        break;
    }
    TLobby::set_mode(var_r30);
}
void TLobby__sub_8022644C(void) {
    s32 i;
    if (lbl_805D62B0 != 0) {
        TLobby__sub_80227D38();
    }
    for (i = 0; i < 0x28; i++) {
        lbl_805145F0[i].flags &= lbl_805DC748;
        lbl_805145F0[i].timer = 0;
        lbl_805145F0[i].src = 0;
    }
}
s32 check_sound_admission_range(const Vec *pos);
extern "C" {
s32 fn_802264B8(s32 slot, s32) {
    s32 r;
    if (lbl_805145F0[slot].flags & 0x2000) {
        r = 0;
    } else {
        r = check_sound_admission_range(lbl_805145F0[slot].src);
    }
    if (r == -0x100) {
        lbl_805145F0[slot].flags |= 0x100;
        return 0;
    }
    lbl_805145F0[slot].flags &= ~0x100;
    return 1;
}
}

SndEnt_8022675C lbl_805145F0[40];
u8 lbl_80514C30[0x20];
f32 lbl_80514C50[4];

s32 check_sound_admission(const Vec *position, s32 flags) {
    s32 var_r3;

    if (flags & 0x2000) {
        var_r3 = 0;
    } else {
        var_r3 = check_sound_admission_range(position);
    }
    if (var_r3 == -0x100) {
        return 0;
    }
    return 1;
}
s32 play_persistent_sound(s32 id, const void *actor, const Vec *position, s32 volume, s32 flags) {
    s32 idx = -1;
    s32 i;
    s32 ok;
    SndEnt_8022675C *e;

    last_sound_effect_slot = -1;
    if (lbl_805D62B0 == 0) {
        return -1;
    }
    if (id == 0xF0000) {
        return -1;
    }
    for (i = 0; i < 40; i++) {
        if ((lbl_805145F0[i].flags & 0x400) && id == lbl_805145F0[i].id) {
            idx = i;
            break;
        }
    }
    if (idx >= 0) {
        if (position != NULL) {
            ok = check_sound_admission(position, lbl_805145F0[idx].flags);
        } else {
            ok = fn_802264B8(idx, 1);
        }
        last_sound_effect_slot = idx;
        if (ok != 0) {
            e = &lbl_805145F0[idx];
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
            lbl_805145F0[idx].flags &= lbl_805DC748;
            if (flags & 1) {
                lbl_805145F0[idx].flags |= 0x2000;
            }
            lbl_805145F0[idx].src = position;
            lbl_805145F0[idx].volume = volume;
            lbl_805145F0[idx].id = id;
            lbl_805145F0[idx].actor = actor;
            lbl_805145F0[idx].timer = 5;
            lbl_805145F0[idx].flags |= 0x1600;
        } else {
            return -1;
        }
    }
    return idx;
}
extern "C" {
s32 play_sound_effect(s32 id, const Vec *position, s32 volume, s32 flags) {
    s32 i;
    s32 idx;
    Vec *pos;
    last_sound_effect_slot = -1;
    if (lbl_805D62B0 == 0) {
        return -1;
    }
    if (id == 0xF0000) {
        return -1;
    }
    idx = -1;
    for (i = 0; i < 40; i++) {
        if ((lbl_805145F0[i].flags & 0x400) && id == lbl_805145F0[i].id && lbl_805145F0[i].timer >= 0x94) {
            return -1;
        }
    }
    if (idx < 0) {
        idx = play_packed_sound_once(id, (saddr)position, volume, flags);
    }
    if (idx >= 0) {
        if (position != NULL) {
            pos = &lbl_805145F0[idx].pos;
            VecCopy(pos, position);
            ((void (*)(s32, Vec *))TLobby__sub_80227AF8)(idx, pos);
        }
        lbl_805145F0[idx].flags &= lbl_805DC748;
        if (flags & 1) {
            lbl_805145F0[idx].flags |= 0x2000;
        }
        lbl_805145F0[idx].src = position;
        lbl_805145F0[idx].timer = 0x96;
        lbl_805145F0[idx].volume = volume;
        lbl_805145F0[idx].id = id;
        lbl_805145F0[idx].actor = NULL;
        if (fn_802264B8(idx, 0) == 1) {
            last_sound_effect_slot = idx;
            lbl_805145F0[idx].flags |= 0x600;
            return idx;
        }
    }
    return -1;
}
s32 TLobby__sub_8023F880(s32 arg0);

void TLobby::update_lobby_subsystems() { TLobby__sub_8022644C(); stop_cue_stream(); }

// Dead-stripped from the DOL: no code of it survives. This part of the .sdata2 pool opens
// with 0.0 (0x805DC74C) ahead of check_sound_admission_range's 90000/40/260/127
// although that function loads 0.0 last, so a function before it used 0.0 first.
// Minimal body: it clears the sound listener position (lbl_80514C50) the way
// update_sound_request_slots does when there is neither a player nor a camera.
// Name inferred from that role.
void clear_sound_listener_position(void) {
    lbl_80514C50[2] = 0.0f;
    lbl_80514C50[1] = 0.0f;
    lbl_80514C50[0] = 0.0f;
}

f32 xz_distance_squared(const Vec *a, const Vec *b);
}
s32 check_sound_admission_range(const Vec *pos) {
    if (pos == NULL) {
        return 0;
    }
    if (camera_ctrl_instance == NULL) {
        return 0;
    }
    f32 dist_sq = xz_distance_squared(pos, (const Vec *)lbl_80514C50);
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
    SndEnt_8022675C *e;
    s16 *t;
    if (lbl_805D62B0 != 0) {
        p = (uaddr)get_player_by_client_id((local_client_id));
        if (p != 0U) {
            VecCopy((Vec *)lbl_80514C50, (const Vec *)(p + 0x38));
        } else if (camera_ctrl_instance != NULL) {
            VecCopy((Vec *)lbl_80514C50, &camera_ctrl_instance->pos);
        } else {
            lbl_80514C50[2] = 0.0f;
            lbl_80514C50[1] = 0.0f;
            lbl_80514C50[0] = 0.0f;
        }
        if (lbl_805D6279 == 0) {
            for (i = 0; i < 0x28; i++) {
                r = TLobby__sub_8023F880(i);
                if (r == -1 || r == 1) {
                    e = &lbl_805145F0[i];
                    t = &e->timer;
                    e->flags &= ~0x200;
                    if (*t > 0) {
                        (*t)--;
                        if ((e->flags & 0x1000) && e->src != NULL && fn_802264B8(i, 1) == 0) {
                            *t = 0;
                            stop_sound_request(i);
                            e->flags &= ~0x400;
                        }
                    } else {
                        stop_sound_request(i);
                        e->flags &= ~0x400;
                    }
                } else {
                    e = &lbl_805145F0[i];
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

int TLobby__sub_80226B64(void) { TLobby::update_lobby_subsystems(); TLobby::init_layout_positions(); TLobby__sub_80226308(); lbl_805D62B4 = 0; lbl_805D62B8 = 0; lbl_805D62B0 = 1; return 0; }

extern "C" {

s32 TLobby__sub_80226BA4(void) {
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
    lbl_805D62B0 = 1;
    lbl_805D6279 = 0;
    lbl_805D62B8 = 0;
    lbl_80514C30[0] = 0;
    lbl_805D6280 = 0;
    lbl_805D62A8 = 0;
    lbl_805D6294 = 0;
    TLobby::init_layout_positions();
    for (i = 0; i < 40; i++) {
        lbl_805145F0[i].flags = 1;
    }
    return 1;
}
}
