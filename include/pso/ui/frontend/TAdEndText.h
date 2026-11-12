#ifndef PSO_UI_FRONTEND_TADENDTEXT_H
#define PSO_UI_FRONTEND_TADENDTEXT_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdEndText : public TObject {
public:
    virtual ~TAdEndText();
    virtual void render();
    virtual void run_task();
public:
    static void free_resources();
    static void load_ending_font();
public:
    static void cleanup();
};

extern "C" {
s32 TAdEndText__sub_8001B3BC(u8 arg0);
s32 TAdEndText__sub_8001B3D4(u8 arg0);
s32 TAdEndText__sub_8001B3EC(u8 arg0);
s32 TAdEndText__sub_8001B404(u8 arg0);
s32 TAdEndText__sub_8001B41C(void);
u8 *__ct__10TAdEndTextFv(u8 *arg0, TObject *parent);
s32 get_end_text_font_loaded_flag(void);
s32 get_ending_scene_active(void);
void render__10TAdEndTextFv(u8 *arg0);
void run_task__10TAdEndTextFv(u8 *arg0);
}

#endif
