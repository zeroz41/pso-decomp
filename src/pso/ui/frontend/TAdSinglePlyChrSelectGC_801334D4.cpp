#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

s32 TAdSinglePlyChrSelectGC::get_selected_slot() { return *(s32*)((char*)this + 0xac); }
s32 TAdSinglePlyChrSelectGC__sub_801334DC(void* p) { return *(s32*)((char*)p + 0xa4); }
void TAdSinglePlyChrSelectGC__sub_801334E4(void) {  }
void TAdSinglePlyChrSelectGC::set_position(void* q) { *(f32 *)&this->m_20 = *(f32*)((char*)q + 0x4); *(f32 *)&this->m_24 = *(f32*)((char*)q + 0x8); *(f32 *)&this->m_28 = *(f32*)((char*)q + 0xc); }
void TAdSinglePlyChrSelectGC::noop_laser() {  }
void TAdSinglePlyChrSelectGC__sub_80133508(void *light) {  }
void TAdSinglePlyChrSelectGC::forward_to_field_0x14(void* a1) { TAdSinglePlyChrSelectGC__sub_80133530((void*)((char*)this + 0x14), a1); }
void TAdSinglePlyChrSelectGC__sub_80133530(void* p, void* q) { *(f32*)((char*)p + 0x0) = *(f32*)((char*)q + 0x0); *(f32*)((char*)p + 0x4) = *(f32*)((char*)q + 0x4); }
void TAdSinglePlyChrSelectGC__sub_80133544(void) {  }
void TAdSinglePlyChrSelectGC__sub_80133548(void) {  }
void TAdSinglePlyChrSelectGC::set_vec3(void* q) { *(f32 *)&this->m_prev = *(f32*)((char*)q + 0x0); *(f32 *)&this->m_next = *(f32*)((char*)q + 0x4); *(f32 *)&this->m_up = *(f32*)((char*)q + 0x8); }
