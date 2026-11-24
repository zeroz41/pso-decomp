#include "pso/unk/text_800F9B84.h"
#include "pso/player/PlayerState.h"
#include "types.h"
#include "pso/unk/text_801D40D4.h"
#include "pso/player/TObjPlayer_801D84CC.h"
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

#include "pso/item/TItemData.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

struct Stack_801D8664 {
    s8 sp8;
    s8 sp9;
    s8 spA;
    u8 rest[0x11];
};


extern "C" {
s32 copy_player_visual_record(void *, void *);
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

void process_trade_target__10TObjPlayerFiPv(saddr arg0, void *player) {
    void *item;

    ((TObjBase *)arg0)->get_entity_id();
    *(s32 *)((s8 *)player + 0xC) = advance_item_id_counter();
    item = create_item((TItemData *)player);
    if (item != NULL) {
        s8 val = ((VObj_84_801d859c_801D84CC *)item)->m31();
        s32 val_ext = (s32)val;
        TItem *slot_item = (TItem *)TObjPlayer::get_slot_value((s32 *)(arg0 + 0xD04), val_ext);
        if (slot_item != NULL) {
            TObjPlayer::send_6x29_delete_item((void *)arg0, slot_item->get_item_id(), 1);
            set_equip_slot_entry(arg0 + 0xD04, val_ext, 0);
        }
        if (((TObjPlayer *)arg0)->pickup_item((TItem *)item) != 0U) {
            ((TObjPlayer *)arg0)->set_flag_20000();
            ((TObjPlayer *)arg0)->equip_item_to_slot(reinterpret_cast<TItem *>(item), 0);
            ((TObjPlayer *)arg0)->clear_flag_20000();
        }
    }
}
void TObjPlayer__sub_801D8664(s32 arg0, s8 arg1, s8 arg2) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_801D8664, sp8) == 0x0);
    LAYOUT_ASSERT(sp9_offset, offsetof(Stack_801D8664, sp9) == 0x1);
    LAYOUT_ASSERT(spA_offset, offsetof(Stack_801D8664, spA) == 0x2);
    Stack_801D8664 stack;
    ((TItemData *)(&stack.sp8))->init();
    stack.sp9 = arg1;
    stack.sp8 = 0;
    stack.spA = arg2;
    process_trade_target__10TObjPlayerFiPv(arg0, &stack.sp8);
}

s32 TObjPlayer__sub_801BAC48(void *);
}
BmlMotionEntry **player_ending_motion_object;
void save_render_material_state(u8 *arg0);
extern "C" {
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, int);

int TUnk_804C4540::set_position_from(void *pos) { return TObjBase::set_position_from(pos); }
void TUnk_804C4540::set_animation_default(s16 index) { set_animation(index); }

TUnk_804C4540 *TUnk_804C4540::create(TPlyCharData *data) {
    TUnk_801D8A4C sp8;
    ((TObjPlayer *)(&sp8))->init_inventory();
    copy_player_visual_record(sp8.visual, &data->m_disp_part2);
    TLobby::copy_data(sp8.stats, &data->m_stats);
    fn_801D40D4(data->m_inventory.m_num_items,
                data->m_inventory.get_items(),
                reinterpret_cast<TPlyInventoryItem *>(sp8.items));
    return new TUnk_804C4540(tl_03, &sp8);
}

void TUnk_804C4540::render() {
    if ((test_actor_flags(0x02000000) == 0) && ((s32)model_load_flags == 0)) {
        select_actor_lighting(this);
        push_matrix();
        translate_matrix_vec3(0, (u8 *)&position);
        rotate_matrix_y(0, rotation_y);
        save_render_material_state((u8 *)&render_material_state);
        apply_material_color_override();
        TObjFish::set_global_param(&body_textures);
        set_motion_packed_rotation();
        draw_saving_joints_checked();
        clear_motion_packed_rotation();
        ((TObjPlayer *)&render_material_state)->write_ids();
        draw_head_attachments();
        pop_matrix();
        TObjPlayer__sub_801BAC48(this);
        restore_scene_lighting();
        return;
    }
    push_matrix();
    translate_matrix_vec3(0, (u8 *)&position);
    rotate_matrix_y(0, rotation_y);
    calc_joint_matrices(current_motion, frame, (saddr)joint_matrices);
    pop_matrix();
}

void TUnk_804C4540::run_task() {}

void TObjPlayer::free_shared_lobby_data() { TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(player_ending_motion_object)); player_ending_motion_object = NULL; TObjPlayer::free_shared_data(); }
}

#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/player/TPlyInventory.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
extern u8 *TObjPlayer__shared_model_buffer;
}
void create_player_ending_motion(void);
void create_player_ending_motion(void) { TObjPlayer::alloc_shared_buffers(); player_ending_motion_object = static_cast<BmlMotionEntry **>(create_named_object("PlyEndingMotionData.rel")); }

TUnk_804C4540::TUnk_804C4540(TObject *parent, TUnk_801D8A4C *src) : TObjPlayer(parent, src) {
    set_floor_index(1);
    set_floor_index(1);
    VecCopy(&position, (const Vec *)((TObjPlayer *)src->pose)->get_sub_object());
    rotation_y = ((TObjPlayer *)src->pose)->get_lock_timer();
    select_class_action_provider();
    joint_matrices = TObjPlayer__shared_model_buffer + this->get_entity_id() * 0xC00;
    init_motion((TObjMotionAction *)get_table_entry_by_clamped_index(), *player_ending_motion_object, 1);
    frame = src->frame;
    set_action_flag_40();
    push_matrix();
    translate_matrix_vec3(0, (u8 *)&position);
    rotate_matrix_y(0, rotation_y);
    calc_joint_matrices(current_motion, 0.0f, (saddr)joint_matrices);
    pop_matrix();
    TObjPlayer::assign_lobby_slot_if_flagged((saddr)this, &src->items[0]);
    TObjPlayer::assign_lobby_slot_if_flagged((saddr)this, &src->items[1]);
}

TUnk_804C4540::~TUnk_804C4540() {}

void TObjPlayer__sub_801D8A38(void* a0) { *(short*)((char*)a0 + 0x0) = 1; *(float*)((char*)a0 + 0x4) = 0.0f; }

void*TObjPlayer::init_inventory() { TObjPlayer::init_inventory_items((s32)((saddr)((char*)this + 0x50))); TObjPlayer__sub_801BFF80((u8 *)((char*)this + 0xac)); TObjPlayer__sub_801D8A38((void*)((void*)((char*)this + 0xc0))); return this; }

s32 TObjPlayer::init_inventory_items(saddr arg0) {
    s32 var_r30;
    s32 i;

    i = 0;
    var_r30 = 0;
    do {
        ((TPlyInventoryItem *)(arg0 + var_r30))->init();
        i += 1;
        var_r30 += 0x1C;
    } while (i < 2);
    return arg0;
}
