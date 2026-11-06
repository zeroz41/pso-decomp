#include "pso/system/RlcArchive.h"
#include "types.h"
#include "pso/ui/window/TWindowSnapShot_802A5B2C.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/system/TGStream.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_802A5F24_lbl_804DD098 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
s32 strncpy(void *, void *, int);
s32 strcpy(void *, void *);
s32 strlen(void *);
void mem_free(void *);
extern s32 lbl_804DD098[];
u32 mem_alloc();
s32 memset(void *, int, int);

}

u32 RlcDirectoryEntry::get_size() { return read_be32(size_be); }
u32 RlcDirectoryEntry::get_offset() { return read_be32(offset_be); }
u32 RlcDirectoryEntry::read_be32(const s8 *bytes) { return 0; }

u32 RlcHeader::get_directory_offset() { return read_be32(directory_offset_be); }
u32 RlcHeader::get_chunk_count() { return read_be32(chunk_count_be); }
u32 RlcHeader::read_be32(const s8 *bytes) { return 0; }

s32 fn_802A5C3C(u32 *arg0) {
    u32 temp_r0;
    temp_r0 = *arg0;
    if (temp_r0 == 0U) {
        ((TWindowSnapShot *)arg0)->set_mode(7);
        return -1;
    }
    return ((RlcHeader *)temp_r0)->get_chunk_count();
}

void fn_802A5C7C(void *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = (s32) (*(s32 *)((s8 *)arg0 + 8) + ((RlcHeader *)(*(s32 *)((s8 *)arg0 + 0)))->get_directory_offset());
}
void fn_802A5CB8(void* p) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)p + 0x8); }

void fn_802A5CC4(u8 *arg0, s32 arg1) {
    if (strlen((void *)arg1) > 0x1F) {
        strncpy(arg0 + 0x1C, (void *)arg1, 0x1F);
        *(s8 *)((s8 *)arg0 + 0x3B) = 0;
        return;
    }
    strcpy(arg0 + 0x1C, (void *)arg1);
}

void TWindowSnapShot::free_buffer() {
    if (this->m_prev != NULL) {
        mem_free(this->m_prev);
        this->m_prev = 0;
    }
}

s32 alloc_buffer__15TWindowSnapShotFPv(TWindowSnapShot *window_snap_shot) {
    window_snap_shot->get_buffer_size();
    *(u32 *)((s8 *)window_snap_shot + 8) = mem_alloc();
    if ((u32) *(u32 *)((s8 *)window_snap_shot + 8) == 0U) {
        window_snap_shot->set_mode(4);
        return 0;
    }
    return 1;
}
s32 TWindowSnapShot::open_stream(s32 arg1) {
    *(s32 *)&this->m_next = TGStream::read_whole_file((s32)arg1, (u8 *)(*(s32 *)&this->m_prev));
    if (TWindowSnapShot__sub_802A605C((u8 *)this) == 0) {
        set_mode(2);
        free_buffer();
        return 0;
    }
    return 1;
}
s32 init__15TWindowSnapShotFPvi(TWindowSnapShot *window_snap_shot, s32 arg1) {
    *(s32 *)((s8 *)window_snap_shot + 0xC) = ((TLobby *)arg1)->get_resource_file_size();
    if (TWindowSnapShot__sub_802A605C((u8 *)window_snap_shot) == 0) {
        window_snap_shot->set_mode(1);
        return 0;
    }
    return 1;
}
void TWindowSnapShot::reset() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)&this->m_name = 0;
    *(s32 *)&this->m_flags = 0;
    memset((u8 *)&this->_pad1C, 0, 0x20);
    *(s32 *)&this->m_prev = 0;
    *(s32 *)&this->m_next = 0;
    *(s32 *)&this->m_down = 0;
    *(s32 *)((s8 *)arg0 + 0x18) = 0;
}
void *TWindowSnapShot__sub_802A5EDC(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x3C) = lbl_804DD098;
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_802A5F24_lbl_804DD098_size[sizeof(RecoveredGlobal_802A5F24_lbl_804DD098) == 0x10 ? 1 : -1];
u8 *TWindowSnapShot::init_and_reset() {
    u8 *arg0 = (u8 *)this;
    this->m_3c = &(*(RecoveredGlobal_802A5F24_lbl_804DD098 *)&lbl_804DD098).value;
    reset();
    return arg0;
}

void TWindowSnapShot::update_both() { free_buffer(); reset(); }
s32 TWindowSnapShot::start_capture(s32 arg1) {
    if (arg1 == 0) {
        set_mode(3);
        return 0;
    }
    if (init__15TWindowSnapShotFPvi(this, arg1) == 0) {
        return 0;
    }
    if (alloc_buffer__15TWindowSnapShotFPv(this) == 0) {
        return 0;
    }
    if (open_stream(arg1) == 0) {
        return 0;
    }
    fn_802A5CB8(this);
    fn_802A5C7C(this);
    fn_802A5CC4((u8 *)this, (s32)arg1);
    *(s32 *)&this->m_down = 1;
    return 1;
}
int TWindowSnapShot::get_width() { return 32; }
void TWindowSnapShot::set_mode(s32 v) { *(s32*)((char*)this + 0x18) = v; }
s32 TWindowSnapShot::get_buffer_size() { return *(s32 *)&this->m_next; }
s32 TWindowSnapShot__sub_802A605C(u8 *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0xC) != 0);
}
void fn_802A6070(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }
void fn_802A6078(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
