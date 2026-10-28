#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Uro.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
struct Obj_8004AA04 { s32 count; u8 pad[0xC]; void **items; };

typedef struct Rec_8004AA80 {
    s32 a;
    s32 b;
    s32 c;
} Rec_8004AA80;

typedef struct Obj_8004AA80 {
    s32 count;
    u8 pad4[0x8 - 0x4];
    s32 f8;
    s32 fc;
    s32 *items;
} Obj_8004AA80;

extern "C" {
void mem_free(void *p);
void fn_8004AA04(Obj_8004AA04 *self);
s32 get_bml_model(s32, s32);
s32 alloc_tables__6TLobbyFll(s32, s32, s32);
void *mem_alloc(u32 size);
void init_model_node_tables(Obj_8004AA80 *arg0, Rec_8004AA80 *arg1, s32 arg2);
void fn_8004AA04(Obj_8004AA04 *self) {
    s32 i;
    for (i = 0; i < self->count; i++) {
        if (self->items[i] != 0) {
            destroy_buffer_pair(self->items[i], 1);
            self->items[i] = 0;
        }
    }
    mem_free(self->items);
    self->items = 0;
}
void init_model_node_tables(Obj_8004AA80 *arg0, Rec_8004AA80 *arg1, s32 arg2) {
    s32 h;
    s32 i;
    Rec_8004AA80 *r;
    s32 t;
    s32 p;
    s32 j;
    h = TBoss4Uro::get_instance_count();
    if (h == 0 || arg1 == NULL || arg2 < 1) {
        return;
    }
    arg0->count = arg2;
    arg0->items = NULL;
    arg0->items = (s32 *)mem_alloc(arg0->count * 4);
    arg0->f8 = 0;
    arg0->fc = 0;
    for (j = 0; j < arg0->count; j++) {
        arg0->items[j] = 0;
    }
    for (i = 0; i < arg0->count; i++) {
        r = &arg1[i];
        t = (s32)find_model_node(get_bml_model(h, r->a), r->b);
        p = (int)::operator new(0x14);
        if (p != 0) {
            p = alloc_tables__6TLobbyFll(p, t, r->c);
        }
        arg0->items[i] = p;
    }
}

}
