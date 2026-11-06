#include "types.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/quest/TQuestListVM.h"

int TWindowMenu::is_cancelled() { return (this->m_70 >> 2) & 0x1; }
