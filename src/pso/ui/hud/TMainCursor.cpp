#include "pso/system/SoundEffect.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/object/base/TObjChara.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/ui/hud/LockOnTask.h"
#include "pso/unk/TLOC_ListClear.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/TLOC_End.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLOC_Start.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerCommands.h"
#include "pso/render/render_util.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/object/TActorLight.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/camera/TCameraConversation.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/TextureState.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/map/FloorArea.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TForceOperate.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/map/CsnQuery.h"
#include "pso/math/ScratchVectors.h"
#define PSO_SDK_COMPACT_MATH
#include "pso/effect/TEffect.h"
#include "pso/item/item_pmt.h"
#include "pso/render/DebugFont.h"
#undef PSO_SDK_COMPACT_MATH


extern void *lock_on_list_clear_vtable[6];


extern const char *lockon_list_clear_task_name;


extern "C" {
extern const f32 cursor_float_zero;

extern const char *lock_on_start_task_name;
}



extern "C" void render__7TObjectFv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void run_task__14TLOC_ListClearFv();
const char *bm_ply_lock_on_cursor_model_names[4] = {
    "obj_f_maincarsol.nj", "obj_f_zakocarsol.nj", "obj_f_blackcarsol.nj", NULL,
};
const char *bm_ply_lock_on_cursor_motion_names[1] = {NULL};
BmlResourceDescriptor target_cursor_resource_descriptor = {
    "bm_ply_lock_on_cursor.bml", bm_ply_lock_on_cursor_model_names, bm_ply_lock_on_cursor_motion_names, 3, 0,
};
const char *lock_on_cursor_class_name = "TLockOnCursor";
const char *main_cursor_class_name = "TMainCursor";
const char *lock_on_start_task_name = "TLOC_Start";
const char *lock_on_end_task_name = "TLOC_End";
const char *lockon_list_clear_task_name = "TLOC_ListClear";
u8 cursor_action_priority_table[20] = {
    3, 8, 11, 5, 10, 13, 4, 9, 12, 7, 21, 22, 19, 20, 0, 16, 17, 14, 6, 0,
};
NJS_ARGB target_cursor_color_table[6] = {
    {1.0f, 0.0f, 0.78f, 0.0f},
    {1.0f, 0.0f, 0.78f, 0.0f},
    {1.0f, 0.7f, 0.7f, 0.7f},
    {1.0f, 1.0f, 0.0f, 0.0f},
    {1.0f, 0.0f, 0.39f, 0.0f},
    {1.0f, 0.0f, 0.0f, 0.0f},
};
void *lock_on_list_clear_vtable[6] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__14TLOC_ListClearFv, (void *)&run_task__14TLOC_ListClearFv,
    (void *)&render__7TObjectFv, (void *)&render_shadows__7TObjectFv,
};


struct TLockOnCursor;


extern "C" {
extern f32 scratch_vec5[3];
#define APPLY_TECH_RANGE(t)                                          \
    cur->cone_apex_offset = (t)->apex_offset;                                           \
    cur->lock_range = (t)->reach + cur->cone_apex_offset;                                \
    cur->horizontal_cone_angle = (t)->horizontal_angle;                                          \
    cur->horizontal_cone_cos = cos_table_lookup(cur->horizontal_cone_angle);              \
    cur->vertical_cone_angle = (t)->vertical_angle;                                          \
    cur->vertical_cone_cos = cos_table_lookup(cur->vertical_cone_angle);

}


BmlResource *lock_on_cursor_bml_resource;
NJS_OBJECT *lock_on_cursor_model;
NJS_OBJECT *TLockOnCursor::target_cursor_model;

NJS_OBJECT *main_cursor_model;
void reset_target_part_entry(LockOnTargetPart *);

extern const f32 lock_on_max_target_dist;


// TMainCursor and TLockOnCursor are one translation unit: their vtables and the lock-on tasks' sit
// together in .data in reverse key-function order. Deferred code generation is switched on and off
// across the file; each deferred stretch is written last to first.
#pragma defer_codegen off

void TLOC_ListClear::run_task() {
    if (m_target.resolve() != 0 && m_target.get_player()->lock_on_cursor != NULL) {
        set_action_channel_inactive(&m_target.get_player()->lock_on_cursor->palette_override);
    }
}

TLOC_ListClear *__dt__14TLOC_ListClearFv(TLOC_ListClear *task, s16 flags) {
    if (task != NULL) {
        *(void ***)((u8 *)task + 0x18) = lock_on_list_clear_vtable;
        if (task->m_target.resolve() != 0 && task->m_target.get_player()->lock_on_cursor != NULL) {
            task->m_target.get_player()->lock_on_cursor->set_list_clear_task(NULL);
        }
        __dt__10LockOnTaskFv(task, 0);
        if (flags > 0) {
            TObject::operator delete(task);
        }
    }
    return task;
}

void *TLOC_ListClear::init_lockon(TObject *parent, u16 id) {
    __ct__10LockOnTaskFP7TObjectUs(this, parent, id);
    *(void ***)((s8 *)this + 0x18) = lock_on_list_clear_vtable;
    m_name = lockon_list_clear_task_name;
    return this;
}

void TLOC_End::run_task() {
    s32 i;
    if (m_target.resolve() == 0) {
        return;
    }
    if (m_target.get_player()->lock_on_cursor == NULL) {
        return;
    }
    for (i = 0; i < 4; i++) {
        m_target.get_player()->lock_on_cursor->sort_list(i);
        m_target.get_player()->lock_on_cursor->publish_target_list(i);
    }
    m_target.get_player()->lock_on_cursor->nearest_target.publish();
    for (i = 0; i < 4; i++) {
        m_target.get_player()->lock_on_cursor->action_slots[i].reset_target_list();
    }
}

#pragma defer_codegen on

TLockOnCursor::TLockOnCursor(TObject *parent, u16 target_id) : TObject(parent) {
    m_name = lock_on_cursor_class_name;
    set_target_id(target_id);
    flags.reset();
}

ActionPriorityList::~ActionPriorityList() {}

TLockOnCursor::~TLockOnCursor() {
    TObject *task;
    task = get_start_task();
    if (task != NULL) {
        delete task;
    }
    task = get_end_task();
    if (task != NULL) {
        delete task;
    }
    task = get_list_clear_task();
    if (task != NULL) {
        delete task;
    }
}

void load_target_cursor_models(void) {
    BmlResource *resource;
    if (lock_on_cursor_bml_resource == NULL) {
        resource = new BmlResource(5, &target_cursor_resource_descriptor, 0, 0, NULL);
        lock_on_cursor_bml_resource = resource;
        if (resource != NULL) {
            lock_on_cursor_model = get_bml_model(resource, 0);
            TLockOnCursor::target_cursor_model = get_bml_model(lock_on_cursor_bml_resource, 0);
            main_cursor_model = get_bml_model(lock_on_cursor_bml_resource, 2);
        }
    }
}

void TLockOnCursor::free_cursor_resources() {
    if (lock_on_cursor_bml_resource != NULL) {
        delete lock_on_cursor_bml_resource;
        lock_on_cursor_bml_resource = NULL;
    }
    lock_on_cursor_model = NULL;
    TLockOnCursor::target_cursor_model = NULL;
}

