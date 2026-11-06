#include "types.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/item/TItemLoad_8010FDF0.h"
#include "pso/system/memory.h"
#include "pso/item/TUnk_8049C658.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/drop/TItemDrop.h"

extern "C" {

struct Sp8Buf_8010fe6c_8010FDF0 {
    s32 field00;
    s32 field04;
    s32 field08;
    s32 field0c;
    s32 field10;
    s32 field14;
    s32 field18;
    u32 field1c;
    s32 field20;
    s32 field24;
    s32 field28;
    s32 field2c;
    s32 field30;
    s32 field34;
    s32 field38;
    s32 field3c;
};

s32 apply_rel_relocations(s32 *);
s32 read_disc_file(u32, s32);
s32 read_checked_align__6TLobbyFlll(s32, s32, s32, void *);
void *mem_alloc(u32 size);
s32 prs_decompress_alloc(s32, u32, s32);
void mem_free(void *p);

    extern int item_load_compressed_work_buffer;
    extern int item_load_work_buffer_busy;
void TItemLoad::alloc_work_buffer() { item_load_compressed_work_buffer = (int)mem_alloc((u32)((void*)24576)); item_load_work_buffer_busy = 0; }

RelocatedFile::~RelocatedFile() {
    mem_free(buffer);
}

RelocatedFile::RelocatedFile(const char *path, s32 size) {
    struct Sp8Buf_8010fe6c_8010FDF0 sp8;
    s32 temp_r31;
    s32 item_buff;

    buffer = NULL;
    root = NULL;
    if ((size != 0) && (path != NULL)) {
        buffer = mem_alloc(size);
        item_buff = create_item_buff(size);
        if ((item_buff != 0) && (buffer != NULL) && (read_disc_file((u32)path, item_buff) > 0)) {
            temp_r31 = prs_decompress_alloc(item_buff, (u32)buffer, size);
            ((TUnk_8049C658 *)((s32 *)&sp8))->construct();
            sp8.field1c = (u32)buffer;
            sp8.field20 = temp_r31;
            root = (void *)apply_rel_relocations((s32 *)&sp8);
            ((TUnk_8049C658 *)((s32 *)&sp8))->destroy(-1);
        }
        TItemBuff__ct();
    }
}

void TItemLoad::request_load(s32 arg1) {
    read_checked_align__6TLobbyFlll(*(s32 *)&this->m_flags, *(s32 *)&this->m_next, arg1, this);
}

}
