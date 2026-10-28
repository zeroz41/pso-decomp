#include "pso/system/NinjaTypes.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemMagSub.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/system/byteswap.h"
#include "pso/TItemAttacker.h"
#include "pso/TItemLoad.h"
#include "pso/TObject.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TTecResta.h"
#include "pso/misc/TTecReverser.h"
#include "pso/misc/TTecSifta.h"
#include "pso/player/TObjPlayer.h"

#include "types.h"
#include "pso/item/TItemMag.h"

struct O_80110F04 { u8 pad[0x190]; f32 f190; f32 f194; };

struct TItemMag_80110B94 { u8 pad[0x1a8]; void *subs[2]; };

struct TItemMag_80111140 { u8 pad[0x1bd]; u8 a[4]; u8 b[4]; };

struct TItemMag_80111758 { u8 pad[0x1a8]; void *subs[2]; };

struct TItemMag_801112B8 {
    u8 pad0[0x18C];
    s32 f18C;
    u8 pad190[0x1A8 - 0x190];
    u8 *objs[2];
    s8 *types[2];
};

struct VBase_18_8b050c { char pad[0x18]; };

struct VObj_18_8b050c : VBase_18_8b050c {
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
    virtual s32 m44();
    virtual s32 m45();
};

struct Self_801124C4
{
  u8 pad[0x198];
  u8 data[1];
};

typedef struct Self_801124C4 Self_801124C4;

struct RecoveredFields_80113244_arg0 {
    u8 unknown_0[0x1CC];
    s32 field_1CC;
};

typedef struct TargetList_80112BC4 { s32 count; s16 ids[46]; } TargetList_80112BC4;

struct MagStats_80112A3C {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 e;
    s16 f;
    u8 pad[0x4];
};

struct Mag_80112A3C {
    u8 pad0[0x1A8];
    u8 *subs[2];
};

struct VBase_80112720 { u8 pad[0x18]; };

struct VObj_80112720 : VBase_80112720 {
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
    virtual s32 m14();
};
extern "C" {

void * memcpy(void *dst, const void *src, u32 n);
s32 get_main_phase();
s32 obj_isState2_324__13TUnk_804806E8Fv(int);
s16 obj_getS16_32C(s32);
s16 obj_getField1c(void *);
int get_item_field_6__10TObjPlayerFPv(void *p);
u8 get_item_group__5TItemFv(s32);
u8 * get_type__8TItemMagFv(s32);
s32 is_quest_active();
s32 is_flag_set__6TLobbyFv();
s32 test_action_mask__10TObjPlayerFl(s32, s32);
void *spawn_particle_effect(void *pos, s32 id);
s32 get_item_id__5TItemFv(int);
s32 apply_switch_attack__5TItemFl(void *, s32);
int set_item_group__5TItemFUc(s32, s32);
s32 send_activate_effect__5TItemFl(void *, s32);
s32 check_equip_requirements__5TItemFP10TObjPlayerPs(int, int, int);
s32 check_class_equip_permission(void *, int);
s32 activate_d04_slot__10TObjPlayerFv();
u8 get_item_index__5TItemFv();
void *lookup_item_pmt_record(u8 *item);
void try_add_action__8TItemMagFii(s32 arg0, s32 arg1);
void TItemMag__vt40(TItemMag_80110B94 *self);
void tick_fullness_timer__8TItemMagFPv(O_80110F04 *self);
u8 mag_owner_has_motion_action(void *arg0);
int TItemMag__sub_801112B0(void);
void select_action_motion__8TItemMagFPv(TItemMag_801112B8 *self);
s32 get_evolution_stage__8TItemMagFPv(void * _w0);
s32 get_max_stat_flags__8TItemMagFi(s32 arg0);
u8 evolve_rare_form__8TItemMagFPv(u8 *arg0);
void TItemMag__sub_8011271C(void);
s32 TItemMag__vt39(u8 *arg0, u8 *arg1);
void TItemMag__vt15(void* p, s32 _w1);
void update_protection__8TItemMagFv(u8 *self);
s16 TObjPlayer__sub_80113D90(void *p);
s16 get_mag_item_data(s32);
s16 get_mag_level(s32);
s16 get_mag_item_percent();
s32 get_mag_item_stat_percent(s32);
void TItemMag__sub_80113EDC(s32, s16, s8);
u32 test_flags__8TItemMagFUl(void *, s32);
void TItemMag__sub_80114198(u8 *mag, s16 arg1);
s16 get_mag_total_level(void *);
u8 * get_pmt_record__10TObjPlayerFi(u8);
void send_6x26_unequip_item__10TObjPlayerFPvPv(void *self, void *item);
}
s32 mag_owner_freezes_follow(void *arg0);
void mag_feed_add_mind(u8 *mag, s16 arg1);
void mag_feed_add_def(u8 *mag, s16 arg1);
s32 get_mag_feed_result(s32 arg0, s32 arg1);
void assign_default_photon_blast_palette_slots(u8 *arg0);
void assign_photon_blast_palette_slot(u8 *arg0, s32 arg1);
extern "C" {
s32 is_boss_area();
s32 play_sound_effect(int, int, int, int);
void create__10TTecDebandFlll(void *, void *, int);
s32 is_challenge_mode_active();
s32 rand();

extern s32 TItemMag__item_load_instance;
extern const f32 TItemMag__data_805DABA4;
extern const f32 TItemMag__data_805DABA8;
extern s32 lbl_8043E534[];
extern u8 lbl_8043E540[];
extern const f32 lbl_805DAB98;
extern const f32 lbl_805DAB9C;
extern const f32 lbl_805DABA0;
extern const f32 lbl_805DABAC;
extern const f32 lbl_805DABB0;
extern const f32 lbl_805DABB4;

#pragma push
#pragma inline_depth(4)
#pragma auto_inline off
#pragma dont_inline off
extern "C" s8 get_attach_slot__14TItemEquipBaseFv(TItemEquipBase *arg0);
extern "C" void vfunc_49__14TItemEquipBaseFv();
extern "C" void vfunc_48__14TItemEquipBaseFv();
extern "C" void TItemMag__vt48();
extern "C" void add_slot__5TItemFv();
extern "C" void vfunc_34__5TItemFv();
extern "C" void get_attack_flags__5TItemFv();
extern "C" void use__5TItemFv();
extern "C" void render_equipped_deferred__5TItemFv();
extern "C" void perform_action__5TItemFv();
extern "C" int update_object_view_visibility__5TItemFff(void *p);
extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void get_motion_type__5TItemFv();
extern "C" void vfunc_9__13TUnk_804B9870Fv();
extern "C" void add_equip_stats__14TItemEquipBaseFl();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void render__5TItemFv();
extern "C" void equip__14TItemEquipBaseFv();
extern "C" void get_name__5TItemFv();
extern "C" void reset_motion_fields__13TUnk_804AF8A0Fv();
extern "C" void remove_equip_stats__14TItemEquipBaseFl();
extern "C" void render_shadows__5TItemFv();
extern "C" int get_slot_count__5TItemFv(void);
extern "C" int add_amount__5TItemFl(void);
extern "C" int remove_amount__5TItemFl(void);
extern "C" int get_amount__5TItemFv(void);
extern "C" void is_identified__5TItemFv();
extern "C" void run_task__5TItemFv();
extern "C" void set_attach_slot__14TItemEquipBaseFSc();
extern "C" void subtract_equip_stats__14TItemEquipBaseFlPUcPUc();
extern "C" void subtract_item_stat_bonus__14TItemEquipBaseFllPs();
extern "C" void interact__5TItemFl();
extern "C" void unequip__14TItemEquipBaseFv();
extern "C" void update_equip__14TItemEquipBaseFv();
struct TItemMag_801138F0; struct Self_801134CC; struct Self_80113310; struct Self_801135E0;
extern "C" { void *__dt__8TItemMagFv(void *, s16); void TItemMag__vt12(s32); int TItemMag__vt13(void*); void TItemMag__vt14(Self_80113310*); void serialize_to_item__8TItemMagFPv(TItemMag *, void *); void TItemMag__vt24(Self_801135E0*); void TItemMag__vt25(Self_801134CC*); void TItemMag__vt42(TItemMag *); void TItemMag__vt43(u8*); void TItemMag__vt44(s32); void TItemMag__vt45(TItemMag_801138F0*); }
void *__vt__8TItemMag[51] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__8TItemMagFv, (void *)&run_task__5TItemFv,
    (void *)&render__5TItemFv, (void *)&render_shadows__5TItemFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804AF8A0Fv, (void *)&vfunc_9__13TUnk_804B9870Fv, (void *)&update_object_view_visibility__5TItemFff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__5TItemFv, (void *)&interact__5TItemFl, (void *)&TItemMag__vt12, (void *)&TItemMag__vt13,
    (void *)&TItemMag__vt14, (void *)&TItemMag__vt15, (void *)&serialize_to_item__8TItemMagFPv, (void *)&set_attach_slot__14TItemEquipBaseFSc,
    (void *)&equip__14TItemEquipBaseFv, (void *)&unequip__14TItemEquipBaseFv, (void *)&add_equip_stats__14TItemEquipBaseFl, (void *)&remove_equip_stats__14TItemEquipBaseFl,
    (void *)&subtract_item_stat_bonus__14TItemEquipBaseFllPs, (void *)&subtract_equip_stats__14TItemEquipBaseFlPUcPUc, (void *)&TItemMag__vt24, (void *)&TItemMag__vt25,
    (void *)&render_equipped_deferred__5TItemFv, (void *)&update_equip__14TItemEquipBaseFv, (void *)&perform_action__5TItemFv, (void *)&use__5TItemFv,
    (void *)&get_attack_flags__5TItemFv, (void *)&get_attach_slot__14TItemEquipBaseFv, (void *)&vfunc_34__5TItemFv, (void *)&is_identified__5TItemFv,
    (void *)&get_amount__5TItemFv, (void *)&remove_amount__5TItemFl, (void *)&add_amount__5TItemFl, (void *)&get_slot_count__5TItemFv,
    (void *)&add_slot__5TItemFv, (void *)&TItemMag__vt39, (void *)&TItemMag__vt40, (void *)&get_motion_type__5TItemFv,
    (void *)&TItemMag__vt42, (void *)&TItemMag__vt43, (void *)&TItemMag__vt44, (void *)&TItemMag__vt45,
    (void *)&vfunc_48__14TItemEquipBaseFv, (void *)&vfunc_49__14TItemEquipBaseFv, (void *)&TItemMag__vt48,
};
#define __vt__8TItemMag ((s32 *)__vt__8TItemMag)

