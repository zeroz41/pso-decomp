#include "types.h"
#include "pso/ui/window/TWindowMenuInfomation.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowChoiceSetting.h"

s16 TWindowChoiceSetting::get_field_74() { return this->index; }

int TWindowMenuInfomation::is_open() { return (this->m_70 >> 1) & 0x1; }
