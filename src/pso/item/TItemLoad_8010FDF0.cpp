#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/TItemLoad_8010FC28.h"
#include "pso/system/memory.h"
#include "pso/item/TUnk_8049F42C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/item/TItemLoad_8010FDF0.h"
#include "pso/item/TUnk_8049C658.h"
#include "pso/item/drop/TItemDrop.h"

extern "C" {
s32 test_flags_any(void *, int);
extern s32 lbl_8049F42C[];
extern s32 item_load_work_buffer_busy;
void init_buffer__9TItemLoadFPviii(void *);
void mem_free(void *p);
struct VOff_8010FD2C_arg0_8010fd2c { char pad_0[0x1C]; char f_1C[1]; };

extern s32 item_load_compressed_work_buffer;

void TItemLoad::advance_load_state() {
    u8 *arg0 = (u8 *)this;
    if (test_flags_any(arg0 + 0x1C, 4) == 0) {
        if ((s32) item_load_work_buffer_busy != 1) {
            item_load_work_buffer_busy = 1;
            ((FlagWord *)(arg0 + 0x1C))->set(4);
            goto block_3;
        }
    } else {
block_3:
        if (((TItemLoad *)arg0)->load_data((int) (*(s32 *)((s8 *)arg0 + 0x20))) != 0U) {
            TItemLoad__sub_801107DC(arg0);
            ((TItemLoad *)arg0)->request_load(item_load_compressed_work_buffer);
            *(s32 *)((s8 *)arg0 + 0x18) = 2;
        }
    }
}

u8 *__dt__13TUnk_8049F42CFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x14) = lbl_8049F42C;
        if (test_flags_any(arg0 + 0x1C, 4) != 0) {
            item_load_work_buffer_busy = 0;
        }
        ((TUnk_8049F42C *)arg0)->sub_80110010(0);
        if (arg1 > 0) {
            ::operator delete((arg0));
        }
    }
    return arg0;
}

void *TUnk_8049F42C::init() {
    struct VOff_8010FD2C_arg0_8010fd2c *self = (struct VOff_8010FD2C_arg0_8010fd2c *)this;
    init_buffer__9TItemLoadFPviii(this);
    *(s32 * *)&(*(TObject * *)((u8 *)this + 0x14)) = lbl_8049F42C;
    __ct__8FlagWordFv((self->f_1C));
    *(u32 *)((s8 *)this + 0x18) = 0;
    ((FlagWord *)(self->f_1C))->reset();
    return this;
}

s32 TItemLoad::decompress_buffer(u32 arg0) {
    if (((u32) (*(u32 *)&item_load_compressed_work_buffer) != 0U) && (arg0 != 0U)) {
        return prs_decompress_buffer((*(u32 *)&item_load_compressed_work_buffer), arg0);
    }
    return 0;
}

void TItemLoad::free_boss4_rock() { mem_free((void *)item_load_compressed_work_buffer); item_load_compressed_work_buffer = 0; }

}

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

void TItemLoad::alloc_work_buffer() { item_load_compressed_work_buffer = (s32)mem_alloc((u32)((void*)24576)); item_load_work_buffer_busy = 0; }

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
