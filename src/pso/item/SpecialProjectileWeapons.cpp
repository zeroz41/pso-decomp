#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TUnk_804A2018.h"
#include "pso/TItemShoot.h"
#include "pso/TObject.h"

#include "pso/item/TUnk_804A204C.h"
#include "pso/item/TUnk_804A2148.h"
#include "pso/item/TUnk_804A2164.h"
#include "pso/items/TItemWeapon.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
struct TItemEquipBase;
#include "pso/item/TItemShootParticle.h"

#include "pso/TItemAttacker.h"
#include "pso/TParticleCtrl.h"
#include "pso/item/TItemMag.h"
#include "pso/object/TObjCamera.h"

struct RecoilWeaponView : TItemWeapon {
    s32 projectileVisible;
    s32 projectileSpin;
    s32 recoilAngle;
    s32 recoilPhase;
};

typedef struct MegidWeaponRenderView { u8 pad[0x200]; s32 f200; } MegidWeaponRenderView;

struct StarLightPosition { f32 x, y, z; };

struct StarLightParameters { u32 w[5]; };

struct StarLightFollowerView {
    u8 pad0[0x18];
    void *vtbl;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 f28;
};

typedef char RecoilVisibleOffset[offsetof(RecoilWeaponView, projectileVisible) == 0x1F8 ? 1 : -1];
typedef char RecoilSpinOffset[offsetof(RecoilWeaponView, projectileSpin) == 0x1FC ? 1 : -1];
typedef char RecoilAngleOffset[offsetof(RecoilWeaponView, recoilAngle) == 0x200 ? 1 : -1];
typedef char RecoilPhaseOffset[offsetof(RecoilWeaponView, recoilPhase) == 0x204 ? 1 : -1];
typedef char RecoilWeaponExtent[sizeof(RecoilWeaponView) == 0x208 ? 1 : -1];
typedef char StarLightParametersExtent[sizeof(StarLightParameters) == 0x14 ? 1 : -1];
typedef char StarLightFollowerExtent[sizeof(StarLightFollowerView) == 0x2C ? 1 : -1];

extern "C" {
s32 launch_rare_weapon_special__10TObjPlayerFPvlf(void *, void *, int, f32);

void emit_marker_effects__13TUnk_804A2164Fv(RecoilWeaponView *arg0);
s32 rotate_matrix_z(s32, s32);
void draw_ginja_object(void *child);
void update_weapon__13TUnk_804A2164Fv(void *arg0);
void *__dt__11TItemWeaponFv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A2164Fv(void *arg0, s16 arg1);
void TItemWeapon__ct(void *);
u8 *__nw__5TItemFUl(s32);
void __dl__7TObjectFPv(void *);
void *__dt__15TItemShootModelFv(void *self, s16 flag);
void *dt_item_shoot_model__13TUnk_804A2148Fs(void *arg0, s16 arg1);
void increment_burst_counter(u8 *arg0);
s32 get_burst_counter(void* p);
s32 get_owner_client__5TItemFv(void *);
s32 __nw__15TItemHeapObjectFUl(s32);
s32 init_vtable__13TUnk_804A0668Fv(s32, u32, s32, s32);
void init_armor__10TObjPlayerFPv(void *arg0);
s32 post_translate_matrix(void *);
s32 draw_weapon_at_joint(void *, s32, void *);
s32 warn_if_gauge_low__10TObjPlayerFv(s32);
s32 set_model_fade_alpha__10TObjPlayerFf();
void TObjPlayer__sub_80364198(void);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
extern s32 model_render_flags;
void reserved_53__13TUnk_804A204CFv(void *arg0);
void TObjPlayer__sub_8012443C(MegidWeaponRenderView *arg0);
s32 get_current_floor();
s32 is_item_area_enabled();
void update_weapon__13TUnk_804A204CFv(void *arg0);
s32 create_ex__9TTecMegidFllll(void *, s32 *, s32, s32);
void emit_marker_effects__13TUnk_804A204CFv(void *arg0);
s32 __nw__7TObjectFUl(s32);
void create_icon__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2);
}
void drill_launcher_node_callback(void *arg0);
s32 drill_launcher_create_shot(s32 arg0, s32 arg1, s32 arg2, f32 farg0);

