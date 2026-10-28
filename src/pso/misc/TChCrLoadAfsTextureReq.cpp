#include "types.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_8001ED80.h"
#include "pso/TChCrLoadGmNjReq.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8028C378___vt__22TChCrLoadAfsTextureReq {
    s32 value;
    u8 remaining[0x14];
};

struct S_8028C310 { u8 pad0[4]; s32 cnt; };

struct R_8028C310 {
    u8 pad0[0x1c]; s32 f1c; u8 pad20[8]; s32 f28; s32 f2c; S_8028C310 *f30; u8 pad34[4];
    s32 tab[8]; s32 f58; s32 f5c; u8 pad60[4]; s32 f64; s32 f68;
};

struct Req_8028C1F0 {
    u8 pad[0x18];
    void *vt;
    s32 mode;
    u8 pad2[0x34 - 0x20];
    s32 *flags;
    u32 tab[8];
    s32 count;
    u8 pad3[0x60 - 0x5C];
    s32 handle;
    u8 pad4[0x6C - 0x64];
    s32 mask;
};

class Req_8028C090 {
public:
    u8 pad[0x28];
    s32 done;
    s32 state;
    u8 pad2[0x64 - 0x30];
    s32 wait;
    void m0();
    void m1();
    void m2();
};

typedef void (Req_8028C090::*Handler_8028C090)();

class TChCrLoadAfsTextureReq {
public:
    void try_begin_load(void *);
    void start_read(void *);
    void update_loading(void *);
};

extern "C" {
s32 queue_destruction__7TObjectFv(void *, int, int);
u32 get_bml_model(int, int);
s32 TLobby__sub_8001FE7C(int, int);
u32 TLobby__sub_8002058C(int, int, void *, void *, int, int, int);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__22TChCrLoadAfsTextureReq[];
extern void *lbl_805D3B50;
u8 *TChCrLoadAfsTextureReq__ct(u8 *arg0, u8 *arg1, s32 arg2, s32 *arg3, s32 arg4);
void init_texture_table__22TChCrLoadAfsTextureReqFPv(R_8028C310 *arg0);
void __dt__7TObjectFv(void *, s32);
void __dl__7TObjectFPv(void *);
void finish_request__22TChCrLoadAfsTextureReqFPv(void *arg0);
s32 TLobby__sub_803CC4C0(s32);
Req_8028C1F0 *__dt__22TChCrLoadAfsTextureReqFv(Req_8028C1F0 *arg0, s16 arg1);
f32 TLobby__sub_8028C50C(void);
void * create__22TChCrLoadAfsTextureReqFPvPv(void *arg0, void *arg1);
void *init__22TChCrLoadAfsTextureReqFPvPvPv(void *arg0, void *arg1, void *arg2);
s32 try_acquire_load_slot__22TChCrLoadAfsTextureReqFPv(void *arg0);
void try_begin_load__22TChCrLoadAfsTextureReqFPv(void* p);
void *__nw__7TObjectFUl(int);
f64 log();

void try_begin_load__22TChCrLoadAfsTextureReqFPv(void* p) { if (try_acquire_load_slot__22TChCrLoadAfsTextureReqFPv(p) != 0) { *(int*)((char*)p + 0x2c) = 1; } }

s32 TChCrLoadAfsTextureReq__active_load_count;

void run_task__22TChCrLoadAfsTextureReqFv(Req_8028C090 *arg0) {
    if (arg0->done == 1) {
        return;
    }
    if (--arg0->wait <= 0) {
        return;
    }
    static Handler_8028C090 tbl[] = {
        reinterpret_cast<Handler_8028C090>(&TChCrLoadAfsTextureReq::try_begin_load),
        reinterpret_cast<Handler_8028C090>(&TChCrLoadAfsTextureReq::start_read),
        reinterpret_cast<Handler_8028C090>(&TChCrLoadAfsTextureReq::update_loading),
    };
    if (arg0->state < 0 || arg0->state >= 3) {
        ((void (*)(void *))queue_destruction__7TObjectFv)(arg0);
        return;
    }
    (arg0->*tbl[arg0->state])();
}

extern s32 TChCrLoadAfsTextureReq__active_load_count;

void finish_request__22TChCrLoadAfsTextureReqFPv(void *arg0) {
    s32 temp_r0;

    if (((s32) *(s32 *)((s8 *)arg0 + 0x68) != 0) && ((s32) TChCrLoadAfsTextureReq__active_load_count <= 3)) {
        temp_r0 = TChCrLoadAfsTextureReq__active_load_count - 1;
        TChCrLoadAfsTextureReq__active_load_count = temp_r0;
        if (temp_r0 >= 0) {
            *(s32 *)((s8 *)arg0 + 0x68) = 0;
        }
    }
}

s32 try_acquire_load_slot__22TChCrLoadAfsTextureReqFPv(void *arg0) {
    if (((s32) TChCrLoadAfsTextureReq__active_load_count < 0) || ((s32) TChCrLoadAfsTextureReq__active_load_count > 3)) {
        return 0;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x68) == 1) {
        return 0;
    }
    if ((s32) TChCrLoadAfsTextureReq__active_load_count >= 3) {
        return 0;
    }
    TChCrLoadAfsTextureReq__active_load_count += 1;
    *(s32 *)((s8 *)arg0 + 0x68) = 1;
    return 1;
}

