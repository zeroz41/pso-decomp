#ifndef PSO_UI_CHARCREATE_CHARACTERLOADBUFFER_H
#define PSO_UI_CHARCREATE_CHARACTERLOADBUFFER_H

#include "types.h"

extern u8 *chr_select_load_buffer_base;
extern u8 *chr_select_load_buffer;
uaddr reset_character_load_buffer(s32 slot);
uaddr advance_character_load_buffer(s32 slot, s32 size);
void *get_character_load_buffer(s32 slot);

void alloc_quest_download_buffer(void);
void destroy_character_creation_effects(void);
void create_character_creation_effects(void);

class TChCrEffWall;
class TChCrEffTag;
class TChCrEffCtrlPl;

struct CharacterCreationEffects {
    TChCrEffWall *wall;
    TChCrEffTag *heading;
    TChCrEffCtrlPl *controller_plate;
};
LAYOUT_ASSERT(CharacterCreationEffectsSize, sizeof(CharacterCreationEffects) == 0xC);
extern CharacterCreationEffects character_creation_effects;

void check_load_buffer_slot_stub(s32 i);
void free_single_player_chr_select();
void alloc_download_server();
void free_chr_select_singleton();

#endif
