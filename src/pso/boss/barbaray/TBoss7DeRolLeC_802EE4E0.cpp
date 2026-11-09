#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/boss/barbaray/TBoss7DeRolLeC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowCtrl.h"

struct RecoveredGlobal_802EE4E0_lbl_804E3C5C {
    s32 value;
    u8 remaining[0x2C];
};


extern "C" {
u8 * free_bin_model_request(void *, s16);
void call_funcs_reverse__6TLobbyFPvUi(s32, u32);
extern RecoveredGlobal_802EE4E0_lbl_804E3C5C lbl_804E3C5C;
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void run_load_callback_table(void *, int);
extern s32 lbl_804E3D1C[];
extern const f32 lbl_805DEA10;


typedef char RecoveredGlobal_802EE4E0_lbl_804E3C5C_size[sizeof(RecoveredGlobal_802EE4E0_lbl_804E3C5C) == 0x30 ? 1 : -1];
void TBoss7DeRolLeC::run_exit_callbacks() {
    call_funcs_reverse__6TLobbyFPvUi((s32) &lbl_804E3C5C.value, 0x30U);
    if ((void *) lbl_805D6918 != NULL) {
        free_bin_model_request(lbl_805D6918, 1);
        lbl_805D6918 = NULL;
    }
}

void *TBoss7DeRolLeC::create(void *arg0) {
    return new TBoss7DeRolLeC(tl_04, arg0);
}
void TObjPlayer__sub_802EE574(void) {
    s32 i;
    u8 *p;
    p = (u8 *)::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 1, lbl_804E3D1C, 0, 0, 0);
    }
    lbl_805D6918 = p;
    boss7_derolle_c_motion_id = 0;
    lbl_805D6920 = 0;
    lbl_805D6924 = 0;
    lbl_805D6928 = 0;
    lbl_805D692C = 0;
    lbl_805D6930 = 0;
    lbl_805D6934 = 0;
    boss7_joint_state = 0;
    run_load_callback_table(&lbl_804E3C5C.value, 0x30);
    lbl_805D693C = (u8 *)find_model_node(*(s32 *)((s8 *)(*(u8 **)((s8 *)lbl_805D6918 + 0x42C)) + 8), 0x4D);
    lbl_805D6940 = *(s32 **)((s8 *)lbl_805D693C + 0x2C);
    for (i = 0; i < 11; i++) {
        Light_802EE574 *l = &boss7_derolle_light_pool[i];
        l->type = 0xF;
        l->f4 = 0;
        l->f8 = lbl_805DEA10;
        l->fC = lbl_805DEA10;
        l->f10 = lbl_805DEA10;
        l->f14 = 0;
        l->f18 = 0;
        l->f1C = 0;
        l->f20 = lbl_805DEA10;
        l->f24 = lbl_805DEA10;
        l->f28 = lbl_805DEA10;
        l->next = 0;
        l->f30 = 0;
    }
    for (i = 0; i < 10; i++) {
        boss7_derolle_light_pool[i].next = &boss7_derolle_light_pool[i + 1];
    }
    {
        Light_802EE574 *t = &boss7_derolle_light_pool[10];
        t->type = 0x1F;
        t->next = 0;
    }
    TWindowCtrl::init_all_slots();
}

}

Light_802EE574 boss7_derolle_light_pool[11];