inline f32 frand_80110A18(void) {
    f32 r = lbl_805DAB9C * (f32) rand();
    return r;
}
#pragma pop

#pragma push
#pragma inline_depth(4)
#pragma auto_inline off
#pragma dont_inline off
#pragma opt_lifetimes off
void TItemMag::resolve_sentinel_color() {
    u8 *arg0 = (u8 *)this;
    u8 v;

    if (check_class_equip_permission(this->m_f0, 0xD7) != 0) {
        v = (u8) *(s16 *)((s8 *)this->m_f0 + 0x896);
    } else {
        v = (u8) *(s16 *)((s8 *)this->m_f0 + 0x894);
    }
    v = v % 9;
    if (v >= 7) {
        v = lbl_805DAB98 * (lbl_805DAB9C * (f32) rand());
    }
    if (lbl_805DAB9C * (f32) rand() < lbl_805DABA0) {
        v += 9;
    }
    this->m_1a6 = v;
}
#pragma pop

void TItemMag::carry_over_stats(TItemData *data, TItem *mag) {
    u8 type = data->data1.data_u8[1];
    mag->copy_to_item_data(data);
    data->data1.data_u8[1] = type;
}

void try_add_action__8TItemMagFii(s32 arg0, s32 arg1) {
    if (((s32 (*)(void))get_evolution_stage__8TItemMagFPv)() < 4) {
        set_item_group__5TItemFUc(arg0, arg1);
    }
}

void TItemMag__vt40(TItemMag_80110B94 *self) {
    s32 i;
    for (i = 0; i != 2; i++) {
        if (self->subs[i] != 0) {
            ((TItemMagSub *)(self->subs[i]))->set_flags(2);
            TItemAttacker::spawn_item_timer((s32)self->subs[i], (s32)((void *)TItemMagSub::clear_optional_oscillation_flag), 0x1e);
        }
    }
}

s32 TItemMag::check_evolution_cond(u32 arg0, s32 arg1) {
    s32 temp_r3;
    s32 var_r30;

    if ((arg0 != 0U) && (temp_r3 = activate_d04_slot__10TObjPlayerFv(), ((temp_r3 == 0) == 0))) {
        switch (arg1) {
        case 0:
            if (get_item_index__5TItemFv() >= 0x64U) {
                return 1;
            }
            break;
        case 1:
            if (get_item_index__5TItemFv() >= 0x64U) {
                return 1;
            }
            break;
        case 2:
            var_r30 = 0;
            if (((s16 (*)(void))get_mag_item_stat_percent)() >= 0x46) {
                var_r30 = 1;
            }
            if (((s16 (*)(s32))get_mag_item_percent)(temp_r3) >= 0x46) {
                var_r30 += 1;
            }
            if (get_mag_level(temp_r3) >= 0x46) {
                var_r30 += 1;
            }
            if (get_mag_item_data(temp_r3) >= 0x46) {
                var_r30 += 1;
            }
            if (var_r30 >= 2) {
                return 1;
            }
            break;
        case 3:
            if (get_item_index__5TItemFv() >= 0x64U) {
                return 1;
            }
            break;
        case 4:
            if ((get_item_index__5TItemFv() >= 0x78U) && (((TObjPlayer *)temp_r3)->get_mag_data() >= 0xB4) && (TObjPlayer__sub_80113D90((void *)temp_r3) >= 0x6E)) {
                return 1;
            }
            break;
        case 5:
            if ((((s16 (*)(void))get_mag_item_stat_percent)() >= 0x23) && (((s16 (*)(s32))get_mag_item_percent)(temp_r3) >= 0x23) && (get_mag_level(temp_r3) >= 0x23) && (get_mag_item_data(temp_r3) >= 0x23)) {
                return 1;
            }
            break;
        }
    }
    return 0;
}

s32 TItemMag::check_feed_state(s32 arg1) {
    s16 temp_r3;

    temp_r3 = obj_getS16_32C(*(s32 *)&this->m_f0);
    if (arg1 == 7) {
        if (temp_r3 != 0) {
            return 0;
        }
        goto block_5;
    }
    if (temp_r3 == 0) {
        return 0;
    }
block_5:
    return 1;
}

void TItemMag::copy_owner_data() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    temp_r3 = get_pmt_record__10TObjPlayerFi(((int (*)(void))get_item_group__5TItemFv)());
    if (temp_r3 != NULL) {
        this->m_1b8 = (s32) *(s16 *)((s8 *)temp_r3 + 8);
        *(u8 *)((s8 *)arg0 + 0x1BC) = (u8) *(u8 *)((s8 *)temp_r3 + 0xB);
        copy_owner_pair(temp_r3 + 0xC, temp_r3 + 0x10);
    }
}

void TItemMag::register_photon_blasts() {
    s32 i;
    s32 slot;
    u8 *arg0 = (u8 *)this;
    assign_default_photon_blast_palette_slots((u8 *)(*(s32 *)((s8 *)arg0 + 0xF0) + 0x500));
    slot = 0;
    do {
        i = ((TItemMag *)(arg0 + 0x198))->get_photon_blast_at_slot(slot);
        if (i != -1) {
            TItemMag__sub_80113EDC(*(s32 *)((s8 *)arg0 + 0xF0) + 0x4AC, (s16) i, ((u8 (*)(void *)) get_item_index__5TItemFv)(arg0));
            assign_photon_blast_palette_slot(*(u8 **)((s8 *)arg0 + 0xF0) + 0x500, (s16) i);
        }
        slot += 1;
    } while (slot != 3);
}

void tick_fullness_timer__8TItemMagFPv(O_80110F04 *self) {
    if (TItemMag__data_805DABA4 != self->f190) {
        self->f190 -= TItemMag__data_805DABA8;
        if (TItemMag__data_805DABA4 == self->f190) {
            self->f194 = TItemMag__data_805DABA4;
        }
    }
}