void* drill_launcher_ct(void* a0, s32, void *);
extern s32 tl_05;
u8 *create_drill_launcher(u8 *arg0);
void drill_launcher_return_timer(void *arg0);
int get_item_system_generation(void);
u8 *spawn_star_light_2d(s32 arg0, s32 arg1, s32 arg2);
extern "C" {
const StarLightParameters weapon_star_light_parameters[] = {
    { { 0x40400000, 0x40E00000, 0xB4FF0019, 0, 0x41A00000 } }
};
StarLightFollowerView *__ct__13TUnk_804A2018FP7TObjectll(StarLightFollowerView *self, void *parent, s32 a, s32 b);
void __dt__7TObjectFv(void *, int);
void *TObjPlayer__sub_8012417C(void *arg0, s16 arg1);
s8 get_mode__5TItemFv();
s32 copy_position__15TEffStarLight2DFPv(u32, s32 *);
void queue_destruction__7TObjectFv(void *arg0);
void run_task__13TUnk_804A2018Fv(void *arg0);
void *__dt__13TUnk_804A204CFv(void *arg0, s16 arg1);
void *TObjPlayer__sub_80124694(TObjPlayer *arg0);
u8 *TObjPlayer__sub_80124708(u8 *arg0);
s32 is_owner_alive__15TItemShootModelFv();
s32 rotate_matrix_x(int, int);

void hook__13TUnk_804A2148Fv(void);
void __ct__15TItemShootModelFPvPC3VecPC3Vecf(void *);
u32 spawn_shoot_particle__10TObjPlayerFUlllf(s32, s32, s32, f32);
typedef u8 *(*Fn_80124694_3)(void *, s32, void *);
typedef s32 (*Fn_80124810_5)(s32, s32, s32, s32, f32);

extern "C" void render__7TObjectFv();
extern "C" void render_shadows__7TObjectFv();
void *__vt__13TUnk_804A2018[6] = {
    (void *)0x0, (void *)0x0, (void *)&TObjPlayer__sub_8012417C, (void *)&run_task__13TUnk_804A2018Fv,
    (void *)&render__7TObjectFv, (void *)&render_shadows__7TObjectFv,
};
#define __vt__13TUnk_804A2018 ((u8 *)__vt__13TUnk_804A2018)

void TUnk_804A2018::run_task() {
    s32 sp8;
    s32 item;
    if ((u32) this->m_28 != ((u32)get_item_system_generation())) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if ((u32) *(u32 *)&this->unk_24 != 0U) {
        item = ((s32)find_item_by_id(*(s32 *)&this->unk_1C));
        if ((item != 0) && (get_mode__5TItemFv() == 2) && (((TObjPlayer *)item)->draw_icon(this->m_20, (s32)&sp8) != 0)) {
            if (((TItem *)item)->is_hidden() == 0) {
                copy_position__15TEffStarLight2DFPv(*(u32 *)&this->unk_24, &sp8);
                return;
            }
            ((TObjCamera *)(*(u32 *)&this->unk_24))->queue_target_destruction();
            return;
        }
    }
    queue_destruction__7TObjectFv(this);
}

void *TObjPlayer__sub_8012417C(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = ((s32 *)__vt__13TUnk_804A2018);
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
TUnk_804A2018::TUnk_804A2018(TObject *parent, s32 a, s32 b) : TObject(parent) {
    StarLightPosition v;
    void *p;
    ((StarLightFollowerView *)this)->f1c = a;
    ((StarLightFollowerView *)this)->f20 = b;
    ((StarLightFollowerView *)this)->f24 = 0;
    ((StarLightFollowerView *)this)->f28 = get_item_system_generation();
    p = find_item_by_id(((StarLightFollowerView *)this)->f1c);
    if (p != NULL && ((TObjPlayer *)p)->draw_icon((s32)((StarLightFollowerView *)this)->f20, (s32)((s32 *)&v)) != 0) {
        StarLightParameters blk = weapon_star_light_parameters[0];
        ((StarLightFollowerView *)this)->f24 = (s32)spawn_star_light_2d((s32)&v, (s32)&blk, (s32)((StarLightFollowerView *)this));
    }
}
extern "C" {

void create_icon__10TObjPlayerFiii(s32 parent, s32 arg1, s32 arg2) {
    void *temp_r3;
    if (parent != 0) {
        temp_r3 = (void *)((u32)__nw__7TObjectFUl(0x2C));
        if (temp_r3 != (void *)0U) {
            __ct__13TUnk_804A2018FP7TObjectll((StarLightFollowerView *)(temp_r3), (void *)parent, (s32)arg1, (s32)arg2);
        }
    }
}

void TUnk_804A204C::emit_marker_effects() {
    s32 sp8;
    void *temp_r31;
    if (((TObjPlayer *)this)->is_mode_two_and_ready() != 0) {
        if (((TObjPlayer *)this)->draw_icon(5, (s32)&sp8) != 0) {
            temp_r31 = this->player;
            create_ex__9TTecMegidFllll(temp_r31, &sp8, *(s32 *)((s8 *)temp_r31 + 0x60), ((TObjPlayer *)this)->get_tp());
            this->roll_technique();
        }
    } else {
        ((TObjPlayer *)this)->update_active_game_effect();
    }
}

void TUnk_804A204C::update_weapon() {
    s32 temp_r3;
    if ((s32) this->m_1fc == 1) {
        *(s32 *)((s8 *)this + 0x200) = (s32) (*(s32 *)((s8 *)this + 0x200) + 0xAAA);
        if ((s32) *(s32 *)((s8 *)this + 0x200) >= 0x2000) {
            *(s32 *)((s8 *)this + 0x200) = 0x2000;
            this->m_1fc = 0;
        }
    } else {
        *(s32 *)((s8 *)this + 0x200) = (s32) (*(s32 *)((s8 *)this + 0x200) - 0xAAA);
        if ((s32) *(s32 *)((s8 *)this + 0x200) <= -0x2000) {
            *(s32 *)((s8 *)this + 0x200) = -0x2000;
            this->m_1fc = 1;
        }
    }
    temp_r3 = get_current_floor();
    if (((s32) this->m_204 != temp_r3) && ((u32) *(u32 *)((s8 *)this + 0xF4) != 0U)) {
        this->m_204 = temp_r3;
        if (is_item_area_enabled() != 0) {
            create_icon__10TObjPlayerFiii(tl_05, (s32)((s32)(((TItem *)this)->get_item_id())), 5);
        }
    }
}

void TObjPlayer__sub_8012443C(MegidWeaponRenderView *arg0) {
    switch (((u32)TObjPlayer::get_player_list())) {
    case 1:
        rotate_matrix_y(0, arg0->f200);
        return;
    case 2:
        TItem::begin_effect_render();
        return;
    case 3:
        rotate_matrix_y(0, (int)(-arg0->f200));
        return;
    case 4:
        TItem::begin_effect_render();
        return;
    case 6:
        TItem::begin_effect_render();
        break;
    case 0:
    case 5:
        break;
    }
}

void TUnk_804A204C::reserved_53() {
    s32 sp8;
    s32 temp_r3;
    void *temp_r31;
    void *temp_r5;
    if (((void *) *(void **)((s8 *)this + 0xF4) != NULL) && (((TItem *)this)->is_hidden() == 0)) {
        temp_r5 = *(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)this + 0xF4)) + 0x2C)) + 0x30);
        temp_r31 = *(void **)((s8 *)temp_r5 + 0x30);
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) | 0x18);
        draw_weapon_at_joint(this, 0x30, temp_r5);
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) & 0xFFFFFFE7);
        if (((TObjPlayer *)this)->draw_icon(5, (s32)&sp8) != 0) {
            push_matrix();
            TObjPlayer__sub_80364198();
            model_render_flags &= 0xFFFFFFEF;
            ((TItem *)this)->get_owner_alpha();
            set_model_fade_alpha__10TObjPlayerFf();
            post_translate_matrix(&sp8);
            rotate_matrix_y(0, (int)(*(s32 *)((s8 *)this->player + 0x60)));
            *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) | 0x11);
            draw_ginja_object(temp_r31);
            TParticleCtrl::begin_effect_render();
            draw_ginja_object(*(void **)((s8 *)temp_r31 + 0x2C));
            TParticleCtrl::end_effect_render();
            temp_r3 = *(s32 *)((s8 *)temp_r31 + 0);
            *(s32 *)((s8 *)temp_r31 + 0) = (s32) (temp_r3 & ~0x11);
            warn_if_gauge_low__10TObjPlayerFv(temp_r3);
            pop_matrix();
            pop_matrix();
        }
    }
}

