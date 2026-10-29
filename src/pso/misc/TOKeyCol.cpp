#include "types.h"
#include "pso/misc/TOKeyCol.h"

#include "pso/misc/TOKey.h"

extern "C" {

void *TOKeyCol__ct(TOKeyCol *arg0, s32 arg1, s32 arg2);
s32 __ct__5TOKeyFP7TObject();
void *__nw__7TObjectFUl(int);

void TOKeyCol::vfunc_19() {  }
void TOKeyCol::trigger_activate_sound() {  }
void TOKeyCol::vfunc_17() {  }
void TOKeyCol::vfunc_16() {  }

void TOKeyCol::run_task() {
    u8 *arg0 = (u8 *)this;
    this->update_lock_state();
    if ((s32) this->m_d4 != 1) {
        this->vfunc_17();
        if (this->is_confirm_pressed() == 1) {
            ((TOKeyCol *)arg0)->send_switch_changed(1);
            this->trigger_activate_sound();
            this->m_d4 = 1;
        }
    } else {
        this->vfunc_16();
        if (this->is_confirm_pressed() != 1) {
            ((TOKeyCol *)arg0)->send_switch_changed(0);
            this->vfunc_19();
            this->m_d4 = 0;
        }
    }
}

void TOKeyCol::render() {  }

extern void *tl_05;

void *TOKeyCol::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE8);
    if (o != NULL) {
        o = TOKeyCol__ct((TOKeyCol *)((void *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

extern s32 __vt__8TOKeyCol[];

}
TOKeyCol::~TOKeyCol() {

}


extern s32 TOKeyCol__name;
extern const f32 lbl_805DB758;
extern const f32 lbl_805DB75C;
extern const f32 lbl_805DB760;

void *TOKeyCol__ct(TOKeyCol *key_col, s32 arg1, s32 arg2) {
    __ct__5TOKeyFP7TObject();
    *(s32 **)((s8 *)key_col + 0x18) = __vt__8TOKeyCol;
    *(s32 *)((s8 *)key_col + 0) = (s32) TOKeyCol__name;
    key_col->apply_object_set_data((void *)arg2);
    ((TOKey *)key_col)->init_switch_id();
    key_col->m_c0 = (f32) lbl_805DB758;
    *(f32 *)((s8 *)key_col + 0xC4) = (f32) lbl_805DB75C;
    *(f32 *)((s8 *)key_col + 0xCC) = (f32) (lbl_805DB760 + key_col->scale.x);
    if (((s32) key_col->m_d0 != 2) && ((s32) *(s32 *)((s8 *)key_col + 0x88) < 0)) {
        key_col->m_d0 = 1;
    } else {
        key_col->m_d0 = 0;
    }
    return key_col;
}

