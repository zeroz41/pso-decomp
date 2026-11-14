#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/system/vector.h"
#include "pso/object/trap/TOTrapAncient01.h"

extern "C" {

s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);

s8 sound_mode_value = 1;
s32 last_sound_effect_slot = -1;

void TObjPlayer::play_effect_if_v2(s32 arg0) {
    if (TObjEneDD::check_v2_mode() != 0) {
        update_technique_slot__10TTecRaFoieFl(last_sound_effect_slot, arg0, 0);
    }
}

}

struct Vec_8022675C { f32 x, y, z; };

struct SndEnt_8022675C {
    s32 flags;
    s32 id;
    Vec_8022675C *src;
    Vec_8022675C pos;
    s16 prio;
    s16 x1a;
    s32 x1c;
    u8 pad[8];
};

void set_music_streams_volume(s32);
extern s32 lbl_805D627C;
extern s32 lbl_805D6280;
extern int lbl_805D6284;
extern s32 music_stream_base_gain;
extern s32 music_stream_gain;
extern "C" {
void update_music_stream_gain(s32 user);
void TLobby__sub_8022614C(s32 arg0);
extern s32 lbl_805D6294;
extern int lobby_layout_offset_c;
extern s32 lbl_805D6290;
extern s32 lobby_layout_start_position;

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
u8 *get_global_state__23TAdSinglePlyChrSelectGCFv();
s32 OSSetSoundMode(int);
extern SndEnt_8022675C lbl_805145F0[];
extern const u32 lbl_805DC748;
extern s32 lbl_805D62B0;
int release_sound_with_fade(void *p);
void stop_sound_request(s32 idx);
u32 OSGetSoundMode();
int TLobby__sub_80227D38(void);
void TLobby__sub_8022644C(void);
void set_menu_index_main__6TLobbyFPUc(void);
extern s32 lbl_805D629C;
extern s32 lbl_805D62A0;
extern s32 lbl_805D62A8;
extern s32 lbl_805D62AC;
int TLobby__sub_80226308(void);
void TTecRaFoie__sub_80226254(void);
s32 set_sound_slot_pitch();

int TLobby::get_lobby_data() {  return lbl_805D6280; }

void TLobby__sub_8022614C(s32 arg0) {
    set_menu_index_main__6TLobbyFPUc();
    lbl_805D6294 = arg0;
    lbl_805D629C = lbl_805D6290 + lbl_805D6294 + lobby_layout_offset_c;
    lbl_805D62A0 = lbl_805D6290 + lobby_layout_offset_c;
    lbl_805D62A8 = (s32)(2.3622048f * (f32)arg0);
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

void TTecRaFoie::update_technique_slot(s32 arg0) {
    if (((s32) lbl_805D62B0 != 0) && (arg0 >= 0) && (arg0 < 0x28)) {
        set_sound_slot_pitch();
    }
}

void stop_sound_request(s32 idx) {
    if (lbl_805D62B0 != 0 && idx >= 0 && idx < 0x28) {
        release_sound_with_fade((void *)idx);
        lbl_805145F0[idx].flags &= lbl_805DC748;
        lbl_805145F0[idx].prio = 0;
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
        p = get_global_state__23TAdSinglePlyChrSelectGCFv();
        if (p != NULL && p != NULL && *(s16 *)((s8 *)p + 0xE) != 0) {
            sound_mode_value = 2;
            TLobby::set_mode(2);
        }
    }
    return sound_mode_value;
}

void TLobby::set_sound_output_mode(s32 arg0) {
    s32 var_r30;
    u8 *temp_r3;
    temp_r3 = get_global_state__23TAdSinglePlyChrSelectGCFv();
    if (temp_r3 != NULL) {
        *(s16 *)((s8 *)temp_r3 + 0xE) = 0;
    }
    switch (arg0) {
    case 0:
        var_r30 = 1;
        OSSetSoundMode(1);
        break;
    case 2:
        OSSetSoundMode(1);
        if (temp_r3 != NULL) {
            *(s16 *)((s8 *)temp_r3 + 0xE) = 1;
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
        lbl_805145F0[i].prio = 0;
        lbl_805145F0[i].src = 0;
    }
}
}


extern "C" {
s32 check_sound_admission_range(const Vec *pos);
s32 fn_802264B8(s32 slot, s32) {
    s32 r;
    if (lbl_805145F0[slot].flags & 0x2000) {
        r = 0;
    } else {
        r = check_sound_admission_range((const Vec *)lbl_805145F0[slot].src);
    }
    if (r == -0x100) {
        lbl_805145F0[slot].flags |= 0x100;
        return 0;
    }
    lbl_805145F0[slot].flags &= ~0x100;
    return 1;
}

}



extern "C" {
SndEnt_8022675C lbl_805145F0[40];
u8 lbl_80514C30[0x20];
f32 lbl_80514C50[4];
s32 play_sound_effect(s32 id, Vec_8022675C *src, s32 a2, s32 flags);

s32 TOTrapAncient01::check_trigger_flag(s32 arg0, s32 arg1) {
    s32 var_r3;

    if (arg1 & 0x2000) {
        var_r3 = 0;
    } else {
        var_r3 = check_sound_admission_range((const Vec *)arg0);
    }
    if (var_r3 == -0x100) {
        return 0;
    }
    return 1;
}
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags) {
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
        if (src != 0) {
            ok = TOTrapAncient01::check_trigger_flag(src, lbl_805145F0[idx].flags);
        } else {
            ok = fn_802264B8(idx, 1);
        }
        last_sound_effect_slot = idx;
        if (ok != 0) {
            e = &lbl_805145F0[idx];
            e->src = (Vec_8022675C *)src;
            e->x1a = a3;
            e->prio = 5;
            idx = normalize_sound_request(id, e->x1c, (s32)e->src, e->x1a, flags);
        }
        return idx;
    }
    if (TOTrapAncient01::check_trigger_flag(src, flags) != 0) {
        idx = normalize_sound_request(id, a1, src, a3, flags);
        last_sound_effect_slot = idx;
        if (idx >= 0) {
            lbl_805145F0[idx].flags &= lbl_805DC748;
            if (flags & 1) {
                lbl_805145F0[idx].flags |= 0x2000;
            }
            lbl_805145F0[idx].src = (Vec_8022675C *)src;
            lbl_805145F0[idx].x1a = a3;
            lbl_805145F0[idx].id = id;
            lbl_805145F0[idx].x1c = a1;
            lbl_805145F0[idx].prio = 5;
            lbl_805145F0[idx].flags |= 0x1600;
        } else {
            return -1;
        }
    }
    return idx;
}
s32 play_sound_effect(s32 id, Vec_8022675C *src, s32 a2, s32 flags) {
    s32 i;
    s32 idx;
    Vec_8022675C *pos;
    last_sound_effect_slot = -1;
    if (lbl_805D62B0 == 0) {
        return -1;
    }
    if (id == 0xF0000) {
        return -1;
    }
    idx = -1;
    for (i = 0; i < 40; i++) {
        if ((lbl_805145F0[i].flags & 0x400) && id == lbl_805145F0[i].id && lbl_805145F0[i].prio >= 0x94) {
            return -1;
        }
    }
    if (idx < 0) {
        idx = play_packed_sound_once(id, (s32)src, a2, flags);
    }
    if (idx >= 0) {
        if (src != NULL) {
            pos = &lbl_805145F0[idx].pos;
            VecCopy((Vec *)pos, (const Vec *)src);
            ((void (*)(s32, Vec_8022675C *))TLobby__sub_80227AF8)(idx, pos);
        }
        lbl_805145F0[idx].flags &= lbl_805DC748;
        if (flags & 1) {
            lbl_805145F0[idx].flags |= 0x2000;
        }
        lbl_805145F0[idx].src = src;
        lbl_805145F0[idx].prio = 0x96;
        lbl_805145F0[idx].x1a = a2;
        lbl_805145F0[idx].id = id;
        lbl_805145F0[idx].x1c = 0;
        if (fn_802264B8(idx, 0) == 1) {
            last_sound_effect_slot = idx;
            lbl_805145F0[idx].flags |= 0x600;
            return idx;
        }
    }
    return -1;
}

}