u8 mag_owner_has_motion_action(void *arg0) {
    int var_r31;

    var_r31 = 0;
    if ((test_action_mask__10TObjPlayerFl(*(s32 *)((s8 *)arg0 + 0xF0), 4) != 0) || (test_action_mask__10TObjPlayerFl(*(s32 *)((s8 *)arg0 + 0xF0), 0x10) != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}
}

s32 mag_owner_freezes_follow(void *arg0) {
    s32 var_r31;

    var_r31 = 0;
    if (((u32) *(u32 *)((s8 *)arg0 + 0xF0) != 0U) && (((TItemMag *)(*(u32 *)((s8 *)arg0 + 0xF0)))->is_active() != 0)) {
        var_r31 = 1;
    }
    return var_r31;
}

s32 TItemMag::check_action_probability(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    u8 temp_r3;
    u8 var_r31;
    u8 var_r5;
    u8 *temp_r4;

    temp_r0 = *(s16 *)((s8 *)arg0 + 0x19A);
    if (temp_r0 < 0x1F) {
        var_r5 = 0;
    } else if (temp_r0 < 0x3D) {
        var_r5 = 0xF;
    } else if (temp_r0 < 0x51) {
        var_r5 = 0x19;
    } else if (temp_r0 < 0x65) {
        var_r5 = 0x1E;
    } else {
        var_r5 = 0x23;
    }
    temp_r4 = arg0 + arg1;
    var_r31 = 0;
    if ((u8) *(u8 *)((s8 *)temp_r4 + 0x1BD) != 0) {
        switch ((s32) (*(u8 *)((s8 *)temp_r4 + 0x1C1))) {
        case 0:
            var_r31 = *(u8 *)((s8 *)arg0 + 0x1BC);
            break;
        case 1:
            var_r31 = *(u8 *)((s8 *)arg0 + 0x1BC) + var_r5;
            break;
        case 2:
            var_r31 = var_r5;
            break;
        case 3:
            temp_r3 = *(u8 *)((s8 *)arg0 + 0x1BC);
            if (temp_r3 > 0xAU) {
                var_r31 = temp_r3 - 0xA;
            } else {
                var_r31 = 0;
            }
            break;
        case 4:
            if (var_r5 > 0xAU) {
                var_r31 = var_r5 - 0xA;
            } else {
                var_r31 = 0;
            }
            break;
        }
        if ((u8) (s32) (lbl_805DABAC * (lbl_805DAB9C * (f32) rand())) < var_r31) {
            return 1;
        }
        goto block_29;
    }
block_29:
    return 0;
}

void TItemMag::copy_owner_pair(void *a, void *b) {
    TItemMag_80111140 *self = (TItemMag_80111140 *)this;
    memcpy(self->a, a, 4);
    memcpy(self->b, b, 4);
}

void TItemMag::apply_transform_action(u8 arg1) {
    u8 temp_r31;
    temp_r31 = ((u8 (*)(void *))get_item_group__5TItemFv)(this);
    switch ((s32) arg1) {
    case 0:
        if (*(u8 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0xF0)) + 0x88C) & 1) {
            ((s32 (*)(void *, int))try_add_action__8TItemMagFii)(this, 0x1D);
        } else {
            ((s32 (*)(void *, int))try_add_action__8TItemMagFii)(this, 0x21);
        }
        break;
    case 1:
        if (*(u8 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0xF0)) + 0x88C) & 1) {
            ((s32 (*)(void *, int))try_add_action__8TItemMagFii)(this, 0x22);
        } else {
            ((s32 (*)(void *, int))try_add_action__8TItemMagFii)(this, 0x27);
        }
        break;
    case 2:
        ((s32 (*)(void *, int))try_add_action__8TItemMagFii)(this, 0x28);
        break;
    case 3:
        ((s32 (*)(void *, int))try_add_action__8TItemMagFii)(this, 0x29);
        break;
    case 4:
        ((s32 (*)(void *, int))try_add_action__8TItemMagFii)(this, 0x2A);
        break;
    case 5:
        ((s32 (*)(void *, int))try_add_action__8TItemMagFii)(this, 0x2B);
        break;
    }
    if (temp_r31 != ((u8 (*)(void *))get_item_group__5TItemFv)(this)) {
        this->apply_form_change();
    }
}

int TItemMag__sub_801112B0(void) { return 0; }

void select_action_motion__8TItemMagFPv(TItemMag_801112B8 *self) {
    s32 i;
    u8 *o;
    s16 lv;
    for (i = 0; i != 2; i++) {
        o = self->objs[i];
        if (o != NULL) {
            lv = self->f18C & 0xF;
            if (lv > 0 && lv < 6) {
                ((TItemMagSub *)o)->transition_motion_type(self->types[i][lv - 1]);
            } else if (lv >= 6 && lv < 8) {
                ((TItemMagSub *)o)->transition_motion_type(self->types[i][5]);
            } else if (lv == 8) {
                ((TItemMagSub *)o)->transition_motion_type(self->types[i][3]);
            }
        }
    }
}

void TItemMag::set_subs_visible(s32 on) {
    TItemMag_80111758 *self = (TItemMag_80111758 *)this;
    s32 i;
    for (i = 0; i != 2; i++) {
        if (self->subs[i] != 0) {
            if (on) {
                ((TQuestVmDownLoadServer *)(self->subs[i]))->clear_flag4_bit4();
            } else {
                ((TObject *)(self->subs[i]))->suspend_update();
            }
        }
    }
}

s32 get_evolution_stage__8TItemMagFPv(void * _w0) {
    u8 temp_r3;
    u8 var_r31;
    temp_r3 = ((u8 (*)(void *))get_item_group__5TItemFv)(_w0);
    var_r31 = temp_r3;
    if (temp_r3 >= 0x42U) {
        var_r31 = 0x42;
    }
    if (var_r31 <= 0x42U) {
        return *(s8 *)((s8 *)(*(s32 *)((s8 *)(get_type__8TItemMagFv(TItemMag__item_load_instance)) + 0x14)) + var_r31);
    }
    return 0;
}

s32 get_max_stat_flags__8TItemMagFi(s32 arg0) {
    s32 var_r31;
    s16 mag_item_percent;
    s16 mag_level;
    s16 mag_item_data;
    s16 var_r0;
    s32 var_r4;

    var_r31 = 0;
    mag_item_percent = get_mag_item_percent();
    mag_level = get_mag_level(arg0);
    mag_item_data = get_mag_item_data(arg0);
    get_mag_item_stat_percent(arg0);
    if ((mag_level < mag_item_percent) && (mag_item_data < mag_item_percent)) {
        var_r31 |= 8;
    }
    if ((mag_item_percent < mag_level) && (mag_item_data < mag_level)) {
        var_r31 |= 0x10;
    }
    if ((mag_level < mag_item_data) && (mag_item_percent < mag_item_data)) {
        var_r31 |= 0x20;
    }
    var_r0 = mag_level;
    var_r4 = 0;
    if (mag_item_percent > mag_level) {
        var_r0 = mag_item_percent;
    }
    if (var_r0 > mag_item_data) {
        var_r0 = mag_level;
        if (mag_item_percent > mag_level) {
            var_r0 = mag_item_percent;
        }
    } else {
        var_r0 = mag_item_data;
    }
    {
        s32 max32 = var_r0;
        if (mag_item_percent == max32) {
            var_r4 = 1;
        }
        if (mag_level == max32) {
            var_r4 += 1;
        }
        if (mag_item_data == max32) {
            var_r4 += 1;
        }
    }
    if (var_r4 >= 2) {
        var_r31 |= 0x100;
    }
    return var_r31;
}

u8 evolve_rare_form__8TItemMagFPv(u8 *arg0) {
    s16 stat;
    s16 data;
    s16 level;
    u8 before;
    s32 idx;
    s16 pct;
    s8 group;
    before = ((u8 (*)(void *))get_item_group__5TItemFv)(arg0);
    if (*(u8 **)((s8 *)arg0 + 0xF0) != NULL && get_mag_total_level(arg0 + 0x198) >= 100) {
        group = (s8)*(u8 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xF0)) + 0x88C) % 3;
        pct = ((s16 (*)(s32))get_mag_item_percent)((s32)arg0);
        level = get_mag_level((s32)arg0);
        data = get_mag_item_data((s32)arg0);
        stat = ((s16 (*)(s32))get_mag_item_stat_percent)((s32)arg0);
        idx = (u32)__cntlzw(check_class_equip_permission(*(u8 **)((s8 *)arg0 + 0xF0), 0x7F)) >> 5;
        idx += group * 2;
        if (check_class_equip_permission(*(u8 **)((s8 *)arg0 + 0xF0), 0xF9) == 0) {
            if (check_class_equip_permission(*(u8 **)((s8 *)arg0 + 0xF0), 0xFA) != 0) {
                idx += 6;
            } else if (check_class_equip_permission(*(u8 **)((s8 *)arg0 + 0xF0), 0xFC) != 0) {
                idx += 12;
            }
        }
        if (check_class_equip_permission(*(u8 **)((s8 *)arg0 + 0xF0), 0xF9) != 0) {
            switch (group) {
            case 0:
                if (pct + data == stat + level) {
                    ((void (*)(void *, int))try_add_action__8TItemMagFii)(arg0, lbl_8043E540[idx]);
                }
                break;
            case 1:
                if (pct + level == data + stat) {
                    ((void (*)(void *, int))try_add_action__8TItemMagFii)(arg0, lbl_8043E540[idx]);
                }
                break;
            case 2:
                if (pct + stat == data + level) {
                    ((void (*)(void *, int))try_add_action__8TItemMagFii)(arg0, lbl_8043E540[idx]);
                }
                break;
            }
        } else if (check_class_equip_permission(*(u8 **)((s8 *)arg0 + 0xF0), 0xFA) != 0) {
            switch (group) {
            case 0:
                if (pct + data == stat + level) {
                    ((void (*)(void *, int))try_add_action__8TItemMagFii)(arg0, lbl_8043E540[idx]);
                }
                break;
            case 1:
                if (pct + level == data + stat) {
                    ((void (*)(void *, int))try_add_action__8TItemMagFii)(arg0, lbl_8043E540[idx]);
                }
                break;
            case 2:
                if (pct + stat == data + level) {
                    ((void (*)(void *, int))try_add_action__8TItemMagFii)(arg0, lbl_8043E540[idx]);
                }
                break;
            }
        } else if (check_class_equip_permission(*(u8 **)((s8 *)arg0 + 0xF0), 0xFC) != 0) {
            switch (group) {
            case 0:
                if (pct + data == stat + level) {
                    ((void (*)(void *, int))try_add_action__8TItemMagFii)(arg0, lbl_8043E540[idx]);
                }
                break;
            case 1:
                if (pct + level == data + stat) {
                    ((void (*)(void *, int))try_add_action__8TItemMagFii)(arg0, lbl_8043E540[idx]);
                }
                break;
            case 2:
                if (pct + stat == data + level) {
                    ((void (*)(void *, int))try_add_action__8TItemMagFii)(arg0, lbl_8043E540[idx]);
                }
                break;
            }
        }
    }
    return ((u8 (*)(void *))get_item_group__5TItemFv)(arg0) != before;
}

