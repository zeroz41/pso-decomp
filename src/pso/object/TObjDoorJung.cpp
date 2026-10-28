#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/misc/TScene.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8018F9CC_lbl_804B788C {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8018F9CC___vt__12TObjDoorJung {
    s32 value;
    u8 remaining[0x54];
};

struct VBase_8018F644 { char pad[0x18]; };
struct VObj_8018F644 : VBase_8018F644 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Jung_8018F808 { u8 pad0[0xC8]; s32 fC8; u8 padCC[4]; u32 fD0; s32 fD4; };

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
void *init_door_base(void *a0);
extern RecoveredGlobal_8018F9CC_lbl_804B788C TObjDoorJung__collision_desc;
extern s32 __vt__12TObjDoorJung[];
extern s32 TObjDoorJung__class_name;
u8 *TObjDoorJung__ct(u8 *arg0, s32 arg1, s32 arg2);
u8 is_current_floor_switch_set(int);
/* Ninja object node of the door model: model pointer, transform, then child and sibling links. */
struct Node_8018F4AC {
    u32 eval_flags;
    s32 model;
    f32 position[3];
    s32 angle[3];
    f32 scale[3];
    Node_8018F4AC *child;
    Node_8018F4AC *sibling;
};
Node_8018F4AC *get_bml_model(void *, int);
void free_children__12TObjDoorJungFPv(s32, u16);
void PPCSync();
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_object(void *child);
extern s32 TObjDoorJung__child_table[];
extern s32 actor_frame_tick;
extern void *TObjDoorJung__resource_handle;
extern s32 lbl_805D5BD4;
extern s32 door_jung_child_list;
extern s32 lbl_805D5BDC;
extern void *TObjDoorJung__door_scene_buffer;
extern s32 lbl_805D5BE4;
extern s32 lbl_805D5BE8;
extern s32 lbl_805D5BEC;
extern s32 lbl_805D5BF0;
extern const f32 lbl_805DBDF8;
extern const f32 lbl_805DBDFC;

void *__dt__12TObjDoorJungFv(void *arg0, s16 arg1);
s32 TLobby__sub_8001FE7C(void *, s16);
s32 free_collision_body_parts(void *);
s32 minimap_render_gate(void *, s32, u16, s32, s32);
s32 __dl__7TObjectFPv(void *);

void TObjDoorJung::free_buffers() {
    if (TObjDoorJung__door_scene_buffer != NULL) {
        ((TScene *)TObjDoorJung__door_scene_buffer)->destroy_buffers(1);
        TObjDoorJung__door_scene_buffer = NULL;
    }
    if (TObjDoorJung__resource_handle != NULL) {
        TLobby__sub_8001FE7C(TObjDoorJung__resource_handle, 1);
        TObjDoorJung__resource_handle = NULL;
    }
}

struct DoorJungPartNames {
    const char *names[4];
};
extern const DoorJungPartNames lbl_80445640;
extern u8 bm_obj_beamdoa_resource_descriptor[];
s32 load_resource_from_descriptor(s32 buffer, s32 kind, void *descriptor, s32 a3, s32 a4, s32 a5);
s32 TObjFish__sub_8001EDB0(void *bml, s32 index);

void TObjDoorJung__sub_8018F4AC(void) {
    s32 handle;
    Node_8018F4AC *model;
    Node_8018F4AC *node;
    void *scene;

    handle = (int)::operator new(0x440);
    if (handle != 0) {
        handle = load_resource_from_descriptor(handle, 5, bm_obj_beamdoa_resource_descriptor, 0, 0, 0);
    }
    TObjDoorJung__resource_handle = (void *)handle;
    lbl_805D5BD4 = TObjFish__sub_8001EDB0(TObjDoorJung__resource_handle, 0);
    model = get_bml_model(TObjDoorJung__resource_handle, 1);
    node = model->child;
    TObjDoorJung__child_table[0] = node->model;
    TObjDoorJung__child_table[1] = node->child->model;
    TObjDoorJung__child_table[2] = node->child->child->model;
    TObjDoorJung__child_table[3] = node->child->child->child->model;
    door_jung_child_list = model->child->sibling->model;
    lbl_805D5BDC = 0;
    DoorJungPartNames parts = lbl_80445640;
    lbl_805D5BE4 = ((TObjDoorJung *)lbl_805D5BD4)->find_entry_by_name(parts.names[0]);
    lbl_805D5BE8 = ((TObjDoorJung *)lbl_805D5BD4)->find_entry_by_name(parts.names[1]);
    lbl_805D5BEC = ((TObjDoorJung *)lbl_805D5BD4)->find_entry_by_name(parts.names[2]);
    lbl_805D5BF0 = ((TObjDoorJung *)lbl_805D5BD4)->find_entry_by_name(parts.names[3]);
    if (lbl_805D5BEC != -1) {
        scene = (void *)::operator new(0x14);
        if (scene != NULL) {
            scene = ((TScene *)scene)->init_buffers((s32)model->child->sibling, lbl_805D5BEC);
        }
        TObjDoorJung__door_scene_buffer = scene;
    } else {
        TObjDoorJung__door_scene_buffer = NULL;
    }
}

