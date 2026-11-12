#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/system/memory.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/hud/TMainCursor_8013DEF8.h"
#include "pso/player/TForceOperate.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/hud/TLockOnCursor_8013E0D0.h"
#include "pso/ui/hud/TMainCursor_8013DF5C.h"

#include "pso/unk/TUnk_804A7260.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/ui/hud/TMainCursor_8013E17C.h"
#include "pso/ui/hud/TMainCursor_8013E1C8.h"
#include "pso/ui/hud/TMainCursor_8013E2E4.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/ui/hud/TMainCursor_8013E44C.h"
#include "pso/ui/hud/TMainCursor_8013E47C.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/hud/TMainCursor_8013E624.h"
#include "pso/player/TPlyDispConfig_80071F1C.h"
#include "pso/ui/hud/TMainCursor_8013E7B8.h"
#include "pso/ui/hud/TLockOnCursor_8013EA08.h"
#include "pso/ui/hud/TLockOnCursor_8013EB80.h"
#include "pso/unk/text_80072004.h"
#include "pso/ui/hud/TLockOnCursor_8013ED0C.h"
#include "pso/ui/hud/TLockOnCursor_8013EDC4.h"
#include "pso/ui/hud/TLockOnCursor_8013EE00.h"
#include "pso/ui/hud/TLockOnCursor_8013EEC8.h"
#include "pso/ui/hud/TMainCursor_8013F104.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"

struct Obj_8013E240 { s32 a; u16 b; u16 c; f32 d; f32 e; };
struct Rec_8013EB6C { u8 pad[0x124]; };
struct Obj_8013EB6C { u8 pad[0x5c]; Rec_8013EB6C recs[1]; };
struct Obj_8013EC1C { u16 a; u16 b; u16 c; };

extern "C" void __dl__FPv(void *);

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
u8 * free_bin_model_request(void *, s16);
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
s32 __dt_deleting__13TLockOnCursorFis(s32, s16);
extern s32 __vt__13TLockOnCursor[];
s32 init_lockon__14TLOC_ListClearFv(s32, s32, s32);
s32 init_vtable__8TLOC_EndFv(s32, s32, s32);
s32 init__10TLOC_StartFv(s32, s32, s32);
void reset_nearest_target_record(void *);
s32 get_target_id__13TLockOnCursorFv(s32);
void TLockOnCursor__sub_8013EC1C(void *);
s32 __nw__7TObjectFUl(s32);
extern s32 tl_loc_start;
extern s32 tl_loc_end;
extern s32 tl_window;
s32 is_split_screen();
s32 get_split_screen_view_index__11TCameraCtrlFUs(void *);
s32 get_mode__11TCameraCtrlFPv(void *);
Ent_8013D91C *TObjPlayer__sub_80116620(s32, s32);
u8 get_active__11TMainCursorFv(int);

Rec_8013EB6C *TLockOnCursor__sub_8013EB6C(Obj_8013EB6C *, s32);
u8 *find_entity_by_id(u16);
void render__13TLockOnCursorFv(s32 arg0);
struct VOff_8013DE3C_arg0_8013D91C { char pad_0[0x1C]; char f_1C[1]; };

void *TLockOnCursor__ct(void *arg0, void *arg1, void *arg2);
void TLockOnCursor__sub_8013EB80(void *p);
void TLockOnCursor__sub_8013EB8C(void *p);
void sub_8013EEC0__13TLockOnCursorFs(void *, void *);
s32 is_channel_active__11TMainCursorFv(void *);
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
        c = (u8 *)TLockOnCursor__sub_8013EB6C((Obj_8013EB6C *)arg0, i);
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
                            ((TLockOnCursor *)arg0)->renderSecondaryCursor((u8*)e, (s32)(TMainCursor__sub_8013E900((void *)c)), (s32)(get_active__11TMainCursorFv((int)c)));
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
    if (is_channel_active__11TMainCursorFv((void *)(arg0 + 0x520)) != 0) {
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
    TLockOnCursor__sub_8013EC1C((void *)(arg0 + 0x508));
    reset_nearest_target_record((void *)(arg0 + 0x510));
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
        free_bin_model_request(lock_on_cursor_bml_resource, 1);
        lock_on_cursor_bml_resource = NULL;
    }
    lock_on_cursor_model = 0;
    TLockOnCursor__target_cursor_model = 0;
}

