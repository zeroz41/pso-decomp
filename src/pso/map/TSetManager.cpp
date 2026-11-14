#include "pso/map/TSetManager.h"
#include "types.h"

#pragma readonly_strings on

extern "C" {
extern "C" void apply_floor_set_rows__11TSetManagerFv();
extern "C" void update_decoration_spawning__11TSetManagerFv();
void *set_manager_task_pmf_table[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&apply_floor_set_rows__11TSetManagerFv,
};
void *lbl_804C9454[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_decoration_spawning__11TSetManagerFv,
};
void *lbl_804C9460[6] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
}
void TSetManager__sub_8020D7D4(void) {  }
typedef void (TSetManager::*Pmf_8020D7D8)();

void TSetManager::run_task() {
    static s8 init;
    if (!init) {
        ((Pmf_8020D7D8 *)lbl_804C9460)[0] = *(Pmf_8020D7D8 *)set_manager_task_pmf_table;
        ((Pmf_8020D7D8 *)lbl_804C9460)[1] = *(Pmf_8020D7D8 *)lbl_804C9454;
        init = 1;
    }
    (this->*((Pmf_8020D7D8 *)lbl_804C9460)[*(s32 *)((u8 *)this + 0x1C)])();
    ((void (*)(void *))TSetManager__sub_8020D7D4)(this);
}

TSetManager::~TSetManager() {}

extern "C" {

void __ct__7TObjectFP7TObject(void *, void *);

extern s32 __vt__11TSetManager[];
const char *lbl_805D3638 = "TSetManager";

void *TSetManager__ct(void *set_manager, void *parent) {
    __ct__7TObjectFP7TObject(set_manager, parent);
    *(s32 **)((s8 *)set_manager + 0x18) = __vt__11TSetManager;
    ((TSetManager *)set_manager)->m_name = lbl_805D3638;
    *(u32 *)((s8 *)set_manager + 0x1C) = 0;
    return set_manager;
}

}
