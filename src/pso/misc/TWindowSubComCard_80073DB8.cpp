#include "types.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/quest/TQuestListVM.h"

int TWindowMenu::is_cancelled() { return (this->m_70 >> 2) & 0x1; }
