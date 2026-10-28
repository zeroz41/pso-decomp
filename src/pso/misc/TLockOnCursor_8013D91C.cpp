#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TLockOnCursor.h"
#include "pso/system/memory.h"

#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TMainCursor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8013DC38_lbl_804A7140 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8013DC38_lbl_804A7140_size[sizeof(RecoveredGlobal_8013DC38_lbl_804A7140) == 0x10 ? 1 : -1];

struct Base_8013DCCC { u8 pad[0x18]; };

struct Obj_8013DCCC : Base_8013DCCC {
    virtual ~Obj_8013DCCC();
};

struct Obj_8013DCCC;
struct Elem_8013DAB0 { u8 b[0x124]; };

struct Cur_8013DAB0 { u8 pad[0x5C]; Elem_8013DAB0 arr[4]; };

struct Ent_8013D91C { u16 id; s16 idx; u8 pad[8]; };

struct RecoveredGlobal_8013D91C_main_task {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
u8 * TLobby__sub_8001FE7C(void *, s16);
extern u8 *lock_on_cursor_bml_resource;
extern s32 lock_on_cursor_model;
extern s32 TLockOnCursor__target_cursor_model;
s32 get_bml_model(void *, s32);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8013DC38_lbl_804A7140 target_cursor_resource_descriptor;
extern s32 main_cursor_model;
void load_target_cursor_models(void);
Obj_8013DCCC *release_target__13TLockOnCursorFv(void *);
Obj_8013DCCC *cleanup_field__13TLockOnCursorFv(void *);
Obj_8013DCCC *cleanup_field_3c__13TLockOnCursorFv(void *);
s32 __dt__13TLockOnCursorFis(s32 arg0, s16 arg1);
s32 destroy__13TLockOnCursorFis(s32 arg0, s16 arg1);
void __destroy_arr(void *, void *, int, int);
extern s32 __dt_deleting__13TLockOnCursorFis[];
extern s32 __vt__13TLockOnCursor[];
s32 init_lockon__14TLOC_ListClearFv(s32, s32, s32);
s32 init_vtable__8TLOC_EndFv(s32, s32, s32);
s32 init__10TLOC_StartFv(s32, s32, s32);
s32 reset_nearest_target_record(s32);
s32 get_target_id__13TLockOnCursorFv(s32);
s32 TLockOnCursor__sub_8013EC1C(s32);
s32 __nw__7TObjectFUl(s32);
extern s32 tl_loc_start;
extern s32 tl_loc_end;
extern s32 tl_window;
s32 is_split_screen();
s32 get_split_screen_view_index__11TCameraCtrlFUs(void *);
s32 get_mode__11TCameraCtrlFPv(void *);
Ent_8013D91C *TObjPlayer__sub_80116620(s32, s32);
u8 get_active__11TMainCursorFv(int);
u8 TMainCursor__sub_8013E900(int);
s32 TLockOnCursor__sub_8013EB6C(void *, int);
u8 *find_entity_by_id(u16);
void render__13TLockOnCursorFv(s32 arg0);
struct VOff_8013DE3C_arg0_8013D91C { char pad_0[0x1C]; char f_1C[1]; };

void *TLockOnCursor__ct(void *arg0, void *arg1, void *arg2);
void TLockOnCursor__sub_8013EB80(void *p);
void TLockOnCursor__sub_8013EB8C(void *p);
void sub_8013EEC0__13TLockOnCursorFs(void *, void *);
s32 is_channel_active__11TMainCursorFv(s32);
u8 *TMainCursor__sub_8013F1F0(u8 *arg0);
void __construct_array(void *, void *, void *, int, int);
void __ct__7TObjectFP7TObject(void *);
void *fn_8013F0A0(void *arg0);

#pragma push
#pragma opt_loop_invariants off
typedef char RecoveredGlobal_8013D91C_main_task_size[sizeof(RecoveredGlobal_8013D91C_main_task) == 0x34 ? 1 : -1];
void render__13TLockOnCursorFv(s32 arg0) {
    s32 i;
    s32 j;
    u8 *c;
    s32 n;
    Ent_8013D91C *p;
    s32 e;
    u8 *o;
    if (is_split_screen() != 0) {
        if (TCameraCtrl::get_camera_no() != get_split_screen_view_index__11TCameraCtrlFUs((void *)((s32)get_target_id__13TLockOnCursorFv((s32)((void *)arg0))))) {
            return;
        }
    } else if (get_mode__11TCameraCtrlFPv(&(*(RecoveredGlobal_8013D91C_main_task *)&main_task).value) & 0x10) {
        return;
    }
    for (i = 0; i < 4; i++) {
        c = (u8 *)TLockOnCursor__sub_8013EB6C((void *)arg0, i);
        if (((TMainCursor *)c)->get_selected_entry() != 0) {
            n = ((TLockOnCursor *)(c + 0x9C))->get_target();
            for (p = TObjPlayer__sub_80116620((s32)(c + 0x9C), 0), j = 0; j < n; j++, p++) {
                if (((TLockOnCursor *)p)->test_flag_1_at_8() == 0 &&
                    ((TLockOnCursor *)p)->render_part() == 0 &&
                    ((TObjPlayer *)p)->get_type_id() != 0xFFFF) {
                    o = find_entity_by_id(p->id);
                    if (o != NULL) {
                        e = *(s32 *)(o + 0xA4) + p->idx * 0x2C;
                        if (e != 0) {
                            ((TLockOnCursor *)arg0)->renderSecondaryCursor((u8*)e, (s32)(TMainCursor__sub_8013E900((int)c)), (s32)(get_active__11TMainCursorFv((int)c)));
                        }
                    }
                }
            }
        }
    }
}
#pragma pop

void TLockOnCursor::run_task() {
    s32 arg0 = (s32)this;
    if (is_channel_active__11TMainCursorFv(arg0 + 0x520) != 0) {
        TLockOnCursor__sub_8013EB8C((void *)(arg0 + 0x520));
        return;
    }
    TLockOnCursor__sub_8013EB80((void *)(arg0 + 0x520));
}

void TLockOnCursor::reset_and_spawn_cursors() {
    s32 var_r31_2;
    s32 var_r31_3;
    s32 var_r31_4;
    s32 i;
    s32 arg0 = (s32)this;
    ((FlagWord *)(arg0 + 0x1C))->reset();
    for (i = 0; i < 4; i++) {
        ((TMainCursor *)((s32)&((Cur_8013DAB0 *)arg0)->arr[i]))->reset_state();
    }
    ((TLockOnCursor *)(arg0 + 0x4EC))->reset_state();
    TLockOnCursor__sub_8013EC1C(arg0 + 0x508);
    reset_nearest_target_record(arg0 + 0x510);
    if (cleanup_field_3c__13TLockOnCursorFv((void *)arg0) == NULL) {
        var_r31_2 = __nw__7TObjectFUl(0x24);
        if (var_r31_2 != 0) {
            var_r31_2 = init__10TLOC_StartFv(var_r31_2, tl_loc_start, get_target_id__13TLockOnCursorFv(arg0));
        }
        ((TMainCursor *)arg0)->set_sub_cursor_value(var_r31_2);
    }
    if (cleanup_field__13TLockOnCursorFv((void *)arg0) == NULL) {
        var_r31_3 = __nw__7TObjectFUl(0x24);
        if (var_r31_3 != 0) {
            var_r31_3 = init_vtable__8TLOC_EndFv(var_r31_3, tl_loc_end, get_target_id__13TLockOnCursorFv(arg0));
        }
        ((TMainCursor *)arg0)->set_target(var_r31_3);
    }
    if (release_target__13TLockOnCursorFv((void *)arg0) == NULL) {
        var_r31_4 = __nw__7TObjectFUl(0x24);
        if (var_r31_4 != 0) {
            var_r31_4 = init_lockon__14TLOC_ListClearFv(var_r31_4, tl_window, get_target_id__13TLockOnCursorFv(arg0));
        }
        ((TMainCursor *)arg0)->destroy_lock_on(var_r31_4);
    }
}

void TLockOnCursor::free_cursor_resources() {
    if ((void *) lock_on_cursor_bml_resource != NULL) {
        TLobby__sub_8001FE7C(lock_on_cursor_bml_resource, 1);
        lock_on_cursor_bml_resource = NULL;
    }
    lock_on_cursor_model = 0;
    TLockOnCursor__target_cursor_model = 0;
}

void load_target_cursor_models(void) {
    s32 temp_r3;
    s32 var_r0;
    if ((void *) lock_on_cursor_bml_resource == NULL) {
        temp_r3 = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &target_cursor_resource_descriptor.value, 0, 0, 0));
        }
        lock_on_cursor_bml_resource = (unsigned char *) ((void *) var_r0);
        if ((u32) var_r0 != 0U) {
            lock_on_cursor_model = get_bml_model((void *) var_r0, 0);
            TLockOnCursor__target_cursor_model = get_bml_model(lock_on_cursor_bml_resource, 0);
            main_cursor_model = get_bml_model(lock_on_cursor_bml_resource, 2);
        }
    }
}

}
TLockOnCursor::~TLockOnCursor() {
    Obj_8013DCCC *p;
    p = cleanup_field_3c__13TLockOnCursorFv(this);
    if (p != NULL) {
        delete p;
    }
    p = cleanup_field__13TLockOnCursorFv(this);
    if (p != NULL) {
        delete p;
    }
    p = release_target__13TLockOnCursorFv(this);
    if (p != NULL) {
        delete p;
    }
    ((TLockOnCursor *)(((u8 *)this) + 0x520))->destroy(-1);
    destroy__13TLockOnCursorFis((s32)(((u8 *)this) + 0x4EC), -1);
    __destroy_arr(((u8 *)this) + 0x5C, __dt_deleting__13TLockOnCursorFis, 0x124, 4);
    ((TMainCursor *)(((u8 *)this) + 0x48))->destroy(-1);
    __dt__13TLockOnCursorFis((s32)(((u8 *)this) + 0x3C), -1);
    TLockOnCursor::dt((s32)(((u8 *)this) + 0x24), -1);
}


