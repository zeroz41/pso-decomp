#include "types.h"
#include "pso/ui/window/TWindowSubTechnique.h"

struct Base_80286B0C { char pad[0x18]; };
struct VObj_80286B0C : Base_80286B0C {
    virtual void v0();
#define VV(n) virtual void v##n();
VV(1)VV(2)VV(3)VV(4)VV(5)VV(6)VV(7)VV(8)VV(9)VV(10)
VV(11)VV(12)VV(13)VV(14)VV(15)VV(16)VV(17)VV(18)VV(19)VV(20)
VV(21)VV(22)VV(23)VV(24)VV(25)VV(26)VV(27)VV(28)VV(29)VV(30)
VV(31)VV(32)VV(33)
#undef VV
    virtual s32 v36();
};

extern "C" {

void *get_player_by_client_id(s32);

void TWindowSubTechnique::get_selection(s16 *arg0, s32 *arg1, s32 arg2) {
    void *player;

    player = get_player_by_client_id(arg2);
    if (player != NULL) {
        *arg0 = *(s16 *)((s8 *)player + 0x32E);
        *arg1 = ((VObj_80286B0C *)player)->v36();
    }
}

}