void TLockOnCursor::reset_and_spawn_cursors() {
    TLOC_ListClear *list_clear;
    s32 i;
    flags.reset();
    for (i = 0; i < 4; i++) {
        action_slots[i].reset_state();
    }
    selection.reset_state();
    reset_target_part_entry(&target_part);
    nearest_target.reset();
    if (get_start_task() == NULL) {
        set_start_task(new TLOC_Start(tl_loc_start, get_target_id()));
    }
    if (get_end_task() == NULL) {
        set_end_task(new TLOC_End(tl_loc_end, get_target_id()));
    }
    if (get_list_clear_task() == NULL) {
        list_clear = (TLOC_ListClear *)TObject::operator new(sizeof(TLOC_ListClear));
        if (list_clear != NULL) {
            list_clear = (TLOC_ListClear *)list_clear->init_lockon(tl_window, get_target_id());
        }
        set_list_clear_task(list_clear);
    }
}

void TLockOnCursor::run_task() {
    if (is_channel_active(&palette_override) != 0) {
        palette_override.set_active();
        return;
    }
    palette_override.clear_active();
}

#pragma push
#pragma opt_loop_invariants off

void TLockOnCursor::render() {
    s32 i;
    s32 j;
    LockOnActionSlot *c;
    s32 n;
    LockOnTargetRecord *p;
    CollisionBody *body;
    TObjCollidable *o;
    if (is_split_screen() != 0) {
        if (TCameraCtrl::get_camera_no() != TCameraCtrl::get_split_screen_view_index(get_target_id())) {
            return;
        }
    } else if ((s32)main_task.get_task_flags() & 0x10) {
        return;
    }
    for (i = 0; i < 4; i++) {
        c = get_action_slot(i);
        if (c->get_selected_entry() != 0) {
            n = c->target_records.get_count();
            for (p = c->target_records.get_record(0), j = 0; j < n; j++, p++) {
                if (p->is_primary() == 0 &&
                    p->is_excluded() == 0 &&
                    p->get_entity_id() != 0xFFFF) {
                    o = find_entity_by_id(p->id);
                    if (o != NULL) {
                        body = &o->bodies[p->flag];
                        if (body != NULL) {
                            renderSecondaryCursor(body, (s32)(get_cursor_palette_mode(c)), (s32)(c->get_active()));
                        }
                    }
                }
            }
        }
    }
}
#pragma pop

void TLockOnCursor::renderSecondaryCursor(CollisionBody *body, s16 type, s32 action) {
    f32 offset[3];
    f32 y;
    s32 color_index;
    TObjPlayer *player;
    if (is_inactive() != 0) {
        player = get_player_by_client_id(get_target_id());
        if (player != NULL) {
            color_index = TMainCursor::check_visible(&player->action_palettes.m_smth, player, type, action);
            if (color_index != -1) {
                set_texture_list(&shared_effect_texture_list);
                y = body->radius;
                push_matrix();
                offset_point_toward_camera(&body->center, (Vec *)&offset, y);
                translate_matrix_vec3((u8 *)(0), (u8 *)&offset);
                rotate_matrix_y(0, camera_ctrl_instance->yaw);
                begin_effect_render();
                push_matrix();
                translate_matrix(0, cursor_float_zero, y, cursor_float_zero);
                save_model_draw_state(&marker);
                begin_constant_color_draw(&marker, &target_cursor_color_table[5]);
                draw_chunk_object(TMainCursor::get_cursor_model());
                begin_constant_color_draw(&marker, &target_cursor_color_table[color_index]);
                draw_chunk_object(get_target_cursor_model());
                restore_model_draw_state(&marker);
                pop_matrix();
                end_effect_render();
                pop_matrix();
            }
        }
    }
}

void TLockOnCursor::publish_target_list(s32 slot) {
    s32 count;
    s32 i;
    LockOnActionSlot *sub;
    TargetCursorRecord *item;
    s32 n;
    TObjCollidable *ent;
    CollisionBody *part;
    s32 mode;
    LockOnTargetRecord *cur;
    CursorTarget *list;
    sub = &action_slots[slot];
    count = 0;
    item = sub->target_list.get_record(0);
    n = sub->target_list.get_count();
    for (i = 0; i < n; i++, item++) {
        if (item->id == 0xFFFF) {
            continue;
        }
        ent = find_entity_by_id(item->id);
        if (ent == NULL) {
            continue;
        }
        part = &ent->bodies[item->flag];
        if (part == NULL) {
            continue;
        }
        if (count >= sub->get_max_targets()) {
            break;
        }
        mode = 0;
        if (target_part.actor_id != 0xFFFF) {
            if (target_part.actor_id == item->id && target_part.collider == item->flag) {
                if (selection.target.get_entity_id() == 0xFFFF) {
                    mode = 2;
                } else {
                    mode = 1;
                }
            } else if (sub->get_max_targets() > 1) {
                mode = 1;
            }
        } else if (selection.target.get_entity_id() == 0xFFFF) {
            mode = 2;
        } else {
            mode = 1;
        }
        if (mode == 0) {
            continue;
        }
        if (get_cursor_palette_mode(sub) == 1) {
            if (mode == 1) {
                continue;
            }
            set_cursor_slot(sub, (u8)ent->get_cursor_action());
        }
        cur = sub->target_records.get_record(count);
        cur->set_id(item->id);
        cur->set_value(item->value);
        cur->set_flag(item->flag);
        cur->clear_excluded();
        if (is_inactive() == 0 || ent->test_body_flag(item->flag, get_target_id()) != 0 || (part->flags & 0x08000000)) {
            cur->set_excluded();
        }
        if (mode == 1) {
            cur->clear_primary();
        } else {
            cur->set_primary();
            if (ent->test_body_flag(item->flag, get_target_id()) == 0) {
                list = selection.get_target();
                list->set_entity_id(item->id);
                set_cursor_palette_mode(&list->palette_tag, get_cursor_palette_mode(sub));
                set_cursor_palette_slot(&list->palette_tag, sub->get_active());
                list->set_target_id(item->flag);
                if (selection.is_cursor_on_target() == 0 && cur->is_excluded() == 0) {
                    TMainCursor *cursor = new TMainCursor((TObject *)tl_loc_end, item->id, item->flag, (s32)get_cursor_palette_mode(sub), (s32)sub->get_active(), get_target_id(), part->radius);
                    if (cursor != NULL) {
                        cursor->refresh_target_marker();
                    }
                }
            }
        }
        part->flags |= 0x10000000;
        ent->set_body_flag(item->flag, get_target_id());
        count++;
    }
    sub->target_records.set_count(count);
    sub->target_records.get_record(count)->set_id(0xFFFF);
}

void TLockOnCursor::sort_list(s32 index) {
    LockOnActionSlot *slot = &action_slots[index];
    if (slot->get_selected_entry() != 0) {
        slot->quick_sort(slot->target_list.get_record(0), 0, slot->target_list.get_count() - 1);
    }
}

#pragma push
#pragma fp_contract on

