#ifndef PSO_SYSTEM_SAVE_TSAVECHCR_H
#define PSO_SYSTEM_SAVE_TSAVECHCR_H

#include "pso/system/task/TObject.h"
#include "types.h"

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
    u8 unk_30[0x4];
    void * m_34;
    s32 timer;
    TObject *owned_window;

public:
    void close_and_advance(void* a1);
    void set_message_by_index(s32 arg1);
    void open_message_window(u32 arg1);
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
    void set_state(s32 arg1);
    static void *create(void *arg0);
};

typedef void (TSaveChCr::*TSaveChCrStateAction)();
struct TSaveChCrStateActions {
    TSaveChCrStateAction first;
    TSaveChCrStateAction task;
};

#include <stddef.h>
typedef char SaveChCrSize[sizeof(TSaveChCr) == 0x40 ? 1 : -1];
typedef char TSaveChCr_owned_window_offset[offsetof(TSaveChCr, owned_window) == 0x3c ? 1 : -1];
typedef char TSaveChCr_state_index_offset[offsetof(TSaveChCr, state_index) == 0x1c ? 1 : -1];
typedef char TSaveChCr_card_status_offset[offsetof(TSaveChCr, card_status) == 0x2c ? 1 : -1];
typedef char TSaveChCr_timer_offset[offsetof(TSaveChCr, timer) == 0x38 ? 1 : -1];
typedef char TSaveChCrActionSize[sizeof(TSaveChCrStateAction) == 12 ? 1 : -1];
typedef char TSaveChCrEntrySize[sizeof(TSaveChCrStateActions) == 24 ? 1 : -1];
typedef char TSaveChCrStateTaskOffset[offsetof(TSaveChCrStateActions, task) == 12 ? 1 : -1];

#endif
