#include "pso/unk/text_800F9B84.h"
#include "pso/player/PlayerState.h"
#include "pso/player/PlayerTaskEffects.h"
#include "types.h"
#include "pso/player/TPlyItem.h"
#include "pso/player/TObjPlayer_801D84CC.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/item/TItem.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TObjEndingPlayer.h"
#include "pso/system/vector.h"
#include "pso/network/TLobby.h"
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
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/TObjBase.h"


extern "C" {
s32 copy_player_visual_record(void *, void *);

s32 advance_item_id_counter();

void process_trade_target__10TObjPlayerFiPv(saddr player, TItemData *item_data) {
    TItem *item;

    ((TObjBase *)player)->get_entity_id();
    item_data->id = advance_item_id_counter();
    item = create_item(item_data);
    if (item != NULL) {
        s8 val = item->get_attach_slot();
        s32 val_ext = (s32)val;
        TItem *slot_item = (TItem *)TObjPlayer::get_slot_value((s32 *)(player + 0xD04), val_ext);
        if (slot_item != NULL) {
            TObjPlayer::send_6x29_delete_item((TObjPlayer *)player, slot_item->get_item_id(), 1);
            set_equip_slot_entry(player + 0xD04, val_ext, 0);
        }
        TObjPlayer *owner = (TObjPlayer *)player;
        if (owner->pickup_item(item) != 0U) {
            owner->set_flag_20000();
            owner->equip_item_to_slot(item, 0);
            owner->clear_flag_20000();
        }
    }
}
void TObjPlayer__sub_801D8664(s32 player, s8 group, s8 kind) {
    TItemData item_data;
    item_data.init();
    item_data.data1.data_u8[1] = group;
    item_data.data1.data_u8[0] = 0;
    item_data.data1.data_u8[2] = kind;
    process_trade_target__10TObjPlayerFiPv(player, &item_data);
}

}
BmlMotionEntry **player_ending_motion_object;
extern "C" {
void translate_matrix_vec3(u8 *matrix, u8 *vec);
s32 rotate_matrix_y(int, int);

int TObjEndingPlayer::set_position_from(void *pos) { return TObjBase::set_position_from(pos); }
void TObjEndingPlayer::set_animation_default(s16 index) { set_animation(index); }

TObjEndingPlayer *TObjEndingPlayer::create(TPlyCharData *data) {
    EndingPlayerRecord record;
    copy_player_visual_record(record.visual, &data->m_disp_part2);
    record.stats = data->m_stats;
    copy_equipped_weapon_and_mag(data->m_inventory.m_num_items,
                data->m_inventory.get_items(),
                record.equipment.items);
    return new TObjEndingPlayer(tl_03, &record);
}

void TObjEndingPlayer::render() {
    if ((test_actor_flags(0x02000000) == 0) && ((s32)model_load_flags == 0)) {
        select_actor_lighting(this);
        push_matrix();
        translate_matrix_vec3(0, (u8 *)&position);
        rotate_matrix_y(0, rotation_y);
        render_material_state.save();
        apply_material_color_override();
        TObjFish::set_global_param(&body_textures);
        set_motion_packed_rotation();
        draw_saving_joints_checked();
        clear_motion_packed_rotation();
        render_material_state.restore();
        draw_head_attachments();
        pop_matrix();
        draw_body_overlay();
        restore_scene_lighting();
        return;
    }
    push_matrix();
    translate_matrix_vec3(0, (u8 *)&position);
    rotate_matrix_y(0, rotation_y);
    calc_joint_matrices(current_motion, frame, (saddr)joint_matrices);
    pop_matrix();
}

void TObjEndingPlayer::run_task() {}

void TObjPlayer::free_shared_lobby_data() { TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(player_ending_motion_object)); player_ending_motion_object = NULL; TObjPlayer::free_shared_data(); }
}

#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/player/TPlyInventory.h"


void create_player_ending_motion(void);
void create_player_ending_motion(void) { TObjPlayer::alloc_shared_buffers(); player_ending_motion_object = static_cast<BmlMotionEntry **>(create_named_object("PlyEndingMotionData.rel")); }

TObjEndingPlayer::TObjEndingPlayer(TObject *parent, EndingPlayerRecord *src) : TObjPlayer(parent, src) {
    set_floor_index(1);
    set_floor_index(1);
    VecCopy(&position, src->pose.get_pos());
    rotation_y = src->pose.get_heading();
    select_class_action_provider();
    joint_matrices = shared_model_buffer + this->get_entity_id() * 0xC00;
    init_motion((TObjMotionAction *)get_table_entry_by_clamped_index(), *player_ending_motion_object, 1);
    frame = src->motion.frame;
    pause_motion();
    push_matrix();
    translate_matrix_vec3(0, (u8 *)&position);
    rotate_matrix_y(0, rotation_y);
    calc_joint_matrices(current_motion, 0.0f, (saddr)joint_matrices);
    pop_matrix();
    TObjPlayer::assign_lobby_slot_if_flagged((saddr)this, &src->equipment.items[0]);
    TObjPlayer::assign_lobby_slot_if_flagged((saddr)this, &src->equipment.items[1]);
}

TObjEndingPlayer::~TObjEndingPlayer() {}

EndingMotionStart::EndingMotionStart() {
    pad_0 = 1;
    frame = 0.0f;
}

EndingPlayerRecord::EndingPlayerRecord() {}

EquippedWeaponAndMag::EquippedWeaponAndMag() {
    s32 i;

    for (i = 0; i < 2; i++) {
        items[i].init();
    }
}
