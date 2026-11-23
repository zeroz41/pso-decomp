#ifndef PSO_SYSTEM_SAVE_TSAVECHCR_H
#define PSO_SYSTEM_SAVE_TSAVECHCR_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMessage;
class TAdBackGC;
class TAdBackTxtGC;

class TSaveChCr : public TObject {
public:
    TSaveChCr(TObject *parent, s32 mode);
    virtual ~TSaveChCr();
    s32 poll_memcard_status();
    virtual void run_task();
    s32 state_index;
    // 0 saves the character; otherwise it is loaded back from the card.
    s32 mode;
    s32 m_24;
    s32 m_28;
    s32 card_status;
    TAdBackGC *backdrop;
    TAdBackTxtGC *backdrop_text;
    s32 timer;
    TWindowMessage *owned_window;

public:
    void close_and_advance(s32 message);
    void set_message_by_index(s32 message);
    void open_message_window(u32 text);
    void destroy_if_keyboard_idle();
    void save_if_dirty();
    void close_and_advance_to_3();
    void update_save_status();
    void close_and_advance_step2();
    void save_1();
    void update_save_state();
    void fn_80339D78();
    void sub_80339CE4();
    void sub_80339B94();
    s32 sub_80339DBC();
    s32 sub_80339F30();
    s32 sub_8033A138();
    void close_window();
    void create_backgrounds();
    s32 save_character();
    void set_state(s32 next_state);
    static TSaveChCr *create(s32 mode);
};

typedef void (TSaveChCr::*TSaveChCrStateAction)();
struct TSaveChCrStateActions {
    TSaveChCrStateAction first;
    TSaveChCrStateAction task;
};

#include <stddef.h>
LAYOUT_ASSERT(SaveChCrSize, sizeof(TSaveChCr) == 0x40);
LAYOUT_ASSERT(TSaveChCr_owned_window_offset, offsetof(TSaveChCr, owned_window) == 0x3c);
LAYOUT_ASSERT(TSaveChCr_state_index_offset, offsetof(TSaveChCr, state_index) == 0x1c);
LAYOUT_ASSERT(TSaveChCr_card_status_offset, offsetof(TSaveChCr, card_status) == 0x2c);
LAYOUT_ASSERT(TSaveChCr_timer_offset, offsetof(TSaveChCr, timer) == 0x38);
LAYOUT_ASSERT(TSaveChCrActionSize, sizeof(TSaveChCrStateAction) == 12);
LAYOUT_ASSERT(TSaveChCrEntrySize, sizeof(TSaveChCrStateActions) == 24);
LAYOUT_ASSERT(TSaveChCrStateTaskOffset, offsetof(TSaveChCrStateActions, task) == 12);


#endif
