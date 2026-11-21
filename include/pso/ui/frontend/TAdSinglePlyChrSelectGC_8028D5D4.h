#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_8028D5D4_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_8028D5D4_H

#include "types.h"

void alloc_quest_download_buffer(void);
extern "C" {
void fn_8028D8F4(void);
void fn_8028D940(void);
}

class TChCrEffWall;
class TChCrEffTag;
class TChCrEffCtrlPl;

struct CharacterCreationEffects {
    TChCrEffWall *wall;
    TChCrEffTag *heading;
    TChCrEffCtrlPl *controller_plate;
};
LAYOUT_ASSERT(CharacterCreationEffectsSize, sizeof(CharacterCreationEffects) == 0xC);
extern CharacterCreationEffects lbl_8051C070;

#endif
