#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
typedef struct Win_8024C024 {
    u8 pad0[0x50];
    s32 fade;
} Win_8024C024;

typedef struct Ctrl_8024C024 {
    u8 pad0[0x1E];
    s16 timer;
    s16 step;
    u8 pad22[0x48 - 0x22];
    Win_8024C024 *split[12];
    Win_8024C024 *slots[3];
} Ctrl_8024C024;

extern "C" {
s32 is_split_screen();
extern s16 lbl_8044EBD4[];
extern s16 lbl_8044EBE0[];
void TWindowCtrl::update_open_sequence() {
    Ctrl_8024C024 *o = (Ctrl_8024C024 *)this;
    if (is_split_screen() != 0) {
        if (o->timer == lbl_8044EBD4[o->step]) {
            if (o->split[o->step] != NULL) {
                ((TQuestVmDownLoadServer *)(o->split[o->step]))->clear_flag4_bit4();
            }
            o->step++;
        }
    } else {
        if (o->timer == lbl_8044EBE0[o->step]) {
            if (o->slots[o->step] != NULL) {
                ((TQuestVmDownLoadServer *)(o->slots[o->step]))->clear_flag4_bit4();
                ((TWindowCtrl *)o)->update_party_status_rows();
                o->slots[o->step]->fade = 0;
            }
            o->step++;
        }
    }
    if (o->timer > 30000) {
        o->timer -= 10000;
    }
    o->timer++;
}

}
