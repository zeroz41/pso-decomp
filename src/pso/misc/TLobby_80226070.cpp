#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TTecRaFoie.h"

struct Ent_80226294 { u32 flags; u8 pad4[4]; s32 f8; u8 padC[0xC]; s16 f18; u8 pad1a[0xE]; };

void set_music_streams_volume(s32);
extern s32 lbl_805D627C;
extern int lbl_805D6280;
extern int lbl_805D6284;
extern s32 music_stream_base_gain;
extern s32 music_stream_gain;
extern "C" {
void update_music_stream_gain(s32 user);
void TLobby__sub_8022614C(s32 arg0);
int init_sound_mode__6TLobbyFPv(void *);
extern int lbl_805D6294;
extern int lobby_layout_offset_c;
extern s32 lbl_805D6290;
extern s32 lobby_layout_start_position;

void TLobby::set_and_notify(int a0) { lbl_805D6284 = a0; update_music_stream_gain(lbl_805D6280); }

void TLobby::reset_global() { lobby_layout_offset_c = 0; TLobby__sub_8022614C(lbl_805D6294); }

void TLobby::close_option_window() { lbl_805D6284 = 0; update_music_stream_gain(lbl_805D6280); }

void TLobby::init_layout_positions() {
    lbl_805D627C = -0x50;
    lobby_layout_start_position = -0x5A;
    if (((int (*)(void))init_sound_mode__6TLobbyFPv)() == 1) {
        lbl_805D627C -= 0x32;
    }
    lbl_805D6290 = -0xA;
    TLobby::close_option_window();
    TLobby::reset_global();
}
u8 *get_global_state__23TAdSinglePlyChrSelectGCFv();
s32 OSSetSoundMode(int);
extern Ent_80226294 lbl_805145F0[];
extern u32 lbl_805DC748;
extern s32 lbl_805D62B0;
int release_sound_with_fade(void *p);
void stop_sound_request(s32 idx);
u32 OSGetSoundMode();
extern s8 sound_mode_value;
int TLobby__sub_80227D38(void);
void TLobby__sub_8022644C(void);
void set_cue_stream_gain(s32, s32);
void set_menu_index_main__6TLobbyFPUc(void);
extern s32 lbl_805D629C;
extern s32 lbl_805D62A0;
extern s32 lbl_805D62A8;
extern s32 lbl_805D62AC;
int TLobby__sub_80226308(void* p);
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
    set_cue_stream_gain(lbl_805D62AC, lbl_805D62A8);
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
        lbl_805145F0[idx].f18 = 0;
        lbl_805145F0[idx].f8 = 0;
    }
}

int TLobby__sub_80226308(void* p) { return init_sound_mode__6TLobbyFPv(p); }

int init_sound_mode__6TLobbyFPv(void *) {
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
        lbl_805145F0[i].f18 = 0;
        lbl_805145F0[i].f8 = 0;
    }
}
}
