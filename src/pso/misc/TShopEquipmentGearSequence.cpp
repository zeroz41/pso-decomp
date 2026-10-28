#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TShopEquipmentGearSequence.h"
#include "pso/TShopWindowBase.h"
#include "pso/quest/TQuestListVM.h"

struct Base_8021B2E8 { char pad[0x18]; };
struct VObj_8021B2E8 : Base_8021B2E8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int a, int b);
};
struct Base_8021B338 { char pad[0x18]; };
struct VObj_8021B338 : Base_8021B338 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32  m8();
};
extern "C" {

s32 close_if_single_screen__13TShopSequenceFv(void *);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
s32 close_window__13TShopSequenceFv(void *);

extern s32 lbl_805D6218;
extern s32 lbl_805D621C;

struct Base_8021B288 { char pad[0x18]; };
struct VObj_8021B288 : Base_8021B288 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int, int);
};

void TShopEquipmentGearSequence::open_gear_shop() {
    if (this != NULL) {
        ((struct VObj_8021B288 *)this)->m4(0x1B, 1);
        this->set_field_20(7);
        lbl_805D6218 = 0x1A;
        lbl_805D621C = 2;
    }
}

void TShopEquipmentGearSequence::enter_quest_list() {
    struct VObj_8021B2E8 *o = (struct VObj_8021B2E8 *)this;
    if (o != NULL) {
        o->m4(0x1A, 1);
        this->set_field_20(2);
    }
}

void TShopEquipmentGearSequence::handle_confirm() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((VObj_8021B338*)this)->m4(lbl_805D6218, 1);
        this->set_field_20(lbl_805D621C);
    }
}

void TShopEquipmentGearSequence::try_close() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        close_if_single_screen__13TShopSequenceFv(this);
        close_window__13TShopSequenceFv(this);
        queue_destruction__7TObjectFv(this);
    }
}

}
