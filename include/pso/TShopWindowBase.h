#ifndef PSO_TSHOPWINDOWBASE_H
#define PSO_TSHOPWINDOWBASE_H
#include "pso/TObject.h"
#include "types.h"

class TShopWindowBase : public TObject {
public:
    virtual ~TShopWindowBase();
    virtual void vfunc_6();
    virtual void display_message(const char *text, s32 flags);
    virtual void vfunc_8();
    virtual void display_guild_message(s32 index, s32 flags);
    virtual int vfunc_10();
    virtual void vfunc_11();
    void set_field_20(s32);
    bool sub_80223A48();
    u16 sub_8022397C();
    virtual void run_task();
public:
    static f32 get_scale();
public:
    void confirm_and_close_if_valid();
};

#endif
