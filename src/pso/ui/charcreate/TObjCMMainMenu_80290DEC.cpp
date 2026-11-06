#include "types.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"

extern "C" {
void TCharaMaking__resolve_creation_sprite_table(u8 * *table, s32 *id);
s16 TObjCMMainMenu::get_creation_sprite_id(s32 arg0) {
    s32 spC;
    s32 sp8;
    sp8 = arg0;
    TCharaMaking__resolve_creation_sprite_table((u8 * *)(&spC), &sp8);
    return *(s16 *)((s8 *)(spC + (sp8 * 0x14)) + 0);
}

}
