#include <string.h>
#include "pso/audio/AdxtInit.h"
#include "pso/system/ResourceFile.h"
#include "pso/audio/AdxtInternal.h"
#include "pso/audio/AdxTalk.h"
#include "pso/audio/AdxtEntryAfs.h"
#include "types.h"
#include <dolphin/ar.h>
#include <dolphin/ai.h>
#include "pso/system/vector.h"
#include "pso/network/TLobby.h"
#include "pso/system/TLoadCtrl.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_80226C3C.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/unk/TLobby_80227AA0.h"
#include "pso/unk/text_8036A3CC.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/audio/AdxManager.h"
#include "pso/ui/keyboard/SystemBootInitInternal.h"
#include "dolphin/ar.h"
#include "dolphin/ai.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/object/collision/TObjBgmColCtrl.h"



s32 lbl_805D3710 = -140;
s32 area_music_fade_frame_count = 60;
f32 music_fade_full_scale = 200.0f;
s16 lbl_805D371C = -1;
char *lobby_current_slot_entry = "";

extern "C" {
u32 lbl_804CB838[6] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
}
// [0] and [1] play the music, [2] the cue stream ("can't create ADXT-BGM #%d", "can't create ADXT-SE #%d").
AdxtPlayer *adxt_players[3] = { NULL, NULL, NULL };

void *lbl_805D62D8;
void *lbl_805D62DC;
s32 music_active;
s32 music_state;
s32 music_fade_slot_index;
u32 lbl_805D62EC;
s32 music_next_cue;
s32 music_cue_threshold;
s32 lbl_805D62F8;
s32 lbl_805D62FC;
s32 music_program_index;
TLoadCtrlProgram *music_program;
s32 music_sequencer_passage_index;
s32 music_passage_index;
s32 music_loop_started;
s32 lbl_805D6314 = lbl_805D3710;
s32 music_active_mode_index;
s32 music_target_id;
s32 music_sequencer_fade_state;
s32 music_sequencer_timer;
f32 music_fade_step;
s32 music_fade_frames_remaining;
s32 bgm_stream_active;
s16 music_current_slot;

extern char music_slot_entries[2][0x20];
u8 *TLobby::get_current_slot_entry() {
    if ((s32) music_state == 1) {
        return (u8 *)music_slot_entries[music_fade_slot_index];
    }
    return (u8 *)lobby_current_slot_entry;
}

void TLobby::set_and_notify_default() { TLobby::set_and_notify(0); }
void TLobby::send_neg30() { TLobby::set_and_notify(-30); }

void set_cue_stream_gain(s32 gain) {
    s32 value;
    value = gain;
    if (value <= -0x140) {
        value = -0x3E7;
    }
    if (adxt_players[2] != NULL) {
        adxt_set_output_vol(adxt_players[2], value);
    }
}

void set_music_streams_volume(s32 total) {
    s32 value;
    value = total;
    if (value <= -0x140) {
        value = -0x3E7;
    }
    if ((s32) bgm_stream_active == 0) {
        adxt_set_output_vol(adxt_players[0], value);
    }
    adxt_set_output_vol(adxt_players[1], value);
}
void TLobby::release_bgm_resource() {
    if ((s32) bgm_stream_active != 0) {
        stop_audio_stream(adxt_players[1]);
        bgm_stream_active = 0;
        TLobby::init_layout_positions();
    }
}
void *bgm_stream_buffers[0x20];
extern const char *bgm_stream_files[];

void start_bgm_stream(s32 index) {
    if (index < 0 || index >= 4) {
        return;
    }
    if (bgm_stream_active == 0) {
        void *buf;
        TLoadCtrl::step();
        /* the original marks the stream busy while evaluating the call's arguments */
        read_disc_file_sectors(bgm_stream_files[index],
                               (bgm_stream_active = 1, buf = bgm_stream_buffers[0]));
        ADXT_StartMemIdx(adxt_players[1], (u8 *)buf, 0);
        adxt_set_output_vol(adxt_players[1], get_music_base_gain());
        adxt_set_pause(adxt_players[1], 0);
    }
}

