#include "types.h"
#include "pso/misc/TOChatSensor.h"
#include "pso/misc/TOChatSensor.h"
#include "pso/misc/TLobby.h"

extern "C" {
s32 TOChatSensorFolder__ct(int, int);
u32 __nw__7TObjectFUl(int);
extern u32 TOChatSensorFolder__instance;
extern s32 tl_05;
u32 TOChatSensor__create(s32 arg0);
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 __vt__12TOChatSensor[];
extern s32 lbl_805D2ED8;
extern u32 chat_sensor_table;
u32 TOChatSensor__ct(int arg0, void *arg1, void *arg2);
void *__dt__12TOChatSensorFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

}
TOChatSensor::~TOChatSensor() {

}
extern "C" {

u32 TOChatSensor__ct(int arg0, void *parent, void *arg2) {
    s32 n;
    s32 *t;
    __ct__8TObjBaseFP7TObject((void *) arg0, parent);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOChatSensor;
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D2ED8;
    ((TOChatSensor *)arg0)->apply_object_set_data(arg2);
    ((TOChatSensor *)arg0)->m_c4 = 0;
    ((TOChatSensor *)arg0)->m_a0 = 0;
    ((TOChatSensor *)arg0)->init_params();
    n = ((TOChatSensor *)arg0)->m_cc;
    if (n > 0) {
        t = (s32 *) *(s32 *)((s8 *)chat_sensor_table + 4);
        t += n;
        ((TOChatSensor *)arg0)->set_trigger_text((void *)t[-1]);
    }
    return arg0;
}

void TOChatSensor::dispatch_chat_message_to_children(s32 arg0) {
    void *var_r31;
    if (TOChatSensorFolder__instance != 0U) {
        var_r31 = *(void **)((s8 *)TOChatSensorFolder__instance + 0x14);
        while (var_r31 != NULL) {
            ((TOChatSensor *)var_r31)->handle_chat_message((void *)arg0);
            var_r31 = *(void **)((s8 *)var_r31 + 0xC);
        }
    }
}

u32 TOChatSensor__create(s32 arg0) {
    u32 temp_r3;
    u32 temp_r3_2;
    u32 var_r0;
    if ((u32) TOChatSensorFolder__instance == 0U) {
        temp_r3 = __nw__7TObjectFUl(0x1C);
        if (temp_r3 != 0U) {
            TOChatSensorFolder__ct(temp_r3, tl_05);
        }
    }
    if ((u32) TOChatSensorFolder__instance != 0U) {
        temp_r3_2 = __nw__7TObjectFUl(0xD0);
        var_r0 = temp_r3_2;
        if (var_r0 != 0U) {
            var_r0 = TOChatSensor__ct((int)temp_r3_2, (void *)TOChatSensorFolder__instance, (void *)arg0);
        }
        return var_r0;
    }
    return 0U;
}

void TOChatSensor::destroy_global() {
    if ((u32) chat_sensor_table != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)chat_sensor_table));
        chat_sensor_table = 0U;
    }
}

}
