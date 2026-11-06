#include "pso/effect/TEffStarLight2D.h"
#include "pso/item/TUnk_804A204C.h"
#include "pso/item/TUnk_804A2148.h"
#include "pso/item/TUnk_804A2164.h"
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
#include "pso/player/TObjPlayer_8023E480.h"
struct TItemEquipBase;
#include "pso/item/TItemShootParticle.h"

#include "pso/item/TItemAttacker.h"
#include "pso/effect/TParticleCtrl.h"
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

struct WeaponStarLightParameterWords { u32 w[5]; };

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
typedef char WeaponStarLightParameterWordsExtent[sizeof(WeaponStarLightParameterWords) == 0x14 ? 1 : -1];
typedef char StarLightFollowerExtent[sizeof(StarLightFollowerView) == 0x2C ? 1 : -1];

extern "C" {

s32 rotate_matrix_z(s32, s32);
void draw_ginja_object(void *child);
void *__dt__13TUnk_804A2164Fv(void *arg0, s16 arg1);
void __ct__11TItemWeaponFP7TObjectPUc(void *);
u8 *__nw__5TItemFUl(s32);
void __dl__7TObjectFPv(void *);
void *__dt__15TItemShootModelFv(void *self, s16 flag);
void increment_burst_counter(u8 *arg0);
s32 get_burst_counter(void* p);
s32 get_owner_client__5TItemFv(void *);
s32 __nw__15TItemHeapObjectFUl(s32);
s32 init_vtable__13TUnk_804A0668Fv(s32, u32, s32, s32);
s32 post_translate_matrix(void *);
s32 draw_weapon_at_joint(void *, s32, void *);
s32 warn_if_gauge_low__10TObjPlayerFv(s32);
s32 set_model_fade_alpha__10TObjPlayerFf();
void TObjPlayer__sub_80364198(void);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
extern s32 model_render_flags;
s32 get_current_floor();
s32 is_item_area_enabled();
s32 create_ex__9TTecMegidFllll(void *, s32 *, s32, s32);
s32 __nw__7TObjectFUl(s32);
void create_icon__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2);
}
s32 drill_launcher_create_shot(s32 arg0, s32 arg1, s32 arg2, f32 farg0);

void* drill_launcher_ct(void* a0, s32, void *);
extern s32 tl_05;
u8 *create_drill_launcher(u8 *arg0);
void drill_launcher_return_timer(void *arg0);
int get_item_system_generation(void);
u8 *spawn_star_light_2d(s32 arg0, s32 arg1, s32 arg2);
extern "C" {
const WeaponStarLightParameterWords weapon_star_light_parameters[] = {
    { { 0x40400000, 0x40E00000, 0xB4FF0019, 0, 0x41A00000 } }
};
StarLightFollowerView *__ct__13TUnk_804A2018FP7TObjectll(StarLightFollowerView *self, void *parent, s32 a, s32 b);
void __dt__7TObjectFv(void *, int);
void *TObjPlayer__sub_8012417C(void *arg0, s16 arg1);
s8 get_mode__5TItemFv();

void queue_destruction__7TObjectFv(void *arg0);
void run_task__13TUnk_804A2018Fv(void *arg0);
void *__dt__13TUnk_804A204CFv(void *arg0, s16 arg1);
void *TObjPlayer__sub_80124694(TObjPlayer *arg0);
u8 *TObjPlayer__sub_80124708(u8 *arg0);
s32 rotate_matrix_x(int, int);

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
        if ((item != 0) && (get_mode__5TItemFv() == 2) && (((TItemWeapon *)item)->get_joint_position(this->m_20, &sp8) != 0)) {
            if (((TItem *)item)->is_hidden() == 0) {
                ((TEffStarLight2D *)*(u32 *)&this->unk_24)->copy_position((const Vec *)&sp8);
                return;
            }
            ((TEffStarLight2D *)*(u32 *)&this->unk_24)->queue_child_destruction();
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
    if (p != NULL && ((TItemWeapon *)p)->get_joint_position(((StarLightFollowerView *)this)->f20, &v) != 0) {
        WeaponStarLightParameterWords blk = weapon_star_light_parameters[0];
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
    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(5, &sp8) != 0) {
            temp_r31 = this->owner;
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

void TUnk_804A204C::vfunc_60() {
    switch (((u32)TObjPlayer::get_player_list())) {
    case 1:
        rotate_matrix_y(0, ((MegidWeaponRenderView *)this)->f200);
        return;
    case 2:
        TItem::begin_effect_render();
        return;
    case 3:
        rotate_matrix_y(0, (int)(-((MegidWeaponRenderView *)this)->f200));
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
        if (get_joint_position(5, &sp8) != 0) {
            push_matrix();
            TObjPlayer__sub_80364198();
            model_render_flags &= 0xFFFFFFEF;
            ((TItem *)this)->get_owner_alpha();
            set_model_fade_alpha__10TObjPlayerFf();
            post_translate_matrix(&sp8);
            rotate_matrix_y(0, (int)(*(s32 *)((s8 *)this->owner + 0x60)));
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

void TUnk_804A204C::vfunc_57() {
    s32 temp_r3;
    m_204 = -1;
    if ((u32) *(u32 *)((s8 *)this + 0x174) != 0U) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3 != 0) {
            init_vtable__13TUnk_804A0668Fv(temp_r3, *(u32 *)((s8 *)this + 0x174), get_owner_client__5TItemFv(this), 0x5A);
        }
    }
    roll_technique();
    roll_technique();
}

extern void *__vt__13TUnk_804A204C[];
extern void *__vt__13TUnk_804A2148[];
extern void *__vt__13TUnk_804A2164[];
#define __vt__13TUnk_804A204C ((s32 *)__vt__13TUnk_804A204C)
#define __vt__13TUnk_804A2148 ((s32 *)__vt__13TUnk_804A2148)
#define __vt__13TUnk_804A2164 ((s32 *)__vt__13TUnk_804A2164)

}
TUnk_804A204C::~TUnk_804A204C() {

}
extern "C" {

void *TObjPlayer__sub_80124694(TObjPlayer *player) {
    __ct__11TItemWeaponFP7TObjectPUc(player);
    *(s32 **)((s8 *)player + 0x18) = __vt__13TUnk_804A204C;
    ((FlagWord *)((char *)player + 376))->set(32);
    ((TItemWeapon *)player)->set_weapon_flags(35);
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
}
