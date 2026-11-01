#include "pso/TMemberCheck.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TLobby.h"

#pragma readonly_strings on

extern "C" {
const char *member_check_name_ptr = "TMemberCheck";
s32 TMemberCheck__previous_member_count;
}


extern "C" {
void* memset(void*, int, unsigned long);
extern const char *member_check_name_ptr;
extern s32 TMemberCheck__previous_member_count;
}

void TMemberCheck::run_task() {
    s32 n = TLobby::count_members();
    if (TMemberCheck__previous_member_count != n) {
        TMemberCheck__previous_member_count = n;
        open_member_name_window();
    }
    update_member_proximity();
}

TMemberCheck::~TMemberCheck() {
    if (m_1C != 0) {
        ((TWindowBase *)m_1C)->close();
        m_1C = 0;
    }
}
TMemberCheck::TMemberCheck(TObject* parent) : TObject(parent) {
    m_name = member_check_name_ptr;
    m_1C = 0;
    memset(m_20, 0, 0x60);
    TMemberCheck__previous_member_count = TLobby::count_members();
    open_member_name_window();
}
