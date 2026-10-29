#include "types.h"
#include "pso/ui/TAdPlayerLoadGC_800F9EF8.h"
#include "pso/misc/TLobby_800F9DA0.h"
#include "pso/render/render_util.h"
#include "pso/system/main_loop.h"
#include "pso/misc/TLobby.h"
#include "pso/TObject.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TScene.h"

extern "C" {

int read_whole_file__8TGStreamFlPUc(void);
void TLobby__sub_800F8AD0(void);
void TLobby__sub_800F8F34(void);
void TLobby__sub_803382E4(void);
s32 adxf_get_fsize_byte__6TLobbyFv();
s32 adxf_open__6TLobbyFUii(s32, s32);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
void restore_saved_depth_alpha_state(void);
void fn_801E2C50(void);
s8 func_801A5E54__Fv();
void func_803DCDFC__Fv(void);
void system_reset(void);

s32 TLobby::get_file_size() {
    s32 temp_r31;
    s32 temp_r3;
    s32 uninit;

    temp_r3 = adxf_open__6TLobbyFUii(uninit, 0);
    if (temp_r3 == 0) {
        return -1;
    }
    temp_r31 = adxf_get_fsize_byte__6TLobbyFv();
    ((TLobby *)temp_r3)->close_adxf_handle();
    return temp_r31;
}

    extern int disc_read_filename;
void read_disc_file(int a0) { disc_read_filename = a0; read_whole_file__8TGStreamFlPUc(); }

extern s32 tl_su;
extern s32 tl_camera;
extern s32 tl_07;
extern s32 tl_particle;
extern s32 tl_fade;

void TLobby::run_frame() {
    func_803DCDFC__Fv();
    TLobby__sub_800F8F34();
    ((TObject *)tl_su)->run_tasks();
    ((TObject *)tl_camera)->run_tasks();
    ((TObject *)tl_07)->run_tasks();
    ((TObject *)tl_particle)->run_tasks();
    if ((TLoadCtrl__sub_800F9F00() != 0U) && (all_parents_unqueued_for_destruction__7TObjectFv() != 0)) {
        ((TObject *)tl_fade)->run_tasks();
    }
    set_depth_buffer_settings_1();
    ((TObject *)tl_su)->render_nodes();
    ((TObject *)tl_07)->render_nodes();
    ((TObject *)tl_particle)->render_nodes();
    if ((TLoadCtrl__sub_800F9F00() != 0U) && (all_parents_unqueued_for_destruction__7TObjectFv() != 0)) {
        ((TObject *)tl_fade)->render_nodes();
    }
    ((TObject *)tl_su)->debug_render();
    ((TObject *)tl_su)->debug_update();
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        system_reset();
        fn_801E2C50();
    }
    restore_saved_depth_alpha_state();
    if (func_801A5E54__Fv() != 0) {
        TLobby__sub_800F8AD0();
    }
    TLobby__sub_803382E4();
    render_tick();
}

}
