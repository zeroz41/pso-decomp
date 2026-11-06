#include "types.h"
#include "pso/unk/TLobby_802D22F0.h"
#include "pso/unk/TLobby.h"

struct E_802D2334 { u32 a; u32 b; };

struct E_802D230C { u32 a; u32 b; };

struct E_802D2358 { u32 a; u32 b; };

extern "C" {
E_802D2334 *TLobby__sub_802D2334(E_802D2334 *p, u32 key);
E_802D230C *find_free_trade_slot__6TLobbyFPv(E_802D230C *p);
void TLobby__sub_802D2358(E_802D2358 *p);
int byteswap_trade_packet__6TLobbyFv(void);

void TLobby__sub_802D22F0(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }
void*TLobby::get_trade_obj_ptr() { return (char*)this + 0xf0; }

E_802D230C *find_free_trade_slot__6TLobbyFPv(E_802D230C *p) {
    s32 i;
    for (i = 0; i < 30; i++, p++) {
        if (p->a == 0xFFFFFFFF) return p;
    }
    return 0;
}

E_802D2334 *TLobby__sub_802D2334(E_802D2334 *p, u32 key) {
    s32 i;
    for (i = 0; i < 31; i++, p++) {
        if (key == p->a) return p;
    }
    return 0;
}

    extern int local_client_id;

void TLobby__sub_802D2358(E_802D2358 *p) {
    s32 i;
    for (i = 0; i < 31; i++, p++) {
        p->a = 0xFFFFFFFF;
        p->b = 0;
    }
}

void TLobby::prepare_trade_packet() { *(short*)((char*)this + 0x2) = local_client_id; byteswap_trade_packet__6TLobbyFv(); }

}