typedef char RecoveredGlobal_8028C378___vt__22TChCrLoadAfsTextureReq_size[sizeof(RecoveredGlobal_8028C378___vt__22TChCrLoadAfsTextureReq) == 0x18 ? 1 : -1];

Req_8028C1F0 *__dt__22TChCrLoadAfsTextureReqFv(Req_8028C1F0 *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        arg0->vt = ((s32 *)&__vt__22TChCrLoadAfsTextureReq);
        if (arg0->mode == 0 && arg0->tab[0] != 0) {
            if (TLobby__sub_803CC4C0(arg0->handle) == 2) {
                ((TLobby *)(arg0->handle))->adxf_stop();
            }
            ((TLobby *)(arg0->handle))->close_adxf_handle();
            arg0->handle = 0;
        }
        finish_request__22TChCrLoadAfsTextureReqFPv(arg0);
        for (i = 0; i < arg0->count; i++) {
            if (arg0->tab[i] != 0) {
                TAdSinglePlyChrSelectGC::safe_free(arg0->tab[i]);
                arg0->tab[i] = 0;
            }
        }
        if (arg0->mode == 1) {
            if (arg0->mask != 0) {
                *arg0->flags &= ~arg0->mask;
            } else if (arg0->flags != NULL) {
                *arg0->flags = 1;
            }
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void init_texture_table__22TChCrLoadAfsTextureReqFPv(R_8028C310 *arg0) {
    s32 i;
    arg0->f58 = arg0->f30->cnt;
    if (arg0->f58 <= 0 || arg0->f58 > 8) return;
    {
    for (i = 0; i < 8; i++) arg0->tab[i] = 0;
    arg0->f1c = 0;
    arg0->f2c = 0;
    arg0->f5c = 0;
    arg0->f28 = 0;
    arg0->f64 = 0x14FA;
    arg0->f68 = 0;
    }
}

u8 *TChCrLoadAfsTextureReq__ct(u8 *object, u8 *arg1, s32 arg2, s32 *arg3, s32 arg4) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &(*(RecoveredGlobal_8028C378___vt__22TChCrLoadAfsTextureReq *)&__vt__22TChCrLoadAfsTextureReq).value;
    *(s32 *)((s8 *)object + 0) = (s32) (*(s32 *)&lbl_805D3B50);
    *(s32 *)((s8 *)object + 0x30) = arg2;
    *(s32 **)((s8 *)object + 0x34) = arg3;
    **(s32 **)((s8 *)object + 0x34) = 0;
    *(s32 *)((s8 *)object + 0x6C) = 0;
    *(s32 *)((s8 *)object + 0x70) = arg4;
    init_texture_table__22TChCrLoadAfsTextureReqFPv((R_8028C310 *)(object));
    return object;
}

void *init__22TChCrLoadAfsTextureReqFPvPvPv(void *object, void *arg1, void *arg2) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = __vt__22TChCrLoadAfsTextureReq;
    *(void **)((s8 *)object + 0x0) = lbl_805D3B50;
    *(void **)((s8 *)object + 0x30) = *(void **)((s8 *)arg2 + 0x0);
    *(void **)((s8 *)object + 0x6C) = *(void **)((s8 *)arg2 + 0x4);
    *(void **)((s8 *)object + 0x34) = *(void **)((s8 *)arg2 + 0x8);
    *(void **)((s8 *)object + 0x70) = *(void **)((s8 *)arg2 + 0xC);
    init_texture_table__22TChCrLoadAfsTextureReqFPv((R_8028C310 *)(object));
    return object;
}
}
void * create_ch_cr_load_afs_texture_req(void *arg0, void *arg1, void *arg2, void *arg3);
void * create_ch_cr_load_afs_texture_req(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x194);
    if (o != NULL) {
        o = TChCrLoadAfsTextureReq__ct((u8 *)o, (u8 *)arg0, (s32)arg1, (s32 *)arg2, (s32)arg3);
    }
    return o;
}

