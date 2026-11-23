#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdRayGC.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TitleBackgroundStorage.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"

#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"

struct Txt_802FFE58 { TAdSelectTxtLayout v[3]; };

struct Pos_802FFE58 { f32 v[6]; };

struct Cur_802FFE58 { f32 v[2]; };

extern "C" {
s32 lbl_805D69E8;
}
s32 is_multiplayer_character_slot_selected(s32 arg0);
extern "C" {
const char *TAdMultiChgGameModeGC__name = "TAdMultiChgGameModeGC";

static const Txt_802FFE58 multi_chg_game_mode_text_layout = { { { -1, 223.0f, 169.0f }, { -1, 193.0f, 221.0f }, { -1, 163.0f, 273.0f } } };
static const Cur_802FFE58 lbl_80474E1C[1] = { { { 302.0f, 28.0f } } };
static const Pos_802FFE58 multi_chg_game_mode_position_table = { { 200.0f, 170.0f, 170.0f, 222.0f, 140.0f, 274.0f } };

void fn_802FFC78(void) {  }
void fn_802FFC7C(void) {  }
void TAdMultiChgGameModeGC::render() {  }
s32 TAdMultiChgGameModeGC::check_players_ready(void * _w0) {
    u32 var_r31;

    var_r31 = 0U;
loop_1:
    if ((is_multiplayer_character_slot_selected(var_r31) != 0) && (TAdMultiPlyChrSelectGC::get_multiplayer_character_slot(var_r31) > 3)) {
        return 1;
    }
    var_r31 += 1;
    if (var_r31 >= 4U) {
        return 0;
    }
    goto loop_1;
}
void TAdMultiChgGameModeGC::run_task() {
    set_default_camera();
    selection = select_cursor->selection_index();
    if (prev_selection != selection) {
        guide_text->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x21, selection)));
    }
    if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0 ||
        test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
        request_scene_change();
    } else if (select_cursor->confirmation_result() == 1) {
        switch (select_cursor->selection_index()) {
        case 0:
            set_mode_state_0d();
            break;
        case 1:
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            lbl_805D69E8 = 1;
            set_mode_18();
            break;
        case 2:
            if (check_players_ready(this) != 0) {
                set_mode_state_0e();
            } else {
                request_scene_change();
            }
            break;
        }
    }
    prev_selection = selection;
}
TAdMultiChgGameModeGC::~TAdMultiChgGameModeGC() {}
TAdMultiChgGameModeGC::TAdMultiChgGameModeGC(TObject *parent) : TObject(parent) {
    m_name = TAdMultiChgGameModeGC__name;
    pad_1C = 0;
    selection = 2;
    prev_selection = -1;
    guide_text = 0;
    select_cursor = 0;
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    new TAdRayGC(this);
    new TAdTitleGC(this, 0xF);
    {
        Txt_802FFE58 txt = multi_chg_game_mode_text_layout;
        new TAdSelectTxtGC(this, &txt.v[0], 0xC);
        new TAdSelectTxtGC(this, &txt.v[1], 0xD);
        new TAdSelectTxtGC(this, &txt.v[2], 0xE);
        new TAdTitleTexGC(this);
        {
            Cur_802FFE58 cur = lbl_80474E1C[0];
            Pos_802FFE58 pos = multi_chg_game_mode_position_table;
            select_cursor = new TAdSelectCurGC(this, reinterpret_cast<const NJS_POINT2 *>(&pos), reinterpret_cast<const NJS_POINT2 *>(&cur));
            select_cursor->append_entry(&pos.v[0]);
            select_cursor->append_entry(&pos.v[2]);
            select_cursor->append_entry(&pos.v[4]);
        }
    }
    select_cursor->set_selection_index(selection);
    guide_text = new TAdGuideTxtGC(this);
    create_draw_line_ctrl(this, 0xF, 0.0f);
}
}
