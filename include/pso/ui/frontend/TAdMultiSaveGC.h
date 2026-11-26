#ifndef PSO_UI_FRONTEND_TADMULTISAVEGC_H
#define PSO_UI_FRONTEND_TADMULTISAVEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TWindowBase;
struct TWindowMenu;
struct TWindowMessage;
struct TWindowSubComCardList;

struct TAdMultiSaveGC : public TObject {
    static const char *class_name;
    TAdMultiSaveGC(TObject *parent);
    virtual ~TAdMultiSaveGC();
    virtual void render();
    virtual void run_task();
    u32 m_state; // run_task step (name inferred from the switch)
    // Window names inferred from the run_task step that opens each one.
    TWindowBase *no_card_window;     // step 0: slot A probe fails
    TWindowBase *card_status_window; // step 1: card status check fails
    TWindowBase *saving_window;      // step 4: opened after write_encrypted_save
    TWindowBase *load_error_window;  // step 2: system file or save load fails
    TWindowMenu *retry_menu;         // step 2/3: 1 leaves (step 8), 0 retries (step 0)
    static void queue_destruction(TObject *fade);
    TWindowSubComCardList *create_save_or_exit_menu();
    TWindowMessage *create_saving_message();
    TWindowMessage *create_card_status_message();
    TWindowMessage *create_load_error_message();
    TWindowMessage *create_no_card_message();
};

LAYOUT_ASSERT(TAdMultiSaveGC_size, sizeof(TAdMultiSaveGC) == 0x34);

#endif
