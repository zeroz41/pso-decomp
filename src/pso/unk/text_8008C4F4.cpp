#include "pso/system/task/TMainTask.h"
#include "types.h"
#include "pso/unk/text_8008C4F4.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_8008C534_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_8008C4F4_lbl_8048E7C0 {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_8008C4F4_main_task {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
s32 TKeyBoardControl__sub_8000F92C();
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
s8 func_801A5E54__Fv();
void func_803DCDFC__Fv(void);
s32 call_funcs_reverse__6TLobbyFPvUi(void *, int);
extern RecoveredGlobal_8008C4F4_lbl_8048E7C0 ending_scene_callbacks;
typedef char RecoveredGlobal_8008C534_main_task_size[sizeof(RecoveredGlobal_8008C534_main_task) == 0x34 ? 1 : -1];

typedef char RecoveredGlobal_8008C4F4_lbl_8048E7C0_size[sizeof(RecoveredGlobal_8008C4F4_lbl_8048E7C0) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_8008C4F4_main_task_size[sizeof(RecoveredGlobal_8008C4F4_main_task) == 0x34 ? 1 : -1];
void fn_8008C4F4(void) {
    s32 *var_r3;
    s32 var_r4;
    TLobby::stop_audio_streams();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C4F4_main_task *)&(*(RecoveredGlobal_8008C534_main_task *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C4F4_main_task *)&(*(RecoveredGlobal_8008C534_main_task *)&main_task)).value);
    main_task.delete_layer_children();
    var_r3 = &ending_scene_callbacks.value;
    var_r4 = 0x68;
    var_r3 = &ending_scene_callbacks.value;
    call_funcs_reverse__6TLobbyFPvUi(&ending_scene_callbacks.value, 0x68);
    render_tick();
}
}
void process_async_file_reads(void);
void update_sound_request_slots(void);
void run_game_frame(void) {
    s32 *var_r3;
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    main_task.begin_frame();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    main_task.run_task();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    main_task.render();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
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
