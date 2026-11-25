#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/object/base/TObjChara.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/unk/TUnk_804A7260.h"
#include "pso/unk/TLOC_ListClear.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/TLOC_End.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLOC_Start.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/charcreate/PaletteCursorAction.h"
#include "pso/render/render_util.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/unk/text_8023601C.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/ui/hud/TMainCursor_8013B524.h"
#include "pso/ui/hud/TMainCursor_8013E1C8.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/hud/TMainCursor_8013B690.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/camera/TCameraConversation.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/hud/TMainCursor_8013F104.h"
#include "pso/system/vector.h"
#include "pso/ui/hud/TMainCursor_8013BEB8.h"
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
#include "pso/ui/hud/TMainCursor_8013DEF8.h"
#include "pso/player/TForceOperate.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/hud/TMainCursor_8013DF5C.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/ui/hud/TMainCursor_8013E2E4.h"
#include "pso/ui/hud/TMainCursor_8013E47C.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/hud/TMainCursor_8013E624.h"
#include "pso/ui/hud/TMainCursor_8013E7B8.h"
#include "pso/ui/hud/TLockOnCursor_8013EA08.h"
#include "pso/ui/hud/TLockOnCursor_8013EB80.h"
#include "pso/unk/text_80072004.h"
#include "pso/ui/hud/TLockOnCursor_8013EE00.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/hud/TMainCursor_80154090.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/map/CsnQuery.h"
#include "pso/math/ScratchVectors.h"
#define PSO_SDK_COMPACT_MATH
#include "pso/effect/TEffect.h"
#undef PSO_SDK_COMPACT_MATH


extern void *lbl_804A71C4[6];


extern const char *lockon_list_clear_task_name;

struct Pl_8013B0F0 {
    u8 pad[0x424];
    TLockOnCursor *cur;
};

extern Pl_8013B0F0 *player_slot_table[12];


struct Ent_8013B2C8 { s32 w; };

extern "C" {
extern const f32 TMainCursor__data_805DB0C0;

extern const char *TLOC_Start__name;
}

extern "C" {

void draw_chunk_object(void);

struct VOff_8013B524_arg0_8013B524 { char pad_0[0x4C]; char f_4C[1]; };

s32 rotate_matrix_y(s32, s32);

u8 get_cast_technique_level(void *, s32);
s16 TObjPlayer__sub_801B5AF8(TObjPlayer *player, s32 index);
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
const char *TLOC_Start__name = "TLOC_Start";
const char *TLOC_End__name = "TLOC_End";
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
void *lbl_804A71C4[6] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__14TLOC_ListClearFv, (void *)&run_task__14TLOC_ListClearFv,
    (void *)&render__7TObjectFv, (void *)&render_shadows__7TObjectFv,
};


extern "C" {
f32 vec3_dot(void *, void *);
}

struct ActionCursor_8013C924 {
    u8 pad0[0x24];
    TMainCursor actions;
    u8 pad8C[0x520 - 0x24 - sizeof(TMainCursor)];
    ActionPaletteTag channel;
};

struct TLockOnCursor;

struct Cursor_8013CDE4 {
    u8 pad0[0x1C];
    f32 pos[3];
    f32 f28;
    f32 f2c;
    f32 f30;
    s32 f34;
    s32 f38;
    f32 f3c;
    TargetCursorList f40;
    LockOnTargetRecordList f9c;
};

struct Main_8013CDE4 { u8 pad0[0x5C]; Cursor_8013CDE4 cursors[4]; };

struct Tech_8013CDE4 { u8 pad0[8]; f32 f8; f32 fc; u8 pad10[0x18 - 0x10]; s32 f18; s32 f1c; u8 pad20[2]; s8 f22; };

struct Weapon_8013CDE4 { f32 f0; f32 f4; s32 f8; s32 fc; s32 f10; };

extern "C" {
Weapon_8013CDE4 *get_weapon_range_record(void *, s32);
extern f32 scratch_vec5[3];
#define C_8013CDE4 ((saddr)cur)
#define TECH_8013CDE4(t)                                          \
    cur->f3c = (t)->fc;                                           \
    cur->f28 = (t)->f8 + cur->f3c;                                \
    cur->f34 = (t)->f18;                                          \
    cur->f2c = cos_table_lookup(cur->f34);              \
    cur->f38 = (t)->f1c;                                          \
    cur->f30 = cos_table_lookup(cur->f38);

}

struct Obj_8013EC1C { u16 a; u16 b; u16 c; };


u8 * lock_on_cursor_bml_resource;
s32 lock_on_cursor_model;
s32 TLockOnCursor::target_cursor_model;

NJS_OBJECT *main_cursor_model;
extern "C" {
void TLockOnCursor__sub_8013EC1C(void *);

}

extern const f32 lbl_805DB0C4;


struct Rec_8013E870 { u8 pad[0x124]; };

struct Obj_8013E870 { u8 pad[0x5c]; Rec_8013E870 recs[1]; };


struct Obj_8013F24C { u8 pad[0x44]; u8 arr[1]; };

extern "C" {
u8 fn_8013F24C(Obj_8013F24C *self, s16 i);

}

// TMainCursor and TLockOnCursor are one translation unit: their vtables and the lock-on tasks' sit
// together in .data in reverse key-function order. Deferred code generation is switched on and off
// across the file; each deferred stretch is written last to first.
#pragma defer_codegen off

void TLOC_ListClear::run_task() {
    if (m_target.resolve() != 0 && m_target.get_player()->lock_on_cursor != NULL) {
        TObjPlayer__sub_8013DEF8((u8 *)&m_target.get_player()->lock_on_cursor->palette_override);
    }
}

TLOC_ListClear *__dt__14TLOC_ListClearFv(TLOC_ListClear *task, s16 flags) {
    if (task != NULL) {
        *(void ***)((u8 *)task + 0x18) = lbl_804A71C4;
        if (task->m_target.resolve() != 0 && task->m_target.get_player()->lock_on_cursor != NULL) {
            task->m_target.get_player()->lock_on_cursor->set_list_clear_task(NULL);
        }
        __dt__13TUnk_804A7260Fv(task, 0);
        if (flags > 0) {
            TObject::operator delete(task);
        }
    }
    return task;
}

void *TLOC_ListClear::init_lockon(TObject *parent, u16 id) {
    __ct__13TUnk_804A7260FP7TObjectUs(this, parent, id);
    *(void ***)((s8 *)this + 0x18) = lbl_804A71C4;
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
    sub_8013EEC0(target_id);
    flags.reset();
}

