#ifndef PSO_UI_FRONTEND_TADPLAYERLOADGC_H
#define PSO_UI_FRONTEND_TADPLAYERLOADGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

// One pending memory-card request per slot (A, B), stepped by TAdPlayerLoadGC::poll_card_load.
struct CardRequestSlot {
    s32 buffer;      // read/write data
    char name[0x20];
    char new_name[0x20]; // rename target
    s32 kind;        // 1 mount, 2 create, 3 open, 4 read, 5 write, 6 rename, 7 delete, 8 set attributes, 9 check
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

// Memory-card watcher of the character-select screens: run_task steps through the probe,
// mount and file checks of slot A and, depending on mode, of slot B.
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
    static void set_state(int a0);
    static void reset_load_state(void *arg0, void *arg1);
    static void poll_card_load(s32 arg0);
    s32 check_card_result_code();
    static s32 probe_and_check_card(s32 chan);
    static void unmount_card_and_clear_flags(s32 n);
    static void load_banner_files();
    static s32 get_load_result(void * _w0);
    static s32 build_save_file_image(void *image, void *desc);
    static s32 probe_card_slot(s32 chan);
    static s32 find_card_file(s32 chan, const char *name);
    static s32 check_memcard_status(s32 arg0);
    static s32 query_memcard_capacity(s32 arg0);
    static s32 poll_load_status(s32 arg0);
    u8 *create_instance();
    static s32 get_or_set_channel_flag(s32 arg0, s32 arg1);
    static s32 get_load_state();
    static void step_set_attributes(s32 arg0);
    static void update_card_delete(s32 arg0);
    static void update_card_rename(s32 arg0);
    static void reset_slot_entry(s32 arg0);
    static s32 close_card_slot(s32 arg0);
    static s32 finish_load_slot_state4(s32 arg0, s32 *arg1);
    static s32 queue_network_request(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static s32 finish_load_slot_state3(s32 arg0, s32 *arg1);
    static s32 begin_card_file_request(s32 chan, const char *name);
    static void unmount_card(s32 chan);
    static s32 take_network_info_load_result(s32 arg0, s32 *arg1);
    static s32 take_network_info_poll_result(s32 arg0, s32 *arg1);
public:
    static s32 request_card_open(s32 arg0, const char *arg1);

    u32 state;
    int mode; // 0, 1 or 2, given by the creator; from state 12 on, mode 1 also watches slot B
};
typedef char TAdPlayerLoadGCExtent[sizeof(TAdPlayerLoadGC) == 0x24 ? 1 : -1];

int get_player_load_state(void);
void set_character_select_b_slot_state(int a0);

// --- C functions defined in TAdPlayerLoadGC.cpp ---
extern "C" {
void *__dt__13TUnk_804E24F0Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