void TItemMag::update_feed_anim() {
    s16 temp_r26;
    s16 temp_r29;
    s16 temp_r30;
    s16 temp_r31;
    s32 temp_r25;
    s8 temp_r28;
    void *temp_r4;

    if ((void *) this->m_f0 != NULL) {
        temp_r25 = ((s32 (*)(void))get_max_stat_flags__8TItemMagFi)();
        temp_r4 = this->m_f0;
        temp_r28 = (s8) *(u8 *)((s8 *)temp_r4 + 0x88C);
        temp_r29 = ((s16 (*)(void *, void *))get_mag_item_percent)(this, temp_r4);
        temp_r30 = ((s16 (*)(void *))get_mag_level)(this);
        temp_r31 = ((s16 (*)(void *))get_mag_item_data)(this);
        temp_r26 = ((s16 (*)(void *))get_mag_item_stat_percent)(this);
        if (((s32 (*)(void *, s32))check_class_equip_permission)(this->m_f0, 0xF9) != 0) {
            if (temp_r25 & 0x108) {
                if (!(temp_r28 & 1)) {
                    if (temp_r31 <= temp_r30) {
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 5);
                        return;
                    }
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0xC);
                    return;
                }
                if (temp_r31 <= temp_r30) {
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 6);
                    return;
                }
                ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 8);
                return;
            }
            if (temp_r25 & 0x10) {
                if (!(temp_r28 & 1)) {
                    if (temp_r29 <= temp_r31) {
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x13);
                        return;
                    }
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x17);
                    return;
                }
                if (temp_r29 <= temp_r31) {
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x10);
                    return;
                }
                ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x12);
                return;
            }
            if (temp_r25 & 0x20) {
                if (!(temp_r28 & 1)) {
                    if (temp_r30 <= temp_r29) {
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x1E);
                        return;
                    }
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 7);
                    return;
                }
                if (temp_r30 <= temp_r29) {
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x24);
                    return;
                }
                ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x16);
            }
        } else if (((s32 (*)(void *, s32))check_class_equip_permission)(this->m_f0, 0xFA) != 0) {
            if (temp_r25 & 0x110) {
                if (!(temp_r28 & 1)) {
                    if (temp_r29 <= temp_r31) {
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 6);
                        return;
                    }
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0xC);
                    return;
                }
                if (temp_r29 <= temp_r31) {
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 5);
                    return;
                }
                ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0xA);
                return;
            }
            if (temp_r25 & 8) {
                if (!(temp_r28 & 1)) {
                    if (temp_r31 <= temp_r30) {
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 6);
                        return;
                    }
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0xC);
                    return;
                }
                if (temp_r31 <= temp_r30) {
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x26);
                    return;
                }
                ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0xA);
                return;
            }
            if (temp_r25 & 0x20) {
                if (!(temp_r28 & 1)) {
                    if (temp_r30 <= temp_r29) {
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 5);
                        return;
                    }
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 8);
                    return;
                }
                if (temp_r30 <= temp_r29) {
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x1E);
                    return;
                }
                ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x18);
            }
        } else if (((s32 (*)(void *, s32))check_class_equip_permission)(this->m_f0, 0xFC) != 0) {
            if (temp_r25 & 0x120) {
                if (temp_r26 <= 0x2C) {
                    if (!(temp_r28 & 1)) {
                        if (temp_r30 <= temp_r29) {
                            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x1C);
                            return;
                        }
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x1E);
                        return;
                    }
                    if (temp_r30 <= temp_r29) {
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 9);
                        return;
                    }
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x17);
                    return;
                }
                ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x24);
                return;
            }
            if (temp_r25 & 8) {
                if (temp_r26 <= 0x2C) {
                    if (!(temp_r28 & 1)) {
                        if (temp_r31 <= temp_r30) {
                            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x25);
                            return;
                        }
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x1F);
                        return;
                    }
                    if (temp_r31 <= temp_r30) {
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x20);
                        return;
                    }
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x1C);
                    return;
                }
                ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x23);
                return;
            }
            if (temp_r25 & 0x10) {
                if (temp_r26 <= 0x2C) {
                    if (!(temp_r28 & 1)) {
                        if (temp_r29 <= temp_r31) {
                            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x11);
                            return;
                        }
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x15);
                        return;
                    }
                    if (temp_r29 <= temp_r31) {
                        ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0xC);
                        return;
                    }
                    ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x12);
                    return;
                }
                ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)(this, 0x24);
            }
        }
    }
}

void TItemMag::do_action_by_class() {
    s32 arg0 = (s32)this;
    s32 temp_r31;
    u8 temp_r3;

    temp_r31 = ((s32 (*)(void))get_max_stat_flags__8TItemMagFi)();
    temp_r3 = get_item_group__5TItemFv(arg0);
    switch ((s32) temp_r3) {
    case 1:
        if (temp_r31 & 0x108) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)arg0, 0xE);
            return;
        }
        if (temp_r31 & 0x10) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)arg0, 0xF);
            return;
        }
        if (temp_r31 & 0x20) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)arg0, 4);
        }
        break;
    case 13:
        if (temp_r31 & 0x110) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)arg0, 2);
            return;
        }
        if (temp_r31 & 8) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)arg0, 3);
            return;
        }
        if (temp_r31 & 0x20) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)arg0, 0xB);
            return;
        }
        break;
    case 25:
        if (temp_r31 & 0x120) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)arg0, 0x1A);
            return;
        }
        if (temp_r31 & 8) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)arg0, 0x1B);
            return;
        }
        if (temp_r31 & 0x10) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)arg0, 0x14);
        }
        break;
    }
}

void TItemMag::evolve_first_form() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    temp_r3 = (u8 *)this->m_f0;
    if (temp_r3 != NULL) {
        if (((s32 (*)(void *, s32))check_class_equip_permission)(temp_r3, 0xF9) != 0) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)((s32) arg0), 1);
            return;
        }
        if (((s32 (*)(void *, s32))check_class_equip_permission)(this->m_f0, 0xFA) != 0) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)((s32) arg0), 0xD);
            return;
        }
        if (((s32 (*)(void *, s32))check_class_equip_permission)(this->m_f0, 0xFC) != 0) {
            ((s32 (*)(void *, s32))try_add_action__8TItemMagFii)((void *)((s32) arg0), 0x19);
        }
    }
}

void TItemMag::apply_form_change() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    temp_r3 = (u8 *)(((u8 * (*)(int))get_pmt_record__10TObjPlayerFi)((s32) get_item_group__5TItemFv((s32)arg0)));
    if (temp_r3 != NULL) {
        ((TItemMag *)(arg0 + 0x198))->add_photon_blast((int) (*(u8 *)((s8 *)temp_r3 + 0xA)));
    }
    if (((TItem *)arg0)->get_mode() == 2) {
        ((VObj_18_8b050c *)(arg0))->m45();
        *(s32 *)&this->m_18c = (s32) (*(s32 *)&this->m_18c | 0x40);
        ((VObj_18_8b050c *)(arg0))->m44();
        ((TItemMag *)arg0)->register_photon_blasts();
    }
    if (((TItem *)arg0)->is_hidden() == 0) {
        play_sound_effect(0x4000B20A, (int) (*(s32 *)&this->m_f0 + 0x38), 0, 0);
    }
    copy_owner_data();
}

