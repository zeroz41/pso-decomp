#include "types.h"
#include "pso/object/TObjWarpLobby.h"
#include "pso/object/TObjWarpJungMain.h"
#include "pso/npc/TObjNpcEnemy.h"

extern "C" {
s32 debug_print_area_num__12TObjAreaWarpFv();
s32 debug_printf_at(s32, s32 *, ...);
extern s32 lbl_80446854[];
void TObjWarpJungMain::debug_print_area_num() {  }
void TObjWarpLobby::debug_print_area_num() {
    s32 base;
    debug_print_area_num__12TObjAreaWarpFv();
    if ((s32) this->set_params[1] < 0) {
        this->set_params[1] = 0;
    }
    if ((s32) this->set_params[1] > 1) {
        *(s32 *)&this->set_params[1] = 1;
    }
    switch (*(s32 *)&this->set_params[1]) {
    case 0:
        *(s32 *)((s8 *)this + 0xCC) = 1;
        break;
    case 1:
        *(s32 *)((s8 *)this + 0xCC) = 0;
        break;
    default:
        *(s32 *)((s8 *)this + 0xCC) = 1;
        break;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130021, lbl_80446854);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

}
