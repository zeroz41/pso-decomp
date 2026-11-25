#include "types.h"
#include "pso/unk/TLobby_801D726C.h"
#include "pso/network/TLobby.h"
#include "pso/system/data/pso_const_ids4.h"
#include "pso/item/drop/TItemDrop.h"

extern "C" {

void fn_801D726C(void *rules, u8 value) {
    if (value >= 0x1E) {
        value = default_setting_18(rules);
    }
    *(s16 *)((s8 *)rules + 0x18) = value;
}

void fn_801D72B0(void *rules, s16 value) {
    if (value >= 0xC8) {
        value = default_setting_16(rules);
    }
    *(s16 *)((s8 *)rules + 0x16) = value;
}

}

void TLobby::set_field_0xE(void *rules, u8 value) {
    if (value >= 2) {
        value = default_setting_0E(rules);
    }
    *(u8 *)((s8 *)rules + 0xE) = value;
}

void TLobby::set_field_d(void *rules, u8 value) {
    if (value >= 2) {
        value = default_setting_0D(rules);
    }
    *(u8 *)((s8 *)rules + 0xD) = value;
}

void TLobby::set_clamped_field_c(void *rules, u8 value) {
    if (value >= 3) {
        value = default_setting_0C(rules);
    }
    *(u8 *)((s8 *)rules + 0xC) = value;
}

void TLobby::set_field_b(void *rules, u8 value) {
    if (value >= 2) {
        value = default_setting_0B(rules);
    }
    *(u8 *)((s8 *)rules + 0xB) = value;
}

void TLobby::set_field_a(void *rules, u8 value) {
    if (value >= 2) {
        value = default_setting_0A(rules);
    }
    *(u8 *)((s8 *)rules + 0xA) = value;
}

void TLobby::set_byte9_clamped(void *rules, u8 value) {
    if (value >= 2) {
        value = default_setting_09(rules);
    }
    *(u8 *)((s8 *)rules + 9) = value;
}

void TLobby::set_difficulty(void *rules, u8 value) {
    if (value >= 2) {
        value = default_setting_08(rules);
    }
    *(u8 *)((s8 *)rules + 8) = value;
}

void TLobby::set_field7_clamped(void *rules, u8 value) {
    if (value >= 3) {
        value = default_setting_07(rules);
    }
    *(u8 *)((s8 *)rules + 7) = value;
}

void TLobby::set_field_0x6(void *rules, u8 value) {
    if (value >= 2) {
        value = default_setting_06(rules);
    }
    *(u8 *)((s8 *)rules + 6) = value;
}

void TLobby::set_field_5(void *rules, u8 value) {
    if (value >= 2) {
        value = default_setting_05(rules);
    }
    *(u8 *)((s8 *)rules + 5) = value;
}

void TLobby::set_clamped_field_4(void *rules, u8 value) {
    if (value >= 3) {
        value = default_setting_04(rules);
    }
    *(u8 *)((s8 *)rules + 4) = value;
}

void TLobby::set_field_3(void *rules, u8 value) {
    if (value >= 2) {
        value = default_setting_03(rules);
    }
    *(u8 *)((s8 *)rules + 3) = value;
}

void TLobby::set_field_2(void *rules, u8 value) {
    if (value >= 4) {
        value = default_setting_02(rules);
    }
    *(u8 *)((s8 *)rules + 2) = value;
}

void TLobby::set_validated_field_0x1(void *rules, u8 value) {
    if (value >= 3) {
        value = default_setting_01(rules);
    }
    *(u8 *)((s8 *)rules + 1) = value;
}

void TLobby::set_section_id(void *rules, u8 value) {
    if (value >= 2) {
        value = TItemDrop__sub_80107B04(rules);
    }
    *(u8 *)rules = value;
}

void TLobby::reset_settings_to_default() {
    u8 *rules = (u8 *)this;
    s32 k;

    set_section_id(this, TItemDrop__sub_80107B04(this));
    set_validated_field_0x1(this, default_setting_01(this));
    set_field_2(this, default_setting_02(this));
    set_field_3(this, default_setting_03(this));
    set_clamped_field_4(this, default_setting_04(this));
    set_field_5(this, default_setting_05(this));
    set_field_0x6(this, default_setting_06(this));
    set_field7_clamped(this, default_setting_07(this));
    set_difficulty(this, default_setting_08(this));
    set_byte9_clamped(this, default_setting_09(this));
    set_field_a(this, default_setting_0A(this));
    set_field_b(this, default_setting_0B(this));
    set_clamped_field_c(this, default_setting_0C(this));
    set_field_d(this, default_setting_0D(this));
    set_field_0xE(this, default_setting_0E(this));
    this->set_volume(0);
    this->set_max_tech_level(0xFF);
    this->set_clamped_index(0);
    this->set_clamped_value_1c(0xA);
    *(s8 *)(rules + 0x12) = 0;
    for (k = 0; k < 4; k++) {
        *(rules + k + 0x20) = 0x14;
    }
    *(s8 *)(rules + 0xF) = 0;
}
