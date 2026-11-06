#include "pso/system/task/TMainTask.h"
#include "types.h"
#include "pso/unk/text_80290BEC.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_80290BEC_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_80290C20_main_task {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
s32 TKeyBoardControl__sub_8000F92C();
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
s8 func_801A5E54__Fv();
void run_save_load_sequence__23TAdSinglePlyChrSelectGCFv(void);
}
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern "C" {
void func_803DCDFC__Fv(void);
typedef char RecoveredGlobal_80290BEC_main_task_size[sizeof(RecoveredGlobal_80290BEC_main_task) == 0x34 ? 1 : -1];
void fn_80290BEC(void) {
    s32 *var_r3;
    TLobby::stop_audio_streams();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80290BEC_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80290BEC_main_task *)&main_task).value);
    main_task.delete_layer_children();
    TLobby::free_all_resources();
    render_tick();
}
typedef char RecoveredGlobal_80290C20_main_task_size[sizeof(RecoveredGlobal_80290C20_main_task) == 0x34 ? 1 : -1];
void run_main_frame(void) {
    s32 *var_r3;
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80290C20_main_task *)&(*(RecoveredGlobal_80290BEC_main_task *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80290C20_main_task *)&(*(RecoveredGlobal_80290BEC_main_task *)&main_task)).value);
    main_task.begin_frame();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80290C20_main_task *)&(*(RecoveredGlobal_80290BEC_main_task *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80290C20_main_task *)&(*(RecoveredGlobal_80290BEC_main_task *)&main_task)).value);
    main_task.run_task();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80290C20_main_task *)&(*(RecoveredGlobal_80290BEC_main_task *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80290C20_main_task *)&(*(RecoveredGlobal_80290BEC_main_task *)&main_task)).value);
    main_task.render();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80290C20_main_task *)&(*(RecoveredGlobal_80290BEC_main_task *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80290C20_main_task *)&(*(RecoveredGlobal_80290BEC_main_task *)&main_task)).value);
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
    TAdSinglePlyChrSelectGC::noop();
    if (func_801A5E54__Fv() != 0) {
        TKeyBoardControl__sub_8000F92C();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        var_r3 = NULL;
        TKeyBoardControl__sub_8000F9CC(0);
    }
    render_tick();
}
}
