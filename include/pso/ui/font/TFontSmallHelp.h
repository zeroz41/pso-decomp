#ifndef PSO_UI_FONT_TFONTSMALLHELP_H
#define PSO_UI_FONT_TFONTSMALLHELP_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>

struct NJS_TEXLIST;
extern NJS_TEXLIST *localized_alphabet_list;

struct HelpTextPlayerState {
    u8 unresolved_00[0x84C];
    Vec position;
    u8 unresolved_858[0x558];
    u32 identity;
};
LAYOUT_ASSERT(HelpTextPlayerPosition, offsetof(HelpTextPlayerState, position) == 0x84C);
LAYOUT_ASSERT(HelpTextPlayerIdentity, offsetof(HelpTextPlayerState, identity) == 0xDB0);

class TFontSmallHelp : public TObject {
public:
    Vec position;
    u32 owner_identity;
    f32 text_width;
    char text[32];
    u32 color;
    s32 age_ticks;
    s32 lifetime_ticks;
    u32 player_id;

    TFontSmallHelp(u32 player, u32 text_color, s32 lifetime, uaddr text_id);
    virtual ~TFontSmallHelp();
    virtual void run_task();
    virtual void render();

    void set_color(u32 text_color);
    void set_help_text(const char *text_source);
public:
};

#include <stddef.h>
LAYOUT_ASSERT(TFontSmallHelpSize, sizeof(TFontSmallHelp) == 0x60);
LAYOUT_ASSERT(TFontSmallHelpPosition, offsetof(TFontSmallHelp, position) == 0x1C);
LAYOUT_ASSERT(TFontSmallHelpOwner, offsetof(TFontSmallHelp, owner_identity) == 0x28);
LAYOUT_ASSERT(TFontSmallHelpWidth, offsetof(TFontSmallHelp, text_width) == 0x2C);
LAYOUT_ASSERT(TFontSmallHelpText, offsetof(TFontSmallHelp, text) == 0x30);
LAYOUT_ASSERT(TFontSmallHelpColor, offsetof(TFontSmallHelp, color) == 0x50);
LAYOUT_ASSERT(TFontSmallHelpAge, offsetof(TFontSmallHelp, age_ticks) == 0x54);
LAYOUT_ASSERT(TFontSmallHelpLifetime, offsetof(TFontSmallHelp, lifetime_ticks) == 0x58);
LAYOUT_ASSERT(TFontSmallHelpPlayer, offsetof(TFontSmallHelp, player_id) == 0x5C);

#endif
