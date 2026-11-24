#include "pso/system/RlcArchive.h"
#include "types.h"
#include "pso/ui/window/TWindowSnapShot_802A5B2C.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/system/TGStream.h"
#include "pso/unk/TLobby.h"
#include <string.h>
#include "pso/boss/darkfalz/TOBoss4Rock.h"


u32 RlcDirectoryEntry::get_size() { return read_be32(size_be); }
u32 RlcDirectoryEntry::get_offset() { return read_be32(offset_be); }
u32 RlcDirectoryEntry::read_be32(const s8 *bytes) {
    u32 value;
    u32 hi;
    s8 b3;
    s8 b2;
    s8 b1;
    s8 b0;

    b0 = bytes[0];
    b1 = bytes[1];
    if (bytes && bytes) {}
    hi = (b1 << 16) & 0xFF0000;
    value = (b0 << 24) | hi;
    b2 = bytes[2];
    b3 = bytes[3];
    if (bytes && bytes) {}
    value |= (b2 << 8) & 0xFF00;
    value |= b3 & 0xFF;
    return value;
}

u32 RlcHeader::get_directory_offset() { return read_be32(directory_offset_be); }
u32 RlcHeader::get_chunk_count() { return read_be32(chunk_count_be); }
u32 RlcHeader::read_be32(const s8 *bytes) {
    u32 value;
    u32 hi;
    s8 b3;
    s8 b2;
    s8 b1;
    s8 b0;

    b0 = bytes[0];
    b1 = bytes[1];
    if (bytes && bytes) {}
    hi = (b1 << 16) & 0xFF0000;
    value = (b0 << 24) | hi;
    b2 = bytes[2];
    b3 = bytes[3];
    if (bytes && bytes) {}
    value |= (b2 << 8) & 0xFF00;
    value |= b3 & 0xFF;
    return value;
}

s32 RlcArchive::get_chunk_count() {
    if (header == NULL) {
        set_mode(7);
        return -1;
    }
    return header->get_chunk_count();
}

void RlcArchive::set_directory_pointer() { directory = (RlcDirectoryEntry *)(buffer + header->get_directory_offset()); }
void RlcArchive::set_header_pointer() { header = (RlcHeader *)buffer; }

void RlcArchive::store_capture_filename(saddr file) {
    if ((s32)strlen((const char *)file) > 0x1F) {
        strncpy(name, (const char *)file, 0x1F);
        name[0x1F] = 0;
        return;
    }
    strcpy(name, (const char *)file);
}

void RlcArchive::free_buffer() {
    if (buffer != NULL) {
        mem_free(buffer);
        buffer = 0;
    }
}

s32 RlcArchive::alloc_buffer() {
    buffer = (u8 *)mem_alloc(get_buffer_size());
    if (buffer == 0) {
        set_mode(4);
        return 0;
    }
    return 1;
}
s32 RlcArchive::open_stream(saddr file) {
    file_size = TGStream::read_whole_file((const char *)file, buffer);
    if (has_resource_size() == 0) {
        set_mode(2);
        free_buffer();
        return 0;
    }
    return 1;
}
s32 RlcArchive::init(saddr file) {
    file_size = TGStream::get_resource_file_size((const char *)file);
    if (has_resource_size() == 0) {
        set_mode(1);
        return 0;
    }
    return 1;
}
void RlcArchive::reset() {
    header = 0;
    directory = 0;
    memset(name, 0, 0x20);
    buffer = 0;
    file_size = 0;
    loaded = 0;
    error = 0;
}

RlcArchive::~RlcArchive() {}

RlcArchive::RlcArchive() { reset(); }

void RlcArchive::update_both() { free_buffer(); reset(); }
s32 RlcArchive::start_capture(saddr file) {
    if (file == 0) {
        set_mode(3);
        return 0;
    }
    if (init(file) == 0) {
        return 0;
    }
    if (alloc_buffer() == 0) {
        return 0;
    }
    if (open_stream(file) == 0) {
        return 0;
    }
    set_header_pointer();
    set_directory_pointer();
    store_capture_filename(file);
    loaded = 1;
    return 1;
}
int TWindowSnapShot::get_width() { return 32; }
void RlcArchive::set_mode(s32 v) { error = v; }
s32 RlcArchive::get_buffer_size() { return file_size; }
s32 RlcArchive::has_resource_size() { return (u8)(file_size != 0); }
void set_slot_size(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }
void set_slot_offset(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
