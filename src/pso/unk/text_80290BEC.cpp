#include "pso/system/ControllerInput.h"
#include "pso/system/task/TMainTask.h"
#include "types.h"
#include "pso/unk/text_80290BEC.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"

extern "C" {
s32 TKeyBoardControl__sub_8000F92C();
void request_main_phase(s32 arg0);
}
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern "C" {
void func_803DCDFC__Fv(void);
void fn_80290BEC(void) {
    s32 *var_r3;
    TLobby::stop_audio_streams();
    var_r3 = (s32 *)&main_task;
    var_r3 = (s32 *)&main_task;
    main_task.delete_layer_children();
    TLobby::free_all_resources();
    render_tick();
}
void run_main_frame(void) {
    s32 *var_r3;
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    var_r3 = (s32 *)&main_task;
    var_r3 = (s32 *)&main_task;
    main_task.begin_frame();
    var_r3 = (s32 *)&main_task;
    var_r3 = (s32 *)&main_task;
    main_task.run_task();
    var_r3 = (s32 *)&main_task;
    var_r3 = (s32 *)&main_task;
    main_task.render();
    var_r3 = (s32 *)&main_task;
    var_r3 = (s32 *)&main_task;
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::run_save_load_sequence();
    TAdSinglePlyChrSelectGC::noop();
    if (static_cast<s8>(func_801A5E54()) != 0) {
        TKeyBoardControl__sub_8000F92C();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        var_r3 = NULL;
        request_main_phase(0);
    }
    render_tick();
}
}
