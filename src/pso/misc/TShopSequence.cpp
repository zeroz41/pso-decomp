#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TShopSequence.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TMessageWindowController.h"

struct VObj_802235A0_8022356C {
    virtual void m0(int);
};

struct RecoveredGlobal_802238D8___vt__13TShopSequence { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_802238D8___vt__13TShopSequence_size[sizeof(RecoveredGlobal_802238D8___vt__13TShopSequence) == 0x38 ? 1 : -1];
struct Del_80223850 {
    virtual ~Del_80223850();
};

extern "C" {
s32 get_entity_id(u32);
u32 create_message_window__24TMessageWindowControllerFlll(void *, s32, s32, s32);
u32 create_window__24TMessageWindowControllerFll(void *, s32, s32);
u8 * __ct__24TMessageWindowControllerFv(void *);
void *__ct__15TShopWindowBaseFv(void *arg0);
extern RecoveredGlobal_802238D8___vt__13TShopSequence __vt__13TShopSequence;
extern s32 TShopSequence__class_name;
u8 *TShopSequence__ct(u8 *arg0);
void *__dt__15TShopWindowBaseFv(void *self, s16 m);
s32 __dl__7TObjectFPv(void *);
s32 load_character_from_card__23TAdSinglePlyChrSelectGCFi(s32);
s32 activate_body_collision__10TObjPlayerFv();
s32 deactivate_body_collision__10TObjPlayerFv();
void *get_player_by_client_id(s32 i);
s32 suppress_slot__11TWindowCtrlFv(u16);
s32 unsuppress_slot__11TWindowCtrlFv(u16);
int display_message__24TMessageWindowControllerFPCcl(void*);
int format_guild_message__24TMessageWindowControllerFll(void*);
s32 is_split_screen();
int send_message__24TMessageWindowControllerFll(void*);
int format_shop_message__24TMessageWindowControllerFll(void*);

int TShopSequence::vfunc_10() {
    void *message_window_controller = *(void **)((s8 *)this + 0x28);
    if (message_window_controller != NULL) {
        return ((TMessageWindowController *)message_window_controller)->is_ready();
    }
    return 1;
}

void TShopSequence::close_message_window() {
    VObj_802235A0_8022356C *temp_r3;

    if (*(VObj_802235A0_8022356C **)((s8 *)this + 0x28) != NULL) {
        ((TMessageWindowController *)(*(VObj_802235A0_8022356C **)((s8 *)this + 0x28)))->close();
        temp_r3 = *(VObj_802235A0_8022356C **)((s8 *)this + 0x28);
        if (temp_r3 != NULL) {
            temp_r3->m0(1);
        }
        *(VObj_802235A0_8022356C **)((s8 *)this + 0x28) = NULL;
    }
}

u32 TShopSequence::create_message_window(s32 arg1, s32 arg2) {
    u8 *message_window_controller;
    u8 *temp_r3;
    message_window_controller = (u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x28));
    if (message_window_controller != NULL) {
        temp_r3 = (u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x24));
        if (temp_r3 != NULL) {
            return create_message_window__24TMessageWindowControllerFlll(*(u8 **)((s8 *)((u8 *)this) + 0x28), arg1, arg2, (s32) ((u16)get_entity_id((u32)temp_r3)));
        }
        return create_window__24TMessageWindowControllerFll(message_window_controller, arg1, arg2);
    }
    return 0U;
}

void TShopSequence::vfunc_9() { void* m = *(void**)((char*)this + 0x28); if (m) format_guild_message__24TMessageWindowControllerFll(m); }
void TShopSequence::vfunc_8() { void* m = *(void**)((char*)this + 0x28); if (m) send_message__24TMessageWindowControllerFll(m); }
void TShopSequence::vfunc_7() { void* m = *(void**)((char*)this + 0x28); if (m) display_message__24TMessageWindowControllerFPCcl(m); }
void TShopSequence::vfunc_6() { void* m = *(void**)((char*)this + 0x28); if (m) format_shop_message__24TMessageWindowControllerFll(m); }
void TShopSequence::close_if_single_screen() {
    if ((TAdSinglePlyChrSelectGC::get_game_mode() != 0) && (is_split_screen() == 0)) {
        load_character_from_card__23TAdSinglePlyChrSelectGCFi(0);
    }
}
void TShopSequence::close_window() {
    s32 var_r31;

    if ((u32) *(u32 *)((s8 *)this + 0x24) != 0U) {
        unsuppress_slot__11TWindowCtrlFv(get_entity_id(*(u32 *)((s8 *)this + 0x24)));
        if (TRaderMapCore::is_not_split_screen() != 1) {
            var_r31 = 0;
            do {
                if (get_player_by_client_id(var_r31) != 0U) {
                    activate_body_collision__10TObjPlayerFv();
                }
                var_r31 += 1;
            } while (var_r31 < 4);
        }
        TObjPlayer::clear_lobby_flag((void *)(*(u32 *)((s8 *)this + 0x24)));
    }
}
void TShopSequence::restore_player_state() {
    s32 var_r31;

    if ((u32) *(u32 *)((s8 *)this + 0x24) != 0U) {
        ((TObjPlayer *)(*(void **)((s8 *)this + 0x24)))->init_effect_5f0();
        if (TRaderMapCore::is_not_split_screen() != 1) {
            var_r31 = 0;
            do {
                if (get_player_by_client_id(var_r31) != 0U) {
                    deactivate_body_collision__10TObjPlayerFv();
                }
                var_r31 += 1;
            } while (var_r31 < 4);
        }
        suppress_slot__11TWindowCtrlFv(get_entity_id(*(u32 *)((s8 *)this + 0x24)));
    }
}
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TShopSequence.value;
        if (*(Del_80223850 **)((s8 *)arg0 + 0x28) != NULL) {
            delete *(Del_80223850 **)((s8 *)arg0 + 0x28);
            *(Del_80223850 **)((s8 *)arg0 + 0x28) = NULL;
        }
        __dt__15TShopWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TShopSequence__ct(u8 *shop_window_base) {
    s32 temp_r3;
    s32 var_r0;
    __ct__15TShopWindowBaseFv(shop_window_base);
    *(s32 **)((s8 *)shop_window_base + 0x18) = &__vt__13TShopSequence.value;
    *(s32 *)((s8 *)shop_window_base + 0) = (s32) TShopSequence__class_name;
    temp_r3 = ((TAdSinglePlyChrSelectGC *)((void *)0x210))->alloc();
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (__ct__24TMessageWindowControllerFv((void *) temp_r3));
    }
    *(s32 *)((s8 *)shop_window_base + 0x28) = var_r0;
    return shop_window_base;
}

}
