#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/item/TItem.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TUnk_804C4540.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerClassStats.h"
#include "pso/map/FloorArea.h"

#include <stddef.h>
#include "pso/map/FloorArea.h"
#include "pso/item/TItemData.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
struct Stack_801D8664 {
    s8 sp8;
    s8 sp9;
    s8 spA;
    u8 rest[0x11];
};

struct Player_801D88C8;
struct Src_801D88C8;
struct Rec_801D86F8 { s32 a[0x50 / 4]; s32 b[0x38 / 4]; s32 c[0x40 / 4]; };

extern "C" {
void process_trade_target__10TObjPlayerFiPv(s32 arg0, void *arg1);
void TObjPlayer__sub_801D8664(s32 arg0, s8 arg1, s8 arg2);
void copy_data__6TLobbyFPvPv(void *arg0, void *arg1);
s32 copy_player_visual_record(void *, void *);
s32 fn_801D40D4(void *, void *, void *);
Player_801D88C8 *create_ending_sequence_player(Player_801D88C8 *self, void *parent, Src_801D88C8 *src);
extern s32 tl_03;
struct VObj_84Base_801d859c_801D84CC { char pad[0x18]; };
struct VObj_84_801d859c_801D84CC : VObj_84Base_801d859c_801D84CC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30();
    virtual s8 m31();
};

s32 advance_item_id_counter();
void send_6x29_delete_item__10TObjPlayerFPvii(void *obj, s32 a, s32 b);
void *pickup_item__10TObjPlayerFP5TItem(u8 *arg0, u8 *arg1);
void set_equip_slot_entry(s32 arg0, s32 arg1, s32 arg2);
s32 get_item_id__5TItemFv();
u16 get_entity_id(void *);

void process_trade_target__10TObjPlayerFiPv(s32 arg0, void *player) {
    void *temp_r3;

    ((s32 (*)())get_entity_id)();
    *(s32 *)((s8 *)player + 0xC) = advance_item_id_counter();
    temp_r3 = create_item((TItemData *)player);
    if (temp_r3 != NULL) {
        s8 val = ((VObj_84_801d859c_801D84CC *)temp_r3)->m31();
        s32 val_ext = (s32)val;
        if (TObjPlayer::get_slot_value((s32 *)(arg0 + 0xD04), val_ext) != 0U) {
            send_6x29_delete_item__10TObjPlayerFPvii((void *)arg0, get_item_id__5TItemFv(), 1);
            set_equip_slot_entry(arg0 + 0xD04, val_ext, 0);
        }
        if (pickup_item__10TObjPlayerFP5TItem((u8 *)arg0, (u8 *)temp_r3) != 0U) {
            ((TObjPlayer *)arg0)->set_flag_20000();
            ((TObjPlayer *)arg0)->equip_item_to_slot(temp_r3, 0);
            ((TObjPlayer *)arg0)->sub_801BE9A8();
        }
    }
}
void TObjPlayer__sub_801D8664(s32 arg0, s8 arg1, s8 arg2) {
    typedef char sp8_offset[(offsetof(Stack_801D8664, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_801D8664, sp9) == 0x1) ? 1 : -1];
    typedef char spA_offset[(offsetof(Stack_801D8664, spA) == 0x2) ? 1 : -1];
    Stack_801D8664 stack;
    ((TItemData *)(&stack.sp8))->init();
    stack.sp9 = arg1;
    stack.sp8 = 0;
    stack.spA = arg2;
    process_trade_target__10TObjPlayerFiPv(arg0, &stack.sp8);
}

s32 calc_joint_matrices__10TObjMotionFP10NJS_MOTIONfl(void *, s32, f32, s32);
void push_matrix(void);
s32 pop_matrix(void);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
s32 TObjPlayer__sub_801BAC48(void *);
}
int player_ending_motion_object;
void save_render_material_state(u8 *arg0);
extern "C" {
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, int);
void TObjPlayer__sub_801D877C(u8 *arg0);
void TObjPlayer__sub_801D8864(void);

int TUnk_804C4540::set_position_from(void *pos) { return TObjBase::set_position_from(pos); }
void TUnk_804C4540::set_animation_default(s16 index) { set_animation(index); }

TUnk_804C4540 *TUnk_804C4540::create(TPlyCharData *data) {
    Rec_801D86F8 sp8;
    TUnk_804C4540 *player;
    ((TObjPlayer *)(&sp8))->init_inventory();
    copy_player_visual_record(&sp8, &data->m_disp_data.m_disp_part2);
    copy_data__6TLobbyFPvPv(sp8.c, &data->m_disp_data);
    fn_801D40D4((void *)data->m_inventory.m_num_items, (void *)((TObjPlayer *)data)->get_ptr_4(), sp8.b);
    player = (TUnk_804C4540 *)TObject::operator new(0xDB8);
    if (player != NULL) {
        player = (TUnk_804C4540 *)create_ending_sequence_player((Player_801D88C8 *)player, (void *)tl_03, (Src_801D88C8 *)&sp8);
    }
    return player;
}

