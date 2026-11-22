#ifndef PSO_SYSTEM_TMCFORMATSEQUENCE_H
#define PSO_SYSTEM_TMCFORMATSEQUENCE_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMenu;
struct TWindowMessagePage;

// Formats a memory card after asking for confirmation. Field names are inferred from their uses in
// TQuestVmDownLoadServer.cpp (the class's TU).
class TMCFormatSequence : public TObject {
public:
    void (*done_callback)(TMCFormatSequence *sequence);  // called in state 4: formatted, declined or cancelled
    void (*error_callback)(TMCFormatSequence *sequence); // called in state 3, after the error message
    s32 state;                                           // run_task's switch, 0-4
    s32 card_slot;                                       // the card channel probed and formatted
    s32 message_group;                                   // get_localized_text_entry(message_group, message_id):
    s32 message_id;                                      // the question open_windows shows
    TWindowMessagePage *message_window;
    TWindowMenu *confirm_menu;                           // init_shop_judgment_window's yes/no menu

    TMCFormatSequence(TObject *parent, s32 card_slot);
    virtual ~TMCFormatSequence();
    virtual void run_task();

    void close_window();
    void show_message(s32 text, s32 flags);
    void check_memcard_load_result();
    void process_format_result();
    void open_windows();
    void wait_confirm_and_finish();
    void update_wait_confirm();
};

#endif