void TItemMag::apply_natural_evolution() {
  unsigned int new_var;
  s32 stage;
  s16 level;
  u8 before;
  stage = ((s8 (*)(void *))get_evolution_stage__8TItemMagFPv)(this);
  level = get_mag_total_level(((Self_801124C4 *)this)->data);
  before = get_item_group__5TItemFv((s32) this);
  {
    new_var = (s32) this;
    if ((lbl_8043E534[0] <= level) && (level < lbl_8043E534[1]))
    {
      if (stage < 1)
      {
        this->evolve_first_form();
      }
    }
    else
      if ((lbl_8043E534[1] <= level) && (level < lbl_8043E534[2]))
    {
      if (stage < 2)
      {
        ((TItemMag *)new_var)->do_action_by_class();
      }
    }
    else
      if ((((lbl_8043E534[2] <= level) && ((level % 5) == 0)) && (stage <= 3)) && (((s32 (*)(void *))evolve_rare_form__8TItemMagFPv)(this) == 0))
    {
      this->update_feed_anim();
    }
    if (before != get_item_group__5TItemFv(new_var))
    {
      this->apply_form_change();
    }
  }
}

void TItemMag::feed_by_item_flags(s8 arg1) {
    rand();
    if (arg1 & 0x40) {
        if (check_action_probability(0) != 0) {
            request_support_action(this->m_1bd);
        }
    } else if (arg1 & 1) {
        if (check_action_probability(1) != 0) {
            request_support_action(*(u8 *)((s8 *)this + 0x1BE));
        }
    } else if (arg1 & 2) {
        if (check_action_probability(2) != 0) {
            request_support_action(this->m_1bf);
        }
    } else if (arg1 & 0x80) {
        if (check_action_probability(3) != 0) {
            request_support_action(*(u8 *)((s8 *)this + 0x1C0));
        }
    } else {
        if (arg1 & 0x20) {
            request_support_action(2U);
            return;
        }
        if (arg1 & 0x10) {
            request_support_action(3U);
            return;
        }
        if (arg1 & 4) {
            request_support_action(5U);
            return;
        }
        if (arg1 & 8) {
            request_support_action(4U);
        }
    }
}

void TItemMag__sub_8011271C(void) {  }

s8 TItemMag::collect_support_events() {
    u8 *arg0 = (u8 *)this;
    s16 delta;
    s16 cur;
    s16 lim;
    s32 g;
    s8 ev;

    if (!(*(s32 *)&this->m_18c & 1)) {
        return 0;
    }
    delta = 0;
    cur = obj_getS16_32C(*(s32 *)&this->m_f0);
    lim = ((TItemProShield *)(*(void * *)&this->m_f0))->get_field_2b8();
    ev = 0;
    if (*(s16 *)&this->m_1dc != cur) {
        if (cur < *(s16 *)&this->m_1dc) {
            delta = *(s16 *)&this->m_1dc - cur;
        }
        *(s16 *)&this->m_1dc = cur;
    }
    if (cur == 0) {
        if (test_flags__8TItemMagFUl(arg0 + 0x1D4, 2) == 0) {
            if (get_main_phase() == 0xE) {
                ev |= 2;
            }
            ((TItemMag *)(arg0 + 0x1D4))->set_flags(2);
            ((TItemMag *)(arg0 + 0x198))->add_clamped_stat(-5);
        }
    } else if (test_flags__8TItemMagFUl(arg0 + 0x1D4, 2) != 0) {
        ((TItemMag *)(arg0 + 0x1D4))->clear_feed_flags(2);
    }
    if (cur * 10 < lim && lim <= delta * 5) {
        if (test_flags__8TItemMagFUl(arg0 + 0x1D4, 1) == 0) {
            ev |= 1;
            ((TItemMag *)(arg0 + 0x1D4))->set_flags(1);
        }
    } else if (test_flags__8TItemMagFUl(arg0 + 0x1D4, 1) != 0) {
        ((TItemMag *)(arg0 + 0x1D4))->clear_feed_flags(1);
    }
    if (*(s16 *)((s8 *)arg0 + 0x19A) < 0x1E) {
        if (test_flags__8TItemMagFUl(arg0 + 0x1D4, 4) == 0) {
            ev |= 4;
            ((TItemMag *)(arg0 + 0x1D4))->set_flags(4);
        }
    } else if (*(s16 *)((s8 *)arg0 + 0x19A) > 0x64) {
        if (test_flags__8TItemMagFUl(arg0 + 0x1D4, 8) == 0) {
            ev |= 8;
            ((TItemMag *)(arg0 + 0x1D4))->set_flags(8);
        }
    } else {
        ((TItemMag *)(arg0 + 0x1D4))->clear_feed_flags(0xC);
    }
    if (*(s16 *)&this->m_1d4 < (*(VObj_80112720 * *)&this->m_f0)->m14()) {
        *(s16 *)&this->m_1d4 = (*(VObj_80112720 * *)&this->m_f0)->m14();
        ev |= 0x20;
    }
    g = TOKeyMachine01::get_global_state();
    if (this->m_1d6 != g) {
        this->m_1d6 = g;
        if (is_boss_area() == 1) {
            ev |= 0x80;
        }
    }
    if (lbl_805DABAC == (f32)((TItemMag *)(*(void * *)&this->m_f0))->get_sub_value() &&
        test_flags__8TItemMagFUl(arg0 + 0x1D4, 0x40) == 0) {
        ((TItemMag *)(arg0 + 0x1D4))->set_flags(0x40);
        ev |= 0x40;
    } else if ((f32)((TItemMag *)(*(void * *)&this->m_f0))->get_sub_value() < lbl_805DABAC &&
               test_flags__8TItemMagFUl(arg0 + 0x1D4, 0x40) != 0) {
        ((TItemMag *)(arg0 + 0x1D4))->clear_feed_flags(0x40);
    }
    if (test_flags__8TItemMagFUl(arg0 + 0x1D4, 0x10) != 0) {
        ((TItemMag *)(arg0 + 0x1D4))->clear_feed_flags(0x10);
        ev |= 0x10;
    }
    return ev;
}

s32 TItemMag__vt39(u8 *arg0, u8 *item) {
    MagStats_80112A3C stats;
    u8 pos[0xC];
    s32 *rec;
    u8 *tbl;
    s32 i;
    if (item == NULL) {
        return 0;
    }
    ((TItemData *)(&stats))->initialize_mag_data();
    stats.a = 0;
    stats.b = 0;
    stats.f = 0;
    stats.e = 0;
    stats.d = 0;
    stats.c = 0;
    if (*item == 3) {
        rec = (s32 *)lookup_item_pmt_record(item);
        if (rec != NULL) {
            tbl = (u8 *)get_mag_feed_result(*(s32 *)((s8 *)arg0 + 0x1B8), *rec);
            if (tbl != NULL) {
                stats.c = (s8)tbl[0];
                stats.d = (s8)tbl[1];
                stats.e = (s8)tbl[2];
                stats.f = (s8)tbl[3];
                stats.a = (s8)tbl[4];
                stats.b = (s8)tbl[5];
                ((TItemMag *)(arg0 + 0x1D4))->set_flags(0x10);
                if (TItemMag__data_805DABA4 != *(f32 *)((s8 *)arg0 + 0x190)) {
                    *(f32 *)((s8 *)arg0 + 0x194) = *(f32 *)((s8 *)arg0 + 0x194) + TItemMag__data_805DABA8;
                } else {
                    *(f32 *)((s8 *)arg0 + 0x190) = lbl_805DABB0;
                }
            }
        }
    }
    if (((TItem *)arg0)->is_hidden() == 0) {
        for (i = 0; i != 2; i++) {
            if (((Mag_80112A3C *)arg0)->subs[i] != NULL &&
                ((TItemMagSub *)(((Mag_80112A3C *)arg0)->subs[i]))->get_world_position(pos) != 0) {
                spawn_particle_effect(pos, 0x9B);
            }
        }
        ((void (*)(int, int, int, int))play_sound_effect)(0x5B211, *(s32 *)((s8 *)arg0 + 0xF0) + 0x38, 0, 0);
    }
    return ((TItemMag *)arg0)->apply_feed_stats((u8 *)&stats);
}