TUnk_8013F0A0::~TUnk_8013F0A0() {}

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
    saddr resource;
    if ((void *) lock_on_cursor_bml_resource == NULL) {
        resource = (saddr)new BmlResource(5, (BmlResourceDescriptor *)&target_cursor_resource_descriptor, 0, 0, NULL);
        lock_on_cursor_bml_resource = (unsigned char *) ((void *) resource);
        if ((u32) resource != 0U) {
            lock_on_cursor_model = (saddr)get_bml_model((BmlResource *)(void *) resource, 0);
            TLockOnCursor::target_cursor_model = (saddr)get_bml_model((BmlResource *)lock_on_cursor_bml_resource, 0);
            main_cursor_model = get_bml_model((BmlResource *)lock_on_cursor_bml_resource, 2);
        }
    }
}

void TLockOnCursor::free_cursor_resources() {
    if ((void *) lock_on_cursor_bml_resource != NULL) {
        delete (BmlResource *)lock_on_cursor_bml_resource;
        lock_on_cursor_bml_resource = NULL;
    }
    lock_on_cursor_model = 0;
    TLockOnCursor::target_cursor_model = 0;
}

void TLockOnCursor::reset_and_spawn_cursors() {
    TLOC_ListClear *list_clear;
    s32 i;
    flags.reset();
    for (i = 0; i < 4; i++) {
        action_slots[i].reset_state();
    }
    selection.reset_state();
    TLockOnCursor__sub_8013EC1C(&target_part);
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
    saddr arg0 = (saddr)this;
    if (((TMainCursor *)(arg0 + 0x520))->is_channel_active() != 0) {
        TLockOnCursor__sub_8013EB8C((void *)(arg0 + 0x520));
        return;
    }
    TLockOnCursor__sub_8013EB80((void *)(arg0 + 0x520));
}

#pragma push
#pragma opt_loop_invariants off

void TLockOnCursor::render() {
    s32 i;
    s32 j;
    u8 *c;
    s32 n;
    LockOnTargetRecord *p;
    saddr e;
    u8 *o;
    if (is_split_screen() != 0) {
        if (TCameraCtrl::get_camera_no() != TCameraCtrl::get_split_screen_view_index(get_target_id())) {
            return;
        }
    } else if ((s32)main_task.get_task_flags() & 0x10) {
        return;
    }
    for (i = 0; i < 4; i++) {
        c = (u8 *)get_action_slot(i);
        if (((TMainCursor *)c)->get_selected_entry() != 0) {
            n = ((LockOnTargetRecordList *)(c + 0x9C))->get_count();
            for (p = ((LockOnActionSlot *)c)->target_records.get_record(0), j = 0; j < n; j++, p++) {
                if (p->is_primary() == 0 &&
                    p->is_excluded() == 0 &&
                    p->get_entity_id() != 0xFFFF) {
                    o = (u8 *)find_entity_by_id(p->id);
                    if (o != NULL) {
                        e = *(s32 *)(o + 0xA4) + p->flag * 0x2C;
                        if (e != 0) {
                            renderSecondaryCursor((u8*)e, (s32)(get_cursor_palette_mode((void *)c)), (s32)(((TMainCursor *)c)->get_active()));
                        }
                    }
                }
            }
        }
    }
}
#pragma pop

