#include "types.h"
#include "pso/system/data/pso_const_ids4.h"

struct LobbyRuleBytes {
    u8 m_0;
    u8 m_1;
    u8 m_2;
    u8 m_3;
    u8 m_4;
    u8 m_5;
};

extern "C" {

u8 fn_801D7134(LobbyRuleBytes *p) {
    if (p->m_5 >= 2) {
        return default_setting_05(p);
    }
    return p->m_5;
}

u8 fn_801D7168(LobbyRuleBytes *p) {
    if (p->m_4 >= 3) {
        return default_setting_04(p);
    }
    return p->m_4;
}

u8 fn_801D719C(LobbyRuleBytes *p) {
    if (p->m_3 >= 2) {
        return default_setting_03(p);
    }
    return p->m_3;
}

u8 fn_801D71D0(LobbyRuleBytes *p) {
    if (p->m_2 >= 4) {
        return default_setting_02(p);
    }
    return p->m_2;
}

u8 fn_801D7204(LobbyRuleBytes *p) {
    if (p->m_1 >= 3) {
        return default_setting_01(p);
    }
    return p->m_1;
}
}
