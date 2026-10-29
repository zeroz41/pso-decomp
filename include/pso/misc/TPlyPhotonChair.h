#ifndef PSO_MISC_TPLYPHOTONCHAIR_H
#define PSO_MISC_TPLYPHOTONCHAIR_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TPlyPhotonChair : public TObjBase {
    virtual ~TPlyPhotonChair();
    u16 sub_8035B530();
    s8 get_actor_section_id();
    u8 unk_90[0x2];
    u16 m_92;
    u32 m_94;
    void* m_98;
    u32 m_9c;
    u8 _padA0[0x14];
    void* m_b4;
    u32 m_b8;
    u8 _padBC[0x14];
    void* m_d0;
    virtual void render();
    virtual void run_task();
    static void free_static_model();
    static s32 load_resources();
    void set_field90(s32 v);
    static void render(void* p, void* a1);
    void set_state_ready();
    void sync_field10_from_child();
    void set_field_8(s32 v);
    void set_type(s32 v);
    static void free_instance();
    static void play_sound_with_arg(void* p, void* a1);
    void play_sound();
    static void update_parts(void* p);
    static void update_parts2(void* p);
    static void restore_state(s32 _w0);
    static void copy_vec4_forward(s32 _w0);
    static void copy_vec4_reverse(s32 _w0);
    static void save_state(s32 _w0);
    int is_mounted();
    u8 unk_D4[0x10];
};

typedef char TPlyPhotonChair_size[sizeof(TPlyPhotonChair) == 0xE4 ? 1 : -1];
#endif
