#include "pso/system/RlcArchive.h"
#include "types.h"
#include "pso/ui/window/TWindowSnapShot_802A5B2C.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/system/TGStream.h"
#include "pso/unk/TLobby.h"

extern "C" {
s32 strncpy(void *, void *, int);
s32 strcpy(void *, void *);
s32 strlen(void *);
void mem_free(void *);
void *mem_alloc(u32 size);
s32 memset(void *, int, int);

}

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

s32 RlcArchive::fn_802A5C3C() {
    if (header == NULL) {
        set_mode(7);
        return -1;
    }
    return header->get_chunk_count();
}

void RlcArchive::fn_802A5C7C() { directory = (RlcDirectoryEntry *)(buffer + header->get_directory_offset()); }
void RlcArchive::fn_802A5CB8() { header = (RlcHeader *)buffer; }

void RlcArchive::fn_802A5CC4(s32 file) {
    if (strlen((void *)file) > 0x1F) {
        strncpy(name, (void *)file, 0x1F);
        name[0x1F] = 0;
        return;
    }
    strcpy(name, (void *)file);
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
s32 RlcArchive::open_stream(s32 file) {
    file_size = TGStream::read_whole_file(file, buffer);
    if (fn_802A605C() == 0) {
        set_mode(2);
        free_buffer();
        return 0;
    }
    return 1;
}
s32 RlcArchive::init(s32 file) {
    file_size = ((TLobby *)file)->get_resource_file_size();
    if (fn_802A605C() == 0) {
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
s32 RlcArchive::start_capture(s32 file) {
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
    fn_802A5CB8();
    fn_802A5C7C();
    fn_802A5CC4(file);
    loaded = 1;
    return 1;
}
int TWindowSnapShot::get_width() { return 32; }
void RlcArchive::set_mode(s32 v) { error = v; }
s32 RlcArchive::get_buffer_size() { return file_size; }
s32 RlcArchive::fn_802A605C() { return (u8)(file_size != 0); }
void fn_802A6070(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }
void fn_802A6078(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
