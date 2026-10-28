#include "types.h"
#include "pso/misc/TLobby.h"
struct Rec_8020BCE4 { u8 pad[0xA]; u16 fA; u8 pad2[0x3C]; };

struct Ent_8020BC50 { u8 pad1[0x40]; u32 f40; };

struct Pkt_8020BD50 { u8 hdr[2]; u16 id; s16 area; s16 flags; };

struct Ent_8020BD50 { u16 id; s16 flags; u8 pad[4]; };

struct Area_8020BD50 {
    s32 n0;
    s32 n1;
    u8 pad8[8];
    Ent_8020BD50 *l0;
    Ent_8020BD50 *l1;
};

struct ObjA_8020BD50 { u8 pad0[2]; s16 flags; u8 pad4[6]; u16 id; u8 padc[0x48 - 0xC]; };

struct ObjB_8020BD50 { u8 pad0[2]; s16 flags; u8 pad4[4]; u16 id; u8 pada[0x44 - 0xA]; };

extern "C" {
void obj_setFlags30(u32, int);
s32 get_current_floor();
void *find_entity_by_id(u16 id);
Rec_8020BCE4 *resolve_matching_object__6TLobbyFv();
s32 get_object_type__6TLobbyFi();
void TLobby__sub_8020BCE4(void);
Ent_8020BC50 *get_object_count__6TLobbyFPv();
s32 get_obj_table_entry__6TLobbyFi();
void destroy_child_recursive__6TLobbyFPvPv(int, int);
extern s32 tl_02;
extern s32 tl_05;
extern s32 tl_06;
extern s32 tl_07;
void TLobby__sub_8020BC50(void);
extern Area_8020BD50 TLobby__floor_enemy_group_table[];
extern ObjB_8020BD50 *TLobby__data_805D610C;
extern s32 TLobby__current_floor_object_set_count;
extern ObjA_8020BD50 *TLobby__data_805D6114;
extern s32 TLobby__current_floor_enemy_set_count;
void handle_6x76_set_entity_set_flags(Pkt_8020BD50 *pkt);

void TLobby__sub_8020BC50(void) {
    s32 n;
    Ent_8020BC50 *p;
    s32 i;
    get_current_floor();
    p = get_object_count__6TLobbyFPv();
    get_current_floor();
    n = get_obj_table_entry__6TLobbyFi();
    for (i = 0; i < n; i++, p++) {
        if (p->f40 != 0) {
            destroy_child_recursive__6TLobbyFPvPv(tl_02, p->f40);
            destroy_child_recursive__6TLobbyFPvPv(tl_05, p->f40);
            destroy_child_recursive__6TLobbyFPvPv(tl_06, p->f40);
            destroy_child_recursive__6TLobbyFPvPv(tl_07, p->f40);
            p->f40 = 0;
        }
    }
}

void TLobby__sub_8020BCE4(void) {
    Rec_8020BCE4 *p;
    s32 n;
    s32 i;
    get_current_floor();
    p = resolve_matching_object__6TLobbyFv();
    get_current_floor();
    n = get_object_type__6TLobbyFi();
    for (i = 0; i < n; i++, p++) {
        u32 r = (u32)find_entity_by_id(p->fA);
        if (r != 0) {
            obj_setFlags30(r, 0x800);
        }
    }
}
void handle_6x76_set_entity_set_flags(Pkt_8020BD50 *pkt) {
    Ent_8020BD50 *e;
    Area_8020BD50 *a;
    Ent_8020BD50 *e2;
    Area_8020BD50 *a2;
    s32 i;
    u16 id;
    ((TLobby *)pkt)->bswap_player_fields();
    id = pkt->id;
    if (id >= 0x1000 && id < 0x4000) {
        a = &TLobby__floor_enemy_group_table[pkt->area];
        if (a->l1 != NULL) {
            e = a->l1;
            for (i = 0; i < a->n1; i++, e++) {
                if (e->id == id) {
                    e->flags |= pkt->flags;
                    break;
                }
            }
        }
        if (pkt->area == get_current_floor()) {
            for (i = 0; i < TLobby__current_floor_enemy_set_count; i++) {
                if (pkt->id == TLobby__data_805D6114[i].id) {
                    TLobby__data_805D6114[i].flags |= pkt->flags;
                    break;
                }
            }
        }
    }
    id = pkt->id;
    if (id >= 0x4000 && id < 0xFFFF) {
        a2 = &TLobby__floor_enemy_group_table[pkt->area];
        if (a2->l0 != NULL) {
            e2 = a2->l0;
            for (i = 0; i < a2->n0; i++, e2++) {
                if (e2->id == id) {
                    e2->flags |= pkt->flags;
                    break;
                }
            }
        }
        if (pkt->area == get_current_floor()) {
            for (i = 0; i < TLobby__current_floor_object_set_count; i++) {
                if (pkt->id == TLobby__data_805D610C[i].id) {
                    TLobby__data_805D610C[i].flags |= pkt->flags;
                    break;
                }
            }
        }
    }
}

}

struct Pkt_8020BF14 { u8 hdr[2]; s16 a; s16 b; s16 c; };

extern "C" {
s16 get_entity_id(void *);
}
void build_6x76_set_entity_set_flags(void *);
void send_6x76_set_entity_set_flags(void *arg0, s16 arg1);

void send_6x76_set_entity_set_flags(void *arg0, s16 arg1) {
    Pkt_8020BF14 pkt;
    build_6x76_set_entity_set_flags(&pkt);
    pkt.a = get_entity_id(arg0);
    pkt.b = ((s16 (*)())get_current_floor)();
    pkt.c = arg1;
    ((TLobby *)(&pkt))->send_player_update();
}
