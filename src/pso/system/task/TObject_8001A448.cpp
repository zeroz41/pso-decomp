#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/system/task/TObject.h"

void TObject::allow_rendering() {
    m_flags = (u16) (m_flags & 0xFFFFFFEF);
}

void TObject::disallow_rendering() {
    m_flags = (u16) (m_flags | 0x10);
}
