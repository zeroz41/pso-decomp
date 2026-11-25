#include "types.h"
#include "pso/player/TPlyDispConfig.h"
#include "pso/ui/window/ActionPaletteTag.h"

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