void TLockOnCursor::setup_action_channel(TObjPlayer *player, s32 slot, s16 kind, s16 id) {
    LockOnActionSlot *cur;
    TechniqueCursorParams *tech;
    WeaponRangeRecord *wpn;
    if (player == NULL) {
        return;
    }
    cur = &action_slots[slot];
    if (check_type_and_enabled(&cur->palette_tag, kind, id) == 0) {
        clear_target_cursor_list(&cur->target_list);
        cur->target_records.clear();
    }
    set_cursor_mode(cur, kind);
    set_cursor_slot(cur, id);
    switch (kind) {
    case 1:
        if (((TObjChara *)player)->obj_isState3_324() == 0) {
            activate_action_channel(cur);
            cur->set_body_include_mask(0x20000);
            cur->set_body_exclude_mask(0x8000);
            cur->set_actor_include_mask(0xC0000000);
            cur->set_actor_exclude_mask(0x30040800);
            cur->set_max_targets(1);
            VecCopy(&cur->origin, &player->body_center);
            cur->cone_apex_offset = cursor_float_zero;
            cur->lock_range = 15.0f;
            cur->horizontal_cone_angle = 0x8000;
            cur->vertical_cone_angle = 0x8000;
            cur->horizontal_cone_cos = cos_table_lookup(cur->horizontal_cone_angle);
            cur->vertical_cone_cos = cos_table_lookup(cur->vertical_cone_angle);
        }
        break;
    case 4:
        switch (id) {
        case 10:
            tech = (TechniqueCursorParams *)calc_technique_parameters(0xF, 0xE, player->get_entity_id());
            activate_action_channel(cur);
            APPLY_TECH_RANGE(tech)
            cur->set_max_targets(tech->cursor_type);
            VecCopy(&cur->origin, &player->body_center);
            set_display_flags(player, cur);
            break;
        case 9:
            tech = (TechniqueCursorParams *)calc_technique_parameters(0x11, 0xE, player->get_entity_id());
            activate_action_channel(cur);
            APPLY_TECH_RANGE(tech)
            cur->set_max_targets(tech->cursor_type);
            VecCopy(&cur->origin, &player->body_center);
            setup_flags(player, cur);
            break;
        }
        break;
    case 2:
        wpn = get_weapon_range_record(TObjPlayer::get_equipped_weapon(player), id);
        activate_action_channel(cur);
        set_cursor_color(player, cur);
        cur->set_body_exclude_mask(0);
        cur->set_actor_exclude_mask(0x40800);
        VecCopy(&cur->origin, &player->body_center);
        cur->cone_apex_offset = wpn->apex_offset;
        cur->lock_range = wpn->reach + cur->cone_apex_offset;
        cur->horizontal_cone_angle = wpn->horizontal_angle;
        cur->vertical_cone_angle = wpn->vertical_angle;
        cur->horizontal_cone_cos = cos_table_lookup(cur->horizontal_cone_angle);
        cur->vertical_cone_cos = cos_table_lookup(cur->vertical_cone_angle);
        cur->set_max_targets(wpn->max_targets);
        break;
    case 3: {
        u16 client = player->get_entity_id();
        s32 lvl = player->technique_state.get_cast_technique_level(id);
        s32 technique = id;
        tech = (TechniqueCursorParams *)calc_technique_parameters(technique, lvl, client);
        activate_action_channel(cur);
        APPLY_TECH_RANGE(tech)
        cur->set_max_targets(tech->cursor_type);
        switch (technique) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 18:
            set_cursor_color(player, cur);
            cur->set_body_exclude_mask(0);
            cur->set_actor_exclude_mask(0x40800);
            VecCopy(&cur->origin, &player->body_center);
            break;
        case 14:
            cur->set_body_include_mask(0x8000);
            cur->set_body_exclude_mask(0);
            cur->set_actor_include_mask(0x60000000);
            cur->set_actor_exclude_mask(0x40800);
            scratch_vec5[0] = 50.0f * sin_table_lookup(player->rotation.y) + player->body_center.x;
            scratch_vec5[1] = player->body_center.y;
            scratch_vec5[2] = 50.0f * cos_table_lookup(player->rotation.y) + player->body_center.z;
            VecCopy(&cur->origin, (const Vec *)scratch_vec5);
            break;
        case 10:
        case 13:
        case 15:
        case 16:
            VecCopy(&cur->origin, &player->body_center);
            set_display_flags(player, cur);
            break;
        case 11:
        case 12:
            if (player->pk_state.is_enabled() != 0) {
                cur->set_body_include_mask(0xA000);
                cur->set_actor_include_mask(0x30000000);
            } else {
                cur->set_body_include_mask(0x8000);
                cur->set_actor_include_mask(0x20000000);
            }
            cur->set_body_exclude_mask(0x30000);
            cur->set_actor_exclude_mask(0xC0040800);
            VecCopy(&cur->origin, &player->body_center);
            break;
        case 17:
            VecCopy(&cur->origin, &player->body_center);
            setup_flags(player, cur);
            break;
        }
        break;
    }
    case 5: {
        s32 blast = id;
        tech = (TechniqueCursorParams *)get_photon_blast_entry(blast);
        activate_action_channel(cur);
        if (player->pk_state.is_enabled() == 0) {
            cur->set_body_include_mask(0x8000);
            cur->set_actor_include_mask(0x20000000);
        } else {
            cur->set_body_include_mask(0xA000);
            cur->set_actor_include_mask(0x30000000);
        }
        cur->set_body_exclude_mask(0);
        cur->set_actor_exclude_mask(0xD0040800);
        APPLY_TECH_RANGE(tech)
        switch (blast) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            VecCopy(&cur->origin, &player->body_center);
            cur->set_max_targets(0xA);
            break;
        }
        break;
    }
    }
}
#pragma pop

void TLockOnCursor::setup_flags(TObjPlayer *player, LockOnActionSlot *main_cursor) {
    main_cursor->set_body_include_mask(0x2000);
    main_cursor->set_body_exclude_mask(0x3C000);
    main_cursor->set_actor_include_mask(0x800);
    main_cursor->set_actor_exclude_mask(0xE0000000);
}

void TLockOnCursor::set_display_flags(TObjPlayer *player, LockOnActionSlot *main_cursor) {
    main_cursor->set_body_include_mask(0x2000);
    main_cursor->set_actor_include_mask(0x10000000);
    main_cursor->set_actor_exclude_mask(0xE0000800);
    if (is_technique_ready() == 0) {
        main_cursor->set_body_exclude_mask(0x30000);
        return;
    }
    if (player->get_pk_team() == 1) {
        main_cursor->set_body_exclude_mask(0x40030000);
        return;
    }
    main_cursor->set_body_exclude_mask(0x40030000);
}

void TLockOnCursor::set_cursor_color(TObjPlayer *player, LockOnActionSlot *main_cursor) {
    if (player->pk_state.is_enabled() != 0) {
        main_cursor->set_body_include_mask(0xA000);
        main_cursor->set_actor_include_mask(0x70000000);
        return;
    }
    main_cursor->set_body_include_mask(0x8000);
    main_cursor->set_actor_include_mask(0x60000000);
}

s32 TLockOnCursor::get_action_cursor_priority(TObjPlayer *player, s32 index) {
    s32 kind;
    s32 sub;
    kind = get_action_palette_mode(player, index);
    sub = player->get_action_palette_entry(index);
    switch (kind) {
    case 1:
        if (TObjPlayer::is_effect_channel_active(player, 0) != 0) {
            return 1;
        }
        break;
    case 2:
        if (player->check_mode_action(sub) != 0) {
            return 2;
        }
        break;
    case 3:
        if (player->try_camera_action(sub) != 0) {
            return cursor_action_priority_table[sub];
        }
        break;
    case 4:
        if (TObjPlayer::is_effect_channel_active(player, index) != 0 && is_current_area_item_enabled() != 0 && player->test_action_mask(0x43001E) != 0 && (sub == 0xA || sub == 9)) {
            return 0xF;
        }
        break;
    case 5:
        return (s8)(sub + 3);
    default:
        return 0;
    }
    return 0;
}

