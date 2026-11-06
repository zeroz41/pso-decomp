#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

    extern int chr_select_game_mode;
int TAdSinglePlyChrSelectGC::get_game_mode() {  return chr_select_game_mode; }

u8 TAdSinglePlyChrSelectGC::is_both_confirmed() {
    s32 var_r4;

    var_r4 = 0;
    if (((u8) *(u8 *)&this->m_name == 1) && ((u8) *(u8 *)((s8 *)this + 1) == 1)) {
        var_r4 = 1;
    }
    return (u8)var_r4;
}
