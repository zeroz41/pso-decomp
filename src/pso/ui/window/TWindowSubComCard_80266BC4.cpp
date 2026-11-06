#include "types.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"

void TWindowMenu::reset_selection() { *(s16 *)&this->unk_7A = -1; }
