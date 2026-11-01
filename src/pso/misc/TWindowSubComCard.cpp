#include "types.h"
#include "pso/misc/TQuestListOnline.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct Base_8021845C_802183B4 { char pad[0x18]; };
struct VObj_8021845C_802183B4 : Base_8021845C_802183B4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
};
struct Base_802184C8_802183B4 { char pad[0x18]; };
struct VObj_802184C8_802183B4 : Base_802184C8_802183B4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};
struct Base_80218500_802183B4 { char pad[0x18]; };
struct VObj_80218500_802183B4 : Base_80218500_802183B4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};
struct Base_80218538_802183B4 { char pad[0x18]; };
struct VObj_80218538_802183B4 : Base_80218538_802183B4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};

extern "C" {

s32 sub_80223A48__15TShopWindowBaseFv(void *);
u32 get_serial_access__22TQuestVmDownLoadServerFv();
s32 poll_serial_access__22TQuestVmDownLoadServerFv();

}
s32 TQuestListOnline::get_selection_stage() { return selection_stage; }

void TWindowSubComCard::clear_flag_and_release() {
    u32 temp;
    *(u16 *)((s8 *)this + 0x70) = (u16) (*(u16 *)((s8 *)this + 0x70) & 0xFFFFFFFD);
    temp = (u32) *(u32 *)((s8 *)this + 0x88);
    if (temp != 0U) {
        ((TWindowSubStatusDisp *)temp)->set_entry_state(1);
    }
}
void TQuestListVM::set_selected_entry(void* a1) { set_field_20((s32)((void*)20)); *(void* *)&this->m_23b4 = a1; }
void TQuestListVM::poll_download() {
    if (get_serial_access__22TQuestVmDownLoadServerFv() == 0U) {
        poll_serial_access__22TQuestVmDownLoadServerFv();
    }
}

int TQuestListVM::vfunc_10() {
    void *temp_r3;

    temp_r3 = *(void * *)&this->m_23a0;
    if (temp_r3 != NULL) {
        if (((VObj_8021845C_802183B4 *)temp_r3)->m8() == 0) {
            return 0;
        }
        return sub_80223A48__15TShopWindowBaseFv(this) ? 1 : 0;
    }
    return 1;
}

void TQuestListVM::display_guild_message(s32 index, s32 flags) {
    struct VObj_802184C8_802183B4 *o = (struct VObj_802184C8_802183B4 *)this->m_23a0;
    if (o != NULL) {
        o->m7();
    }
}

void TQuestListVM::display_message(const char *text, s32 flags) {
    struct VObj_80218500_802183B4 *o = (struct VObj_80218500_802183B4 *)this->m_23a0;
    if (o != NULL) {
        o->m5();
    }
}

void TQuestListVM::vfunc_6() {
    struct VObj_80218538_802183B4 *o = (struct VObj_80218538_802183B4 *)this->m_23a0;
    if (o != NULL) {
        o->m4();
    }
}
