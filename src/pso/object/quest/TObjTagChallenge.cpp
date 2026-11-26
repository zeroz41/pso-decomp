#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/quest/TObjTagChallenge.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TObjNewFloorWin.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowCtrlMain.h"

void TObjTagChallenge::run_task() {
    if (has_window_task_root() != 0) {
        TWindowCtrl::close_active_window();
        close_current_window();
        TWindowCtrl::open_status_111();
        queue_destruction();
    }
}

TObjTagChallenge::~TObjTagChallenge() {}

#include "types.h"

#pragma readonly_strings on


const char *tag_challenge_class_name = "TObjTagChallenge";

TObjTagChallenge::TObjTagChallenge(TObject *parent) : TObject(parent) {
    m_name = tag_challenge_class_name;
}

void *create_obj_tag_challenge(void *tag_challenge) {
    return new TObjTagChallenge((TObject *)tag_challenge);
}
