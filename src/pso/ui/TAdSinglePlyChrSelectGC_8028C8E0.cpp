#include "types.h"
#include "pso/ui/TChCrLoadGmNjReq.h"
#include "pso/misc/TLobby_801E2F94.h"
#include "pso/misc/TLobby_8028D714.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_8028C8E0.h"
#include "pso/misc/TChCrLoadReq.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TChCrLoadAfs.h"
#include "pso/misc/TCharaMaking.h"

struct Obj_8028C8A8 { u8 pad[0x6c]; s32 f6c; };

extern s32 chr_select_slot_state;

void TChCrLoadGmNjReq::sub_8028C8A8() {
    Obj_8028C8A8 *o = (Obj_8028C8A8 *)this;
    if (chr_select_slot_state < 0 || chr_select_slot_state > 1) return;
    if (o->f6c == 0) return;
    chr_select_slot_state--;
    o->f6c = 0;
}

struct Cm_8028CB6C { u8 pad[0x3E]; s16 f3e; };

struct Gc_8028CB6C { u8 pad0[0x38]; Cm_8028CB6C *cm; };

struct Sl_8028CB6C { u8 pad0[0x68]; s32 a; u8 pad6c[8]; void *b; u8 pad78[8]; void *c; };

struct Req_8028CC28 { s32 id; s32 type; s32 *flags; s32 index; };

struct Info_8028CC28 { u8 pad[0x10]; u32 a; u32 b; };

struct Sel_8028CC28 {
    u8 pad[0x38];
    void *chara;
    s32 *flags;
    u8 pad2[0x4C - 0x40];
    s32 id4C;
    s32 id50;
    s32 id54;
    u8 pad3[0x5C - 0x58];
    Info_8028CC28 *info;
};

struct Sel_8028C9B0 {
    u8 pad0[0x38];
    u8 *f38;
    u8 pad3C[0x44 - 0x3C];
    s32 *f44;
    u8 pad48[0x58 - 0x48];
    s32 *f58;
    u8 pad5C[0x68 - 0x5C];
    s32 f68[3];
    void *f74[6];
};

struct Arg_8028C9B0 {
    u8 *a;
    s32 b;
    s32 c;
    s32 x[3];
    u32 y[3];
    u32 z[3];
};

struct Req_8028CD18 {
    u32 data;
    void *dest;
    s32 ctx;
    s32 type;
    u32 *flags;
};

struct Cm_8028CD18 {
    u8 pad0[0x3E];
    s16 f3E;
    s16 f40;
};

struct Tbl_8028CD18 {
    u8 pad0[0x10];
    u32 *f10;
    u32 *f14;
    u32 *f18;
    u32 f1C;
};

struct Sel_8028CD18 {
    u8 pad0[0x38];
    Cm_8028CD18 *f38;
    u32 *f3C;
    s32 f40;
    s32 *f44;
    s32 *f48;
    u8 pad4C[0x5C - 0x4C];
    Tbl_8028CD18 *f5C;
};

