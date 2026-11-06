#include "types.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/object/container/TObjContainerIdo.h"

struct Base_8017E158_8017E154 { char pad[0x18]; };
struct VObj_8017E158_8017E154 : Base_8017E158_8017E154 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
};
struct Base_8017E184_8017E154 { char pad[0x18]; };
struct VObj_8017E184_8017E154 : Base_8017E184_8017E154 {
    virtual void g0();
    virtual void m0();  virtual void m1();  virtual void m2();
    virtual void m3();  virtual void m4();  virtual void m5();
    virtual void m6();
    virtual s32 m7(f32, f32);
    virtual void m8();  virtual void m9();  virtual void m10();
    virtual void m11();
    virtual void m12();
};

void TUnk_804B97C0::vfunc_14() {  }

void TUnk_804B97C0::run_task() {
    struct VObj_8017E158_8017E154 *o = (struct VObj_8017E158_8017E154 *)this;
    o->m12();
}

void TUnk_804B97C0::render() {
    struct VObj_8017E184_8017E154 *o = (struct VObj_8017E184_8017E154 *)this;
    if (o->m7(*(f32 *)&this->unk_AC, *(f32 *)&this->m_b0) != 0) {
        o->m12();
    }
}

void TUnk_804B97C0::vfunc_15() {  }
