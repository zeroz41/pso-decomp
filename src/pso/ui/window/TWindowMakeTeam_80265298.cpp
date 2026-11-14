#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMakeTeam_80265298.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowMakeTeam_8026534C.h"
#include "pso/system/task/TObject.h"

extern "C" {

void mem_free(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

extern s32 __vt__15TWindowMakeTeam[];

void *__dt__15TWindowMakeTeamFv(TWindowMakeTeam *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TWindowMakeTeam;
        mem_free(*(void **)((s8 *)arg0 + 0x28));
        mem_free(*(void **)((s8 *)arg0 + 0x24));
        if (*(void **)((s8 *)arg0 + 0x34) != NULL) { ((TObject *)(*(void **)((s8 *)arg0 + 0x34)))->queue_destruction(); arg0->m_34 = 0; }
        if (*(void **)((s8 *)arg0 + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x30)))->close(); arg0->m_30 = 0; }
        if (*(void **)((s8 *)arg0 + 0x2C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x2C)))->close(); arg0->m_2c = 0; }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

extern "C" {

s32 init_status_disp__15TWindowMakeTeamFc(u8);
s32 draw_entry_0x110__15TWindowMakeTeamFSc(u8);
s32 create_menu__15TWindowMakeTeamFv(struct TWMT *);
s32 __ct__7TObjectFP7TObject();

struct TWMT;
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
