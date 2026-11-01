#include "types.h"
#include "pso/TObject.h"
#include "pso/misc/TFogCtrl_EOR.h"
#include "pso/misc/TQuestVmDownLoadServer_800FA8A4.h"

#include "pso/misc/TFogCtrl.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"

struct RecoveredGlobal_800FA95C_lbl_8049C700 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void *__nw__7TObjectFUl(int);
extern u32 fog_ctrl_instance;
s32 request_fog__8TFogCtrlFPvii(u8 *arg0, s32 arg1, s32 arg2);
extern s32 TFogCtrl__fog_instance_table[];
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__12TFogCtrl_EOR[];
extern s32 lbl_805D2B1C;
s32 TFogCtrl__sub_800FAC84(void *p);
void queue_destruction__7TObjectFv(void *arg0);
int update_all__8TFogCtrlFv(void*);

s32 TQuestVmDownLoadServer::get_serial_access() { return TAdEnterSerialAccessGC::parse_serial_value(); }
s32 TQuestVmDownLoadServer::poll_serial_access() { return TAdEnterSerialAccessGC::parse_serial_value(); }
void TFogCtrl_EOR::run_task() { update_all__8TFogCtrlFv(this); }

}
TFogCtrl_EOR::~TFogCtrl_EOR() {

}


typedef char RecoveredGlobal_800FA95C_lbl_8049C700_size[sizeof(RecoveredGlobal_800FA95C_lbl_8049C700) == 0x18 ? 1 : -1];
u8 *TFogCtrl_EOR::init_object() {
    u8 *arg0 = (u8 *)this;
    __ct__7TObjectFP7TObject(arg0, &end_of_render_root);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_800FA95C_lbl_8049C700 *)&__vt__12TFogCtrl_EOR).value;
    *(s32 *)&this->m_name = (s32) lbl_805D2B1C;
    return arg0;
}

void TQuestVmDownLoadServer::destroy_instance() {
    if ((u32) fog_ctrl_instance != 0U) {
        queue_destruction__7TObjectFv((void *)fog_ctrl_instance);
    }
    fog_ctrl_instance = 0U;
}
void TFogCtrl::create_instance() {
    void *o;
    o = __nw__7TObjectFUl(0x1C);
    if (o != NULL) {
        o = ((TFogCtrl_EOR *)o)->init_object();
    }
    (*(void * *)&fog_ctrl_instance) = o;
}
s32 TFogCtrl::update_all(s32 arg0, s32 arg1) {
    s32 var_r29 = 0;
    s32 *var_r30 = TFogCtrl__fog_instance_table;
    s32 var_r31 = 0;
    do {
        u32 v = (u32)var_r30[var_r31];
        if (v != 0U) {
            request_fog__8TFogCtrlFPvii((u8 *)v, arg0, arg1);
        }
        var_r29 += 1;
        var_r31 += 1;
    } while (var_r29 != 4);
    return 1;
}
s32 TFogCtrl::apply_all(s32 arg0, s32 arg1) {
    s32 var_r29 = 0;
    s32 *var_r30 = TFogCtrl__fog_instance_table;
    s32 var_r31 = 0;
    do {
        u32 v = (u32)var_r30[var_r31];
        if (v != 0U) {
            ((TFogCtrl *)v)->select_fog(arg0, arg1);
        }
        var_r29 += 1;
        var_r31 += 1;
    } while (var_r29 != 4);
    return 1;
}

s32 TFogCtrl::update_first_active_fog() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if ((void *)((s32 *)&TFogCtrl__fog_instance_table)[i] != NULL) {
            return TFogCtrl__sub_800FAC84((void *)((s32 *)&TFogCtrl__fog_instance_table)[i]);
        }
    }
    return 0;
}

s32 TFogCtrl::update_all(s32 arg0) {
    s32 var_r29;
    s32 var_r31;
    s32 temp_r3;
    var_r29 = 0;
    var_r31 = 0;
    do {
        temp_r3 = *(TFogCtrl__fog_instance_table + var_r31);
        if ((u32) temp_r3 != 0U) {
            ((TFogCtrl *)temp_r3)->restore_fog(arg0);
        }
        var_r29 += 1;
        var_r31 += 1;
    } while (var_r29 != 4);
    return 1;
}

