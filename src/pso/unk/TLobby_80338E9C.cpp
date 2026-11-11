#include "types.h"
#include "pso/unk/TLobby_80338E9C.h"
#include "pso/unk/text_80338F3C.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

extern "C" {

void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void *TLobby::create_object(void *arg0) {
    void *o = __nw__7TObjectFUl(0x8C);
    if (o != NULL) {
        o = fn_80338F3C((u8 *)o, (s32)arg0);
    }
    return o;
}

struct RecoveredGlobal_80338F3C_lbl_804EF4E0 {
    s32 value;
    u8 remaining[0x1C];
};
extern RecoveredGlobal_80338F3C_lbl_804EF4E0 lbl_804EF4E0;
typedef char RecoveredGlobal_80338F3C_lbl_804EF4E0_size[sizeof(RecoveredGlobal_80338F3C_lbl_804EF4E0) == 0x20 ? 1 : -1];

void *__dt__13TUnk_804EF4E0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804EF4E0.value;
        ((TWindowSubStatusDisp *)arg0)->deleting_dtor(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

struct RecoveredGlobal_80338F3C_lbl_804EF4CC {
    s32 value;
    u8 remaining[0x10];
};


extern "C" {
u8 * get_window_layout_position(s32);
extern RecoveredGlobal_80338F3C_lbl_804EF4CC lbl_804EF4CC;
typedef char RecoveredGlobal_80338F3C_lbl_804EF4CC_size[sizeof(RecoveredGlobal_80338F3C_lbl_804EF4CC) == 0x14 ? 1 : -1];
u8 *fn_80338F3C(u8 *window_sub_status_disp, s32 arg1) {
    ((TWindowSubStatusDisp *)window_sub_status_disp)->ct_helper((s32)((int) (get_window_layout_position(0xB0))), arg1, 0x40, (s32)&lbl_804EF4CC.value);
    *(s32 **)((s8 *)window_sub_status_disp + 0x18) = &lbl_804EF4E0.value;
    return window_sub_status_disp;
}

}
