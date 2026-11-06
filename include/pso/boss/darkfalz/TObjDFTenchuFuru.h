#ifndef PSO_BOSS_DARKFALZ_TOBJDFTENCHUFURU_H
#define PSO_BOSS_DARKFALZ_TOBJDFTENCHUFURU_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjDFTenchuFuru : public TObject {
public:
    u8 unk_1C[0x4];
    f32 m_20;
    u8 unk_24[0x4];
    s32 m_28;
 void* m_2c;
public:
    virtual ~TObjDFTenchuFuru();
    virtual void run_task();
public:
    void *create(void *arg1);
    static void capture_matrix_by_frame();
    static void register_callback();
    void transform_node_tree();
    void draw_node_tree();
};

#endif
