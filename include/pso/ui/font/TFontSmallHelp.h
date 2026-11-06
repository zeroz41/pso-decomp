#ifndef PSO_UI_FONT_TFONTSMALLHELP_H
#define PSO_UI_FONT_TFONTSMALLHELP_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

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

    TFontSmallHelp(u32 player, u32 text_color, s32 lifetime, u32 text_id);
    virtual ~TFontSmallHelp();
    virtual void run_task();
    virtual void render();

    void set_color(u32 text_color);
    void set_help_text(const char *text_source);
public:
};

#include <stddef.h>
typedef char TFontSmallHelpSize[sizeof(TFontSmallHelp) == 0x60 ? 1 : -1];
typedef char TFontSmallHelpPosition[offsetof(TFontSmallHelp, position) == 0x1C ? 1 : -1];
typedef char TFontSmallHelpOwner[offsetof(TFontSmallHelp, owner_identity) == 0x28 ? 1 : -1];
typedef char TFontSmallHelpWidth[offsetof(TFontSmallHelp, text_width) == 0x2C ? 1 : -1];
typedef char TFontSmallHelpText[offsetof(TFontSmallHelp, text) == 0x30 ? 1 : -1];
typedef char TFontSmallHelpColor[offsetof(TFontSmallHelp, color) == 0x50 ? 1 : -1];
typedef char TFontSmallHelpAge[offsetof(TFontSmallHelp, age_ticks) == 0x54 ? 1 : -1];
typedef char TFontSmallHelpLifetime[offsetof(TFontSmallHelp, lifetime_ticks) == 0x58 ? 1 : -1];
typedef char TFontSmallHelpPlayer[offsetof(TFontSmallHelp, player_id) == 0x5C ? 1 : -1];

#endif
