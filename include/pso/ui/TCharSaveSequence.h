#ifndef PSO_UI_TCHARSAVESEQUENCE_H
#define PSO_UI_TCHARSAVESEQUENCE_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TCheckMemoryCard;
struct TWindowMenu;
struct TWindowMessage;

// Created under tl_01 by init_single_player_char_select_scene; run_task steps the single-player character
// select through a table of handlers indexed by state.
class TCharSaveSequence : public TObject {
public:
    TCharSaveSequence();
    virtual ~TCharSaveSequence();
    void alloc_download_buffer();
    void clear_buffer();
    void free_buffer();
    void report_missing_file();
    void queue_destruction();
    void handle_retry_menu();
    void handle_player_load();
    void update_setup();
    void check_memcard_space();
    void wait_character_file_write();
    void update_select_state();
    void handle_load_result();
    void start_character_read();
    void wait_card_check();
    void start_check_memory_card();
    void set_char_slots(s32 message, s32 sub_message);
    void close_window();
    void init_warp();
    void init_warps();
    void close_message_window();
    virtual void run_task();
    s32 download_buffer_size;
    void *download_buffer;
    saddr chr_select_state;      // TAdSinglePlyChrSelectGC::get_chr_select_state() at construction
    s32 flag_count;            // TAdSinglePlyChrSelectGC::get_flag_count() at construction
    s32 state;                 // run_task's handler index
    s32 unk_30;
    s32 unk_34;
    TWindowMessage *message_window; // the handlers append lines to it
    TWindowMenu *menu;
    TCheckMemoryCard *check_memory_card;
};
LAYOUT_ASSERT(TCharSaveSequence_size, sizeof(TCharSaveSequence) == 0x44);

extern "C" {
void TAdSinglePlyChrSelectGC__sub_8033B244(TObject *fade);
void TAdSinglePlyChrSelectGC__sub_8033B264(void);
}
void init_single_player_char_select_scene(void);
void seed_character_select_serial_rng(s32 arg0);

#endif
