#include "pso/system/ControllerInput.h"
#include "pso/system/task/TMainTask.h"
#include "types.h"
#include "pso/render/gjSystem.h"
#include "pso/system/MainFrame.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/network/TLobby.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/AsyncFileRead.h"

void fn_80290BEC(void) {
    s32 *task;
    TLobby::stop_audio_streams();
    task = (s32 *)&main_task;
    task = (s32 *)&main_task;
    main_task.delete_layer_children();
    TLobby::free_all_resources();
    render_tick();
}
extern "C" {
void run_main_frame(void) {
    s32 *task;
    begin_gx_frame();
    controller_stuff();
    update_keyboard_input_frame();
    task = (s32 *)&main_task;
    task = (s32 *)&main_task;
    main_task.begin_frame();
    task = (s32 *)&main_task;
    task = (s32 *)&main_task;
    main_task.run_task();
    task = (s32 *)&main_task;
    task = (s32 *)&main_task;
    main_task.render();
    task = (s32 *)&main_task;
    task = (s32 *)&main_task;
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::run_save_load_sequence();
    TAdSinglePlyChrSelectGC::noop();
    if (static_cast<s8>(poll_reset_request()) != 0) {
        switch_to_fallback_main_phase();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        task = NULL;
        request_main_phase(0);
    }
    render_tick();
}
}