void TLockOnCursor::set_cursor_pos(u16 part, s32 index) {
    u32 eq = (u32) __cntlzw((u32) ((u16) selection.target.get_entity_id() - part)) >> 5;
    set_target_part(&target_part, part, index, eq + 1);
}

void TLockOnCursor::bind_action_channels() {
    s32 i;
    TObjPlayer *player;
    u8 type;
    s32 slot;
    s32 count;
    u8 enabled;
    ActionPriorityEntry *entry;

    if (is_cursor_clear() == 0) {
        return;
    }
    if (TCameraCtrl::get_mode() != 0) {
        return;
    }
    player = get_player_by_client_id(get_target_id());
    if (player == NULL) {
        return;
    }
    if (player->is_controls_locked() != 0 && is_channel_active(&palette_override) != 0) {
        type = get_action_palette_tag_mode(&palette_override);
        enabled = get_action_palette_tag_slot(&palette_override);
        if (is_current_area_item_enabled() == 0) {
            if (TObjPlayer::is_key_machine_ready() == 0) {
                return;
            }
            if (type != 4) {
                return;
            }
            if (enabled != 10) {
                return;
            }
        }
        setup_action_channel(player, 0, type, enabled);
        return;
    }
    count = action_list.get_count();
    entry = action_list.get_entries();
    for (i = 0; i < count; i++) {
        entry->set_priority((s8)get_action_cursor_priority(player, i));
        entry->set_index(i);
        entry++;
    }
    action_list.sort_actions_by_priority();
    entry = action_list.get_entries();
    slot = 0;
    for (i = 0; i < count; i++) {
        if (entry->get_priority() != 0) {
            setup_action_channel(player, slot, get_action_palette_mode(player, entry->get_index()), player->get_action_palette_entry(entry->get_index()));
            slot++;
        }
        entry++;
    }
}

LockOnActionSlot *TLockOnCursor::find_by_pos(s16 mode, s16 kind) {
    s32 i;
    LockOnActionSlot *slot;

    i = 0;
    slot = action_slots;
    do {
        if ((mode == (s32) get_cursor_palette_mode(slot)) && (kind == (s32) slot->get_active()) && (slot->get_selected_entry() != 0)) {
            return slot;
        }
        i += 1;
        slot += 1;
    } while (i < 4);
    return NULL;
}

void TLockOnCursor::init_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        init_slot(i);
    }
}

void TLockOnCursor::reset_slots() {
    s32 i;
    LockOnActionSlot *slot;

    slot = action_slots;
    i = 0;
    do {
        clear_target_cursor_list(&slot->target_list);
        slot->target_records.clear();
        i += 1;
        slot++;
    } while (i < 4);
}

void LockOnActionSlot::quick_sort(TargetCursorRecord *records, s32 lo, s32 hi) {
    s32 mid;

    if (lo < hi) {
        mid = quick_sort_partition(records, lo, hi);
        quick_sort(records, lo, mid - 1);
        quick_sort(records, mid + 1, hi);
    }
}

s32 LockOnActionSlot::quick_sort_partition(TargetCursorRecord *a, s32 lo, s32 hi) {
    TargetCursorRecord tmp;
    f32 pivot;
    s32 i;
    s32 j;

    j = hi;
    i = lo - 1;
    pivot = a[hi].value;
    for (;;) {
        while (a[++i].value < pivot) {
        }
        while (i < --j && pivot < a[j].value) {
        }
        if (i >= j) {
            break;
        }
        store_sorted_record(&a[i], &tmp);
        store_sorted_record(&a[j], &a[i]);
        store_sorted_record(&tmp, &a[j]);
    }
    store_sorted_record(&a[i], &tmp);
    store_sorted_record(&a[hi], &a[i]);
    store_sorted_record(&tmp, &a[hi]);
    return i;
}

void LockOnActionSlot::reset_target_list() {
    s32 i;

    target_list.set_count(0);
    i = 0;
    max_candidate_dist = cursor_float_zero;
    do {
        target_list.get_record(i)->set_value(cursor_float_zero);
        target_list.get_record(i)->set_id(0xFFFF);
        i += 1;
    } while (i < 0xA);
}

s32 TMainCursor::try_add_target_candidate(LockOnActionSlot *entry, TObjCollidable *candidate, TObjPlayer *owner, LockOnNearestTarget *best) {
    f32 dist;
    s32 slot;
    s32 found;
    s32 i;
    CollisionBody *c;
    s32 yaw;
    s32 stat;
    s32 j;
    slot = 0;
    found = 0;
    if (owner == NULL) {
        return 0;
    }
    if ((u16)owner->get_entity_id() == (u16)candidate->get_entity_id()) {
        return 0;
    }
    if (is_technique_ready() == 0) {
        if (owner->get_room() != (stat = candidate->get_room()) && (candidate->actorFlags & 0x60000000) == 0x20000000 && stat != -1) {
            return 0;
        }
    }
    if (owner->test_actor_flags(0xA00) != 0) {
        return 0;
    }
    if (candidate == NULL || candidate->all_parents_unqueued_for_destruction() == 0) {
        return 0;
    }
    if (candidate->test_actor_flags(entry->get_actor_include_mask()) == 0 ||
        candidate->test_actor_flags(entry->get_actor_exclude_mask()) != 0) {
        return 0;
    }
    yaw = owner->rotation.y;
    for (i = 0; i < candidate->body_count; i++) {
        c = &candidate->bodies[i];
        if (c == NULL) {
            continue;
        }
        c->flags &= ~0x10000000;
        candidate->clear_body_flag(i, owner->get_entity_id());
        if (!(c->flags & 1)) {
            continue;
        }
        if (!(c->flags & entry->get_body_include_mask())) {
            continue;
        }
        if (c->flags & entry->get_body_exclude_mask()) {
            continue;
        }
        dist = horizontal_distance_squared(&entry->origin, &c->center);
        if (!(c->flags & 0x22000) && best->candidate_target_dist > dist) {
            best->candidate_target_dist = dist;
            best->candidate_target_id = candidate->get_entity_id();
            best->candidate_part_index = i;
        }
        {
            f32 r = entry->lock_range + c->radius;
            if (dist > r * r) {
                continue;
            }
        }
        if (is_technique_ready() != 0 && (c->flags & 0xA000) &&
            is_target_obstructed(entry, &c->center, &owner->bodies->center) != NULL) {
            continue;
        }
        if (target_in_xz_cone(&entry->origin, &c->center, &owner->position, yaw,
                              entry->horizontal_cone_cos, entry->cone_apex_offset) == 0) {
            continue;
        }
        if (target_in_vertical_cone(&entry->origin, &c->center, yaw, entry->vertical_cone_cos,
                                      entry->cone_apex_offset) == 0) {
            continue;
        }
        if (entry->max_candidate_dist < dist) {
            entry->max_candidate_dist = dist;
        }
        if (entry->target_list.get_count() >= 10) {
            for (j = 0; j <= entry->target_list.get_count(); j++) {
                if (entry->max_candidate_dist == entry->target_list.get_record(j)->get_value()) {
                    entry->max_candidate_dist = dist;
                    slot = j;
                    break;
                }
            }
        } else {
            slot = entry->target_list.get_count();
            entry->target_list.increment_count();
        }
        entry->target_list.get_record(slot)->set_value(dist);
        entry->target_list.get_record(slot)->set_flag(i);
        entry->target_list.get_record(slot)->set_id(candidate->get_entity_id());
        found = 1;
    }
    return found;
}


