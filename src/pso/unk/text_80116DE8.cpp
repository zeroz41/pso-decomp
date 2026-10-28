#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer_801AEB84.h"
#include "pso/item/TItemObject_80115D6C.h"
#include "pso/unk/text_80116DE8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TUnk_8049FBC0.h"

// calc_stat_bonus_sum/calc_equip_bonus(u16) as this file's callers see them:
// the client id still in r3 from obj_getField1c.
extern "C" s16 calc_stat_bonus_sum__FUs();
extern "C" s16 calc_equip_bonus__FUs();

struct VBase_18_ddf499 { char pad[0x18]; };

struct VObj_18_ddf499 : VBase_18_ddf499 {
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
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual s32 m71();
};

extern "C" {
s32 obj_getField1c(void *);
s32 check_class_equip_permission(void *, int);
u8 get_item_index__5TItemFv();
void vfunc_44__13TUnk_8049FBC0Fv(u8 *arg0);
void run_task__5TItemFv();
void render__5TItemFv();
void render_shadows__5TItemFv();
void vfunc_6__13TUnk_804B9870FPsl();
void apply_object_set_data__13TUnk_804B9870FPv();
void reset_motion_fields__13TUnk_804AF8A0Fv();
void add_slot__5TItemFv();
void feed__5TItemFP9TItemData();
void get_slot_count__5TItemFv();
void vfunc_42__5TItemFv();
void update_object_view_visibility__5TItemFff();
void update_in_inventory__5TItemFv();
void vfunc_9__11TItemObjectFv();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void vfunc_12__5TItemFv();
void vfunc_13__5TItemFl();
void update_owned__11TItemObjectFv();
void update_equipped__5TItemFv();
void activate_effect__5TItemFl();
void set_attach_slot__5TItemFSc();
void equip__5TItemFv();
void unequip__5TItemFv();
void add_equip_stats__5TItemFl();
void remove_equip_stats__5TItemFl();
void subtract_item_stat_bonus__5TItemFllPs();
void subtract_equip_stats__5TItemFPvPsPs();
void render_equipped__5TItemFv();
void render_equipped_shadow__5TItemFv();
void render_equipped_deferred__5TItemFv();
void destroy__5TItemFv();
void vfunc_30__5TItemFv();
void use__11TItemObjectFv();
void get_attack_flags__5TItemFv();
void get_attach_slot__5TItemFv();
void vfunc_34__5TItemFv();
void is_identified__5TItemFv();
void get_amount__11TItemObjectFv();
void get_motion_type__5TItemFv();
void *lbl_8049FBC0[45] = {
    0, 0, (void *)__dt__13TUnk_8049FBC0Fv, (void *)run_task__5TItemFv, (void *)render__5TItemFv, (void *)render_shadows__5TItemFv, (void *)vfunc_6__13TUnk_804B9870FPsl, (void *)apply_object_set_data__13TUnk_804B9870FPv, (void *)reset_motion_fields__13TUnk_804AF8A0Fv, (void *)vfunc_9__11TItemObjectFv, (void *)update_object_view_visibility__5TItemFff, (void *)classify_actor_view_detail__13TUnk_804B9870Ffff, (void *)vfunc_12__5TItemFv, (void *)vfunc_13__5TItemFl, (void *)update_owned__11TItemObjectFv, (void *)update_in_inventory__5TItemFv, (void *)update_equipped__5TItemFv, (void *)activate_effect__5TItemFl, (void *)TItemObject__vt16, (void *)set_attach_slot__5TItemFSc, (void *)equip__5TItemFv, (void *)unequip__5TItemFv, (void *)add_equip_stats__5TItemFl, (void *)remove_equip_stats__5TItemFl, (void *)subtract_item_stat_bonus__5TItemFllPs, (void *)subtract_equip_stats__5TItemFPvPsPs, (void *)render_equipped__5TItemFv, (void *)render_equipped_shadow__5TItemFv, (void *)render_equipped_deferred__5TItemFv, (void *)destroy__5TItemFv, (void *)vfunc_30__5TItemFv, (void *)use__11TItemObjectFv, (void *)get_attack_flags__5TItemFv, (void *)get_attach_slot__5TItemFv, (void *)vfunc_34__5TItemFv, (void *)is_identified__5TItemFv, (void *)get_amount__11TItemObjectFv, (void *)remove_amount__11TItemObjectFl, (void *)add_amount__11TItemObjectFl, (void *)get_slot_count__5TItemFv, (void *)add_slot__5TItemFv, (void *)feed__5TItemFP9TItemData, (void *)vfunc_42__5TItemFv, (void *)get_motion_type__5TItemFv, (void *)vfunc_44__13TUnk_8049FBC0Fv
};

void TUnk_8049FBC0::vfunc_44() {
    switch (get_item_index__5TItemFv()) {
    case 0:
        ((TObjPlayer *)(this->m_f0))->add_stat_and_item(2);
        break;
    case 1:
        if (check_class_equip_permission((void *)this->m_f0, 0xD7) == 0) {
            ((TObjPlayer *)(this->m_f0))->add_mst_and_item(2);
        }
        break;
    case 2:
        ((TObjPlayer *)(this->m_f0))->add_evp_material(2);
        break;
    case 3:
        obj_getField1c((void *)this->m_f0);
        if (calc_equip_bonus__FUs() < 0xFA) {
            ((TObjPlayer *)(this->m_f0))->apply_speed_with_camera_scale((u8)(2));
        }
        break;
    case 4:
        obj_getField1c((void *)this->m_f0);
        if ((calc_stat_bonus_sum__FUs() < 0xFA) && (check_class_equip_permission((void *)this->m_f0, 0xD7) == 0)) {
            ((TObjPlayer *)(this->m_f0))->set_speed_scaled_by_camera((u8)(2));
        }
        break;
    case 5:
        ((TObjPlayer *)(this->m_f0))->add_dfp_material(2);
        break;
    case 6:
        ((TObjPlayer *)(this->m_f0))->apply_luck_reward(2);
        break;
    }
    ((VObj_18_ddf499 *)(this->m_f0))->m71();
}
void *__dt__13TUnk_8049FBC0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)lbl_8049FBC0;
        __dt__11TItemObjectFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

}