s32 TLockOnCursor::dt(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        TLockOnCursor::free_if_owned(arg0, 0);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

extern s32 TLockOnCursor__sub_8013EFB8[];
extern void *lock_on_cursor_class_name;

void *TLockOnCursor__ct(void *lock_on_cursor, void *arg1, void *arg2) {
    struct VOff_8013DE3C_arg0_8013D91C *self = (struct VOff_8013DE3C_arg0_8013D91C *)lock_on_cursor;
    __ct__7TObjectFP7TObject(lock_on_cursor);
    *(s32 **)((s8 *)lock_on_cursor + 0x18) = __vt__13TLockOnCursor;
    __ct__8FlagWordFv((self->f_1C));
    fn_8013F0A0(((char *)lock_on_cursor + 36));
    ((TLockOnCursor *)((char *)lock_on_cursor + 60))->reset_fields();
    TMainCursor__sub_8013F1F0((u8 *)((char *)lock_on_cursor + 72));
    __construct_array((void *)((char *)lock_on_cursor + 92), TLockOnCursor__sub_8013EFB8, __dt_deleting__13TLockOnCursorFis, 292, 4);
    ((TLockOnCursor *)((char *)lock_on_cursor + 1260))->cleanup();
    ((TLockOnCursor *)((char *)lock_on_cursor + 1288))->init_forward();
    ((TLockOnCursor *)((char *)lock_on_cursor + 1296))->init_cursor();
    ((TLockOnCursor *)((char *)lock_on_cursor + 1312))->init_vtable();
    *(void * *)&((TLockOnCursor *)lock_on_cursor)->m_name = lock_on_cursor_class_name;
    sub_8013EEC0__13TLockOnCursorFs(lock_on_cursor, arg2);
    ((FlagWord *)(self->f_1C))->reset();
    return lock_on_cursor;
}