CsnHit *is_target_obstructed(LockOnActionSlot *unused, const Vec *to, const Vec *from) {
    return csnVector(from, to, 0x28A0);
}


#pragma push
#pragma fp_contract on


s32 target_in_xz_cone(Vec *p, Vec *q, Vec *r, s32 yaw, f32 range, f32 dist) {
    Vec a;
    Vec b;
    f32 x;
    f32 z;
    if (-1.0f < range && range < 1.0f) {
        a.x = sin_table_lookup(yaw);
        a.y = cursor_float_zero;
        a.z = cos_table_lookup(yaw);
        if (cursor_float_zero == dist) {
            b.x = q->x - p->x;
            b.y = cursor_float_zero;
            b.z = q->z - p->z;
            normalize_vector_safe(&b);
            if (vec3_dot(&a, &b) < range) {
                return 0;
            }
        } else {
            x = dist * sin_table_lookup(yaw + 0x8000) + p->x;
            z = dist * cos_table_lookup(yaw + 0x8000) + p->z;
            b.x = q->x - x;
            b.y = cursor_float_zero;
            b.z = q->z - z;
            normalize_vector_safe(&b);
            if (vec3_dot(&a, &b) < range) {
                return 0;
            }
            scratch_vec.x = q->x - r->x;
            scratch_vec.y = cursor_float_zero;
            scratch_vec.z = q->z - r->z;
            normalize_vector_safe(&scratch_vec);
            if (vec3_dot(&a, &scratch_vec) < cursor_float_zero) {
                return 0;
            }
        }
    }
    return 1;
}

s32 target_in_vertical_cone(Vec *p, Vec *q, s32 yaw, f32 range, f32 dist) {
    Vec a;
    Vec b;
    f32 x;
    f32 y;
    f32 z;
    if (-1.0f < range && range < 1.0f) {
        if (cursor_float_zero == dist) {
            a.x = q->x - p->x;
            a.y = cursor_float_zero;
            a.z = q->z - p->z;
            b.x = a.x;
            b.y = q->y - p->y;
            b.z = a.z;
            normalize_vector_safe(&a);
            normalize_vector_safe(&b);
            if (vec3_dot(&a, &b) < range) {
                return 0;
            }
        } else {
            x = dist * sin_table_lookup(yaw + 0x8000) + p->x;
            y = p->y;
            z = dist * cos_table_lookup(yaw + 0x8000) + p->z;
            a.x = q->x - x;
            a.y = cursor_float_zero;
            a.z = q->z - z;
            b.x = a.x;
            b.y = q->y - y;
            b.z = a.z;
            normalize_vector_safe(&a);
            normalize_vector_safe(&b);
            if (vec3_dot(&a, &b) < range) {
                return 0;
            }
        }
    }
    return 1;
}

#pragma pop


s32 is_active_channel_matching(LockOnActionSlot *slot, u8 type, u8 enabled) {
    if (is_channel_active(&slot->palette_tag) != 0) {
        return matches_type_and_enabled(&slot->palette_tag, type, enabled);
    }
    return 0;
}


int check_type_and_enabled(const ActionPaletteTag *tag, u8 type, u8 enabled) { return matches_type_and_enabled(tag, type, enabled); }

TMainCursor::TMainCursor(TObject *parent, u16 entity_id, s32 target_id, s32 action_palette, s32 active,
                         u16 client_id, f32 size)
    : TObject(parent) {
    m_name = main_cursor_class_name;
    set_entity_id(entity_id);
    set_target_id(target_id);
    set_size(size);
    set_cursor_action_palette_mode(this, action_palette);
    set_palette_slot(active);
    set_client_id(client_id);
}

TMainCursor::~TMainCursor() {}

void TMainCursor::refresh_target_marker() {
    TObjPlayer *player;
    s32 color_index;
    player = get_owner_player();
    if (player == NULL) {
        queue_destruction();
        return;
    }
    color_index = TMainCursor::check_visible(&player->action_palettes.m_smth, player, get_palette_mode(), (u8) this->get_palette_slot());
    if (color_index == -1) {
        queue_destruction();
        return;
    }
    this->phase = 0;
    rest_height = 3.75f;
    min_height = rest_height - 1.0f;
    start_height = 5.0f + rest_height;
    height = start_height;
    this->m_3c = 0.5f;
    this->update_position();
    if (check_can_pickup() != 0) {
        this->check_flag_4();
    }
    if (this->update() != 0) {
        marker.set_color(&target_cursor_color_table[4]);
        return;
    }
    marker.set_color(&target_cursor_color_table[color_index]);
}

void TMainCursor::update_position() {
    TObjCollidable *entity;

    entity = find_entity_by_id(target.get_entity_id());
    if (entity != NULL) {
        CollisionBody *body = &entity->bodies[is_position_moved()];
        VecCopy(&position, &body->center);
    }
}

void TMainCursor::run_task() {
    if ((s32) this->phase != 2) {
        validate_target();
        if (check_flag_1() != 0) {
            this->phase = 2;
        }
    }
    switch (this->phase) {
    case 0:
        height = (f32) (height - 1.0f);
        if (!(height > min_height)) {
            height = (f32) rest_height;
            this->phase = 1;
            if (init_render_flags() == 0) {
                if (update() != 0) {
                    play_sound_effect(0x3816, &position, 0, 1);
                    return;
                }
                play_sound_effect(0x3111, &position, 0, 1);
            }
        }
    case 1:
        return;
    case 2: {
        f32 distance = marker.get_alpha() - 0.2f;
        if (distance > cursor_float_zero) {
            marker.set_alpha(distance);
            return;
        }
        queue_destruction();
        break;
    }
    }
}

void TMainCursor::render() {
    s32 cam;
    s32 no;
    if (init_render_flags() != 0) {
        return;
    }
    switch (is_hidden()) {
    case 0:
        break;
    default:
        return;
    }
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_split_screen_view_index(get_client_id());
        no = TCameraCtrl::get_camera_no();
        if (no != cam) {
            return;
        }
    } else if ((s32)main_task.get_task_flags() & 0x10) {
        return;
    }
    switch (this->phase) {
    case 0:
    case 1:
        update_position();
        break;
    case 2:
        break;
    default:
        return;
    }
    set_texture_list(&shared_effect_texture_list);
    render_marker(this);
}

#pragma push
#pragma opt_common_subs off

