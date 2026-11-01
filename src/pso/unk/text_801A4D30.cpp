#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowShortListCtrl_801A4FC0.h"
#include "pso/ui/TObjBagWarnWin_8006EF24.h"
#include "pso/misc/TUnk_804C2298.h"
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/TCheckMemoryCard.h"
#include "pso/misc/TLobby.h"
typedef struct Vec_801A4D30 {
    s32 x, y, z;
} Vec_801A4D30;

typedef struct Pair_801A4D30 {
    s32 a, b;
} Pair_801A4D30;

typedef struct Obj_801A4D30 {
    u8 pad0[0x1C];
    s8 state;
    u8 pad1D;
    s16 timer;
    s32 result;
    void *list;
    void *window;
    void *card;
} Obj_801A4D30;

extern "C" {
void queue_destruction__7TObjectFv(void *);
void set_active_camera_pose(void *, void *);
s32 activate_camera_mode(s32 arg0);
s32 verify_system_file__23TAdSinglePlyChrSelectGCFPv(void);
s32 pso_system_load_gc(void);
void *update_window_mode_from_progress__6TLobbyFPv(void *, void *);
s32 TAdSinglePlyChrSelectGC__sub_8033B9F8(void *);
extern Vec_801A4D30 lbl_80446940;
extern Vec_801A4D30 lbl_8044694C;
extern Pair_801A4D30 lbl_80446958[];
extern Pair_801A4D30 lbl_80446960[];
extern const f32 lbl_805DC0A8;
void TUnk_804C2298::run_task() {
    Obj_801A4D30 *self = (Obj_801A4D30 *)this;
    Vec_801A4D30 pos = lbl_80446940;
    Vec_801A4D30 target = lbl_8044694C;
    activate_camera_mode(9);
    set_active_camera_pose(&pos, &target);
    switch (self->state) {
    case 0:
        self->state = 1;
    case 1:
        if (self->list != NULL) {
            if (TWindowShortListCtrl__sub_801A5144(self->list) != 0) {
                self->state = 2;
            } else {
                self->result = TWindowShortListCtrl__sub_801A513C(self->list);
                if (self->result != 4) {
                    self->state = 2;
                }
            }
        }
        break;
    case 2:
        if (self->list != NULL) {
            queue_destruction__7TObjectFv(self->list);
            self->list = NULL;
        }
        self->state = 3;
    case 3:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            self->state = 4;
        }
        break;
    case 4:
        if (self->card == NULL) {
            self->card = ((TCheckMemoryCard *)self)->create(NULL, NULL);
        }
        self->state = 5;
    case 5:
        if (self->card != NULL && TAdSinglePlyChrSelectGC__sub_8033B9F8(self->card) == 1) {
            queue_destruction__7TObjectFv(self->card);
            self->card = NULL;
            if (verify_system_file__23TAdSinglePlyChrSelectGCFPv() != 0) {
                pso_system_load_gc();
            }
            self->timer = 0;
            self->state = 6;
        }
        break;
    case 6:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            self->state = 8;
        } else {
            Pair_801A4D30 a = lbl_80446958[0];
            Pair_801A4D30 b = lbl_80446960[0];
            self->window = update_window_mode_from_progress__6TLobbyFPv(&a, &b);
            ((TWindowMessage *)(self->window))->append_line(TQuestVmDownLoadServer__sub_8006EF6C(0xC), 1);
            self->state = 7;
        }
        break;
    case 7:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            ((TWindowBase *)self->window)->close();
            self->window = NULL;
            self->state = 8;
        }
        break;
    case 8:
        self->timer++;
        if ((f32)self->timer > lbl_805DC0A8) {
            ((TUnk_804C2298 *)self)->sub_801A4CA4();
            self->state = 9;
            TAdMultiChgGameModeGC::request_scene_change();
        }
        break;
    case 9:
        break;
    }
}

}
