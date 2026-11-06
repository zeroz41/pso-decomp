#ifndef PSO_UI_CITY_TMEDICALCENTERMES_H
#define PSO_UI_CITY_TMEDICALCENTERMES_H

#include "pso/system/task/TObject.h"
#include "pso/ui/window/TMessageWindowController.h"
#include "types.h"

struct TObjPlayer;

class TMedicalCenterMes : public TObject, public TMessageWindowController {
public:
    TObjPlayer *player;
    s32 state;

    TMedicalCenterMes(TObject *parent, TObjPlayer *player);
    virtual ~TMedicalCenterMes();
    virtual void run_task();

    static s32 get_slot_flag(int client);
    static void clear_slot_flags();
};
typedef char TMedicalCenterMes_size_check[sizeof(TMedicalCenterMes) == 0x234 ? 1 : -1];

#endif