void init_armor__10TObjPlayerFPv(void *arg0) {
    s32 temp_r3;
    ((TUnk_804A204C *)arg0)->m_204 = -1;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x174) != 0U) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3 != 0) {
            init_vtable__13TUnk_804A0668Fv(temp_r3, *(u32 *)((s8 *)arg0 + 0x174), get_owner_client__5TItemFv(arg0), 0x5A);
        }
    }
    ((TItemWeapon *)arg0)->roll_technique();
    ((TItemWeapon *)arg0)->roll_technique();
}

void render__13TUnk_804A2148Fv(u8 *);
extern "C" s8 get_attach_slot__14TItemEquipBaseFv(TItemEquipBase *arg0);
extern "C" void TItemWeapon__sub_8011E5C4();
extern "C" void TItemWeapon__sub_8011E5C8();
extern "C" void TItemWeapon__sub_8011E5CC();
extern "C" void reserved_53__11TItemWeaponFv();
extern "C" void update_idle__11TItemWeaponFv();
extern "C" void update_attack__11TItemWeaponFv();
extern "C" void vfunc_17__11TItemWeaponFl();
extern "C" void vfunc_14__11TItemWeaponFv();
extern "C" void vfunc_50__11TItemWeaponFv();
extern "C" void vfunc_45__11TItemWeaponFv();
extern "C" u8 TItemWeapon__sub_80121064(void *p);
extern "C" void TItemWeapon__write_item_data();
extern "C" void vfunc_42__5TItemFv();
extern "C" void update_in_inventory__5TItemFv();
extern "C" int feed__5TItemFP9TItemData(void);
extern "C" void add_slot__5TItemFv();
extern "C" int update_object_view_visibility__5TItemFff(void *p);
extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void add_equip_stats__14TItemEquipBaseFl();
extern "C" void vfunc_44__11TItemWeaponFv();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void vfunc_48__11TItemWeaponFv();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void deliver_hit__11TItemWeaponFlPUcllf();
extern "C" void vfunc_30__11TItemWeaponFv();
extern "C" void use__5TItemFv();
extern "C" void render__5TItemFv();
extern "C" void vfunc_27__11TItemWeaponFv();
extern "C" void vfunc_26__11TItemWeaponFv();
extern "C" void equip__14TItemEquipBaseFv();
extern "C" void get_attack_flags__11TItemWeaponFv();
extern "C" void get_motion_ptr__11TItemWeaponFv();
extern "C" void launch_shot__11TItemWeaponFPUclll();
extern "C" void vfunc_46__11TItemWeaponFv();
extern "C" void get_name__5TItemFv();
extern "C" void reset_motion_fields__13TUnk_804AF8A0Fv();
extern "C" void remove_equip_stats__14TItemEquipBaseFl();
extern "C" void render_shadows__5TItemFv();
extern "C" void vfunc_49__11TItemWeaponFv();
extern "C" void release__11TItemWeaponFv();
extern "C" int get_slot_count__5TItemFv(void);
extern "C" int add_amount__5TItemFl(void);
extern "C" int remove_amount__5TItemFl(void);
extern "C" int get_amount__5TItemFv(void);
extern "C" void run_task__10TItemShootFv();
extern "C" void run_task__5TItemFv();
extern "C" void set_attach_slot__14TItemEquipBaseFSc();
extern "C" void subtract_equip_stats__14TItemEquipBaseFlPUcPUc();
extern "C" void subtract_item_stat_bonus__14TItemEquipBaseFllPs();
extern "C" void vfunc_13__5TItemFl();
extern "C" void unequip__14TItemEquipBaseFv();
extern "C" void vfunc_16__11TItemWeaponFv();
extern "C" void update_equip__14TItemEquipBaseFv();
extern "C" void vfunc_34__11TItemWeaponFv();
extern "C" void vfunc_28__11TItemWeaponFv();
void *megid_projectile_weapon_vtable[63] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TUnk_804A204CFv, (void *)&run_task__5TItemFv,
    (void *)&render__5TItemFv, (void *)&render_shadows__5TItemFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804AF8A0Fv, (void *)&get_motion_ptr__11TItemWeaponFv, (void *)&update_object_view_visibility__5TItemFff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__5TItemFv, (void *)&vfunc_13__5TItemFl, (void *)&vfunc_14__11TItemWeaponFv, (void *)&update_in_inventory__5TItemFv,
    (void *)&vfunc_16__11TItemWeaponFv, (void *)&vfunc_17__11TItemWeaponFl, (void *)&TItemWeapon__write_item_data, (void *)&set_attach_slot__14TItemEquipBaseFSc,
    (void *)&equip__14TItemEquipBaseFv, (void *)&unequip__14TItemEquipBaseFv, (void *)&add_equip_stats__14TItemEquipBaseFl, (void *)&remove_equip_stats__14TItemEquipBaseFl,
    (void *)&subtract_item_stat_bonus__14TItemEquipBaseFllPs, (void *)&subtract_equip_stats__14TItemEquipBaseFlPUcPUc, (void *)&vfunc_26__11TItemWeaponFv, (void *)&vfunc_27__11TItemWeaponFv,
    (void *)&vfunc_28__11TItemWeaponFv, (void *)&update_equip__14TItemEquipBaseFv, (void *)&vfunc_30__11TItemWeaponFv, (void *)&use__5TItemFv,
    (void *)&get_attack_flags__11TItemWeaponFv, (void *)&get_attach_slot__14TItemEquipBaseFv, (void *)&vfunc_34__11TItemWeaponFv, (void *)&TItemWeapon::copy_item_to_data,
    (void *)&get_amount__5TItemFv, (void *)&remove_amount__5TItemFl, (void *)&add_amount__5TItemFl, (void *)&get_slot_count__5TItemFv,
    (void *)&add_slot__5TItemFv, (void *)&feed__5TItemFP9TItemData, (void *)&vfunc_42__5TItemFv, (void *)&TItemWeapon__sub_80121064,
    (void *)&vfunc_44__11TItemWeaponFv, (void *)&vfunc_45__11TItemWeaponFv, (void *)&vfunc_46__11TItemWeaponFv, (void *)&release__11TItemWeaponFv,
    (void *)&vfunc_48__11TItemWeaponFv, (void *)&vfunc_49__11TItemWeaponFv, (void *)&vfunc_50__11TItemWeaponFv, (void *)&launch_shot__11TItemWeaponFPUclll,
    (void *)&emit_marker_effects__13TUnk_804A204CFv, (void *)&update_attack__11TItemWeaponFv, (void *)&update_idle__11TItemWeaponFv, (void *)&reserved_53__13TUnk_804A204CFv,
    (void *)&update_weapon__13TUnk_804A204CFv, (void *)&init_armor__10TObjPlayerFPv, (void *)&TItemWeapon__sub_8011E5C8, (void *)&TItemWeapon__sub_8011E5C4,
    (void *)&TObjPlayer__sub_8012443C, (void *)&deliver_hit__11TItemWeaponFlPUcllf, (void *)0x0,
};
void *recoil_weapon_shoot_model_vtable[7] = {
    (void *)0x0, (void *)0x0, (void *)&dt_item_shoot_model__13TUnk_804A2148Fs, (void *)&run_task__10TItemShootFv,
    (void *)&render__13TUnk_804A2148Fv, (void *)&render_shadows__7TObjectFv, (void *)&hook__13TUnk_804A2148Fv,
};
void *recoiling_projectile_weapon_vtable[63] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TUnk_804A2164Fv, (void *)&run_task__5TItemFv,
    (void *)&render__5TItemFv, (void *)&render_shadows__5TItemFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804AF8A0Fv, (void *)&get_motion_ptr__11TItemWeaponFv, (void *)&update_object_view_visibility__5TItemFff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__5TItemFv, (void *)&vfunc_13__5TItemFl, (void *)&vfunc_14__11TItemWeaponFv, (void *)&update_in_inventory__5TItemFv,
    (void *)&vfunc_16__11TItemWeaponFv, (void *)&vfunc_17__11TItemWeaponFl, (void *)&TItemWeapon__write_item_data, (void *)&set_attach_slot__14TItemEquipBaseFSc,
    (void *)&equip__14TItemEquipBaseFv, (void *)&unequip__14TItemEquipBaseFv, (void *)&add_equip_stats__14TItemEquipBaseFl, (void *)&remove_equip_stats__14TItemEquipBaseFl,
    (void *)&subtract_item_stat_bonus__14TItemEquipBaseFllPs, (void *)&subtract_equip_stats__14TItemEquipBaseFlPUcPUc, (void *)&vfunc_26__11TItemWeaponFv, (void *)&vfunc_27__11TItemWeaponFv,
    (void *)&vfunc_28__11TItemWeaponFv, (void *)&update_equip__14TItemEquipBaseFv, (void *)&vfunc_30__11TItemWeaponFv, (void *)&use__5TItemFv,
    (void *)&get_attack_flags__11TItemWeaponFv, (void *)&get_attach_slot__14TItemEquipBaseFv, (void *)&vfunc_34__11TItemWeaponFv, (void *)&TItemWeapon::copy_item_to_data,
    (void *)&get_amount__5TItemFv, (void *)&remove_amount__5TItemFl, (void *)&add_amount__5TItemFl, (void *)&get_slot_count__5TItemFv,
    (void *)&add_slot__5TItemFv, (void *)&feed__5TItemFP9TItemData, (void *)&vfunc_42__5TItemFv, (void *)&TItemWeapon__sub_80121064,
    (void *)&vfunc_44__11TItemWeaponFv, (void *)&vfunc_45__11TItemWeaponFv, (void *)&vfunc_46__11TItemWeaponFv, (void *)&release__11TItemWeaponFv,
    (void *)&vfunc_48__11TItemWeaponFv, (void *)&vfunc_49__11TItemWeaponFv, (void *)&vfunc_50__11TItemWeaponFv, (void *)&launch_shot__11TItemWeaponFPUclll,
    (void *)&emit_marker_effects__13TUnk_804A2164Fv, (void *)&update_attack__11TItemWeaponFv, (void *)&update_idle__11TItemWeaponFv, (void *)&reserved_53__11TItemWeaponFv,
    (void *)&update_weapon__13TUnk_804A2164Fv, (void *)&TItemWeapon__sub_8011E5CC, (void *)&TItemWeapon__sub_8011E5C8, (void *)&TItemWeapon__sub_8011E5C4,
    (void *)&drill_launcher_node_callback, (void *)&deliver_hit__11TItemWeaponFlPUcllf, (void *)0x0,
};
#define megid_projectile_weapon_vtable ((s32 *)megid_projectile_weapon_vtable)
#define recoil_weapon_shoot_model_vtable ((s32 *)recoil_weapon_shoot_model_vtable)
#define recoiling_projectile_weapon_vtable ((s32 *)recoiling_projectile_weapon_vtable)

