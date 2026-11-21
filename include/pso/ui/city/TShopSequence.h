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
    s32 get_child_field1c();
    u32 create_message_window(s32, s32);
    void close_message_window();
    virtual void vfunc_6(s32 id, s32 flags);
    virtual void display_message(const char *text, s32 flags);
    virtual void vfunc_8(s32 id, s32 flags);
    virtual void display_guild_message(s32 index, s32 flags);
    virtual int vfunc_10();
    void close_if_single_screen(); // every caller passes this in r3

    // 0x1C-0x27 are cleared by the TShopWindowBase ctor; they stay here until the
    // TShopWindowBase windows declare them there.
    u8 pad_1c[0x4];
    s32 state;                                  // 0x20: set_field_20, the vfunc_11 switch
    TObjPlayer *player;                         // 0x24: the player at the counter
    TMessageWindowController *message_window;   // 0x28: created by the ctor, deleted by the dtor
};

LAYOUT_ASSERT(TShopSequence_size, sizeof(TShopSequence) == 0x2C);

#endif
