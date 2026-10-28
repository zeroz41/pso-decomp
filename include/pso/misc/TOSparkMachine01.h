#ifndef PSO_MISC_TOSPARKMACHINE01_H
#define PSO_MISC_TOSPARKMACHINE01_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TOSparkMachine01 : public TObjBase {
    virtual ~TOSparkMachine01();
    u8 unk_90[0x10];
    u8 m_a0;
    u8 _padA1[0x1];
    u8 m_a2;
    u8 m_a3;
    void update_spark_toggle(s32 i);
    virtual void run_task();
    virtual void render();
    void *create();
    static void destroy_static_instance();
    static void load_static_resource();
    u8 unk_A4[0xC];
};

typedef char TOSparkMachine01_size[sizeof(TOSparkMachine01) == 0xB0 ? 1 : -1];

extern "C" {
void *TOSparkMachine01__ct(void *arg0, void *arg1);
void *__dt__16TOSparkMachine01Fv(void *arg0, s16 arg1);
}

#endif