void TMainCursor::validate_target() {
    TObjPlayer *t;
    state_flags.clear(0xB);
    t = get_owner_player();
    if (t == NULL) {
        this->update_target_sub();
        return;
    }
    if (t->lock_on_cursor == NULL) {
        this->update_target_sub();
        return;
    }
    if (target.is_same_target(t->lock_on_cursor->selection.get_target()) == 0) {
        this->update_target_sub();
        return;
    }
    if (get_target_palette_mode(&target.palette_tag) != 1) {
        if (TMainCursor::check_visible(&t->action_palettes.m_smth, t, get_target_palette_mode(&target.palette_tag),
                                            get_target_palette_slot(&target.palette_tag)) == -1) {
            t->lock_on_cursor->selection.target.set_entity_id(0xFFFF);
            this->update_target_sub();
            return;
        }
    }
    if (is_any_teammate_in_state() != 0) {
        hide();
        return;
    }
    switch (get_target_palette_mode(&target.palette_tag)) {
    case 0:
        this->update_target_sub();
        return;
    case 1:
        return;
    case 2:
        if (t->can_perform_physical_action() == 0) {
            this->update_target_sub();
            return;
        }
        return;
    case 3:
        if (TObjPlayer::is_invalid_slot(t->technique_state.get_cast_technique_level(get_target_palette_slot(&target.palette_tag))) != 0) {
            this->update_target_sub();
            return;
        }
        if (t->is_controls_locked() == 0 && t->test_actor_flags(0x20006) != 0) {
            this->update_target_sub();
            return;
        }
        if (t->test_action_mask(0x548000) != 0) {
            this->update_target_sub();
            return;
        }
        if (is_current_area_item_enabled() == 0) {
            this->update_target_sub();
            return;
        }
        if (t->tp - (calc_technique_parameters(get_target_palette_slot(&target.palette_tag),
                                                      t->technique_state.get_cast_technique_level(get_target_palette_slot(&target.palette_tag)),
                                                      t->get_entity_id()))->tp_cost < 0) {
            this->update_target_sub();
            return;
        }
        return;
    case 4:
        return;
    case 5:
        if ((s8)t->photon_blast_gauge.get_blast_level(get_target_palette_slot(&target.palette_tag)) != (s8)get_empty_action_entry()) {
            this->update_target_sub();
            return;
        }
        if (t->test_action_mask(0x548000) != 0) {
            this->update_target_sub();
            return;
        }
        if (is_current_area_item_enabled() == 0) {
            this->update_target_sub();
        }
        return;
    case 6:
    case 7:
        return;
    }
}
#pragma pop

s32 TMainCursor::check_can_pickup() {
    saddr entity;
    TObjPlayer *player;

    entity = (saddr)find_entity_by_id(target.get_entity_id());
    if ((entity != 0) && ((u32) (((TObjCollidable *)entity)->test_actor_flags(0x80000000) + 0x80000000) == 0U) && ((player = get_owner_player()) != NULL) && (player->can_pickup_item_by_id((TItem *)entity) == 0)) {
        return 1;
    }
    return 0;
}


void render_marker(TMainCursor *main_cursor) {
    s32 offset;
    f32 y;

    begin_effect_render();
    y = main_cursor->height;
    push_matrix();
    offset_point_toward_camera(&main_cursor->position, (Vec *)&offset, main_cursor->size);
    translate_matrix_vec3((u8 *)(0), (u8 *)&offset);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    push_matrix();
    rotate_matrix_z(0, 0x2AAA);
    translate_matrix(0, cursor_float_zero, y, cursor_float_zero);
    main_cursor->update_photon_chair();
    main_cursor->update_chair();
    pop_matrix();
    push_matrix();
    rotate_matrix_z(0, 0x7FFF);
    translate_matrix(0, cursor_float_zero, y, cursor_float_zero);
    main_cursor->update_photon_chair();
    main_cursor->update_chair();
    pop_matrix();
    push_matrix();
    rotate_matrix_z(0, 0xD554);
    translate_matrix(0, cursor_float_zero, y, cursor_float_zero);
    main_cursor->update_photon_chair();
    main_cursor->update_chair();
    pop_matrix();
    pop_matrix();
    end_effect_render();
}


void TMainCursor::update_chair() {
    save_model_draw_state(&marker);
    begin_constant_color_draw_self((NJS_ARGB *)&marker);
    draw_chunk_object(get_lock_on_cursor_model());
    restore_model_draw_state(&marker);
}

void TMainCursor::update_photon_chair() {
    if (marker.get_alpha() > 0.99999f) {
        save_model_draw_state(&marker);
        begin_constant_color_draw_argb(&marker, 1.0f, cursor_float_zero, cursor_float_zero, cursor_float_zero);
        draw_chunk_object(TMainCursor::get_cursor_model());
        restore_model_draw_state(&marker);
    }
}


s32 canSetMenuCursorAction(LockOnPaletteOverride *cursor, TObjPlayer *player, u8 kind, u8 parameter) {
    if (is_channel_active(cursor) != 0) {
        return 0;
    }
    switch ((s32) kind) {
    case 4:
        switch (parameter) {
        case 9: case 10: return 1;
        default: return 0;
        }
    case 3:
        return player->can_start_technique(parameter);
    default:
        return 0;
    }
}


void LockOnActionSlot::reset_state() {
    origin.z = cursor_float_zero;
    origin.y = cursor_float_zero;
    origin.x = cursor_float_zero;
    lock_range = cursor_float_zero;
    horizontal_cone_cos = cursor_float_zero;
    vertical_cone_cos = cursor_float_zero;
    horizontal_cone_angle = 0;
    vertical_cone_angle = 0;
    cone_apex_offset = cursor_float_zero;
    max_candidate_dist = cursor_float_zero;
    set_max_targets(0);
    clear_target_cursor_list(&target_list);
    target_records.clear();
}

void copy_action_entry(ActionPriorityEntry *dst, ActionPriorityEntry *src) {
    dst->priority = src->priority;
    dst->index = src->index;
}

s32 ActionPriorityList::sort_actions_by_priority() {
    s32 k;
    s32 n;
    s32 i;
    ActionPriorityEntry *p;
    ActionPriorityEntry *q;
    ActionPriorityEntry tmp;
    if (get_entries() == NULL) {
        return 0;
    }
    n = get_count();
    while (--n > 0) {
        p = get_entries();
        for (i = 0; i < n; p++, i++) {
            q = p + 1;
            k = q->get_priority();
            if (p->get_priority() > k) {
                copy_action_entry(&tmp, p);
                copy_action_entry(p, q);
                copy_action_entry(q, &tmp);
            }
        }
    }
    return 1;
}

TObjPlayer *CursorOwner::get_player() { return get_player_by_client_id(client_id); }

TLOC_Start::TLOC_Start(TObject *parent, u16 id) : LockOnTask(parent, id) { m_name = lock_on_start_task_name; }

TLOC_Start::~TLOC_Start() {
    if ((m_target.resolve() != 0) && (m_target.get_player()->lock_on_cursor != NULL)) {
        m_target.get_player()->lock_on_cursor->set_start_task(NULL);
    }
}

void TLOC_Start::run_task() {
    TObjPlayer *pl;
    TLockOnCursor *cur;
    s32 i;
    pl = get_player_by_client_id((s32)(m_target.get_client_id()));
    if (pl == NULL) {
        return;
    }
    cur = pl->lock_on_cursor;
    if (cur == NULL) {
        return;
    }
    cur->nearest_target.reset();
    cur->selection.update_cursor_pos();
    cur->selection.target.set_entity_id(0xFFFF);
    cur->init_slots();
    cur->bind_action_channels();
    if (get_main_phase() == 0xF) {
        for (i = 0; i < 12; i++) {
            TObjPlayer *p = player_slot_table[i];
            if (p != NULL && p->is_body_collision_inactive() == 0) {
                submit_cursor_candidate(p, -1);
            }
        }
    } else {
        submit_cursor_candidate(pl, -1);
    }
}

TLOC_End::TLOC_End(TObject *parent, u16 id) : LockOnTask(parent, id) { m_name = lock_on_end_task_name; }

TLOC_End::~TLOC_End() {
    if ((m_target.resolve() != 0) && (m_target.get_player()->lock_on_cursor != NULL)) {
        m_target.get_player()->lock_on_cursor->set_end_task(NULL);
    }
}

#pragma defer_codegen off


void set_action_channel_inactive(gc_tag *tag) { *(s16 *)&tag->tag2 |= 1; }


