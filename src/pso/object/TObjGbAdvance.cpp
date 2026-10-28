#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjComputer.h"
#include "pso/object/TObjGbAdvance.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjMesBase.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80187F78_lbl_804B6280 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80187F78___vt__13TObjGbAdvance {
    s32 value;
    u8 remaining[0x40];
};

extern "C" {
u32 init_collision_body_parts(void *, s32, s32);
u8 * TObjMesBase__ct(void *, s32);
extern RecoveredGlobal_80187F78_lbl_804B6280 gb_advance_collision_body_parts;
extern s32 __vt__13TObjGbAdvance[];
extern s32 lbl_805D32D0;
u8 *TObjGbAdvance__ct(u8 *arg0, s32 arg1);
s32 get_bml_model(void *, s32);
void debug_printf_at(s32 id, const char *fmt, ...);
extern char lbl_80444B48[];
extern u32 TObjComputer__model_archive;
extern s16 TObjComputer__data_805DBCD8[2];
void *__dt__13TObjGbAdvanceFv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 vfunc_14__11TObjMesBaseFv();
s32 submit_cursor_candidate(void *, s32);
s32 __dl__7TObjectFPv(void *);
void *__dt__11TObjMesBaseFv(void *arg0, s16 arg1);

void TObjGbAdvance::vfunc_14() {
    vfunc_14__11TObjMesBaseFv();
    if ((s32) this->messageLabel != 0) {
        submit_cursor_candidate(this, -1);
    }
}

void *__dt__13TObjGbAdvanceFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TObjGbAdvance;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__11TObjMesBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80187F78_lbl_804B6280_size[sizeof(RecoveredGlobal_80187F78_lbl_804B6280) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80187F78___vt__13TObjGbAdvance_size[sizeof(RecoveredGlobal_80187F78___vt__13TObjGbAdvance) == 0x44 ? 1 : -1];
u8 *TObjGbAdvance__ct(u8 *arg0, s32 arg1) {
    TObjMesBase__ct(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80187F78___vt__13TObjGbAdvance *)&__vt__13TObjGbAdvance).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D32D0;
    init_collision_body_parts(arg0, (s32) &gb_advance_collision_body_parts.value, 1);
    ((TObjGbAdvance *)arg0)->actorFlags = (s32) (((TObjGbAdvance *)arg0)->actorFlags | 0x40000000);
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TObjGbAdvance *)arg0)->cursor_action.set_use();
    return arg0;
}
void TObjComputer::debug_draw_label() {
    this->TObjMesBase::debug_draw_label();
    *(s32 *)&this->set_params[1] = *(s32 *)&this->set_params[1] % 2;
    *(s32 *)&this->m_bc = get_bml_model((void *)TObjComputer__model_archive, TObjComputer__data_805DBCD8[*(s32 *)&this->set_params[1]]);
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130021, lbl_80444B48);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

}
