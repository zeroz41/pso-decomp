#include "types.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/quest/TQuestListVM.h"

struct Base_8021277C { char pad[0x18]; };
struct VObj_8021277C : Base_8021277C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(int, int);
};

extern struct VObj_8021277C *THunterGuildSeqOffline__active_instance;

void THunterGuildSeqOffline::set_state_close2() {
    if (THunterGuildSeqOffline__active_instance != NULL) {
        THunterGuildSeqOffline__active_instance->m7(0xC, 1);
        *(s32 *)((s8 *)THunterGuildSeqOffline__active_instance + 0x38) = 0;
        ((TShopWindowBase *)THunterGuildSeqOffline__active_instance)->set_field_20(5);
    }
}

    extern int evt2_random_enemies_mode;
void THunterGuildSeqOffline::set_enemy_mode_5() { TLobby::set_enemy_mode_flag(); evt2_random_enemies_mode = 5; TKeyBoardControl__sub_8000F950(); }

void THunterGuildSeqOffline::set_enemy_mode_1() { TLobby::set_enemy_mode_flag(); evt2_random_enemies_mode = 1; TKeyBoardControl__sub_8000F950(); }