void TItemMag::cast_support_technique(s32 technique) {
    u8 *self = (u8 *)this;
    TargetList_80112BC4 targets;
    s32 level = *(s16 *)((s8 *)self + 0x198) / 40;
    if (*(u8 * *)&this->m_f0 == NULL) {
        return;
    }
    switch (technique) {
    case 13:
        TTecSifta::create((void *)(*(u8 * *)&this->m_f0), (void *)(*(u8 * *)&this->m_f0 + 0x38), (void *)level);
        break;
    case 10:
        create__10TTecDebandFlll(*(u8 * *)&this->m_f0, *(u8 * *)&this->m_f0 + 0x38, level);
        break;
    case 15:
        TTecResta::create((void *)(*(u8 * *)&this->m_f0), (void *)(*(u8 * *)&this->m_f0 + 0x38), (void *)level);
        break;
    case 17:
        ((TObjPlayer *)(&targets))->construct_target_cursor_records();
        targets.count = 1;
        targets.ids[0] = obj_getField1c(*(u8 * *)&this->m_f0);
        targets.ids[1] = 0;
        TTecReverser::create((void *)(*(u8 * *)&this->m_f0), (void *)(*(u8 * *)&this->m_f0 + 0x38), &targets, (void *)level);
        break;
    case 11:
        return;
    case 12:
        return;
    case 14:
        return;
    case 16:
        return;
    }
}

s32 TItemMag::apply_feed_stats(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    if (arg1 != NULL) {
        mag_feed_add_def((arg0 + 0x198), (*(s16 *)((s8 *)arg1 + 4)));
        ((TItemMag *)(arg0 + 0x198))->add_stat_level_capped((int) (*(s16 *)((s8 *)arg1 + 6)));
        mag_feed_add_mind((arg0 + 0x198), (*(s16 *)((s8 *)arg1 + 0xA)));
        TItemMag__sub_80114198((arg0 + 0x198), (*(s16 *)((s8 *)arg1 + 8)));
        TItemMag::add_stat_clamped((s16 *)(arg0 + 0x198), (s32)((int) (*(s16 *)((s8 *)arg1 + 0))));
        ((TItemMag *)(arg0 + 0x198))->add_clamped_stat((int) (*(s16 *)((s8 *)arg1 + 2)));
        ((TItem *)arg0)->set_item_index((u8)((void *) (((u8 (*)(void *))get_mag_total_level)(arg0 + 0x198))));
        if (((TItem *)arg0)->get_mode() == 2) {
            ((TItemEquipBase *)arg0)->refresh_owner_stats();
            if (obj_isState2_324__13TUnk_804806E8Fv((int)this->m_f0) == 0) {
                arg1 = (u8 *) get_item_field_6__10TObjPlayerFPv(this->m_f0);
                if ((arg1 != NULL) && (check_equip_requirements__5TItemFP10TObjPlayerPs((int)arg1, (int)this->m_f0, 0) == 0)) {
                    send_6x26_unequip_item__10TObjPlayerFPvPv(this->m_f0, (void *)(get_item_id__5TItemFv((int)arg1)));
                }
            }
        }
        ((TItemMag *)arg0)->apply_natural_evolution();
        return 1;
    }
    return 0;
}

void TItemMag__vt15(void* p, s32 _w1) { ((TItemMag *)p)->select_support_action(_w1); }

void TItemMag::select_support_action(s32 arg1) {
    s32 temp_r4;
    this->apply_feed_delta();
    *(s32 *)((s8 *)((u8 *)this) + 0x18C) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x18C) & 0xF0);
    temp_r4 = *(s32 *)((s8 *)((u8 *)this) + 0x18C) | arg1;
    *(s32 *)((s8 *)((u8 *)this) + 0x18C) = temp_r4;
    *(f32 *)((s8 *)((u8 *)this) + 0x1C8) = (f32) lbl_805DABB4;
    *(s32 *)((s8 *)((u8 *)this) + 0x1CC) = 0;
    ((s32 (*)(void *, int))select_action_motion__8TItemMagFPv)(this, temp_r4);
    this->set_subs_visible(1);
}

void TItemMag::request_support_action(s32 arg1) {
    if ((is_flag_set__6TLobbyFv() != 0 || is_challenge_mode_active() != 0) && (arg1 == 7 || arg1 == 6)) {
        return;
    }
    if (is_quest_active() != 0 && arg1 == 7) {
        return;
    }
    if (arg1 != 1) {
        if (get_status_flag() != 0 && !(TItemMag__data_805DABA4 < this->m_1c8) && check_feed_state(arg1) != 0) {
            send_activate_effect__5TItemFl(this, arg1);
        }
    } else {
        select_support_action(arg1);
    }
}

void TItemMag::transfer_energy() {
    u32 temp_r3;
    s32 temp_r4;

    temp_r3 = *(u32 *)&this->m_f0;
    if ((temp_r3 != 0U) && (((TItemMag *)(temp_r3 + 0x644))->get_mag_id() == 0)) {
        temp_r4 = *(s32 *)&this->_pad1D0 - *(s32 *)&this->m_1cc;
        if (temp_r4 > 0) {
            ((TObjPlayer *)(*(u32 *)&this->m_f0 + 0x644))->set_type(temp_r4);
        }
    }
}

void TItemMag::apply_feed_delta() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;

    if (((u32) *(u32 *)&this->m_f0 != 0U) && (test_flags__8TItemMagFUl(arg0 + 0x1D4, 0x100) != 0U)) {
        temp_r4 = *(s32 *)&this->_pad1D0 - *(s32 *)&this->m_1cc;
        if (temp_r4 > 0) {
            TObjPlayer::decrement_clamp((s32 *)(*(u32 *)&this->m_f0 + 0x644), (s32)temp_r4);
        }
        ((TItemMag *)(arg0 + 0x1D4))->clear_feed_flags(0x100);
    }
}

void update_protection__8TItemMagFv(u8 *self) {
    *(s32 *)((s8 *)self + 0x1D0) = (s32) (lbl_805DABB4 * (f32) ((((s16) ((TItemMag *)(self + 0x198))->get_sync() + (s16) ((TItemMag *)(self + 0x198))->get_item_type()) / 3) + 40));
    if (*(s32 *)((s8 *)self + 0x1D0) > 900) {
        *(s32 *)((s8 *)self + 0x1D0) = 900;
    }
    if (*(u32 *)((s8 *)self + 0xF0) != 0 && ((TItemMag *)(*(u32 *)((s8 *)self + 0xF0) + 0x644))->get_mag_id() < *(s32 *)((s8 *)self + 0x1D0)) {
        ((TObjPlayer *)(*(s32 *)((s8 *)self + 0xF0) + 0x644))->set_type(*(s32 *)((s8 *)self + 0x1D0));
        ((TItemMag *)(self + 0x1D4))->set_flags(0x100);
    }
}

void TItemMag::update_feed_timer() {
    if ((s32) *(s32 *)&this->m_1cc == 0) {
        ((s32 (*)(void))update_protection__8TItemMagFv)();
    }
    transfer_energy();
    if ((s32) *(s32 *)&this->_pad1D0 <= (s32) *(s32 *)&this->m_1cc) {
        apply_feed_delta();
        request_support_action((s32)((void*)(1)));
    }
    if ((*(s32 *)&this->m_1cc % 60) == 0) {
        apply_switch_attack__5TItemFl(this, 0x6C);
    }
}

void TItemMag::feed_if_over_90() { if (*(int *)&this->m_1cc > 90) { request_support_action((s32)((void*)((void*)1))); } }

void TItemMag::feed_if_over_45() { if (*(int *)&this->m_1cc > 45) { request_support_action((s32)((void*)((void*)1))); } }

void TItemMag::update_feed() {
    s32 temp_r0;

    temp_r0 = this->m_1cc;
    if ((temp_r0 != 0x5A) && (temp_r0 > 0x5A)) {
        request_support_action((s32)((void*)(1)));
    }
}

void TItemMag::check_level_cap() {
    s32 temp_r0;

    temp_r0 = this->m_1cc;
    if (temp_r0 == 0x5A) {
        cast_support_technique(0x11);
        return;
    }
    if (temp_r0 > 0x5A) {
        request_support_action((s32)((void*)(1)));
    }
}

void TItemMag::check_level_evolve() {
    s32 temp_r0;

    temp_r0 = this->m_1cc;
    if (temp_r0 == 0x5A) {
        if (obj_getS16_32C(*(s32 *)&this->m_f0) > 0) {
            cast_support_technique(0xF);
        }
    } else if (temp_r0 > 0x5A) {
        request_support_action((s32)((void*)(1)));
    }
}

void TItemMag::apply_auto_support_techniques() {
    struct RecoveredFields_80113244_arg0 *arg0 = (struct RecoveredFields_80113244_arg0 *)this;
    s32 temp_r0;
    temp_r0 = arg0->field_1CC;
    if (temp_r0 == 0x5A) {
        cast_support_technique(0xD);
        cast_support_technique(0xA);
        return;
    }
    if (temp_r0 > 0x5A) {
        request_support_action((s32)((void*)(1)));
    }
}
#pragma push
#pragma dont_inline on

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
    virtual s16 m14();
};

struct Base_801139F4 { s32 x0; u8 pad[0x14]; };

