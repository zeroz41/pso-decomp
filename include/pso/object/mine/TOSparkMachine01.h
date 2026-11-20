#ifndef PSO_OBJECT_MINE_TOSPARKMACHINE01_H
#define PSO_OBJECT_MINE_TOSPARKMACHINE01_H

#include <stddef.h>
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOSparkMachine01 : public TObjBase {
    virtual ~TOSparkMachine01();
    f32 spark_timer[4];
    u8 spark_on[4];
    f32 spark_speed;
    f32 view_range;
    f32 model_radius;
    void update_spark_toggle(s32 i);
    virtual void run_task();
    virtual void render();
    void *create();
    static void destroy_static_instance();
    static void load_static_resource();
};

typedef char TOSparkMachine01SparkTimersOffset[offsetof(TOSparkMachine01, spark_timer) == 0x90 ? 1 : -1];
typedef char TOSparkMachine01_size[sizeof(TOSparkMachine01) == 0xB0 ? 1 : -1];

extern "C" {
void *TOSparkMachine01__ct(void *arg0, void *arg1);
void *__dt__16TOSparkMachine01Fv(void *arg0, s16 arg1);
}

#endif
