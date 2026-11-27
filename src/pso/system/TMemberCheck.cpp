#include <string.h>
#include "pso/system/TMemberCheck.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

extern "C" {
const char *member_check_name_ptr = "TMemberCheck";
extern const char *member_check_name_ptr;
}
s32 TMemberCheck::previous_member_count;

void TMemberCheck::run_task() {
    s32 n = count_members();
    if (TMemberCheck::previous_member_count != n) {
        TMemberCheck::previous_member_count = n;
        open_member_name_window();
    }
    update_member_proximity();
}

TMemberCheck::~TMemberCheck() {
    if (member_window != 0) {
        ((TWindowBase *)member_window)->close();
        member_window = 0;
    }
}
TMemberCheck::TMemberCheck(TObject* parent) : TObject(parent) {
    m_name = member_check_name_ptr;
    member_window = 0;
    memset(names, 0, 0x60);
    TMemberCheck::previous_member_count = count_members();
    open_member_name_window();
}
