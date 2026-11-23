#ifndef PSO_UI_WINDOW_TWINDOWGETCOMCARD_H
#define PSO_UI_WINDOW_TWINDOWGETCOMCARD_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct GuildCardEntry;
struct TWindowMenu;
struct TWindowMessage;

struct TWindowGetComCard : public TObject {
    explicit TWindowGetComCard(TObject *parent);
    virtual ~TWindowGetComCard();
    virtual void run_task();
    TWindowMessage *message;
    TWindowMenu *confirmation;
    s32 state;
    s32 timer;
    virtual void render();
    static void remove_entry(s32 index, GuildCardEntry *entries, s32 count);
    static void construct_card_tags();
};

LAYOUT_ASSERT(TWindowGetComCard_size, sizeof(TWindowGetComCard) == 0x2C);

extern "C" {
void TWindowFukidasi__sub_80252C38(void *p);
void *__dt__17TWindowGetComCardFv(TWindowGetComCard *arg0, s16 arg1);
int fn_80252CBC(void *p);
}

// --- C functions defined in TWindowGetComCard.cpp ---
extern "C" {
void TWindowFukidasi__sub_80252C38(void *p);
int fn_80252CBC(void *p);
}
// --- end of C functions

#endif
