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
#include "pso/unk/TLOC_End.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
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
#include "pso/ui/hud/TMainCursor_8013AE18.h"
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
#include "pso/ui/hud/TMainCursor_8013E44C.h"
#include "pso/ui/hud/TMainCursor_8013E47C.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/hud/TMainCursor_8013E624.h"
#include "pso/ui/hud/TMainCursor_8013E7B8.h"
#include "pso/ui/hud/TLockOnCursor_8013EA08.h"
#include "pso/ui/hud/TLockOnCursor_8013EB80.h"
#include "pso/unk/text_80072004.h"
#include "pso/ui/hud/TLockOnCursor_8013ED0C.h"
#include "pso/ui/hud/TLockOnCursor_8013EDC4.h"
#include "pso/ui/hud/TLockOnCursor_8013EE00.h"
#include "pso/ui/hud/TLockOnCursor_8013EEC8.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/hud/TMainCursor_80154090.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
extern "C" void *__ct__16TargetCursorListFv(void *list);
extern "C" void *__ct__18TargetCursorRecordFv(void *p);

extern "C" {

u8 *__dt__14TLOC_ListClearFv(u8 *arg0, s16 arg1);
void TObjPlayer__sub_8013DEF8(u8 *arg0);
s32 TObjPlayer__sub_801C6DAC(u8 *arg0);

extern void *lbl_804A71C4[6];

}

struct Part_8013AF50 { u8 pad[0x124]; };

struct Cur_8013AF50 {
    u8 pad0[0x5C];
    Part_8013AF50 parts[4];
    u8 pad[0x510 - 0x5C - 4 * 0x124];
    TUnk_8013EF0C nearest_target;
};

struct State_8013AF50 {
    u8 pad[0x424];
    Cur_8013AF50 *cur;
};

extern "C" {
void publish_target_list__11TMainCursorFPvi(struct Self_8013D4A0 *, s32);
State_8013AF50 *get_state__11TMainCursorFv(s32);

extern const char *lockon_list_clear_task_name;

}

struct Cur_8013B0F0 {
    u8 pad0[0x4EC];
    u8 pos[0x4F8 - 0x4EC];
    u8 target[0x510 - 0x4F8];
    TUnk_8013EF0C nearest_target;
};

struct Pl_8013B0F0 {
    u8 pad[0x424];
    Cur_8013B0F0 *cur;
};

extern "C" {
u16 get_client_id(void *p);
int set_target_index__11TMainCursorFs(void *, s32);
}
extern Pl_8013B0F0 *player_slot_table[12];


struct Ent_8013B2C8 { s32 w; };

extern "C" {
void clear_target_cursor_list(void *);
extern const f32 TMainCursor__data_805DB0C0;
s32 can_start_technique__10TObjPlayerFPvi(TObjPlayer*, s32);
s32 canSetMenuCursorAction(PaletteCursorOverride* cursor, TObjPlayer* player, u8 kind, u8 parameter);
void copy_action_entry(void *arg0, void *arg1);
s16 TMainCursor__sub_8013E298(void *p);
s32 TMainCursor__sub_8013E2A0(void *);
TObjPlayer *resolve_player_by_client_id(u16 *client_id);

extern const char *TLOC_Start__name;
}

extern "C" {

void draw_chunk_object(void);

struct VOff_8013B524_arg0_8013B524 { char pad_0[0x4C]; char f_4C[1]; };

s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_y(s32, s32);

s32 check_visible__11TMainCursorFv(void *, void *, s32, s32);
void *find_entity_by_id(u16 id);
u8 get_cast_technique_level(void *, s32);
s16 TObjPlayer__sub_801B5AF8(TObjPlayer *player, s32 index);
void set_cursor_id__11TMainCursorFs(void *, u16);
u8 get_cursor_palette_mode(void *);
}

struct Target_8013B70C {
    u8 pad0[0x32E];
    s16 f32E;
    u8 pad330[0x424 - 0x330];
    u8 *f424;
};