struct Mag_801139F4 : Base_801139F4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(s32);
    u8 pad1c[0x170];
    s32 x18c;
    f32 x190;
    f32 x194;
    u8 data198[0xC];
    u8 flags1a4;
    u8 pad1a5[3];
    s32 x1a8[2];
    s32 x1b0[2];
    u8 pad1b8[0x10];
    f32 x1c8;
};

struct TItemMag_801138F0 { u8 pad[0x1a8]; void *subs[2]; };

struct VBase_18_801134CC { char pad[0x18]; };

struct VObj_18_801134CC : VBase_18_801134CC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

struct Owner_801134CC { u8 pad[0x5B0]; u8 stats[1]; };

struct Self_801134CC {
    u8 pad0[0xF0];
    Owner_801134CC *owner;
    u8 pad1[0x1A8 - 0xF4];
    VObj_18_801134CC *subs[2];
};

struct Self_80113310 {
    u8 pad0[0x18C];
    u32 f18C;
    u8 pad1[0x1CC - 0x190];
    s32 f1CC;
};

struct VBase_18_801135E0 { char pad[0x18]; };

struct VObj_18_801135E0 : VBase_18_801135E0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

struct Owner_801135E0 { u8 pad[0x5B0]; u8 stats[1]; };

struct Self_801135E0 {
    u8 pad0[0xF0];
    Owner_801135E0 *owner;
    u8 pad1[0x1A8 - 0xF4];
    VObj_18_801135E0 *subs[2];
};

struct Grp_80113B6C { u32 a, b, c, d; };

struct Rec_80113B6C {
    u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; u32 f14; u32 f18; u32 f1C;
    u32 f20; u32 f24; u32 f28; u32 f2C; u32 f30;
    Grp_80113B6C g[3];
};

extern "C" {
void TItemMag__vt12(s32 arg0);
s16 obj_getS16_32E(void *);
s32 test_flags_any(void *, int);
s32 obj_isState7_324(void *);
void TItemMag__vt42(TItemMag *arg0);
s32 is_flag_20000_set__10TObjPlayerFv(void *);
void send_6x3A_clear_photon_blast_ready_flag(u16 *arg0);
void TItemMag__vt43(u8 *arg0);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
extern s32 lbl_805D2C00;
extern const f32 lbl_805DABB8;
u8 *TItemEquipBase__ct(u8 *arg0, s32 arg1, s32 arg2);
void deserialize_mag__9TItemDataFPvPv(void *src, void *dst);
u8 *TItemMag__ct(Mag_801139F4 *self, s32 a, s32 src);
void release__14TItemEquipBaseFv(void *arg0);
void TItemMag__vt45(TItemMag_801138F0 *self);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, s32);
s32 push_matrix();
s32 pop_matrix();
void TItemMag__vt25(Self_801134CC *self);
s32 reset_key_machine_state__10TObjPlayerFv();
void TItemMag__vt14(Self_80113310 *self);
void TObjPlayer__sub_80364198();
void TObjPlayer__sub_8036414C();
void TItemMag__vt24(Self_801135E0 *self);
void *alloc__23TAdSinglePlyChrSelectGCFv(s32);
int fn_800F955C(void *p);
extern u8 lbl_8043E568[];
extern u8 lbl_8043E57C[];
extern int item_mag_type_id;
extern int item_mag_param_table;
int TItemMag__vt13(void* p);
void TItemMag__vt44(s32 arg0);
void *__dt__8TItemMagFv(void *arg0, s16 arg1);
void serialize_mag__9TItemDataFPvPv(void *, const void *);
s32 request_model_load__14TItemEquipBaseFl(s32, u8);
void *__dt__14TItemEquipBaseFv(void *arg0, s16 arg1);
s32 *__dt__9TItemLoadFPvs(s32 *arg0, s16 arg1);
int fn_800F953C(void*);

void TItemMag::update() {
    f32 temp_f1;

    temp_f1 = this->m_1c8;
    if (TItemMag__data_805DABA4 < temp_f1) {
        this->m_1c8 = (f32) (temp_f1 - TItemMag__data_805DABA8);
    }
    if (obj_testFlags30__13TUnk_804AF8A0FUl(this, 0x08000000) == 0) {
        set_subs_visible(1);
        return;
    }
    set_subs_visible(0);
}

void TItemMag__vt14(Self_80113310 *self) {
    s8 events;
    ((int (*)(void*))tick_fullness_timer__8TItemMagFPv)(self);
    ((TItemEquipBase *)self)->bind_loaded_resources();
    if (self->f18C & 0x20) {
        return;
    }
    events = ((TItemMag *)self)->collect_support_events();
    if (((TItemMag *)self)->get_status_flag() != 0) {
        if (reset_key_machine_state__10TObjPlayerFv() != 0) {
            ((TItemMag *)self)->feed_by_item_flags(events);
            ((void (*)(void *))TItemMag__sub_8011271C)(self);
        } else {
            return;
        }
    }
    switch (self->f18C & 0xF) {
    case 1:
        ((TItemMag *)self)->update();
        break;
    case 4:
        ((TItemMag *)self)->apply_auto_support_techniques();
        break;
    case 6:
        ((TItemMag *)self)->check_level_evolve();
        break;
    case 7:
        ((TItemMag *)self)->check_level_cap();
        break;
    case 5:
        ((TItemMag *)self)->update_feed();
        break;
    case 2:
        ((TItemMag *)self)->feed_if_over_45();
        break;
    case 3:
        ((TItemMag *)self)->feed_if_over_90();
        break;
    case 8:
        ((TItemMag *)self)->update_feed_timer();
        break;
    }
    self->f1CC++;
}

int TItemMag__vt13(void* p) { return ((int (*)(void*))tick_fullness_timer__8TItemMagFPv)(p); }

void TItemMag__vt12(s32 arg0) {
    if ((get_mag_total_level((void *)(arg0 + 0x198)) > 0xC8) || (((s16)((TItemData *)(arg0 + 0x198))->get_stat_percent()) < 0) || (((s16)((TItemData *)(arg0 + 0x198))->get_percent()) < 0) || (((s16)((TItemData *)(arg0 + 0x198))->get_level()) < 0) || (((s16)((TItemData *)(arg0 + 0x198))->get_mag_mind_level()) < 0)) {
        ((TItem *)arg0)->refresh_if_current_player();
    }
}

void TItemMag__vt25(Self_801134CC *self) {
    s32 scaled;
    VObj_18_801134CC *child;
    s32 i;
    f32 scale;
    if (self->owner != NULL && obj_testFlags30__13TUnk_804AF8A0FUl(self, 0x08000000) == 0 && ((TItem *)self)->is_hidden() == 0) {
    scaled = ((TItemMag *)(self->owner->stats))->check_state_flag_1();
    scale = ((TItemMag *)(self->owner->stats))->get_stat_f32();
    push_matrix();
    for (i = 0; i != 2; i++) {
        if (self->subs[i] != NULL && ((TItemMagSub *)(self->subs[i]))->is_growth_inactive() != 0) {
            child = self->subs[i];
            if (scaled != 0) {
                ((TItemMagSub *)child)->scale_owner_height(scale);
                child->m3();
                ((TItemMagSub *)child)->scale_owner_height(TItemMag__data_805DABA8 / scale);
            } else {
                child->m3();
            }
        }
    }
    pop_matrix();
    }
}

void TItemMag__vt24(Self_801135E0 *self) {
    s32 scaled;
    VObj_18_801135E0 *child;
    s32 i;
    f32 scale;
    if (self->owner != NULL && obj_testFlags30__13TUnk_804AF8A0FUl(self, 0x08000000) == 0 && ((TItem *)self)->is_hidden() == 0) {
    scaled = ((TItemMag *)(self->owner->stats))->check_state_flag_1();
    scale = ((TItemMag *)(self->owner->stats))->get_stat_f32();
    push_matrix();
    TObjPlayer__sub_80364198();
    TObjPlayer::set_model_fade_alpha(((TItem *)self)->get_owner_alpha());
    for (i = 0; i != 2; i++) {
        if (self->subs[i] != NULL && ((TItemMagSub *)(self->subs[i]))->is_growth_inactive() != 0) {
            child = self->subs[i];
            if (scaled != 0) {
                ((TItemMagSub *)child)->scale_owner_height(scale);
                child->m2();
                ((TItemMagSub *)child)->scale_owner_height(TItemMag__data_805DABA8 / scale);
            } else {
                child->m2();
            }
        }
    }
    TObjPlayer::warn_if_gauge_low();
    TObjPlayer__sub_8036414C();
    pop_matrix();
    }
}

void TItemMag::serialize_to_item(void *item) {
    serialize_mag__9TItemDataFPvPv(item, &m_198);
}

