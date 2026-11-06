#ifndef PSO_UI_CITY_TSHOPWINDOWBASE_H
#define PSO_UI_CITY_TSHOPWINDOWBASE_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TShopWindowBase : public TObject {
public:
    TShopWindowBase(TObject *parent);
    virtual ~TShopWindowBase();
    virtual void vfunc_6();
    virtual void display_message(const char *text, s32 flags);
    virtual void vfunc_8();
    virtual void display_guild_message(s32 index, s32 flags);
    virtual int vfunc_10();
    virtual void vfunc_11();
    void set_field_20(s32);
    s32 sub_80223A48();
    u16 sub_8022397C();
    virtual void run_task();
public:
    f32 get_scale();
public:
    void confirm_and_close_if_valid();
};

// The derived windows' constructors are still C functions and call these by symbol.
extern "C" {
void *__ct__15TShopWindowBaseFP7TObject(void *self, TObject *parent);
void *__dt__15TShopWindowBaseFv(void *self, s16 flag);
}

#endif
