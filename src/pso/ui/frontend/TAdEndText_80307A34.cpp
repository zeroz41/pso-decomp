#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdEndText_80307A34.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TUnk_804E71A0.h"
#include "pso/system/ControllerInput.h"
#include "pso/unk/text_803DCDFC.h"
#include "pso/unk/text_800FA464.h"
#include "pso/render/GinjaView.h"
#include "pso/effect/particle/TParticleCtrl.h"

// .sbss 0x805D6A58-0x805D6A60 is one TU's run: 0x805D6A5C is not 8-aligned, so both words belong to the TU that
// starts at 0x805D6A58 after TAdGameStartBackGC's pad word. Between TAdGameStartBackGC and TBoss7Crawfish only this
// unit (start_ending_sequence) and TObjPlayer_80307618 (the TUnk_804E71A0 it creates) use them.
s32 ending_sequence_active;
s32 ending_movie_active_flag;

void TAdEndText::cleanup() { ending_sequence_active = 0; main_task.delete_layer_children(); TLobby::free_ending_callback(); TLobby::free_keyboard_soft_resources(); TAdEndText::free_resources(); render_tick(); }
void TKeyBoardControl::run_main_frame() {
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    if (static_cast<s8>(func_801A5E54()) != 0) {
        TKeyBoardControl__sub_8000F92C();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        request_main_phase(0);
    }
    render_tick();
}
void start_ending_sequence(void) {
    ending_sequence_active = 1;
    set_screen_size(1.0f, 0.85f);
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    set_queued_main_phase(2);
    TKeyBoardControl__sub_8000F90C(2);
    TAdEndText::load_ending_font();
    TLobby::update_keyboard_menu();
    TLobby::set_ending_callback();
    new TUnk_804E71A0;
    render_tick();
}
