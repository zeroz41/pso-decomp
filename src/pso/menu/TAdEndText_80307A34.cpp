#include "types.h"
#include "pso/TMainTask.h"
#include "pso/menu/TAdEndText_80307A34.h"
#include "pso/system/main_loop.h"
#include "pso/TAdEndText.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TLobby.h"

struct RecoveredGlobal_80307A74_main_task {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
s32 TKeyBoardControl__sub_8000F92C();
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
s8 func_801A5E54__Fv();
void func_803DCDFC__Fv(void);
void TKeyBoardControl__sub_8000F90C(s32 arg0);
void TKeyBoardControl__sub_8000F91C(s32 arg0);
void reset_controller_input_state(void);
s32 set_copy_clear_color_argb(s32, s32, s32);
u32 __nw__7TObjectFUl(s32);
s32 init_ending_movie();
}
void process_async_file_reads(void);
void set_screen_size(f32 farg0, f32 farg1);
extern int ending_sequence_active;
extern "C" {
int TLobby__sub_800FC3CC(void);

void TAdEndText::cleanup() { ending_sequence_active = 0; main_task.delete_layer_children(); TLobby__sub_800FC3CC(); TLobby::free_keyboard_soft_resources(); TAdEndText::free_resources(); render_tick(); }
typedef char RecoveredGlobal_80307A74_main_task_size[sizeof(RecoveredGlobal_80307A74_main_task) == 0x34 ? 1 : -1];
void TKeyBoardControl::run_main_frame() {
    s32 *var_r3;
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80307A74_main_task *)((unsigned char *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80307A74_main_task *)((unsigned char *)&main_task)).value);
    main_task.begin_frame();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80307A74_main_task *)((unsigned char *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80307A74_main_task *)((unsigned char *)&main_task)).value);
    main_task.run_task();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80307A74_main_task *)((unsigned char *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80307A74_main_task *)((unsigned char *)&main_task)).value);
    main_task.render();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80307A74_main_task *)((unsigned char *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_80307A74_main_task *)((unsigned char *)&main_task)).value);
    main_task.render_screen_overlay();
    process_async_file_reads();
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
void start_ending_sequence(void) {
    (*(s32 *)&ending_sequence_active) = 1;
    set_screen_size(1.0f, 0.85f);
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    TKeyBoardControl__sub_8000F91C(2);
    TKeyBoardControl__sub_8000F90C(2);
    TAdEndText::load_ending_font();
    TLobby::update_keyboard_menu();
    TLobby::set_ending_callback();
    if (__nw__7TObjectFUl(0x1C) != 0U) {
        init_ending_movie();
    }
    render_tick();
}
