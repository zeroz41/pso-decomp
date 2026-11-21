#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSetLevelUp.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"


struct ByteBlock_16 { u8 bytes[0x16]; };

struct VOff_8026DD70_arg0_8026DCE0 { char pad_0[0x24]; char f_24[1]; };

struct VObj_8026DA44 {
    char pad[0x18];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual s32 get_level();
};

typedef struct LvUp_8026DA44 {
    u8 pad0[0x1C];
    s8 state;
    u8 pad1d;
    s16 timer;
    saddr client;
    s16 d24;
    s16 d26;
    s16 d28;
    s16 d2a;
    s16 d2c;
    u8 pad2e[0xC];
    s16 d3a;
    s16 d3c;
} LvUp_8026DA44;
extern "C" {

void *get_player_by_client_id(s32 i);
void __ct__7TObjectFP7TObject(void *);
void update_stat_messages__17TWindowSetLevelUpFv(LvUp_8026DA44 *self);
void render__17TWindowSetLevelUpFv(void);
void * __ct__17TWindowSetLevelUpFv(void *arg0, void *arg1, void *arg2, void *arg3);
void TWindowSetLevelUp__sub_8026DE28(void* p, s32 v);
}
void text_builder_reset(void);
extern "C" {

void *__dt__17TWindowSetLevelUpFv(void *arg0, s16 arg1);
void run_task__17TWindowSetLevelUpFv(u8 *arg0);
void render_shadows__7TObjectFv(void);
void __dt__7TObjectFv(void *, int);
void *__vt__17TWindowSetLevelUp[6] = {
    0, 0,
    (void *)__dt__17TWindowSetLevelUpFv,
    (void *)run_task__17TWindowSetLevelUpFv,
    (void *)render__17TWindowSetLevelUpFv,
    (void *)render_shadows__7TObjectFv,
};
const char *TWindowSetLevelUp__name = "TWindowSetLevelUp";

void TWindowSetLevelUp::update_stat_messages() {
    LvUp_8026DA44 *self = (LvUp_8026DA44 *)this;
    VObj_8026DA44 *pl;

    text_builder_reset();
    text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x46)));
    switch (self->state) {
    case 0:
    case 1:
        pl = (VObj_8026DA44 *)get_player_by_client_id(self->client);
        if (pl != NULL && ((TObjPlayer *)pl)->get_stats() != 0) {
            text_builder_append((u8 *)"LEVEL ");
            text_builder_append_int(pl->get_level() + 1);
            TWindowCtrl::set_window_flags_off(self->client, (saddr)get_shared_text_buffer());
            self->state = 2;
        }
        break;
    case 2:
        if (self->d3a > 0) {
            text_builder_append((u8 *)"HP +");
            text_builder_append_int(self->d3a);
            TWindowCtrl::set_window_flags_off(self->client, (saddr)get_shared_text_buffer());
            self->state = 3;
            break;
        }
    case 3:
        if (self->d3c > 0) {
            text_builder_append((u8 *)"TP +");
            text_builder_append_int(self->d3c);
            TWindowCtrl::set_window_flags_off(self->client, (saddr)get_shared_text_buffer());
            self->state = 4;
            break;
        }
    case 4:
        if (self->d24 > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x83)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(self->d24);
            TWindowCtrl::set_window_flags_off(self->client, (saddr)get_shared_text_buffer());
            self->state = 5;
            break;
        }
    case 5:
        if (self->d26 > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x84)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(self->d26);
            TWindowCtrl::set_window_flags_off(self->client, (saddr)get_shared_text_buffer());
            self->state = 6;
            break;
        }
    case 6:
        if (self->d28 > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x85)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(self->d28);
            TWindowCtrl::set_window_flags_off(self->client, (saddr)get_shared_text_buffer());
            self->state = 7;
            break;
        }
    case 7:
        if (self->d2a > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x86)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(self->d2a);
            TWindowCtrl::set_window_flags_off(self->client, (saddr)get_shared_text_buffer());
            self->state = 8;
            break;
        }
    case 8:
        if (self->d2c > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x87)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(self->d2c);
            TWindowCtrl::set_window_flags_off(self->client, (saddr)get_shared_text_buffer());
            self->state = 9;
            break;
        }
    case 9:
        ((TObject *)self)->queue_destruction();
        break;
    }
    self->timer = 0x16;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void render__17TWindowSetLevelUpFv(void) {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void run_task__17TWindowSetLevelUpFv(u8 *arg0) {
    s16 temp_r5;
    temp_r5 = *(s16 *)((s8 *)arg0 + 0x1E);
    *(s16 *)((s8 *)arg0 + 0x1E) = (temp_r5 - 1);
    if (temp_r5 <= 0) {
        ((s32 (*)(void))update_stat_messages__17TWindowSetLevelUpFv)();
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void *__dt__17TWindowSetLevelUpFv(void *object, s16 arg1) {
    if (object != NULL) {
        *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__17TWindowSetLevelUp;
        __dt__7TObjectFv(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void *__ct__17TWindowSetLevelUpFv(void *window_set_level_up, void *arg1, void *arg2, void *arg3) {
    struct VOff_8026DD70_arg0_8026DCE0 *self = (struct VOff_8026DD70_arg0_8026DCE0 *)window_set_level_up;
    __ct__7TObjectFP7TObject(window_set_level_up);
    *(s32 **)((s8 *)window_set_level_up + 0x18) = (s32 *)__vt__17TWindowSetLevelUp;
    ((TObjPlayer *)(self->f_24))->reset_sub_status_disp();
    ((TWindowSetLevelUp *)window_set_level_up)->m_name = TWindowSetLevelUp__name;
    ((TWindowSetLevelUp *)(self->f_24))->copy_stat_block((saddr)arg2);
    *(u16 *)((s8 *)window_set_level_up + 0x1E) = 0;
    *(void **)((s8 *)window_set_level_up + 0x20) = arg3;
    *(u8 *)((s8 *)window_set_level_up + 0x1C) = 0;
    return window_set_level_up;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void TWindowSetLevelUp::copy_stat_block(saddr arg1) {
    saddr arg0 = (saddr)this;
    *(ByteBlock_16 *)(arg0) = *(const ByteBlock_16 *)(arg1);
    *(s16 *)((s8 *)arg0 + 0x16) = (s16) *(s16 *)((s8 *)arg1 + 0x16);
    *(s16 *)((s8 *)arg0 + 0x18) = (s16) *(s16 *)((s8 *)arg1 + 0x18);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void TWindowSetLevelUp__sub_8026DE28(void* p, s32 v) { *(s32*)((char*)p + 0x88) = v; }
}
#pragma pop
