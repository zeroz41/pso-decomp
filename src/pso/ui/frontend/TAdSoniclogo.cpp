#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TScreenFadeOut.h"
#include "pso/unk/TScreenFadeIn.h"
#include "pso/ui/TLogo_8001C134.h"
#include "pso/ui/frontend/TAdSoniclogo.h"

#include "types.h"
#include "pso/ui/TLogo.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

extern "C" {
void * sonic_logo_object;
int TAdSoniclogo__state;
int TLogo__exit_requested_flag;
const char *TAdSoniclogo__class_name = "TAdSoniclogo";

void TAdSoniclogo::request_destroy(TObject *fade) {
    fade->queue_destruction();
    TAdSoniclogo__state = 1;
}

}


void TAdSoniclogo::render() {
    render_logo_with_default(sonic_logo_object, 16, -1, -150.0f);
}
void TAdSoniclogo::run_task() {
    switch (TAdSoniclogo__state) {
    case 0:
        break;
    case 1:
        if (++m_wait_frames > 0x3c) {
            TAdSoniclogo__state = 2;
            new TScreenFadeOut(tl_00, TLogo::request_exit);
        }
        break;
    case 2:
        break;
    }
}
TAdSoniclogo::~TAdSoniclogo() {}

TAdSoniclogo::TAdSoniclogo(TObject *parent) : TObject(parent) {
    m_name = TAdSoniclogo__class_name;
    m_wait_frames = 0;
    TAdSoniclogo__state = 0;
    TLogo__exit_requested_flag = 0;
    TAdSinglePlyChrSelectGC::init_logo_state(1);
    new TScreenFadeIn(tl_00, request_destroy);
}


void TLogo__sub_8001C360(void) {  }

void TLogo__sub_8001C364(void) { sonic_logo_object = get_logo_texture_e_handle(); }