extern "C" {
s32 is_selection_done__23TAdSinglePlyChrSelectGCFPv(void *);
void start_preview_loads__23TAdSinglePlyChrSelectGCFPv(Gc_8028CB6C *arg0);
void *create__22TChCrLoadAfsTextureReqFPvPv(void *arg0, void *arg1);
s32 is_node_tree_valid(u32, s32);
void blend_creation_proportion_shapes(void *);
extern s32 chr_select_preview_stride_table[];
extern s32 chr_select_preview_base_offset_table[];

extern s32 chr_select_slot_state;

s32 TAdSinglePlyChrSelectGC::try_acquire_slot() {
    if (((s32) chr_select_slot_state < 0) || ((s32) chr_select_slot_state > 1)) {
        return 0;
    }
    if ((s32) *(s32 *)((s8 *)this + 0x6C) != 0) {
        return 0;
    }
    if ((s32) chr_select_slot_state >= 1) {
        return 0;
    }
    chr_select_slot_state += 1;
    *(s32 *)((s8 *)this + 0x6C) = 1;
    return 1;
}

s32 TAdSinglePlyChrSelectGC::are_all_selections_done() {
    u8 *arg0 = (u8 *)this;
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    do {
        if (is_selection_done__23TAdSinglePlyChrSelectGCFPv(*(void **)(arg0 + 0x74 + off)) == 0) return 0;
        i++;
        off += 4;
    } while (i < 6);
    return 1;
}

s32 TAdSinglePlyChrSelectGC__sub_8028C998(void *arg0) {
    return (u32) __cntlzw((u32) (**(s32 **)((s8 *)arg0 + 0x3C) & 0x7F)) >> 5;
}

extern s32 chr_select_load_slot_count;

s32 TAdSinglePlyChrSelectGC::load_preview_models() {
    s32 len;
    s32 tag;
    u32 bufs[6];
    Arg_8028C9B0 s;
    s32 i;
    s32 j;
    u32 p;
    Sel_8028C9B0 *self = (Sel_8028C9B0 *)this;
    for (i = 0; i < 6; i++) {
        len = 0;
        p = (u32)TLobby__sub_801E38A0((s32)(((TAdSinglePlyChrSelectGC *)(self->f74[i]))->get_result()), &len, &tag, (s32 *)(0), (s32 *)(0));
        if (p == 0 || tag != 0x4E4A544C) return;
        TAdSinglePlyChrSelectGC::safe_free(p);
        bufs[i] = (u32)TLobby__sub_801E38A0((s32)(((TAdSinglePlyChrSelectGC *)(self->f74[i]))->get_result()), &len, &tag, (s32 *)(0), (s32 *)(0));
        if (bufs[i] == 0 || tag != 0x4E4A434D) {
            for (i = 0; i < 6; i++) TAdSinglePlyChrSelectGC::safe_free(bufs[i]);
            return;
        }
        if (is_node_tree_valid(bufs[i], tag) == 0) {
            for (i = 0; i < 6; i++) TAdSinglePlyChrSelectGC::safe_free(bufs[i]);
            return;
        }
    }
    s.a = self->f38;
    s.b = *self->f58;
    s.c = *self->f44;
    for (i = 0; i < 3; i++) {
        s.x[i] = self->f68[i];
        s.y[i] = bufs[i];
        s.z[i] = bufs[i + 3];
    }
    ((TAdSinglePlyChrSelectGC *)(&s))->reset_creation_parts();
    blend_creation_proportion_shapes(self->f38 + 0x48);
    for (j = 0; j < 6; j++) TAdSinglePlyChrSelectGC::safe_free(bufs[j]);
}

void start_preview_loads__23TAdSinglePlyChrSelectGCFPv(Gc_8028CB6C *arg0) {
    s32 off;
    Sl_8028CB6C *p;
    s32 disp;
    s32 i;
    s32 id;
    void *t;
    ((TAdSinglePlyChrSelectGC *)((u8 *)arg0->cm + 0x48))->get_sorted_region_samples((s32 *)((u8 *)arg0 + 0x68));
    disp = ((TCharaMaking *)(arg0->cm))->get_display_index();
    for (i = 0, off = 0; i < 3; i++, off += 4) {
        p = (Sl_8028CB6C *)((u8 *)arg0 + off);
        id = p->a;
        t = ((TChCrLoadAfs *)arg0)->create((void *)0xDB, (void *)(TAdSinglePlyChrSelectGC::calc_preview_offset(arg0, disp, arg0->cm->f3e, id)));
        p->b = t;
        if (t == NULL) {
            break;
        }
        p->c = ((TChCrLoadAfs *)arg0)->create((void *)0xDB, (void *)((void*)((TChCrLoadReq*)arg0)->calc_preview_last_index(disp, id)));
    }
}

void TAdSinglePlyChrSelectGC::request_texture_loads() {
    Sel_8028CC28 *arg0 = (Sel_8028CC28 *)this;
    Req_8028CC28 r1;
    Req_8028CC28 r2;
    Req_8028CC28 r3;
    s32 idx;
    idx = ((TCharaMaking *)(arg0->chara))->get_display_index();
    r1.id = arg0->id4C;
    r1.type = 4;
    r1.flags = arg0->flags;
    r1.index = idx;
    if (create__22TChCrLoadAfsTextureReqFPvPv(arg0, &r1) == 0) {
        return;
    }
    if (arg0->info->a != 0 || arg0->info->b != 0) {
        r2.id = arg0->id54;
        r2.type = 1;
        r2.flags = arg0->flags;
        r2.index = idx;
        if (create__22TChCrLoadAfsTextureReqFPvPv(arg0, &r2) == 0) {
            return;
        }
    } else {
        *arg0->flags &= ~1;
    }
    r3.id = arg0->id50;
    r3.type = 2;
    r3.flags = arg0->flags;
    r3.index = idx;
    if (create__22TChCrLoadAfsTextureReqFPvPv(arg0, &r3) == 0) {
        return;
    }
}

void TAdSinglePlyChrSelectGC::request_model_loads() {
    Req_8028CD18 r1;
    Req_8028CD18 r2;
    Req_8028CD18 r3;
    Req_8028CD18 r4;
    s32 idx;
    u32 *tbl;
    u32 d;
    TLobby__sub_8028D738(((Sel_8028CD18 *)this)->f40);
    *((Sel_8028CD18 *)this)->f44 = 0;
    r1.data = ((Sel_8028CD18 *)this)->f5C->f1C;
    r1.dest = ((Sel_8028CD18 *)this)->f44;
    r1.ctx = ((Sel_8028CD18 *)this)->f40;
    r1.type = 0x40;
    r1.flags = ((Sel_8028CD18 *)this)->f3C;
    if (create_ch_cr_load_gm_nj_req(this, &r1) == 0) return;
    idx = ((Sel_8028CD18 *)this)->f38->f40;
    ((Sel_8028CD18 *)this)->f48[1] = 0;
    tbl = ((Sel_8028CD18 *)this)->f5C->f14;
    if (tbl != 0 && (d = tbl[idx]) != 0) {
        r2.data = d;
        r2.dest = &((Sel_8028CD18 *)this)->f48[1];
        r2.ctx = ((Sel_8028CD18 *)this)->f40;
        r2.type = 8;
        r2.flags = ((Sel_8028CD18 *)this)->f3C;
        if (create_ch_cr_load_gm_nj_req(this, &r2) == 0) return;
    } else {
        *((Sel_8028CD18 *)this)->f3C &= ~8;
    }
    ((Sel_8028CD18 *)this)->f48[0] = 0;
    tbl = ((Sel_8028CD18 *)this)->f5C->f10;
    if (tbl != 0 && (d = tbl[idx]) != 0) {
        r3.data = d;
        r3.dest = &((Sel_8028CD18 *)this)->f48[0];
        r3.ctx = ((Sel_8028CD18 *)this)->f40;
        r3.type = 0x10;
        r3.flags = ((Sel_8028CD18 *)this)->f3C;
        if (create_ch_cr_load_gm_nj_req(this, &r3) == 0) return;
    } else {
        *((Sel_8028CD18 *)this)->f3C &= ~0x10;
    }
    ((Sel_8028CD18 *)this)->f48[2] = 0;
    r4.data = ((Sel_8028CD18 *)this)->f5C->f18[((Sel_8028CD18 *)this)->f38->f3E];
    r4.dest = &((Sel_8028CD18 *)this)->f48[2];
    r4.ctx = ((Sel_8028CD18 *)this)->f40;
    r4.type = 0x20;
    r4.flags = ((Sel_8028CD18 *)this)->f3C;
    if (create_ch_cr_load_gm_nj_req(this, &r4) == 0) return;
}

void TChCrLoadReq::sub_8028CEEC(s32 *) {
    if (((s32) chr_select_load_slot_count <= 1) && ((s32) this->m_8c != 0)) {
        this->m_8c = 0;
        if (--chr_select_load_slot_count == 0) {
            return;
        }
    }
}

s32 TAdSinglePlyChrSelectGC::try_claim_load_slot() {
    if (((s32) *(s32 *)((s8 *)this + 0x8C) != 0) || ((s32) chr_select_load_slot_count < 0) || ((s32) chr_select_load_slot_count > 1)) {
        return 0;
    }
    if ((s32) chr_select_load_slot_count >= 1) {
        return 0;
    }
    *(s32 *)((s8 *)this + 0x8C) = 1;
    chr_select_load_slot_count += 1;
    return 1;
}

s32 TAdSinglePlyChrSelectGC__sub_8028CF6C(void) {
    return chr_select_load_slot_count < 1;
}

}

