#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/boss/TBoss8Dragon_802FDDD4.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/boss/TBoss8Dragon.h"

struct Node_802FDDD4 {
    u8 pad0[4];
    s32 v;
    u8 pad1[0x24];
    Node_802FDDD4 *c0;
    Node_802FDDD4 *c1;
    u8 pad2[4];
};

extern "C" {

void copy_model_node(u8 *, u8 *);
Node_802FDDD4 *clone_node_tree__12TBoss8DragonFPvPvi(Node_802FDDD4 *src, Node_802FDDD4 *dst, s32 v);
extern f32 lbl_805D6980;
extern f32 lbl_805D6984;
extern f32 lbl_805D69C0;
extern f32 lbl_805D9E80;
extern f32 TBoss8Dragon__data_805DEDC8;
extern f32 lbl_805DEE40;

Node_802FDDD4 *clone_node_tree__12TBoss8DragonFPvPvi(Node_802FDDD4 *src, Node_802FDDD4 *dst, s32 v) {
    Node_802FDDD4 *cur = dst;
    dst = dst + 1;
    copy_model_node((u8 *)cur, (u8 *)src);
    cur->v = v;
    if (src->c0 != NULL) {
        cur->c0 = dst;
        dst = clone_node_tree__12TBoss8DragonFPvPvi(src->c0, dst, v);
    }
    if (src->c1 != NULL) {
        cur->c1 = dst;
        dst = clone_node_tree__12TBoss8DragonFPvPvi(src->c1, dst, v);
    }
    return dst;
}

void TBoss8Dragon::vfunc_44() {  }
void TBoss8Dragon::vfunc_45() {  }
void TBoss8Dragon::vfunc_46() {  }
void TBoss8Dragon::vfunc_47() {  }
void TBoss8Dragon::vfunc_48(s32) {  }
void TBoss8Dragon::vfunc_49() {  }
void TBoss8Dragon::vfunc_50() {  }
void TBoss8Dragon::send_swapped_packet() { bswap_packet(); send_subcommand((u8 *)this); }
void TBoss8Dragon::bswap_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }
}

void build_6xA8_gol_dragon_boss_actions(void* p) { *(u8*)((char*)p + 0x0) = 168; *(u8*)((char*)p + 0x1) = 6; }

void TBoss8Dragon__sub_802FDF10(void) {
    f32 temp_f1;

    temp_f1 = TBoss8Dragon__data_805DEDC8 * lbl_805D9E80;
    lbl_805D6980 = temp_f1;
    lbl_805D6984 = lbl_805DEE40 * lbl_805D9E80;
    lbl_805D69C0 = temp_f1;
}

__declspec(section ".ctors") static void *const __sinit_TBoss8Dragon_802FDDD4_cpp_ref = (void *)TBoss8Dragon__sub_802FDF10;
