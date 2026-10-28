#ifndef PSO_TOBJITEMNAMESELECT_H
#define PSO_TOBJITEMNAMESELECT_H

#include "pso/TObject.h"
#include "types.h"

class TObjItemNameSelect : public TObject {
public:
    void *m_1c;
    void *m_20;

    TObjItemNameSelect(TObject *parent);
    // never defined; keeps the vtable hand-written in TQuestThread.cpp from being emitted
    virtual void render();
    virtual ~TObjItemNameSelect();

    static void *create(void *parent);
    static void set_selection_index(int index);
    static s32 get_selected_value();
    static char *get_selected_name();
    s32 get_result();
};

#endif
