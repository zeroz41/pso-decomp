#include "types.h"
#include "pso/unk/text_80191D14.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/object/TObjHashiBase.h"
#include <stddef.h>

struct Base_80191BEC_80191B94 { char pad[0x18]; };
struct VObj_80191BEC_80191B94 : Base_80191BEC_80191B94 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(s32);
};

struct VBase { char pad[0x18]; };

struct VDisp : VBase {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

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
void *TObjHashiBase__ct(TObjHashiBase *arg0, s32 arg1, s32 arg2);
void *__dt__13TObjHashiBaseFv(void *arg0, s16 arg1);
u8 is_current_floor_switch_set(u16, f32);
void __dl__7TObjectFPv(void *);
s32 bswap_6x78__11TObjInfoColFv();
s32 init_map_object_base();

extern s32 __vt__13TObjHashiBase[];

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
typedef char RecoveredGlobal_80191874_lbl_804FF610_size[sizeof(RecoveredGlobal_80191874_lbl_804FF610) == 0xC ? 1 : -1];
s32 TObjHashiBase::update_object_view_visibility(f32 farg0, f32 farg1) {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_80191874, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80191874, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80191874, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_80191874, sp18) == 0x10) ? 1 : -1];
    Stack_80191874 stack;
    if (TMainTask::get_render_pass() == 1) {
        return this->m_1e;
    }
    if (xz_distance_squared((void *)(camera_ctrl_instance + 0x178), (void *)(arg0 + 0x38)) < (farg1 * farg1)) {
        this->m_1e = 1;
        return 1;
    }
    matrix_mult_vec(0, (u8 *)&this->position, (void *)&stack.sp10);
    if (stack.sp18 > lbl_805DBE2C) {
        this->m_1e = 0;
        return 0;
    }
    if (stack.sp18 < -farg0) {
        this->m_1e = 0;
        return 0;
    }
    if (stack.sp10 < lbl_805DBE2C) {
        stack.sp10 = (*(f32 *)((s8 *)&camera_right.value + 0) * farg1) + *(f32 *)((s8 *)arg0 + 0x38);
        stack.sp14 = (*(f32 *)((s8 *)&camera_right.value + 4) * farg1) + *(f32 *)((s8 *)arg0 + 0x3C);
        stack.sp18 = (*(f32 *)((s8 *)&camera_right.value + 8) * farg1) + *(f32 *)((s8 *)arg0 + 0x40);
        project_world_to_screen(0, (void *)&stack.sp10, (void *)&stack.sp8);
        if (stack.sp8 < lbl_805DBE2C) {
            this->m_1e = 0;
            return 0;
        }
        goto block_13;
    }
    stack.sp10 = -((*(f32 *)((s8 *)&camera_right.value + 0) * farg1) - *(f32 *)((s8 *)arg0 + 0x38));
    stack.sp14 = -((*(f32 *)((s8 *)&camera_right.value + 4) * farg1) - *(f32 *)((s8 *)arg0 + 0x3C));
    stack.sp18 = -((*(f32 *)((s8 *)&camera_right.value + 8) * farg1) - *(f32 *)((s8 *)arg0 + 0x40));
    project_world_to_screen(0, (void *)&stack.sp10, (void *)&stack.sp8);
    if (stack.sp8 > lbl_805DBE30) {
        this->m_1e = 0;
        return 0;
    }
block_13:
    this->m_1e = 1;
    return 1;
}
#pragma pop

void TObjHashiBase::render() {
    u8 *arg0 = (u8 *)this;
    void *p;
    if (((VDisp *)arg0)->m8(*(f32 *)((s8 *)arg0 + 0xC0), *(f32 *)((s8 *)arg0 + 0xC4)) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->m_60);
        TObjFish::set_global_param(this->m_24);
        p = this->motion;
        if (p != NULL) {
            draw_model_motion((void *)this->m_34, p, *(f32 *)((s8 *)arg0 + 0xB0));
        } else {
            draw_ginja_object((void *)this->m_34);
        }
        pop_matrix();
    }
}

extern "C" void set_indexed_flags__14TObjCollidableFll(void *arg0, s32 index, s32 flags);
}
void handle_6x78(void *arg0);
typedef char BridgeSize[sizeof(TObjHashiBase)==0xD4?1:-1];
typedef char BridgePhase[offsetof(TObjHashiBase,phase)==0xAC?1:-1];
typedef char BridgeRaisedY[offsetof(TObjHashiBase,raisedHeight)==0xCC?1:-1];
void TObjHashiBase::run_task() {
    f32 height;
    s32 index;
    switch (phase) {
    case 0:
        if (((u8 (*)(u16))is_current_floor_switch_set)((u16)switchId) != 0) {
            phase=1;
            return;
        }
        break;
    case 1:
        position[1]=position[1]+riseSpeed;
        if(position[1]>(height=raisedHeight)) {
            position[1]=height;
            phase=2;
            return;
        }
        break;
    case 2:
        index=0;
        while(index<colliderCount) {
            set_indexed_flags__14TObjCollidableFll(this,index,8);
            ++index;
        }
        phase=3;
        break;
    case 3:break;
    }
}

void *__dt__13TObjHashiBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        ((TObjHashiBase *)arg0)->m_18 = __vt__13TObjHashiBase;
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_805D3374;
extern const f32 lbl_805DBE24;
extern const f32 lbl_805DBE28;
extern const f32 lbl_805DBE34;
extern const f32 lbl_805DBE38;

void *TObjHashiBase__ct(TObjHashiBase *hashi_base, s32 arg1, s32 arg2) {
    init_map_object_base();
    hashi_base->m_18 = __vt__13TObjHashiBase;
    *(s32 *)((s8 *)hashi_base + 0) = (s32) lbl_805D3374;
    ((VObj_80191BEC_80191B94 *)hashi_base)->m5(arg2);
    hashi_base->switchId = (s32) hashi_base->m_84;
    *(f32 *)((s8 *)hashi_base + 0xC0) = (f32) lbl_805DBE24;
    *(f32 *)((s8 *)hashi_base + 0xC4) = (f32) lbl_805DBE28;
    if (is_current_floor_switch_set((u16) hashi_base->switchId, lbl_805DBE24) == 1) {
        hashi_base->phase = 2;
        *(f32 *)((s8 *)hashi_base + 0xCC) = (f32) *(f32 *)((s8 *)hashi_base + 0x3C);
        *(f32 *)((s8 *)hashi_base + 0xD0) = (f32) lbl_805DBE34;
    } else {
        hashi_base->phase = 0;
        *(f32 *)((s8 *)hashi_base + 0xCC) = (f32) *(f32 *)((s8 *)hashi_base + 0x3C);
        *(f32 *)((s8 *)hashi_base + 0x3C) = (f32) (*(f32 *)((s8 *)hashi_base + 0x3C) - lbl_805DBE38);
        *(f32 *)((s8 *)hashi_base + 0xD0) = (f32) lbl_805DBE34;
    }
    return hashi_base;
}

void handle_6x78(void *arg0) {
    bswap_6x78__11TObjInfoColFv();
    if (get_handle_6x78_entry(*(u16 *)((s8 *)arg0 + 4)) != 0) {
        fn_80191D14(*(u16 *)((s8 *)arg0 + 4), 0);
        return;
    }
    fn_80191D5C(*(u16 *)((s8 *)arg0 + 4));
}
