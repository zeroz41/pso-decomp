#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
s32 TAdPlyStatusGC::get_field_498() { return *(s32*)((char*)this + 0x498); }
void*TAdPlyStatusGC::get_chara_making_data() { return (char*)this + 0x1b8; }
s32 TAdPlyStatusGC::get_field_49c() { return *(s32*)((char*)this + 0x49c); }
s32 TAdPlyStatusGC::get_field_4a0() { return *(s32*)((char*)this + 0x4a0); }
void*TAdPlyStatusGC::get_status_data() { return (char*)this + 0x324; }
s32 TAdPlyStatusGC::get_field_4a4() { return *(s32*)((char*)this + 0x4a4); }
void*TAdPlyStatusGC::get_status_sub() { return (char*)this + 0x490; }

    extern int ply_status_chcr_load_afs;
void TAdPlyStatusGC::set_status_param(int a0, int a1) { ply_status_chcr_load_afs = a1; }

    extern int ply_status_gc_instance;
int TAdPlyStatusGC::get_index() {  return ply_status_gc_instance; }

    extern int ply_status_index;
void TAdPlyStatusGC::set_status_index(int a0, int a1) { ply_status_index = a1; }

extern s32 TAdPlyStatusGC__window_offset_index;

void TAdPlyStatusGC::close_window(s32 arg1) {
    TAdPlyStatusGC__window_offset_index = arg1;
    if ((u32) this->m_6c != 0U) {
        ((TWindowBase *)this->m_6c)->close();
        this->m_6c = 0U;
    }
}

}
