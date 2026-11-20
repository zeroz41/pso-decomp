#include "types.h"
#include "versions.h"
#include "pso/ui/window/TWindowCtrl.h"

extern void *TWindowCtrl__active_window;

s32 TWindowCtrl::get_field24() {
    if ((void *) TWindowCtrl__active_window == NULL) {
        return -0x1600;
    }
    return *(s32 *)((s8 *)TWindowCtrl__active_window + 0x24);
}

#if VERSION == VERSION_GPOP8P
#include "pso/ui/Language.h"
#include "pso/unk/text_8042EAD4.h"
#include "pso/unk/text_80145A94.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
void fn_8042DF54(s32 language);

void fn_80145D2C(void) {
    DiscErrorTitles titles;

    switch (current_language) {
    case LANGUAGE_JAPANESE:
        fn_8042DF54(0);
        break;
    case LANGUAGE_ENGLISH:
        fn_8042DF54(0);
        break;
    case LANGUAGE_GERMAN:
        fn_8042DF54(1);
        break;
    case LANGUAGE_FRENCH:
        fn_8042DF54(2);
        break;
    case LANGUAGE_SPANISH:
        fn_8042DF54(3);
        break;
    default:
        fn_8042DF54(0);
        break;
    }
    titles = lbl_8043F21C;
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        fn_8042ED98(1, titles.titles[0]);
        fn_8042ED98(2, titles.titles[1]);
        break;
    case LANGUAGE_ENGLISH:
        fn_8042ED98(1, titles.titles[2]);
        fn_8042ED98(2, titles.titles[3]);
        break;
    case LANGUAGE_GERMAN:
        fn_8042ED98(1, titles.titles[4]);
        fn_8042ED98(2, titles.titles[5]);
        break;
    case LANGUAGE_FRENCH:
        fn_8042ED98(1, titles.titles[6]);
        fn_8042ED98(2, titles.titles[7]);
        break;
    case LANGUAGE_SPANISH:
        fn_8042ED98(1, titles.titles[8]);
        fn_8042ED98(2, titles.titles[9]);
        break;
    default:
        fn_8042ED98(1, titles.titles[2]);
        fn_8042ED98(2, titles.titles[3]);
        break;
    }
}
}
#endif
