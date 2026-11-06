#include "types.h"
#include "pso/unk/TLobby_801D6DC4.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"

struct Obj_801D6F60 { u8 pad[0x16]; s16 v; };

struct Obj_801D7030 { u8 pad[0xB]; u8 v; };

struct Obj_801D6F94 { u8 pad[0xE]; u8 v; };

struct Obj_801D6FC8 { u8 pad[0xD]; u8 v; };

struct Obj_801D6FFC { u8 pad[0xC]; u8 v; };

struct Obj_801D7064 { u8 pad[0xA]; u8 v; };

struct Obj_801D70CC { u8 pad[0x8]; u8 v; };

struct Obj_801D7098 { u8 pad[0x9]; u8 v; };

struct Obj_801D7100 { u8 pad[0x7]; u8 v; };

extern "C" {
u8 ret_801D78EC(Obj_801D6F60 *p);
u8 ret_801D790C(Obj_801D7030 *p);
u8 ret_801D78F4(Obj_801D6F94 *p);
u8 TLobby__sub_801D6F94(Obj_801D6F94 *p);
u8 ret_801D78FC(Obj_801D6FC8 *p);
u8 ret_801D7904(Obj_801D6FFC *p);
u8 TLobby__sub_801D6FFC(Obj_801D6FFC *p);
u8 ret_801D7914(Obj_801D7064 *p);
u8 ret_801D7924(Obj_801D70CC *p);
u8 ret_801D791C(Obj_801D7098 *p);
u8 ret_801D792C(Obj_801D7100 *p);
u8 TLobby__sub_801D7100(Obj_801D7100 *p);
s32 is_invalid_slot__10TObjPlayerFUc(u8);
u8 ret_801D78E4();

void TLobby::set_volume(u8 arg1) {
    u8 var_r4;

    var_r4 = arg1;
    if (var_r4 > 0x63U) {
        var_r4 = 0;
    }
    *(u8 *)&this->m_up = var_r4;
}

u8 TLobby__sub_801D6DDC(void *arg0) {
    u8 v;
    s32 t;
    t = *(u8 *)((s8 *)arg0 + 0x11);
    v = t;
    if (is_invalid_slot__10TObjPlayerFUc(t) == 0 && v > 0x1DU) {
        v = 0;
    }
    return v;
}

void TLobby::set_validated_field_0x11(u8 arg1) {
    u8 var_r31;

    var_r31 = arg1;
    if ((is_invalid_slot__10TObjPlayerFUc(var_r31) == 0) && (var_r31 > 0x1DU)) {
        var_r31 = 0;
    }
    *(u8 *)((s8 *)this + 0x11) = var_r31;
}

s16 TLobby::clamp_player_index() {
    s16 var_r31;

    var_r31 = *(s16 *)&this->m_down;
    if ((var_r31 < 0) || (var_r31 > TObjPlayer::get_max_level())) {
        var_r31 = 0;
    }
    return var_r31;
}

void TLobby::set_clamped_index(s16 arg1) {
    s16 down;

    down = arg1;
    if ((down < 0) || (down > TObjPlayer::get_max_level())) {
        down = 0;
    }
    *(s16 *)&this->m_down = down;
}

void TLobby::set_clamped_value_1c(s32 arg1) {
    s32 var_r4;

    var_r4 = arg1;
    if ((var_r4 < 0) || (var_r4 > 0x278D0)) {
        var_r4 = 0;
    }
    *(s32 *)((s8 *)this + 0x1C) = var_r4;
}

u8 TLobby::get_clamped_level() {
    s16 temp_r0;

    temp_r0 = *(s16 *)((s8 *)this + 0x18);
    if (temp_r0 >= 0x1E) {
        return ret_801D78E4();
    }
    return (u8) temp_r0;
}
s16 TLobby::clamp_value_below_200() {
    Obj_801D6F60 *p = (Obj_801D6F60 *)this;
    if (p->v >= 200) {
        return ret_801D78EC(p);
    }
    return p->v;
}

u8 TLobby__sub_801D6F94(Obj_801D6F94 *p) {
    if (p->v >= 2) {
        return ret_801D78F4(p);
    }
    return p->v;
}

u8 TLobby::clamp_value_below_2() {
    Obj_801D6FC8 *p = (Obj_801D6FC8 *)this;
    if (p->v >= 2) {
        return ret_801D78FC(p);
    }
    return p->v;
}

u8 TLobby__sub_801D6FFC(Obj_801D6FFC *p) {
    if (p->v >= 3) {
        return ret_801D7904(p);
    }
    return p->v;
}

u8 TLobby::normalize_battle_rule_value() {
    Obj_801D7030 *p = (Obj_801D7030 *)this;
    if (p->v >= 2) {
        return ret_801D790C(p);
    }
    return p->v;
}
u8 TLobby::get_rule_field_a() {
    Obj_801D7064 *p = (Obj_801D7064 *)this;
    if (p->v >= 2) {
        return ret_801D7914(p);
    }
    return p->v;
}

u8 TLobby::normalize_battle_rule_value_b() {
    Obj_801D7098 *p = (Obj_801D7098 *)this;
    if (p->v >= 2) {
        return ret_801D791C(p);
    }
    return p->v;
}

u8 TLobby::clamp_rule_value_2() {
    Obj_801D70CC *p = (Obj_801D70CC *)this;
    if (p->v >= 2) {
        return ret_801D7924(p);
    }
    return p->v;
}
u8 TLobby__sub_801D7100(Obj_801D7100 *p) {
    if (p->v >= 3) {
        return ret_801D792C(p);
    }
    return p->v;
}

}
