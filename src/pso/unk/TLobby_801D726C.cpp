#include "types.h"
#include "pso/unk/TLobby_801D726C.h"
#include "pso/network/TLobby.h"

extern "C" {

u8 default_setting_18();

void fn_801D726C(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 0x1EU) {
        var_r4 = default_setting_18();
    }
    *(s16 *)((s8 *)arg0 + 0x18) = (s16) var_r4;
}

u8 default_setting_16();

void fn_801D72B0(void *arg0, s16 arg1) {
    s16 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 0xC8) {
        var_r4 = (s16) default_setting_16();
    }
    *(s16 *)((s8 *)arg0 + 0x16) = var_r4;
}

u8 default_setting_0E();

void set_field_0xE__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = default_setting_0E();
    }
    *(u8 *)((s8 *)arg0 + 0xE) = var_r4;
}

u8 default_setting_0D();

void set_field_d__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = default_setting_0D();
    }
    *(u8 *)((s8 *)arg0 + 0xD) = var_r4;
}

u8 default_setting_0C();

void set_clamped_field_c__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 3U) {
        var_r4 = default_setting_0C();
    }
    *(u8 *)((s8 *)arg0 + 0xC) = var_r4;
}

u8 default_setting_0B();

void set_field_b__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = default_setting_0B();
    }
    *(u8 *)((s8 *)arg0 + 0xB) = var_r4;
}

u8 default_setting_0A();

void set_field_a__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = default_setting_0A();
    }
    *(u8 *)((s8 *)arg0 + 0xA) = var_r4;
}

u8 default_setting_09();

void set_byte9_clamped__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = default_setting_09();
    }
    *(u8 *)((s8 *)arg0 + 9) = var_r4;
}

u8 default_setting_08();

void set_difficulty__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = default_setting_08();
    }
    *(u8 *)((s8 *)arg0 + 8) = var_r4;
}

u8 default_setting_07();

void set_field7_clamped__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 3U) {
        var_r4 = default_setting_07();
    }
    *(u8 *)((s8 *)arg0 + 7) = var_r4;
}

u8 default_setting_06();

void set_field_0x6__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = default_setting_06();
    }
    *(u8 *)((s8 *)arg0 + 6) = var_r4;
}

u8 default_setting_05();

void set_field_5__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = default_setting_05();
    }
    *(u8 *)((s8 *)arg0 + 5) = var_r4;
}

u8 default_setting_04();

void set_clamped_field_4__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 3U) {
        var_r4 = default_setting_04();
    }
    *(u8 *)((s8 *)arg0 + 4) = var_r4;
}

u8 default_setting_03();

void set_field_3__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 2U) {
        var_r4 = default_setting_03();
    }
    *(u8 *)((s8 *)arg0 + 3) = var_r4;
}

u8 default_setting_02();

void set_field_2__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 4U) {
        var_r4 = default_setting_02();
    }
    *(u8 *)((s8 *)arg0 + 2) = var_r4;
}

u8 default_setting_01();

void set_validated_field_0x1__6TLobbyFPvUc(void *arg0, u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 >= 3U) {
        var_r4 = default_setting_01();
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
    s32 k;

    ((s32 (*)(void *, s32)) set_section_id__6TLobbyFPvUc)(arg0, ((s32 (*)()) TItemDrop__sub_80107B04)());
    ((s32 (*)(void *, s32)) set_validated_field_0x1__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_01)(arg0));
    ((s32 (*)(void *, s32)) set_field_2__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_02)(arg0));
    ((s32 (*)(void *, s32)) set_field_3__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_03)(arg0));
    ((s32 (*)(void *, s32)) set_clamped_field_4__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_04)(arg0));
    ((s32 (*)(void *, s32)) set_field_5__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_05)(arg0));
    ((s32 (*)(void *, s32)) set_field_0x6__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_06)(arg0));
    ((s32 (*)(void *, s32)) set_field7_clamped__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_07)(arg0));
    ((s32 (*)(void *, s32)) set_difficulty__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_08)(arg0));
    ((s32 (*)(void *, s32)) set_byte9_clamped__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_09)(arg0));
    ((s32 (*)(void *, s32)) set_field_a__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_0A)(arg0));
    ((s32 (*)(void *, s32)) set_field_b__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_0B)(arg0));
    ((s32 (*)(void *, s32)) set_clamped_field_c__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_0C)(arg0));
    ((s32 (*)(void *, s32)) set_field_d__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_0D)(arg0));
    ((s32 (*)(void *, s32)) set_field_0xE__6TLobbyFPvUc)(arg0, ((s32 (*)(void *)) default_setting_0E)(arg0));
    this->set_volume(0);
    this->set_max_tech_level(0xFF);
    this->set_clamped_index(0);
    this->set_clamped_value_1c(0xA);
    *(s8 *)((s8 *)arg0 + 0x12) = 0;
    for (k = 0; k < 4; k++) {
        *(arg0 + k + 0x20) = 0x14;
    }
    *(s8 *)((s8 *)arg0 + 0xF) = 0;
}

}
