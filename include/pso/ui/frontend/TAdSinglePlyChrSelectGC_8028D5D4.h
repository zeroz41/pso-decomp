#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_8028D5D4_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_8028D5D4_H

#include "types.h"

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

void TLobby__sub_8028D7D0(s32 i);

#endif
