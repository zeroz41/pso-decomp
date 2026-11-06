#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjLuker.h"

void TObject::suspend_update() { this->m_flags |= 0x4; }
