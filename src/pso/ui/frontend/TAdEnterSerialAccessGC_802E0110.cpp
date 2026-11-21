#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"

void TAdSelectCurGC::lock_navigation() { navigation_locked = 1; }