void *__dt__13TUnk_804A204CFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = megid_projectile_weapon_vtable;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void *TObjPlayer__sub_80124694(TObjPlayer *player) {
    TItemWeapon__ct(player);
    *(s32 **)((s8 *)player + 0x18) = megid_projectile_weapon_vtable;
    ((FlagWord *)((char *)player + 376))->set(32);
    player->set_status_flags(35);
    player->set_effect_state(12);
    *(u32 *)((s8 *)player + 0x1F8) = 0;
    *(u32 *)((s8 *)player + 0x200) = 0;
    ((TUnk_804A204C *)player)->m_204 = -1;
    return player;
}

u8 *TObjPlayer__sub_80124708(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x208));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((Fn_80124694_3)TObjPlayer__sub_80124694)(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

void TUnk_804A2148::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;
    u8 *temp_r3;

    if (is_owner_alive__15TItemShootModelFv() != 0) {
        temp_r3 = (unsigned char *) (this->m_58);
        if ((temp_r3 != NULL) && ((u32) this->m_5C != 0U)) {
            temp_r31 = (unsigned char *) (*(void **)((s8 *)((unsigned char *) (*(void **)((s8 *)temp_r3 + 0x2C))) + 0x30));
            *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) & 0xFFFFFFFB);
            *(f32 *)((s8 *)temp_r31 + 0x20) = (f32) 10.0f;
            push_matrix();
            TObjPlayer::notify_fish_if_valid((int)this->m_5C);
            post_translate_matrix(arg0 + 0x1C);
            rotate_matrix_y(0, this->m_count);
            rotate_matrix_x(0, this->m_28 - 0x4000);
            draw_ginja_object((this->m_58));
            pop_matrix();
            *(f32 *)((s8 *)temp_r31 + 0x20) = (f32) 1.0f;
        }
    }
}

