#include "types.h"
#include "pso/system/TEndingAB.h"

extern "C" {


    extern const float lbl_805D9584;
    extern const float lbl_805D9588;
    extern const float lbl_805D958C;
    extern const float lbl_805D9590;
    extern const float lbl_805D9594;
    extern const float lbl_805D9598;
    extern const float lbl_805D959C;
    extern const float lbl_805D95A0;
    extern const float lbl_805D95A4;
    extern const float lbl_805D95A8;
    extern const float lbl_805D95AC;
    extern const float lbl_805D95B0;
    extern const float lbl_805D95B4;
    extern const float lbl_805D95B8;
void TEndingAB::init_float_table() { *(float*)((char*)this + 0x2c) = lbl_805D9584; *(float*)((char*)this + 0x30) = lbl_805D9588; *(float*)((char*)this + 0x34) = lbl_805D958C; *(float*)((char*)this + 0x38) = lbl_805D9590; *(float*)((char*)this + 0x3c) = lbl_805D9594; *(float*)((char*)this + 0x40) = lbl_805D9588; *(float*)((char*)this + 0x44) = lbl_805D9598; *(float*)((char*)this + 0x48) = lbl_805D959C; *(float*)((char*)this + 0x4c) = lbl_805D9588; *(float*)((char*)this + 0x50) = lbl_805D9588; *(float*)((char*)this + 0x54) = lbl_805D95A0; *(float*)((char*)this + 0x58) = lbl_805D9590; *(float*)((char*)this + 0x5c) = lbl_805D9588; *(float*)((char*)this + 0x60) = lbl_805D9588; *(float*)((char*)this + 0x64) = lbl_805D9594; *(float*)((char*)this + 0x68) = lbl_805D959C; *(float*)((char*)this + 0x6c) = lbl_805D9584; *(float*)((char*)this + 0x70) = lbl_805D9588; *(float*)((char*)this + 0x74) = lbl_805D958C; *(float*)((char*)this + 0x78) = lbl_805D9590; *(float*)((char*)this + 0x7c) = lbl_805D9594; *(float*)((char*)this + 0x80) = lbl_805D9588; *(float*)((char*)this + 0x84) = lbl_805D9598; *(float*)((char*)this + 0x88) = lbl_805D959C; *(float*)((char*)this + 0x8c) = lbl_805D9588; *(float*)((char*)this + 0x90) = lbl_805D9588; *(float*)((char*)this + 0x94) = lbl_805D95A0; *(float*)((char*)this + 0x98) = lbl_805D9590; *(float*)((char*)this + 0x9c) = lbl_805D9588; *(float*)((char*)this + 0xa0) = lbl_805D9588; *(float*)((char*)this + 0xa4) = lbl_805D9594; *(float*)((char*)this + 0xa8) = lbl_805D959C; *(float*)((char*)this + 0xac) = lbl_805D95A4; *(float*)((char*)this + 0xb0) = lbl_805D95A8; *(float*)((char*)this + 0xb4) = lbl_805D95AC; *(float*)((char*)this + 0xb8) = lbl_805D95B0; *(float*)((char*)this + 0xbc) = lbl_805D9588; *(float*)((char*)this + 0xc0) = lbl_805D9588; *(float*)((char*)this + 0xc4) = lbl_805D9598; *(float*)((char*)this + 0xc8) = lbl_805D9598; *(float*)((char*)this + 0xcc) = lbl_805D95A4; *(float*)((char*)this + 0xd0) = lbl_805D95B4; *(float*)((char*)this + 0xd4) = lbl_805D95AC; *(float*)((char*)this + 0xd8) = lbl_805D95B8; *(float*)((char*)this + 0xdc) = lbl_805D9588; *(float*)((char*)this + 0xe0) = lbl_805D9588; *(float*)((char*)this + 0xe4) = lbl_805D9598; *(float*)((char*)this + 0xe8) = lbl_805D9598; }

extern s32 TEndingAB__fade_sequence_state;

void TEndingAB::render() {
    s32 arg0 = (s32)this;
    if ((s32) TEndingAB__fade_sequence_state != 0) {
        TEndingAB::set_fish_global_param();
        ((TEndingAB *)arg0)->draw_overlay();
        TEndingAB__sub_8008CCC0((TEndingAB *)arg0);
    }
}

}
