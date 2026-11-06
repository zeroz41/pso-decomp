#include "types.h"
#include "pso/ui/frontend/TAdEndText_80399904.h"

struct RecoveredGlobal_8039994C_lbl_804F5800 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_80399904_lbl_804F5A00 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_80399928_lbl_804F5900 {
    s32 value;
    u8 remaining[0xFC];
};

extern RecoveredGlobal_8039994C_lbl_804F5800 lbl_804F5800;
extern RecoveredGlobal_80399904_lbl_804F5A00 lbl_804F5A00;
extern RecoveredGlobal_80399928_lbl_804F5900 lbl_804F5900;
typedef char RecoveredGlobal_8039994C_lbl_804F5800_size[sizeof(RecoveredGlobal_8039994C_lbl_804F5800) == 0x100 ? 1 : -1];

typedef char RecoveredGlobal_80399904_lbl_804F5A00_size[sizeof(RecoveredGlobal_80399904_lbl_804F5A00) == 0x100 ? 1 : -1];
u32 TAdEndText__sub_80399904(s32 arg0) {
    if (arg0 == -1) {
        return -1U;
    }
    return *(u8 *)((s8 *)((u8 *)&lbl_804F5A00.value + (u8) arg0) + 0);
}

typedef char RecoveredGlobal_80399928_lbl_804F5900_size[sizeof(RecoveredGlobal_80399928_lbl_804F5900) == 0x100 ? 1 : -1];
u32 TAdEndText__sub_80399928(s32 arg0) {
    if (arg0 == -1) {
        return -1U;
    }
    return *(u8 *)((s8 *)((u8 *)&lbl_804F5900.value + (u8) arg0) + 0);
}

s32 TAdEndText__sub_8039994C(u8 arg0) {
    return *(u8 *)((s8 *)((u8 *)&lbl_804F5800.value + arg0) + 0) & 0x40;
}