void TObjPlayer__sub_801D877C(u8 *arg0) {
    if ((((TObjCollidable *)arg0)->obj_testFlags30(0x02000000) == 0) && ((s32) ((TUnk_804C4540 *)arg0)->m_cfc == 0)) {
        select_actor_lighting((s32)arg0);
        push_matrix();
        translate_matrix_vec3(0, (arg0 + 0x38));
        rotate_matrix_y(0, (int) (((TUnk_804C4540 *)arg0)->rotation_y));
        save_render_material_state((arg0 + 0x608));
        ((TObjPlayer *)arg0)->apply_material_color_override();
        TObjFish::set_global_param((s32)(arg0 + 0xCF4));
        set_motion_packed_rotation();
        ((TObjPlayer *)arg0)->draw_saving_joints_checked();
        clear_motion_packed_rotation();
        ((TObjPlayer *)(arg0 + 0x608))->write_ids();
        ((TObjPlayer *)arg0)->draw_head_attachments();
        pop_matrix();
        TObjPlayer__sub_801BAC48(arg0);
        restore_scene_lighting();
        return;
    }
    push_matrix();
    translate_matrix_vec3(0, (arg0 + 0x38));
    rotate_matrix_y(0, (int) (((TUnk_804C4540 *)arg0)->rotation_y));
    ((TUnk_804C4540 *)arg0)->calc_joint_matrices(((TUnk_804C4540 *)arg0)->current_motion, ((TUnk_804C4540 *)arg0)->frame, *(s32 *)((s8 *)arg0 + 0xE0));
    pop_matrix();
}

void TObjPlayer__sub_801D8864(void) {  }

void TObjPlayer::free_shared_lobby_data() { TLobby::free_nodes_with_id(player_ending_motion_object); player_ending_motion_object = 0; TObjPlayer::free_shared_data(); }
}

#include "pso/boss/darkfalz/TBoss4DarkFalz.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

typedef struct Src_801D88C8 {
    u8 pad0[0x50];
    u8 slot0[0x1C];
    u8 slot1[0x40];
    u8 sub[0x18];
    f32 frame;
} Src_801D88C8;

typedef struct Player_801D88C8 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x38 - 0x1C];
    u8 pos[12];
    u8 pad44[0x60 - 0x44];
    s32 ang;
    u8 pad64[0xC0 - 0x64];
    f32 frame;
    u8 padc4[0xE0 - 0xC4];
    u8 *model;
    u8 pade4[0xF8 - 0xE4];
    void *motion;
} Player_801D88C8;

extern "C" {
void TObjPlayer__ct(void *, void *);
extern s32 ending_sequence_player_vtable[];
extern u8 *TObjPlayer__shared_model_buffer;
void *__dt__13TUnk_804C4540Fv(void *arg0, s16 arg1);
void TObjPlayer__sub_801D8A38(void* a0);
void TObjPlayer__sub_801BFF80(u8 *arg0);
void __dl__7TObjectFPv(void *);
void *__dt__10TObjPlayerFv(void *arg0, s16 arg1);
void init__17TPlyInventoryItemFv(u8 *arg0);
}
void create_player_ending_motion(void);
s32 create_named_object(s32 arg0);
void create_player_ending_motion(void) { TObjPlayer::alloc_shared_buffers(); player_ending_motion_object = create_named_object((s32)"PlyEndingMotionData.rel"); }

Player_801D88C8 *create_ending_sequence_player(Player_801D88C8 *self, void *parent, Src_801D88C8 *src) {
    TObjPlayer__ct(self, parent);
    self->vt = ((s32 *)&ending_sequence_player_vtable);
    ((TObjPlayer *)self)->set_floor_index(1);
    ((TObjPlayer *)self)->set_floor_index(1);
    VecCopy((Vec *)self->pos, (const Vec *)(((TObjPlayer *)(src->sub))->get_sub_object()));
    self->ang = ((TObjPlayer *)(src->sub))->get_lock_timer();
    ((TObjPlayer *)self)->select_class_action_provider();
    self->model = TObjPlayer__shared_model_buffer + get_entity_id(self) * 0xC00;
    ((TObjPlayer *)self)->init_motion((TObjMotionAction *)((TObjPlayer *)self)->get_table_entry_by_clamped_index(), (BmlMotionEntry *)*(s32 *)player_ending_motion_object, 1);
    self->frame = src->frame;
    ((TObjPlayer *)self)->set_action_flag_40();
    push_matrix();
    translate_matrix_vec3(0, self->pos);
    rotate_matrix_y(0, self->ang);
    ((void (*)(void *, void *, f32, void *))calc_joint_matrices__10TObjMotionFP10NJS_MOTIONfl)(self, self->motion, 0.0f, self->model);
    pop_matrix();
    TObjPlayer::assign_lobby_slot_if_flagged((s32)self, src->slot0);
    TObjPlayer::assign_lobby_slot_if_flagged((s32)self, src->slot1);
    return self;
}

void *__dt__13TUnk_804C4540Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = ending_sequence_player_vtable;
        __dt__10TObjPlayerFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjPlayer__sub_801D8A38(void* a0) { *(short*)((char*)a0 + 0x0) = 1; *(float*)((char*)a0 + 0x4) = 0.0f; }

void*TObjPlayer::init_inventory() { TObjPlayer::init_inventory_items((s32)((s32)((char*)this + 0x50))); TObjPlayer__sub_801BFF80((u8 *)((char*)this + 0xac)); TObjPlayer__sub_801D8A38((void*)((void*)((char*)this + 0xc0))); return this; }

s32 TObjPlayer::init_inventory_items(s32 arg0) {
    s32 var_r30;
    s32 var_r31;

    var_r31 = 0;
    var_r30 = 0;
    do {
        init__17TPlyInventoryItemFv((u8 *)(arg0 + var_r30));
        var_r31 += 1;
        var_r30 += 0x1C;
    } while (var_r31 < 2);
    return arg0;
}