void TUnk_804A2148::hook() {  }

void *ct_shoot_model__10TObjPlayerFPv(void *item_shoot_model) {
    __ct__15TItemShootModelFPvPC3VecPC3Vecf(item_shoot_model);
    *(s32 **)((s8 *)item_shoot_model + 0x18) = recoil_weapon_shoot_model_vtable;
    return item_shoot_model;
}
}

s32 drill_launcher_create_shot(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    s32 var_r0;
    s32 var_r31;

    var_r31 = 0;
    if (arg0 != 0) {
        var_r0 = __nw__7TObjectFUl(0x6C);
        if (var_r0 != 0) {
            var_r0 = ((Fn_80124810_5)ct_shoot_model__10TObjPlayerFPv)(var_r0, arg0, arg1, arg2, farg0);
        }
        var_r31 = var_r0;
    }
    var_r0 = spawn_shoot_particle__10TObjPlayerFUlllf(arg0, arg1, arg2, farg0);
    if (var_r0 != 0U) {
        ((TItemShootParticle *)var_r0)->spawn_slot_emitter(0x1BB, 0);
    }
    return var_r31;
}
typedef char BurstReadyOffset[offsetof(RecoilWeaponView, projectileVisible)==0x1F8 ? 1 : -1];
typedef char BurstModeOffset[offsetof(RecoilWeaponView, recoilPhase)==0x204 ? 1 : -1];

