#include "types.h"
#include "pso/unk/TLobby_801D726C.h"
#include "pso/network/TLobby.h"
#include "pso/system/data/pso_const_ids4.h"
#include "pso/item/drop/TItemDrop.h"

extern "C" {

void fn_801D726C(void *rules, u8 value) {
    if (value >= 0x1E) {
        value = ret_801D78E4(rules);
    }
    *(s16 *)((s8 *)rules + 0x18) = value;
}

void fn_801D72B0(void *rules, s16 value) {
    if (value >= 0xC8) {
        value = ret_801D78EC(rules);
    }
    *(s16 *)((s8 *)rules + 0x16) = value;
}

}

void TLobby::set_field_0xE(void *rules, u8 value) {
    if (value >= 2) {
        value = ret_801D78F4(rules);
    }
    *(u8 *)((s8 *)rules + 0xE) = value;
}

void TLobby::set_field_d(void *rules, u8 value) {
    if (value >= 2) {
        value = ret_801D78FC(rules);
    }
    *(u8 *)((s8 *)rules + 0xD) = value;
}

void TLobby::set_clamped_field_c(void *rules, u8 value) {
    if (value >= 3) {
        value = ret_801D7904(rules);
    }
    *(u8 *)((s8 *)rules + 0xC) = value;
}

void TLobby::set_field_b(void *rules, u8 value) {
    if (value >= 2) {
        value = ret_801D790C(rules);
    }
    *(u8 *)((s8 *)rules + 0xB) = value;
}

void TLobby::set_field_a(void *rules, u8 value) {
    if (value >= 2) {
        value = ret_801D7914(rules);
    }
    *(u8 *)((s8 *)rules + 0xA) = value;
}

void TLobby::set_byte9_clamped(void *rules, u8 value) {
    if (value >= 2) {
        value = ret_801D791C(rules);
    }
    *(u8 *)((s8 *)rules + 9) = value;
}

void TLobby::set_difficulty(void *rules, u8 value) {
    if (value >= 2) {
        value = ret_801D7924(rules);
    }
    *(u8 *)((s8 *)rules + 8) = value;
}

void TLobby::set_field7_clamped(void *rules, u8 value) {
    if (value >= 3) {
        value = ret_801D792C(rules);
    }
    *(u8 *)((s8 *)rules + 7) = value;
}

void TLobby::set_field_0x6(void *rules, u8 value) {
    if (value >= 2) {
        value = ret_801D7934(rules);
    }
    *(u8 *)((s8 *)rules + 6) = value;
}

void TLobby::set_field_5(void *rules, u8 value) {
    if (value >= 2) {
        value = ret_801D793C(rules);
    }
    *(u8 *)((s8 *)rules + 5) = value;
}

void TLobby::set_clamped_field_4(void *rules, u8 value) {
    if (value >= 3) {
        value = ret_801D7944(rules);
    }
    *(u8 *)((s8 *)rules + 4) = value;
}

void TLobby::set_field_3(void *rules, u8 value) {
    if (value >= 2) {
        value = ret_801D794C(rules);
    }
    *(u8 *)((s8 *)rules + 3) = value;
}

void TLobby::set_field_2(void *rules, u8 value) {
    if (value >= 4) {
        value = ret_801D7954(rules);
    }
    *(u8 *)((s8 *)rules + 2) = value;
}

void TLobby::set_validated_field_0x1(void *rules, u8 value) {
    if (value >= 3) {
        value = ret_801D795C(rules);
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
    set_validated_field_0x1(this, ret_801D795C(this));
    set_field_2(this, ret_801D7954(this));
    set_field_3(this, ret_801D794C(this));
    set_clamped_field_4(this, ret_801D7944(this));
    set_field_5(this, ret_801D793C(this));
    set_field_0x6(this, ret_801D7934(this));
    set_field7_clamped(this, ret_801D792C(this));
    set_difficulty(this, ret_801D7924(this));
    set_byte9_clamped(this, ret_801D791C(this));
    set_field_a(this, ret_801D7914(this));
    set_field_b(this, ret_801D790C(this));
    set_clamped_field_c(this, ret_801D7904(this));
    set_field_d(this, ret_801D78FC(this));
    set_field_0xE(this, ret_801D78F4(this));
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
