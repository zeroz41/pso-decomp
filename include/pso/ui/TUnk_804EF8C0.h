#ifndef PSO_UI_TUNK_804EF8C0_H
#define PSO_UI_TUNK_804EF8C0_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Created under tl_01 by init_single_player_char_select_scene; run_task steps the single-player character
// select through a table of TAdSinglePlyChrSelectGC handlers indexed by state.
class TUnk_804EF8C0 : public TObject {
public:
    TUnk_804EF8C0();
    virtual ~TUnk_804EF8C0();
    void alloc_download_buffer();
    void clear_buffer();
    void free_buffer();
    virtual void run_task();
    s32 download_buffer_size;
    void *download_buffer;
    saddr chr_select_state;      // TAdSinglePlyChrSelectGC::get_chr_select_state() at construction
    s32 flag_count;            // TAdSinglePlyChrSelectGC::get_flag_count() at construction
    s32 state;                 // run_task's handler index
    s32 unk_30;
    s32 unk_34;
    TObject *message_window;   // TWindowMessage the handlers append lines to
    TObject *menu;
    TObject *check_memory_card; // TCheckMemoryCard::create
};
LAYOUT_ASSERT(TUnk_804EF8C0_size, sizeof(TUnk_804EF8C0) == 0x44);

#endif
