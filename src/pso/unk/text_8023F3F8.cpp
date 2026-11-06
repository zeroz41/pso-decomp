#include "types.h"
#include "pso/unk/text_8023F3F8.h"
#include "pso/TObject.h"
#include "pso/TMainTask.h"
#include "pso/ui/TAdMultiChgGameModeGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/system/main_loop.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TLobby_802268F4.h"
#include "pso/unk/text_800FA464.h"
#include "pso/unk/text_803DCDFC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"

extern "C" {
s8 func_801A5E54__Fv();
extern s32 lbl_805D63C8;
extern TObject *game_mode_scene_instance;

void fn_8023F3F8(void) {
    switch (lbl_805D63C8) {
    case 0:
        break;
    case 1:
        if (game_mode_scene_instance != NULL) {
            game_mode_scene_instance->queue_destruction();
            game_mode_scene_instance = NULL;
        }
        lbl_805D63C8 = 2;
        break;
    case 2:
        lbl_805D63C8 = 0;
        TAdMultiChgGameModeGC::create_mode_scene();
        break;
    }
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
    TAdSinglePlyChrSelectGC::noop();
    if (TAdPlayerLoadGC::get_instance() == 0) {
        if (func_801A5E54__Fv() != 0) {
            TKeyBoardControl__sub_8000F92C();
        }
        if (TQuestVmDownLoadServer::is_ready() != 0) {
            TKeyBoardControl__sub_8000F9CC(0);
        }
    }
    render_tick();
}
}
