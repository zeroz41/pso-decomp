#ifndef PSO_OBJECT_TOBJLUKER_H
#define PSO_OBJECT_TOBJLUKER_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjLuker : public TObjBase {
    virtual ~TObjLuker();
    u8 unk_90[0x10];
    u32 m_a0;
    u32 m_a4;
    u16 m_a8;
    u16 m_aa;
    s16 m_ac;
    u16 m_ae;
    s16 m_b0;
    u8 _padB2[0x2];
    u32 m_b4;
    u32 m_b8;
    void show_part(s32 arg1);
    void update_floor_name_windows();
    void open_destination_windows();
    void transfer_to_town();
    virtual void render();
    virtual void run_task();
    static int get_stat_table_entry(int a0);
};

typedef char TObjLuker_size[sizeof(TObjLuker) == 0xBC ? 1 : -1];
#endif
