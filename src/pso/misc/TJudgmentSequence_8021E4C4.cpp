#include "types.h"
#include "pso/misc/TJudgmentSequence_8021E4C4.h"
#include "pso/misc/TShopGetItemWindow.h"
#include "pso/misc/TJudgmentSequence.h"

struct Base_8021E524_8021E4C4 { char pad[0x18]; };
struct VObj_8021E524_8021E4C4 : Base_8021E524_8021E4C4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};
struct Base_8021E55C_8021E4C4 { char pad[0x18]; };
struct VObj_8021E55C_8021E4C4 : Base_8021E55C_8021E4C4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};

extern "C" {

void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TJudgmentSequence::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x34);
    if (o != NULL) {
        o = TJudgmentSequence__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}
}

    extern int TJudgmentSequence__slot_flags[];
int get_judgment_shop_slot_flags(int a0) {  return TJudgmentSequence__slot_flags[a0]; }

void TShopGetItemWindow::display_message(const char *text, s32 flags) {
    struct VObj_8021E524_8021E4C4 *o = (struct VObj_8021E524_8021E4C4 *)this->m_5c;
    if (o != NULL) {
        o->m5();
    }
}

void TShopGetItemWindow::vfunc_6() {
    struct VObj_8021E55C_8021E4C4 *o = (struct VObj_8021E55C_8021E4C4 *)this->m_5c;
    if (o != NULL) {
        o->m4();
    }
}
