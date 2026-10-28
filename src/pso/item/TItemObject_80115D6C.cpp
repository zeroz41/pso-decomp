#include "pso/item/TItemObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/TItemList.h"
#include "pso/misc/TShopEquipmentListWindow.h"

#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TMainCursor.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
struct Msg_80116004 { u8 hdr[4]; s16 ids[4]; };

struct Obj_80116004 { u8 pad0[0x38]; f32 pos[3]; };

struct VBase_80115F28 { char pad[0x18]; };

struct VObj_80115F28 : VBase_80115F28 {
    virtual s32 m0(); virtual s32 m1(); virtual s32 m2();
    virtual s32 m3(); virtual s32 m4(); virtual s32 m5();
    virtual s32 m6(); virtual s32 m7(); virtual s32 m8();
    virtual s32 m9(); virtual s32 m10(); virtual s32 m11();
    virtual s32 m12(); virtual s32 m13(); virtual s32 m14();
    virtual s32 m15(); virtual s32 m16(); virtual s32 m17();
    virtual s32 m18(); virtual s32 m19(); virtual s32 m20();
    virtual s32 m21(); virtual s32 m22(); virtual s32 m23();
    virtual s32 m24(); virtual s32 m25(); virtual s32 m26();
    virtual s32 m27(); virtual s32 m28(); virtual s32 m29();
    virtual s32 m30(); virtual s32 m31(); virtual s32 m32();
    virtual s32 m33();
};

struct Pkt_80115F28 { u8 pad[4]; s16 ids[4]; };

struct Msg_801160E0 { u8 hdr[4]; s16 id; s16 types[3]; u8 pad[0xC]; };

struct Item_801160E0 { u8 pad[0x424]; u32 f424; };

extern "C" {
s16 obj_getField1c(Obj_80116004 *);
f32 horizontal_distance_squared(void *, void *);
s32 sub_801A1DDC__10TObjPlayerFv(void *);
void *get_player_by_client_id(s32 i);
void send_nearby_player_ids(Obj_80116004 *self, f32 range);
u8 get_item_group__5TItemFv(void *);
s32 TItemObject__sub_80115DE8(void *item);
s32 set_hp_clamped__10TObjPlayerFs(void *, s32);
s32 get_field_2b8__14TItemProShieldFv(void *);
void *spawn_particle_effect(void *pos, s32 id);
s32 reset_key_machine_state__10TObjPlayerFv();
void *TObjPlayer__sub_80116620(void *, s32);
void send_star_atomizer_targets(void *arg0);
}
void handle_6x66_use_star_atomizer(u8 *arg0);
void TItemObject::store_encoded_value(s32 value) {
    encoded_value = value ^ (s32)&encoded_value;
}