extern "C" {
extern u8 shared_effect_texture_list[];

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
f32 target_cursor_color_table[6][4] = {
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

}

extern "C" {

s32 set_offset_y__11TMainCursorFs(void *, u16);
s32 get_rader_map__11TMainCursorFv(void *, void *);

}

struct Coll_8013C288 { u8 pad0[0xC]; f32 radius; u8 pad10[0x18 - 0x10]; u32 flags; u8 pos[0x2C - 0x1C]; };

extern "C" {
u8 * csnVector(s32, s32, s32);
f32 vec3_dot(void *, void *);
s32 target_in_vertical_cone(Vec *p, Vec *q, s32 yaw, f32 range, f32 dist);
extern Vec scratch_vec;
s32 target_in_xz_cone(Vec *p, Vec *q, Vec *r, s32 yaw, f32 range, f32 dist);
s32 TMainCursor__sub_8013F168(void *);
s32 try_add_target_candidate__11TMainCursorFPvPvPvPv(u8 *cursor, u8 *player, u8 *target, TUnk_8013EF0C *best);
struct Ent_8013C678 { u32 id; f32 key; };
s32 quick_sort_partition__11TMainCursorFiPvii(saddr self, Ent_8013C678 *a, s32 lo, s32 hi);
void TMainCursor__sub_8013F170(void *p, s32 v);
void clear_target_cursor_list(void *p);

s32 is_key_machine_ready__10TObjPlayerFv();
s32 TMainCursor__sub_8013E2A0(void *list);
s16 TMainCursor__sub_8013E298(void *entry);
s16 get_action_entry_index(void *entry);
void set_action_entry_index(void *entry, s16 v);
}

struct ActionCursor_8013C924 {
    u8 pad0[0x24];
    TMainCursor actions;
    u8 pad8C[0x520 - 0x24 - sizeof(TMainCursor)];
    ActionPaletteTag channel;
};

struct TLockOnCursor;
struct Item_8013D4A0 { u16 id; s16 idx; f32 size; };

struct Part_8013D4A0 { u8 pad0[0xC]; f32 size; u8 pad10[8]; s32 flags; u8 pad1C[0x10]; };

struct Sub_8013D4A0 { u8 pad0[0x40]; u8 x40[0x5C]; u8 x9C[0x88]; };

struct Self_8013D4A0 { u8 pad0[0x5C]; Sub_8013D4A0 subs[3]; u8 pad3C8[0x124]; u8 x4EC[0xC]; u8 x4F8[0x10]; u16 x508; s16 x50A; };

struct Ent_8013D4A0 { u8 pad0[0xA4]; Part_8013D4A0 *parts; };

struct Cursor_8013CDE4 {
    u8 pad0[0x1C];
    f32 pos[3];
    f32 f28;
    f32 f2c;
    f32 f30;
    s32 f34;
    s32 f38;
    f32 f3c;
    u8 f40[0x9C - 0x40];
    u8 f9c[0x124 - 0x9C];
};

struct Main_8013CDE4 { u8 pad0[0x5C]; Cursor_8013CDE4 cursors[4]; };

struct Tech_8013CDE4 { u8 pad0[8]; f32 f8; f32 fc; u8 pad10[0x18 - 0x10]; s32 f18; s32 f1c; u8 pad20[2]; s8 f22; };

struct Weapon_8013CDE4 { f32 f0; f32 f4; s32 f8; s32 fc; s32 f10; };

extern "C" {
int TLockOnCursor__sub_8013EB34(void);
void *TObjPlayer__sub_80116620(void *, s32);
void set_cursor_count(void *, s32);
s32 TLockOnCursor__sub_8013EB2C(void *);
s32 TMainCursor__sub_8013F168(void *p);
Weapon_8013CDE4 *get_weapon_range_record(void *, s32);
void TMainCursor__sub_8013E9A0(void *p);
extern f32 lbl_8050BF60[3];
int TObjPlayer__sub_801B066C(void *p);
#define C_8013CDE4 ((saddr)cur)
#define TECH_8013CDE4(t)                                          \
    cur->f3c = (t)->fc;                                           \
    cur->f28 = (t)->f8 + cur->f3c;                                \
    cur->f34 = (t)->f18;                                          \
    cur->f2c = cos_table_lookup(cur->f34);              \
    cur->f38 = (t)->f1c;                                          \
    cur->f30 = cos_table_lookup(cur->f38);

}

struct Rec_8013EB6C { u8 pad[0x124]; };
struct Obj_8013EB6C { u8 pad[0x5c]; Rec_8013EB6C recs[1]; };
struct Obj_8013EC1C { u16 a; u16 b; u16 c; };


struct Ent_8013D91C { u16 id; s16 idx; u8 pad[8]; };

extern "C" {

u8 * lock_on_cursor_bml_resource;
s32 lock_on_cursor_model;
s32 TLockOnCursor__target_cursor_model;

}
s32 main_cursor_model;
void load_target_cursor_models(void);
extern "C" {
void __destroy_arr(void *, void *, int, int);
}
extern "C" {
void TLockOnCursor__sub_8013EC1C(void *);

Rec_8013EB6C *TLockOnCursor__record_at(Obj_8013EB6C *, s32);
void render__13TLockOnCursorFv(saddr arg0);
void TLockOnCursor__sub_8013EB80(void *p);
void TLockOnCursor__sub_8013EB8C(void *p);
void __construct_array(void *, void *, void *, int, int);
}

extern "C" {
int find_action_slot_for_target__11TMainCursorFllll(void*);

}

extern "C" {

int TObjPlayer__sub_8013A820(void* a0 = 0);
}
extern const f32 lbl_805DB0C4;


struct Rec_8013E870 { u8 pad[0x124]; };

struct Obj_8013E870 { u8 pad[0x5c]; Rec_8013E870 recs[1]; };


s32 destroy_target_record(saddr, s16);


struct Rec_8013F154 { u8 pad[0x8]; };

struct Obj_8013F154 { u8 pad[0x4]; Rec_8013F154 recs[1]; };

struct Obj_8013F24C { u8 pad[0x44]; u8 arr[1]; };

extern "C" {
u8 fn_8013F24C(Obj_8013F24C *self, s16 i);

}

// TMainCursor and TLockOnCursor are one translation unit: their vtables and the lock-on tasks' sit
// together in .data in reverse key-function order. Deferred code generation is switched on and off
// across the file; each deferred stretch is written last to first.
#pragma defer_codegen off

void TLOC_ListClear::run_task() {
    saddr arg0 = (saddr)this;
    if ((TObjPlayer__sub_801C6DAC((u8 *)(arg0 + 0x1C)) != 0) && ((u32) *(u32 *)((s8 *)(((TMainCursor *)(arg0 + 0x1C))->get_state()) + 0x424) != 0U)) {
        TObjPlayer__sub_8013DEF8((u8 *)(*(saddr *)((s8 *)(((TMainCursor *)(arg0 + 0x1C))->get_state()) + 0x424) + 0x520));
    }
}

extern "C" {

u8 *__dt__14TLOC_ListClearFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 0x18) = lbl_804A71C4;
        if ((TObjPlayer__sub_801C6DAC(arg0 + 0x1C) != 0) &&((u32) *(u32 *)((s8 *)(((TMainCursor *)(arg0 + 0x1C))->get_state()) + 0x424) != 0U)) {
            ((TLockOnCursor *)(*(saddr *)((s8 *)(((TMainCursor *)(arg0 + 0x1C))->get_state()) + 0x424)))->set_list_clear_task(NULL);
        }
        __dt__13TUnk_804A7260Fv(arg0, 0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

}

void *TLOC_ListClear::init_lockon(TObject *parent, u16 id) {
    __ct__13TUnk_804A7260FP7TObjectUs(this, parent, id);
    *(void ***)((s8 *)this + 0x18) = lbl_804A71C4;
    m_name = lockon_list_clear_task_name;
    return this;
}

void TLOC_End::run_task() {
    saddr arg0 = (saddr)this;
    s32 i;
    if (TObjPlayer__sub_801C6DAC((u8 *)(arg0 + 0x1C)) == 0) {
        return;
    }
    if (get_state__11TMainCursorFv(arg0 + 0x1C)->cur == NULL) {
        return;
    }
    for (i = 0; i < 4; i++) {
        TMainCursor::sort_list((saddr)(get_state__11TMainCursorFv(arg0 + 0x1C)->cur), (s32)i);
        publish_target_list__11TMainCursorFPvi((Self_8013D4A0 *)get_state__11TMainCursorFv(arg0 + 0x1C)->cur, i);
    }
    get_state__11TMainCursorFv(arg0 + 0x1C)->cur->nearest_target.publish();
    for (i = 0; i < 4; i++) {
        ((TMainCursor *)(&get_state__11TMainCursorFv(arg0 + 0x1C)->cur->parts[i]))->reset_cursor_parts();
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
            TLockOnCursor__target_cursor_model = (saddr)get_bml_model((BmlResource *)lock_on_cursor_bml_resource, 0);
            main_cursor_model = (saddr)get_bml_model((BmlResource *)lock_on_cursor_bml_resource, 2);
        }
    }
}

void TLockOnCursor::free_cursor_resources() {
    if ((void *) lock_on_cursor_bml_resource != NULL) {
        delete (BmlResource *)lock_on_cursor_bml_resource;
        lock_on_cursor_bml_resource = NULL;
    }
    lock_on_cursor_model = 0;
    TLockOnCursor__target_cursor_model = 0;
}

