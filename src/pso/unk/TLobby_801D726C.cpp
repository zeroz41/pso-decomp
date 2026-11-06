#include "types.h"
#include "pso/unk/TLobby_801D726C.h"
#include "pso/unk/TLobby.h"

extern "C" {

u8 ret_801D78E4();

void fn_801D726C(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 0x1EU) {
        var_r4 = ret_801D78E4();
    }
    *(s16 *)((s8 *)arg0 + 0x18) = (s16) var_r4;
}

u8 ret_801D78EC();

void fn_801D72B0(void *arg0, s16 arg1) {
    s16 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 0xC8) {
        var_r4 = (s16) ret_801D78EC();
    }
    *(s16 *)((s8 *)arg0 + 0x16) = var_r4;
}

u8 ret_801D78F4();

void set_field_0xE__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = ret_801D78F4();
    }
    *(u8 *)((s8 *)arg0 + 0xE) = var_r4;
}

u8 ret_801D78FC();

void set_field_d__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = ret_801D78FC();
    }
    *(u8 *)((s8 *)arg0 + 0xD) = var_r4;
}

u8 ret_801D7904();

void set_clamped_field_c__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 3U) {
        var_r4 = ret_801D7904();
    }
    *(u8 *)((s8 *)arg0 + 0xC) = var_r4;
}

u8 ret_801D790C();

void set_field_b__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = ret_801D790C();
    }
    *(u8 *)((s8 *)arg0 + 0xB) = var_r4;
}

u8 ret_801D7914();

void set_field_a__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = ret_801D7914();
    }
    *(u8 *)((s8 *)arg0 + 0xA) = var_r4;
}

u8 ret_801D791C();

void set_byte9_clamped__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = ret_801D791C();
    }
    *(u8 *)((s8 *)arg0 + 9) = var_r4;
}

u8 ret_801D7924();

void set_difficulty__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = ret_801D7924();
    }
    *(u8 *)((s8 *)arg0 + 8) = var_r4;
}

u8 ret_801D792C();

void set_field7_clamped__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 3U) {
        var_r4 = ret_801D792C();
    }
    *(u8 *)((s8 *)arg0 + 7) = var_r4;
}

u8 ret_801D7934();

void set_field_0x6__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = ret_801D7934();
    }
    *(u8 *)((s8 *)arg0 + 6) = var_r4;
}

u8 ret_801D793C();

void set_field_5__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = ret_801D793C();
    }
    *(u8 *)((s8 *)arg0 + 5) = var_r4;
}

u8 ret_801D7944();

void set_clamped_field_4__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 3U) {
        var_r4 = ret_801D7944();
    }
    *(u8 *)((s8 *)arg0 + 4) = var_r4;
}

u8 ret_801D794C();

void set_field_3__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = ret_801D794C();
    }
    *(u8 *)((s8 *)arg0 + 3) = var_r4;
}

u8 ret_801D7954();

void set_field_2__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 4U) {
        var_r4 = ret_801D7954();
    }
    *(u8 *)((s8 *)arg0 + 2) = var_r4;
}

u8 ret_801D795C();

void set_validated_field_0x1__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 3U) {
        var_r4 = ret_801D795C();
    }
    *(u8 *)((s8 *)arg0 + 1) = var_r4;
}

u8 TItemDrop__sub_80107B04();

void set_section_id__6TLobbyFPvUc(u8 *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = TItemDrop__sub_80107B04();
    }
    *arg0 = var_r4;
}

void TLobby::reset_settings_to_default() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 var_ctr;
    s32 var_r4;

    ((s32 (*)(void *, s32)) set_section_id__6TLobbyFPvUc)(arg0, ((s32 (*)()) TItemDrop__sub_80107B04)());
    ((s32 (*)(void *, s32)) set_validated_field_0x1__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D795C)(arg0));
    ((s32 (*)(void *, s32)) set_field_2__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D7954)(arg0));
    ((s32 (*)(void *, s32)) set_field_3__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D794C)(arg0));
    ((s32 (*)(void *, s32)) set_clamped_field_4__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D7944)(arg0));
    ((s32 (*)(void *, s32)) set_field_5__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D793C)(arg0));
    ((s32 (*)(void *, s32)) set_field_0x6__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D7934)(arg0));
    ((s32 (*)(void *, s32)) set_field7_clamped__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D792C)(arg0));
    ((s32 (*)(void *, s32)) set_difficulty__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D7924)(arg0));
    ((s32 (*)(void *, s32)) set_byte9_clamped__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D791C)(arg0));
    ((s32 (*)(void *, s32)) set_field_a__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D7914)(arg0));
    ((s32 (*)(void *, s32)) set_field_b__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D790C)(arg0));
    ((s32 (*)(void *, s32)) set_clamped_field_c__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D7904)(arg0));
    ((s32 (*)(void *, s32)) set_field_d__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D78FC)(arg0));
    ((s32 (*)(void *, s32)) set_field_0xE__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) ret_801D78F4)(arg0));
    ((TLobby *)arg0)->set_volume(0);
    ((TLobby *)arg0)->set_validated_field_0x11(0xFF);
    ((TLobby *)arg0)->set_clamped_index(0);
    ((TLobby *)arg0)->set_clamped_value_1c(0xA);
    *(s8 *)((s8 *)arg0 + 0x12) = 0;
    for (var_r4 = 0; var_r4 < 4; var_r4++) {
        *(arg0 + var_r4 + 0x20) = 0x14;
    }
    *(s8 *)((s8 *)arg0 + 0xF) = 0;
}

}