extern "C" {

void update_owned__11TItemObjectFv(void *arg0);
u8 *vfunc_9__11TItemObjectFv(u8 *arg0);
s32 get_max_stack__5TItemFv(void *);

void *__dt__11TItemObjectFv(void *arg0, s16 arg1);
void TItemObject__vt16(u8 *arg0, u8 *arg1);
void use__11TItemObjectFv(void *arg0);
s32 remove_amount__11TItemObjectFl(TItemObject *arg0, s32 arg1);
s32 add_amount__11TItemObjectFl(void *arg0, s32 arg1);
void vfunc_44__11TItemObjectFv(void *arg0);
s32 get_amount__11TItemObjectFv(void);
void run_task__5TItemFv(); void render__5TItemFv(); void render_shadows__5TItemFv();
void vfunc_6__13TUnk_804B9870FPsl(); void apply_object_set_data__13TUnk_804B9870FPv(); void reset_motion_fields__13TUnk_804AF8A0Fv();
int update_object_view_visibility__5TItemFff(void *p); void classify_actor_view_detail__13TUnk_804B9870Ffff(); void vfunc_12__5TItemFv();
void vfunc_13__5TItemFl(); void update_in_inventory__5TItemFv(); void update_equipped__5TItemFv();
void activate_effect__5TItemFl(); void set_attach_slot__5TItemFSc(); void equip__5TItemFv();
void unequip__5TItemFv(); void add_equip_stats__5TItemFl(); void remove_equip_stats__5TItemFl();
void subtract_item_stat_bonus__5TItemFllPs(); void subtract_equip_stats__5TItemFPvPsPs(); void render_equipped__5TItemFv();
void render_equipped_shadow__5TItemFv(); void render_equipped_deferred__5TItemFv(); void destroy__5TItemFv();
void vfunc_30__5TItemFv(); void get_attack_flags__5TItemFv(); void get_attach_slot__5TItemFv();
void vfunc_34__5TItemFv(); void is_identified__5TItemFv(); int get_slot_count__5TItemFv(void); void add_slot__5TItemFv();
int feed__5TItemFP9TItemData(void); void vfunc_42__5TItemFv(); void get_motion_type__5TItemFv();
void *__vt__11TItemObject[] = {
    0, 0,
    (void *)__dt__11TItemObjectFv, (void *)run_task__5TItemFv, (void *)render__5TItemFv,
    (void *)render_shadows__5TItemFv, (void *)vfunc_6__13TUnk_804B9870FPsl, (void *)apply_object_set_data__13TUnk_804B9870FPv,
    (void *)reset_motion_fields__13TUnk_804AF8A0Fv, (void *)vfunc_9__11TItemObjectFv, (void *)update_object_view_visibility__5TItemFff,
    (void *)classify_actor_view_detail__13TUnk_804B9870Ffff, (void *)vfunc_12__5TItemFv, (void *)vfunc_13__5TItemFl,
    (void *)update_owned__11TItemObjectFv, (void *)update_in_inventory__5TItemFv, (void *)update_equipped__5TItemFv,
    (void *)activate_effect__5TItemFl, (void *)TItemObject__vt16, (void *)set_attach_slot__5TItemFSc,
    (void *)equip__5TItemFv, (void *)unequip__5TItemFv, (void *)add_equip_stats__5TItemFl,
    (void *)remove_equip_stats__5TItemFl, (void *)subtract_item_stat_bonus__5TItemFllPs, (void *)subtract_equip_stats__5TItemFPvPsPs,
    (void *)render_equipped__5TItemFv, (void *)render_equipped_shadow__5TItemFv, (void *)render_equipped_deferred__5TItemFv,
    (void *)destroy__5TItemFv, (void *)vfunc_30__5TItemFv, (void *)use__11TItemObjectFv,
    (void *)get_attack_flags__5TItemFv, (void *)get_attach_slot__5TItemFv, (void *)vfunc_34__5TItemFv,
    (void *)is_identified__5TItemFv, (void *)get_amount__11TItemObjectFv, (void *)remove_amount__11TItemObjectFl,
    (void *)add_amount__11TItemObjectFl, (void *)get_slot_count__5TItemFv, (void *)add_slot__5TItemFv,
    (void *)feed__5TItemFP9TItemData, (void *)vfunc_42__5TItemFv, (void *)get_motion_type__5TItemFv,
    (void *)vfunc_44__11TItemObjectFv,
};

u8 TItemObject::sub_80115D7C() { return this->m_100; }

u8 TItemObject::get_tool_pmt_amount_byte() {
    return (u8) *(u16 *)(this->m_f8 + 8);
}

void TItemObject::update_owned() {

    if (this->get_amount() > (((s32 (*)())get_max_stack__5TItemFv)())) {
        this->refresh_if_current_player();
    }
}

s32 TItemObject__sub_80115DE8(void *item) {
    if (item != NULL) {
        u8 kind = get_item_group__5TItemFv(item);
        u8 slots = ((TItem *)item)->get_item_index();
        switch (kind) {
        case 0:
            switch (slots) {
            case 0: return 0;
            case 1: return 1;
            case 2: return 2;
            }
            break;
        case 1:
            switch (slots) {
            case 0: return 3;
            case 1: return 4;
            case 2: return 5;
            }
            break;
        case 6:
            switch (slots) {
            case 0: return 6;
            case 1: return 7;
            }
            break;
        case 3: return 8;
        case 4: return 9;
        case 5: return 10;
        case 7: return 11;
        case 8: return 12;
        default: return -1;
        }
    }
    return -1;
}
}

