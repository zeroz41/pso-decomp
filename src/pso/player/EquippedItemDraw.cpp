#include "pso/system/NinjaTypes.h"
#include "pso/player/TEquippedItemDrawTask.h"
#include "pso/player/TEquippedWeaponDrawTask.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/memory.h"

#include "pso/item/TItemLoad.h"
#include "pso/item/EquippedItemDrawQueue.h"
#include "pso/render/model_render_state.h"
#include "pso/system/task/TObject.h"

#pragma defer_codegen on

EquippedItemDrawQueue *equipped_weapon_draw_queue;
EquippedItemDrawQueue *player_item_id_list;

static const NJS_ARGB default_fade_color = {0.0f, 0.0f, 0.0f, 0.0f};

EquippedItemDrawQueue::EquippedItemDrawQueue() {
    reset();
}

void EquippedItemDrawQueue::reset() {
    u32 *p = item_ids;
    int i;
    for (i = 0; i < 32; i++) {
        *p++ = -1;
    }
    count = 0;
}

void EquippedItemDrawQueue::push(s32 id) {
    s32 n = count;
    if (n < 0x20) {
        item_ids[n] = (u32)id;
        count = count + 1;
    }
}

void TEquippedWeaponDrawTask::create_queue() {
    equipped_weapon_draw_queue = new EquippedItemDrawQueue;
}

void TEquippedWeaponDrawTask::destroy_queue() {
    if (equipped_weapon_draw_queue != NULL) {
        ::operator delete(equipped_weapon_draw_queue);
        equipped_weapon_draw_queue = NULL;
    }
}

void TEquippedWeaponDrawTask::save_model_render_state() {
    equipped_weapon_draw_queue->saved_model_render_flags = model_render_flags;
    copy_argb(&equipped_weapon_draw_queue->saved_model_material_color, &model_material_color);
    equipped_weapon_draw_queue->saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    equipped_weapon_draw_queue->saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
}

void TEquippedWeaponDrawTask::restore_model_render_state() {
    model_render_flags = equipped_weapon_draw_queue->saved_model_render_flags;
    copy_argb(&model_material_color, &equipped_weapon_draw_queue->saved_model_material_color);
    chunk_polygon_flags_and_mask = equipped_weapon_draw_queue->saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = equipped_weapon_draw_queue->saved_chunk_polygon_flags_or_mask;
}

void TEquippedWeaponDrawTask::push_fade_color(NJS_ARGB *color) {
    copy_argb(&equipped_weapon_draw_queue->saved_fade_color, &model_material_color);
    if (color != NULL) {
        copy_argb(&model_material_color, color);
    }
}

void TEquippedWeaponDrawTask::pop_fade_color() {
    copy_argb(&model_material_color, &equipped_weapon_draw_queue->saved_fade_color);
}

void TEquippedWeaponDrawTask::set_fade_alpha(f32 alpha) {
    if (alpha < 1.0f) {
        model_render_flags |= 0x24;
        set_chunk_material_override_pair(-1, 0x800);
        set_chunk_blend(0x2500);
        NJS_ARGB color = default_fade_color;
        color.a = alpha - 1.0f;
        push_fade_color(&color);
    }
    equipped_weapon_draw_queue->fade_alpha = alpha;
}

void TEquippedWeaponDrawTask::end_fade() {
    if (equipped_weapon_draw_queue->fade_alpha < 1.0f) {
        set_chunk_blend(0x2500);
        pop_fade_color();
    }
}

void TEquippedWeaponDrawTask::create(TObject *parent) {
    new TEquippedWeaponDrawTask(parent);
}

void TEquippedWeaponDrawTask::queue_weapon(s32 item_id) {
    if (equipped_weapon_draw_queue->count == 0) {
        equipped_weapon_draw_queue->reset();
    }
    equipped_weapon_draw_queue->push(item_id);
}

TEquippedWeaponDrawTask::TEquippedWeaponDrawTask(TObject *parent) : TObject(parent) {
    equipped_weapon_draw_queue->reset();
}

TEquippedWeaponDrawTask::~TEquippedWeaponDrawTask() {
}

void TEquippedWeaponDrawTask::run_task() {
    NJS_OBJECT *model;
    NJS_TEXLIST *texture;

    TItemLoad::get_drop_model(5, &model, &texture);
    if (model != NULL) {
        scroll_item_model_uvs(model->child, 2, 2, 0xB);
    }
}

void TEquippedWeaponDrawTask::render() {
    u32 *id;
    s32 remaining;
    TItem *item;
    set_default_alpha_blend();
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    copy_argb(&saved_model_draw_color, &model_material_color);
    remaining = equipped_weapon_draw_queue->count;
    id = equipped_weapon_draw_queue->item_ids;
    while (remaining != 0) {
        item = find_equipped_item(*id++);
        if (item != NULL) {
            set_draw_list_mask(1);
            item->render_equipped_deferred();
            set_default_alpha_blend();
            copy_argb(&model_material_color, &saved_model_draw_color);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
            set_draw_list_mask(2);
            item->render_equipped_deferred();
            set_default_alpha_blend();
            copy_argb(&model_material_color, &saved_model_draw_color);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
        remaining--;
    }
    restore_draw_list_mask();
    equipped_weapon_draw_queue->count = 0;
}

void TEquippedItemDrawTask::create_queue() {
    player_item_id_list = new EquippedItemDrawQueue;
}

void TEquippedItemDrawTask::destroy_queue() {
    if (player_item_id_list != NULL) {
        ::operator delete(player_item_id_list);
        player_item_id_list = NULL;
    }
}

void TEquippedItemDrawTask::create(TObject *parent) {
    new TEquippedItemDrawTask(parent);
}

TEquippedItemDrawTask::TEquippedItemDrawTask(TObject *parent) : TObject(parent) {
    player_item_id_list->reset();
}

TEquippedItemDrawTask::~TEquippedItemDrawTask() {
}

void TEquippedItemDrawTask::run_task() {
    player_item_id_list->reset();
}

void TEquippedItemDrawTask::render() {
    set_default_alpha_blend();
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    copy_argb(&saved_model_draw_color, &model_material_color);
    u32 *id = player_item_id_list->item_ids;
    s32 remaining = player_item_id_list->count;
    while (remaining != 0) {
        TItem *item = find_equipped_item(*id++);
        if (item) {
            item->render_equipped();
            set_default_alpha_blend();
            copy_argb(&model_material_color, &saved_model_draw_color);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
        --remaining;
    }
}

void TItem::push_equipped_id(s32 id) {
    player_item_id_list->push(id);
}
