#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneMe3Shinowa.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEneMe3ShinowaMirage.h"

struct Obj_800E4554 { u8 pad0[0x1C]; u16 f1C; u8 pad1E[0xE]; s16 f2C; u8 pad2E[0x42C - 0x2E]; u16 slots[8]; };

struct Base_800E46D4 { s32 f0; u8 pad4[0x14]; };

struct Obj_800E46D4 : Base_800E46D4 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void m85(s16, s32);
    u8 pad1C[0x326 - 0x1C];
    s16 f326;
    u8 pad328[0x3C4 - 0x328];
    u32 f3C4;
    u8 pad3C8[0x3D4 - 0x3C8];
    s32 f3D4;
    u8 pad3D8[0x42C - 0x3D8];
    u16 slots[8];
};

extern "C" {
s32 sub_800E7250__21TObjEneMe3ShinowaRealFv();
s32 create__23TObjEneMe3ShinowaMirageFPvPv(void *, s32, s32, s32);
void *find_entity_by_id(u16 id);
u16 get_entity_id();
void TObjEneMe3Shinowa__ct(void *, void *);
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);
void fn_800E762C(void *);
extern s32 TObjEneMe3ShinowaReal_class_name;
extern s32 __vt__21TObjEneMe3ShinowaReal[];
Obj_800E46D4 *TObjEneMe3ShinowaReal__ct(Obj_800E46D4 *arg0, void *arg1, void *arg2);
u16 TObjEneMe3ShinowaReal__sub_800E45CC(void* p);
void *__dt__21TObjEneMe3ShinowaRealFv(void *arg0, s16 arg1);
int vfunc_62__17TObjEneMe3ShinowaFv(void*);
int vfunc_63__17TObjEneMe3ShinowaFv(void*);
void __dl__7TObjectFPv(void *);
void *__dt__17TObjEneMe3ShinowaFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
int init_mirage__23TObjEneMe3ShinowaMirageFv(void);

void TObjEneMe3ShinowaReal::spawn_mirages() { { int i; for (i = 0; i < 4; i++) { get_or_create_mirage((s32)((void*)((void*)i))); init_mirage__23TObjEneMe3ShinowaMirageFv(); } } }
void TObjEneMe3ShinowaReal::vfunc_111() { this->try_spawn_mirages(); }

void TObjEneMe3ShinowaReal::vfunc_107() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3D8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3D8) + 1);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x3D8) >= 2) {
        ((TObjEneMe3ShinowaReal *)arg0)->try_spawn_mirages();
        ((TObjEneDD *)arg0)->transition_enemy_state(7);
        return;
    }
    ((TObjEneDD *)arg0)->transition_enemy_state(4);
}

s32 TObjEneMe3ShinowaReal::get_or_create_mirage(s32 arg1) {
    Obj_800E4554 *arg0 = (Obj_800E4554 *)this;
    s32 r;
    if (arg0->slots[arg1] == 0xFFFF) {
        u16 t = this->entity_id;
        s32 n = arg1 + 1;
        r = create__23TObjEneMe3ShinowaMirageFPvPv(arg0, (u16)(t + n), arg0->f2C + n, t);
        if (r != 0) {
            arg0->slots[arg1] = get_entity_id();
        }
    } else {
        r = (s32)find_entity_by_id(arg0->slots[arg1]);
    }
    return r;
}

u16 TObjEneMe3ShinowaReal__sub_800E45CC(void* p) { return *(u16*)((char*)p + 0x38c); }

void TObjEneMe3ShinowaReal::try_spawn_mirages() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x3C4) & 0x10) {
        sub_800E7250__21TObjEneMe3ShinowaRealFv();
        spawn_mirages();
    }
}

void TObjEneMe3ShinowaReal::vfunc_62() { this->try_spawn_mirages(); vfunc_62__17TObjEneMe3ShinowaFv(this); }
void TObjEneMe3ShinowaReal::vfunc_63() { this->try_spawn_mirages(); vfunc_63__17TObjEneMe3ShinowaFv(this); }

void *__dt__21TObjEneMe3ShinowaRealFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__21TObjEneMe3ShinowaReal;
        __dt__17TObjEneMe3ShinowaFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

Obj_800E46D4 *TObjEneMe3ShinowaReal__ct(Obj_800E46D4 *arg0, void *ene_me3_shinowa, void *arg2) {
    s32 i;
    TObjEneMe3Shinowa__ct(arg0, ene_me3_shinowa);
    *(void **) ((u8 *) arg0 + 0x18) = ((u8 *)&__vt__21TObjEneMe3ShinowaReal);
    arg0->f0 = TObjEneMe3ShinowaReal_class_name;
    invoke_initialization_hook__9TObjEneDDFv(arg0, arg2);
    fn_800E762C(arg0);
    ((TObjEneMe3Shinowa *)arg0)->init_enemy();
    arg0->f3D4 = 0;
    arg0->f3C4 &= 0xFFFFEFFF;
    for (i = 0; i < 4; i++) {
        arg0->slots[i] = 0xFFFF;
    }
    arg0->f326 = 0;
    arg0->m85(arg0->f326, 4);
    return arg0;
}

void *TObjEneMe3ShinowaReal::create() {
    void *o = __nw__7TObjectFUl(0x434);
    if (o != NULL) {
        o = TObjEneMe3ShinowaReal__ct((Obj_800E46D4 *)(o), tl_04, this);
    }
    return o;
}

}
