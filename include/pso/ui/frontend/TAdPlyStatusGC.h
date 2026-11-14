#ifndef PSO_UI_FRONTEND_TADPLYSTATUSGC_H
#define PSO_UI_FRONTEND_TADPLYSTATUSGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TWindowBase;

struct TAdPlyStatusGC : public TObject {
    virtual ~TAdPlyStatusGC();
    virtual void render();
    virtual void run_task();
    u32 state; // inferred: indexes run_task's close/shown/hidden handler table
    u32 prev_state;
    u32 m_24;
    u8 _pad28[0x10];
    u32 m_38;
    u32 m_3c;
    u32 m_40;
    u32 m_44;
    u32 m_48;
    u8 _pad4C[0x10];
    u32 m_5c;
    u32 m_60;
    u32 m_64;
    u32 m_68;
    TWindowBase *window;
    s32 get_field_498();
    void*get_chara_making_data();
    s32 get_field_49c();
    s32 get_field_4a0();
    void*get_status_data();
    s32 get_field_4a4();
    void*get_status_sub();
    static void set_status_param(int a0, int a1);
    static int get_index();
    static void set_status_index(int a0, int a1);
    void close_window(s32 arg1);
    void close_window();
    void update_shown();
    void update_hidden();
    static u32 get_instance(s32 arg0, s32 arg1);
    static int get_player_index();
};

typedef char TAdPlyStatusGC_size[sizeof(TAdPlyStatusGC) == 0x70 ? 1 : -1];
#endif
