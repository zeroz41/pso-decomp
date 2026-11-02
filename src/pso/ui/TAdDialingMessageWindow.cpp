#pragma readonly_strings on
#include "types.h"
#include "pso/ui/TAdDialingMessageWindow.h"

#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdDrawLineCtrl.h"
#include "pso/ui/TUnk_804F3428.h"

#include "pso/TObject.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Base_8036A248_8036A174 { char pad[0x18]; };
struct VObj_8036A248_8036A174 : Base_8036A248_8036A174 { virtual void m0(int); };

extern "C" {
const char *TAdDialingMessageWindow__name = "TAdDialingMessageWindow";

void TAdDialingGC__sub_80328B24(const f32 *, const f32 *);
const f32 lbl_8047A400[2] = {0.0f, 28.0f};
const f32 lbl_8047A408[2] = {640.0f, 84.0f};
extern const f32 lbl_805E0364;
extern const f32 lbl_805E0368;
void __ct__7TObjectFP7TObject(void *, void *);
void *__nw__7TObjectFUl(int);

    extern const float lbl_805E0360;
void TAdDialingMessageWindow::set_flag_and_notify() { this->m_1c = (this->m_1c | 0x1); create_draw_line_ctrl__13TAdMcSelectGCFiif((this->m_28), 17, lbl_805E0360); }

void TAdDialingMessageWindow::run_child_tasks() { void* m = *(void* *)&this->m_28; if (m) ((TObject *)m)->run_tasks(); }


void TAdDialingMessageWindow::render() {
    if (this->m_1c & 1) {
        TAdDialingGC__sub_80328B24(lbl_8047A400, lbl_8047A408);
        if ((u32) this->m_20 != 0U) {
            ((TAdSinglePlyChrSelectGC *)(this->m_20))->render_status_disp(lbl_805E0364, lbl_805E0368);
        }
    }
    if ((u32) this->m_28 != 0U) {
        ((TObject *)(this->m_28))->render_nodes();
    }
}

}
TAdDialingMessageWindow::~TAdDialingMessageWindow() {
    void *temp_r3;
    if (*(void **)((s8 *)this + 0x24) != NULL) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x24));
    }
    temp_r3 = *(void **)((s8 *)this + 0x28);
    if ((temp_r3 != NULL) && (temp_r3 != NULL)) {
        ((VObj_8036A248_8036A174 *)temp_r3)->m0(1);
    }
}
extern void *tl_fadeafter;
extern void *tl_camera;
TAdDialingMessageWindow::TAdDialingMessageWindow(void *arg1, void *arg2) : TObject((TObject *)tl_fadeafter) {
    void *o;
    void *o2;
    *(const char **)&this->m_name = TAdDialingMessageWindow__name;
    this->m_1c = 0;
    *(void **)((s8 *)this + 0x20) = arg1;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        o = ((TUnk_804F3428 *)o)->init(tl_camera, this, arg2);
    }
    *(void **)((s8 *)this + 0x24) = o;
    o2 = __nw__7TObjectFUl(0x1C);
    if (o2 != NULL) {
        o2 = ((void * (*)(void *, int))__ct__7TObjectFP7TObject)(o2, 0);
    }
    *(void **)((s8 *)this + 0x28) = o2;
}
