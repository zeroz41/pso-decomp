#ifndef PSO_UI_HUD_TLOCKONCURSOR_H
#define PSO_UI_HUD_TLOCKONCURSOR_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TLockOnCursor : public TObject {
    virtual ~TLockOnCursor();
    u16 get_target_id();
    void sub_8013EEC0(s16);
    virtual void render();
    void renderSecondaryCursor(u8* body, s32 type, s32 action);
    u32 m_1c;
    u8 _pad20[0x4];
    void* m_24;
    u8 _pad28[0x14];
    void* m_3c;
    u8 _pad40[0x8];
    void* m_48;
    u8 _pad4C[0x10];
    void* m_5c;
    u8 _pad60[0x48C];
    void* m_4ec;
    u8 _pad4F0[0x18];
    void* m_508;
    u8 _pad50C[0x4];
    void* m_510;
    u8 _pad514[0xC];
    void* m_520;
    static s32 free_if_owned(s32 arg0, s16 arg1);
    virtual void run_task();
    static void free_cursor_resources();
    int render_part();
    void update_cursor_pos();
    int set_flag_8_bit0();
    int update_ring();
    int is_bit1_set();
    int is_inactive();
    int update_ring_sub();
    int test_flag_1_at_8();
    s32 get_target();
    s32 release_target();
    s32 cleanup_field();
    s32 cleanup_field_3c();
    void reset_state();
    void *destroy(s16 arg1);
    void *init_vtable();
    void*init_cursor();
    void*init_forward();
    void*cleanup();
    void reset_fields();
    u8 unk_524[0x8];
    static s32 dt(s32 arg0, s16 arg1);
    void reset_and_spawn_cursors();
};

typedef char TLockOnCursor_size[sizeof(TLockOnCursor) == 0x52C ? 1 : -1];
#endif
