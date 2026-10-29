#include "types.h"
#include "pso/enemy/TObjEneRe7Berura_803E4CE0.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/object/TObjFish_800E2FFC.h"
#include "pso/object/TObjFish.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Entry_800E2FFC { s32 id; u8 data[0xC]; };

struct Param_800E2FFC { s32 a; s32 b; s32 c; };

struct State_800E2FFC { s32 counter; Entry_800E2FFC *list; Param_800E2FFC *params; s32 pad; };

struct Entry_800E30BC { s32 id; u8 data[0xC]; };

struct Entry_800E3074 { s32 id; u8 data[0xC]; };

struct Param_800E3074 { s32 a; s32 b; s32 c; };

struct State_800E3074 { s32 counter; Entry_800E3074 *list; Param_800E3074 *params; s32 pad; };

struct Arg_800E3074 { Entry_800E3074 *list; Param_800E3074 *params; };

extern "C" {
u8 * fn_800E31C4(void *, void *, s32);
extern State_800E2FFC TObjFish_draw_callback_state;
void transform_to_view__11TCameraCtrlFii(s32 arg0, s32 arg1);

void TObjFish::draw_callback_transform_to_view() {
    Entry_800E2FFC *p = TObjFish_draw_callback_state.list;
    Param_800E2FFC *q = TObjFish_draw_callback_state.params;
    s32 id;
    while ((id = p->id) != -1) {
        if (id == TObjFish_draw_callback_state.counter) {
            transform_to_view__11TCameraCtrlFii((s32)p->data, (s32)q);
        }
        p++;
        q++;
    }
    TObjFish_draw_callback_state.counter++;
}

void TObjFish::set_draw_callback_list() {
    Arg_800E3074 *arg = (Arg_800E3074 *)this;
    (*(State_800E3074 *)&TObjFish_draw_callback_state).counter = 0;
    (*(State_800E3074 *)&TObjFish_draw_callback_state).list = arg->list;
    (*(State_800E3074 *)&TObjFish_draw_callback_state).params = arg->params;
    set_chunk_model_node_callback((s32)((void *)TObjFish::draw_callback_transform_to_view));
}

s32 TObjFish::is_entry_table_valid() {
    Entry_800E30BC *p = (Entry_800E30BC *)this;
    s32 i;
    if (p == 0) {
        return 0;
    }
    for (i = 0; p->id != -1; i++, p++) {
        if (i >= 0x40) {
            return 0;
        }
    }
    return 1;
}

void TObjFish::init_state_1(void *arg0) {
    TObjFish__sub_800E3188((s32)arg0, (s16)(1));
}

s32 TObjFish__sub_800E3124(u8 *list, s32 vecs) {
    s32 temp_r3;
    s32 var_r0;
    if (((TObjFish *)list)->is_entry_table_valid() != 0) {
        temp_r3 = (int)::operator new(8);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = (long) (fn_800E31C4((void *) temp_r3, list, vecs));
        }
        return var_r0;
    }
    return 0;
}

s32 TObjFish__sub_800E3188(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

}
