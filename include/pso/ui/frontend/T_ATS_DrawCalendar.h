#ifndef PSO_UI_FRONTEND_T_ATS_DRAWCALENDAR_H
#define PSO_UI_FRONTEND_T_ATS_DRAWCALENDAR_H
#include "types.h"
#include "pso/system/task/TObject.h"

class T_ATS_DrawCalendar : public TObject {
public:
    virtual ~T_ATS_DrawCalendar();
    void *init_object(void *);
    virtual void render();
    u8 unk_1C[0xC];
};
typedef char T_ATS_DrawCalendar_size[sizeof(T_ATS_DrawCalendar) == 0x28 ? 1 : -1];

#endif
