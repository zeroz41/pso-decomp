#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubStatusDisp_802671F0.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TUnk_804D0948.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct RecoveredGlobal_8026E110_lbl_804D0948 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_8026E168_lbl_804D0948 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, int);
s32 draw_item_list_capacity(void *, int, int, int);
s32 draw_window_scrollbar(void *, int, void *);
s32 forward_render__20TWindowSubStatusDispFv(void *, int);
u8 * fn_80268384(void *, s32, s32, s16, s32);
s32 sub_8026DE94__13TUnk_804D0948Fv(void *, void *);
extern s32 item_list_window_vtable[];
extern s32 local_client_id;
u8 * get_window_layout_position(s32);
u8 *fn_802683F4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void __dl__7TObjectFPv(void *);

#pragma push
#pragma fp_contract on
void TUnk_804D0948::render() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    s32 n;
    void *p;
    temp_r3 = get_draw_context__11TWindowBaseFPv();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
    if (!(this->state_flags & 0x80)) {
        ((TWindowMenuIconLine *)arg0)->draw_selected_list_entry(temp_r3);
    }
    n = *(s32 *)&this->unk_88;
    if (n > 0) {
        draw_item_list_capacity(arg0, temp_r3, this->entry_count, n);
    }
    p = this->status_display;
    if (p != NULL) {
        forward_render__20TWindowSubStatusDispFv(p, temp_r3);
    }
    p = *(void * *)&this->unk_84;
    if (p != NULL) {
        draw_window_scrollbar(p, temp_r3, (u8 *)&this->m_68);
    }
}
#pragma pop

void TUnk_804D0948::run_task() { run_task__19TWindowMenuIconLineFv((u8 *)this); }

void *TWindowSubStatusDisp::deleting_dtor(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = item_list_window_vtable;
        destroy_item_list_resources(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
typedef char RecoveredGlobal_8026E110_lbl_804D0948_size[sizeof(RecoveredGlobal_8026E110_lbl_804D0948) == 0x20 ? 1 : -1];
u8 *TWindowSubStatusDisp::ct_helper(s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    fn_80268384(this, arg1, arg3, (s16) local_client_id, arg4);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_8026E110_lbl_804D0948 *)&item_list_window_vtable).value;
    sub_8026DE94__13TUnk_804D0948Fv(this, (void *)arg2);
    return ((u8 *)this);
}
typedef char RecoveredGlobal_8026E168_lbl_804D0948_size[sizeof(RecoveredGlobal_8026E168_lbl_804D0948) == 0x20 ? 1 : -1];
u8 *TWindowSubStatusDisp::construct_item_list(s32 arg1, s32 arg2, s16 arg3) {
    fn_802683F4((((u8 *)this)), (s32)(get_window_layout_position(0x26)), (arg2), (arg3));
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_8026E168_lbl_804D0948 *)&item_list_window_vtable).value;
    sub_8026DE94__13TUnk_804D0948Fv(this, (void *)arg1);
    return ((u8 *)this);
}

}
