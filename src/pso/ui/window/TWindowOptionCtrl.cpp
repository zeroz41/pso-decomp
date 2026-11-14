#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_8023F160.h"
#include "pso/unk/text_8036A3CC.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 play_area_music();
u32 create_menu__17TWindowOptionCtrlFv(void *);

void TWindowOptionCtrl::set_params(void *arg0, s16 arg1, s8 arg2) {
    void *temp_r3;

    temp_r3 = TAdSinglePlyChrSelectGC::get_global_state();
    if (temp_r3 != NULL) {
        *(s16 *)((s8 *)temp_r3 + 4) = arg1;
        *(s8 *)((s8 *)temp_r3 + 6) = arg2;
    }
}

void TWindowOptionCtrl::apply_selection_change() {
    if ((s16) *(s16 *)((s8 *)this + 0x1E) != (s16) *(s16 *)((s8 *)this + 0x20)) {
        TLobby::stop_audio_streams();
        TLobby::set_sound_output_mode(*(s16 *)((s8 *)this + 0x20));
        TLobby::init_layout_positions();
    }
}

void TWindowOptionCtrl::init_selection_indices() {
    s16 temp_r3;

    temp_r3 = TLobby::init_sound_mode();
    *(s16 *)((s8 *)this + 0x1E) = temp_r3;
    *(s16 *)((s8 *)this + 0x20) = temp_r3;
}

void TWindowOptionCtrl::apply_and_close(s32 arg1) {
    TLobby::stop_audio_streams();
    TLobby::stop_audio_streams();
    TLobby::close_option_window();
    get_bgm_filename(arg1);
    play_area_music();
    this->m_1d = (u8) (this->m_1d | 2);
}

s32 TWindowOptionCtrl::handle_input(s32 language) {
    if (TLanguage::set_language((s8) language) != 0) {
        fn_8023F160();
        fn_8023F18C();
        if ((u32) *(u32 *)((s8 *)this + 0x34) != 0U) {
            ((TObject *)(*(void **)((s8 *)this + 0x34)))->queue_destruction();
            *(u32 *)((s8 *)this + 0x34) = 0U;
        }
        if ((u32) *(u32 *)((s8 *)this + 0x28) != 0U) {
            ((TObject *)(*(void **)((s8 *)this + 0x28)))->queue_destruction();
            *(u32 *)((s8 *)this + 0x28) = 0U;
        }
        *(u32 *)((s8 *)this + 0x28) = create_menu__17TWindowOptionCtrlFv(this);
        window_request_refresh((u8 *)(*(u32 *)((s8 *)this + 0x28)));
        return 1;
    }
    return 0;
}

}
