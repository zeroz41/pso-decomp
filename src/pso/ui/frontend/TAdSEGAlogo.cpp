#include "pso/ui/frontend/TAdSEGAlogo.h"
#include "types.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"

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

struct Obj_8001BFCC { u8 pad[0x1c]; s32 f1c; };

extern "C" {
s32 render_logo_with_default(void *, int, int, f32);
extern void* logo_texture_e_handle;
extern int TAdSEGAlogo__state;
extern void *tl_00;
void *__nw__7TObjectFUl(u32 size);
int queue_destruction__7TObjectFv(void);

    extern int sega_logo_done_flag;
void TAdSEGAlogo::destroy_and_mark_done() { queue_destruction__7TObjectFv(); sega_logo_done_flag = 1; }

void TAdSEGAlogo::request_destroy() { queue_destruction__7TObjectFv(); TAdSEGAlogo__state = 1; }

}

void TAdSEGAlogo::render() {
    render_logo_with_default(logo_texture_e_handle, 8, -1, -150.0f);
}
void TAdSEGAlogo::run_task() {
    Obj_8001BFCC *self = (Obj_8001BFCC *)this;
    switch (TAdSEGAlogo__state) {
    case 0:
        break;
    case 1:
        if ((f32)++self->f1c > 60.0f) {
            void *p;
            TAdSEGAlogo__state = 2;
            p = __nw__7TObjectFUl(0x28);
            if (p != 0) {
                ((THunterGuildSeqOffline *)p)->init(tl_00, (void *)TAdSEGAlogo::destroy_and_mark_done);
            }
        }
        break;
    case 2:
        break;
    }
}

TAdSEGAlogo::~TAdSEGAlogo() {}


extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__11TAdSEGAlogo[];
extern s32 request_destroy__11TAdSEGAlogoFv[];

void *__ct__11TAdSEGAlogoFv(void *ad_seg_alogo) {
    void *o;
    __ct__7TObjectFP7TObject(ad_seg_alogo);
    *(s32 **)((s8 *)ad_seg_alogo + 0x18) = __vt__11TAdSEGAlogo;
    ((TAdSEGAlogo *)ad_seg_alogo)->m_name = TAdSEGAlogo__class_name;
    *(u32 *)((s8 *)ad_seg_alogo + 0x1C) = 0;
    TAdSEGAlogo__state = 0;
    sega_logo_done_flag = 0;
    TAdSinglePlyChrSelectGC::init_logo_state(0);
    o = __nw__7TObjectFUl(0x28);
    if (o != NULL) {
        ((TLobby *)o)->init_fade(tl_00, request_destroy__11TAdSEGAlogoFv);
    }
    return ad_seg_alogo;
}

}
