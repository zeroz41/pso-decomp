#ifndef PSO_UI_WINDOW_TWINDOWSNAPSHOT_H
#define PSO_UI_WINDOW_TWINDOWSNAPSHOT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/RlcArchive.h"
#include "pso/unk/WindowLayoutRecord.h"

struct TWindowSnapShot : public TWindowBase {
    TWindowSnapShot(saddr position);
    virtual ~TWindowSnapShot();
    static const char *class_name;
    virtual void render();
    u8 result_flags; // bit 0 closed by the player (is_done), bit 1 no valid snapshot
    void play_open_sound();
    int is_done();
    virtual void run_task();
    u8 pad_61[0x3];
};

LAYOUT_ASSERT(TWindowSnapShot_size, sizeof(TWindowSnapShot) == 0x64);

const char *get_player_motion_filename(void);

// The player motion archive (PlyMotionData.rlc) lives in auxiliary RAM. Only its header and
// directory stay in main memory; motions are read back from ARAM one entry at a time.
struct PlayerMotionAramEntry {
    s32 aram_addr;
    s32 size;

    void clear();
    void set_size(s32 v);
    void set_aram_addr(s32 v);
    s32 get_aram_addr();
    s32 get_size();
};

LAYOUT_ASSERT(PlayerMotionAramEntry_size, sizeof(PlayerMotionAramEntry) == 8);

extern RlcArchive *player_motion_archive;
extern RlcHeader *player_motion_directory;
extern s32 player_motion_directory_size;
extern s32 player_motion_aram_addr;
extern int player_motion_aram_size;

// The directory buffer holds the archive header and up to get_player_motion_max_entries() entries.
int get_rlc_header_size();
int get_rlc_directory_entry_size();
int get_player_motion_max_entries();

void free_player_motion_directory();
s32 copy_player_motion_directory();
void alloc_player_motion_directory();
void get_player_motion_entry(s32 index, PlayerMotionAramEntry *entry);
void read_player_motion(s32 aram_addr, void *dest, s32 size);
void upload_player_motion_data();
void alloc_player_motion_aram();
s32 load_player_motion_data(void);
void free_player_motion_archive();

// window_snapshot_layout_entries, the layout table window_snapshot_layout points at
// (a sprite part and a text line).
struct SnapShotWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
};


#endif
