#include "types.h"
#include "pso/unk/TLobby_801D6DC4.h"
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"

struct ClampValueBelow200Object { u8 pad[0x16]; s16 v; };

struct NormalizeBattleRuleValueObject { u8 pad[0xB]; u8 v; };

struct TLobbyObject { u8 pad[0xE]; u8 v; };

struct ClampValueBelow2Object { u8 pad[0xD]; u8 v; };

struct TLobbyObject2 { u8 pad[0xC]; u8 v; };

struct GetRuleFieldAObject { u8 pad[0xA]; u8 v; };

struct ClampRuleValue2Object { u8 pad[0x8]; u8 v; };

struct NormalizeBattleRuleValueBObject { u8 pad[0x9]; u8 v; };

struct TLobbyObject3 { u8 pad[0x7]; u8 v; };

extern "C" {
u8 default_setting_16(ClampValueBelow200Object *p);
u8 default_setting_0B(NormalizeBattleRuleValueObject *p);
u8 default_setting_0E(TLobbyObject *p);
u8 TLobby__sub_801D6F94(TLobbyObject *p);
u8 default_setting_0D(ClampValueBelow2Object *p);
u8 default_setting_0C(TLobbyObject2 *p);
u8 TLobby__sub_801D6FFC(TLobbyObject2 *p);
u8 default_setting_0A(GetRuleFieldAObject *p);
u8 default_setting_08(ClampRuleValue2Object *p);
u8 default_setting_09(NormalizeBattleRuleValueBObject *p);
u8 default_setting_07(TLobbyObject3 *p);
u8 TLobby__sub_801D7100(TLobbyObject3 *p);
u8 default_setting_18();

void TLobby::set_volume(u8 vol) {
    u8 value;

    value = vol;
    if (value > 0x63U) {
        value = 0;
    }
    *(u8 *)&this->m_up = value;
}

u8 TLobby__sub_801D6DDC(void *record) {
    u8 v;
    s32 t;
    t = *(u8 *)((s8 *)record + 0x11);
    v = t;
    if (TObjPlayer::is_invalid_slot(t) == 0 && v > 0x1DU) {
        v = 0;
    }
    return v;
}

void TLobby::set_max_tech_level(u8 level) {
    u8 max_level;

    max_level = level;
    if ((TObjPlayer::is_invalid_slot(max_level) == 0) && (max_level > 0x1DU)) {
        max_level = 0;
    }
    *(u8 *)((s8 *)this + 0x11) = max_level;
}

s16 TLobby::clamp_player_index() {
    s16 index;

    index = *(s16 *)&this->m_down;
    if ((index < 0) || (index > TObjPlayer::get_max_level())) {
        index = 0;
    }
    return index;
}

void TLobby::set_clamped_index(s16 level) {
    s16 down;

    down = level;
    if ((down < 0) || (down > TObjPlayer::get_max_level())) {
        down = 0;
    }
    *(s16 *)&this->m_down = down;
}

void TLobby::set_clamped_value_1c(s32 value) {
    s32 clamped;

    clamped = value;
    if ((clamped < 0) || (clamped > 0x278D0)) {
        clamped = 0;
    }
    *(s32 *)((s8 *)this + 0x1C) = clamped;
}

u8 TLobby::get_clamped_level() {
    s16 level;

    level = *(s16 *)((s8 *)this + 0x18);
    if (level >= 0x1E) {
        return default_setting_18();
    }
    return (u8) level;
}
s16 TLobby::clamp_value_below_200() {
    ClampValueBelow200Object *p = (ClampValueBelow200Object *)this;
    if (p->v >= 200) {
        return default_setting_16(p);
    }
    return p->v;
}

u8 TLobby__sub_801D6F94(TLobbyObject *p) {
    if (p->v >= 2) {
        return default_setting_0E(p);
    }
    return p->v;
}

u8 TLobby::clamp_value_below_2() {
    ClampValueBelow2Object *p = (ClampValueBelow2Object *)this;
    if (p->v >= 2) {
        return default_setting_0D(p);
    }
    return p->v;
}

u8 TLobby__sub_801D6FFC(TLobbyObject2 *p) {
    if (p->v >= 3) {
        return default_setting_0C(p);
    }
    return p->v;
}

u8 TLobby::normalize_battle_rule_value() {
    NormalizeBattleRuleValueObject *p = (NormalizeBattleRuleValueObject *)this;
    if (p->v >= 2) {
        return default_setting_0B(p);
    }
    return p->v;
}
u8 TLobby::get_rule_field_a() {
    GetRuleFieldAObject *p = (GetRuleFieldAObject *)this;
    if (p->v >= 2) {
        return default_setting_0A(p);
    }
    return p->v;
}

u8 TLobby::normalize_battle_rule_value_b() {
    NormalizeBattleRuleValueBObject *p = (NormalizeBattleRuleValueBObject *)this;
    if (p->v >= 2) {
        return default_setting_09(p);
    }
    return p->v;
}

u8 TLobby::clamp_rule_value_2() {
    ClampRuleValue2Object *p = (ClampRuleValue2Object *)this;
    if (p->v >= 2) {
        return default_setting_08(p);
    }
    return p->v;
}
u8 TLobby__sub_801D7100(TLobbyObject3 *p) {
    if (p->v >= 3) {
        return default_setting_07(p);
    }
    return p->v;
}

}