void TUnk_804A2164::emit_marker_effects() {
    WeaponVector sp8;
    s32 temp_r31;
    s32 var_r30;
    if ((s32) ((RecoilWeaponView *)this)->projectileVisible == 1) {
        TItemAttacker::spawn_item_timer((s32)((RecoilWeaponView *)this), (s32)drill_launcher_return_timer, 0x1E);
        ((RecoilWeaponView *)this)->projectileVisible = 0;
    }
    ((RecoilWeaponView *)this)->recoilPhase = 2;
    temp_r31 = (s32)((RecoilWeaponView *)this)->player + 0x7CC;
    if (get_burst_counter((void*)temp_r31) == 0) {
        var_r30 = 0;
        do {
            increment_burst_counter((u8 *)temp_r31);
            var_r30 += 1;
        } while (var_r30 != 2);
    }
    ((TObjPlayer *)((RecoilWeaponView *)this))->draw_status_icon((s32)&sp8);
    if (((TObjPlayer *)((RecoilWeaponView *)this))->is_mode_two_and_ready() != 0) {
        launch_rare_weapon_special__10TObjPlayerFPvlf((void *) (((RecoilWeaponView *)this)), &sp8, 1, (f32) (1.0f));
        return;
    }
    ((RecoilWeaponView *)this)->deliver_projectile(&sp8, 0, 0, 1);
}
void drill_launcher_node_callback(void *arg0) {
    s32 player_list;
    player_list = TObjPlayer::get_player_list();
    if ((player_list > 0) && (player_list < 4)) {
        rotate_matrix_z(0, *(s32 *)((s8 *)arg0 + 0x200));
        return;
    }
    if (player_list == 4) {
        if (((TUnk_804A2164 *)arg0)->projectile != 0U) {
            if ((s32) *(s32 *)((s8 *)arg0 + 0x1F8) == 1) {
                draw_ginja_object((void *)(((TUnk_804A2164 *)arg0)->projectile));
            }
        }
    }
}

