#include "types.h"
#include "pso/player/TPlyDispConfig.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801D84A8.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/window/ActionPaletteTag.h"

s32 TPlyDispConfigSmth::find_action_slot_for_target(TObjPlayer *player, s16 type, s32 enabled) {
    return find_action_slot(player, type, enabled, TObjPlayer__sub_801D84A8(this));
}

s32 TPlyDispConfigSmth::find_action_slot(TObjPlayer *player, s16 type, s32 enabled, s32 row) {
    ActionPaletteTag *forced;
    s32 slot;
    ActionPaletteTag *tag;

    if (player != NULL && player->lock_on_cursor != NULL) {
        forced = &player->lock_on_cursor->palette_override;
        if (TObjPlayer__sub_801D84F0(forced) != 0) {
            if (get_action_palette_tag_mode(forced) == 1) {
                if (type == get_action_palette_tag_mode(forced)) {
                    return 0;
                }
            } else if (matches_type_and_enabled(forced, type, enabled) != 0) {
                return 0;
            }
        }
    }
    tag = get_row(row);
    slot = 0;
    do {
        if (get_action_palette_tag_mode(tag) == 1) {
            if (type == get_action_palette_tag_mode(tag)) {
                return slot;
            }
        } else if (matches_type_and_enabled(tag, type, enabled) != 0) {
            return slot;
        }
        slot++;
        tag++;
    } while (slot < 4);
    return -1;
}

int TPlyDispConfigSmth::is_bank_empty(s32 bank) {
    s32 i;
    ActionPaletteTag *tag;
    if (bank == 0) {
        tag = m_tags;
    } else {
        tag = m_tags1;
    }
    for (i = 0; i < 4; i++, tag++) {
        if (get_action_palette_tag_mode(tag) != 0) {
            return 0;
        }
    }
    return 1;
}
