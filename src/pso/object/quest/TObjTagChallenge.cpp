#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/quest/TObjTagChallenge.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TObjNewFloorWin.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"

void TObjTagChallenge::run_task() {
    if (has_window_task_root() != 0) {
        TWindowCtrl::close_active_window();
        fn_800740DC();
        TWindowCtrl::open_status_111();
        queue_destruction();
    }
}

TObjTagChallenge::~TObjTagChallenge() {}

#include "types.h"

#pragma readonly_strings on


const char *TObjTagChallenge__class_name = "TObjTagChallenge";

TObjTagChallenge::TObjTagChallenge(TObject *parent) : TObject(parent) {
    m_name = TObjTagChallenge__class_name;
}

void *create_obj_tag_challenge(void *tag_challenge) {
    return new TObjTagChallenge((TObject *)tag_challenge);
}
