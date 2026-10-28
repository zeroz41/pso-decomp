#include "types.h"
#include "pso/item/TItemData.h"
#include "pso/system/byteswap.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemProShield.h"
#include "pso/TParticleCtrl.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801186EC___vt__14TItemProShield { s32 value; u8 remaining[0xCC]; };

struct Status_80118558 { s8 a; u8 b; u8 pad[2]; u32 c; s32 d; s32 e; s32 f; };

extern "C" {
void TItemProShield__vt16(TItemProShield *arg0, void *arg1);
void TItemEquipBase__sub_8010A82C(s32 arg0);
s32 play_sound_effect(int, int, int, int);
s32 ct_init__14TItemEffShieldFPUcs(int, int, void *);
s32 __ct__13TUnk_8049F130FP7TObjectsUc(int, int, void *, int);
s32 __nw__7TObjectFUl(int);
s32 __nw__15TItemHeapObjectFUl(int);
s32 construct_timer_event__13TUnk_804A0628Fv(int, int, void *, int);
s32 get_owner_client__5TItemFv(void *);
s32 init_item_timer_event__13TUnk_804A0648Fv(int, int, void *, int);
int fn_800F953C(void*);
    extern int TItemProShield__shield_table;
int fn_800F955C(void *p);
extern s32 lbl_805D2C3C;
void *__dt__14TItemEquipBaseFv(void *arg0, s16 arg1);
extern s32 __vt__14TItemProShield[];
void *__dt__14TItemProShieldFv(void *arg0, s16 arg1);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * TItemEquipBase__ct(void *);
s16 get_bswap16_field8__9TItemDataFPv(void *);
s16 getS16_06__9TItemDataFPv(void *);
void *lookup_item_pmt_record(u8 *item);
extern s32 lbl_805D2C38;
u8 *TItemProShield__ct(TItemProShield *arg0, s32 arg1, u8 *arg2);
s32 add_actor_tp(u8 *arg0, s32 arg1);
s32 add_actor_hp(u8 *arg0, s16 arg1);
s16 obj_getS16_2BA(u8 *p);
s32 create_shield_effect__14TItemProShieldFlUsUl(s32, s32, s32);
s32 play_shield_sound_cue(Status_80118558 *);
extern const f32 lbl_805DABF0;
s32 register_technique_boosts__14TItemEquipBaseFPvPv(void *, s32);
void draw_ginja_object(void *child);
s32 set_model_fade_alpha__10TObjPlayerFf();
void TObjPlayer__sub_8036414C(void);
void TObjPlayer__sub_80364198(void);
s32 push_matrix_from();
s32 pop_matrix();
s32 get_owner_alpha__5TItemFv(void *);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, s32);

extern s32 model_render_flags;

void TItemProShield::deactivate_shield_effect(s32 arg1) {
    if (((u32) this->m_f4 != 0U) && ((u32) this->m_f0 != 0U) && (obj_testFlags30__13TUnk_804AF8A0FUl(this, 0x08000000) == 0) && (is_hidden() == 0)) {
        ((TObjMotion *)(this->m_f0))->get_item_ptr(arg1);
        push_matrix_from();
        TObjPlayer__sub_80364198();
        model_render_flags &= 0xFFFFFFEF;
        get_owner_alpha__5TItemFv(this);
        set_model_fade_alpha__10TObjPlayerFf();
        if (this->m_19c & 2) {
            TParticleCtrl::begin_effect_render();
        }
        TObjPlayer::notify_fish_if_valid(this->texture_id);
        draw_ginja_object((void *)this->m_f4);
        if (this->m_19c & 2) {
            TParticleCtrl::end_effect_render();
        }
        TObjPlayer::warn_if_gauge_low();
        TObjPlayer__sub_8036414C();
        pop_matrix();
    }
}

void TItemProShield::vfunc_46() { update_with_player(); }
void TItemProShield::vfunc_51() {  }
void TItemProShield::carry_over_stats(TItemData *data, TItem *item) {
    data->set_dfp_bonus(((TItemProShield *)item)->m_198);
    data->set_bswapped_field_8(((TItemProShield *)item)->m_199);
}

void TItemProShield::vfunc_14() {
    if ((u8) this->m_19a < (u8) this->m_198) {
        this->m_198 = 0U;
    }
    if ((u8) this->m_19b < (u8) this->m_199) {
        this->m_199 = 0U;
    }
}

