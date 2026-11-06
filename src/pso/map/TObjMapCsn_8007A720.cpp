#include "types.h"
#include "pso/map/TObjMapCsn.h"

extern "C" {
    extern const float lbl_805D9204;
s32 fn_8007A7A0();
void*TObjMapCsn::get_data_ptr() { return (char*)this + 0x1c; }

extern s32 map_csn_ctrl_instance;

s32 TObjMapCsn::get_map_count() {
    return map_csn_ctrl_instance;
}
void*TObjMapCsn::init() { TObjMapCsn::init_and_return((s32)this); *(int *)&this->m_prev = -1; *(float *)&this->m_next = lbl_805D9204; return this; }
s32 TObjMapCsn::init_and_return(s32 arg0) {
    fn_8007A7A0();
    return arg0;
}

}
