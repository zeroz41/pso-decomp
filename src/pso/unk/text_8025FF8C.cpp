#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8025CB70.h"
#include "pso/unk/text_8025FF8C.h"
#include "pso/ui/Language.h"

void fn_8025FF8C(void *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x70) != 0U) {
        *(s32 *)((s8 *)arg0 + 0x60) = (s32) (*(s32 *)((s8 *)arg0 + 0x60) | 0x40);
        TKeyBoardControl__sub_8025CC3C((void *)(*(u32 *)((s8 *)arg0 + 0x70)));
        switch (current_language) {
        case LANGUAGE_JAPANESE:
        case LANGUAGE_ENGLISH:
            break;
        case LANGUAGE_GERMAN:
        case LANGUAGE_FRENCH:
        case LANGUAGE_SPANISH:
            *(s32 *)((s8 *)arg0 + 0x6C) = 7;
            break;
        }
    }
}
