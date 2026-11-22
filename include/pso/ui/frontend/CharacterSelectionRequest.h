#ifndef PSO_UI_FRONTEND_CHARACTERSELECTIONREQUEST_H
#define PSO_UI_FRONTEND_CHARACTERSELECTIONREQUEST_H

#include <stddef.h>
#include "types.h"

struct CharacterSelectionRequest {
    s32 card_slots[4];
    s32 player_ids[4];
    u32 count;

    void clear_slot_lists();
    void reset_slot_lists();
};

LAYOUT_ASSERT(CharacterSelectionRequestSize, sizeof(CharacterSelectionRequest) == 0x24);
LAYOUT_ASSERT(CharacterSelectionRequestPlayerOffset, offsetof(CharacterSelectionRequest, player_ids) == 0x10);
LAYOUT_ASSERT(CharacterSelectionRequestCountOffset, offsetof(CharacterSelectionRequest, count) == 0x20);

extern "C" {
extern CharacterSelectionRequest chr_select_request_buffer;
void copy_selected_characters(const CharacterSelectionRequest *request);
void copy_character_selection_request(CharacterSelectionRequest *destination, const CharacterSelectionRequest *source);
}

#endif
