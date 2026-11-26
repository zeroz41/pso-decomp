#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

int TAdSinglePlyChrSelectGC::get_game_mode() {  return chr_select_game_mode; }

s32 TAdSinglePlyChrSelectGC::is_both_confirmed() {
    s32 result;

    result = 0;
    if (((u8) *(u8 *)&this->m_name == 1) && ((u8) *(u8 *)((s8 *)this + 1) == 1)) {
        result = 1;
    }
    return (u8)((u8)result);
}