s32 is_channel_active(const gc_tag *tag) {
    return (u8)((u8) ((*(const s16 *)((const s8 *)tag + 2) & 1) ^ 1));
}

s32 TMainCursor::check_visible(TPlyDispConfigSmth *palette, TObjPlayer *player, s16 type, s32 enabled) {
    return palette->find_action_slot_for_target(player, type, enabled);
}

u8 get_action_palette_tag_slot(const ActionPaletteTag *tag) { return tag->tag1; }

u8 get_action_palette_tag_mode(const ActionPaletteTag *tag) { return tag->tag0; }

void set_action_palette_tag_slot(ActionPaletteTag *tag, u8 slot) { tag->tag1 = slot; }

void set_action_palette_tag_mode(ActionPaletteTag *tag, u8 mode) { tag->tag0 = mode; }

int matches_type_and_enabled(const ActionPaletteTag *tag, u8 type, u8 enabled) {
    s32 matched;
    matched = 0;
    if ((type == get_action_palette_tag_mode(tag)) && (enabled == get_action_palette_tag_slot(tag))) {
        matched = 1;
    }
    return (u8)matched;
}


void set_action_channel_active(gc_tag *tag) { *(s16 *)&tag->tag2 &= ~1; }


TObjPlayer *PlayerRef::get_player() { return player; }

PlayerRef::~PlayerRef() {}

void PlayerRef::set_client_id(u16 id) { client_id = id; }

PlayerRef::PlayerRef() {
    client_id = reserved = 0xffff;
    player = 0;
}

u16 PlayerRef::get_client_id() { return client_id; }

LockOnTask::~LockOnTask() {}

void TLockOnCursor::set_list_clear_task(TObject *task) { tasks.set_list_clear_task(task); }

void LockOnTasks::set_list_clear_task(TObject *task) { list_clear_task = task; }

LockOnTask::LockOnTask(TObject *parent, u16 id) : TObject(parent) {
    disallow_rendering();
    m_target.set_client_id(id);
}

void LockOnNearestTarget::publish() {
    set_published_target_id(get_candidate_target_id());
    set_published_target_dist(get_candidate_target_dist());
}

void LockOnNearestTarget::set_published_target_dist(f32 dist) { published_target_dist = dist; }

f32 LockOnNearestTarget::get_candidate_target_dist() { return candidate_target_dist; }

void LockOnNearestTarget::set_published_target_id(u16 id) { published_target_id = id; }

u16 LockOnNearestTarget::get_candidate_target_id() { return candidate_target_id; }

void TLockOnCursor::set_end_task(TObject *task) { tasks.set_end_task(task); }

void LockOnTasks::set_end_task(TObject *task) { end_task = task; }

void CursorTarget::set_entity_id(u16 id) { entity_id = id; }

void LockOnSelection::update_cursor_pos() { cursor_target.copy_from(&target); }

CursorTarget *CursorTarget::copy_from(CursorTarget *src) {
    copy_gc_tag(&palette_tag, &src->palette_tag);
    entity_id = src->entity_id;
    target_id = src->target_id;
    return this;
}

void LockOnNearestTarget::reset() {
    candidate_part_index = 0;
    published_target_id = 0xffff;
    candidate_target_id = 0xffff;
    published_target_dist = cursor_float_zero;
    candidate_target_dist = lock_on_max_target_dist;
}

void TLockOnCursor::set_start_task(TObject *task) { tasks.set_start_task(task); }

void LockOnTasks::set_start_task(TObject *task) { start_task = task; }


s16 ActionPriorityEntry::get_priority() { return priority; }

s32 ActionListBase::get_count() { return count; }


ActionPriorityEntry *ActionListBase::get_entries() { return entries; }

ActionPriorityEntry::ActionPriorityEntry() { index = 0; priority = 0; }

void LockOnTargetRecordList::clear() { count = 0; }

void LockOnActionSlot::set_max_targets(s32 v) { max_targets = v; }

NJS_OBJECT *TMainCursor::get_cursor_model() { return main_cursor_model; }


NJS_OBJECT *get_lock_on_cursor_model(void) { return lock_on_cursor_model; }


TObjPlayer *TMainCursor::get_owner_player() { return owner.get_player(); }

u16 CursorTarget::get_entity_id() { return entity_id; }


void TMainCursor::hide() { state_flags.set(2); }

u8 get_target_palette_slot(ActionPaletteTag *p) { return get_action_palette_tag_slot(p); }

u8 get_target_palette_mode(ActionPaletteTag *p) { return get_action_palette_tag_mode(p); }


int CursorTarget::is_same_target(CursorTarget *other) {
    u8 result = 0;
    if (matches_id(other->get_entity_id()) != 0) {
        if (get_action_palette_tag_mode(&palette_tag) == get_action_palette_tag_mode(&other->palette_tag)) {
            if (get_action_palette_tag_slot(&palette_tag) == get_action_palette_tag_slot(&other->palette_tag)) {
                result = 1;
            }
        }
    }
    return result;
}

int CursorTarget::matches_id(u16 id) {
    return (u8) (id == get_entity_id());
}

CursorTarget *LockOnSelection::get_target() { return &target; }

void TMainCursor::update_target_sub() { state_flags.set(1); }

u16 TMainCursor::get_client_id() { return owner.get_client_id(); }

u16 CursorOwner::get_client_id() { return client_id; }

int TMainCursor::is_hidden() { return state_flags.test_flags_any(2); }

int TMainCursor::init_render_flags() { return state_flags.test_flags_any(8); }

int TMainCursor::update() { return state_flags.test_flags_any(4); }

int TMainCursor::check_flag_1() { return state_flags.test_flags_any(1); }

u8 TMainCursor::is_position_moved() { return (u8)(target.get_target_id()); }


s16 CursorTarget::get_target_id() { return target_id; }


void TMainCursor::check_flag_4() { state_flags.set(4); }

u8 TMainCursor::get_palette_slot() { return get_target_palette_slot(&target.palette_tag); }

u8 TMainCursor::get_palette_mode() { return get_target_palette_mode(&target.palette_tag); }

CursorOwner::~CursorOwner() {}

CursorTarget::~CursorTarget() {}

void TMainCursor::set_client_id(u16 id) { owner.set_client_id(id); }

void CursorOwner::set_client_id(u16 id) { client_id = id; }

void TMainCursor::set_palette_slot(u8 slot) { set_cursor_palette_slot(&target.palette_tag, slot); }

void set_cursor_palette_slot(ActionPaletteTag *tag, u8 slot) { set_action_palette_tag_slot(tag, slot); }

void set_cursor_action_palette_mode(TMainCursor *cursor, u8 mode) { set_cursor_palette_mode(&cursor->target.palette_tag, mode); }

void set_cursor_palette_mode(ActionPaletteTag *tag, u8 mode) { set_action_palette_tag_mode(tag, mode); }

void TMainCursor::set_size(f32 v) { this->size = v; }

void TMainCursor::set_target_id(u8 target_id) {
    target.set_target_id(target_id);
}

void CursorTarget::set_target_id(s16 id) { target_id = id; }

void TMainCursor::set_entity_id(u16 id) { target.set_entity_id(id); }

CursorTarget::CursorTarget() {
    reset_target();
}

void CursorTarget::reset_target() {
    palette_tag.init();
    set_entity_id(0xFFFF);
    set_target_id(0);
}

CursorOwner::CursorOwner() {
    client_id = 0xffff;
}

s32 LockOnActionSlot::get_body_exclude_mask() { return body_exclude_mask; }

