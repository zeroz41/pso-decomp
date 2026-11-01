#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/TObject.h"
#include "pso/misc/TWindow.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TQuestListOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/quest/TQuestListVM.h"

extern "C" {

typedef void (*Cb_802171BC)(void *);

struct QuestList_802171BC {
    u8 pad[0x20];
    u32 state;
    u8 pad24[4];
    Cb_802171BC cancelled;
    Cb_802171BC accepted;
    Cb_802171BC download;
    void *owner;
};

struct Win_80217344 {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    u8 pad1C[8];
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    u8 pad4C[4];
    s32 f50;
    void *f54;
};

void queue_destruction__7TObjectFv(void *);
void vfunc_11__17TQuestListOfflineFv(QuestList_802171BC *self);
void * close_shop_subwindows__17TQuestListOfflineFs(void *arg0, s16 arg1);
void *__dt__15TShopWindowBaseFv(void *self, s16 m);
void __ct__15TShopWindowBaseFv(void *, s32);
void __dl__7TObjectFPv(void *);

extern s32 TQuestListOffline__class_name;

extern "C" void vfunc_6__15TShopWindowBaseFv();
extern "C" void vfunc_8__15TShopWindowBaseFv();
extern "C" void display_message__15TShopWindowBaseFPCcl();
extern "C" void display_guild_message__15TShopWindowBaseFll();
extern "C" void vfunc_10__15TShopWindowBaseFv();
extern "C" void run_task__15TShopWindowBaseFv();
extern "C" u8 lbl_8044BDA0[];
extern "C" u8 lbl_8044BDA8[];
extern "C" u8 lbl_8044BDB0[];
extern "C" u8 lbl_8044BDB8[];
extern "C" u8 lbl_8044BDC0[];
extern "C" u8 lbl_8044BDC8[];
extern "C" u8 lbl_8044BDD0[];
extern "C" u8 lbl_8044BDD8[];
extern "C" u8 lbl_8044BDE0[];
extern "C" u8 lbl_8044BDE8[];
extern "C" u8 lbl_8044BDF0[];
extern "C" u8 lbl_8044BDF8[];
extern "C" u8 lbl_8044BE00[];
extern "C" u8 lbl_8044BE08[];
extern "C" u8 lbl_8044BE10[];
extern "C" u8 lbl_8044BE18[];
extern "C" u8 lbl_8044BE20[];
extern "C" u8 lbl_8044BE28[];
extern "C" u8 lbl_8044BE30[];
extern "C" u8 lbl_8044BE38[];
extern "C" u8 lbl_8044BE40[];
extern "C" u8 lbl_8044BE48[];
extern "C" u8 lbl_8044BE50[];
extern "C" u8 lbl_8044BE58[];
extern "C" u8 lbl_8044BE60[];
extern "C" u8 lbl_8044BE68[];
extern "C" u8 lbl_8044BE70[];
extern "C" u8 lbl_8044BE78[];
extern "C" u8 lbl_8044BE80[];
extern "C" u8 lbl_805DC690[];
extern "C" void render__7TObjectFv();
extern "C" void render_shadows__7TObjectFv();
void *offline_quest_catalog_ep1[196] = {
    (void *)0x1, (void *)0x0, (void *)0x1, (void *)0x2,
    (void *)0x6a006b, (void *)0x0, (void *)&lbl_8044BDA0, (void *)0x2,
    (void *)0x3, (void *)0x4, (void *)0x5, (void *)0x660067,
    (void *)0x0, (void *)&lbl_8044BDA8, (void *)0x3, (void *)0x6,
    (void *)0x7, (void *)0x8, (void *)0x640065, (void *)0x0,
    (void *)&lbl_8044BDB0, (void *)0x4, (void *)0x9, (void *)0xa,
    (void *)0xb, (void *)0x680069, (void *)0x0, (void *)&lbl_8044BDB8,
    (void *)0x5, (void *)0xc, (void *)0xd, (void *)0xe,
    (void *)0x6c006d, (void *)0x0, (void *)&lbl_8044BDC0, (void *)0x6,
    (void *)0xf, (void *)0x10, (void *)0x11, (void *)0x6e006f,
    (void *)0x0, (void *)&lbl_8044BDC8, (void *)0x7, (void *)0x12,
    (void *)0x13, (void *)0x14, (void *)0x700071, (void *)0x0,
    (void *)&lbl_8044BDD0, (void *)0x8, (void *)0x15, (void *)0x16,
    (void *)0x17, (void *)0x720073, (void *)0x0, (void *)&lbl_8044BDD8,
    (void *)0x9, (void *)0x18, (void *)0x19, (void *)0x1a,
    (void *)0x740075, (void *)0x0, (void *)&lbl_8044BDE0, (void *)0xa,
    (void *)0x1b, (void *)0x1c, (void *)0x1d, (void *)0x760077,
    (void *)0x0, (void *)&lbl_8044BDE8, (void *)0xb, (void *)0x1e,
    (void *)0x1f, (void *)0x20, (void *)0x780079, (void *)0x0,
    (void *)&lbl_8044BDF0, (void *)0xc, (void *)0x21, (void *)0x22,
    (void *)0x23, (void *)0x7a007b, (void *)0x0, (void *)&lbl_8044BDF8,
    (void *)0xd, (void *)0x24, (void *)0x25, (void *)0x26,
    (void *)0x7c007d, (void *)0x0, (void *)&lbl_8044BE00, (void *)0xe,
    (void *)0x27, (void *)0x28, (void *)0x29, (void *)0x7e007f,
    (void *)0x0, (void *)&lbl_8044BE08, (void *)0xf, (void *)0x2a,
    (void *)0x2b, (void *)0x2c, (void *)0x800081, (void *)0x0,
    (void *)&lbl_8044BE10, (void *)0x10, (void *)0x2d, (void *)0x2e,
    (void *)0x2f, (void *)0x820083, (void *)0x0, (void *)&lbl_8044BE18,
    (void *)0x11, (void *)0x30, (void *)0x31, (void *)0x32,
    (void *)0x840085, (void *)0x0, (void *)&lbl_8044BE20, (void *)0x12,
    (void *)0x33, (void *)0x34, (void *)0x35, (void *)0x860087,
    (void *)0x0, (void *)&lbl_8044BE28, (void *)0x13, (void *)0x36,
    (void *)0x37, (void *)0x38, (void *)0x880089, (void *)0x0,
    (void *)&lbl_8044BE30, (void *)0x14, (void *)0x39, (void *)0x3a,
    (void *)0x3b, (void *)0x8a008b, (void *)0x0, (void *)&lbl_8044BE38,
    (void *)0x15, (void *)0x3c, (void *)0x3d, (void *)0x3e,
    (void *)0x8c008d, (void *)0x0, (void *)&lbl_8044BE40, (void *)0x16,
    (void *)0x3f, (void *)0x40, (void *)0x41, (void *)0x8e008f,
    (void *)0x0, (void *)&lbl_8044BE48, (void *)0x17, (void *)0x42,
    (void *)0x43, (void *)0x44, (void *)0x900091, (void *)0x0,
    (void *)&lbl_8044BE50, (void *)0x18, (void *)0x45, (void *)0x46,
    (void *)0x47, (void *)0x920093, (void *)0x0, (void *)&lbl_8044BE58,
    (void *)0x19, (void *)0x48, (void *)0x49, (void *)0x4a,
    (void *)0x940095, (void *)0x0, (void *)&lbl_8044BE60, (void *)0x1a,
    (void *)0x4b, (void *)0x4c, (void *)0x4d, (void *)0x9f00a0,
    (void *)0x0, (void *)&lbl_8044BE68, (void *)0x0, (void *)0x57,
    (void *)0x58, (void *)0x59, (void *)0xffffffff, (void *)0x1,
    (void *)&lbl_805DC690, (void *)0xffffffff, (void *)0xffffffff, (void *)0xffffffff,
    (void *)0xffffffff, (void *)0xffffffff, (void *)0xffffffff, (void *)&lbl_805DC690,
};
void *lbl_804C9C10[35] = {
    (void *)0x1b, (void *)0x4e, (void *)0x4f, (void *)0x50,
    (void *)0xffff00a1, (void *)0x0, (void *)&lbl_8044BE70, (void *)0x1c,
    (void *)0x51, (void *)0x52, (void *)0x53, (void *)0xa200a3,
    (void *)0x0, (void *)&lbl_8044BE78, (void *)0x1d, (void *)0x54,
    (void *)0x55, (void *)0x56, (void *)0xa400a5, (void *)0x0,
    (void *)&lbl_8044BE80, (void *)0x0, (void *)0x57, (void *)0x58,
    (void *)0x59, (void *)0xffffffff, (void *)0x1, (void *)&lbl_805DC690,
    (void *)0xffffffff, (void *)0xffffffff, (void *)0xffffffff, (void *)0xffffffff,
    (void *)0xffffffff, (void *)0xffffffff, (void *)&lbl_805DC690,
};
void *lbl_804C9C9C[12] = {
    (void *)0x0, (void *)0x0, (void *)&close_shop_subwindows__17TQuestListOfflineFs, (void *)&run_task__15TShopWindowBaseFv,
    (void *)&render__7TObjectFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__15TShopWindowBaseFv, (void *)&display_message__15TShopWindowBaseFPCcl,
    (void *)&vfunc_8__15TShopWindowBaseFv, (void *)&display_guild_message__15TShopWindowBaseFll, (void *)&vfunc_10__15TShopWindowBaseFv, (void *)&vfunc_11__17TQuestListOfflineFv,
};
#define lbl_804C9C9C ((s32 *)lbl_804C9C9C)

void TQuestListOffline::vfunc_11() {
    QuestList_802171BC *self = (QuestList_802171BC *)this;
    switch (self->state) {
    case 0:
        ((TQuestListOffline *)self)->init_quest_list_window();
        break;
    case 1:
        ((TQuestListOffline *)self)->update_list_navigation();
        break;
    case 2:
        handle_confirm_dialog((TShopWindowBase *)self);
        break;
    case 3:
        if (self->accepted) {
            self->accepted(self->owner);
        }
        queue_destruction__7TObjectFv(self);
        break;
    case 5:
        if (self->cancelled) {
            self->cancelled(self->owner);
        }
        queue_destruction__7TObjectFv(self);
        break;
    case 4:
        if (self->download) {
            self->download(self->owner);
        }
        queue_destruction__7TObjectFv(self);
        break;
    case 6:
        break;
    }
}

void *TQuestListOffline::close_shop_subwindows(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804C9C9C;
        if (*(void **)((s8 *)this + 0x3C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x3C)))->close(); *(s32 *)((s8 *)this + 0x3C) = 0; }
        if (this->m_38 != NULL) { ((TWindowBase *)this->m_38)->close(); *(s32 *)((s8 *)this + 0x3C) = 0; }
        if (this->m_40 != NULL) { ((TWindowBase *)this->m_40)->close(); this->m_40 = 0; }
        if (*(void **)((s8 *)this + 0x44) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x44)))->close(); *(s32 *)((s8 *)this + 0x44) = 0; }
        __dt__15TShopWindowBaseFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TQuestListOffline__ct(Win_80217344 *self, s32 shop_window_base, s32 arg2, s32 arg3) {
    __ct__15TShopWindowBaseFv(self, shop_window_base);
    self->vt = (void *)((void * *)lbl_804C9C9C);
    self->f0 = TQuestListOffline__class_name;
    self->f34 = arg2;
    self->f3C = 0;
    self->f38 = 0;
    self->f40 = 0;
    self->f44 = 0;
    self->f24 = arg3;
    self->f48 = 0;
    self->f50 = 0;
    self->f28 = 0;
    self->f2C = 0;
    self->f30 = 0;
    if (TLobby::get_instance() == 0) {
        self->f54 = (void *)offline_quest_catalog_ep1;
    } else {
        self->f54 = (void *)lbl_804C9C10;
    }
    ((TShopWindowBase *)self)->set_field_20(0);
    return self;
}

}
