#include "types.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_802F4380_main_task { s32 value; u8 remaining[0x30]; };
typedef char RecoveredGlobal_802F4380_main_task_size[sizeof(RecoveredGlobal_802F4380_main_task) == 0x34 ? 1 : -1];

extern "C" {

s32 get_mode__11TCameraCtrlFPv(void *);
s32 defer_render__7TObjectFv(void *);
s32 is_split_screen();

void TBoss8Dragon__sub_802F4380(TBoss8Dragon *self) {
    s32 view = 0;
    u8 pos[0xC];
    if (TObjPlayer::check_demo_mode() != 0) {
        ((void (*)(void *))self->m_18[106])((void *)self);
        return;
    }
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_mode();
    }
    self->sub_802F4098(pos);
    if (defer_render__7TObjectFv((void *)self) != 0) {
        if (!(get_mode__11TCameraCtrlFPv(&(*(RecoveredGlobal_802F4380_main_task *)&main_task).value) & 8)) {
            self->render_body_model();
            self->copy_vectors();
        }
        if (self->renderFadeStates[view].isFading() == 0) {
            self->draw_with_fade((s32)pos, view);
        }
        self->render_nodes_flagged();
    } else if (self->renderFadeStates[view].isFading() != 0) {
        self->draw_with_fade((s32)pos, view);
    }
}

}
