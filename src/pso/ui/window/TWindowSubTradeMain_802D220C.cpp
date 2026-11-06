#include "types.h"
#include "pso/unk/TLobby_802D22F0.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/unk/TLobby.h"

struct E_802D2240 { u32 id; s32 cnt; };

struct T_802D2240 { s32 a; s32 b; };

extern "C" {
void * TLobby__sub_802D2334(void);

s32 TWindowSubTradeMain::get_state() {
    void *temp_r3;

    temp_r3 = TLobby__sub_802D2334();
    if (temp_r3 != NULL) {
        return *(s32 *)((s8 *)temp_r3 + 4);
    }
    return 0;
}
void TLobby::remove_trade_entry(u32 arg1) {
    E_802D2240 *p;
    s32 i;
    if ((arg1 + 0x10000) == 0xFF01) {
        T_802D2240 *t = (T_802D2240 *)((void *)this->get_trade_obj_ptr());
        t->b = 0;
        return;
    }
    {
    p = ((E_802D2240 *)this);
    for (i = 0; i < 0x1F; i++, p++) {
        if (arg1 == p->id) {
            break;
        }
    }
    i++;
    p++;
    while (i < 0x1F) {
        if ((p->id + 0x10000) == 0xFF01) {
            break;
        }
        TLobby__sub_802D22F0(p - 1, p);
        p->id = -1;
        i++;
        p->cnt = 0;
        p++;
    }
    }
}

}
