#include "pso/ui/TAdDrawLineCtrl.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/render/render_util.h"


#include "types.h"
#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/player/TObjPlayer.h"


extern "C" {
void *__ct__15TAdDrawLineCtrlFP7TObjectPvf(void *arg0, void *arg1, void *arg2, f32 farg0);
void *__nw__7TObjectFUl(int);
extern u32 lbl_805D49D8;
void __ct__7TObjectFP7TObject(void *);
s32 defer_render__7TObjectFv();

void TAdDrawLineCtrl::render() {
    if ((s32) this->render_mode == 0) {
        if (defer_render__7TObjectFv() == 0) {
            set_depth_buffer_settings_2();
            goto block_5;
        }
    } else if ((get_main_phase() != 2) || (TMainTask::get_render_pass() != 1)) {
block_5:
        set_default_alpha_blend();
        if ((u32) this->child_root != 0U) {
            ((TObject *)(this->child_root))->render_nodes();
        }
        if ((s32) this->render_mode == 0) {
            restore_saved_depth_alpha_state();
        }
    }
}

extern void *TAdDrawLineCtrl__class_name;

void TAdDrawLineCtrl::run_task() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r0;
    temp_r0 = *(u32 *)&this->child_root;
    if (temp_r0 != 0U) {
        ((TObject *)temp_r0)->run_tasks();
        return;
    }
    queue_destruction__7TObjectFv(arg0);
}

}

TAdDrawLineCtrl::~TAdDrawLineCtrl() {
    delete child_root;
}

TAdDrawLineCtrl::TAdDrawLineCtrl(TObject *object, void *arg2, f32 farg0) : TObject(object) {
    void *o;
    *(void * *)&this->m_name = TAdDrawLineCtrl__class_name;
    this->line_data = arg2;
    o = __nw__7TObjectFUl(0x1C);
    if (o != NULL) {
        o = ((void * (*)(void *, int))__ct__7TObjectFP7TObject)(o, 0);
    }
    *(void * *)&this->child_root = o;
    this->render_mode = 1;
    this->set_draw_line_param_all_nodes(farg0);
    sub_80019B08(-1);
}

u8 *create_draw_line_ctrl__13TAdMcSelectGCFiif(s32 arg0, s32 arg1, f32 farg0) {
    u8 *ad_draw_line_ctrl;
    u8 *var_r0;
    if ((u32) lbl_805D49D8 != 0U) {
        ad_draw_line_ctrl = (u8 *)(((u8 *)__nw__7TObjectFUl(0x2C)));
        var_r0 = ad_draw_line_ctrl;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)__ct__15TAdDrawLineCtrlFP7TObjectPvf((void *)ad_draw_line_ctrl, (void *)arg0, (void *)(lbl_805D49D8 + (arg1 * 0xC)), farg0)));
        }
        return var_r0;
    }
    return NULL;
}