void TItemMag__vt43(u8 *item_mag) {
  s32 temp_r3;
  s32 slot;
  u8 *temp_r6;
  u8 *new_var;
  if (((volatile int)((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(*((u8 **) (((s8 *) item_mag) + 0xF0)))) == 0)
  {
    assign_default_photon_blast_palette_slots(((*((u8 **) (((s8 *) item_mag) + 0xF0))) + 0x500));
    slot = 0;
    do
    {
      temp_r3 = ((TItemMag *)(item_mag + 0x198))->get_photon_blast_at_slot(slot);
      if (temp_r3 != (-1))
      {
        new_var = item_mag;
        temp_r6 = (u8 *) (*((u8 **) (((s8 *) new_var) + 0xF0)));
        ((s32 (*)(void *, int, int, int))TItemMag__sub_80113EDC)(temp_r6 + 0x4AC, (int) ((s16) temp_r3), -1, (int) temp_r6);
      }
      slot += 1;
    }
    while (slot != 3);
    if (is_flag_20000_set__10TObjPlayerFv((void *) (*((u8 **) (((s8 *) item_mag) + 0xF0)))) == 0)
    {
      ((TItemMag *)((*((u8 **) (((s8 *) item_mag) + 0xF0))) + 0x4AC))->init_feed_timer();
      send_6x3A_clear_photon_blast_ready_flag((u16 *)((*((u8 **) (((s8 *) item_mag) + 0xF0))) + 0x4AC));
    }
  }
  ((TItemMag *)item_mag)->apply_feed_delta();
}

void TItemMag__vt42(TItemMag *item_mag) {
    *(s32 *)((s8 *)item_mag + 0x18C) = 0;
    if (((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)((void *) (*(u8 **)((s8 *)item_mag + 0xF0))) == 0) {
        *(s32 *)((s8 *)item_mag + 0x18C) = 0x10;
        item_mag->register_photon_blasts();
    }
    item_mag->request_support_action(1);
    *(s16 *)((s8 *)item_mag + 0x1D4) = ((VObj_18 *)(*(u8 **)((s8 *)item_mag + 0xF0)))->m14();
    if ((s16) *(s16 *)((s8 *)item_mag + 0x1D6) == -1) {
        *(s16 *)((s8 *)item_mag + 0x1D6) = TOKeyMachine01::get_global_state();
    }
    *(s16 *)((s8 *)item_mag + 0x1DC) = ((s16 (*)(void *))obj_getS16_32C)((void *) (*(u8 **)((s8 *)item_mag + 0xF0)));
    *(s16 *)((s8 *)item_mag + 0x1DE) = obj_getS16_32E((void *) (*(u8 **)((s8 *)item_mag + 0xF0)));
    if (test_flags_any((u8 *)item_mag + 0x178, 1) != 0) {
        *(s32 *)((s8 *)item_mag + 0x18C) = (s32) (*(s32 *)((s8 *)item_mag + 0x18C) & 0xFFFFFFDF);
    } else {
        *(s32 *)((s8 *)item_mag + 0x18C) = (s32) (*(s32 *)((s8 *)item_mag + 0x18C) | 0x20);
    }
    if ((((TItem *)item_mag)->is_hidden() == 0) && (obj_isState7_324((void *) (*(u8 **)((s8 *)item_mag + 0xF0))) == 0)) {
        ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4000B20A, (void *) (*(u8 **)((s8 *)item_mag + 0xF0) + 0x38), 0, 0);
    }
}

void TItemMag__vt45(TItemMag_801138F0 *self) {
    s32 i;
    for (i = 0; i != 2; i++) {
        if (self->subs[i] != 0) {
            ((TItemMagSub *)(self->subs[i]))->release_model_and_destroy();
            self->subs[i] = 0;
        }
    }
    release__14TItemEquipBaseFv(self);
}

void TItemMag__vt44(s32 arg0) {
    u8 temp_r3;
    u8 var_r4;

    temp_r3 = ((u8 (*)())get_item_group__5TItemFv)();
    var_r4 = temp_r3;
    if (temp_r3 >= 0x42U) {
        var_r4 = 0x42;
    }
    request_model_load__14TItemEquipBaseFl(arg0, var_r4);
}

void *__dt__8TItemMagFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__8TItemMag;
        __dt__14TItemEquipBaseFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma opt_common_subs off
u8 *TItemMag__ct(Mag_801139F4 *self, s32 a, s32 src) {
    s32 i;
    TItemEquipBase__ct((u8 *)self, a, src);
    *(s32 **)((u8 *)self + 0x18) = ((s32 *)__vt__8TItemMag);
    ((TItemData *)(self->data198))->initialize_mag_data();
    self->x0 = lbl_805D2C00;
    self->x1c8 = TItemMag__data_805DABA4;
    self->x190 = lbl_805DABB0;
    self->x194 = lbl_805DABB8;
    deserialize_mag__9TItemDataFPvPv((void *)src, self->data198);
    self->flags1a4 &= ~0x40;
    ((TItem *)self)->set_item_index((u8)(get_mag_total_level(self->data198)));
    self->m17(1);
    self->x18c = 0;
    for (i = 0; i < 2; i++) {
        self->x1a8[i] = 0;
        self->x1b0[i] = 0;
    }
    ((TItemMag *)self)->copy_owner_data();
    return (u8 *)self;
}
#pragma pop

u8 *TItemMag::create(s32 src) {
    u8 *temp_r3;
    u8 *var_r0;
    if (src != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1E0));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TItemMag__ct((Mag_801139F4 *)(temp_r3), tl_05, src));
        }
        return var_r0;
    }
    return NULL;
}

void TItemMag::cleanup() { __dt__9TItemLoadFPvs((s32 *)TItemMag__item_load_instance, (s16)((void*)1)); fn_800F953C((void*)item_mag_param_table); TItemMag__item_load_instance = 0; item_mag_type_id = 0; item_mag_param_table = 0; }

void TItemMag::load_data_files() {
    s32 i;
    s32 j;
    Rec_80113B6C *rec;
    Grp_80113B6C *g;
    s32 *type;
    void *buf;
    item_mag_param_table = fn_800F955C(lbl_8043E568);
    rec = (Rec_80113B6C *)item_mag_param_table;
    for (i = 0; i < 0x5A; i++, rec++) {
        bswap_32(&rec->f0);
        bswap_32(&rec->f8);
        bswap_32(&rec->f10);
        bswap_32(&rec->f14);
        bswap_32(&rec->f18);
        bswap_32(&rec->f1C);
        bswap_32(&rec->f20);
        bswap_32(&rec->f24);
        bswap_32(&rec->f28);
        bswap_32(&rec->f2C);
        bswap_32(&rec->f30);
        g = rec->g;
        for (j = 0; j < 3; j++, g++) {
            bswap_32(&g->a);
            bswap_32(&g->b);
            bswap_32(&g->c);
            bswap_32(&g->d);
        }
    }
    type = NULL;
    buf = alloc__23TAdSinglePlyChrSelectGCFv(8);
    if (buf != NULL) {
        buf = ((TItemLoad *)buf)->load_buffer((u32)lbl_8043E57C, 0x1000);
    }
    TItemMag__item_load_instance = (int)buf;
    if (buf != NULL) {
        type = ((s32 * (*)(void *))get_type__8TItemMagFv)(buf);
    }
    if (type != NULL) {
        item_mag_type_id = *type;
    }
}

}
void TItemMagSub::set_flags(u32 value) { flags |= value; }

void TItemMagSub::set_node_id(s32 index, s32 id) { node_ids[index] = id; }
void TItemMagSub::set_material_node(s32 node, void* parameters) { node_ids[0] = node; if (parameters != 0) copy_argb((NJS_ARGB *)material_parameters, (NJS_ARGB *)parameters); }

void TItemMagSub::set_model(void* model_arg, u32 textures_arg, void* animation_arg) {
    void* arg0=this; s32 arg1=(s32)model_arg; s32 arg2=(s32)textures_arg; void* arg3=animation_arg;
    *(s32 *)((s8 *)arg0 + 0x24) = arg1;
    *(s32 *)((s8 *)arg0 + 0x2C) = arg2;
    *(void **)((s8 *)arg0 + 0x28) = arg3;
    if ((void *) *(void **)((s8 *)arg0 + 0x28) != NULL) {
        *(f32 *)((s8 *)arg0 + 0x80) = (f32) TItemMag__data_805DABA4;
        *(f32 *)((s8 *)arg0 + 0x84) = (f32) ((f32) *(u32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x28)) + 4) - TItemMag__data_805DABA8);
    }
}
void TItemMagSub::scale_owner_height(f32 factor) { owner_height_scale *= factor; }
int TItemMagSub::is_growth_inactive() {
    void* p=this; return (((TItemMagSub *)p)->test_flags(64)) == 0; }

#pragma pop
