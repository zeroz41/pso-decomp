#ifndef PSO_UI_FRONTEND_TADPLYCHRSELPLATEGC_H
#define PSO_UI_FRONTEND_TADPLYCHRSELPLATEGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdPlyChrSelPlateGC : public TObject {
public:
    virtual ~TAdPlyChrSelPlateGC();
    virtual void run_task();
    virtual void render();
public:
    bool is_slot_value_ready(s32 i);
    void reset_selection_slots();
    void push_plate_position();
};

#endif
