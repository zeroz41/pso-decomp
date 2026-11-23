#ifndef PSO_UI_HUD_TOBJRADERICON_H
#define PSO_UI_HUD_TOBJRADERICON_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjRaderIcon : public TObjBase {
    TObjRaderIcon(TObject *parent, void *arg2);
    virtual ~TObjRaderIcon();
    u32 m_90;
    u32 m_94;
    u32 m_98;
    u8 _pad9C[0x4];
    u32 m_a0;
    virtual void render();
    virtual void run_task();
    void initialize_from_placement();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjRaderIcon_size, sizeof(TObjRaderIcon) == 0xA4);

extern "C" {
void *__dt__13TObjRaderIconFv(void *arg0, s16 arg1);
}


#endif