void load_target_cursor_models(void) {
    s32 temp_r3;
    s32 var_r0;
    if ((void *) lock_on_cursor_bml_resource == NULL) {
        temp_r3 = (int)::operator new(0x440);
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
    __destroy_arr(((u8 *)this) + 0x5C, (void *)__dt_deleting__13TLockOnCursorFis, 0x124, 4);
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

void *TLockOnCursor__sub_8013EFB8(void *);
extern const char *lock_on_cursor_class_name;

void *TLockOnCursor__ct(void *lock_on_cursor, void *arg1, void *arg2) {
    struct VOff_8013DE3C_arg0_8013D91C *self = (struct VOff_8013DE3C_arg0_8013D91C *)lock_on_cursor;
    __ct__7TObjectFP7TObject(lock_on_cursor);
    *(s32 **)((s8 *)lock_on_cursor + 0x18) = __vt__13TLockOnCursor;
    __ct__8FlagWordFv((self->f_1C));
    fn_8013F0A0(((char *)lock_on_cursor + 36));
    ((TLockOnCursor *)((char *)lock_on_cursor + 60))->reset_fields();
    TMainCursor__sub_8013F1F0((u8 *)((char *)lock_on_cursor + 72));
    __construct_array((void *)((char *)lock_on_cursor + 92), (void *)TLockOnCursor__sub_8013EFB8, (void *)__dt_deleting__13TLockOnCursorFis, 292, 4);
    ((TLockOnCursor *)((char *)lock_on_cursor + 1260))->cleanup();
    ((TLockOnCursor *)((char *)lock_on_cursor + 1288))->init_forward();
    ((TLockOnCursor *)((char *)lock_on_cursor + 1296))->init_cursor();
    ((TLockOnCursor *)((char *)lock_on_cursor + 1312))->init_vtable();
    ((TLockOnCursor *)lock_on_cursor)->m_name = lock_on_cursor_class_name;
    sub_8013EEC0__13TLockOnCursorFs(lock_on_cursor, arg2);
    ((FlagWord *)(self->f_1C))->reset();
    return lock_on_cursor;
}

extern "C" {
int find_action_slot_for_target__11TMainCursorFllll(void*);

void TObjPlayer__sub_8013DEF8(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 2) = (s16) (*(s16 *)((s8 *)arg0 + 2) | 1);
}

u8 TMainCursor::is_channel_active() {
    u8 *arg0 = (u8 *)this;
    return (u8) ((*(s16 *)((s8 *)arg0 + 2) & 1) ^ 1);
}

int TMainCursor::check_visible() { return find_action_slot_for_target__11TMainCursorFllll(this); }
u8 TMainCursor::get_enabled() { return *(u8*)((char*)this + 0x1); }
u8 TMainCursor::get_type() { return *(u8 *)&this->m_name; }

}

void TWindowActionPalette::set_slot(u8 v) { *(u8*)((char*)this + 0x1) = v; }
void TWindowActionPalette::set_mode(u8 v) { *(u8*)((char*)this + 0x0) = v; }


extern "C" {
void fn_8013E020(Obj_8013E020 *self);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void __ct__7TObjectFP7TObject(void *);
void set_field_0__13TForceOperateFs(void *, void *);

int matches_type_and_enabled__11TMainCursorFiUcUc(s32 arg0, u8 arg1, u8 arg2) {
    s32 var_r31;
    var_r31 = 0;
    if ((arg1 == ((TMainCursor *)arg0)->get_type()) && (arg2 == ((TMainCursor *)arg0)->get_enabled())) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}

void TMainCursor__sub_8013DFC4(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 2) = (s16) (*(s16 *)((s8 *)arg0 + 2) & 0xFFFFFFFE);
}

s32 TMainCursor::get_state() { return *(s32 *)&this->m_flags; }

s32 TForceOperate::destroy(s32 obj, s16 flags) {
    if ((obj != 0) && (flags > 0)) {
        __dl__FPv((void *)obj);
    }
    return obj;
}
void TForceOperate::set_field_0(s16 v) { *(s16 *)&this->m_name = v; }

void fn_8013E020(Obj_8013E020 *self) {
    self->a = self->b = 0xffff;
    self->c = 0;
}

u16 TMainCursor__sub_8013E03C(void* p) { return *(u16*)((char*)p + 0x0); }

extern s32 lbl_804A7260[];

void *TUnk_804A7260::destroy_cursor(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804A7260;
        TForceOperate::destroy((s32)((s8 *)this + 0x1C), (s16)(-1));
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void TMainCursor::destroy_lock_on(s32 a1) { TLockOnCursor__sub_8013E0D0((char*)this + 0x3c, a1); }

struct VOff_8013E0D8_arg0_8013e0d8_8013E0D0 { char pad_0[0x1C]; Obj_8013E020 f_1C; };

void TLockOnCursor__sub_8013E0D0(void* p, s32 v) { *(s32*)((char*)p + 0x8) = v; }

void *TUnk_804A7260::init(void *arg1, void *arg2) {
    struct VOff_8013E0D8_arg0_8013e0d8_8013E0D0 *self = (struct VOff_8013E0D8_arg0_8013e0d8_8013E0D0 *)this;
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A7260;
    fn_8013E020(&self->f_1C);
    disallow_rendering();
    set_field_0__13TForceOperateFs(&self->f_1C, arg2);
    return this;
}

}

void TMainCursor::publish_nearest_target() {
    TMainCursor__sub_8013E18C(this, ((s16 (*)(void *))TMainCursor__sub_8013E194)(this));
    TMainCursor__sub_8013E17C(this, TMainCursor__sub_8013E184(this));
}

void TMainCursor__sub_8013E17C(void* p, f32 v) { *(f32*)((char*)p + 0x8) = v; }
f32 TMainCursor__sub_8013E184(void* p) { return *(f32*)((char*)p + 0xc); }
void TMainCursor__sub_8013E18C(void* p, s16 v) { *(s16*)((char*)p + 0x4) = v; }
u16 TMainCursor__sub_8013E194(void* p) { return *(u16*)((char*)p + 0x6); }
void TMainCursor::set_target(s32 a1) { TMainCursor__sub_8013E1C0((char*)this + 0x3c, a1); }
void TMainCursor__sub_8013E1C0(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }


extern "C" {

int TObjPlayer__sub_8013A820(void* a0 = 0);
extern const f32 TMainCursor__data_805DB0C0;
extern const f32 lbl_805DB0C4;
extern s32 main_cursor_model;
extern s32 lock_on_cursor_model;

void TMainCursor::set_target_index(s16 v) { this->m_flags = v; }
void TMainCursor::update_cursor_pos() { ((TMainCursor *)((char*)this + 0x14))->copy_from((char*)this + 0xc); }

void*TMainCursor::copy_from(void* a1) { TObjPlayer__sub_8013A820(this); this->m_flags = *(unsigned short*)((char*)a1 + 0x4); this->m_id = *(short*)((char*)a1 + 0x6); return this; }

void reset_nearest_target_record(void *p) {
    Obj_8013E240 *self = (Obj_8013E240 *)p;
    self->a = 0;
    self->b = 0xffff;
    self->c = 0xffff;
    self->d = TMainCursor__data_805DB0C0;
    self->e = lbl_805DB0C4;
}

void TMainCursor::set_sub_cursor_value(s32 a1) { TMainCursor__sub_8013E290((void*)((char*)this + 0x3c), a1); }
void TMainCursor__sub_8013E290(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
s16 TMainCursor__sub_8013E298(void* p) { return *(s16*)((char*)p + 0x0); }
s32 TMainCursor__sub_8013E2A0(void* p) { return *(s32*)((char*)p + 0x0); }
s32 TMainCursor::get_index() { return *(s32 *)&this->m_flags; }
void TMainCursor__sub_8013E2B0(void* p) { *(s16*)((char*)p + 0x2) = 0; *(s16*)((char*)p + 0x0) = 0; }
void TMainCursor::reset_slot() { this->m_name = 0; }
void TMainCursor::set_type(s32 v) { *(s32 *)&this->m_flags = v; }

int TMainCursor::get_cursor_state() {  return main_cursor_model; }

int TMainCursor__sub_8013E2DC(void) {  return lock_on_cursor_model; }

}

extern "C" {

int set__8FlagWordFUl(void*, int);
int TMainCursor__sub_8013B2A4(void*);
int get_enabled__11TMainCursorFv(void*);
int get_type__11TMainCursorFv(void*);

int TMainCursor::check_field_24() { return TMainCursor__sub_8013B2A4((char*)this + 0x24); }
u16 TMainCursor::get_id() { return this->m_flags; }
int TMainCursor__sub_8013E310(void* p) { return set__8FlagWordFUl((char*)p + 0x20, 2); }
int TMainCursor__sub_8013E338(void* p) { return get_enabled__11TMainCursorFv(p); }
int TMainCursor__sub_8013E358(void* p) { return get_type__11TMainCursorFv(p); }

}

extern "C" {
int set__8FlagWordFUl(void*, int);

int TMainCursor::is_same_target(void *b) {
    u8 result = 0;
    if (TMainCursor__sub_8013E40C((TMainCursor *)this, ((TMainCursor *)b)->get_id()) != 0) {
        if (((u8)this->get_type()) == ((u8)((TMainCursor *)b)->get_type())) {
            if (((u8)this->get_enabled()) == ((u8)((TMainCursor *)b)->get_enabled())) {
                result = 1;
            }
        }
    }
    return result;
}

int TMainCursor__sub_8013E40C(TMainCursor *main_cursor, u16 arg1) {
    return (u8) (arg1 == main_cursor->get_id());
}

}

void*TMainCursor::get_list() { return (char*)this + 0xc; }
int TMainCursor::update_target_sub() { return set__8FlagWordFUl((char*)this + 0x20, 1); }

extern "C" {

int set__8FlagWordFUl(void*, int);
int test_flags_any(void*, int);

u16 TMainCursor::get_render_flag() { return TMainCursor__sub_8013E4A0((char*)this + 0x24); }
u16 TMainCursor__sub_8013E4A0(void* p) { return *(u16*)((char*)p + 0x0); }
int TMainCursor::test_flag_2_at_20() { return test_flags_any((char*)this + 0x20, 2); }
int TMainCursor::init_render_flags() { return test_flags_any((char*)this + 0x20, 8); }
int TMainCursor::update() { return test_flags_any((char*)this + 0x20, 4); }
int TMainCursor::check_flag_1() { return test_flags_any((char*)this + 0x20, 1); }
u8 TMainCursor::is_position_moved() { return (u8)(TMainCursor__sub_8013E570((char*)this + 0x60)); }
s16 TMainCursor__sub_8013E570(void* p) { return *(s16*)((char*)p + 0x6); }
int TMainCursor::check_flag_4() { return set__8FlagWordFUl((char*)this + 0x20, 4); }
int TMainCursor::forward_13E338_at_60() { return TMainCursor__sub_8013E338((char*)this + 0x60); }
int TMainCursor::update_sub_60() { return TMainCursor__sub_8013E358((char*)this + 0x60); }

}

extern "C" {

int set_slot__20TWindowActionPaletteFUc(void*);
int set_mode__20TWindowActionPaletteFUc(void*);

s32 TMainCursor::delete_this(s16 arg1) {
    s32 arg0 = (s32)this;
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv((void *)arg0);
    }
    return arg0;
}

}

s32 destroy__11TMainCursorFis(s32 obj, s16 flags) {
    if (obj != 0) {
        TPlyDispConfig::free_if_valid(obj, -1);
        if (flags > 0) {
            __dl__FPv((void *)obj);
        }
    }
    return obj;
}
void TMainCursor::set_offset_y(s16 a1) { TMainCursor__sub_8013E694((char*)this + 0x24, a1); }
void TMainCursor__sub_8013E694(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }
int TMainCursor::init_field_60() { return ((TMainCursor *)((char*)this + 0x60))->get_action_palette(); }
int TMainCursor::get_action_palette() { return set_slot__20TWindowActionPaletteFUc(this); }
int TMainCursor__sub_8013E6E0(void* p) { return ((TMainCursor *)((char*)p + 0x60))->update_action_palette(); }
int TMainCursor::update_action_palette() { return set_mode__20TWindowActionPaletteFUc(this); }
void TMainCursor::sub_8013E724(f32 v) { this->m_2c = v; }

void TMainCursor::set_target_id_at_60(u8 arg1) {
    s32 arg0 = (s32)this;
    ((TMainCursor *)(arg0 + 0x60))->set_target_id(arg1);
}

void TMainCursor::set_target_id(s16 v) { this->m_id = v; }

extern "C" {
int set_target_index__11TMainCursorFs(void*, void* a1);

int TMainCursor::set_target_index_at_60(void* _w1) { return set_target_index__11TMainCursorFs((void*)((char*)this + 0x60), _w1); }

extern "C" {

s32 TMainCursor::reset() {
    s32 arg0 = (s32)this;
    init_gc_tag(arg0);
    ((TMainCursor *)arg0)->reset_target();
    return arg0;
}

}

}

extern "C" {

int test_flags_any(void*, int);

int get_enabled__11TMainCursorFv(void*);
int get_type__11TMainCursorFv(void*);
int set_slot__20TWindowActionPaletteFUc(void*);
int set_mode__20TWindowActionPaletteFUc(void*);

int set_target_index__11TMainCursorFs(void*, void* a1 = 0);

void TMainCursor::reset_target() {
    s32 arg0 = (s32)this;
    init__6gc_tagFv((void *)arg0);
    set_target_index__11TMainCursorFs((void*)arg0, (void*)(0xFFFF));
    ((TMainCursor *)arg0)->set_target_id(0);
}

}

struct Obj_8013E800 { u16 a; };

extern "C" {
void TMainCursor__sub_8013E800(Obj_8013E800 *self);

void TMainCursor__sub_8013E800(Obj_8013E800 *self) {
    self->a = 0xffff;
}

s32 TMainCursor::get_body_exclude_mask() { return *(s32 *)&this->m_next; }
s32 TMainCursor::get_body_include_mask() { return *(s32 *)&this->m_prev; }
s32 TMainCursor::get_actor_exclude_mask() { return *(s32 *)&this->m_down; }
s32 TMainCursor::get_actor_include_mask() { return *(s32 *)&this->m_up; }
void TMainCursor::store_sorted_record(void* p, void* a1, void* a2) { ((int (*)(void *))copy_target_record__11TMainCursorFPvPv)(a2); }

}

struct Rec_8013E870 { u8 pad[0x124]; };

struct Obj_8013E870 { u8 pad[0x5c]; Rec_8013E870 recs[1]; };

void copy_target_record__11TMainCursorFPvPv(u8 *arg0, u8 *arg1) {
    *(u16 *)((s8 *)arg0 + 0) = (u16) *(u16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(f32 *)((s8 *)arg0 + 4) = (f32) *(f32 *)((s8 *)arg1 + 4);
}
void TMainCursor::init_slot(s32 i) {
    TMainCursor__sub_8013E8A0((void*)(&((Obj_8013E870 *)this)->recs[i]));
}

void TMainCursor__sub_8013E8A0(void *p) { TObjPlayer__sub_8013DEF8((u8 *)p); }
int TMainCursor::get_selected_entry() { return is_channel_active__11TMainCursorFv(this); }
int TMainCursor::get_active() { return get_enabled__11TMainCursorFv(this); }
u8 TMainCursor__sub_8013E900(void *p) { return ((TMainCursor *)p)->get_type(); }
s16 TMainCursor__sub_8013E920(void* p) { return *(s16*)((char*)p + 0x2); }
void TMainCursor__sub_8013E928(void* p, s16 v) { *(s16*)((char*)p + 0x2) = v; }
void TMainCursor__sub_8013E930(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }
u16 TLockOnCursor::get_target_id() { return *(u16 *)&(*(void * *)((u8 *)this + 0x20)); }
int TMainCursor::is_cursor_clear() { return (test_flags_any((char*)this + 0x1c, 1)) == 0; }

void TMainCursor__sub_8013E970(u8 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    *(s16 *)((s8 *)arg0 + 0) = arg1;
    *(s16 *)((s8 *)arg0 + 2) = arg2;
    *(s16 *)((s8 *)arg0 + 4) = arg3;
}

void TMainCursor::set_color_mode(s32 v) { *(s32 *)&this->m_up = v; }
void TMainCursor::set_color(s32 v) { *(s32 *)&this->m_prev = v; }
void TMainCursor::set_field_0c(s32 v) { *(s32 *)&this->m_next = v; }
void TMainCursor::set_flags(s32 v) { *(s32 *)&this->m_down = v; }

void TMainCursor__sub_8013E9A0(void *p) { TMainCursor__sub_8013DFC4((u8 *)p); }
int TMainCursor__sub_8013E9C0(void* p) { return set_slot__20TWindowActionPaletteFUc(p); }
int TMainCursor__sub_8013E9E0(void* p) { return set_mode__20TWindowActionPaletteFUc(p); }
void TMainCursor__sub_8013EA00(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }



extern "C" {
int test_flags_any(void*, int);
int clear__8FlagWordFUl(void*, int);
int set__8FlagWordFUl(void*, int);

int TLockOnCursor::render_part() { return test_flags_any((char*)this + 0x8, 2); }
void TLockOnCursor::update_cursor_pos() { ((TMainCursor *)((char*)this + 0xc))->is_same_target((char*)this + 0x14); }
int TLockOnCursor::set_flag_8_bit0() { return set__8FlagWordFUl((char*)this + 0x8, 1); }
int TLockOnCursor::update_ring() { return clear__8FlagWordFUl((char*)this + 0x8, 1); }
int TLockOnCursor::is_bit1_set() { return set__8FlagWordFUl((char*)this + 0x8, 2); }
int TLockOnCursor::is_inactive() { return (test_flags_any((char*)this + 0x1c, 2)) == 0; }
int TLockOnCursor::update_ring_sub() { return clear__8FlagWordFUl((char*)this + 0x8, 2); }
s32 TLockOnCursor__sub_8013EB2C(void* p) { return *(s32*)((char*)p + 0x4); }

    extern s32 TLockOnCursor__target_cursor_model;
int TLockOnCursor__sub_8013EB34(void) {  return TLockOnCursor__target_cursor_model; }

int TLockOnCursor::test_flag_1_at_8() { return test_flags_any((char*)this + 0x8, 1); }
s32 TLockOnCursor::get_target() { return *(s32 *)&this->m_name; }
Rec_8013EB6C *TLockOnCursor__sub_8013EB6C(Obj_8013EB6C *self, s32 i) {
    return &self->recs[i];
}

}


struct Obj_8013EC38 { u16 h0; s16 h2; f32 f4; u8 f8[4]; u8 fc[8]; u8 f14[8]; };

extern "C" {
extern const f32 TMainCursor__data_805DB0C0;

void TLockOnCursor__sub_8013EB80(void* p) { *(s32*)((char*)p + 0x4) = 0; }
void TLockOnCursor__sub_8013EB8C(void* p) { *(s32*)((char*)p + 0x4) = 1; }
s32 TLockOnCursor::release_target() { return TLockOnCursor__sub_8013EBBC((void*)((char*)this + 0x3c)); }
s32 TLockOnCursor__sub_8013EBBC(void* p) { return *(s32*)((char*)p + 0x8); }
s32 TLockOnCursor::cleanup_field() { return TLockOnCursor__sub_8013EBE8((void*)((char*)this + 0x3c)); }
s32 TLockOnCursor__sub_8013EBE8(void* p) { return *(s32*)((char*)p + 0x4); }
s32 TLockOnCursor::cleanup_field_3c() { return TLockOnCursor__sub_8013EC14((void*)((char*)this + 0x3c)); }
s32 TLockOnCursor__sub_8013EC14(void* p) { return *(s32*)((char*)p + 0x0); }
void TLockOnCursor__sub_8013EC1C(void *p) {
    Obj_8013EC1C *self = (Obj_8013EC1C *)p;
    self->a = 0xffff;
    self->b = 0;
    self->c = 0;
}
void TLockOnCursor::reset_state() {
    Obj_8013EC38 *self = (Obj_8013EC38 *)this;
    ((TMainCursor *)(self->fc))->reset_target();
    ((TMainCursor *)(self->f14))->reset_target();
    init__6gc_tagFv(self->f8);
    self->h0 = 0xffff;
    self->h2 = 0;
    self->f4 = TMainCursor__data_805DB0C0;
}

}

extern "C" {

s32 __dt__13TLockOnCursorFis(s32 arg0, s16 arg1);

s32 TLockOnCursor::free_if_owned(s32 obj, s16 flags) {
    if ((obj != 0) && (flags > 0)) {
        __dl__FPv((void *)obj);
    }
    return obj;
}

s32 __dt__13TLockOnCursorFis(s32 obj, s16 flags) {
    if ((obj != 0) && (flags > 0)) {
        __dl__FPv((void *)obj);
    }
    return obj;
}

}

extern "C" {

s32 TLockOnCursor__sub_8013EDC4(s32, s16);

s32 __dt_deleting__13TLockOnCursorFis(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        TLockOnCursor__sub_8013ED68(arg0 + 0x9C, (s16)(-1));
        TPlyDispConfig::free_if_valid(arg0, -1);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}
s32 TLockOnCursor__sub_8013ED68(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __destroy_arr((void *)(arg0 + 0x4), (void *)TLockOnCursor__sub_8013EDC4, 0xc, 0xb);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

}

s32 TLockOnCursor__sub_8013EDC4(s32 obj, s16 flags) {
    if ((obj != 0) && (flags > 0)) {
        __dl__FPv((void *)obj);
    }
    return obj;
}

s32 destroy__13TLockOnCursorFis(s32 obj, s16 flags) {
    if (obj != 0) {
        destroy__11TMainCursorFis(obj + 0x14, -1);
        destroy__11TMainCursorFis(obj + 0xC, -1);
        TPlyDispConfig::free_if_valid(obj + 8, -1);
        if (flags > 0) {
            ::operator delete((void *)obj);
        }
    }
    return obj;
}

extern s32 lbl_804A7248[];

void *TLockOnCursor::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 * *)&this->m_prev = lbl_804A7248;
        TPlyDispConfig::free_if_valid((s32)this, 0);
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

void TLockOnCursor::sub_8013EEC0(s16 v) { *(s16*)((char*)this + 0x20) = v; }

extern "C" {

void *fn_8004438C(void *p);

void *TLockOnCursor::init_vtable() {
    init_gc_tag((s32)this);
    *(s32 * *)&this->m_prev = lbl_804A7248;
    *(u32 *)&this->m_flags = 0;
    return this;
}

void*TLockOnCursor::init_cursor() { reset_nearest_target_record(this); return this; }
void*TLockOnCursor::init_forward() { TLockOnCursor__sub_8013EC1C(this); return this; }
void*TLockOnCursor::cleanup() { init_gc_tag((s32)((char*)this + 0x8)); ((TMainCursor *)((char*)this + 0xc))->reset(); ((TMainCursor *)((char*)this + 0x14))->reset(); reset_state(); return this; }

void *TLockOnCursor__sub_8013EFB8(void *main_cursor) {
    init_gc_tag((s32)main_cursor);
    ((TObjPlayer *)((char *)main_cursor + 64))->construct_target_cursor_records();
    TLockOnCursor__sub_8013F000((void *)((void *)((void *)((char *)main_cursor + 156))));
    ((TMainCursor *)main_cursor)->reset_state();
    return main_cursor;
}

int TLockOnCursor__sub_8013F000(void *self) {
    __construct_array((char *)self + 4, (void *)init_sub__13TLockOnCursorFPv, (void *)TLockOnCursor__sub_8013EDC4, 0xc, 0xb);
    ((TMainCursor *)self)->reset_slot();
    return (int)self;
}

void* init_sub__13TLockOnCursorFPv(void* p) { fn_8004438C(p); __ct__8FlagWordFv(((char*)p + 0x8)); return p; }
void TLockOnCursor::reset_fields() { *(s32 *)&this->m_name = 0; *(s32 *)&this->m_flags = 0; *(s32 *)&this->m_prev = 0; }

struct VOff_8013F0A0_arg0 { char pad_0[0x8]; char f_8[1]; };
void *fn_8013F0A0(void *arg0) {
    struct VOff_8013F0A0_arg0 *self = (struct VOff_8013F0A0_arg0 *)arg0;
    TMainCursor__sub_8013F114(arg0);
    __construct_array(self->f_8, (void *)TMainCursor__sub_8013E2B0, 0, 4, 4);
    TMainCursor__sub_8013F10C(arg0, 4);
    TMainCursor__sub_8013F104((void*)arg0, (s32)self->f_8);
    return arg0;
}

}

struct RecoveredGlobal_8013F1F0_lbl_804A7254 {
    s32 value;
    u8 remaining[0x8];
};

struct Rec_8013F154 { u8 pad[0x8]; };

struct Obj_8013F154 { u8 pad[0x4]; Rec_8013F154 recs[1]; };

struct Obj_8013F24C { u8 pad[0x44]; u8 arr[1]; };

extern "C" {
extern s32 lbl_804A7254[];
Rec_8013F154 *get_record_at__11TMainCursorFPvi(Obj_8013F154 *self, s32 i);
u8 fn_8013F24C(Obj_8013F24C *self, s16 i);

void TMainCursor__sub_8013F104(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }
void TMainCursor__sub_8013F10C(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
void TMainCursor__sub_8013F114(void* p) { *(s32*)((char*)p + 0x0) = 0; *(s32*)((char*)p + 0x4) = 0; }

void TMainCursor::set_cursor_id(s16 v) { *(s16 *)&this->m_name = v; }
void TMainCursor::set_field2(s16 v) { *(s16*)((char*)this + 0x2) = v; }
void TMainCursor::set_size(f32 v) { *(f32 *)&this->m_flags = v; }

void TMainCursor__sub_8013F13C(s32 *arg0) {
    *arg0 += 1;
}

f32 TMainCursor__sub_8013F14C(void* p) { return *(f32*)((char*)p + 0x4); }

Rec_8013F154 *get_record_at__11TMainCursorFPvi(Obj_8013F154 *self, s32 i) {
    return &self->recs[i];
}

s32 TMainCursor__sub_8013F168(void* p) { return *(s32*)((char*)p + 0x0); }
void TMainCursor__sub_8013F170(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }

f32 TMainCursor::get_pos() { return *(f32 *)&this->m_name; }
void TMainCursor__sub_8013F180(void* p, f32 v) { *(f32*)((char*)p + 0x0) = v; }

int TMainCursor::get_rader_map() { return ((int (*)(void *))copy_argb)(this); }

void *TMainCursor::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 * *)&this->m_up = lbl_804A7254;
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

    extern const float TMainCursor__data_805DB0C0;

typedef char RecoveredGlobal_8013F1F0_lbl_804A7254_size[sizeof(RecoveredGlobal_8013F1F0_lbl_804A7254) == 0xC ? 1 : -1];
u8 *TMainCursor__sub_8013F1F0(u8 *arg0) {
    *(s32 **)((s8 *)arg0 + 0x10) = &(*(RecoveredGlobal_8013F1F0_lbl_804A7254 *)&lbl_804A7254).value;
    TMainCursor__sub_8013F22C(arg0);
    return arg0;
}

void TMainCursor__sub_8013F22C(void* a0) { *(float*)((char*)a0 + 0xc) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x8) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x4) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x0) = TMainCursor__data_805DB0C0; }

int TMainCursor__sub_8013F244(void) { return -1; }
u8 fn_8013F24C(Obj_8013F24C *self, s16 i) {
    return self->arr[i];
}

}

    extern int TCameraCtrl__fixed_npc_camera_active;
int TCameraCtrl::get_mode() {  return TCameraCtrl__fixed_npc_camera_active; }
