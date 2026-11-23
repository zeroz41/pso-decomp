#ifndef PSO_UI_CITY_TSHOPSEQUENCE_H
#define PSO_UI_CITY_TSHOPSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"

struct TObjPlayer;
class TMessageWindowController;

// Base of the city counter sequences (shops, bank, guild, medical centre, tekker).
struct TShopSequence : public TShopWindowBase {
    TShopSequence(TObject *parent);
    virtual ~TShopSequence();
    virtual void restore_player_state();
    virtual void close_window();
    u32 create_message_window(s32, s32);
    void close_message_window();
    virtual void display_shop_message(s32 id, s32 flags);
    virtual void display_message(const char *text, s32 flags);
    virtual void send_message(s32 id, s32 flags);
    virtual void display_guild_message(s32 index, s32 flags);
    virtual int is_message_ready();
    void close_if_single_screen(); // every caller passes this in r3

    TMessageWindowController *message_window;   // 0x28: created by the ctor, deleted by the dtor
};

LAYOUT_ASSERT(TShopSequence_size, sizeof(TShopSequence) == 0x2C);

#endif
