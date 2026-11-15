#include "types.h"
#include "pso/unk/TUnk_804F1C58.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

extern "C" {

void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void mem_free(void *);

struct RecoveredGlobal_8035A860_lbl_804F1C58 {
    s32 value;
    u8 remaining[0x14];
};
extern RecoveredGlobal_8035A860_lbl_804F1C58 lbl_804F1C58;
typedef char RecoveredGlobal_8035A860_lbl_804F1C58_size[sizeof(RecoveredGlobal_8035A860_lbl_804F1C58) == 0x18 ? 1 : -1];

void *TUnk_804F1C58::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = &lbl_804F1C58.value;
        mem_free(*(void * *)&(this->m_28));
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}


extern "C" {
void *mem_alloc(u32 size);
s32 __ct__7TObjectFP7TObject(void *, void *);
TUnk_804F1C58 *__ct__13TUnk_804F1C58FP7TObjectPv(TUnk_804F1C58 *self, TObject *parent, void *model) {
    __ct__7TObjectFP7TObject(self, parent);
    *(s32 **)((s8 *)self + 0x18) = &lbl_804F1C58.value;
    self->model = model;
    self->m_20 = 0;
    self->m_24 = 0.0f;
    self->m_30 = 0;
    self->node_count = ((TObjBoss2Tunnel *)model)->count_tree_nodes();
    self->m_28 = mem_alloc(self->node_count * 0x30);
    self->m_34 = 0;
    self->m_38 = 0;
    return self;
}
}