void TLockOnCursor::reset_and_spawn_cursors() {
    TLOC_ListClear *list_clear;
    s32 i;
    flags.reset();
    for (i = 0; i < 4; i++) {
        ((TMainCursor *)&action_slots[i])->reset_state();
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

extern "C" {

void render__13TLockOnCursorFv(saddr arg0) {
    s32 i;
    s32 j;
    u8 *c;
    s32 n;
    Ent_8013D91C *p;
    saddr e;
    u8 *o;
    if (is_split_screen() != 0) {
        if (TCameraCtrl::get_camera_no() != TCameraCtrl::get_split_screen_view_index(((TLockOnCursor *)arg0)->get_target_id())) {
            return;
        }
    } else if ((s32)main_task.get_task_flags() & 0x10) {
        return;
    }
    for (i = 0; i < 4; i++) {
        c = (u8 *)TLockOnCursor__record_at((Obj_8013EB6C *)arg0, i);
        if (((TMainCursor *)c)->get_selected_entry() != 0) {
            n = ((TLockOnCursor *)(c + 0x9C))->get_target();
            for (p = (Ent_8013D91C *)TObjPlayer__sub_80116620(c + 0x9C, 0), j = 0; j < n; j++, p++) {
                if (((TLockOnCursor *)p)->test_flag_1_at_8() == 0 &&
                    ((TLockOnCursor *)p)->render_part() == 0 &&
                    ((TObjPlayer *)p)->get_type_id() != 0xFFFF) {
                    o = (u8 *)find_entity_by_id(p->id);
                    if (o != NULL) {
                        e = *(s32 *)(o + 0xA4) + p->idx * 0x2C;
                        if (e != 0) {
                            ((TLockOnCursor *)arg0)->renderSecondaryCursor((u8*)e, (s32)(get_cursor_palette_mode((void *)c)), (s32)(((TMainCursor *)c)->get_active()));
                        }
                    }
                }
            }
        }
    }
}

}
#pragma pop

void TLockOnCursor::renderSecondaryCursor(u8 *body, s32 type, s32 action) {
    const saddr arg0 = (saddr)this;
    f32 sp8[3];
    f32 y;
    s32 temp_r3_2;
    uaddr player;
    if (is_inactive() != 0) {
        player = (uaddr)get_player_by_client_id((get_target_id()));
        if (player != 0U) {
            temp_r3_2 = check_visible__11TMainCursorFv((void *)(player + 0x500), (void *)player, type, action);
            if (temp_r3_2 != -1) {
                TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(&shared_effect_texture_list));
                y = *(f32 *)((s8 *)body + 0xC);
                push_matrix();
                offset_point_toward_camera((Vec *)(body + 0x1C), (Vec *)&sp8, (f32)y);
                translate_matrix_vec3((u8 *)(0), (u8 *)&sp8);
                rotate_matrix_y(0, camera_ctrl_instance->yaw);
                TParticleCtrl::begin_effect_render();
                push_matrix();
                translate_matrix(0, TMainCursor__data_805DB0C0, y, TMainCursor__data_805DB0C0);
                save_model_draw_state((void *)(arg0 + 0x48));
                begin_constant_color_draw((void *)(arg0 + 0x48), (const NJS_ARGB *)((void *)target_cursor_color_table[5]));
                TMainCursor::get_cursor_state();
                draw_chunk_object();
                begin_constant_color_draw((void *)(arg0 + 0x48), (const NJS_ARGB *)((void *)target_cursor_color_table[temp_r3_2]));
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

extern "C" {

void publish_target_list__11TMainCursorFPvi(Self_8013D4A0 *arg0, s32 arg1) {
    s32 count;
    s32 i;
    Sub_8013D4A0 *sub;
    Item_8013D4A0 *item;
    s32 n;
    Ent_8013D4A0 *ent;
    Part_8013D4A0 *part;
    s32 mode;
    void *cur;
    void *list;
    sub = &arg0->subs[arg1];
    count = 0;
    item = (Item_8013D4A0 *)TMainCursor::get_record_at(sub->x40, 0);
    n = TMainCursor__sub_8013F168(sub->x40);
    for (i = 0; i < n; i++, item++) {
        if (item->id == 0xFFFF) {
            continue;
        }
        ent = (Ent_8013D4A0 *)find_entity_by_id(item->id);
        if (ent == NULL) {
            continue;
        }
        part = &ent->parts[item->idx];
        if (part == NULL) {
            continue;
        }
        if (count >= TLockOnCursor__sub_8013EB2C(sub)) {
            break;
        }
        mode = 0;
        if (arg0->x508 != 0xFFFF) {
            if (arg0->x508 == item->id && arg0->x50A == item->idx) {
                if (((TMainCursor *)(arg0->x4F8))->get_id() == 0xFFFF) {
                    mode = 2;
                } else {
                    mode = 1;
                }
            } else if (TLockOnCursor__sub_8013EB2C(sub) > 1) {
                mode = 1;
            }
        } else if (((TMainCursor *)(arg0->x4F8))->get_id() == 0xFFFF) {
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
            set_cursor_slot(sub, (u8)((TObjCollidable *)ent)->get_cursor_action());
        }
        cur = TObjPlayer__sub_80116620(sub->x9C, count);
        set_cursor_id__11TMainCursorFs(cur, item->id);
        ((TMainCursor *)cur)->set_size(item->size);
        ((TMainCursor *)cur)->set_field2(item->idx);
        ((TLockOnCursor *)cur)->update_ring_sub();
        if (((TLockOnCursor *)arg0)->is_inactive() == 0 || ((TMainCursor *)ent)->test_button(item->idx, ((TLockOnCursor *)arg0)->get_target_id()) != 0 || (part->flags & 0x08000000)) {
            ((TLockOnCursor *)cur)->is_bit1_set();
        }
        if (mode == 1) {
            ((TLockOnCursor *)cur)->update_ring();
        } else {
            ((TLockOnCursor *)cur)->set_flag_8_bit0();
            if (((TMainCursor *)ent)->test_button(item->idx, ((TLockOnCursor *)arg0)->get_target_id()) == 0) {
                list = ((TMainCursor *)(arg0->x4EC))->get_list();
                set_target_index__11TMainCursorFs(list, item->id);
                set_cursor_palette_mode(reinterpret_cast<ActionPaletteTag *>(list), get_cursor_palette_mode(sub));
                set_cursor_palette_slot(reinterpret_cast<ActionPaletteTag *>(list), ((TMainCursor *)sub)->get_active());
                ((TMainCursor *)list)->set_target_id(item->idx);
                if (((TLockOnCursor *)arg0->x4EC)->update_cursor_pos() == 0 && ((TLockOnCursor *)cur)->render_part() == 0) {
                    cur = new TMainCursor((TObject *)tl_loc_end, item->id, item->idx, (s32)get_cursor_palette_mode(sub), (s32)((TMainCursor *)sub)->get_active(), ((TLockOnCursor *)arg0)->get_target_id(), part->size);
                    if (cur != NULL) {
                        ((TMainCursor *)cur)->refresh_target_marker();
                    }
                }
            }
        }
        part->flags |= 0x10000000;
        TMainCursor__sub_80154230(ent, item->idx, ((TLockOnCursor *)arg0)->get_target_id());
        count++;
    }
    set_cursor_count(sub->x9C, count);
    set_cursor_id__11TMainCursorFs(TObjPlayer__sub_80116620(sub->x9C, count), 0xFFFF);
}

}

void TMainCursor::sort_list(s32 arg0, s32 arg1) {
    saddr temp_r30;

    temp_r30 = arg0 + (arg1 * 0x124) + 0x5C;
    if (((TMainCursor *)temp_r30)->get_selected_entry() != 0) {
        TMainCursor::quick_sort(temp_r30, (saddr)TMainCursor::get_record_at((void *)(temp_r30 + 0x40), 0), 0, TMainCursor__sub_8013F168((void *)(temp_r30 + 0x40)) - 1);
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
        clear_target_cursor_list(cur->f40);
        ((TMainCursor *)(cur->f9c))->reset_slot();
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
            lbl_8050BF60[0] = 50.0f * sin_table_lookup(*(s32 *)(player + 0x60)) + *(f32 *)(player + 0x2FC);
            lbl_8050BF60[1] = *(f32 *)(player + 0x300);
            lbl_8050BF60[2] = 50.0f * cos_table_lookup(*(s32 *)(player + 0x60)) + *(f32 *)(player + 0x304);
            VecCopy((Vec *)cur->pos, (const Vec *)lbl_8050BF60);
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
            if (get_type__10TObjPlayerFPv((player + 0x828)) != 0) {
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
        if (get_type__10TObjPlayerFPv((player + 0x828)) == 0) {
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
    if (TObjPlayer__sub_801B066C((void *)player) == 1) {
        ((TMainCursor *)main_cursor)->set_field_0c(0x40030000);
        return;
    }
    ((TMainCursor *)main_cursor)->set_field_0c(0x40030000);
}

void TMainCursor::set_cursor_color(s32 arg0, saddr player, saddr main_cursor) {
    if (get_type__10TObjPlayerFPv((void *)(player + 0x828)) != 0) {
        ((TMainCursor *)main_cursor)->set_color(0xA000);
        ((TMainCursor *)main_cursor)->set_color_mode(0x70000000);
        return;
    }
    ((TMainCursor *)main_cursor)->set_color(0x8000);
    ((TMainCursor *)main_cursor)->set_color_mode(0x60000000);
}

s32 TMainCursor::get_action_cursor_priority(void *arg0, saddr player, s32 index) {
    u16 kind;
    u16 sub;
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
        if (TObjPlayer::try_camera_action(player, sub) != 0) {
            return cursor_action_priority_table[sub];
        }
        break;
    case 4:
        if (TObjPlayer::is_effect_channel_active(player, index) != 0 && is_current_area_item_enabled() != 0 && ((TObjPlayer *)player)->test_action_mask(0x43001E) != 0 && ((s32)sub == 0xA || (s32)sub == 9)) {
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
    u32 eq = (u32) __cntlzw((u32) ((u16) ((TMainCursor *)(arg0 + 0x4F8))->get_id() - (u16) arg1)) >> 5;
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
            if (is_key_machine_ready__10TObjPlayerFv() == 0) {
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
        clear_target_cursor_list((void *)(base + 0x40));
        ((TMainCursor *)(base + 0x9C))->reset_slot();
        i += 1;
        base += 0x124;
    } while (i < 4);
}

void TMainCursor::quick_sort(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    if (arg2 < arg3) {
        temp_r3 = ((s32 (*)(void))quick_sort_partition__11TMainCursorFiPvii)();
        TMainCursor::quick_sort(arg0, arg1, arg2, temp_r3 - 1);
        TMainCursor::quick_sort(arg0, arg1, temp_r3 + 1, arg3);
    }
}

extern "C" {

s32 quick_sort_partition__11TMainCursorFiPvii(saddr self, Ent_8013C678 *a, s32 lo, s32 hi) {
    Ent_8013C678 tmp;
    f32 pivot;
    s32 i;
    s32 j;

    __ct__18TargetCursorRecordFv(&tmp);
    j = hi;
    i = lo - 1;
    pivot = a[hi].key;
    for (;;) {
        while (a[++i].key < pivot) {
        }
        while (i < --j && pivot < a[j].key) {
        }
        if (i >= j) {
            break;
        }
        TMainCursor::store_sorted_record((void*)self, &a[i], &tmp);
        TMainCursor::store_sorted_record((void*)self, &a[j], &a[i]);
        TMainCursor::store_sorted_record((void*)self, &tmp, &a[j]);
    }
    TMainCursor::store_sorted_record((void*)self, &a[i], &tmp);
    TMainCursor::store_sorted_record((void*)self, &a[hi], &a[i]);
    TMainCursor::store_sorted_record((void*)self, &tmp, &a[hi]);
    return i;
}

}

void TMainCursor::reset_cursor_parts() {
    u8 *arg0 = (u8 *)this;
    s32 i;

    TMainCursor__sub_8013F170(((u8 *)&this->m_40), 0);
    i = 0;
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) TMainCursor__data_805DB0C0;
    do {
        ((TMainCursor *)TMainCursor::get_record_at((u8 *)&this->m_40, i))->set_size(TMainCursor__data_805DB0C0);
        set_cursor_id__11TMainCursorFs((void *)TMainCursor::get_record_at((u8 *)&this->m_40, i), 0xFFFF);
        i += 1;
    } while (i < 0xA);
}

extern "C" {

s32 try_add_target_candidate__11TMainCursorFPvPvPvPv(u8 *cursor, u8 *player, u8 *target, TUnk_8013EF0C *best) {
    f32 dist;
    s32 slot;
    s32 found;
    s32 i;
    Coll_8013C288 *c;
    s32 yaw;
    s32 stat;
    s32 j;
    slot = 0;
    found = 0;
    if (target == NULL) {
        return 0;
    }
    if ((u16)((TObjBase *)target)->get_entity_id() == (u16)((TObjBase *)player)->get_entity_id()) {
        return 0;
    }
    if (TTecCtrl::is_technique_ready() == 0) {
        if (((TObjBase *)target)->get_room() != (stat = ((TObjBase *)player)->get_room()) && (*(u32 *)(player + 0x30) & 0x60000000) == 0x20000000 && stat != -1) {
            return 0;
        }
    }
    if (((TObjCollidable *)target)->test_actor_flags(0xA00) != 0) {
        return 0;
    }
    if (player == NULL || ((TObject *)player)->all_parents_unqueued_for_destruction() == 0) {
        return 0;
    }
    if (((TObjCollidable *)player)->test_actor_flags(((TMainCursor *)cursor)->get_actor_include_mask()) == 0 ||
        ((TObjCollidable *)player)->test_actor_flags(((TMainCursor *)cursor)->get_actor_exclude_mask()) != 0) {
        return 0;
    }
    yaw = *(s32 *)(target + 0x60);
    for (i = 0; i < *(s32 *)(player + 0xA8); i++) {
        c = &(*(Coll_8013C288 **)(player + 0xA4))[i];
        if (c == NULL) {
            continue;
        }
        c->flags &= ~0x10000000;
        ((TMainCursor *)player)->set_flag_bit(i, ((TObjBase *)target)->get_entity_id());
        if (!(c->flags & 1)) {
            continue;
        }
        if (!(c->flags & ((TMainCursor *)cursor)->get_body_include_mask())) {
            continue;
        }
        if (c->flags & ((TMainCursor *)cursor)->get_body_exclude_mask()) {
            continue;
        }
        dist = horizontal_distance_squared((const Vec *)(cursor + 0x1C), (const Vec *)c->pos);
        if (!(c->flags & 0x22000) && best->candidate_target_dist > dist) {
            best->candidate_target_dist = dist;
            best->candidate_target_id = ((TObjBase *)player)->get_entity_id();
            best->candidate_part_index = i;
        }
        {
            f32 r = *(f32 *)(cursor + 0x28) + c->radius;
            if (dist > r * r) {
                continue;
            }
        }
        if (TTecCtrl::is_technique_ready() != 0 && (c->flags & 0xA000) &&
            ((u32 (*)(u8 *, void *, s32))init_target_vector__11TMainCursorFiii)(cursor, c->pos, *(s32 *)(target + 0xA4) + 0x1C) != 0) {
            continue;
        }
        if (target_in_xz_cone((Vec *)(cursor + 0x1C), (Vec *)c->pos, (Vec *)(target + 0x38), yaw,
                              *(f32 *)(cursor + 0x2C), *(f32 *)(cursor + 0x3C)) == 0) {
            continue;
        }
        if (target_in_vertical_cone((Vec *)(cursor + 0x1C), (Vec *)c->pos, yaw, *(f32 *)(cursor + 0x30),
                                      *(f32 *)(cursor + 0x3C)) == 0) {
            continue;
        }
        if (*(f32 *)(cursor + 0x18) < dist) {
            *(f32 *)(cursor + 0x18) = dist;
        }
        if (TMainCursor__sub_8013F168(cursor + 0x40) >= 10) {
            for (j = 0; j <= TMainCursor__sub_8013F168(cursor + 0x40); j++) {
                if (*(f32 *)(cursor + 0x18) == TMainCursor__sub_8013F14C((void *)TMainCursor::get_record_at(cursor + 0x40, j))) {
                    *(f32 *)(cursor + 0x18) = dist;
                    slot = j;
                    break;
                }
            }
        } else {
            slot = TMainCursor__sub_8013F168(cursor + 0x40);
            TMainCursor__sub_8013F13C((s32 *)(cursor + 0x40));
        }
        ((TMainCursor *)TMainCursor::get_record_at(cursor + 0x40, slot))->set_size(dist);
        ((TMainCursor *)(TMainCursor::get_record_at(cursor + 0x40, slot)))->set_field2(i);
        set_cursor_id__11TMainCursorFs((void *)TMainCursor::get_record_at(cursor + 0x40, slot), ((TObjBase *)player)->get_entity_id());
        found = 1;
    }
    return found;
}

void init_target_vector__11TMainCursorFiii(s32 arg0, s32 to, s32 from) {
    csnVector(from, to, 0x28A0);
}

}

#pragma push
#pragma fp_contract on

extern "C" {

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

}
#pragma pop

extern "C" {

s32 try_move__11TMainCursorFiii(saddr cursor, u8 type, u8 enabled) {
    if (((TMainCursor *)cursor)->is_channel_active() != 0) {
        return matches_type_and_enabled(reinterpret_cast<const ActionPaletteTag *>(cursor), type, enabled);
    }
    return 0;
}

}

int check_type_and_enabled(const ActionPaletteTag *tag, u8 type, u8 enabled) { return matches_type_and_enabled(tag, type, enabled); }

TMainCursor::TMainCursor(TObject *parent, saddr target_index, s32 target_id, s32 action_palette, s32 active,
                         u16 offset_y, f32 size)
    : TObject(parent) {
    m_name = main_cursor_class_name;
    set_target_index_at_60((void *)target_index);
    set_target_id_at_60(target_id);
    sub_8013E724(size);
    set_cursor_action_palette_mode(this, action_palette);
    init_field_60(active);
    set_offset_y__11TMainCursorFs((void *)this, offset_y);
}

TMainCursor::~TMainCursor() {}

void TMainCursor::refresh_target_marker() {
    saddr temp_r3;
    s32 temp_r3_2;
    temp_r3 = check_field_24();
    if (temp_r3 == 0) {
        queue_destruction();
        return;
    }
    temp_r3_2 = check_visible__11TMainCursorFv((void *)(temp_r3 + 0x500), (void *)temp_r3, update_sub_60(), (u8) this->forward_13E338_at_60());
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
        get_rader_map__11TMainCursorFv((void *) (((u8 *)this) + 0x4C), (void *)target_cursor_color_table[4]);
        return;
    }
    get_rader_map__11TMainCursorFv((void *) (((u8 *)this) + 0x4C), (void *)target_cursor_color_table[temp_r3_2]);
}

void TMainCursor::update_position() {
    saddr arg0 = (saddr)this;
    void *entity;

    entity = find_entity_by_id(((TMainCursor *)(arg0 + 0x60))->get_id());
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
        f32 distance = ((TMainCursor *)(arg0 + 0x4C))->get_pos() - 0.2f;
        if (distance > TMainCursor__data_805DB0C0) {
            TMainCursor__sub_8013F180((u8 *)&this->unk_4c, distance);
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
        cam = TCameraCtrl::get_split_screen_view_index(((TMainCursor *)arg0)->get_render_flag());
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
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(shared_effect_texture_list));
    render__11TMainCursorFPv((TMainCursor *)arg0);
}

#pragma push
#pragma opt_common_subs off

void TMainCursor::validate_target() {
    Target_8013B70C *t;
    ((FlagWord *)(((u8 *)this) + 0x20))->clear(0xB);
    t = (Target_8013B70C *)this->check_field_24();
    if (t == NULL) {
        this->update_target_sub();
        return;
    }
    if (t->f424 == NULL) {
        this->update_target_sub();
        return;
    }
    if (((TMainCursor *)(((u8 *)this) + 0x60))->is_same_target(((TMainCursor *)(t->f424 + 0x4EC))->get_list()) == 0) {
        this->update_target_sub();
        return;
    }
    if (TMainCursor__sub_8013E358(((u8 *)this) + 0x60) != 1) {
        if (check_visible__11TMainCursorFv((u8 *)t + 0x500, t, TMainCursor__sub_8013E358(((u8 *)this) + 0x60),
                                            TMainCursor__sub_8013E338(((u8 *)this) + 0x60)) == -1) {
            set_target_index__11TMainCursorFs(t->f424 + 0x4F8, 0xFFFF);
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
        if (((TObjPlayer *)t)->can_perform_physical_action() == 0) {
            this->update_target_sub();
            return;
        }
        return;
    case 3:
        if (TObjPlayer::is_invalid_slot(get_cast_technique_level((u8 *)t + 0x428, TMainCursor__sub_8013E338(((u8 *)this) + 0x60))) != 0) {
            this->update_target_sub();
            return;
        }
        if (((TObjPlayer *)t)->is_controls_locked() == 0 && ((TObjCollidable *)t)->test_actor_flags(0x20006) != 0) {
            this->update_target_sub();
            return;
        }
        if (((TObjPlayer *)t)->test_action_mask(0x548000) != 0) {
            this->update_target_sub();
            return;
        }
        if (is_current_area_item_enabled() == 0) {
            this->update_target_sub();
            return;
        }
        if (t->f32E - (calc_technique_parameters(TMainCursor__sub_8013E338(((u8 *)this) + 0x60),
                                                      get_cast_technique_level((u8 *)t + 0x428, TMainCursor__sub_8013E338(((u8 *)this) + 0x60)),
                                                      ((TObjBase *)t)->get_entity_id()))->tp_cost < 0) {
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
        if (((TObjPlayer *)t)->test_action_mask(0x548000) != 0) {
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
    uaddr temp_r3b;
    saddr arg0 = (saddr)this;

    entity = (saddr)find_entity_by_id(((TMainCursor *)(arg0 + 0x60))->get_id());
    if ((entity != 0) && ((u32) (((TObjCollidable *)entity)->test_actor_flags(0x80000000) + 0x80000000) == 0U) && ((temp_r3b = ((TMainCursor *)arg0)->check_field_24()) != 0U) && (((TObjPlayer *)temp_r3b)->can_pickup_item_by_id((TItem *)entity) == 0)) {
        return 1;
    }
    return 0;
}

extern "C" {

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
    if (((TMainCursor *)(arg0 + 0x4C))->get_pos() > 0.99999f) {
        save_model_draw_state((void*)(arg0 + 0x4C));
        begin_constant_color_draw_argb((void *)(arg0 + 0x4C), 1.0f, TMainCursor__data_805DB0C0, TMainCursor__data_805DB0C0, TMainCursor__data_805DB0C0);
        TMainCursor::get_cursor_state();
        draw_chunk_object();
        restore_model_draw_state((void*)(arg0 + 0x4C));
    }
}

extern "C" {

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
        return can_start_technique__10TObjPlayerFPvi(player, parameter);
    default:
        return 0;
    }
}

}

void TMainCursor::reset_state() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)&this->unk_24 = (f32) TMainCursor__data_805DB0C0;
    *(f32 *)&this->unk_20 = (f32) TMainCursor__data_805DB0C0;
    *(f32 *)&this->m_1c = (f32) TMainCursor__data_805DB0C0;
    *(f32 *)&this->unk_28 = (f32) TMainCursor__data_805DB0C0;
    this->m_2c = (f32) TMainCursor__data_805DB0C0;
    *(f32 *)&this->unk_30 = (f32) TMainCursor__data_805DB0C0;
    this->m_34 = 0;
    *(s32 *)&this->unk_38 = 0;
    this->m_3c = (f32) TMainCursor__data_805DB0C0;
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) TMainCursor__data_805DB0C0;
    ((TMainCursor *)arg0)->set_type(0);
    clear_target_cursor_list((u8 *)&this->m_40);
    ((TMainCursor *)(arg0 + 0x9C))->reset_slot();
}

extern "C" {

void copy_action_entry(void *arg0, void *arg1) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
}

}

s32 TMainCursor::sort_actions_by_priority() {
    s32 k;
    s32 n;
    s32 i;
    Ent_8013B2C8 *p;
    Ent_8013B2C8 *q;
    TUnk_8013E2B0 tmp;
    if ((Ent_8013B2C8 *)((TMainCursor *)this)->get_index() == NULL) {
        return 0;
    }
    n = TMainCursor__sub_8013E2A0(this);
    while (--n > 0) {
        p = (Ent_8013B2C8 *)((TMainCursor *)this)->get_index();
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

extern "C" {

TObjPlayer *resolve_player_by_client_id(u16 *client_id) {
    return get_player_by_client_id(*client_id);
}

}

TLOC_Start::TLOC_Start(TObject *parent, u16 id) : TUnk_804A7260(parent, id) { m_name = TLOC_Start__name; }

TLOC_Start::~TLOC_Start() {
    if ((TObjPlayer__sub_801C6DAC((u8 *)&m_target) != 0) && (*(u32 *)((s8 *)((TMainCursor *)&m_target)->get_state() + 0x424) != 0U)) {
        ((TLockOnCursor *)*(saddr *)((s8 *)((TMainCursor *)&m_target)->get_state() + 0x424))->set_start_task(NULL);
    }
}

void TLOC_Start::run_task() {
    saddr arg0 = (saddr)this;
    Pl_8013B0F0 *pl;
    Cur_8013B0F0 *cur;
    s32 i;
    pl = (Pl_8013B0F0 *)get_player_by_client_id((s32)(get_client_id((void *)(arg0 + 0x1C))));
    if (pl == NULL) {
        return;
    }
    cur = pl->cur;
    if (cur == NULL) {
        return;
    }
    cur->nearest_target.reset();
    ((TMainCursor *)(cur->pos))->update_cursor_pos();
    set_target_index__11TMainCursorFs(cur->target, 0xFFFF);
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
    if ((TObjPlayer__sub_801C6DAC((u8 *)&m_target) != 0) && (*(u32 *)((s8 *)((TMainCursor *)&m_target)->get_state() + 0x424) != 0U)) {
        ((TLockOnCursor *)*(saddr *)((s8 *)((TMainCursor *)&m_target)->get_state() + 0x424))->set_end_task(NULL);
    }
}

#pragma defer_codegen off

extern "C" {

void TObjPlayer__sub_8013DEF8(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 2) = (s16) (*(s16 *)((s8 *)arg0 + 2) | 1);
}

}

s32 TMainCursor::is_channel_active() {
    u8 *arg0 = (u8 *)this;
    return (u8)((u8) ((*(s16 *)((s8 *)arg0 + 2) & 1) ^ 1));
}

int TMainCursor::check_visible() { return find_action_slot_for_target__11TMainCursorFllll(this); }

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

extern "C" {

void TMainCursor__sub_8013DFC4(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 2) = (s16) (*(s16 *)((s8 *)arg0 + 2) & 0xFFFFFFFE);
}

}

saddr TMainCursor::get_state() { return *(saddr *)&this->m_flags; }

TUnk_8013E020::~TUnk_8013E020() {}

void TUnk_8013E020::set_field_0(u16 v) { a = v; }

TUnk_8013E020::TUnk_8013E020() {
    a = b = 0xffff;
    c = 0;
}

extern "C" {

u16 get_client_id(void* p) { return *(u16*)((char*)p + 0x0); }

}

TUnk_804A7260::~TUnk_804A7260() {}

void TLockOnCursor::set_list_clear_task(TObject *task) { tasks.set_list_clear_task(task); }

void TUnk_8013F08C::set_list_clear_task(TObject *task) { list_clear_task = task; }

TUnk_804A7260::TUnk_804A7260(TObject *parent, u16 id) : TObject(parent) {
    disallow_rendering();
    m_target.set_field_0(id);
}

void TUnk_8013EF0C::publish() {
    set_published_target_id(get_candidate_target_id());
    set_published_target_dist(get_candidate_target_dist());
}

void TUnk_8013EF0C::set_published_target_dist(f32 dist) { published_target_dist = dist; }

f32 TUnk_8013EF0C::get_candidate_target_dist() { return candidate_target_dist; }

void TUnk_8013EF0C::set_published_target_id(u16 id) { published_target_id = id; }

u16 TUnk_8013EF0C::get_candidate_target_id() { return candidate_target_id; }

void TLockOnCursor::set_end_task(TObject *task) { tasks.set_end_task(task); }

void TUnk_8013F08C::set_end_task(TObject *task) { end_task = task; }

void TMainCursor::set_target_index(s16 v) { this->m_flags = v; }

void TMainCursor::update_cursor_pos() { ((TMainCursor *)((char*)this + 0x14))->copy_from((char*)this + 0xc); }

void*TMainCursor::copy_from(void* a1) { TObjPlayer__sub_8013A820(this); this->m_flags = *(unsigned short*)((char*)a1 + 0x4); this->m_id = *(short*)((char*)a1 + 0x6); return this; }

void TUnk_8013EF0C::reset() {
    candidate_part_index = 0;
    published_target_id = 0xffff;
    candidate_target_id = 0xffff;
    published_target_dist = TMainCursor__data_805DB0C0;
    candidate_target_dist = lbl_805DB0C4;
}

void TLockOnCursor::set_start_task(TObject *task) { tasks.set_start_task(task); }

void TUnk_8013F08C::set_start_task(TObject *task) { start_task = task; }

extern "C" {

s16 TMainCursor__sub_8013E298(void* p) { return *(s16*)((char*)p + 0x0); }

s32 TMainCursor__sub_8013E2A0(void* p) { return *(s32*)((char*)p + 0x0); }

}

saddr TMainCursor::get_index() { return *(s32 *)&this->m_flags; }

TUnk_8013E2B0::TUnk_8013E2B0() { unk_2 = 0; unk_0 = 0; }

void TMainCursor::reset_slot() { this->m_name = 0; }

void TMainCursor::set_type(s32 v) { *(s32 *)&this->m_flags = v; }

int TMainCursor::get_cursor_state() {  return main_cursor_model; }

extern "C" {

int TMainCursor__get_lock_on_cursor_model(void) {  return lock_on_cursor_model; }

}

saddr TMainCursor::check_field_24() { return (saddr)resolve_player_by_client_id((u16 *)((char*)this + 0x24)); }

u16 TMainCursor::get_id() { return this->m_flags; }

extern "C" {

void TMainCursor__sub_8013E310(void* p) { ((FlagWord *)((char*)p + 0x20))->set(2); }

u8 TMainCursor__sub_8013E338(void* p) { return get_action_palette_tag_slot(static_cast<const ActionPaletteTag *>(p)); }

u8 TMainCursor__sub_8013E358(void* p) { return get_action_palette_tag_mode(static_cast<const ActionPaletteTag *>(p)); }

}

int TMainCursor::is_same_target(void *b) {
    u8 result = 0;
    if (matches_id((TMainCursor *)this, ((TMainCursor *)b)->get_id()) != 0) {
        if (get_action_palette_tag_mode(reinterpret_cast<const ActionPaletteTag *>(this)) == get_action_palette_tag_mode(static_cast<const ActionPaletteTag *>(b))) {
            if (get_action_palette_tag_slot(reinterpret_cast<const ActionPaletteTag *>(this)) == get_action_palette_tag_slot(static_cast<const ActionPaletteTag *>(b))) {
                result = 1;
            }
        }
    }
    return result;
}

extern "C" {

int matches_id(TMainCursor *main_cursor, u16 arg1) {
    return (u8) (arg1 == main_cursor->get_id());
}

}

void*TMainCursor::get_list() { return (char*)this + 0xc; }

void TMainCursor::update_target_sub() { ((FlagWord *)((char*)this + 0x20))->set(1); }

u16 TMainCursor::get_render_flag() { return TMainCursor__sub_8013E4A0((char*)this + 0x24); }

extern "C" {

u16 TMainCursor__sub_8013E4A0(void* p) { return *(u16*)((char*)p + 0x0); }

}

int TMainCursor::test_flag_2_at_20() { return test_flags_any((s32 *)((char*)this + 0x20), 2); }

int TMainCursor::init_render_flags() { return test_flags_any((s32 *)((char*)this + 0x20), 8); }

int TMainCursor::update() { return test_flags_any((s32 *)((char*)this + 0x20), 4); }

int TMainCursor::check_flag_1() { return test_flags_any((s32 *)((char*)this + 0x20), 1); }

u8 TMainCursor::is_position_moved() { return (u8)(TMainCursor__sub_8013E570((char*)this + 0x60)); }

extern "C" {

s16 TMainCursor__sub_8013E570(void* p) { return *(s16*)((char*)p + 0x6); }

}

void TMainCursor::check_flag_4() { ((FlagWord *)((char*)this + 0x20))->set(4); }

u8 TMainCursor::forward_13E338_at_60() { return TMainCursor__sub_8013E338((char*)this + 0x60); }

u8 TMainCursor::update_sub_60() { return TMainCursor__sub_8013E358((char*)this + 0x60); }

TUnk_8013E800::~TUnk_8013E800() {}

TUnk_8013E780::~TUnk_8013E780() {}

void TMainCursor::set_offset_y(s16 offset_y) { TMainCursor__sub_8013E694((char*)this + 0x24, offset_y); }

void TMainCursor__sub_8013E694(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }

void TMainCursor::init_field_60(u8 slot) { set_cursor_palette_slot(&unk_60.unk_0, slot); }

void set_cursor_palette_slot(ActionPaletteTag *tag, u8 slot) { set_action_palette_tag_slot(tag, slot); }

void set_cursor_action_palette_mode(TMainCursor *cursor, u8 mode) { set_cursor_palette_mode(&cursor->unk_60.unk_0, mode); }

void set_cursor_palette_mode(ActionPaletteTag *tag, u8 mode) { set_action_palette_tag_mode(tag, mode); }

void TMainCursor::sub_8013E724(f32 v) { this->m_2c = v; }

void TMainCursor::set_target_id_at_60(u8 target_id) {
    saddr arg0 = (saddr)this;
    ((TMainCursor *)(arg0 + 0x60))->set_target_id(target_id);
}

void TMainCursor::set_target_id(s16 v) { this->m_id = v; }

int TMainCursor::set_target_index_at_60(void* target_index) { return set_target_index__11TMainCursorFs((void*)((char*)this + 0x60), (saddr)target_index); }

TUnk_8013E780::TUnk_8013E780() {
    reset_target();
}

void TUnk_8013E780::reset_target() {
    unk_0.init();
    set_target_index__11TMainCursorFs((void *)this, 0xFFFF);
    ((TMainCursor *)this)->set_target_id(0);
}

TUnk_8013E800::TUnk_8013E800() {
    unk_0 = 0xffff;
}

s32 TMainCursor::get_body_exclude_mask() { return *(s32 *)&this->m_next; }

s32 TMainCursor::get_body_include_mask() { return *(s32 *)&this->m_prev; }

s32 TMainCursor::get_actor_exclude_mask() { return *(s32 *)&this->m_down; }

s32 TMainCursor::get_actor_include_mask() { return *(s32 *)&this->m_up; }

void TMainCursor::store_sorted_record(void* p, void* a1, void* a2) { ((int (*)(void *))copy_target_record__11TMainCursorFPvPv)(a2); }

void copy_target_record__11TMainCursorFPvPv(u8 *arg0, u8 *arg1) {
    *(u16 *)((s8 *)arg0 + 0) = (u16) *(u16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(f32 *)((s8 *)arg0 + 4) = (f32) *(f32 *)((s8 *)arg1 + 4);
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

void set_cursor_count(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }

int TLockOnCursor::render_part() { return test_flags_any((s32 *)((char*)this + 0x8), 2); }

int TLockOnCursor::update_cursor_pos() { return ((TMainCursor *)((char*)this + 0xc))->is_same_target((char*)this + 0x14); }

void TLockOnCursor::set_flag_8_bit0() { ((FlagWord *)((char*)this + 0x8))->set(1); }

void TLockOnCursor::update_ring() { ((FlagWord *)((char*)this + 0x8))->clear(1); }

void TLockOnCursor::is_bit1_set() { ((FlagWord *)((char*)this + 0x8))->set(2); }

int TLockOnCursor::is_inactive() { return (test_flags_any(&this->flags.bits, 2)) == 0; }

void TLockOnCursor::update_ring_sub() { ((FlagWord *)((char*)this + 0x8))->clear(2); }

extern "C" {

s32 TLockOnCursor__sub_8013EB2C(void* p) { return *(s32*)((char*)p + 0x4); }

int TLockOnCursor__sub_8013EB34(void) {  return TLockOnCursor__target_cursor_model; }

}

int TLockOnCursor::test_flag_1_at_8() { return test_flags_any((s32 *)((char*)this + 0x8), 1); }

s32 TLockOnCursor::get_target() { return *(s32 *)&this->m_name; }

extern "C" {

Rec_8013EB6C *TLockOnCursor__record_at(Obj_8013EB6C *self, s32 i) {
    return &self->recs[i];
}

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

void TUnk_8013EF6C::reset_state() {
    target.reset_target();
    unk_14.reset_target();
    unk_8.init();
    unk_0 = 0xffff;
    unk_2 = 0;
    unk_4 = TMainCursor__data_805DB0C0;
}

TUnk_8013F114::~TUnk_8013F114() {}

TUnk_8013F08C::~TUnk_8013F08C() {}

LockOnActionSlot::~LockOnActionSlot() {
    destroy_target_records((saddr)&target_records, -1);
}

s32 destroy_target_records(saddr arg0, s16 arg1) {
    if (arg0 != 0) {
        __destroy_arr((void *)(arg0 + 0x4), (void *)destroy_target_record, 0xc, 0xb);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

s32 destroy_target_record(saddr obj, s16 flags) {
    if ((obj != 0) && (flags > 0)) {
        ::operator delete((void *)obj);
    }
    return obj;
}

TUnk_8013EF6C::~TUnk_8013EF6C() {}

#pragma defer_codegen on

TUnk_804A7254::~TUnk_804A7254() {}

int TMainCursor::get_rader_map() { return ((int (*)(void *))copy_argb)(this); }

extern "C" {

void TMainCursor__sub_8013F180(void* p, f32 v) { *(f32*)((char*)p + 0x0) = v; }

}

f32 TMainCursor::get_pos() { return *(f32 *)&this->m_name; }

extern "C" {

void TMainCursor__sub_8013F170(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }

s32 TMainCursor__sub_8013F168(void* p) { return *(s32*)((char*)p + 0x0); }

void *TMainCursor::get_record_at(void *self, int i) {
    return &((Obj_8013F154 *)self)->recs[i];
}

f32 TMainCursor__sub_8013F14C(void* p) { return *(f32*)((char*)p + 0x4); }

void TMainCursor__sub_8013F13C(s32 *arg0) {
    *arg0 += 1;
}

}

void TMainCursor::set_size(f32 v) { *(f32 *)&this->m_flags = v; }

void TMainCursor::set_field2(s16 v) { *(s16*)((char*)this + 0x2) = v; }

void TMainCursor::set_cursor_id(s16 v) { *(s16 *)&this->m_name = v; }

TUnk_8013F114::TUnk_8013F114() { unk_0 = 0; unk_4 = 0; }

extern "C" {

void TMainCursor__sub_8013F10C(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }

void TMainCursor__sub_8013F104(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }

}

TUnk_8013F0A0::TUnk_8013F0A0() {
    TMainCursor__sub_8013F10C(this, 4);
    TMainCursor__sub_8013F104(this, (saddr)unk_8);
}

TUnk_8013F08C::TUnk_8013F08C() { start_task = NULL; end_task = NULL; list_clear_task = NULL; }

extern "C" {

void* TLockOnCursor::init_sub(void* p) { __ct__18TargetCursorRecordFv(p); __ct__8FlagWordFv(((char*)p + 0x8)); return p; }

int TLockOnCursor__sub_8013F000(void *self) {
    __construct_array((char *)self + 4, (void *)TLockOnCursor::init_sub, (void *)destroy_target_record, 0xc, 0xb);
    ((TMainCursor *)self)->reset_slot();
    return (saddr)self;
}

}

LockOnActionSlot::LockOnActionSlot() {
    __ct__16TargetCursorListFv(target_list);
    TLockOnCursor__sub_8013F000(&target_records);
    ((TMainCursor *)this)->reset_state();
}

TUnk_8013EF6C::TUnk_8013EF6C() { reset_state(); }

TUnk_8013EF3C::TUnk_8013EF3C() { TLockOnCursor__sub_8013EC1C(this); }

TUnk_8013EF0C::TUnk_8013EF0C() { reset(); }

TUnk_804A7248::TUnk_804A7248() {
    unk_4 = 0;
}

void TLockOnCursor::sub_8013EEC0(u16 target_id) { this->target_id = target_id; }

TUnk_804A7248::~TUnk_804A7248() {}

#pragma defer_codegen off

TUnk_804A7254::TUnk_804A7254() {
    TMainCursor__sub_8013F22C(this);
}

extern "C" {

void TMainCursor__sub_8013F22C(void* a0) { *(float*)((char*)a0 + 0xc) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x8) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x4) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x0) = TMainCursor__data_805DB0C0; }

int TMainCursor__sub_8013F244(void) { return -1; }

u8 fn_8013F24C(Obj_8013F24C *self, s16 i) {
    return self->arr[i];
}

}

int TCameraCtrl::get_mode() {  return fixed_npc_camera_active; }
