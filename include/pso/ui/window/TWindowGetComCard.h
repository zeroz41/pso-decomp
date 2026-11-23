#ifndef PSO_UI_WINDOW_TWINDOWGETCOMCARD_H
#define PSO_UI_WINDOW_TWINDOWGETCOMCARD_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

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

    static const char *class_name;
    static NJS_POINT2 window_rect; // where run_task opens the yes/no confirmation
};

LAYOUT_ASSERT(TWindowGetComCard_size, sizeof(TWindowGetComCard) == 0x2C);

// --- C functions defined in TWindowGetComCard.cpp ---
extern "C" {
void TWindowFukidasi__sub_80252C38(void *p);
int fn_80252CBC(void *p);
}
// --- end of C functions

#endif
