#include "types.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"

extern "C" {

s32 close_window__14TAdScrollWinGCFv();

void TAdScrollWinGC::close() {
    close_window__14TAdScrollWinGCFv();
    this->m_4c = 1;
}

}
