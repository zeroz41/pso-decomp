#include "types.h"
#include "pso/item/TItemLoad_8010FC28.h"
#include "pso/item/TItemLoad_8010F52C.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/system/memory.h"
#include "pso/item/TUnk_8049F41C.h"
#include "pso/item/TUnk_8049F40C.h"
#include "pso/TItemLoad.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Load_8010F838 { u8 pad[0x14]; void *vtbl; u8 pad18[0xC]; s32 id; s32 f28; s32 f2c[4]; s32 f3c; };

struct Load_8010F61C { u8 pad[0x24]; s32 id; s32 f28; s32 f2c[4]; s32 f3c; };

struct Ent_8010F68C { void *vt; u8 pad[8]; };

struct List_8010F68C { Ent_8010F68C *ents; u32 count; };

struct Load_8010F68C { u8 pad[0x24]; s32 id; List_8010F68C *list; void *f2c[4]; void *f3c; };

extern "C" {
void *mem_alloc(u32 size);
extern s32 lbl_805D2BE8;
extern s32 lbl_805D2BEC;
extern void *item_texture_archive_loader;
extern void *item_model_chunk_loader;
extern s32 item_load_model_buffer;
void init__13TUnk_8049F42CFv(void *, void *, int, int);
extern s32 lbl_8049F40C[];
s32 decompress_buffer__9TItemLoadFUl();
void *TLobby__sub_801E38A0(s32, u32 *, s32 *, s32, s32 *);
extern u8 lbl_80506208[];
extern s32 item_load_tmp_buffer;
struct Base_8010F52C { char pad[0x14]; };
struct VObj_8010F52C : Base_8010F52C {
    virtual void m0(int);
};

s32 load_gvm_texture_archive(s32, s32);
void mem_free(void *p);

void TItemLoad::free_all_models() {
    mem_free((void *)item_load_model_buffer);
    if (item_model_chunk_loader != NULL) {
        ((struct VObj_8010F52C *)item_model_chunk_loader)->m0(1);
    }
    if (item_texture_archive_loader != NULL) {
        ((struct VObj_8010F52C *)item_texture_archive_loader)->m0(1);
    }
    item_texture_archive_loader = NULL;
    item_model_chunk_loader = NULL;
    item_load_model_buffer = 0;
}

void TItemLoad__sub_8010F5A0(void) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r0;
    s32 var_r0_2;
    temp_r3 = (int)::operator new(0x28);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = ((s32)((TUnk_8049F41C *)temp_r3)->construct((void *)lbl_805D2BE8, 0xB5, 0x144));
    }
    (*(s32 *)&item_texture_archive_loader) = var_r0;
    temp_r3_2 = (int)::operator new(0x40);
    var_r0_2 = temp_r3_2;
    if (var_r0_2 != 0) {
        var_r0_2 = ((TUnk_8049F40C *)temp_r3_2)->construct_with_vtable((void *)lbl_805D2BEC, 0xB4, 0x12F);
    }
    (*(s32 *)&item_model_chunk_loader) = var_r0_2;
    item_load_model_buffer = (s32)mem_alloc(0x21000);
}

void TItemLoad::start_load_with_id(s32 id, s32 arg2) {
    Load_8010F61C *self = (Load_8010F61C *)this;
    s32 i;
    if (id != 0 && ((TItemLoad *)self)->begin_load(arg2) == 1) {
        self->id = id;
        self->f28 = 0;
        for (i = 0; i < 4; i++) {
            self->f2c[i] = 0;
        }
        self->f3c = 0;
    }
}

void TUnk_8049F40C::vfunc_3() {
    u32 pos;
    s32 tag;
    s32 size;
    s32 h;
    s32 off;
    u32 total;
    s32 n;
    void *p;
    u32 i;
    if (TLobby__sub_8001EEF4() == 1) {
        h = TLobby::tmp_buf_use_req((const char *)item_load_tmp_buffer);
        off = ((Load_8010F68C *)this)->id;
        total = decompress_buffer__9TItemLoadFUl();
        pos = 0;
        n = 0;
        while (pos < total) {
            p = TLobby__sub_801E38A0(h, &pos, &tag, off, &size);
            off += (size + 0x20) & ~0x1F;
            switch (tag) {
            case 0x4E4A434D:
                if (n < 4) {
                    ((Load_8010F68C *)this)->f2c[n] = p;
                    n++;
                }
                break;
            case 0x4E4A544C:
                if (((Load_8010F68C *)this)->list == NULL) {
                    ((Load_8010F68C *)this)->list = (List_8010F68C *)p;
                    for (i = 0; i != ((Load_8010F68C *)this)->list->count; i++) {
                        ((Load_8010F68C *)this)->list->ents[i].vt = lbl_80506208;
                    }
                }
                break;
            case 0x4E4D444D:
                ((Load_8010F68C *)this)->f3c = p;
                break;
            }
        }
        ((TLobby *)item_load_tmp_buffer)->tmp_buf_release();
        ((Load_8010F68C *)this)->id = 0;
        ((TItemLoad *)((Load_8010F68C *)this))->reset_state();
    }
}

void *TUnk_8049F40C::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 * *)&(*(TObject * *)((u8 *)this + 0x14)) = lbl_8049F40C;
        __dt__13TUnk_8049F42CFv((u8 *)this, 0);
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

s32 TUnk_8049F40C::construct_with_vtable(void *a1, int a2, int a3) {
    int arg0 = (int)this;
    Load_8010F838 *self = (Load_8010F838 *)arg0;
    s32 i;
    init__13TUnk_8049F42CFv(self, a1, a2, a3);
    self->vtbl = ((s32 *)&lbl_8049F40C);
    self->id = 0;
    for (i = 0; i < 4; i++) {
        self->f2c[i] = 0;
    }
    self->f28 = 0;
    self->f3c = 0;
    return (s32)self;
}

void TItemLoad::begin_load_if_pending(s32 arg1, s32 arg2) {
    if ((arg1 != 0) && (begin_load(arg2) == 1)) {
        *(s32 *)((s8 *)this + 0x24) = arg1;
    }
}

void TItemLoad::reload_item() {
    s32 temp_r31;

    if (TLobby__sub_8001EEF4() == 1) {
        temp_r31 = TLobby::tmp_buf_use_req((const char *)item_load_tmp_buffer);
        decompress_buffer__9TItemLoadFUl();
        load_gvm_texture_archive(temp_r31, *(s32 *)((s8 *)this + 0x24));
        ((TLobby *)item_load_tmp_buffer)->tmp_buf_release();
        *(s32 *)((s8 *)this + 0x24) = 0;
        reset_state();
    }
}

extern s32 lbl_8049F41C[];

void *__dt__13TUnk_8049F41CFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x14) = lbl_8049F41C;
        __dt__13TUnk_8049F42CFv((u8 *)arg0, 0);
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

void *TUnk_8049F41C::construct(void *_w1, int _w2, int _w3) {
    init__13TUnk_8049F42CFv(this, _w1, _w2, _w3);
    *(s32 * *)&(*(TObject * *)((u8 *)this + 0x14)) = lbl_8049F41C;
    *(u32 *)((s8 *)this + 0x24) = 0;
    return this;
}

}
