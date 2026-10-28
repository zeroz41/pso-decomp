#include "types.h"
#include "pso/items/TItemWeapon.h"

extern "C" {

int release_model__14TItemEquipBaseFv(void*);
int memset(void*, void*, void*);

void TItemWeapon::release_model() { memset((char*)this + 0x18c, (void*)0, (void*)16); clear_weapon_flags((u32)((void*)12)); release_model__14TItemEquipBaseFv(this); }

}

struct PlB_80120C5C { char pad[0x18]; };

struct Pl_80120C5C : PlB_80120C5C {
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
    virtual u8 m41();
};

struct T_80120C5C { s32 a; s32 b; s32 c; u16 d; u8 e; };

extern "C" {
u8 get_item_group__5TItemFv();
void request_model_load__14TItemEquipBaseFUc(void *, u8);
extern T_80120C5C lbl_8043E828[];
void TItemWeapon::request_equipped_model() {
    Pl_80120C5C *arg0 = (Pl_80120C5C *)this;
    u8 v = get_item_group__5TItemFv();
    if (v >= 0xAA) {
        T_80120C5C t;
        t.a = lbl_8043E828[0].a;
        t.b = lbl_8043E828[0].b;
        t.c = lbl_8043E828[0].c;
        t.d = lbl_8043E828[0].d;
        t.e = lbl_8043E828[0].e;
        v = ((u8 *)&t)[arg0->m41()];
    }
    request_model_load__14TItemEquipBaseFUc(arg0, v);
    ((TItemWeapon *)arg0)->create_weapon_trail_effects();
}

}
