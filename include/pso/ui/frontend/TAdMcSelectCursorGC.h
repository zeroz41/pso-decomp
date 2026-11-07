#ifndef PSO_UI_FRONTEND_TADMCSELECTCURSORGC_H
#define PSO_UI_FRONTEND_TADMCSELECTCURSORGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdMcSelectCursorGC : public TObject {
    virtual ~TAdMcSelectCursorGC();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u8 _pad28[0x100];
    u32 m_128;
    u32 m_12c;
    u8 _pad130[0x4];
    u32 m_134;
    u32 m_138;
    u32 m_13c;
    void render_cursor();
    virtual void render();
    virtual void run_task();
    static u32 get_instance(s32 arg0);
    static void release_cursor_entry();
    static void init_resource();
    static int get_cursor_type(int a0);
    void sub_8032A140(); // clears m_1c; defined in TAdMcSelectGC.cpp
    void sub_8032A15C(); // sets m_1c to 1; defined in TAdMcSelectGC.cpp
    s32 sub_8032AAC4(); // returns m_20, the selected slot; defined in TAdMcSelectMcGC.cpp, its only caller
};

typedef char TAdMcSelectCursorGC_size[sizeof(TAdMcSelectCursorGC) == 0x140 ? 1 : -1];

extern "C" {
void *__dt__19TAdMcSelectCursorGCFv(void *arg0, s16 arg1);
}

#endif