extern "C" {
__declspec(section ".data") s32 music_slot_cues[2];
__declspec(section ".data") s32 music_slot_progress[2];
__declspec(section ".data") s32 lbl_80514CF0[2];
__declspec(section ".data") f32 music_fade_volumes[2];
__declspec(section ".data") char music_slot_entries[2][0x20];
}
u8 lbl_80514D40[0x218];

extern TLoadCtrlProgram *music_programs[];

void init_music_sequencer(s32 program) {
    unlock_sequencer_flag(program);
    lbl_805D371C = 0;
    TLobby::release_bgm_resource();
    music_program_index = program;
    music_program = music_programs[program];
    music_loop_started = 0;
    TLobby::stop_audio_streams();
    music_active = 1;
    music_state = 1;
    music_fade_slot_index = 0;
    music_sequencer_fade_state = 0;
    music_target_id = 0;
    music_active_mode_index = 0;
    music_slot_progress[0] = 0;
    music_slot_progress[1] = 0;
    music_sequencer_timer = 0;
    if (get_video_standard() == 1) {
        music_cue_threshold = music_program->pal;
    } else {
        music_cue_threshold = music_program->ntsc;
    }
    music_slot_cues[0] = music_program->modes[0][0].first;
    music_slot_cues[1] = music_slot_cues[0] + 1;
    music_sequencer_passage_index = 0;
    music_passage_index = 1;
    open_afs_file_wait_input(190, music_program->archive, lbl_80514D40, 128);
    ADXT_EntryAfs(adxt_players[0], 190, music_slot_cues[0]);
    ADXT_EntryAfs(adxt_players[0], 190, music_slot_cues[1]);
    adxt_start_seamless(adxt_players[0]);
    TLobby::close_option_window();
    strncpy(music_slot_entries[0], music_program->archive, 32);
    strncpy(music_slot_entries[1], music_program->archive, 32);
}
void update_music_sequencer(void) {
    UpdateMusicSequencerPassage *passage;
    UpdateMusicSequencerPassage *next;
    if (music_active != 1) {
        return;
    }
    if (music_state != 1) {
        return;
    }
    music_slot_progress[music_fade_slot_index]++;
    if (music_sequencer_timer > 0) {
        music_sequencer_timer--;
    } else if (music_sequencer_fade_state == 0 && music_target_id != music_active_mode_index) {
        music_sequencer_fade_state = 1;
        music_sequencer_timer = 600;
    }
    if (music_slot_progress[music_fade_slot_index] < music_cue_threshold && get_stream_queued_count(adxt_players[0]) != 1) {
        return;
    }
    passage = &music_program->modes[music_active_mode_index][music_sequencer_passage_index];
    switch (music_sequencer_fade_state) {
    case 0:
        if (++music_passage_index >= passage->count) {
            music_sequencer_passage_index = passage->next;
            music_passage_index = 0;
            next = &music_program->modes[music_active_mode_index][music_sequencer_passage_index];
            if (music_loop_started) {
                music_next_cue = next->repeat;
            } else {
                music_next_cue = next->first;
                music_loop_started = 1;
            }
        } else {
            music_next_cue = passage->first + music_passage_index;
        }
        break;
    case 1:
        music_sequencer_passage_index = passage->next;
        music_passage_index = 0;
        music_active_mode_index = 1 - music_active_mode_index;
        music_sequencer_timer = 600;
        if (passage->transition >= 0) {
            music_next_cue = passage->transition;
            music_sequencer_fade_state = 2;
        } else {
            music_next_cue = music_program->modes[music_target_id][music_sequencer_passage_index].first;
            music_loop_started = 1;
            music_sequencer_fade_state = 0;
        }
        break;
    case 2:
        if (music_loop_started) {
            music_next_cue = passage->repeat;
        } else {
            music_next_cue = passage->first;
            music_loop_started = 1;
        }
        music_sequencer_fade_state = 0;
        break;
    }
    music_slot_cues[music_fade_slot_index] = music_next_cue;
    music_current_slot = music_fade_slot_index;
    ADXT_EntryAfs(adxt_players[0], 190, music_slot_cues[music_fade_slot_index]);
    music_fade_slot_index = 1 - music_fade_slot_index;
    music_slot_progress[music_fade_slot_index] = 0;
    lbl_80514CF0[music_fade_slot_index] = adxt_get_num_samples(adxt_players[music_fade_slot_index]);
}

