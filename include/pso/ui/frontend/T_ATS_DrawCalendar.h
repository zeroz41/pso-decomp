#ifndef PSO_UI_FRONTEND_T_ATS_DRAWCALENDAR_H
#define PSO_UI_FRONTEND_T_ATS_DRAWCALENDAR_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct T_ATS_DrawCalendarPos {
    f32 x;
    f32 y;
};

// Date and clock text drawn by TAdTimeSetGC while it asks whether the clock is right.
class T_ATS_DrawCalendar : public TObject {
public:
    T_ATS_DrawCalendar(TObject *parent);
    virtual ~T_ATS_DrawCalendar();
    virtual void render();

    static T_ATS_DrawCalendar *create();
    void sub_802E11BC();
    void sub_802E11C8();

    s32 visible;                // 0x1C: render() draws only while this is set
    T_ATS_DrawCalendarPos pos;  // 0x20: centre of the first text line
};
typedef char T_ATS_DrawCalendar_size[sizeof(T_ATS_DrawCalendar) == 0x28 ? 1 : -1];

#endif
