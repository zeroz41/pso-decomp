#include "types.h"
#include "pso/ui/window/TWindowMakeTeam_8026534C.h"
#include "pso/ui/window/TWindowMakeTeam.h"

extern "C" {

s32 init_status_disp__15TWindowMakeTeamFc(u8);
s32 draw_entry_0x110__15TWindowMakeTeamFSc(u8);
s32 create_menu__15TWindowMakeTeamFv(struct TWMT *);
s32 __ct__7TObjectFP7TObject();

struct TWMT;
extern void* __vt__15TWindowMakeTeam[];
extern s32 TWindowMakeTeam__name;

void *TWindowMakeTeam__ct(void *arg0, void *arg1, s32 arg2) {
    s32 temp_r0;
    s32 v;
    register struct TWMT *self;

    __ct__7TObjectFP7TObject();
    self = (struct TWMT *) arg0;
    *(void **)((s8 *)self + 0x18) = (void *) __vt__15TWindowMakeTeam;
    v = TWindowMakeTeam__name;
    *(s32 *)((s8 *)self + 0) = v;
    ((TWindowMakeTeam *)self)->m_1c = 0;
    ((TWindowMakeTeam *)self)->m_1d = 0;
    ((TWindowMakeTeam *)self)->m_20 = arg2;
    ((TWindowMakeTeam *)self)->m_2c = create_menu__15TWindowMakeTeamFv(self);
    ((TWindowMakeTeam *)self)->m_30 = 0;
    ((TWindowMakeTeam *)self)->m_34 = 0;
    ((TWindowMakeTeam *)self)->m_24 = 0;
    ((TWindowMakeTeam *)self)->m_28 = 0;
    ((TWindowMakeTeam *)self)->m_1e = 0U;
    ((TWindowMakeTeam *)self)->m_1f = 0U;
    temp_r0 = ((TWindowMakeTeam *)self)->m_20;
    if ((temp_r0 == 1) || (temp_r0 == 2)) {
        ((TWindowMakeTeam *)(((TWindowMakeTeam *)self)->m_2c))->set_entry_string_by_id((void *)(draw_entry_0x110__15TWindowMakeTeamFSc(((TWindowMakeTeam *)self)->m_1e)), 2);
    }
    ((TWindowMakeTeam *)(((TWindowMakeTeam *)self)->m_2c))->set_entry_string_by_id((void *)(init_status_disp__15TWindowMakeTeamFc(((TWindowMakeTeam *)self)->m_1f)), 3);
    return arg0;
}

}
