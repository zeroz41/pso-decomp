#include "types.h"
#include "pso/enemy/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_801211F0.h"
#include "pso/player/TObjPlayer_80363BE0.h"
#include "pso/unk/text_80120150.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/object/TObjMotion.h"
#include "pso/items/TItemWeapon.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItemMag.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {
s32 get_attach_joint__14TItemEquipBaseFv(void *);
void draw_weapon_at_joint(s32 arg0, s8 arg1);
}
void set_shadow_material_state(void);
extern "C" {
s32 set_model_fade_alpha__10TObjPlayerFf();
s32 push_matrix_from();
s32 pop_matrix();
void draw_chunk_object(void *child);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern s16 TObjPlayer__weapon_node_ids[];
extern s16 weapon_node_material_index;
extern u8 *weapon_render_callback_object;
extern s32 model_render_flags;
extern const f32 lbl_805DACA8;
extern const f32 lbl_805DACAC;

s32 TItemWeapon::draw_weapon_model() {
    s32 var_r30;
    u8 *temp_r4;
    if ((void *) this->owner == NULL || (u32) *(u32 *)((s8 *)this + 0xF4) == 0U) {
        return;
    }
    {
        reset_model_node_counter();
        if (((TItem *)this)->has_no_defer_render() != 0) {
            var_r30 = 1;
        } else {
            var_r30 = ((VObj_18_26a62c *)(this))->m8(lbl_805DACA8, lbl_805DACAC);
        }
        set_texlist((int) (*(s32 *)((s8 *)this + 0x24)));
        ((TObjMotion *)(this->owner))->get_item_ptr((s32)((void *) ((s8)get_attach_joint__14TItemEquipBaseFv(this))));
        push_matrix_from();
        if ((var_r30 != 0) && (((TItem *)this)->is_hidden() == 0)) {
            weapon_render_callback_object = (u8 *)this;
            weapon_node_material_index = *(s16 *)((s8 *)this + 0x1CC);
            temp_r4 = (u8 *)this->parameters;
            TObjPlayer__weapon_node_ids[0] = (s16) *(u8 *)((s8 *)temp_r4 + 0x21);
            TObjPlayer__weapon_node_ids[1] = (s16) *(u8 *)((s8 *)temp_r4 + 0x22);
            TObjPlayer__weapon_node_ids[2] = (s16) *(u8 *)((s8 *)temp_r4 + 0x23);
            if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                this->sub_80121208((s32)apply_weapon_node_material);
            } else {
                set_chunk_model_node_callback((s32)apply_weapon_node_material);
            }
            TObjPlayer__sub_80364198();
            model_render_flags &= 0xFFFFFFEF;
            ((TItem *)this)->get_owner_alpha();
            set_model_fade_alpha__10TObjPlayerFf();
            if (((TItem *)this)->has_no_defer_render() != 0) {
                model_render_flags |= 0x8011;
                set_color_blend_mode(1, 4, 5, 0);
                set_shadow_material_state();
                if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                    if (this->test_weapon_flags(0x800000) != 0U) {
                        draw_chunk_object((void *)(*(u32 *)((s8 *)this + 0xF4)));
                    } else {
                        ((TItem *)this)->draw_model_nodes(NULL);
                    }
                } else {
                    set_motion_packed_rotation();
                    draw_model_motion((void *)(*(u32 *)((s8 *)this + 0xF4)), (void *)(*(u32 *)((s8 *)this + 0x17C)), (f32)this->motion_frame);
                    clear_motion_packed_rotation();
                }
                model_render_flags &= 0xFFFF7FEE;
            } else if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                if (this->test_weapon_flags(0x40) != 0U) {
                    ((TItem *)this)->apply_sign_effect((u8 *)(*(s32 *)((s8 *)this->owner + 0xDB4)));
                } else if (this->test_weapon_flags(0x800000) != 0U) {
                    draw_chunk_object((void *)(*(u32 *)((s8 *)this + 0xF4)));
                } else {
                    ((TItem *)this)->draw_model_nodes((u8 *)(*(s32 *)((s8 *)this->owner + 0xDB4)));
                }
            } else {
                set_motion_packed_rotation();
                draw_model_motion((void *)(*(u32 *)((s8 *)this + 0xF4)), (void *)(*(u32 *)((s8 *)this + 0x17C)), (f32)this->motion_frame);
                clear_motion_packed_rotation();
            }
            TItem::end_material_color();
            TItem::end_effect_render();
            ((TItem *)this)->end_particle_tev();
            ((TItem *)this)->end_shield_tev();
            TObjPlayer::warn_if_gauge_low();
            TObjPlayer__sub_8036414C();
            if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                this->sub_80121208(NULL);
            } else {
                set_chunk_model_node_callback(NULL);
            }
            item_render_state.reset();
        } else {
            ((TItem *)this)->visit_model_nodes((u8 *)(*(s32 *)((s8 *)this->owner + 0xDB4)));
        }
        pop_matrix();
        reset_model_node_counter();
    }
}

void draw_weapon_at_joint(s32 arg0, s8 arg1) {
    s8 temp_r31;
    temp_r31 = get_attach_joint__14TItemEquipBaseFv((void *)arg0);
    ((TItemEquipBase *)arg0)->set_attach_joint(arg1);
    ((TItemWeapon *)arg0)->draw_weapon_model();
    ((TItemEquipBase *)arg0)->set_attach_joint(temp_r31);
}
}
