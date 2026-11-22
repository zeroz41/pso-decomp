#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSetLevelUp.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/player/PlayerSlots.h"


struct ByteBlock_16 { u8 bytes[0x16]; };

struct VOff_8026DD70_arg0_8026DCE0 { char pad_0[0x24]; char f_24[1]; };

extern "C" {

void __ct__7TObjectFP7TObject(void *);
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
    TObjPlayer *player;

    text_builder_reset();
    text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x46)));
    switch (state) {
    case 0:
    case 1:
        player = get_player_by_client_id(client);
        if (player != NULL && player->get_stats() != 0) {
            text_builder_append((u8 *)"LEVEL ");
            text_builder_append_int(player->get_actor_level_index() + 1);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 2;
        }
        break;
    case 2:
        if (hp_gain > 0) {
            text_builder_append((u8 *)"HP +");
            text_builder_append_int(hp_gain);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 3;
            break;
        }
    case 3:
        if (tp_gain > 0) {
            text_builder_append((u8 *)"TP +");
            text_builder_append_int(tp_gain);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 4;
            break;
        }
    case 4:
        if (stat_gains[0] > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x83)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(stat_gains[0]);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 5;
            break;
        }
    case 5:
        if (stat_gains[1] > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x84)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(stat_gains[1]);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 6;
            break;
        }
    case 6:
        if (stat_gains[2] > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x85)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(stat_gains[2]);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 7;
            break;
        }
    case 7:
        if (stat_gains[3] > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x86)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(stat_gains[3]);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 8;
            break;
        }
    case 8:
        if (stat_gains[4] > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x87)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(stat_gains[4]);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 9;
            break;
        }
    case 9:
        queue_destruction();
        break;
    }
    timer = 0x16;
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
    temp_r5 = ((TWindowSetLevelUp *)arg0)->timer;
    ((TWindowSetLevelUp *)arg0)->timer = (temp_r5 - 1);
    if (temp_r5 <= 0) {
        ((TWindowSetLevelUp *)arg0)->update_stat_messages();
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
    ((TWindowSetLevelUp *)window_set_level_up)->timer = 0;
    ((TWindowSetLevelUp *)window_set_level_up)->client = (saddr)arg3;
    ((TWindowSetLevelUp *)window_set_level_up)->state = 0;
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
