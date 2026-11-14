#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TUnk_804F3640.h"
#include "pso/unk/text_80076E84.h"
#include "pso/unk/TLobby_8036B204.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"


struct Obj_8036B2E8 { u8 pad0[0x1C]; u32 base; s32 t[4]; };
struct Obj_8036B340 { u8 pad0[0x1C]; u32 base; s32 t[4]; };

struct Ent_8036B424 { u8 b[0x3C]; };

struct Mgr_8036B424 {
    u8 pad0[0x18];
    void *vt;
    Ent_8036B424 *buf;
    void *ptrs[4];
};

extern "C" {
s32 TLobby__sub_8036B1AC(s32);
void mem_free(void *p);
extern s32 __vt__13TUnk_804F3640[];
u32 slot_entity_dispatcher_instance;
void *__nw__7TObjectFUl(int);
void *mem_alloc(u32 size);
void __ct__7TObjectFP7TObject(void *);
Mgr_8036B424 *TLobby__sub_8036B424(Mgr_8036B424 *arg0, void * _w1);

void TLobby::send_slot_entity_or_local(u16 arg0, s32 arg1) {
    if (((u32) slot_entity_dispatcher_instance != 0U) && (arg0 < 4U)) {
        ((TLobby *)slot_entity_dispatcher_instance)->send_slot_entity(arg0, arg1);
        return;
    }
    TLobby__sub_8036B1AC(arg1);
}

void dispatch_by_index__6TLobbyFUsi(u16 arg0, s32 src) {
    if (((u32) slot_entity_dispatcher_instance != 0U) && (arg0 < 4U)) {
        ((TLobby *)slot_entity_dispatcher_instance)->start_entry_timer(arg0, src);
    }
}
void TLobby::send_slot_entity(u16 arg1, s32 arg2) {
    u32 temp_r6;
    temp_r6 = *(u32 *)((s8 *)this + 0x1C);
    if (temp_r6 != 0U) {
        copy_symbol_chat_entry__6TLobbyFPvPv((void *)arg2, (void *)(temp_r6 + (arg1 * 0x3C)));
        return;
    }
    TLobby__sub_8036B1AC(arg2);
}
void TLobby::start_entry_timer(u16 arg1, s32 src) {
    Obj_8036B2E8 *arg0 = (Obj_8036B2E8 *)this;
    if (arg0->base != 0) {
        s32 i = arg1;
        copy_symbol_chat_entry__6TLobbyFPvPv((void *)(arg0->base + i * 0x3C), (void *)src);
        arg0->t[i] = 0x78;
    }
}

void TUnk_804F3640::run_task() {
    Obj_8036B340 *arg0 = (Obj_8036B340 *)this;
    s32 i;
    for (i = 0; i != 4; i++) {
        if (arg0->t[i] != 0) {
            arg0->t[i] = arg0->t[i] - 1;
            if (arg0->t[i] == 0) {
                TLobby__sub_8036B1AC(arg0->base + i * 0x3C);
            }
        }
    }
}
}
TUnk_804F3640::~TUnk_804F3640() {
    mem_free((void *)(*(s32 *)((s8 *)this + 0x1C)));
    (*(s32 *)&slot_entity_dispatcher_instance) = 0;
}


Mgr_8036B424 *TLobby__sub_8036B424(Mgr_8036B424 *arg0, void * _w1) {
    s32 i;
    __ct__7TObjectFP7TObject(arg0);
    arg0->vt = ((s32 *)&__vt__13TUnk_804F3640);
    arg0->buf = (Ent_8036B424 *)mem_alloc(0xF0);
    if (arg0->buf != 0) {
        for (i = 0; i != 4; i++) {
            TLobby__sub_8036B1AC((s32)&arg0->buf[i]);
            arg0->ptrs[i] = 0;
        }
    } else {
        ((TObject *)arg0)->queue_destruction();
    }
    slot_entity_dispatcher_instance = (u32)arg0;
    return arg0;
}

void create_singleton__6TLobbyFPv(void *arg0) {
    void *o;
    if ((*(void * *)&slot_entity_dispatcher_instance) == NULL) {
        o = __nw__7TObjectFUl(0x30);
        if (o != NULL) {
            TLobby__sub_8036B424((Mgr_8036B424 *)(o), arg0);
        }
    }
}
void TLobby__sub_8036B50C(void) {  }
void TLobby__sub_8036B510(void) {  }