void TLockOnCursor::renderSecondaryCursor(u8 *body, s16 type, s32 action) {
    const saddr arg0 = (saddr)this;
    f32 sp8[3];
    f32 y;
    s32 temp_r3_2;
    TObjPlayer *player;
    if (is_inactive() != 0) {
        player = get_player_by_client_id(get_target_id());
        if (player != NULL) {
            temp_r3_2 = TMainCursor::check_visible(&player->action_palettes.m_smth, player, type, action);
            if (temp_r3_2 != -1) {
                TObjFish::set_global_param(&shared_effect_texture_list);
                y = *(f32 *)((s8 *)body + 0xC);
                push_matrix();
                offset_point_toward_camera((Vec *)(body + 0x1C), (Vec *)&sp8, (f32)y);
                translate_matrix_vec3((u8 *)(0), (u8 *)&sp8);
                rotate_matrix_y(0, camera_ctrl_instance->yaw);
                TParticleCtrl::begin_effect_render();
                push_matrix();
                translate_matrix(0, TMainCursor__data_805DB0C0, y, TMainCursor__data_805DB0C0);
                save_model_draw_state((void *)(arg0 + 0x48));
                begin_constant_color_draw((void *)(arg0 + 0x48), &target_cursor_color_table[5]);
                TMainCursor::get_cursor_model();
                draw_chunk_object();
                begin_constant_color_draw((void *)(arg0 + 0x48), &target_cursor_color_table[temp_r3_2]);
                TLockOnCursor__sub_8013EB34();
                draw_chunk_object();
                restore_model_draw_state((void *)(arg0 + 0x48));
                pop_matrix();
                TParticleCtrl::end_effect_render();
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
        if (is_inactive() == 0 || ((TMainCursor *)ent)->test_button(item->flag, get_target_id()) != 0 || (part->flags & 0x08000000)) {
            cur->set_excluded();
        }
        if (mode == 1) {
            cur->clear_primary();
        } else {
            cur->set_primary();
            if (((TMainCursor *)ent)->test_button(item->flag, get_target_id()) == 0) {
                list = selection.get_target();
                list->set_entity_id(item->id);
                set_cursor_palette_mode(&list->palette_tag, get_cursor_palette_mode(sub));
                set_cursor_palette_slot(&list->palette_tag, ((TMainCursor *)sub)->get_active());
                list->set_target_id(item->flag);
                if (selection.is_cursor_on_target() == 0 && cur->is_excluded() == 0) {
                    TMainCursor *cursor = new TMainCursor((TObject *)tl_loc_end, item->id, item->flag, (s32)get_cursor_palette_mode(sub), (s32)((TMainCursor *)sub)->get_active(), get_target_id(), part->radius);
                    if (cursor != NULL) {
                        cursor->refresh_target_marker();
                    }
                }
            }
        }
        part->flags |= 0x10000000;
        TMainCursor__sub_80154230(ent, item->flag, get_target_id());
        count++;
    }
    sub->target_records.set_count(count);
    sub->target_records.get_record(count)->set_id(0xFFFF);
}

void TLockOnCursor::sort_list(s32 index) {
    LockOnActionSlot *slot = &action_slots[index];
    if (((TMainCursor *)slot)->get_selected_entry() != 0) {
        slot->quick_sort(slot->target_list.get_record(0), 0, slot->target_list.get_count() - 1);
    }
}

#pragma push
#pragma fp_contract on

void TMainCursor::setup_action_channel(u8 *player, s32 slot, s32 kind, s32 id) {
    Cursor_8013CDE4 *cur;
    Tech_8013CDE4 *tech;
    Weapon_8013CDE4 *wpn;
    s16 sid;
    if (player == NULL) {
        return;
    }
    cur = &((Main_8013CDE4 *)this)->cursors[slot];
    if (check_type_and_enabled(reinterpret_cast<const ActionPaletteTag *>(cur), kind, id) == 0) {
        clear_target_cursor_list(&cur->f40);
        cur->f9c.clear();
    }
    set_cursor_mode(cur, kind);
    set_cursor_slot(cur, id);
    switch ((s16)kind) {
    case 1:
        if (((TObjChara *)player)->obj_isState3_324() == 0) {
            TMainCursor__sub_8013E9A0(cur);
            ((TMainCursor *)C_8013CDE4)->set_color(0x20000);
            ((TMainCursor *)C_8013CDE4)->set_field_0c(0x8000);
            ((TMainCursor *)C_8013CDE4)->set_color_mode(0xC0000000);
            ((TMainCursor *)C_8013CDE4)->set_flags(0x30040800);
            ((TMainCursor *)cur)->set_type(1);
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            cur->f3c = TMainCursor__data_805DB0C0;
            cur->f28 = 15.0f;
            cur->f34 = 0x8000;
            cur->f38 = 0x8000;
            cur->f2c = cos_table_lookup(cur->f34);
            cur->f30 = cos_table_lookup(cur->f38);
        }
        break;
    case 4:
        switch ((s16)id) {
        case 10:
            tech = (Tech_8013CDE4 *)calc_technique_parameters(0xF, 0xE, ((TObjBase *)player)->get_entity_id());
            TMainCursor__sub_8013E9A0(cur);
            TECH_8013CDE4(tech)
            ((TMainCursor *)cur)->set_type(tech->f22);
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            TMainCursor::set_display_flags((saddr)this, (saddr)player, C_8013CDE4);
            break;
        case 9:
            tech = (Tech_8013CDE4 *)calc_technique_parameters(0x11, 0xE, ((TObjBase *)player)->get_entity_id());
            TMainCursor__sub_8013E9A0(cur);
            TECH_8013CDE4(tech)
            ((TMainCursor *)cur)->set_type(tech->f22);
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            TMainCursor::setup_flags((saddr)this, (saddr)player, C_8013CDE4);
            break;
        }
        break;
    case 2:
        wpn = get_weapon_range_record(TObjPlayer::get_equipped_weapon(player), id);
        TMainCursor__sub_8013E9A0(cur);
        TMainCursor::set_cursor_color((saddr)this, (saddr)player, C_8013CDE4);
        ((TMainCursor *)C_8013CDE4)->set_field_0c(0);
        ((TMainCursor *)C_8013CDE4)->set_flags(0x40800);
        VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
        cur->f3c = wpn->f4;
        cur->f28 = wpn->f0 + cur->f3c;
        cur->f34 = wpn->f8;
        cur->f38 = wpn->fc;
        cur->f2c = cos_table_lookup(cur->f34);
        cur->f30 = cos_table_lookup(cur->f38);
        ((TMainCursor *)cur)->set_type(wpn->f10);
        break;
    case 3: {
        u16 client = ((TObjBase *)player)->get_entity_id();
        s32 lvl = get_cast_technique_level(player + 0x428, id);
        sid = id;
        tech = (Tech_8013CDE4 *)calc_technique_parameters(sid, lvl, client);
        TMainCursor__sub_8013E9A0(cur);
        TECH_8013CDE4(tech)
        ((TMainCursor *)cur)->set_type(tech->f22);
        switch (sid) {
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
            TMainCursor::set_cursor_color((saddr)this, (saddr)player, C_8013CDE4);
            ((TMainCursor *)C_8013CDE4)->set_field_0c(0);
            ((TMainCursor *)C_8013CDE4)->set_flags(0x40800);
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            break;
        case 14:
            ((TMainCursor *)C_8013CDE4)->set_color(0x8000);
            ((TMainCursor *)C_8013CDE4)->set_field_0c(0);
            ((TMainCursor *)C_8013CDE4)->set_color_mode(0x60000000);
            ((TMainCursor *)C_8013CDE4)->set_flags(0x40800);
            scratch_vec5[0] = 50.0f * sin_table_lookup(*(s32 *)(player + 0x60)) + *(f32 *)(player + 0x2FC);
            scratch_vec5[1] = *(f32 *)(player + 0x300);
            scratch_vec5[2] = 50.0f * cos_table_lookup(*(s32 *)(player + 0x60)) + *(f32 *)(player + 0x304);
            VecCopy((Vec *)cur->pos, (const Vec *)scratch_vec5);
            break;
        case 10:
        case 13:
        case 15:
        case 16:
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            TMainCursor::set_display_flags((saddr)this, (saddr)player, C_8013CDE4);
            break;
        case 11:
        case 12:
            if (((TObjPlayer *)player)->pk_state.is_enabled() != 0) {
                ((TMainCursor *)C_8013CDE4)->set_color(0xA000);
                ((TMainCursor *)C_8013CDE4)->set_color_mode(0x30000000);
            } else {
                ((TMainCursor *)C_8013CDE4)->set_color(0x8000);
                ((TMainCursor *)C_8013CDE4)->set_color_mode(0x20000000);
            }
            ((TMainCursor *)C_8013CDE4)->set_field_0c(0x30000);
            ((TMainCursor *)C_8013CDE4)->set_flags(0xC0040800);
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            break;
        case 17:
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            TMainCursor::setup_flags((saddr)this, (saddr)player, C_8013CDE4);
            break;
        }
        break;
    }
    case 5: {
        s16 pid = id;
        tech = (Tech_8013CDE4 *)get_photon_blast_entry((s16)pid);
        TMainCursor__sub_8013E9A0(cur);
        if (((TObjPlayer *)player)->pk_state.is_enabled() == 0) {
            ((TMainCursor *)C_8013CDE4)->set_color(0x8000);
            ((TMainCursor *)C_8013CDE4)->set_color_mode(0x20000000);
        } else {
            ((TMainCursor *)C_8013CDE4)->set_color(0xA000);
            ((TMainCursor *)C_8013CDE4)->set_color_mode(0x30000000);
        }
        ((TMainCursor *)C_8013CDE4)->set_field_0c(0);
        ((TMainCursor *)C_8013CDE4)->set_flags(0xD0040800);
        TECH_8013CDE4(tech)
        switch (pid) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            ((TMainCursor *)cur)->set_type(0xA);
            break;
        }
        break;
    }
    }
}
#pragma pop

void TMainCursor::setup_flags(s32 arg0, s32 player, saddr main_cursor) {
    ((TMainCursor *)main_cursor)->set_color(0x2000);
    ((TMainCursor *)main_cursor)->set_field_0c(0x3C000);
    ((TMainCursor *)main_cursor)->set_color_mode(0x800);
    ((TMainCursor *)main_cursor)->set_flags(0xE0000000);
}

void TMainCursor::set_display_flags(s32 arg0, saddr player, saddr main_cursor) {
    ((TMainCursor *)main_cursor)->set_color(0x2000);
    ((TMainCursor *)main_cursor)->set_color_mode(0x10000000);
    ((TMainCursor *)main_cursor)->set_flags(0xE0000800);
    if (TTecCtrl::is_technique_ready() == 0) {
        ((TMainCursor *)main_cursor)->set_field_0c(0x30000);
        return;
    }
    if (((TObjPlayer *)player)->get_pk_team() == 1) {
        ((TMainCursor *)main_cursor)->set_field_0c(0x40030000);
        return;
    }
    ((TMainCursor *)main_cursor)->set_field_0c(0x40030000);
}

void TMainCursor::set_cursor_color(s32 arg0, saddr player, saddr main_cursor) {
    if (((TObjPlayer *)player)->pk_state.is_enabled() != 0) {
        ((TMainCursor *)main_cursor)->set_color(0xA000);
        ((TMainCursor *)main_cursor)->set_color_mode(0x70000000);
        return;
    }
    ((TMainCursor *)main_cursor)->set_color(0x8000);
    ((TMainCursor *)main_cursor)->set_color_mode(0x60000000);
}

s32 TMainCursor::get_action_cursor_priority(void *arg0, saddr player, s32 index) {
    u16 kind;
    s32 sub;
    kind = TObjPlayer__sub_801B5AF8((TObjPlayer *)player, index);
    sub = ((TObjPlayer *)player)->get_action_palette_entry(index);
    switch (kind) {
    case 1:
        if (TObjPlayer::is_effect_channel_active(player, 0) != 0) {
            return 1;
        }
        break;
    case 2:
        if (((TObjPlayer *)player)->check_mode_action(sub) != 0) {
            return 2;
        }
        break;
    case 3:
        if (((TObjPlayer *)player)->try_camera_action(sub) != 0) {
            return cursor_action_priority_table[sub];
        }
        break;
    case 4:
        if (TObjPlayer::is_effect_channel_active(player, index) != 0 && is_current_area_item_enabled() != 0 && ((TObjPlayer *)player)->test_action_mask(0x43001E) != 0 && (sub == 0xA || sub == 9)) {
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

void TMainCursor::set_cursor_pos(u16 arg1, s32 arg2) {
    saddr arg0 = (saddr)this;
    u32 eq = (u32) __cntlzw((u32) ((u16) ((CursorTarget *)(arg0 + 0x4F8))->get_entity_id() - (u16) arg1)) >> 5;
    set_target_part((u8 *)(arg0 + 0x508), arg1, arg2, eq + 1);
}

void TMainCursor::bind_action_channels() {
    ActionCursor_8013C924 *self = (ActionCursor_8013C924 *)this;
    s32 i;
    saddr player;
    u8 type;
    s32 slot;
    s32 count;
    u8 enabled;
    u8 *entry;

    if (is_cursor_clear() == 0) {
        return;
    }
    if (TCameraCtrl::get_mode() != 0) {
        return;
    }
    player = (saddr)get_player_by_client_id(((TLockOnCursor *)this)->get_target_id());
    if (player == 0) {
        return;
    }
    if (((TObjPlayer *)player)->is_controls_locked() != 0 && ((TMainCursor *)(&self->channel))->is_channel_active() != 0) {
        type = get_action_palette_tag_mode(&self->channel);
        enabled = get_action_palette_tag_slot(&self->channel);
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
        setup_action_channel((u8 *)player, 0, type, enabled);
        return;
    }
    count = TMainCursor__sub_8013E2A0(&self->actions);
    entry = (u8 *)self->actions.get_index();
    for (i = 0; i < count; i++) {
        set_action_entry_priority(entry, (s8)get_action_cursor_priority(this, player, i));
        set_action_entry_index(entry, i);
        entry += 4;
    }
    self->actions.sort_actions_by_priority();
    entry = (u8 *)self->actions.get_index();
    slot = 0;
    for (i = 0; i < count; i++) {
        if (TMainCursor__sub_8013E298(entry) != 0) {
            setup_action_channel((u8 *)player, slot, TObjPlayer__sub_801B5AF8((TObjPlayer *)player, get_action_entry_index(entry)), (s16)((TObjPlayer *)player)->get_action_palette_entry(get_action_entry_index(entry)));
            slot++;
        }
        entry += 4;
    }
}

LockOnActionSlot *TLockOnCursor::find_by_pos(s16 mode, s16 kind) {
    s32 i;
    LockOnActionSlot *slot;

    i = 0;
    slot = action_slots;
loop_1:
    if ((mode == (s32) get_cursor_palette_mode(slot)) && (kind == (s32) ((TMainCursor *)slot)->get_active()) && (((TMainCursor *)slot)->get_selected_entry() != 0)) {
        return slot;
    }
    i += 1;
    slot += 1;
    if (i >= 4) {
        return NULL;
    }
    goto loop_1;
}

void TMainCursor::init_slots() { { saddr i; for (i = 0; i < 4; i++) { init_slot((saddr)((void*)i)); } } }

void TMainCursor::reset_slots() {
    s32 arg0 = (saddr)this;
    s32 i;
    saddr base;

    base = arg0 + 0x5C;
    i = 0;
    do {
        clear_target_cursor_list(&((LockOnActionSlot *)base)->target_list);
        ((LockOnActionSlot *)base)->target_records.clear();
        i += 1;
        base += 0x124;
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
    max_candidate_dist = TMainCursor__data_805DB0C0;
    do {
        target_list.get_record(i)->set_value(TMainCursor__data_805DB0C0);
        target_list.get_record(i)->set_id(0xFFFF);
        i += 1;
    } while (i < 0xA);
}

s32 TMainCursor::try_add_target_candidate(LockOnActionSlot *entry, void *candidate, TObjPlayer *owner, LockOnNearestTarget *best) {
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
    if ((u16)owner->get_entity_id() == (u16)((TObjBase *)candidate)->get_entity_id()) {
        return 0;
    }
    if (TTecCtrl::is_technique_ready() == 0) {
        if (owner->get_room() != (stat = ((TObjBase *)candidate)->get_room()) && (((TObjBase *)candidate)->actorFlags & 0x60000000) == 0x20000000 && stat != -1) {
            return 0;
        }
    }
    if (owner->test_actor_flags(0xA00) != 0) {
        return 0;
    }
    if (candidate == NULL || ((TObject *)candidate)->all_parents_unqueued_for_destruction() == 0) {
        return 0;
    }
    if (((TObjCollidable *)candidate)->test_actor_flags(entry->get_actor_include_mask()) == 0 ||
        ((TObjCollidable *)candidate)->test_actor_flags(entry->get_actor_exclude_mask()) != 0) {
        return 0;
    }
    yaw = owner->rotation_y;
    for (i = 0; i < ((TObjCollidable *)candidate)->body_count; i++) {
        c = &((TObjCollidable *)candidate)->bodies[i];
        if (c == NULL) {
            continue;
        }
        c->flags &= ~0x10000000;
        ((TMainCursor *)candidate)->set_flag_bit(i, owner->get_entity_id());
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
            best->candidate_target_id = ((TObjBase *)candidate)->get_entity_id();
            best->candidate_part_index = i;
        }
        {
            f32 r = entry->lock_range + c->radius;
            if (dist > r * r) {
                continue;
            }
        }
        if (TTecCtrl::is_technique_ready() != 0 && (c->flags & 0xA000) &&
            ((u32 (*)(u8 *, void *, void *))init_target_vector__11TMainCursorFiii)((u8 *)entry, &c->center, &owner->bodies->center) != 0) {
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
        entry->target_list.get_record(slot)->set_id(((TObjBase *)candidate)->get_entity_id());
        found = 1;
    }
    return found;
}


void init_target_vector__11TMainCursorFiii(s32 arg0, saddr to, saddr from) {
    csnVector((const Vec *)from, (const Vec *)to, 0x28A0);
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
        a.y = TMainCursor__data_805DB0C0;
        a.z = cos_table_lookup(yaw);
        if (TMainCursor__data_805DB0C0 == dist) {
            b.x = q->x - p->x;
            b.y = TMainCursor__data_805DB0C0;
            b.z = q->z - p->z;
            normalize_vector_safe(&b);
            if (vec3_dot(&a, &b) < range) {
                return 0;
            }
        } else {
            x = dist * sin_table_lookup(yaw + 0x8000) + p->x;
            z = dist * cos_table_lookup(yaw + 0x8000) + p->z;
            b.x = q->x - x;
            b.y = TMainCursor__data_805DB0C0;
            b.z = q->z - z;
            normalize_vector_safe(&b);
            if (vec3_dot(&a, &b) < range) {
                return 0;
            }
            scratch_vec.x = q->x - r->x;
            scratch_vec.y = TMainCursor__data_805DB0C0;
            scratch_vec.z = q->z - r->z;
            normalize_vector_safe(&scratch_vec);
            if (vec3_dot(&a, &scratch_vec) < TMainCursor__data_805DB0C0) {
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
        if (TMainCursor__data_805DB0C0 == dist) {
            a.x = q->x - p->x;
            a.y = TMainCursor__data_805DB0C0;
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
            a.y = TMainCursor__data_805DB0C0;
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


s32 try_move__11TMainCursorFiii(saddr cursor, u8 type, u8 enabled) {
    if (((TMainCursor *)cursor)->is_channel_active() != 0) {
        return matches_type_and_enabled(reinterpret_cast<const ActionPaletteTag *>(cursor), type, enabled);
    }
    return 0;
}


int check_type_and_enabled(const ActionPaletteTag *tag, u8 type, u8 enabled) { return matches_type_and_enabled(tag, type, enabled); }

TMainCursor::TMainCursor(TObject *parent, u16 entity_id, s32 target_id, s32 action_palette, s32 active,
                         u16 client_id, f32 size)
    : TObject(parent) {
    m_name = main_cursor_class_name;
    set_entity_id(entity_id);
    set_target_id_at_60(target_id);
    sub_8013E724(size);
    set_cursor_action_palette_mode(this, action_palette);
    init_field_60(active);
    set_client_id(client_id);
}

TMainCursor::~TMainCursor() {}

void TMainCursor::refresh_target_marker() {
    TObjPlayer *player;
    s32 temp_r3_2;
    player = get_owner_player();
    if (player == NULL) {
        queue_destruction();
        return;
    }
    temp_r3_2 = TMainCursor::check_visible(&player->action_palettes.m_smth, player, update_sub_60(), (u8) this->forward_13E338_at_60());
    if (temp_r3_2 == -1) {
        queue_destruction();
        return;
    }
    this->m_1c = 0;
    *(f32 *)&this->unk_28 = 3.75f;
    *(f32 *)&this->m_34 = *(f32 *)&this->unk_28 - 1.0f;
    *(f32 *)&this->unk_38 = 5.0f + *(f32 *)&this->unk_28;
    *(f32 *)&this->unk_30 = *(f32 *)&this->unk_38;
    this->m_3c = 0.5f;
    this->update_position();
    if (check_can_pickup() != 0) {
        this->check_flag_4();
    }
    if (this->update() != 0) {
        marker.set_color(&target_cursor_color_table[4]);
        return;
    }
    marker.set_color(&target_cursor_color_table[temp_r3_2]);
}

void TMainCursor::update_position() {
    saddr arg0 = (saddr)this;
    void *entity;

    entity = find_entity_by_id(((TMainCursor *)arg0)->target.get_entity_id());
    if (entity != NULL) {
        saddr base = *(s32 *)((s8 *)entity + 0xA4) + ((TMainCursor *)arg0)->is_position_moved() * 0x2C;
        VecCopy((Vec *)(arg0 + 0x40), (const Vec *)(base + 0x1C));
    }
}

void TMainCursor::run_task() {
    u8 *arg0 = (u8 *)this;

    if ((s32) this->m_1c != 2) {
        ((TMainCursor *)arg0)->validate_target();
        if (((TMainCursor *)arg0)->check_flag_1() != 0) {
            this->m_1c = 2;
        }
    }
    switch (this->m_1c) {
    case 0:
        *(f32 *)&this->unk_30 = (f32) (*(f32 *)&this->unk_30 - 1.0f);
        if (!(*(f32 *)&this->unk_30 > *(f32 *)&this->m_34)) {
            *(f32 *)&this->unk_30 = (f32) *(f32 *)&this->unk_28;
            this->m_1c = 1;
            if (((TMainCursor *)arg0)->init_render_flags() == 0) {
                if (((TMainCursor *)arg0)->update() != 0) {
                    play_sound_effect(0x3816, reinterpret_cast<const Vec *>((u8 *)&this->m_40), 0, 1);
                    return;
                }
                play_sound_effect(0x3111, reinterpret_cast<const Vec *>((u8 *)&this->m_40), 0, 1);
            }
        }
    case 1:
        return;
    case 2: {
        f32 distance = marker.get_alpha() - 0.2f;
        if (distance > TMainCursor__data_805DB0C0) {
            marker.set_alpha(distance);
            return;
        }
        ((TObject *)arg0)->queue_destruction();
        break;
    }
    }
}

void TMainCursor::render() {
    u8 *arg0 = (u8 *)this;
    s32 cam;
    s32 no;
    if (((TMainCursor *)arg0)->init_render_flags() != 0) {
        return;
    }
    switch (((TMainCursor *)arg0)->test_flag_2_at_20()) {
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
    switch (*(s32 *)(arg0 + 0x1C)) {
    case 0:
    case 1:
        ((TMainCursor *)arg0)->update_position();
        break;
    case 2:
        break;
    default:
        return;
    }
    TObjFish::set_global_param(&shared_effect_texture_list);
    render__11TMainCursorFPv((TMainCursor *)arg0);
}

#pragma push
#pragma opt_common_subs off

void TMainCursor::validate_target() {
    TObjPlayer *t;
    ((FlagWord *)(((u8 *)this) + 0x20))->clear(0xB);
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
    if (TMainCursor__sub_8013E358(((u8 *)this) + 0x60) != 1) {
        if (TMainCursor::check_visible(&t->action_palettes.m_smth, t, TMainCursor__sub_8013E358(((u8 *)this) + 0x60),
                                            TMainCursor__sub_8013E338(((u8 *)this) + 0x60)) == -1) {
            t->lock_on_cursor->selection.target.set_entity_id(0xFFFF);
            this->update_target_sub();
            return;
        }
    }
    if (TObjPlayer::is_any_teammate_in_state() != 0) {
        TMainCursor__sub_8013E310(this);
        return;
    }
    switch (TMainCursor__sub_8013E358(((u8 *)this) + 0x60)) {
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
        if (TObjPlayer::is_invalid_slot(get_cast_technique_level(&t->technique_state, TMainCursor__sub_8013E338(((u8 *)this) + 0x60))) != 0) {
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
        if (t->tp - (calc_technique_parameters(TMainCursor__sub_8013E338(((u8 *)this) + 0x60),
                                                      get_cast_technique_level(&t->technique_state, TMainCursor__sub_8013E338(((u8 *)this) + 0x60)),
                                                      t->get_entity_id()))->tp_cost < 0) {
            this->update_target_sub();
            return;
        }
        return;
    case 4:
        return;
    case 5:
        if ((s8)fn_8013F24C((Obj_8013F24C *)((u8 *)t + 0x4AC), TMainCursor__sub_8013E338(((u8 *)this) + 0x60)) != (s8)TMainCursor__sub_8013F244()) {
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


void render__11TMainCursorFPv(TMainCursor *main_cursor) {
    s32 sp8;
    f32 y;

    TParticleCtrl::begin_effect_render();
    y = *(f32 *)((s8 *)main_cursor + 0x30);
    push_matrix();
    offset_point_toward_camera((Vec *)((u8 *)main_cursor + 0x40), (Vec *)&sp8, main_cursor->m_2c);
    translate_matrix_vec3((u8 *)(0), (u8 *)&sp8);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    push_matrix();
    rotate_matrix_z(0, 0x2AAA);
    translate_matrix(0, TMainCursor__data_805DB0C0, y, TMainCursor__data_805DB0C0);
    main_cursor->update_photon_chair();
    main_cursor->update_chair();
    pop_matrix();
    push_matrix();
    rotate_matrix_z(0, 0x7FFF);
    translate_matrix(0, TMainCursor__data_805DB0C0, y, TMainCursor__data_805DB0C0);
    main_cursor->update_photon_chair();
    main_cursor->update_chair();
    pop_matrix();
    push_matrix();
    rotate_matrix_z(0, 0xD554);
    translate_matrix(0, TMainCursor__data_805DB0C0, y, TMainCursor__data_805DB0C0);
    main_cursor->update_photon_chair();
    main_cursor->update_chair();
    pop_matrix();
    pop_matrix();
    TParticleCtrl::end_effect_render();
}


void TMainCursor::update_chair() {
    struct VOff_8013B524_arg0_8013B524 *self = (struct VOff_8013B524_arg0_8013B524 *)this;
    save_model_draw_state(self->f_4C);
    begin_constant_color_draw_self((NJS_ARGB *)(self->f_4C));
    TMainCursor__get_lock_on_cursor_model();
    draw_chunk_object();
    restore_model_draw_state(self->f_4C);
}

void TMainCursor::update_photon_chair() {
    saddr arg0 = (saddr)this;
    if (marker.get_alpha() > 0.99999f) {
        save_model_draw_state((void*)(arg0 + 0x4C));
        begin_constant_color_draw_argb((void *)(arg0 + 0x4C), 1.0f, TMainCursor__data_805DB0C0, TMainCursor__data_805DB0C0, TMainCursor__data_805DB0C0);
        TMainCursor::get_cursor_model();
        draw_chunk_object();
        restore_model_draw_state((void*)(arg0 + 0x4C));
    }
}


s32 canSetMenuCursorAction(PaletteCursorOverride* cursor, TObjPlayer* player, u8 kind, u8 parameter) {
    if (((TMainCursor *)cursor)->is_channel_active() != 0) {
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
    origin.z = TMainCursor__data_805DB0C0;
    origin.y = TMainCursor__data_805DB0C0;
    origin.x = TMainCursor__data_805DB0C0;
    lock_range = TMainCursor__data_805DB0C0;
    horizontal_cone_cos = TMainCursor__data_805DB0C0;
    vertical_cone_cos = TMainCursor__data_805DB0C0;
    horizontal_cone_angle = 0;
    vertical_cone_angle = 0;
    cone_apex_offset = TMainCursor__data_805DB0C0;
    max_candidate_dist = TMainCursor__data_805DB0C0;
    ((TMainCursor *)this)->set_type(0);
    clear_target_cursor_list(&target_list);
    target_records.clear();
}

void copy_action_entry(void *arg0, void *arg1) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
}

s32 TMainCursor::sort_actions_by_priority() {
    s32 k;
    s32 n;
    s32 i;
    Ent_8013B2C8 *p;
    Ent_8013B2C8 *q;
    TUnk_8013E2B0 tmp;
    if ((Ent_8013B2C8 *)this->get_index() == NULL) {
        return 0;
    }
    n = TMainCursor__sub_8013E2A0(this);
    while (--n > 0) {
        p = (Ent_8013B2C8 *)this->get_index();
        for (i = 0; i < n; p++, i++) {
            q = p + 1;
            k = TMainCursor__sub_8013E298(q);
            if (TMainCursor__sub_8013E298(p) > k) {
                copy_action_entry(&tmp, p);
                copy_action_entry(p, q);
                copy_action_entry(q, &tmp);
            }
        }
    }
    return 1;
}

TObjPlayer *CursorOwner::get_player() { return get_player_by_client_id(client_id); }

TLOC_Start::TLOC_Start(TObject *parent, u16 id) : TUnk_804A7260(parent, id) { m_name = TLOC_Start__name; }

TLOC_Start::~TLOC_Start() {
    if ((m_target.resolve() != 0) && (m_target.get_player()->lock_on_cursor != NULL)) {
        m_target.get_player()->lock_on_cursor->set_start_task(NULL);
    }
}

void TLOC_Start::run_task() {
    saddr arg0 = (saddr)this;
    Pl_8013B0F0 *pl;
    TLockOnCursor *cur;
    s32 i;
    pl = (Pl_8013B0F0 *)get_player_by_client_id((s32)(((PlayerRef *)(arg0 + 0x1C))->get_client_id()));
    if (pl == NULL) {
        return;
    }
    cur = pl->cur;
    if (cur == NULL) {
        return;
    }
    cur->nearest_target.reset();
    cur->selection.update_cursor_pos();
    cur->selection.target.set_entity_id(0xFFFF);
    ((TMainCursor *)cur)->init_slots();
    ((TMainCursor *)cur)->bind_action_channels();
    if (get_main_phase() == 0xF) {
        for (i = 0; i < 12; i++) {
            Pl_8013B0F0 *p = player_slot_table[i];
            if (p != NULL && ((TObjPlayer *)p)->is_body_collision_inactive() == 0) {
                submit_cursor_candidate(p, -1);
            }
        }
    } else {
        submit_cursor_candidate(pl, -1);
    }
}

TLOC_End::TLOC_End(TObject *parent, u16 id) : TUnk_804A7260(parent, id) { m_name = TLOC_End__name; }

TLOC_End::~TLOC_End() {
    if ((m_target.resolve() != 0) && (m_target.get_player()->lock_on_cursor != NULL)) {
        m_target.get_player()->lock_on_cursor->set_end_task(NULL);
    }
}

#pragma defer_codegen off


void TObjPlayer__sub_8013DEF8(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 2) = (s16) (*(s16 *)((s8 *)arg0 + 2) | 1);
}


s32 TMainCursor::is_channel_active() {
    return (u8)((u8) ((*(s16 *)((s8 *)this + 2) & 1) ^ 1));
}

s32 TMainCursor::check_visible(TPlyDispConfigSmth *palette, TObjPlayer *player, s16 type, s32 enabled) {
    return palette->find_action_slot_for_target(player, type, enabled);
}

u8 get_action_palette_tag_slot(const ActionPaletteTag *tag) { return tag->tag1; }

u8 get_action_palette_tag_mode(const ActionPaletteTag *tag) { return tag->tag0; }

void set_action_palette_tag_slot(ActionPaletteTag *tag, u8 slot) { tag->tag1 = slot; }

void set_action_palette_tag_mode(ActionPaletteTag *tag, u8 mode) { tag->tag0 = mode; }

int matches_type_and_enabled(const ActionPaletteTag *tag, u8 type, u8 enabled) {
    s32 var_r31;
    var_r31 = 0;
    if ((type == get_action_palette_tag_mode(tag)) && (enabled == get_action_palette_tag_slot(tag))) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}


void TMainCursor__sub_8013DFC4(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 2) = (s16) (*(s16 *)((s8 *)arg0 + 2) & 0xFFFFFFFE);
}


TObjPlayer *PlayerRef::get_player() { return player; }

PlayerRef::~PlayerRef() {}

void PlayerRef::set_client_id(u16 id) { client_id = id; }

PlayerRef::PlayerRef() {
    client_id = reserved = 0xffff;
    player = 0;
}

u16 PlayerRef::get_client_id() { return client_id; }

TUnk_804A7260::~TUnk_804A7260() {}

void TLockOnCursor::set_list_clear_task(TObject *task) { tasks.set_list_clear_task(task); }

void TUnk_8013F08C::set_list_clear_task(TObject *task) { list_clear_task = task; }

TUnk_804A7260::TUnk_804A7260(TObject *parent, u16 id) : TObject(parent) {
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

void TUnk_8013F08C::set_end_task(TObject *task) { end_task = task; }

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
    published_target_dist = TMainCursor__data_805DB0C0;
    candidate_target_dist = lbl_805DB0C4;
}

void TLockOnCursor::set_start_task(TObject *task) { tasks.set_start_task(task); }

void TUnk_8013F08C::set_start_task(TObject *task) { start_task = task; }


s16 TMainCursor__sub_8013E298(void* p) { return *(s16*)((char*)p + 0x0); }

s32 TMainCursor__sub_8013E2A0(void* p) { return *(s32*)((char*)p + 0x0); }


saddr TMainCursor::get_index() { return *(s32 *)&this->m_flags; }

TUnk_8013E2B0::TUnk_8013E2B0() { unk_2 = 0; unk_0 = 0; }

void LockOnTargetRecordList::clear() { count = 0; }

void TMainCursor::set_type(s32 v) { *(s32 *)&this->m_flags = v; }

NJS_OBJECT *TMainCursor::get_cursor_model() { return main_cursor_model; }


int TMainCursor__get_lock_on_cursor_model(void) {  return lock_on_cursor_model; }


TObjPlayer *TMainCursor::get_owner_player() { return owner.get_player(); }

u16 CursorTarget::get_entity_id() { return entity_id; }


void TMainCursor__sub_8013E310(void* p) { ((FlagWord *)((char*)p + 0x20))->set(2); }

u8 TMainCursor__sub_8013E338(void* p) { return get_action_palette_tag_slot(static_cast<const ActionPaletteTag *>(p)); }

u8 TMainCursor__sub_8013E358(void* p) { return get_action_palette_tag_mode(static_cast<const ActionPaletteTag *>(p)); }


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

void TMainCursor::update_target_sub() { ((FlagWord *)((char*)this + 0x20))->set(1); }

u16 TMainCursor::get_client_id() { return owner.get_client_id(); }

u16 CursorOwner::get_client_id() { return client_id; }

int TMainCursor::test_flag_2_at_20() { return test_flags_any((s32 *)((char*)this + 0x20), 2); }

int TMainCursor::init_render_flags() { return test_flags_any((s32 *)((char*)this + 0x20), 8); }

int TMainCursor::update() { return test_flags_any((s32 *)((char*)this + 0x20), 4); }

int TMainCursor::check_flag_1() { return test_flags_any((s32 *)((char*)this + 0x20), 1); }

u8 TMainCursor::is_position_moved() { return (u8)(TMainCursor__sub_8013E570((char*)this + 0x60)); }


s16 TMainCursor__sub_8013E570(void* p) { return *(s16*)((char*)p + 0x6); }


void TMainCursor::check_flag_4() { ((FlagWord *)((char*)this + 0x20))->set(4); }

u8 TMainCursor::forward_13E338_at_60() { return TMainCursor__sub_8013E338((char*)this + 0x60); }

u8 TMainCursor::update_sub_60() { return TMainCursor__sub_8013E358((char*)this + 0x60); }

CursorOwner::~CursorOwner() {}

CursorTarget::~CursorTarget() {}

void TMainCursor::set_client_id(u16 id) { owner.set_client_id(id); }

void CursorOwner::set_client_id(u16 id) { client_id = id; }

void TMainCursor::init_field_60(u8 slot) { set_cursor_palette_slot(&target.palette_tag, slot); }

void set_cursor_palette_slot(ActionPaletteTag *tag, u8 slot) { set_action_palette_tag_slot(tag, slot); }

void set_cursor_action_palette_mode(TMainCursor *cursor, u8 mode) { set_cursor_palette_mode(&cursor->target.palette_tag, mode); }

void set_cursor_palette_mode(ActionPaletteTag *tag, u8 mode) { set_action_palette_tag_mode(tag, mode); }

void TMainCursor::sub_8013E724(f32 v) { this->m_2c = v; }

void TMainCursor::set_target_id_at_60(u8 target_id) {
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

void TMainCursor::init_slot(s32 i) {
    TMainCursor__sub_8013E8A0((void*)(&((Obj_8013E870 *)this)->recs[i]));
}

void TMainCursor__sub_8013E8A0(void *p) { TObjPlayer__sub_8013DEF8((u8 *)p); }

int TMainCursor::get_selected_entry() { return is_channel_active(); }

u8 TMainCursor::get_active() { return get_action_palette_tag_slot(reinterpret_cast<const ActionPaletteTag *>(this)); }

u8 get_cursor_palette_mode(void *p) { return get_action_palette_tag_mode(static_cast<const ActionPaletteTag *>(p)); }

s16 get_action_entry_index(void* p) { return *(s16*)((char*)p + 0x2); }

void set_action_entry_index(void* p, s16 v) { *(s16*)((char*)p + 0x2) = v; }

void set_action_entry_priority(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }

u16 TLockOnCursor::get_target_id() { return target_id; }

int TMainCursor::is_cursor_clear() { return (test_flags_any((s32 *)((char*)this + 0x1c), 1)) == 0; }

void set_target_part(u8 *arg0, u16 arg1, s32 arg2, s32 arg3) {
    *(s16 *)((s8 *)arg0 + 0) = arg1;
    *(s16 *)((s8 *)arg0 + 2) = arg2;
    *(s16 *)((s8 *)arg0 + 4) = arg3;
}

void TMainCursor::set_color_mode(s32 v) { *(s32 *)&this->m_up = v; }

void TMainCursor::set_color(s32 v) { *(s32 *)&this->m_prev = v; }

void TMainCursor::set_field_0c(s32 v) { *(s32 *)&this->m_next = v; }

void TMainCursor::set_flags(s32 v) { *(s32 *)&this->m_down = v; }

void TMainCursor__sub_8013E9A0(void *p) { TMainCursor__sub_8013DFC4((u8 *)p); }

void set_cursor_slot(void* p, u8 v) { set_action_palette_tag_slot(static_cast<ActionPaletteTag *>(p), v); }

void set_cursor_mode(void* p, u8 v) { set_action_palette_tag_mode(static_cast<ActionPaletteTag *>(p), v); }

void LockOnTargetRecordList::set_count(s32 count) { this->count = count; }

int LockOnTargetRecord::is_excluded() { return test_flags_any(&flags.bits, 2); }

int LockOnSelection::is_cursor_on_target() { return target.is_same_target(&cursor_target); }

void LockOnTargetRecord::set_primary() { flags.set(1); }

void LockOnTargetRecord::clear_primary() { flags.clear(1); }

void LockOnTargetRecord::set_excluded() { flags.set(2); }

int TLockOnCursor::is_inactive() { return (test_flags_any(&this->flags.bits, 2)) == 0; }

void LockOnTargetRecord::clear_excluded() { flags.clear(2); }

s32 LockOnActionSlot::get_max_targets() { return max_targets; }


int TLockOnCursor__sub_8013EB34(void) {  return TLockOnCursor::target_cursor_model; }


int LockOnTargetRecord::is_primary() { return test_flags_any(&flags.bits, 1); }

s32 LockOnTargetRecordList::get_count() { return count; }

LockOnActionSlot *TLockOnCursor::get_action_slot(s32 i) {
    return &action_slots[i];
}

void TLockOnCursor__sub_8013EB80(void* p) { *(s32*)((char*)p + 0x4) = 0; }

void TLockOnCursor__sub_8013EB8C(void* p) { *(s32*)((char*)p + 0x4) = 1; }

TObject *TLockOnCursor::get_list_clear_task() { return tasks.get_list_clear_task(); }

TObject *TUnk_8013F08C::get_list_clear_task() { return list_clear_task; }

TObject *TLockOnCursor::get_end_task() { return tasks.get_end_task(); }

TObject *TUnk_8013F08C::get_end_task() { return end_task; }

TObject *TLockOnCursor::get_start_task() { return tasks.get_start_task(); }

TObject *TUnk_8013F08C::get_start_task() { return start_task; }

void TLockOnCursor__sub_8013EC1C(void *p) {
    Obj_8013EC1C *self = (Obj_8013EC1C *)p;
    self->a = 0xffff;
    self->b = 0;
    self->c = 0;
}

void LockOnSelection::reset_state() {
    target.reset_target();
    cursor_target.reset_target();
    unk_8.init();
    unk_0 = 0xffff;
    unk_2 = 0;
    unk_4 = TMainCursor__data_805DB0C0;
}

TUnk_8013F114::~TUnk_8013F114() {}

TUnk_8013F08C::~TUnk_8013F08C() {}

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

TUnk_8013F114::TUnk_8013F114() { unk_0 = 0; unk_4 = 0; }


void TMainCursor__sub_8013F10C(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }

void TMainCursor__sub_8013F104(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }


TUnk_8013F0A0::TUnk_8013F0A0() {
    TMainCursor__sub_8013F10C(this, 4);
    TMainCursor__sub_8013F104(this, (saddr)unk_8);
}

TUnk_8013F08C::TUnk_8013F08C() { start_task = NULL; end_task = NULL; list_clear_task = NULL; }

LockOnTargetRecord::LockOnTargetRecord() {}

LockOnTargetRecordList::LockOnTargetRecordList() { clear(); }

LockOnActionSlot::LockOnActionSlot() { reset_state(); }

LockOnSelection::LockOnSelection() { reset_state(); }

TUnk_8013EF3C::TUnk_8013EF3C() { TLockOnCursor__sub_8013EC1C(this); }

LockOnNearestTarget::LockOnNearestTarget() { reset(); }

TUnk_804A7248::TUnk_804A7248() {
    unk_4 = 0;
}

void TLockOnCursor::sub_8013EEC0(u16 target_id) { this->target_id = target_id; }

TUnk_804A7248::~TUnk_804A7248() {}

#pragma defer_codegen off

MarkerColor::MarkerColor() {
    TMainCursor__sub_8013F22C(this);
}


void TMainCursor__sub_8013F22C(void* a0) { *(float*)((char*)a0 + 0xc) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x8) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x4) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x0) = TMainCursor__data_805DB0C0; }

int TMainCursor__sub_8013F244(void) { return -1; }

u8 fn_8013F24C(Obj_8013F24C *self, s16 i) {
    return self->arr[i];
}


int TCameraCtrl::get_mode() {  return fixed_npc_camera_active; }