s32 TChCrLoadReq::calc_preview_last_index(s32 display_index, s32 region_index) {
    s32 stride=chr_select_preview_stride_table[display_index];
    return stride + region_index * stride - 1 + chr_select_preview_base_offset_table[display_index];
}

void *TAdSinglePlyChrSelectGC::calc_preview_offset(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    return (void *)(arg2 + (arg3 * chr_select_preview_stride_table[arg1] + chr_select_preview_base_offset_table[arg1]));
}

void close_and_destroy__12TChCrLoadReqFv(void *arg0) {
    s32 *temp_r4;

    if (((TAdSinglePlyChrSelectGC *)arg0)->are_all_selections_done() != 0) {
        ((TAdSinglePlyChrSelectGC *)arg0)->load_preview_models();
        temp_r4 = *(s32 **)((s8 *)arg0 + 0x3C);
        *temp_r4 &= 0xFFFFFF7F;
        ((TChCrLoadReq *)arg0)->sub_8028CEEC(temp_r4);
        queue_destruction__7TObjectFv(arg0);
    }
}

void TChCrLoadReq::try_advance_state() { if (TAdSinglePlyChrSelectGC__sub_8028C998(this) != 0) { start_preview_loads__23TAdSinglePlyChrSelectGCFPv((Gc_8028CB6C *)(this)); this->state = 2; } }