void TItemProShield::vfunc_16() {
    this->vfunc_51();
    register_technique_boosts__14TItemEquipBaseFPvPv(this, this->m_194);
    if (this->m_19c & 4) {
        refresh_owner_stats();
    }
    this->bind_loaded_resources();
}
void TItemProShield__vt16(TItemProShield *item_pro_shield, void *item_data) {
    ((TItemData *)item_data)->set_dfp_bonus(item_pro_shield->m_198);
    ((TItemData *)item_data)->set_bswapped_field_8(item_pro_shield->m_199);
}
void TItemProShield::vfunc_45() { TItemEquipBase__sub_8010A82C((s32)this); }
void TItemProShield::vfunc_44() {
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    u8 slot_count;
    if (is_hidden() == 0) {
        play_sound_effect(0x4000B20A, this->m_f0 + 0x38, 0, 0);
    }
    if ((u32) this->m_174 != 0U) {
        slot_count = this->get_item_index();
        switch ((s32) slot_count) {
        case 39:
            if ((u32) this->m_174 != 0U) {
                temp_r3_2 = __nw__15TItemHeapObjectFUl(0x2C);
                if (temp_r3_2 != 0) {
                    init_item_timer_event__13TUnk_804A0648Fv(temp_r3_2, this->m_174, (void *) (get_owner_client__5TItemFv(this)), 0x1C2);
                }
                temp_r3_3 = __nw__15TItemHeapObjectFUl(0x2C);
                if (temp_r3_3 != 0) {
                    construct_timer_event__13TUnk_804A0628Fv(temp_r3_3, this->m_174, (void *) (get_owner_client__5TItemFv(this)), 0x1C2);
                }
            }
            break;
        case 26:
            if ((u32) this->m_174 != 0U) {
                temp_r3_4 = __nw__7TObjectFUl(0x2C);
                if (temp_r3_4 != 0) {
                    ct_init__14TItemEffShieldFPUcs(temp_r3_4, this->m_174, (void *) (get_owner_client__5TItemFv(this)));
                }
            }
            break;
        }
        if ((slot_count >= 0x53U) && (slot_count <= 0x82U)) {
            temp_r3_5 = __nw__7TObjectFUl(0x30);
            if (temp_r3_5 != 0) {
                __ct__13TUnk_8049F130FP7TObjectsUc(temp_r3_5, this->m_174, (void *) (get_owner_client__5TItemFv(this)), slot_count);
            }
        }
    }
}

void TItemProShield::vfunc_30() {
    Status_80118558 st;
    if ((u32) this->m_f0 != 0U) {
        if (is_hidden() == 0) {
            create_shield_effect__14TItemProShieldFlUsUl(tl_05, get_owner_client__5TItemFv(this), this->m_190);
            ((TObjPlayer *)(&st))->reset_status_block();
            st.a = this->get_item_group();
            st.b = this->get_item_index();
            st.c = this->m_f0;
            play_shield_sound_cue(&st);
        }
        if (this->m_19c & 1) {
            switch (this->get_item_index()) {
            case 34:
                add_actor_hp((u8 *)this->m_f0, (lbl_805DABF0 * (f32)((TItemProShield *)(this->m_f0))->get_field_2b8()));
                break;
            case 35:
                add_actor_hp((u8 *)this->m_f0, (lbl_805DABF0 * (f32)((TItemProShield *)(this->m_f0))->get_field_2b8()));
                add_actor_tp((u8 *)this->m_f0, (s32)(lbl_805DABF0 * (f32)obj_getS16_2BA((u8 *)this->m_f0)));
                break;
            }
        }
    }
}

u8 *TItemProShield__ct(TItemProShield *item_pro_shield, s32 arg1, u8 *item) {
    TItemEquipBase__ct(item_pro_shield);
    *(s32 **)((s8 *)item_pro_shield + 0x18) = &(*(RecoveredGlobal_801186EC___vt__14TItemProShield *)&__vt__14TItemProShield).value;
    *(s32 *)((s8 *)item_pro_shield + 0) = (s32) lbl_805D2C38;
    ((TItemProShield *)(item_pro_shield))->set_attach_slot(3);
    item_pro_shield->m_18c = (s32)lookup_item_pmt_record(item);
    item_pro_shield->m_190 = (s32) ((*(s32 *)&TItemProShield__shield_table) + ((s8) *(u8 *)(item_pro_shield->m_18c + 0xD) * 0x2C));
    item_pro_shield->m_194 = TObjPlayer::get_shield_pmt_entry(*(u8 *)(item_pro_shield->m_18c + 0x19));
    item_pro_shield->m_19a = (u8) *(u8 *)(item_pro_shield->m_18c + 0x17);
    item_pro_shield->m_19b = (u8) *(u8 *)(item_pro_shield->m_18c + 0x16);
    item_pro_shield->m_198 = getS16_06__9TItemDataFPv(item);
    item_pro_shield->m_199 = get_bswap16_field8__9TItemDataFPv(item);
    item_pro_shield->m_19c = 0;
    ((TItemEquipBase *)item_pro_shield)->set_equip_flag(0x24);
    item_pro_shield->sub_80117FEC();
    return (u8 *)item_pro_shield;
}

u8 *TItemProShield::create_instance() {
    s32 arg0 = (s32)this;
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1A0));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TItemProShield__ct((TItemProShield *)((u8 *)temp_r3), (s32)tl_05, (u8 *)arg0));
        }
        return var_r0;
    }
    return NULL;
}

void TItemProShield::free() { fn_800F953C((void*)TItemProShield__shield_table); TItemProShield__shield_table = 0; }
void TItemProShield::load_data() {
    s32 temp_r3;
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    temp_r3 = fn_800F955C((void *)lbl_805D2C3C);
    (*(s32 *)&TItemProShield__shield_table) = temp_r3;
    var_r31 = 0;
    var_r28 = temp_r3;
    do {
        var_r29 = var_r28;
        var_r30 = 0;
loop_2:
        bswap_32((u32 *)var_r29);
        var_r30 += 1;
        var_r29 += 4;
        if (var_r30 < 8) {
            goto loop_2;
        }
        bswap_32((u32 *)(var_r28 + 0x20));
        bswap_32((u32 *)(var_r28 + 0x24));
        bswap_32((u32 *)(var_r28 + 0x28));
        var_r31 += 1;
        var_r28 += 0x2C;
    } while (var_r31 != 0x32);
}
void *__dt__14TItemProShieldFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TItemProShield;
        __dt__14TItemEquipBaseFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

}
