#ifndef PSO_AUDIO_ADX_HEADER_H
#define PSO_AUDIO_ADX_HEADER_H

#include "types.h"

// Block of an ADX header at 0x14, or at 0x20 when the byte at 0x12 is 4.
struct AdxHeaderBlock {
    s16 loop_enabled_flag;
    s16 loop_type;
    s16 pad_04;
    s16 loop_count;
    s32 loop_start_sample;
    s32 loop_start_offset;
    s32 loop_end_sample;
    s32 loop_end_offset;
};

// Packet header checked by adx_parse_packet_header_len.
struct AdxPacketHeader {
    u16 type;
    s16 len;
};

// Big-endian ADX file header, read in place.
struct AdxHeader {
    u16 magic;
    s16 header_offset;
    u8 pad_04[0xC];
    u16 cutoff; // high-pass cutoff frequency for the prediction coefficients
    u8 version;
    u8 pad_13;
    u8 pad_14[0x4];
    u16 loop_points[4];
};

// --- C functions defined in AdxHeader.cpp ---
extern "C" {
// The ADX header's data offset (len), encoding type (above 4 is AHX), block layout, rate and length.
s32 adx_parse_header_info(u8 *hdr, s32 size, s16 *len, u8 *encoding, s8 *bits, s8 *block_bytes, u8 *channels, s32 *rate, s32 *samples, s32 *block_samples);
s32 adx_parse_header_cutoff(u8 *hdr, s32 size, u16 *cutoff);
// The loop block of an ADX header; only loop type 1 is accepted.
s32 adx_parse_header_loop(u8 *hdr, s32 size, s32 *loop_enabled, s16 *loop_type, s16 *loop_count, s32 *loop_start_sample, s32 *loop_start_byte, s32 *loop_end_sample, s32 *loop_end_byte);
// The length of the packet header at hdr (type 0x8001), with its 4-byte head.
s32 adx_parse_packet_header_len(u8 *hdr, s32 size, s16 *out);
// The two loop point pairs of a version 4 ADX header, zero for older versions.
s32 adx_parse_header_loop_points(u8 *hdr, s32 size, u16 *out0, u16 *out1);
// The index of the first 0x8000 end marker among every other sample, -1 when there is none.
s32 adx_find_end_marker(s16 *samples, s32 count, s16 *out_index);
}
void calc_adx_predictor_coeffs(s32 cutoff, s32 rate, s16 *k0, s16 *k1);
// --- end of C functions

#endif
