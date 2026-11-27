#include "types.h"
#include "pso/system/task/TObject.h"

void TObject::clear_update_suspension() {
    m_flags &= ~SUSPEND_UPDATE;
}
