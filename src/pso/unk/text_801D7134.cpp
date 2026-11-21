#include "types.h"

struct LobbyRuleBytes {
    u8 m_0;
    u8 m_1;
    u8 m_2;
    u8 m_3;
    u8 m_4;
    u8 m_5;
};

extern "C" {
u8 ret_801D793C(LobbyRuleBytes *p);
u8 ret_801D7944(LobbyRuleBytes *p);
u8 ret_801D794C(LobbyRuleBytes *p);
u8 ret_801D7954(LobbyRuleBytes *p);
u8 ret_801D795C(LobbyRuleBytes *p);

u8 get_rule_field_5__6TLobbyFv(LobbyRuleBytes *p) {
    if (p->m_5 >= 2) {
        return ret_801D793C(p);
    }
    return p->m_5;
}

u8 get_rule_field_4__6TLobbyFv(LobbyRuleBytes *p) {
    if (p->m_4 >= 3) {
        return ret_801D7944(p);
    }
    return p->m_4;
}

u8 get_rule_field_3__6TLobbyFv(LobbyRuleBytes *p) {
    if (p->m_3 >= 2) {
        return ret_801D794C(p);
    }
    return p->m_3;
}

u8 get_rule_field_2__6TLobbyFv(LobbyRuleBytes *p) {
    if (p->m_2 >= 4) {
        return ret_801D7954(p);
    }
    return p->m_2;
}

u8 get_rule_field_1__6TLobbyFv(LobbyRuleBytes *p) {
    if (p->m_1 >= 3) {
        return ret_801D795C(p);
    }
    return p->m_1;
}
}