void set_dark_falz_music_request(s32 request) {
    if ((s32) music_program_index == 4) {
        music_target_id = request;
    }
}

void TLobby::set_target_id(s32 target_id) {
    if ((s32) music_program_index != 4) {
        music_target_id = target_id;
    }
}

void stop_cue_stream(void) {
    if (adxt_players[2] != NULL) {
        stop_audio_stream(adxt_players[2]);
    }
}

void play_cue_stream_file(const char *name) {
    if (adxt_players[2] != NULL) {
        ADXT_StartFname(adxt_players[2], name);
    }
}
void turn_on_bgm_p2(void) {
    s32 status;
    adxt_set_pause(adxt_players[music_fade_slot_index], 0);
    adxt_set_pause(adxt_players[2], 0);
    status = adxt_get_stat(adxt_players[music_fade_slot_index]);
    if ((status == 0) || (status == 5)) {
        music_state = 0;
        return;
    }
    music_state = 1;
}
void turn_off_bgm_p2(void) {
    adxt_set_pause(adxt_players[music_fade_slot_index], 1);
    adxt_set_pause(adxt_players[2], 1);
    music_state = 2;
}



extern "C" {
s32 VISetPreRetraceCallback(void (*callback)(void));
}
struct SndHooks {
    void *(*malloc)(u32 size);
    void (*free)(void *ptr);
};
extern "C" {
void adx_bridge_set_buffer_storage(void *work, s32 size, s32 count);
}
extern "C" {
s32 VISetPostRetraceCallback(int (*callback)(void *));
void sndSetHooks(SndHooks *hooks);
s32 sndInit(u8 voices, u8 music, u8 sfx, u8 studios, u32 flags, u32 aram_size);
}

// The four .acx streams start_bgm_stream starts by index.
// MusyX allocation hooks; init_adx_audio_system hands a copy to sndSetHooks (name inferred from that use).
extern const SndHooks snd_hooks = { musyx_malloc_hook, TLobby::free };
const char *bgm_stream_files[] = {"bass.acx", "map1.acx", "map2.acx", "quest.acx", NULL};

// Area music: each program names its .afs archive and two passage lists (modes[0]/[1]).
static UpdateMusicSequencerPassage forest_mode0_passages[6] = {
    {0, 24, 4, 25, 1},
    {4, 4, 4, 26, 2},
    {8, 8, 4, 27, 3},
    {12, 12, 4, 28, 4},
    {16, 16, 4, 29, 5},
    {20, 20, 4, 30, 0},
};
static UpdateMusicSequencerPassage forest_mode1_passages[6] = {
    {31, 55, 4, 56, 1},
    {35, 35, 4, 57, 2},
    {39, 39, 4, 58, 3},
    {43, 43, 4, 59, 4},
    {47, 47, 4, 60, 5},
    {51, 51, 4, 61, 0},
};
static TLoadCtrlProgram forest_music = {"slbgm_forest.afs", 6, 146, 242, {forest_mode0_passages, forest_mode1_passages}};

static UpdateMusicSequencerPassage ancient_mode0_passages[6] = {
    {0, 0, 4, 24, 1},
    {4, 23, 4, 25, 2},
    {8, 8, 2, 26, 3},
    {10, 10, 4, 27, 4},
    {14, 14, 5, 28, 5},
    {19, 19, 4, 29, 1},
};
static UpdateMusicSequencerPassage ancient_mode1_passages[6] = {
    {30, 49, 4, 50, 2},
    {30, 49, 4, 50, 2},
    {34, 34, 2, 51, 3},
    {36, 36, 4, 52, 4},
    {40, 40, 5, 53, 5},
    {45, 45, 4, 54, 1},
};
static TLoadCtrlProgram ancient_music = {"slbgm_ancient.afs", 6, 184, 298, {ancient_mode0_passages, ancient_mode1_passages}};

