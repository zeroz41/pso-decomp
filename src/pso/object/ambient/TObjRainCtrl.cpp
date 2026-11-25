#include "pso/object/ambient/TObjRainCtrl.h"
#include "pso/object/ambient/TObjRain.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"


#pragma readonly_strings on


extern const char rain_ctrl_class_name_string[] = "TObjRainCtrl";
#include "pso/ui/hud/TRaderMapCore.h"
const char *lbl_805D3428 = rain_ctrl_class_name_string;


void TObjRainCtrl::create() {
    if (TRaderMapCore::is_not_split_screen() == 0) {
        new TObjRainCtrl(tl_particle);
    }
}

void TObjRainCtrl::run_task() {
    if (--ticks_until_spawn < 0) {
        if (get_current_floor_area() == AREA_GAL_GRYPHON) {
            new TObjRain(tl_particle, 36);
        } else {
            new TObjRain(tl_particle, 9);
        }
        ticks_until_spawn = 2;
    }
}

TObjRainCtrl::~TObjRainCtrl() {}

TObjRainCtrl::TObjRainCtrl(TObject *parent) : TObject(parent) {
    m_name = lbl_805D3428;
    ticks_until_spawn = 2;
}
