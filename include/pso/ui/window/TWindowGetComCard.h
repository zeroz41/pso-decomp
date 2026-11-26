#ifndef PSO_UI_WINDOW_TWINDOWGETCOMCARD_H
#define PSO_UI_WINDOW_TWINDOWGETCOMCARD_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/GuildCardEntry.h"

struct TWindowMenu;
struct TWindowMessage;

struct TWindowGetComCard : public TObject {
    static GuildCardEntry received_guild_card_tags[4];
    explicit TWindowGetComCard(TObject *parent);
    virtual ~TWindowGetComCard();
    virtual void run_task();
    TWindowMessage *message;
    TWindowMenu *confirmation;
    s32 state;
    s32 timer;
    virtual void render();

    static const char *class_name;
    static NJS_POINT2 window_rect; // where run_task opens the yes/no confirmation
};

LAYOUT_ASSERT(TWindowGetComCard_size, sizeof(TWindowGetComCard) == 0x2C);

// --- C functions defined in TWindowGetComCard.cpp ---
// --- end of C functions

void remove_guild_card_entry(s32 index, GuildCardEntry *entries, s32 count);

#endif