void TObjDoorJung::clamp_state() {
    *(s32 *)&this->unk_D4 = (s32) *(s32 *)&this->set_params[1];
    if ((s32) *(s32 *)&this->unk_D4 < 0) {
        *(s32 *)&this->unk_D4 = 0;
    }
    if ((s32) *(s32 *)&this->unk_D4 > 4) {
        *(s32 *)&this->unk_D4 = 4;
    }
}

void TObjDoorJung::render() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    s32 j;

    if (((VObj_8018F644 *)arg0)->m8(lbl_805DBDF8, lbl_805DBDFC) != 0) {
        if (this->m_d0 & 1) {
            if (lbl_805D5BF0 >= 0) {
                free_children__12TObjDoorJungFPv(door_jung_child_list, lbl_805D5BF0);
            }
        } else if (lbl_805D5BEC >= 0) {
            free_children__12TObjDoorJungFPv(door_jung_child_list, lbl_805D5BEC);
        }
        if (actor_frame_tick != lbl_805D5BDC) {
            if (TObjDoorJung__door_scene_buffer != NULL) {
                ((TScene *)TObjDoorJung__door_scene_buffer)->offset_position(0, -0xA);
            }
            lbl_805D5BDC = actor_frame_tick;
            PPCSync();
        }
        for (i = 0; i < *(s32 *)&this->unk_D4; i++) {
            if (is_current_floor_switch_set((u16)(*(s32 *)&this->unk_C8 + i)) == 1) {
                if (lbl_805D5BE8 >= 0) {
                    free_children__12TObjDoorJungFPv(TObjDoorJung__child_table[i], lbl_805D5BE8);
                }
            } else if (lbl_805D5BE4 >= 0) {
                free_children__12TObjDoorJungFPv(TObjDoorJung__child_table[i], lbl_805D5BE4);
            }
        }
        for (j = *(s32 *)&this->unk_D4; j < 4; j++) {
            if (lbl_805D5BE8 >= 0) {
                free_children__12TObjDoorJungFPv(TObjDoorJung__child_table[j], lbl_805D5BE8);
            }
        }
        TObjFish::set_global_param((s32)((void *)lbl_805D5BD4));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object(get_bml_model(TObjDoorJung__resource_handle, 0));
        TParticleCtrl::begin_effect_render();
        draw_ginja_object(get_bml_model(TObjDoorJung__resource_handle, 1));
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

extern s32 switch_doors_force_closed;

void TObjDoorJung::update_door_switch_state() {
    s32 ok = 1;
    s32 i = 0;
    while (i < ((Jung_8018F808 *)this)->fD4) {
        s32 t = is_current_floor_switch_set((u16)(((Jung_8018F808 *)this)->fC8 + i)) - 1;
        i++;
        ok = (t == 0) ? (ok & 1) : 0;
    }
    if (ok != 0) {
        ((Jung_8018F808 *)this)->fD0 |= 1;
        set_indexed_flags(0, 8);
        return;
    }
    ((Jung_8018F808 *)this)->fD0 &= ~1;
    ((TUnk_804AF8A0 *)((Jung_8018F808 *)this))->clear_player_status_flag(0, 8);
}

void TObjDoorJung::run_task() {
    u8 *arg0 = (u8 *)this;
    if ((s32) switch_doors_force_closed != 0) {
        this->m_d0 = (s32) (this->m_d0 & 0xFFFFFFFE);
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 8);
    } else {
        this->update_door_switch_state();
    }
    if (this->m_d0 & 1) {
        minimap_render_gate((u8 *)&this->position, 0xFF00FF00, (u16) this->rotation_y, 0, 0);
        return;
    }
    minimap_render_gate((u8 *)&this->position, 0xFFFF0000, (u16) this->rotation_y, 0, 0);
}

void *__dt__12TObjDoorJungFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjDoorJung;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B0BB8 *)arg0)->destroy_ancient_door_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8018F9CC_lbl_804B788C_size[sizeof(RecoveredGlobal_8018F9CC_lbl_804B788C) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8018F9CC___vt__12TObjDoorJung_size[sizeof(RecoveredGlobal_8018F9CC___vt__12TObjDoorJung) == 0x58 ? 1 : -1];
u8 *TObjDoorJung__ct(u8 *arg0, s32 arg1, s32 arg2) {
    init_door_base((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8018F9CC___vt__12TObjDoorJung *)&__vt__12TObjDoorJung).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjDoorJung__class_name;
    ((TObjDoorJung *)(arg0))->apply_object_set_data((void *)arg2);
    init_collision_body_parts(arg0, &TObjDoorJung__collision_desc.value, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TObjDoorJung *)(arg0))->init_door_switch_binding();
    ((TObjDoorJung *)arg0)->clamp_state();
    return arg0;
}

}
