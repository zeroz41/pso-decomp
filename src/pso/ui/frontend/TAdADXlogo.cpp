#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "types.h"
#include "pso/ui/frontend/TAdADXlogo.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdBackGC.h"

s32 get_logo_texture_e_handle();

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
            void *fade;
            TAdADXlogo__state = 2;
            fade = operator new(0x28);
            if (fade != NULL) {
                ((THunterGuildSeqOffline *)fade)->init(tl_00, (void *)fade_out_done);
            }
        }
        break;
    case 2:
        break;
    }
}

TAdADXlogo::~TAdADXlogo() {}

TAdADXlogo::TAdADXlogo(TObject *parent) : TObject(parent) {
    void *fade;
    m_name = TAdADXlogo_name;
    m_frames = 0;
    TAdADXlogo__state = 0;
    TAdADXlogo__done = 0;
    fade = operator new(0x28);
    if (fade != NULL) {
        ((TLobby *)fade)->init_fade(tl_00, (void *)fade_in_done);
    }
}

void free_adx_logo_texture() {

}

void load_adx_logo_texture() {
    TAdADXlogo__texture = (void *)get_logo_texture_e_handle();
}

void TObject::queue_destruction() { m_flags |= QUEUE_DESTRUCTION; }
