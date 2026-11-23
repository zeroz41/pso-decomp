#ifndef PSO_UI_FRONTEND_TADPLAYERLOADGC_H
#define PSO_UI_FRONTEND_TADPLAYERLOADGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct CardSaveDescriptor;

// One pending memory-card request per slot (A, B), stepped by update_card_requests.
struct CardRequestSlot {
    void *buffer;    // read/write data
    char name[0x20];
    char new_name[0x20]; // rename target
    s32 kind;        // 1 mount, 2 create, 3 open, 4 read, 5 write, 6 rename, 7 delete, 8 set attributes, 9 find file
    s32 step;        // state of the request's state machine
    s32 offset;      // read/write offset
    s32 length;      // read/write/create size
    s32 file_index;  // entry in the open-file table
    s32 status;      // 200 while pending, then 0 or a negative error
    s32 result;      // last CARD call's result
    s32 file_no;     // CARDSetAttributes file number
    u8 attr;         // CARDSetAttributes attributes
    u8 pad65[3];
};

extern CardRequestSlot load_request_slots[2];

// Memory-card watcher of the character-select screens: run_task steps through the probe,
// mount and file checks of slot A and, depending on mode, of slot B.
struct CardFileInfo;

class TAdPlayerLoadGC : public TObject {
public:
    TAdPlayerLoadGC(TObject *parent, int mode);
    // render is declared first: it is the class's key function, so the vtable is emitted
    // with it (ahead of run_task's switch table), as in the original data.
    virtual void render();
    virtual ~TAdPlayerLoadGC();
    virtual void run_task();
public:
    static s32 get_instance();
    static void set_state(int state);
    static void reset_load_state(s32 channel, u64 *serial_number);
    static void poll_card_load(s32 chan);
    static s32 check_card_result_code(s32 channel);
    static s32 probe_and_check_card(saddr chan);
    static void unmount_card_and_clear_flags(s32 channel, s32 result);
    static void load_banner_files();
    static s32 get_load_result(s32 channel);
    static s32 build_save_file_image(void *image, CardSaveDescriptor *file);
    static s32 probe_card_slot(saddr chan);
    static s32 find_card_file(saddr chan, const char *name);
    static s32 check_memcard_status(s32 chan);
    static s32 query_memcard_capacity(s32 channel, s32 unused);
    static s32 delete_memcard_file(s32 chan, const char *name);
    static s32 get_or_set_channel_flag(s32 arg0, s32 arg1);
    static s32 get_load_state();
    static void step_set_attributes(s32 card_channel);
    static void update_card_delete(s32 card_channel);
    static void update_card_rename(s32 card_channel);
    static void reset_slot_entry(s32 arg0);
    static s32 close_card_slot(s32 file_handle);
    static s32 take_card_read_result(s32 arg0, s32 *card_detail);
    static s32 request_card_read(s32 file, void *buffer, s32 length, s32 offset);
    static s32 take_card_open_result(s32 arg0, s32 *card_detail);
    static s32 begin_card_file_request(s32 chan, const char *name);
    static void unmount_card(s32 chan);
    static s32 take_card_mount_result(s32 arg0, s32 *card_detail);
    static s32 take_card_find_result(s32 card_channel, s32 *card_detail);
public:
    static s32 request_card_find(s32 card_channel, const char *arg1);
    static s32 get_card_file_info(s32 channel, const char *name, CardFileInfo *info);
    // Defined at the end of TAdChrSelASlotGC.cpp, its only user (the original's last function there).
    s32 get_slot_index();

    u32 state;
    int mode; // 0, 1 or 2, given by the creator; from state 12 on, mode 1 also watches slot B
};
LAYOUT_ASSERT(TAdPlayerLoadGCExtent, sizeof(TAdPlayerLoadGC) == 0x24);

int get_player_load_state(void);
void set_character_select_b_slot_state(int a0);

// --- C functions defined in TAdPlayerLoadGC.cpp ---
extern "C" {
void *__dt__13TUnk_804E24F0Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
