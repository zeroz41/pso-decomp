#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"
#include "pso/ui/charcreate/CharacterPreview.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

s32 CharacterPreview::get_hair_model() { return part_models[0]; }
NJS_TEXLIST *CharacterPreview::get_head_texlist() { return &head_textures.list; }
s32 CharacterPreview::get_cap_model() { return part_models[1]; }
s32 CharacterPreview::get_head_model() { return part_models[2]; }
NJS_TEXLIST *CharacterPreview::get_other_texlist() { return &other_textures.list; }
s32 CharacterPreview::get_body_model() { return body_model; }
NJS_TEXLIST *CharacterPreview::get_body_texlist() { return &body_textures.list; }

void TAdPlyStatusGC::set_status_param(CharacterPreview *preview) { ply_status_preview = preview; }

TAdPlyStatusGC *TAdPlyStatusGC::get_index() {  return ply_status_gc_instance; }

    extern int ply_status_index;
void TAdPlyStatusGC::set_status_index(int a0, int a1) { ply_status_index = a1; }

extern s32 TAdPlyStatusGC__window_offset_index;

void TAdPlyStatusGC::close_window(s32 index) {
    TAdPlyStatusGC__window_offset_index = index;
    if (window != NULL) {
        window->close();
        window = NULL;
    }
}

