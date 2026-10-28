#include "types.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListVM.h"

extern "C" {

struct Base_802126C4 { char pad[0x18]; };
struct VObj_802126C4 : Base_802126C4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(int, int);
};
extern VObj_802126C4 *THunterGuildSeqOffline__active_instance;

void THunterGuildSeqOffline::notify_close() {
    if (THunterGuildSeqOffline__active_instance != NULL) {
        THunterGuildSeqOffline__active_instance->m7(0x19, 1);
        ((TShopWindowBase *)THunterGuildSeqOffline__active_instance)->set_field_20(4);
    }
}

struct G_80212710 { u8 pad[0x24]; s32 f24; };
u8 *TQuestListVM__ct(TQuestListVM *, s32, s32, s32);
u8 *__nw__7TObjectFUl(u32);
struct Q_80212710 { u8 pad[0x23B8]; void *cb0; void *cb1; void *cb2; };
extern s32 tl_05;
void THunterGuildSeqOffline::create_quest_list_vm() {
    Q_80212710 *p = (Q_80212710 *)__nw__7TObjectFUl(0x23C4);
    if (p != 0) {
        p = (Q_80212710 *)TQuestListVM__ct((TQuestListVM *)((u8 *)p), tl_05, (s32)THunterGuildSeqOffline__active_instance, ((G_80212710 *)THunterGuildSeqOffline__active_instance)->f24);
    }
    if (p != 0) {
        p->cb0 = (void *)THunterGuildSeqOffline::notify_close;
        p->cb1 = (void *)THunterGuildSeqOffline::init_quest_list;
        p->cb2 = (void *)THunterGuildSeqOffline::set_state_3;
    }
}

}