void TUnk_804A2164::update_weapon() {
    void *temp_r4;
    void *temp_r4_2;
    this->m_1fc = (this->m_1fc + 0x1999);
    temp_r4 = *(void * *)&this->projectile;
    if (temp_r4 != NULL) {
        temp_r4_2 = *(void **)((s8 *)temp_r4 + 0x2C);
        *(s32 *)((s8 *)temp_r4_2 + 0) = (s32) (*(s32 *)((s8 *)temp_r4_2 + 0) & 0xFFFFFFFD);
        *(s32 *)((s8 *)temp_r4_2 + 0x18) = (s32) this->m_1fc;
    }
    switch (this->m_204) {
    case 1:
        *(s32 *)((s8 *)this + 0x200) = (s32) (*(s32 *)((s8 *)this + 0x200) + 0xE38);
        if ((s32) *(s32 *)((s8 *)this + 0x200) >= 0) {
            *(s32 *)((s8 *)this + 0x200) = 0;
            this->m_204 = 0;
        }
        return;
    case 2:
        *(s32 *)((s8 *)this + 0x200) = (s32) (*(s32 *)((s8 *)this + 0x200) - 0xE38);
        if ((s32) *(s32 *)((s8 *)this + 0x200) <= -0x31C7) {
            *(s32 *)((s8 *)this + 0x200) = -0x31C7;
            this->m_204 = 3;
            return;
        }
        break;
    case 3:
        this->m_204 = 1;
        return;
    }
}
void *__dt__13TUnk_804A2164Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = recoiling_projectile_weapon_vtable;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
void* drill_launcher_ct(void* a0, s32 _w1, void * _w2) { TItemWeapon__ct(a0); *(int*)((char*)a0 + 0x18) = (int)((unsigned char *)recoiling_projectile_weapon_vtable); *(int*)((char*)a0 + 0x1f0) = (int)drill_launcher_create_shot; *(float*)((char*)a0 + 0x1e4) = 9.0f; ((TObjPlayer *)a0)->set_status_flags((int)((void*)34)); *(int*)((char*)a0 + 0x1f8) = 1; ((TUnk_804A2164 *)a0)->m_1fc = 0; *(int*)((char*)a0 + 0x200) = 0; return a0; }
u8 *create_drill_launcher(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x208));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)drill_launcher_ct(temp_r3, tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}

void *TUnk_804A2148::dt_item_shoot_model(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = recoil_weapon_shoot_model_vtable;
        __dt__15TItemShootModelFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
void drill_launcher_return_timer(void *arg0) {
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0x1F8) = 1;
    }
}

void increment_burst_counter(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) + 1);
}
s32 get_burst_counter(void* p) { return *(s32*)((char*)p + 0x18); }
