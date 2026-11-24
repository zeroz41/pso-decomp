#include <string.h>
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby.h"
#include "pso/system/TLoadCtrl.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/unk/text_8036A3CC.h"

struct Passage_80226FA0 { s16 first, repeat, count, transition, next; };

struct Program_80226FA0 { char archive[32]; s32 count, ntsc, pal; Passage_80226FA0 *modes[2]; };

s32 lbl_805D3710 = -140;
s32 area_music_fade_frame_count = 60;
f32 music_fade_full_scale = 200.0f;
s16 lbl_805D371C = -1;
char *lobby_current_slot_entry = "";

extern "C" {
    extern int lbl_805D62B8;
void start_audio_stream_file(s32, char *);
void TLobby__sub_803C94DC(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C9CB0(s32);
void *lbl_805D62D8;
void *lbl_805D62DC;
s32 lbl_805D62E0;
s32 lbl_805D62E4;
s32 music_fade_slot_index;
u32 lbl_805D62EC;
s32 lbl_805D62F0;
s32 lbl_805D62F4;
s32 lbl_805D62F8;
s32 lbl_805D62FC;
s32 lbl_805D6300;
Program_80226FA0 *lbl_805D6304;
s32 music_sequencer_passage_index;
s32 music_passage_index;
s32 lbl_805D6310;
s32 lbl_805D6314 = lbl_805D3710;
s32 music_active_mode_index;
s32 music_target_id;
s32 music_sequencer_fade_state;
s32 music_sequencer_timer;
f32 music_fade_step;
s32 music_fade_frames_remaining;
s32 lbl_805D6330;
s16 lbl_805D6334;
void TLobby__sub_802272B4(void);
}
void set_cue_stream_gain(s32 arg0);
extern "C" {
void TLobby__sub_8022733C(void);
s32 TLobby__sub_803C5D00(void *);
s32 TLobby__sub_803C97B8(u8 *arg0);
}
void stop_audio_stream(u8 *arg0);
extern saddr lbl_804CB850[];
void set_dark_falz_music_request(s32 arg0);
void stop_cue_stream(void);
void set_music_streams_volume(s32 total);
void update_music_fade(void);
void append_music_stream_segment(u8 *arg0, s32 arg1, s32 arg2);
void update_music_sequencer(void);

extern "C" char lbl_80514D00[2][0x20];
u8 *TLobby::get_current_slot_entry() {
    if ((s32) lbl_805D62E4 == 1) {
        return (u8 *)lbl_80514D00[music_fade_slot_index];
    }
    return (u8 *)lobby_current_slot_entry;
}

void TLobby::set_and_notify_default() { TLobby::set_and_notify(0); }
void TLobby::send_neg30() { TLobby::set_and_notify(-30); }

void set_cue_stream_gain(s32 arg0) {
    s32 var_r4;
    var_r4 = arg0;
    if (var_r4 <= -0x140) {
        var_r4 = -0x3E7;
    }
    if ((u32) lbl_804CB850[2] != 0U) {
        ((TLobby *)lbl_804CB850[2])->set_field_40_and_notify(var_r4);
    }
}

void set_music_streams_volume(s32 total) {
    s32 var_r31;
    var_r31 = total;
    if (var_r31 <= -0x140) {
        var_r31 = -0x3E7;
    }
    if ((s32) lbl_805D6330 == 0) {
        ((TLobby *)lbl_804CB850[0])->set_field_40_and_notify(var_r31);
    }
    ((TLobby *)lbl_804CB850[1])->set_field_40_and_notify(var_r31);
}
extern "C" {

void TLobby::release_bgm_resource() {
    if ((s32) lbl_805D6330 != 0) {
        stop_audio_stream((u8 *)(*(saddr *)((s8 *)lbl_804CB850 + 4)));
        lbl_805D6330 = 0;
        TLobby::init_layout_positions();
    }
}

extern void *lbl_80514C60[];
extern const char *bgm_stream_files[];
int get_music_base_gain(void);

void TLoadCtrl__sub_80226DA0(s32 index) {
    if (index < 0 || index >= 4) {
        return;
    }
    if (lbl_805D6330 == 0) {
        void *buf;
        TLoadCtrl::step();
        /* the original marks the stream busy while evaluating the call's arguments */
        read_disc_file_sectors(bgm_stream_files[index],
                               (lbl_805D6330 = 1, buf = lbl_80514C60[0]));
        ((TLobby *)lbl_804CB850[1])->adxt_start_mem_idx((u8 *)buf, 0);
        ((TLobby *)lbl_804CB850[1])->set_field_40_and_notify(get_music_base_gain());
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
int TKeyBoardControl__sub_8000F828(void);
s32 TKeyBoardControl__sub_801E3E24(s32 id, const char *name, void *buf, s32 size);
void TLobby__sub_803C5D24(u8 *player);
}
extern Program_80226FA0 *music_programs[];

void init_music_sequencer(s32 program) {
    unlock_sequencer_flag(program);
    lbl_805D371C = 0;
    TLobby::release_bgm_resource();
    lbl_805D6300 = program;
    lbl_805D6304 = music_programs[program];
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
    if (lbl_80514CE8[music_fade_slot_index] < lbl_805D62F4 && TLobby__sub_803C5D00((void *)lbl_804CB850[0]) != 1) {
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
    append_music_stream_segment((u8 *)((void *)lbl_804CB850[0]), 190, lbl_80514CE0[music_fade_slot_index]);
    music_fade_slot_index = 1 - music_fade_slot_index;
    lbl_80514CE8[music_fade_slot_index] = 0;
    lbl_80514CF0[music_fade_slot_index] = TLobby__sub_803C97B8((u8 *)((void *)lbl_804CB850[music_fade_slot_index]));
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
        stop_audio_stream((u8 *)lbl_804CB850[2]);
    }
}

void play_cue_stream_file(const char *name) {
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


extern "C" {
s32 VISetPreRetraceCallback(void (*callback)(void));
void TLobby__sub_80227AA8(s32);
void update_all_zones__14TObjBgmColCtrlFl(void);
extern char lbl_80514D00[][0x20];
void play_area_music(char *name);
void TWindowOptionCtrl__sub_802273B4(s32 arg0);
void TLobby__sub_803CA194(s32);
struct SndHooks {
    void *(*malloc)(u32 size);
    void (*free)(void *ptr);
};
void TLobby__sub_803CBE20(void *work, s32 size, s32 count);
void setup_adx_file_systems(s32 *arg0);
void init_runtime_threads(s32 *cfg);
void TLobby__sub_803C94B8(AdxMessageCallback callback, s32 context);
s32 adx_create_stream_player(s32 n, void *buffer, s32 size);
u32 ARInit(u32 *stack_index_addr, u32 num_entries);
void ARQInit(void);
void AIInit(u8 *stack);
s32 VISetPostRetraceCallback(int (*callback)(void *));
u32 ARAlloc(u32 length);
void sndSetHooks(SndHooks *hooks);
s32 sndInit(u8 voices, u8 music, u8 sfx, u8 studios, u32 flags, u32 aram_size);
}
void init_adx_audio_system(void);
extern u32 lbl_804CB838[6];
saddr lbl_804CB850[3] = { 0, 0, 0 };

// inferred: the four .acx streams TLoadCtrl__sub_80226DA0 starts by index.
// MusyX allocation hooks; init_adx_audio_system hands a copy to sndSetHooks (name inferred from that use).
extern const SndHooks snd_hooks = { TLobby__sub_80227A4C, TLobby::free };
const char *bgm_stream_files[] = {"bass.acx", "map1.acx", "map2.acx", "quest.acx", NULL};

// Area music: each program names its .afs archive and two passage lists (modes[0]/[1]).
static Passage_80226FA0 forest_mode0_passages[6] = {
    {0, 24, 4, 25, 1},
    {4, 4, 4, 26, 2},
    {8, 8, 4, 27, 3},
    {12, 12, 4, 28, 4},
    {16, 16, 4, 29, 5},
    {20, 20, 4, 30, 0},
};
static Passage_80226FA0 forest_mode1_passages[6] = {
    {31, 55, 4, 56, 1},
    {35, 35, 4, 57, 2},
    {39, 39, 4, 58, 3},
    {43, 43, 4, 59, 4},
    {47, 47, 4, 60, 5},
    {51, 51, 4, 61, 0},
};
static Program_80226FA0 forest_music = {"slbgm_forest.afs", 6, 146, 242, {forest_mode0_passages, forest_mode1_passages}};

static Passage_80226FA0 ancient_mode0_passages[6] = {
    {0, 0, 4, 24, 1},
    {4, 23, 4, 25, 2},
    {8, 8, 2, 26, 3},
    {10, 10, 4, 27, 4},
    {14, 14, 5, 28, 5},
    {19, 19, 4, 29, 1},
};
static Passage_80226FA0 ancient_mode1_passages[6] = {
    {30, 49, 4, 50, 2},
    {30, 49, 4, 50, 2},
    {34, 34, 2, 51, 3},
    {36, 36, 4, 52, 4},
    {40, 40, 5, 53, 5},
    {45, 45, 4, 54, 1},
};
static Program_80226FA0 ancient_music = {"slbgm_ancient.afs", 6, 184, 298, {ancient_mode0_passages, ancient_mode1_passages}};

static Passage_80226FA0 dark_mode0_passages[2] = {
    {0, 0, 2, -1, 1},
    {2, 12, 10, -1, 1},
};
static Passage_80226FA0 dark_mode1_passages[2] = {
    {13, 21, 8, -1, 0},
    {13, 21, 8, -1, 0},
};
static Program_80226FA0 dark_music = {"slbgm_dark.afs", 2, 321, 268, {dark_mode0_passages, dark_mode1_passages}};

static Passage_80226FA0 cave_mode0_passages[6] = {
    {0, 24, 4, 25, 1},
    {4, 4, 4, 26, 2},
    {8, 8, 4, 27, 3},
    {12, 12, 4, 28, 4},
    {16, 16, 4, 29, 5},
    {20, 20, 4, 30, 0},
};
static Passage_80226FA0 cave_mode1_passages[6] = {
    {31, 55, 4, 56, 1},
    {35, 35, 4, 57, 2},
    {39, 39, 4, 58, 3},
    {43, 43, 4, 59, 4},
    {47, 47, 4, 60, 5},
    {51, 51, 4, 61, 0},
};
static Program_80226FA0 cave_music = {"slbgm_cave.afs", 6, 157, 260, {cave_mode0_passages, cave_mode1_passages}};

static Passage_80226FA0 machine_mode0_passages[5] = {
    {0, 20, 4, 21, 1},
    {4, 4, 4, 22, 2},
    {8, 8, 4, 23, 3},
    {12, 12, 4, 24, 4},
    {16, 16, 4, 25, 0},
};
static Passage_80226FA0 machine_mode1_passages[5] = {
    {26, 46, 4, 47, 1},
    {30, 30, 4, 48, 2},
    {34, 34, 4, 49, 3},
    {38, 38, 4, 50, 4},
    {42, 42, 4, 51, 0},
};
static Program_80226FA0 machine_music = {"slbgm_machine.afs", 5, 121, 206, {machine_mode0_passages, machine_mode1_passages}};

static Passage_80226FA0 jungle_mode0_passages[7] = {
    {7, 35, 4, 0, 1},
    {11, 11, 4, 1, 2},
    {15, 15, 4, 2, 3},
    {19, 19, 4, 3, 4},
    {23, 23, 4, 4, 5},
    {27, 27, 4, 5, 6},
    {31, 31, 4, 6, 0},
};
static Passage_80226FA0 jungle_mode1_passages[7] = {
    {36, 64, 4, 65, 1},
    {40, 40, 4, 66, 2},
    {44, 44, 4, 67, 3},
    {48, 48, 4, 68, 4},
    {52, 52, 4, 69, 5},
    {56, 56, 4, 70, 6},
    {60, 60, 4, 71, 0},
};
static Program_80226FA0 jungle_music = {"slbgm_jungle.afs", 7, 156, 206, {jungle_mode0_passages, jungle_mode1_passages}};

static Passage_80226FA0 seabed_mode0_passages[6] = {
    {0, 0, 4, 27, 1},
    {4, 26, 4, 28, 2},
    {8, 8, 4, 29, 3},
    {12, 12, 4, 30, 4},
    {16, 16, 4, 31, 5},
    {20, 20, 6, 32, 1},
};
static Passage_80226FA0 seabed_mode1_passages[6] = {
    {33, 33, 4, 60, 1},
    {37, 59, 4, 61, 2},
    {41, 41, 4, 62, 3},
    {45, 45, 4, 63, 4},
    {49, 49, 4, 64, 5},
    {53, 53, 6, 65, 1},
};
static Program_80226FA0 seabed_music = {"slbgm_seabed.afs", 6, 171, 206, {seabed_mode0_passages, seabed_mode1_passages}};

static Passage_80226FA0 space_mode0_passages[8] = {
    {0, 0, 4, 29, 1},
    {4, 28, 4, 30, 2},
    {8, 8, 2, 31, 3},
    {10, 10, 4, 32, 4},
    {14, 14, 2, 33, 5},
    {16, 16, 4, 34, 6},
    {20, 20, 4, 35, 7},
    {24, 24, 4, 36, 1},
};
static Passage_80226FA0 space_mode1_passages[8] = {
    {41, 65, 4, 66, 1},
    {41, 65, 4, 66, 2},
    {45, 45, 2, 67, 3},
    {47, 47, 4, 68, 4},
    {51, 51, 2, 69, 5},
    {53, 53, 4, 70, 6},
    {57, 57, 4, 71, 7},
    {61, 61, 4, 72, 1},
};
static Program_80226FA0 space_music = {"slbgm_space.afs", 8, 192, 206, {space_mode0_passages, space_mode1_passages}};

static Passage_80226FA0 ruin_mode0_passages[7] = {
    {0, 22, 2, 23, 1},
    {2, 2, 4, 24, 2},
    {6, 6, 2, 25, 3},
    {8, 8, 4, 26, 4},
    {12, 12, 2, 27, 5},
    {14, 14, 4, 28, 6},
    {18, 18, 4, 29, 0},
};
static Passage_80226FA0 ruin_mode1_passages[7] = {
    {30, 52, 2, 53, 1},
    {32, 32, 4, 54, 2},
    {36, 36, 2, 55, 3},
    {38, 38, 4, 56, 4},
    {42, 42, 2, 57, 5},
    {44, 44, 4, 58, 6},
    {48, 48, 4, 59, 0},
};
static Program_80226FA0 ruin_music = {"slbgm_ruin.afs", 7, 171, 206, {ruin_mode0_passages, ruin_mode1_passages}};

// inferred: the area music programs init_music_sequencer selects by index.
Program_80226FA0 *music_programs[] = {
    &forest_music, &cave_music, &machine_music, &ancient_music, &dark_music,
    &jungle_music, &seabed_music, &ruin_music, &space_music,
};
extern f32 music_fade_volumes[];

void TLoadCtrl::step() { TLobby::stop_audio_streams(); stop_cue_stream(); }

void TWindowOptionCtrl__sub_802273B4(s32 arg0) {
    if (lbl_805D62E0 != 0) {
        TLobby::stop_audio_streams();
        return;
    }
    music_fade_slot_index = 1 - music_fade_slot_index;
    music_fade_frames_remaining = arg0;
    music_fade_volumes[1 - music_fade_slot_index] = 0.0f;
    music_fade_step = music_fade_full_scale / (f32)arg0;
}

void TLobby::stop_audio_streams() {
    s32 i;
    for (i = 0; i < 2; i++) {
        stop_audio_stream((u8 *)lbl_804CB850[i]);
        music_fade_volumes[i] = 0.0f;
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
            ((TLobby *)lbl_804CB850[i])->set_field_40_and_notify(v);
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
    VISetPreRetraceCallback(TLobby__sub_80227A6C);
}
void TLobby::shutdown_buffers() {
    s32 i;
    for (i = 0; i < 3; i++) {
        TLobby__sub_803CA194(lbl_804CB850[i]);
    }
    if (lbl_805D62DC != NULL) {
        xfree(lbl_805D62DC);
        lbl_805D62DC = NULL;
    }
    TLobby::dec_ref_and_shutdown();
    if (lbl_805D62EC != 0U) {
        safe_free(reinterpret_cast<void *>(lbl_805D62EC));
    }
}

// snd_hooks is addressed by its own symbol here, not off a pooled .rodata base.
#pragma pool_data off
void init_adx_audio_system(void) {
    s32 i;

    lbl_80514C60[0] = xmalloc(0x2D1E4);
    lbl_80514C60[1] = xmalloc(0x2D1E4);
    lbl_805D62D8 = xmalloc(0xA924);
    lbl_805D62DC = xmalloc(0xA000);
    TLobby__sub_803CBE20(lbl_805D62DC, 0xA000, 5);
    TLobby::init_and_add_ref();
    setup_adx_file_systems(NULL);
    init_runtime_threads(NULL);
    SndHooks hooks = snd_hooks;
    ARInit(lbl_804CB838, 6);
    ARQInit();
    AIInit(NULL);
    VISetPostRetraceCallback(TLobby__sub_80227A70);
    VISetPreRetraceCallback(TLobby__sub_80227A6C);
    TLobby__sub_803C94B8(TLobby__sub_80227A90, 0);
    ARAlloc(0xC00000);
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
#pragma pool_data reset


// TLobby::free and TLobby__sub_80227A4C are the MusyX free/malloc hooks (snd_hooks, sndSetHooks).
void TLobby::free(void *p) { xfree(p); }

extern "C" {
void *TLobby__sub_80227A4C(u32 size) { return xmalloc(size); }
void TLobby__sub_80227A6C(void) {  }
int TLobby__sub_80227A70(void* p) { return ((int (*)(void*))TLobby__sub_8022804C)(p); }
void TLobby__sub_80227A90(s32, const char *) {  }
}
