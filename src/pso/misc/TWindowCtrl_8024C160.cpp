#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_8030C340.h"
#include "pso/TObject.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
struct TWindowCtrl_8024C160 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1C[0x2C - 0x1C];
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    void *f44;
    void *objs[12];
    void *wins78[3];
    void *wins84[4];
};

struct TWindowCtrl_8024C308 {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    s16 f1C;
    s16 f1E;
    s16 f20;
    s16 f22;
    s32 f24;
    u16 f28;
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    void *f44;
    void *objs[12];
    void *wins78[3];
    void *wins84[4];
    u8 f94[4];
};

extern "C" {
void __dt__7TObjectFv(void *, int);
void __dl__7TObjectFPv(void *);
extern u8 __vt__11TWindowCtrl[];
extern void *TWindowCtrl__active_window;
TWindowCtrl_8024C160 *__dt__11TWindowCtrlFv(TWindowCtrl_8024C160 *self, s16 flag);
s32 is_split_screen();
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void *);
void *TWindowBreakIn__ct(void *);
void *__ct__11TWindowChatFP7TObjectPv(void *, s32, void *);
void *__ct__17TWindowCtrlPlayerFP7TObjectl(void *, void *, s32);
extern s32 lbl_805D38C8;
extern s32 local_client_id;
extern s32 tl_00;
TWindowCtrl_8024C308 *TWindowCtrl__ct(TWindowCtrl_8024C308 *self);
TWindowCtrl_8024C160 *__dt__11TWindowCtrlFv(TWindowCtrl_8024C160 *self, s16 flag) {
    s32 i;
    if (self != NULL) {
        self->vt = __vt__11TWindowCtrl;
        for (i = 3; i >= 0; i--) {
            if (self->wins84[i] != NULL) {
                ((TWindowBase *)(self->wins84[i]))->close();
                self->wins84[i] = NULL;
            }
        }
        if (self->f44 != NULL) {
            ((TWindowBase *)self->f44)->close();
            self->f44 = NULL;
        }
        if (self->f34 != NULL) {
            ((TWindowBase *)self->f34)->close();
            self->f34 = NULL;
        }
        if (self->f30 != NULL) {
            ((TWindowBase *)self->f30)->close();
            self->f30 = NULL;
        }
        if (self->f40 != NULL) {
            queue_destruction__7TObjectFv(self->f40);
            self->f40 = NULL;
        }
        if (self->f3C != NULL) {
            queue_destruction__7TObjectFv(self->f3C);
            self->f3C = NULL;
        }
        for (i = 2; i >= 0; i--) {
            if (self->wins78[i] != NULL) {
                ((TWindowBase *)(self->wins78[i]))->close();
                self->wins78[i] = NULL;
            }
        }
        for (i = 11; i >= 0; i--) {
            if (self->objs[i] != NULL) {
                queue_destruction__7TObjectFv(self->objs[i]);
                self->objs[i] = NULL;
            }
        }
        if (self->f38 != NULL) {
            queue_destruction__7TObjectFv(self->f38);
            self->f38 = NULL;
        }
        if (self->f2C != NULL) {
            ((TWindowBase *)self->f2C)->close();
            self->f2C = NULL;
        }
        if (TWindowCtrl__active_window == self) {
            TWindowCtrl__active_window = NULL;
        }
        __dt__7TObjectFv(self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
TWindowCtrl_8024C308 *TWindowCtrl__ct(TWindowCtrl_8024C308 *self) {
    s32 i;
    void *p;
    __ct__7TObjectFP7TObject(self);
    self->vt = __vt__11TWindowCtrl;
    self->f0 = lbl_805D38C8;
    if (TWindowCtrl__active_window != NULL) {
        queue_destruction__7TObjectFv(TWindowCtrl__active_window);
    }
    TWindowCtrl__active_window = self;
    self->f1C = 0;
    self->f1E = 0;
    self->f20 = 0;
    self->f22 = 0;
    self->f24 = 0;
    self->f28 = 0xFFFF;
    self->f2C = NULL;
    self->f30 = NULL;
    self->f34 = NULL;
    self->f38 = NULL;
    self->f3C = NULL;
    self->f40 = NULL;
    self->f44 = NULL;
    for (i = 0; i < 12; i++) {
        self->objs[i] = NULL;
    }
    for (i = 0; i < 3; i++) {
        self->wins78[i] = NULL;
    }
    for (i = 0; i < 4; i++) {
        self->wins84[i] = NULL;
    }
    p = __nw__7TObjectFUl(0x60);
    if (p != NULL) {
        p = TWindowBreakIn__ct(p);
    }
    self->f2C = p;
    if (is_split_screen() == 0) {
        p = __nw__7TObjectFUl(0x3C);
        if (p != NULL) {
            p = __ct__11TWindowChatFP7TObjectPv(p, tl_00, self->f94);
        }
        self->f38 = p;
        ((TWindowCtrl *)(self->f38))->set_flag1e_bit40();
    }
    if (is_split_screen() != 0) {
        for (i = 0; i < 4; i++) {
            p = __nw__7TObjectFUl(0x40);
            if (p != NULL) {
                p = __ct__17TWindowCtrlPlayerFP7TObjectl(p, self, i);
            }
            self->objs[i] = p;
            ((TObject *)(self->objs[i]))->suspend_update();
        }
    } else {
        p = __nw__7TObjectFUl(0x40);
        if (p != NULL) {
            p = __ct__17TWindowCtrlPlayerFP7TObjectl(p, self, local_client_id);
        }
        self->objs[local_client_id] = p;
        for (i = 0; i < 3; i++) {
            if (get_current_floor_area() != AREA_LOBBY && is_split_screen() == 0) {
                self->wins78[i] = create_party_status_window(i);
                ((TObject *)(self->wins78[i]))->suspend_update();
            }
        }
    }
    if (TObjPlayer::get_player_count() == 1) {
        TWindowCtrl::open_status_112();
    }
    return self;
}

}
