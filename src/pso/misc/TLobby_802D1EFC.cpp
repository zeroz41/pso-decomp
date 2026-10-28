#include "types.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/misc/TLobby_802D1EFC.h"
#include "pso/misc/TLobby.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"

struct Entry_802D20C8 { u32 id; s32 count; };

struct ItemA_802D20C8 { u8 b[0x14]; };

struct ItemB_802D20C8 { u8 b[0x1C]; };

struct VBase802D1F30 { char pad[0x18]; };

struct VObj802D1F30 : VBase802D1F30 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual s32 m34();
};

extern "C" {
s32 item_identity_matches(u8 *arg0, u8 *arg1);
s32 TObjPlayer__sub_801C1AC8();
Entry_802D20C8 *find_free_trade_slot__6TLobbyFPv(void *);
void *get_player_by_client_id(s32 i);
int TLobby__sub_802D2358(void*);

void TLobby::set_trade_field_4(s32 arg1) {
    s32 arg0 = (s32)this;
    *(s32 *)((s8 *)(((TLobby *)(arg0 + 0xF8))->get_trade_obj_ptr()) + 4) = arg1;
}

void snapshot_player_trade_inventory(s32 arg0, s32 arg1) {
    s32 ids[0x1E];
    s32 temp_r29;
    s32 var_r31;
    u8 *temp_r31;
    u8 *player;
    s32 var_r26;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *var_r25;
    ((TLobby *)arg0)->update_both_halves();
    player = (u8 *)get_player_by_client_id(arg1);
    if (player != NULL) {
        temp_r29 = ((TObjPlayer *)(((TQuestListVM *)player)->m_d00))->run_and_get_result((int)((void *) ids));
        var_r25 = (unsigned char *) (arg0 + 0xF8);
        var_r26 = 0;
        while (var_r26 < temp_r29) {
            temp_r3_2 = ((u8 *(*)(s32)) find_item_by_id)(ids[var_r26]);
            if (temp_r3_2 != NULL) {
                *(s32 *)((s8 *)var_r25 + 0) = ids[var_r26];
                *(s32 *)((s8 *)var_r25 + 4) = ((VObj802D1F30 *)temp_r3_2)->m34();
                if ((s32) *(s32 *)((s8 *)var_r25 + 4) <= 0) {
                    *(s32 *)((s8 *)var_r25 + 4) = 1;
                }
                var_r25 += 8;
            }
            var_r26 += 1;
        }
        temp_r31 = (u8 *) ((TLobby *)(arg0 + 0xF8))->get_trade_obj_ptr();
        temp_r3_3 = ((TObjPlayer *)player)->get_stats();
        *(s32 *)((s8 *)temp_r31 + 0) = -0xFF;
        if (temp_r3_3 != NULL) {
            *(s32 *)((s8 *)temp_r31 + 4) = (s32) *(s32 *)((s8 *)temp_r3_3 + 0x20);
            return;
        }
        *(s32 *)((s8 *)temp_r31 + 4) = 0;
    }
}

void TLobby::update_both_halves() { TLobby__sub_802D2358(this); TLobby__sub_802D2358((char*)this + 0xf8); }

void TLobby::clear_stale_entries(u8 *arg0) {
    u8 *var_r29;
    s32 var_r28;

    var_r29 = arg0;
    var_r28 = 0;
    do {
        if (((u32) (*(s32 *)((s8 *)var_r29 + 0) + 0x10000) != 0xFFFFU) && ((find_item_by_id(*(s32 *)((s8 *)var_r29 + 0)) == NULL) || ((s32) *(s32 *)((s8 *)var_r29 + 4) <= 0))) {
            *(s32 *)((s8 *)var_r29 + 0) = -1;
            *(s32 *)((s8 *)var_r29 + 4) = 0;
        }
        var_r28 += 1;
        var_r29 += 8;
    } while (var_r28 < 0x1E);
}
s32 TLobby::add_trade_item(u32 arg1, s32 arg2) {
    ItemB_802D20C8 a;
    ItemA_802D20C8 b;
    u32 item;
    Entry_802D20C8 *e;
    u32 found;
    s32 i;
    if (arg1 == 0xFFFFFF01) {
        s32 *t = (s32 *) this->get_trade_obj_ptr();
        t[1] += arg2;
        return t[1] > 999999;
    }
    item = ((u32 (*)(u32)) find_item_by_id)(arg1);
    if (item == 0) {
        return 0;
    }
    if (TObjPlayer__sub_801C1AC8() != 0) {
        ((TItem *)item)->copy_to_item_data((TItemData *)&a);
        e = ((Entry_802D20C8 *)this);
        for (i = 0; i < 30; i++, e++) {
            if (e->id != 0xFFFFFFFF && e->id != 0xFFFFFF01) {
                found = ((u32 (*)(u32)) find_item_by_id)(e->id);
                if (found != 0) {
                    ((TItem *)found)->copy_to_item_data((TItemData *)&b);
                    if (item_identity_matches((u8 *)&b, (u8 *)&a) != 0) {
                        e->count += arg2;
                        if (e->count > ((TItem *)found)->get_max_stack_size()) {
                            return 2;
                        }
                    }
                }
            }
        }
    }
    e = find_free_trade_slot__6TLobbyFPv(this);
    if (e == NULL) {
        return 3;
    }
    e->id = arg1;
    e->count = arg2;
    return 0;
}

}
