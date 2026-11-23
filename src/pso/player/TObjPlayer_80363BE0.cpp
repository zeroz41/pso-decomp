#include "pso/system/NinjaTypes.h"
#include "pso/player/TEquippedItemDrawTask.h"
#include "pso/player/TEquippedWeaponDrawTask.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/player/TObjPlayer_80363BE0.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/memory.h"

#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/EquippedItemDrawQueue.h"
#include "pso/render/model_render_state.h"
#include "pso/system/task/TObject.h"

#pragma defer_codegen on

EquippedItemDrawQueue *lbl_805D6FB8;
EquippedItemDrawQueue *player_item_id_list;

static const NJS_ARGB default_fade_color = {0.0f, 0.0f, 0.0f, 0.0f};

saddr TObjPlayer::run_and_return_arg(saddr queue) {
    ((EquippedItemDrawQueue *)queue)->reset();
    return queue;
}

void EquippedItemDrawQueue::reset() {
    u32 *p = item_ids;
    int i;
    for (i = 0; i < 32; i++) {
        *p++ = -1;
    }
    count = 0;
}

void TObjPlayer::push_to_list(s32 id) {
    void *self = this;
    EquippedItemDrawQueue *queue = (EquippedItemDrawQueue *)self;
    s32 count = queue->count;
    if (count < 0x20) {
        queue->item_ids[count] = (u32)id;
        queue->count = queue->count + 1;
    }
}

void TObjPlayer::alloc_and_init_object_b4() {
    void *o = ::operator new(sizeof(EquippedItemDrawQueue));
    if (o != NULL) {
        o = (void *)TObjPlayer::run_and_return_arg((saddr)o);
    }
    lbl_805D6FB8 = (EquippedItemDrawQueue *)o;
}

void TObjPlayer::free_global_805D6FB8() {
    if (lbl_805D6FB8 != NULL) {
        ::operator delete(lbl_805D6FB8);
        lbl_805D6FB8 = NULL;
    }
}

void TObjPlayer::save_model_render_state() {
    lbl_805D6FB8->saved_model_render_flags = model_render_flags;
    copy_argb(&lbl_805D6FB8->saved_model_material_color, &model_material_color);
    lbl_805D6FB8->saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    lbl_805D6FB8->saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
}

void TObjPlayer::restore_model_render_state() {
    model_render_flags = lbl_805D6FB8->saved_model_render_flags;
    copy_argb(&model_material_color, &lbl_805D6FB8->saved_model_material_color);
    chunk_polygon_flags_and_mask = lbl_805D6FB8->saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = lbl_805D6FB8->saved_chunk_polygon_flags_or_mask;
}

void TObjPlayer::push_model_fade_color() {
    copy_argb(&lbl_805D6FB8->saved_fade_color, &model_material_color);
    void *self = this;
    if (self != NULL) {
        copy_argb(&model_material_color, (NJS_ARGB *)self);
    }
}

void TObjPlayer::copy_gauge_warn_vec() {
    copy_argb(&model_material_color, &lbl_805D6FB8->saved_fade_color);
}

void TObjPlayer::set_model_fade_alpha(f32 alpha) {
    if (alpha < 1.0f) {
        model_render_flags |= 0x24;
        set_chunk_material_override_pair(-1, 0x800);
        set_chunk_blend(0x2500);
        NJS_ARGB color = default_fade_color;
        color.a = alpha - 1.0f;
        ((TObjPlayer *)&color)->push_model_fade_color();
    }
    lbl_805D6FB8->fade_alpha = alpha;
}

void TObjPlayer::warn_if_gauge_low() {
    if (lbl_805D6FB8->fade_alpha < 1.0f) {
        set_chunk_blend(0x2500);
        TObjPlayer::copy_gauge_warn_vec();
    }
}

void TObjPlayer::spawn_cleanup_helper(void *parent) {
    new TEquippedWeaponDrawTask((TObject *)parent);
}

void TObjPlayer::push_id_to_list(s32 id) {
    if (lbl_805D6FB8->count == 0) {
        lbl_805D6FB8->reset();
    }
    ((TObjPlayer *)lbl_805D6FB8)->push_to_list(id);
}

TEquippedWeaponDrawTask::TEquippedWeaponDrawTask(TObject *parent) : TObject(parent) {
    lbl_805D6FB8->reset();
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
    remaining = lbl_805D6FB8->count;
    id = lbl_805D6FB8->item_ids;
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
    lbl_805D6FB8->count = 0;
}

void TObjPlayer::alloc_and_run_object() {
    void *o = ::operator new(sizeof(EquippedItemDrawQueue));
    if (o != NULL) {
        o = (void *)TObjPlayer::run_and_return_arg((saddr)o);
    }
    player_item_id_list = (EquippedItemDrawQueue *)o;
}

void TObjPlayer::free_static_buffer() {
    if (player_item_id_list != NULL) {
        ::operator delete(player_item_id_list);
        player_item_id_list = NULL;
    }
}

void TObjPlayer::create_cleanup_object(void *parent) {
    new TEquippedItemDrawTask((TObject *)parent);
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
    ((TObjPlayer *)player_item_id_list)->push_to_list(id);
}
