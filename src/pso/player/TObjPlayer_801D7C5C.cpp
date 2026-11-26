#include "types.h"
#include "pso/player/TObjPlayer_801D84A8.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void TObjPlayer::update_party_cursors(TPlyDispConfigSmth *palette, TObjPlayer *player) {
    s32 i;
    gc_tag *tag;

    i = 0;
    do {
        tag = &palette->get_current_row()[i];
        if (player->is_palette_slot_enabled(i) == 0) {
            set_action_channel_inactive(tag);
        } else if (((TObjPlayer *)tag)->can_use_palette_action_for_entry(player) != 0) {
            set_action_channel_active(tag);
        } else {
            set_action_channel_inactive(tag);
        }
        i += 1;
    } while (i < 4);
}

}