static UpdateMusicSequencerPassage dark_mode0_passages[2] = {
    {0, 0, 2, -1, 1},
    {2, 12, 10, -1, 1},
};
static UpdateMusicSequencerPassage dark_mode1_passages[2] = {
    {13, 21, 8, -1, 0},
    {13, 21, 8, -1, 0},
};
static TLoadCtrlProgram dark_music = {"slbgm_dark.afs", 2, 321, 268, {dark_mode0_passages, dark_mode1_passages}};

static UpdateMusicSequencerPassage cave_mode0_passages[6] = {
    {0, 24, 4, 25, 1},
    {4, 4, 4, 26, 2},
    {8, 8, 4, 27, 3},
    {12, 12, 4, 28, 4},
    {16, 16, 4, 29, 5},
    {20, 20, 4, 30, 0},
};
static UpdateMusicSequencerPassage cave_mode1_passages[6] = {
    {31, 55, 4, 56, 1},
    {35, 35, 4, 57, 2},
    {39, 39, 4, 58, 3},
    {43, 43, 4, 59, 4},
    {47, 47, 4, 60, 5},
    {51, 51, 4, 61, 0},
};
static TLoadCtrlProgram cave_music = {"slbgm_cave.afs", 6, 157, 260, {cave_mode0_passages, cave_mode1_passages}};

static UpdateMusicSequencerPassage machine_mode0_passages[5] = {
    {0, 20, 4, 21, 1},
    {4, 4, 4, 22, 2},
    {8, 8, 4, 23, 3},
    {12, 12, 4, 24, 4},
    {16, 16, 4, 25, 0},
};
static UpdateMusicSequencerPassage machine_mode1_passages[5] = {
    {26, 46, 4, 47, 1},
    {30, 30, 4, 48, 2},
    {34, 34, 4, 49, 3},
    {38, 38, 4, 50, 4},
    {42, 42, 4, 51, 0},
};
static TLoadCtrlProgram machine_music = {"slbgm_machine.afs", 5, 121, 206, {machine_mode0_passages, machine_mode1_passages}};

static UpdateMusicSequencerPassage jungle_mode0_passages[7] = {
    {7, 35, 4, 0, 1},
    {11, 11, 4, 1, 2},
    {15, 15, 4, 2, 3},
    {19, 19, 4, 3, 4},
    {23, 23, 4, 4, 5},
    {27, 27, 4, 5, 6},
    {31, 31, 4, 6, 0},
};
static UpdateMusicSequencerPassage jungle_mode1_passages[7] = {
    {36, 64, 4, 65, 1},
    {40, 40, 4, 66, 2},
    {44, 44, 4, 67, 3},
    {48, 48, 4, 68, 4},
    {52, 52, 4, 69, 5},
    {56, 56, 4, 70, 6},
    {60, 60, 4, 71, 0},
};
static TLoadCtrlProgram jungle_music = {"slbgm_jungle.afs", 7, 156, 206, {jungle_mode0_passages, jungle_mode1_passages}};

static UpdateMusicSequencerPassage seabed_mode0_passages[6] = {
    {0, 0, 4, 27, 1},
    {4, 26, 4, 28, 2},
    {8, 8, 4, 29, 3},
    {12, 12, 4, 30, 4},
    {16, 16, 4, 31, 5},
    {20, 20, 6, 32, 1},
};
static UpdateMusicSequencerPassage seabed_mode1_passages[6] = {
    {33, 33, 4, 60, 1},
    {37, 59, 4, 61, 2},
    {41, 41, 4, 62, 3},
    {45, 45, 4, 63, 4},
    {49, 49, 4, 64, 5},
    {53, 53, 6, 65, 1},
};
static TLoadCtrlProgram seabed_music = {"slbgm_seabed.afs", 6, 171, 206, {seabed_mode0_passages, seabed_mode1_passages}};

