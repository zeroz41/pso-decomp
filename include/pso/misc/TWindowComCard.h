#ifndef PSO_MISC_TWINDOWCOMCARD_H
#define PSO_MISC_TWINDOWCOMCARD_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowComCard : public TWindowBase {
    virtual ~TWindowComCard();
    virtual void render();
    virtual void run_task();
    u8 _pad1C[0x8];
    void* m_24;
    u8 unk_28[0xC];
    s32 m_34;
    u8 unk_38[0x28];
    void set_display_value(s32 arg1, s32 arg2);
    static u8 *create_for_card(s32 arg0, s32 arg1, s32 arg2);
    static void *create(void *arg0, void *arg1);
    void*get_kbd_ptr();
    void set_help_mode(s32 arg1);
    void*get_card_name_ptr();
    void set_selected_index(s32 arg1);
};

typedef char TWindowComCard_size[sizeof(TWindowComCard) == 0x60 ? 1 : -1];
#endif
