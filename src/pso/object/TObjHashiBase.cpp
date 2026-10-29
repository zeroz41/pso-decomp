#include "types.h"
#include "pso/unk/text_80191D14.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/object/TObjHashiBase.h"
#include <stddef.h>


#include <stddef.h>
#include "pso/TMainTask.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
struct Stack_80191874 {
    f32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
    f32 sp14;
    f32 sp18;
};

struct RecoveredGlobal_80191874_lbl_804FF610 {
    s32 value;
    u8 remaining[0x8];
};

extern "C" {
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_object(void *child);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
f32 xz_distance_squared(void *, void *);
s32 matrix_mult_vec(int, void *, void *);
s32 project_world_to_screen(int, void *, void *);
extern RecoveredGlobal_80191874_lbl_804FF610 camera_right;
extern s32 camera_ctrl_instance;
extern const f32 lbl_805DBE2C;
extern const f32 lbl_805DBE30;
u8 is_current_floor_switch_set(u16, f32);
void __dl__7TObjectFPv(void *);
s32 bswap_6x78__11TObjInfoColFv();


#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
typedef char RecoveredGlobal_80191874_lbl_804FF610_size[sizeof(RecoveredGlobal_80191874_lbl_804FF610) == 0xC ? 1 : -1];
s32 TObjHashiBase::update_object_view_visibility(f32 farg0, f32 farg1) {
    typedef char sp8_offset[(offsetof(Stack_80191874, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80191874, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80191874, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_80191874, sp18) == 0x10) ? 1 : -1];
    Stack_80191874 stack;
    if (TMainTask::get_render_pass() == 1) {
        return this->visibility;
    }
    if (xz_distance_squared((void *)(camera_ctrl_instance + 0x178), (void *)&this->position) < (farg1 * farg1)) {
        this->visibility = 1;
        return 1;
    }
    matrix_mult_vec(0, (u8 *)&this->position, (void *)&stack.sp10);
    if (stack.sp18 > lbl_805DBE2C) {
        this->visibility = 0;
        return 0;
    }
    if (stack.sp18 < -farg0) {
        this->visibility = 0;
        return 0;
    }
    if (stack.sp10 < lbl_805DBE2C) {
        stack.sp10 = (*(f32 *)((s8 *)&camera_right.value + 0) * farg1) + this->position.x;
        stack.sp14 = (*(f32 *)((s8 *)&camera_right.value + 4) * farg1) + this->position.y;
        stack.sp18 = (*(f32 *)((s8 *)&camera_right.value + 8) * farg1) + this->position.z;
        project_world_to_screen(0, (void *)&stack.sp10, (void *)&stack.sp8);
        if (stack.sp8 < lbl_805DBE2C) {
            this->visibility = 0;
            return 0;
        }
        goto block_13;
    }
    stack.sp10 = -((*(f32 *)((s8 *)&camera_right.value + 0) * farg1) - this->position.x);
    stack.sp14 = -((*(f32 *)((s8 *)&camera_right.value + 4) * farg1) - this->position.y);
    stack.sp18 = -((*(f32 *)((s8 *)&camera_right.value + 8) * farg1) - this->position.z);
    project_world_to_screen(0, (void *)&stack.sp10, (void *)&stack.sp8);
    if (stack.sp8 > lbl_805DBE30) {
        this->visibility = 0;
        return 0;
    }
block_13:
    this->visibility = 1;
    return 1;
}
#pragma pop

void TObjHashiBase::render() {
    void *p;
    if (this->update_object_view_visibility(this->m_c0, this->model_radius) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        p = this->motion;
        if (p != NULL) {
            draw_model_motion(this->model, p, this->m_b0);
        } else {
            draw_ginja_object(this->model);
        }
        pop_matrix();
    }
}

extern "C" void set_indexed_flags__14TObjCollidableFll(void *arg0, s32 index, s32 flags);
}
void handle_6x78(void *arg0);
typedef char BridgeSize[sizeof(TObjHashiBase)==0xD4?1:-1];
typedef char BridgeRaisedY[offsetof(TObjHashiBase,raisedHeight)==0xCC?1:-1];
void TObjHashiBase::run_task() {
    f32 height;
    s32 index;
    switch (m_ac) {
    case 0:
        if (((u8 (*)(u16))is_current_floor_switch_set)((u16)switchId) != 0) {
            m_ac=1;
            return;
        }
        break;
    case 1:
        position.y=position.y+riseSpeed;
        if(position.y>(height=raisedHeight)) {
            position.y=height;
            m_ac=2;
            return;
        }
        break;
    case 2:
        index=0;
        while(index<body_count) {
            set_indexed_flags__14TObjCollidableFll(this,index,8);
            ++index;
        }
        m_ac=3;
        break;
    case 3:break;
    }
}

// The destructor is still written out by hand: compiled, its vtable would
// open the unit's .data, which the original fills first with the object's
// resource and collision tables (not owned by this unit yet).
extern "C" {
extern void *__vt__13TObjHashiBase[];
void __dl__7TObjectFPv(void *);

void *__dt__13TObjHashiBaseFv(void *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 0x18) = __vt__13TObjHashiBase;

        __dt__13TUnk_804AFBF8Fv(self, 0);
        if (del > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

extern const char *lbl_805D3374;
extern const f32 lbl_805DBE24;
extern const f32 lbl_805DBE28;
extern const f32 lbl_805DBE34;
extern const f32 lbl_805DBE38;

TObjHashiBase::TObjHashiBase(TObject *parent, void *set_data) : TUnk_804AFBF8(parent) {
    this->m_name = lbl_805D3374;
    this->apply_object_set_data(set_data);
    this->switchId = this->set_params[0];
    this->m_c0 = lbl_805DBE24;
    this->model_radius = lbl_805DBE28;
    if (is_current_floor_switch_set((u16) this->switchId, lbl_805DBE24) == 1) {
        this->m_ac = 2;
        this->raisedHeight = this->position.y;
        this->riseSpeed = lbl_805DBE34;
    } else {
        this->m_ac = 0;
        this->raisedHeight = this->position.y;
        this->position.y = this->position.y - lbl_805DBE38;
        this->riseSpeed = lbl_805DBE34;
    }
}

void handle_6x78(void *arg0) {
    bswap_6x78__11TObjInfoColFv();
    if (get_handle_6x78_entry(*(u16 *)((s8 *)arg0 + 4)) != 0) {
        fn_80191D14(*(u16 *)((s8 *)arg0 + 4), 0);
        return;
    }
    fn_80191D5C(*(u16 *)((s8 *)arg0 + 4));
}