static UpdateMusicSequencerPassage space_mode0_passages[8] = {
    {0, 0, 4, 29, 1},
    {4, 28, 4, 30, 2},
    {8, 8, 2, 31, 3},
    {10, 10, 4, 32, 4},
    {14, 14, 2, 33, 5},
    {16, 16, 4, 34, 6},
    {20, 20, 4, 35, 7},
    {24, 24, 4, 36, 1},
};
static UpdateMusicSequencerPassage space_mode1_passages[8] = {
    {41, 65, 4, 66, 1},
    {41, 65, 4, 66, 2},
    {45, 45, 2, 67, 3},
    {47, 47, 4, 68, 4},
    {51, 51, 2, 69, 5},
    {53, 53, 4, 70, 6},
    {57, 57, 4, 71, 7},
    {61, 61, 4, 72, 1},
};
static TLoadCtrlProgram space_music = {"slbgm_space.afs", 8, 192, 206, {space_mode0_passages, space_mode1_passages}};

static UpdateMusicSequencerPassage ruin_mode0_passages[7] = {
    {0, 22, 2, 23, 1},
    {2, 2, 4, 24, 2},
    {6, 6, 2, 25, 3},
    {8, 8, 4, 26, 4},
    {12, 12, 2, 27, 5},
    {14, 14, 4, 28, 6},
    {18, 18, 4, 29, 0},
};
static UpdateMusicSequencerPassage ruin_mode1_passages[7] = {
    {30, 52, 2, 53, 1},
    {32, 32, 4, 54, 2},
    {36, 36, 2, 55, 3},
    {38, 38, 4, 56, 4},
    {42, 42, 2, 57, 5},
    {44, 44, 4, 58, 6},
    {48, 48, 4, 59, 0},
};
static TLoadCtrlProgram ruin_music = {"slbgm_ruin.afs", 7, 171, 206, {ruin_mode0_passages, ruin_mode1_passages}};

// The area music programs init_music_sequencer selects by index.
TLoadCtrlProgram *music_programs[] = {
    &forest_music, &cave_music, &machine_music, &ancient_music, &dark_music,
    &jungle_music, &seabed_music, &ruin_music, &space_music,
};
extern f32 music_fade_volumes[];

void TLoadCtrl::step() { TLobby::stop_audio_streams(); stop_cue_stream(); }

void start_music_crossfade(s32 frames) {
    if (music_active != 0) {
        TLobby::stop_audio_streams();
        return;
    }
    music_fade_slot_index = 1 - music_fade_slot_index;
    music_fade_frames_remaining = frames;
    music_fade_volumes[1 - music_fade_slot_index] = 0.0f;
    music_fade_step = music_fade_full_scale / (f32)frames;
}

void TLobby::stop_audio_streams() {
    s32 i;
    for (i = 0; i < 2; i++) {
        stop_audio_stream(adxt_players[i]);
        music_fade_volumes[i] = 0.0f;
    }
    music_fade_frames_remaining = 0;
    music_active = 0;
    music_state = 0;
}

void play_area_music(char *name) {
    s32 flag;
    TObjBgmColCtrl::update_all_zones((saddr)name);
    TLobby::release_bgm_resource();
    flag = 1;
    if (music_state != 0) {
        if (music_active == 0) {
            music_fade_slot_index = 1 - music_fade_slot_index;
            music_fade_volumes[music_fade_slot_index] = -music_fade_full_scale;
            flag = 0;
            music_fade_frames_remaining = area_music_fade_frame_count;
            music_fade_volumes[1 - music_fade_slot_index] = 0.0f;
            music_fade_step = music_fade_full_scale / (f32)area_music_fade_frame_count;
        } else {
            TLobby::stop_audio_streams();
        }
    }
    if (flag) {
        music_fade_slot_index = 0;
    }
    lbl_805D371C = music_fade_slot_index + 1;
    ADXT_StartFname(adxt_players[music_fade_slot_index], name);
    adxt_set_pause(adxt_players[music_fade_slot_index], 0);
    TLobby::close_option_window();
    music_active = 0;
    music_state = 1;
    strncpy(music_slot_entries[music_fade_slot_index], name, 0x20);
}