void * create__22TChCrLoadAfsTextureReqFPvPv(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x194);
    if (o != NULL) {
        o = init__22TChCrLoadAfsTextureReqFPvPvPv(o, arg0, arg1);
    }
    return o;
}

f32 TLobby__sub_8028C50C(void) {
    return (f32) log();
}
#pragma push
#pragma fp_contract on
void TLobby::update_model_load() {
    s32 *temp_r5;
    s32 temp_r0;
    s32 temp_r4;
    u32 bml_model;
    u32 var_r31;
    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x74) - 1;
    *(s32 *)((s8 *)((u8 *)this) + 0x74) = temp_r0;
    if (temp_r0 < 0) {
        if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x68) != 0U) {
            TLobby__sub_8001FE7C((int) *(u32 *)((s8 *)((u8 *)this) + 0x68), 1);
        } else {
            return;
        }
        var_r31 = (int)::operator new(0x440);
        if (var_r31 != 0U) {
            var_r31 = TLobby__sub_8002058C(var_r31, 6, (void *) (((u8 *)this) + 0x60), (void *) (((u8 *)this) + 0x64), 0, 0, (int) (((TLobby *)(*(s32 *)((s8 *)((u8 *)this) + 0x24)))->start_load_default()));
        }
        *(u32 *)((s8 *)((u8 *)this) + 0x68) = var_r31;
        if (var_r31 != 0U) {
            *(s32 *)((s8 *)((u8 *)this) + 0x74) = 0x12C;
        }
    } else if (fn_8001ED90((void *)(*(u32 *)((s8 *)((u8 *)this) + 0x68))) != 0) {
        bml_model = get_bml_model((int) (*(u32 *)((s8 *)((u8 *)this) + 0x68)), 0);
        **(u32 **)((s8 *)((u8 *)this) + 0x1C) = bml_model;
        if (bml_model != 0U) {
            ((TLobby *)(*(s32 *)((s8 *)((u8 *)this) + 0x24)))->alloc_load_buffer((int) (TLobby__sub_8001ED88((void *)(*(u32 *)((s8 *)((u8 *)this) + 0x68)))));
            TLobby__sub_8001FE7C((int) (*(u32 *)((s8 *)((u8 *)this) + 0x68)), 1);
            *(u32 *)((s8 *)((u8 *)this) + 0x68) = 0U;
            ((TChCrLoadGmNjReq *)((u8 *)this))->sub_8028C8A8();
            temp_r5 = *(s32 **)((s8 *)((u8 *)this) + 0x28);
            temp_r4 = *temp_r5;
            *temp_r5 = temp_r4 & ~*(s32 *)((s8 *)((u8 *)this) + 0x20);
            queue_destruction__7TObjectFv(this, (int)temp_r4, (int)temp_r5);
        }
    }
}
#pragma pop
