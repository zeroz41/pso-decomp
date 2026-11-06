#include "types.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby.h"
#include "pso/system/TLoadCtrl.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

const u32 lbl_805DC748 = 1;

struct Ent_802269B4 {
    s32 flags;
    s32 f4;
    u32 f8;
    u8 pad[0x18 - 0xC];
    s16 timer;
    u8 pad2[0x28 - 0x1A];
};

struct Passage_80226FA0 { s16 first, repeat, count, transition, next; };

struct Program_80226FA0 { char archive[32]; s32 count, ntsc, pal; Passage_80226FA0 *modes[2]; };

extern "C" {
int TLobby__sub_80226308(void);
    extern int lbl_805D62B0;
    extern int lbl_805D62B4;
    extern int lbl_805D62B8;
int TLobby__sub_80226B64(void);
int set_and_notify__6TLobbyFi(void*);
void start_audio_stream_file(s32, char *);
void play_cue_stream_file(s32 arg0);
void TLobby__sub_803C94DC(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C9CB0(s32);
extern s32 lbl_805D62E4;
extern s32 music_fade_slot_index;
void TLobby__sub_802272B4(void);
void set_field_40_and_notify__6TLobbyFs(s32, s32);
void set_cue_stream_gain(s32 arg0);
void TLobby__sub_8022733C(void);
void *get_player_by_client_id(s32 i);
void stop_sound_request(s32 idx);
s32 fn_802264B8(int, int);
s32 TLobby__sub_8023F880(s32 arg0);
s32 TLobby__sub_803C5D00(void *);
s32 TLobby__sub_803C97B8(u8 *arg0);
}
void stop_audio_stream(u8 *arg0);
extern s32 lbl_804CB850[];
extern s32 lbl_805D6330;
extern s32 lbl_805D6300;
extern s32 music_target_id;
void set_dark_falz_music_request(s32 arg0);
void stop_cue_stream(void);
extern u8 *lobby_current_slot_entry;
void set_music_streams_volume(s32 arg0);
void update_music_fade(void);
extern Ent_802269B4 lbl_805145F0[];
extern f32 lbl_80514C50[];
extern u32 camera_ctrl_instance;
extern s32 local_client_id;
extern s8 lbl_805D6279;
void update_sound_request_slots(void);
void append_music_stream_segment(u8 *arg0, s32 arg1, s32 arg2);
extern s32 lbl_805D62E0;
extern s32 lbl_805D62F0;
extern s32 lbl_805D62F4;
extern Program_80226FA0 *lbl_805D6304;
extern s32 music_sequencer_passage_index;
extern s32 music_passage_index;
extern s32 lbl_805D6310;
extern s32 music_active_mode_index;
extern s32 music_sequencer_fade_state;
extern s32 music_sequencer_timer;
extern s16 lbl_805D6334;
void update_music_sequencer(void);
extern "C" {
void TLobby__sub_8022644C(void);

void TLobby::update_lobby_subsystems() { TLobby__sub_8022644C(); stop_cue_stream(); }

// Dead-stripped from the DOL: no code of it survives. The TU's .sdata2 pool opens
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
f32 newton_sqrtf(f32 x);

s32 check_sound_admission_range(const Vec *pos) {
    if (pos == NULL) {
        return 0;
    }
    if (camera_ctrl_instance == 0U) {
        return 0;
    }
    f32 dist_sq = xz_distance_squared(pos, (const Vec *)lbl_80514C50);
    if (dist_sq < 90000.0f) {
        f32 t = (newton_sqrtf(dist_sq) - 40.0f) / 260.0f;
        return (s32)-(127.0f * (t > 0.0f ? t : 0.0f));
    }
    return -0x100;
}
}

void update_sound_request_slots(void) {
    s32 i;
    s32 r;
    u32 p;
    Ent_802269B4 *e;
    s16 *t;
    if (lbl_805D62B0 != 0) {
        p = (u32)get_player_by_client_id((local_client_id));
        if (p != 0U) {
            VecCopy((Vec *)lbl_80514C50, (const Vec *)(p + 0x38));
        } else if (camera_ctrl_instance != 0U) {
            VecCopy((Vec *)lbl_80514C50, (const Vec *)(camera_ctrl_instance + 0x178));
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
                        if ((e->flags & 0x1000) && e->f8 != 0U && fn_802264B8(i, 1) == 0) {
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
extern s8 lbl_805D6278;
extern s32 lbl_805D6280;
extern s32 lbl_805D6294;
extern s32 lbl_805D62A8;
extern s32 lbl_805D62BC;
extern s32 lbl_805D62C0;
extern s32 lbl_805D62C4;
extern s32 lbl_805D62C8;
extern s16 lbl_805D62CC;
extern s8 lbl_805D62CE;
extern s8 lbl_805D62CF;
extern s8 lbl_805D62D0;
extern s8 lbl_805D62D1;
extern u8 lbl_80514C30[0x20];

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

extern "C" char lbl_80514D00[2][0x20];
u8 *TLobby::get_current_slot_entry() {
    if ((s32) lbl_805D62E4 == 1) {
        return (u8 *)lbl_80514D00[music_fade_slot_index];
    }
    return lobby_current_slot_entry;
}

int TLobby::set_and_notify_default() { return set_and_notify__6TLobbyFi((void*)(0)); }
int TLobby::send_neg30() { return set_and_notify__6TLobbyFi((void*)(-30)); }

void set_cue_stream_gain(s32 arg0) {
    s32 var_r4;
    var_r4 = arg0;
    if (var_r4 <= -0x140) {
        var_r4 = -0x3E7;
    }
    if ((u32) lbl_804CB850[2] != 0U) {
        set_field_40_and_notify__6TLobbyFs(lbl_804CB850[2], var_r4);
    }
}

void set_music_streams_volume(s32 arg0) {
    s32 var_r31;
    var_r31 = arg0;
    if (var_r31 <= -0x140) {
        var_r31 = -0x3E7;
    }
    if ((s32) lbl_805D6330 == 0) {
        set_field_40_and_notify__6TLobbyFs(lbl_804CB850[0], var_r31);
    }
    set_field_40_and_notify__6TLobbyFs(lbl_804CB850[1], var_r31);
}
extern "C" {

void TLobby::release_bgm_resource() {
    if ((s32) lbl_805D6330 != 0) {
        stop_audio_stream((u8 *)(*(s32 *)((s8 *)lbl_804CB850 + 4)));
        lbl_805D6330 = 0;
        TLobby::init_layout_positions();
    }
}

extern void *lbl_80514C60[];
extern const char *lbl_804CB85C[];
int get_music_base_gain(void);

void TLoadCtrl__sub_80226DA0(s32 index) {
    if (index < 0 || index >= 4) {
        return;
    }
    if (lbl_805D6330 == 0) {
        void *buf;
        TLoadCtrl::step();
        /* the original marks the stream busy while evaluating the call's arguments */
        ((void (*)(const char *, void *))TLobby::set_stream_state)(lbl_804CB85C[index],
                                                                    (lbl_805D6330 = 1, buf = lbl_80514C60[0]));
        ((TLobby *)lbl_804CB850[1])->adxt_start_mem_idx((u8 *)buf, 0);
        set_field_40_and_notify__6TLobbyFs(lbl_804CB850[1], get_music_base_gain());
        TLobby__sub_803C94DC((u8 *)lbl_804CB850[1], 0);
    }
}

void *lbl_80514C60[0x20];
__declspec(section ".data") s32 lbl_80514CE0[2];
__declspec(section ".data") s32 lbl_80514CE8[2];
__declspec(section ".data") s32 lbl_80514CF0[2];
__declspec(section ".data") f32 music_fade_volumes[2];
__declspec(section ".data") char lbl_80514D00[2][0x20];
u8 lbl_80514D40[0x218];
}

extern "C" {
void fn_8036A450(s32 arg0);
int TKeyBoardControl__sub_8000F828(void);
s32 TKeyBoardControl__sub_801E3E24(s32 id, const char *name, void *buf, s32 size);
void TLobby__sub_803C5D24(u8 *arg0);
char *strncpy(char *dst, const char *src, u32 n);
}
extern s16 lbl_805D371C;
extern Program_80226FA0 *lbl_804CBE74[];

void init_music_sequencer(s32 program) {
    fn_8036A450(program);
    lbl_805D371C = 0;
    TLobby::release_bgm_resource();
    lbl_805D6300 = program;
    lbl_805D6304 = lbl_804CBE74[program];
    lbl_805D6310 = 0;
    TLobby::stop_audio_streams();
    lbl_805D62E0 = 1;
    lbl_805D62E4 = 1;
    music_fade_slot_index = 0;
    music_sequencer_fade_state = 0;
    music_target_id = 0;
    music_active_mode_index = 0;
    lbl_80514CE8[0] = 0;
    lbl_80514CE8[1] = 0;
    music_sequencer_timer = 0;
    if (TKeyBoardControl__sub_8000F828() == 1) {
        lbl_805D62F4 = lbl_805D6304->pal;
    } else {
        lbl_805D62F4 = lbl_805D6304->ntsc;
    }
    lbl_80514CE0[0] = lbl_805D6304->modes[0][0].first;
    lbl_80514CE0[1] = lbl_80514CE0[0] + 1;
    music_sequencer_passage_index = 0;
    music_passage_index = 1;
    TKeyBoardControl__sub_801E3E24(190, lbl_805D6304->archive, lbl_80514D40, 128);
    append_music_stream_segment((u8 *)lbl_804CB850[0], 190, lbl_80514CE0[0]);
    append_music_stream_segment((u8 *)lbl_804CB850[0], 190, lbl_80514CE0[1]);
    TLobby__sub_803C5D24((u8 *)lbl_804CB850[0]);
    TLobby::close_option_window();
    strncpy(lbl_80514D00[0], lbl_805D6304->archive, 32);
    strncpy(lbl_80514D00[1], lbl_805D6304->archive, 32);
}
void update_music_sequencer(void) {
    Passage_80226FA0 *passage;
    Passage_80226FA0 *next;
    if (lbl_805D62E0 != 1) {
        return;
    }
    if (lbl_805D62E4 != 1) {
        return;
    }
    lbl_80514CE8[music_fade_slot_index]++;
    if (music_sequencer_timer > 0) {
        music_sequencer_timer--;
    } else if (music_sequencer_fade_state == 0 && music_target_id != music_active_mode_index) {
        music_sequencer_fade_state = 1;
        music_sequencer_timer = 600;
    }
    if (lbl_80514CE8[music_fade_slot_index] < lbl_805D62F4 && TLobby__sub_803C5D00((void *)((s32 *)&lbl_804CB850)[0]) != 1) {
        return;
    }
    passage = &lbl_805D6304->modes[music_active_mode_index][music_sequencer_passage_index];
    switch (music_sequencer_fade_state) {
    case 0:
        if (++music_passage_index >= passage->count) {
            music_sequencer_passage_index = passage->next;
            music_passage_index = 0;
            next = &lbl_805D6304->modes[music_active_mode_index][music_sequencer_passage_index];
            if (lbl_805D6310) {
                lbl_805D62F0 = next->repeat;
            } else {
                lbl_805D62F0 = next->first;
                lbl_805D6310 = 1;
            }
        } else {
            lbl_805D62F0 = passage->first + music_passage_index;
        }
        break;
    case 1:
        music_sequencer_passage_index = passage->next;
        music_passage_index = 0;
        music_active_mode_index = 1 - music_active_mode_index;
        music_sequencer_timer = 600;
        if (passage->transition >= 0) {
            lbl_805D62F0 = passage->transition;
            music_sequencer_fade_state = 2;
        } else {
            lbl_805D62F0 = lbl_805D6304->modes[music_target_id][music_sequencer_passage_index].first;
            lbl_805D6310 = 1;
            music_sequencer_fade_state = 0;
        }
        break;
    case 2:
        if (lbl_805D6310) {
            lbl_805D62F0 = passage->repeat;
        } else {
            lbl_805D62F0 = passage->first;
            lbl_805D6310 = 1;
        }
        music_sequencer_fade_state = 0;
        break;
    }
    lbl_80514CE0[music_fade_slot_index] = lbl_805D62F0;
    lbl_805D6334 = music_fade_slot_index;
    append_music_stream_segment((u8 *)((void *)((s32 *)&lbl_804CB850)[0]), 190, lbl_80514CE0[music_fade_slot_index]);
    music_fade_slot_index = 1 - music_fade_slot_index;
    lbl_80514CE8[music_fade_slot_index] = 0;
    lbl_80514CF0[music_fade_slot_index] = TLobby__sub_803C97B8((u8 *)((void *)((s32 *)&lbl_804CB850)[music_fade_slot_index]));
}

void set_dark_falz_music_request(s32 arg0) {
    if ((s32) lbl_805D6300 == 4) {
        music_target_id = arg0;
    }
}

void TLobby::set_target_id(s32 arg0) {
    if ((s32) lbl_805D6300 != 4) {
        music_target_id = arg0;
    }
}

void stop_cue_stream(void) {
    if ((u32) lbl_804CB850[2] != 0U) {
        stop_audio_stream((u8 *)(lbl_804CB850[2]));
    }
}

void play_cue_stream_file(s32 name) {
    if ((void *)lbl_804CB850[2] != NULL) {
        start_audio_stream_file(lbl_804CB850[2], (char *)name);
    }
}
void TLobby__sub_802272B4(void) {
    s32 temp_r3;
    TLobby__sub_803C94DC((u8 *)lbl_804CB850[music_fade_slot_index], 0);
    TLobby__sub_803C94DC((u8 *)lbl_804CB850[2], 0);
    temp_r3 = TLobby__sub_803C9CB0(lbl_804CB850[music_fade_slot_index]);
    if ((temp_r3 == 0) || (temp_r3 == 5)) {
        lbl_805D62E4 = 0;
        return;
    }
    lbl_805D62E4 = 1;
}
void TLobby__sub_8022733C(void) {
    TLobby__sub_803C94DC((u8 *)lbl_804CB850[music_fade_slot_index], 1);
    TLobby__sub_803C94DC((u8 *)lbl_804CB850[2], 1);
    lbl_805D62E4 = 2;
}

extern "C" {
u32 lbl_804CB838[6] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
}

struct RecoveredGlobal_8000F7FC_lbl_80515F48 {
    s32 value;
    u8 remaining[0x24];
};

extern "C" {
s32 VISetPreRetraceCallback(s32 *);
void TLobby__sub_80227AA8(s32);
void update_all_zones__14TObjBgmColCtrlFl(void);
extern char lbl_80514D00[][0x20];
extern s32 area_music_fade_frame_count;
extern f32 music_fade_full_scale;
void play_area_music(char *name);
void TWindowOptionCtrl__sub_802273B4(s32 arg0);
void TLobby__sub_803CA194(s32);
struct SndHooks {
    void *(*malloc)(u32 size);
    void (*free)(void *ptr);
};
void TLobby__sub_803CBE20(void *work, s32 size, s32 count);
void TLobby__sub_803CB74C(s32 *arg0);
void TLobby__sub_803CB858(s32 *arg0);
void TLobby__sub_803C94B8(void (*callback)(void), s32 arg1);
s32 adx_create_stream_player(s32 n, void *buffer, s32 size);
u32 ARInit(u32 *stack_index_addr, u32 num_entries);
void ARQInit(void);
void AIInit(u8 *stack);
s32 VISetPostRetraceCallback(int (*callback)(void *));
u32 Dolphin_ARAlloc(u32 length);
void sndSetHooks(SndHooks *hooks);
s32 sndInit(u8 voices, u8 music, u8 sfx, u8 studios, u32 flags, u32 aram_size);
int TLobby__sub_80227A70(void *p);
void TLobby__sub_80227A90(void);
void TLobby__sub_8022780C(void);
extern const SndHooks lbl_8044C858;
extern u32 lbl_804CB838[6];
void *lbl_805D62D8;
extern s32 lbl_805D62F8;
extern s32 lbl_805D62FC;
}
extern RecoveredGlobal_8000F7FC_lbl_80515F48 TLobby__sub_80227A6C;
s32 lbl_804CB850[3] = { 0, 0, 0 };
extern f32 music_fade_volumes[];
extern s32 music_fade_frames_remaining;
extern const f32 lbl_805DC764;
extern f32 music_fade_step;
u32 lbl_805D62DC;
extern u32 lbl_805D62EC;

void TLoadCtrl::step() { TLobby::stop_audio_streams(); stop_cue_stream(); }
typedef char RecoveredGlobal_8000F7FC_lbl_80515F48_size[sizeof(RecoveredGlobal_8000F7FC_lbl_80515F48) == 0x28 ? 1 : -1];

void TWindowOptionCtrl__sub_802273B4(s32 arg0) {
    if (lbl_805D62E0 != 0) {
        TLobby::stop_audio_streams();
        return;
    }
    music_fade_slot_index = 1 - music_fade_slot_index;
    music_fade_frames_remaining = arg0;
    music_fade_volumes[1 - music_fade_slot_index] = lbl_805DC764;
    music_fade_step = music_fade_full_scale / (f32)arg0;
}

void TLobby::stop_audio_streams() {
    s32 i;
    for (i = 0; i < 2; i++) {
        stop_audio_stream((u8 *)lbl_804CB850[i]);
        music_fade_volumes[i] = lbl_805DC764;
    }
    music_fade_frames_remaining = 0;
    lbl_805D62E0 = 0;
    lbl_805D62E4 = 0;
}

void play_area_music(char *name) {
    s32 flag;
    update_all_zones__14TObjBgmColCtrlFl();
    TLobby::release_bgm_resource();
    flag = 1;
    if (lbl_805D62E4 != 0) {
        if (lbl_805D62E0 == 0) {
            music_fade_slot_index = 1 - music_fade_slot_index;
            music_fade_volumes[music_fade_slot_index] = -music_fade_full_scale;
            flag = 0;
            music_fade_frames_remaining = area_music_fade_frame_count;
            music_fade_volumes[1 - music_fade_slot_index] = lbl_805DC764;
            music_fade_step = music_fade_full_scale / (f32)area_music_fade_frame_count;
        } else {
            TLobby::stop_audio_streams();
        }
    }
    if (flag) {
        music_fade_slot_index = 0;
    }
    lbl_805D371C = music_fade_slot_index + 1;
    start_audio_stream_file(lbl_804CB850[music_fade_slot_index], name);
    TLobby__sub_803C94DC((u8 *)lbl_804CB850[music_fade_slot_index], 0);
    TLobby::close_option_window();
    lbl_805D62E0 = 0;
    lbl_805D62E4 = 1;
    strncpy(lbl_80514D00[music_fade_slot_index], name, 0x20);
}

void update_music_fade(void) {
    s32 i;
    if (lbl_805D6330 != 0) {
        return;
    }
    if (lbl_805D62B8 != 0) {
        TLobby::set_and_notify(-999);
    }
    if (music_fade_frames_remaining > 0) {
        music_fade_volumes[music_fade_slot_index] += music_fade_step;
        music_fade_volumes[1 - music_fade_slot_index] -= music_fade_step;
        for (i = 0; i < 2; i++) {
            s32 v;
            if ((s32)music_fade_volumes[i] + get_music_base_gain() > -999) {
                v = (s32)music_fade_volumes[i] + get_music_base_gain();
            } else {
                v = -999;
            }
            set_field_40_and_notify__6TLobbyFs(lbl_804CB850[i], v);
        }
        if (--music_fade_frames_remaining <= 0) {
            s32 st;
            stop_audio_stream((u8 *)lbl_804CB850[1 - music_fade_slot_index]);
            st = TLobby__sub_803C9CB0(lbl_804CB850[music_fade_slot_index]);
            if (st == 0 || st == 5) {
                lbl_805D62E4 = 0;
            }
        }
    }
    if ((u32)lbl_804CB850[2] != 0U && TLobby__sub_803C9CB0(lbl_804CB850[2]) == 3) {
        TLobby__sub_80227AA8(lbl_804CB850[2]);
    }
}

void TLobby::set_pre_retrace_callback() {
    VISetPreRetraceCallback(&TLobby__sub_80227A6C.value);
}
void TLobby::shutdown_buffers() {
    s32 i;
    for (i = 0; i < 3; i++) {
        TLobby__sub_803CA194(lbl_804CB850[i]);
    }
    if (lbl_805D62DC != 0U) {
        xfree((void *)lbl_805D62DC);
        lbl_805D62DC = 0U;
    }
    TLobby::dec_ref_and_shutdown();
    if (lbl_805D62EC != 0U) {
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D62EC);
    }
}

void TLobby__sub_8022780C(void) {
    s32 i;

    lbl_80514C60[0] = xmalloc(0x2D1E4);
    lbl_80514C60[1] = xmalloc(0x2D1E4);
    lbl_805D62D8 = xmalloc(0xA924);
    lbl_805D62DC = (u32)xmalloc(0xA000);
    TLobby__sub_803CBE20((void *)lbl_805D62DC, 0xA000, 5);
    TLobby::init_and_add_ref();
    TLobby__sub_803CB74C(NULL);
    TLobby__sub_803CB858(NULL);
    SndHooks hooks = lbl_8044C858;
    ARInit(lbl_804CB838, 6);
    ARQInit();
    AIInit(NULL);
    VISetPostRetraceCallback(TLobby__sub_80227A70);
    VISetPreRetraceCallback(&TLobby__sub_80227A6C.value);
    TLobby__sub_803C94B8(TLobby__sub_80227A90, 0);
    Dolphin_ARAlloc(0xC00000);
    sndSetHooks(&hooks);
    sndInit(48, 48, 48, 4, 1, 0xC00000);
    TLobby__sub_803C94B8(TLobby__sub_80227A90, 0);
    for (i = 0; i < 2; i++) {
        lbl_804CB850[i] = adx_create_stream_player(2, lbl_80514C60[i], 0x2D1E4);
        if ((u32)lbl_804CB850[i] == 0U) {
            TLobby::debug_print("can't create ADXT-BGM #%d", i);
        } else {
            ((TLobby *)lbl_804CB850[i])->set_field_6d(2);
        }
    }
    for (i = 0; i < 1; i++) {
        lbl_804CB850[2 + i] = adx_create_stream_player(1, (&lbl_805D62D8)[i], 0xA924);
        if ((u32)lbl_804CB850[2 + i] == 0U) {
            TLobby::debug_print("can't create ADXT-SE #%d", i);
        }
    }
    lbl_805D62F8 = 0x5A3C8;
    lbl_805D62FC = 0xA924;
    lbl_805D62E0 = 0;
    lbl_805D62E4 = 0;
    lbl_805D62EC = 0;
    music_fade_frames_remaining = 0;
    lbl_80514D00[1][0] = 0;
    lbl_80514D00[0][0] = 0;
    lbl_805D6330 = 0;
}

