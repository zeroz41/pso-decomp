#include "types.h"
#include "pso/enemy/TNeedleShoot_802A4668.h"
#include "pso/system/vector.h"
#include "pso/enemy/TNeedleShoot.h"

struct Base_802A4668 { char pad[0x18]; };
struct VObj_802A4668 : Base_802A4668 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};

extern "C" {
s32 check_wall_hit__12TNeedleShootFv(void *, f32, f32);

void TNeedleShoot__sub_802A4668(void *arg0) {
    struct VObj_802A4668 *o = (struct VObj_802A4668 *)arg0;
    o->m5();
}
#pragma push
#pragma fp_contract on
void TNeedleShoot::update_position() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f2;
    VecCopy((Vec *)(arg0 + 0x28), (const Vec *)(arg0 + 0x6C));
    *(f32 *)&this->m_6c = (f32) ((*(f32 *)&this->m_94 * *(f32 *)&this->_padAC) + *(f32 *)&this->m_6c);
    *(f32 *)&this->unk_70 = (f32) ((*(f32 *)&this->unk_98 * *(f32 *)&this->_padAC) + *(f32 *)&this->unk_70);
    temp_f2 = this->m_9c;
    temp_f1 = *(f32 *)&this->_padAC;
    this->m_74 = (f32) ((temp_f2 * temp_f1) + this->m_74);
    check_wall_hit__12TNeedleShootFv(arg0, temp_f1, temp_f2);
}
#pragma pop

}
