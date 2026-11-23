#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "pso/unk/TScreenFadeOut.h"
#include "pso/unk/TScreenFadeIn.h"
#include "pso/ui/TLogo_8001C134.h"
#include "types.h"
#include "pso/ui/frontend/TAdADXlogo.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdBackGC.h"


const char *TAdADXlogo_name = "TAdADXlogo";

void *TAdADXlogo__texture;
u32 TAdADXlogo__state;
u32 TAdADXlogo__done;

void TAdADXlogo::fade_out_done(TObject *fade) {
    fade->queue_destruction();
    TAdADXlogo__done = 1;
}

void TAdADXlogo::fade_in_done(TObject *fade) {
    fade->queue_destruction();
    TAdADXlogo__state = 1;
}

void TAdADXlogo::render() {
    render_logo_with_default(TAdADXlogo__texture, 0, -1, -150.0f);
}

void TAdADXlogo::run_task() {
    switch (TAdADXlogo__state) {
    case 0:
        break;
    case 1:
        if ((f32)++m_frames > 60.0f) {
            TAdADXlogo__state = 2;
            new TScreenFadeOut(tl_00, fade_out_done);
        }
        break;
    case 2:
        break;
    }
}

TAdADXlogo::~TAdADXlogo() {}

TAdADXlogo::TAdADXlogo(TObject *parent) : TObject(parent) {
    m_name = TAdADXlogo_name;
    m_frames = 0;
    TAdADXlogo__state = 0;
    TAdADXlogo__done = 0;
    new TScreenFadeIn(tl_00, fade_in_done);
}

void free_adx_logo_texture() {

}

void load_adx_logo_texture() {
    TAdADXlogo__texture = get_logo_texture_e_handle();
}

void TObject::queue_destruction() { m_flags |= QUEUE_DESTRUCTION; }

NJS_TEXLIST *get_logo_texture_e_handle() { return logo_texture_e_handle; }
