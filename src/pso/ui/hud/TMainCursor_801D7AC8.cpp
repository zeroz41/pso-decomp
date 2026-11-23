#include "types.h"
#include "pso/ui/hud/TMainCursor_8013DF5C.h"
#include "pso/player/TObjPlayer_801D84A8.h"
#include "pso/ui/hud/TMainCursor.h"

extern "C" {

s32 TWindowActionPalette__sub_801C1C68(s32, s32);

s32 TMainCursor::find_action_slot(s32 arg0, void *arg1, s16 type, s32 enabled, s32 arg4) {
    saddr first_tag;
    s32 slot;
    saddr tag;
    u32 bank_base;

    if (arg1 != NULL) {
        bank_base = *(u32 *)((s8 *)arg1 + 0x424);
        if (bank_base != 0U) {
            first_tag = bank_base + 0x520;
            if (TObjPlayer__sub_801D84F0((void *)first_tag) != 0) {
                if (get_action_palette_tag_mode(reinterpret_cast<const ActionPaletteTag *>(first_tag)) == 1) {
                    if (type == (s32) get_action_palette_tag_mode(reinterpret_cast<const ActionPaletteTag *>(first_tag))) {
                        return 0;
                    }
                    goto block_8;
                }
                if (matches_type_and_enabled(reinterpret_cast<const ActionPaletteTag *>(first_tag), (u8) type, (u8) enabled) != 0) {
                    return 0;
                }
                goto block_8;
            }
        }
    }
block_8:
    tag = TWindowActionPalette__sub_801C1C68(arg0, arg4);
    slot = 0;
loop_9:
    if (get_action_palette_tag_mode(reinterpret_cast<const ActionPaletteTag *>(tag)) == 1) {
        if (type == (s32) get_action_palette_tag_mode(reinterpret_cast<const ActionPaletteTag *>(tag))) {
            return slot;
        }
        goto block_14;
    }
    if (matches_type_and_enabled(reinterpret_cast<const ActionPaletteTag *>(tag), (u8) type, (u8) enabled) != 0) {
        return slot;
    }
block_14:
    slot += 1;
    tag += 4;
    if (slot >= 4) {
        return -1;
    }
    goto loop_9;
}

}