s32 LockOnActionSlot::get_body_include_mask() { return body_include_mask; }

s32 LockOnActionSlot::get_actor_exclude_mask() { return actor_exclude_mask; }

s32 LockOnActionSlot::get_actor_include_mask() { return actor_include_mask; }

void LockOnActionSlot::store_sorted_record(TargetCursorRecord *src, TargetCursorRecord *dst) { dst->copy_from(src); }

void TargetCursorRecord::copy_from(TargetCursorRecord *src) {
    id = src->id;
    flag = src->flag;
    value = src->value;
}

void TLockOnCursor::init_slot(s32 i) {
    deactivate_action_channel(&action_slots[i]);
}

void deactivate_action_channel(LockOnActionSlot *slot) { set_action_channel_inactive(&slot->palette_tag); }

int LockOnActionSlot::get_selected_entry() { return is_channel_active(&palette_tag); }

u8 LockOnActionSlot::get_active() { return get_action_palette_tag_slot(&palette_tag); }

u8 get_cursor_palette_mode(LockOnActionSlot *slot) { return get_action_palette_tag_mode(&slot->palette_tag); }

s16 ActionPriorityEntry::get_index() { return index; }

void ActionPriorityEntry::set_index(s16 v) { index = v; }

void ActionPriorityEntry::set_priority(s16 v) { priority = v; }

u16 TLockOnCursor::get_target_id() { return target_id; }

int TLockOnCursor::is_cursor_clear() { return (flags.test_flags_any(1)) == 0; }

void set_target_part(LockOnTargetPart *target, u16 part, s32 index, s32 flag) {
    target->actor_id = part;
    target->collider = index;
    target->unk_4 = flag;
}

void LockOnActionSlot::set_actor_include_mask(s32 v) { actor_include_mask = v; }

void LockOnActionSlot::set_body_include_mask(s32 v) { body_include_mask = v; }

void LockOnActionSlot::set_body_exclude_mask(s32 v) { body_exclude_mask = v; }

void LockOnActionSlot::set_actor_exclude_mask(s32 v) { actor_exclude_mask = v; }

void activate_action_channel(LockOnActionSlot *slot) { set_action_channel_active(&slot->palette_tag); }

void set_cursor_slot(LockOnActionSlot *slot, u8 v) { set_action_palette_tag_slot(&slot->palette_tag, v); }

void set_cursor_mode(LockOnActionSlot *slot, u8 v) { set_action_palette_tag_mode(&slot->palette_tag, v); }

void LockOnTargetRecordList::set_count(s32 count) { this->count = count; }

int LockOnTargetRecord::is_excluded() { return flags.test_flags_any(2); }

int LockOnSelection::is_cursor_on_target() { return target.is_same_target(&cursor_target); }

void LockOnTargetRecord::set_primary() { flags.set(1); }

void LockOnTargetRecord::clear_primary() { flags.clear(1); }

void LockOnTargetRecord::set_excluded() { flags.set(2); }

int TLockOnCursor::is_inactive() { return (this->flags.test_flags_any(2)) == 0; }

void LockOnTargetRecord::clear_excluded() { flags.clear(2); }

s32 LockOnActionSlot::get_max_targets() { return max_targets; }


NJS_OBJECT *get_target_cursor_model(void) { return TLockOnCursor::target_cursor_model; }


int LockOnTargetRecord::is_primary() { return flags.test_flags_any(1); }

s32 LockOnTargetRecordList::get_count() { return count; }

LockOnActionSlot *TLockOnCursor::get_action_slot(s32 i) {
    return &action_slots[i];
}

void LockOnPaletteOverride::clear_active() { active = 0; }

void LockOnPaletteOverride::set_active() { active = 1; }

TObject *TLockOnCursor::get_list_clear_task() { return tasks.get_list_clear_task(); }

TObject *LockOnTasks::get_list_clear_task() { return list_clear_task; }

TObject *TLockOnCursor::get_end_task() { return tasks.get_end_task(); }

TObject *LockOnTasks::get_end_task() { return end_task; }

TObject *TLockOnCursor::get_start_task() { return tasks.get_start_task(); }

TObject *LockOnTasks::get_start_task() { return start_task; }

void reset_target_part_entry(LockOnTargetPart *entry) {
    entry->actor_id = 0xffff;
    entry->collider = 0;
    entry->unk_4 = 0;
}

void LockOnSelection::reset_state() {
    target.reset_target();
    cursor_target.reset_target();
    unk_8.init();
    unk_0 = 0xffff;
    unk_2 = 0;
    unk_4 = cursor_float_zero;
}

ActionListBase::~ActionListBase() {}

LockOnTasks::~LockOnTasks() {}

LockOnActionSlot::~LockOnActionSlot() {}

LockOnTargetRecordList::~LockOnTargetRecordList() {}

LockOnTargetRecord::~LockOnTargetRecord() {}

LockOnSelection::~LockOnSelection() {}

#pragma defer_codegen on

MarkerColor::~MarkerColor() {}

void MarkerColor::set_color(NJS_ARGB *src) { copy_argb(&color, src); }

void MarkerColor::set_alpha(f32 alpha) { color.a = alpha; }

f32 MarkerColor::get_alpha() { return color.a; }

void TargetCursorList::set_count(s32 count) { this->count = count; }

s32 TargetCursorList::get_count() { return count; }

TargetCursorRecord *TargetCursorList::get_record(int index) { return &records[index]; }

f32 TargetCursorRecord::get_value() { return value; }

void TargetCursorList::increment_count() { count += 1; }

void TargetCursorRecord::set_value(f32 value) { this->value = value; }

void TargetCursorRecord::set_flag(s16 flag) { this->flag = flag; }

void TargetCursorRecord::set_id(u16 id) { this->id = id; }

ActionListBase::ActionListBase() { count = 0; entries = NULL; }


void ActionListBase::set_count(s32 v) { count = v; }

void ActionListBase::set_entries(s32 v) { *(s32 *)&entries = v; }


ActionPriorityList::ActionPriorityList() {
    set_count(4);
    set_entries((saddr)slots);
}

LockOnTasks::LockOnTasks() { start_task = NULL; end_task = NULL; list_clear_task = NULL; }

LockOnTargetRecord::LockOnTargetRecord() {}

LockOnTargetRecordList::LockOnTargetRecordList() { clear(); }

LockOnActionSlot::LockOnActionSlot() { reset_state(); }

LockOnSelection::LockOnSelection() { reset_state(); }

LockOnTargetPart::LockOnTargetPart() { reset_target_part_entry(this); }

LockOnNearestTarget::LockOnNearestTarget() { reset(); }

LockOnPaletteOverride::LockOnPaletteOverride() {
    active = 0;
}

void TLockOnCursor::set_target_id(u16 target_id) { this->target_id = target_id; }

LockOnPaletteOverride::~LockOnPaletteOverride() {}

#pragma defer_codegen off

MarkerColor::MarkerColor() {
    clear_marker_color(this);
}


void clear_marker_color(MarkerColor *marker) {
    marker->color.b = cursor_float_zero;
    marker->color.g = cursor_float_zero;
    marker->color.r = cursor_float_zero;
    marker->color.a = cursor_float_zero;
}

int get_empty_action_entry(void) { return -1; }

u8 PhotonBlastGauge::get_blast_level(s16 blast) {
    return blast_levels[blast];
}


int TCameraCtrl::get_mode() {  return fixed_npc_camera_active; }
