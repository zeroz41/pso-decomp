#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TScreenFadeOut.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/unk/TScreenFadeIn.h"
#include "pso/ui/frontend/TAdSEGAlogo.h"
#include "pso/ui/TLogo_8001C134.h"
#include "types.h"
#include "pso/ui/frontend/TitleBackground.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma push
#pragma readonly_strings on
#pragma const_strings off
// The logo textures: eight ADX, eight SEGA and eight Sonic Team frames.
NJS_TEXNAME lbl_80480A70[24] = {
    { "gc_adx01", 0, 0 },
    { "gc_adx02", 0, 0 },
    { "gc_adx03", 0, 0 },
    { "gc_adx04", 0, 0 },
    { "gc_adx05", 0, 0 },
    { "gc_adx06", 0, 0 },
    { "gc_adx07", 0, 0 },
    { "gc_adx08", 0, 0 },
    { "sega_logo_e01", 0, 0 },
    { "sega_logo_e02", 0, 0 },
    { "sega_logo_e03", 0, 0 },
    { "sega_logo_e04", 0, 0 },
    { "sega_logo_e05", 0, 0 },
    { "sega_logo_e06", 0, 0 },
    { "sega_logo_e07", 0, 0 },
    { "sega_logo_e08", 0, 0 },
    { "st_logo01", 0, 0 },
    { "st_logo02", 0, 0 },
    { "st_logo03", 0, 0 },
    { "st_logo04", 0, 0 },
    { "st_logo05", 0, 0 },
    { "st_logo06", 0, 0 },
    { "st_logo07", 0, 0 },
    { "st_logo08", 0, 0 },
};
__declspec(section ".data") NJS_TEXLIST texture_logo_e_descriptor = { lbl_80480A70, 24 };
const char *TAdSEGAlogo__class_name = "TAdSEGAlogo";
#pragma pop

NJS_TEXLIST *logo_texture_e_handle;
int TAdSEGAlogo__state;
int sega_logo_done_flag;

void TAdSEGAlogo::destroy_and_mark_done(TObject *fade) {
    fade->queue_destruction();
    sega_logo_done_flag = 1;
}

void TAdSEGAlogo::request_destroy(TObject *fade) {
    fade->queue_destruction();
    TAdSEGAlogo__state = 1;
}

void TAdSEGAlogo::render() {
    render_logo_with_default(logo_texture_e_handle, 8, -1, -150.0f);
}
void TAdSEGAlogo::run_task() {
    switch (TAdSEGAlogo__state) {
    case 0:
        break;
    case 1:
        if ((f32)++m_wait_frames > 60.0f) {
            TAdSEGAlogo__state = 2;
            new TScreenFadeOut(tl_00, TAdSEGAlogo::destroy_and_mark_done);
        }
        break;
    case 2:
        break;
    }
}

TAdSEGAlogo::~TAdSEGAlogo() {}

TAdSEGAlogo::TAdSEGAlogo(TObject *parent) : TObject(parent) {
    m_name = TAdSEGAlogo__class_name;
    m_wait_frames = 0;
    TAdSEGAlogo__state = 0;
    sega_logo_done_flag = 0;
    TAdSinglePlyChrSelectGC::init_logo_state(0);
    new TScreenFadeIn(tl_00, request_destroy);
}