void handle_6x66_use_star_atomizer(u8 *arg0) {
    u8 *player;
    s32 var_r28;
    u8 *temp_r3_2;
    ((TObjPlayer *)arg0)->bswap_fields_x4();
    player = (u8 *)get_player_by_client_id(*(s16 *)&((TObjPlayer *)arg0)->m_flags);
    if (player != NULL) {
        var_r28 = 0;
        do {
            temp_r3_2 = (u8 *)get_player_by_client_id(((Pkt_80115F28 *)arg0)->ids[var_r28]);
            if ((temp_r3_2 != NULL) && (((VObj_80115F28 *)temp_r3_2)->m31() == 0)) {
                if (((TObjPlayer *)player)->get_field_3e4() == ((TObjPlayer *)temp_r3_2)->get_field_3e4()) {
                    set_hp_clamped__10TObjPlayerFs(temp_r3_2, get_field_2b8__14TItemProShieldFv(temp_r3_2));
                    if (reset_key_machine_state__10TObjPlayerFv() != 0) {
                        if (var_r28 == 0) {
                            spawn_particle_effect(temp_r3_2 + 0x2FC, 0x19);
                        }
                        spawn_particle_effect(temp_r3_2 + 0x2FC, 0xC2);
                    }
                }
            }
            var_r28 += 1;
        } while (var_r28 != 4);
    }
}

void send_nearby_player_ids(Obj_80116004 *self, f32 range) {
    Msg_80116004 msg;
    s32 j;
    u16 i;
    Obj_80116004 *pl;
    if (self != NULL && sub_801A1DDC__10TObjPlayerFv(self) != 0) {
        ((TObjPlayer *)(&msg))->set_type_bytes();
        j = 0;
        for (i = 0; i != 4; i++) {
            pl = (Obj_80116004 *)get_player_by_client_id(i);
            if (pl != NULL) {
                if (horizontal_distance_squared(self->pos, pl->pos) < range) {
                    msg.ids[j++] = obj_getField1c(pl);
                } else {
                    msg.ids[j++] = -1;
                }
            } else {
                msg.ids[j++] = -1;
            }
        }
        ((TObjPlayer *)(&msg))->bswap_and_send_item();
    }
}

void send_star_atomizer_targets(void *player) {
    Msg_801160E0 msg;
    s32 t;
    s32 i;
    if (player != NULL && sub_801A1DDC__10TObjPlayerFv(player) != 0 && ((Item_801160E0 *)player)->f424 != 0) {
        t = ((TMainCursor *)(((Item_801160E0 *)player)->f424))->find_by_pos(4, 0xA);
        if (t != 0) {
            ((TObjPlayer *)(&msg))->set_type_bytes();
            msg.id = obj_getField1c((Obj_80116004 *)player);
            for (i = 0; i != 3; i++) {
                msg.types[i] = ((TObjPlayer *)(TObjPlayer__sub_80116620((void *)(t + 0x9C), i)))->get_type_id();
            }
            ((TObjPlayer *)(&msg))->bswap_and_send_item();
        }
    }
}

void*TItemObject::vfunc_9() {
    u32 temp_r4;

    temp_r4 = this->m_f0;
    if (temp_r4 != 0U) {
        return (unsigned char *) (temp_r4 + 0x38);
    }
    return (u8 *)&this->position;
}

struct Base_8011626C_80115D6C { char pad[0x18]; };
struct VObj_8011626C_80115D6C : Base_8011626C_80115D6C {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42();
};

struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual u8 m34();
};

extern "C" {
s32 set_stack_count__24TShopEquipmentListWindowFSc(void *, void *);
void *TItemObject__ct(void *arg0, void *arg1, void *arg2);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void *lookup_item_pmt_record(u8 *item);
s32 is_wrapped__5TItemFv();
s32 get_item_type_or_default__9TItemListFv(void *);
s32 use__5TItemFv();

s32 TItemObject::add_amount(s32 arg1) {
    s32 temp_r31;

    temp_r31 = arg1 + this->get_amount();
    if (temp_r31 <= get_max_stack__5TItemFv(this)) {
        this->store_encoded_value(temp_r31);
        return 1;
    }
    return 0;
}

s32 TItemObject::remove_amount(s32 arg1) {
    s32 temp_r3;

    temp_r3 = this->get_amount();
    if (arg1 <= temp_r3) {
        this->store_encoded_value(temp_r3 - arg1);
        return 1;
    }
    return 0;
}

void TItemObject::use() {
    struct VObj_8011626C_80115D6C *o = (struct VObj_8011626C_80115D6C *)this;
    if (is_wrapped__5TItemFv() != 0) {
        this->unwrap();
        return;
    }
    if ((u32) this->m_f0 != 0U) {
        this->m_101 = 0U;
        o->m42();
        if ((u8) this->m_101 == 0) {
            this->apply_switch_attack(0x1AF);
            this->notify_owner(0x5B211);
        }
        if (this->get_item_flags() & 0x10) {
            consume_item_by_id(get_item_id());
        }
    }
}

void TItemObject::vfunc_44() {
    use__5TItemFv();
    this->m_101 = 1;
}

extern s32 lbl_805D2C28;

void TItemObject__vt16(u8 *item_object, u8 *item) {
    if (((u8 (*)())get_item_group__5TItemFv)() == 2) {
        *(u8 *)((s8 *)item + 4) = (u8) ((TItemObject *)item_object)->m_100;
    }
    set_stack_count__24TShopEquipmentListWindowFSc(item, (void *) (((VObj_18 *)(item_object))->m34()));
}

void *TItemObject__ct(void *arg0, void *arg1, void *item) {
    s16 temp_r3;

    __ct__5TItemFP7TObjectPUc(arg0, arg1, item);
    *(void **)((s8 *)arg0 + 0x18) = (void *) __vt__11TItemObject;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2C28;
    *(void **)((s8 *)arg0 + 0xF8) = lookup_item_pmt_record((u8 *)item);
    ((TItemObject *)arg0)->m_100 = (u8) *(u8 *)((s8 *)item + 4);
    ((TItemObject *)arg0)->store_encoded_value(get_item_type_or_default__9TItemListFv(item));
    if (*(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0xF8)) + 0x10) & 1) {
        ((TItem *)arg0)->add_item_flags(0x10);
    } else {
        ((TItem *)arg0)->clear_item_flags(0x10);
    }
    temp_r3 = *(s16 *)((s8 *)(*(void **)((s8 *)arg0 + 0xF8)) + 4);
    if (temp_r3 != 0) {
        ((TItem *)arg0)->set_drop_model(temp_r3 + 4);
    }
    return arg0;
}
u8 *TItemObject::create() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x104));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)TItemObject__ct((void *)temp_r3, (void *)tl_05, (void *)arg0)));
        }
        return var_r0;
    }
    return NULL;
}


s32 (*TLobby__sub_8010440C())(s32);

s32 TItemObject::call_dispatch(s32 arg0) {
    if (arg0 != 0) {
        s32 (*fp)(s32) = TLobby__sub_8010440C();
        return fp(arg0);
    }
    return 0;
}

void *__dt__11TItemObjectFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 0x18) = __vt__11TItemObject;
        __dt__5TItemFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
}

s32 TItemObject::get_amount() {
    return encoded_value ^ (s32)&encoded_value;
}