void update_music_fade(void) {
    s32 i;
    if (bgm_stream_active != 0) {
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
            adxt_set_output_vol(adxt_players[i], v);
        }
        if (--music_fade_frames_remaining <= 0) {
            s32 st;
            stop_audio_stream(adxt_players[1 - music_fade_slot_index]);
            st = adxt_get_stat(adxt_players[music_fade_slot_index]);
            if (st == 0 || st == 5) {
                music_state = 0;
            }
        }
    }
    if (adxt_players[2] != NULL && adxt_get_stat(adxt_players[2]) == 3) {
        TLobby__sub_80227AA8((saddr)adxt_players[2]);
    }
}

void TLobby::set_pre_retrace_callback() {
    VISetPreRetraceCallback(pre_retrace_callback);
}
void TLobby::shutdown_buffers() {
    s32 i;
    for (i = 0; i < 3; i++) {
        adx_destroy_stream_player(adxt_players[i]);
    }
    if (lbl_805D62DC != NULL) {
        xfree(lbl_805D62DC);
        lbl_805D62DC = NULL;
    }
    adxt_finish();
    if (lbl_805D62EC != 0U) {
        safe_free(reinterpret_cast<void *>(lbl_805D62EC));
    }
}

// snd_hooks is addressed by its own symbol here, not off a pooled .rodata base.
#pragma pool_data off
void init_adx_audio_system(void) {
    s32 i;

    bgm_stream_buffers[0] = xmalloc(0x2D1E4);
    bgm_stream_buffers[1] = xmalloc(0x2D1E4);
    lbl_805D62D8 = xmalloc(0xA924);
    lbl_805D62DC = xmalloc(0xA000);
    adx_bridge_set_buffer_storage(lbl_805D62DC, 0xA000, 5);
    adxt_init();
    setup_adx_file_systems(NULL);
    init_runtime_threads(NULL);
    SndHooks hooks = snd_hooks;
    ARInit(lbl_804CB838, 6);
    ARQInit();
    AIInit(NULL);
    VISetPostRetraceCallback(post_retrace_callback);
    VISetPreRetraceCallback(pre_retrace_callback);
    adxt_set_error_callback(TLobby__sub_80227A90, 0);
    ARAlloc(0xC00000);
    sndSetHooks(&hooks);
    sndInit(48, 48, 48, 4, 1, 0xC00000);
    adxt_set_error_callback(TLobby__sub_80227A90, 0);
    for (i = 0; i < 2; i++) {
        adxt_players[i] = adx_create_stream_player(2, bgm_stream_buffers[i], 0x2D1E4);
        if (adxt_players[i] == NULL) {
            TLobby::debug_print("can't create ADXT-BGM #%d", i);
        } else {
            set_auto_repeat(adxt_players[i], 2);
        }
    }
    for (i = 0; i < 1; i++) {
        adxt_players[2 + i] = adx_create_stream_player(1, (&lbl_805D62D8)[i], 0xA924);
        if (adxt_players[2 + i] == NULL) {
            TLobby::debug_print("can't create ADXT-SE #%d", i);
        }
    }
    lbl_805D62F8 = 0x5A3C8;
    lbl_805D62FC = 0xA924;
    music_active = 0;
    music_state = 0;
    lbl_805D62EC = 0;
    music_fade_frames_remaining = 0;
    music_slot_entries[1][0] = 0;
    music_slot_entries[0][0] = 0;
    bgm_stream_active = 0;
}
#pragma pool_data reset


// TLobby::free and musyx_malloc_hook are the MusyX free/malloc hooks (snd_hooks, sndSetHooks).
void TLobby::free(void *p) { xfree(p); }

void *musyx_malloc_hook(u32 size) { return xmalloc(size); }
void pre_retrace_callback(void) {  }
int post_retrace_callback(void* p) { return ((int (*)(void*))TLobby__sub_8022804C)(p); }
void TLobby__sub_80227A90(s32, const char *) {  }
