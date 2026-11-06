#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

s8 TWindowSubStatusDisp::get_type() { return *(s8 *)&this->m_name; }
