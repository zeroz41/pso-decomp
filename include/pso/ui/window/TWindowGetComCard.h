#ifndef PSO_UI_WINDOW_TWINDOWGETCOMCARD_H
#define PSO_UI_WINDOW_TWINDOWGETCOMCARD_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowGetComCard : public TObject {
    virtual ~TWindowGetComCard();
    virtual void run_task();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    virtual void render();
    static void remove_entry(s32 arg0, s32 arg1, s32 arg2);
    static void construct_card_tags();
};

typedef char TWindowGetComCard_size[sizeof(TWindowGetComCard) == 0x2C ? 1 : -1];

extern "C" {
void TWindowFukidasi__sub_80252C38(void *p);
u8 *TWindowGetComCard__ct(TWindowGetComCard *window_get_com_card);
void *__dt__17TWindowGetComCardFv(TWindowGetComCard *arg0, s16 arg1);
int fn_80252CBC(void *p);
}

// --- C functions defined in TWindowGetComCard.cpp ---
extern "C" {
void TWindowFukidasi__sub_80252C38(void *p);
u8 *TWindowGetComCard__ct(TWindowGetComCard *window_get_com_card);
int fn_80252CBC(void *p);
}
// --- end of C functions

#endif
