#ifndef PSO_TOBJITEMOKWINDOW_H
#define PSO_TOBJITEMOKWINDOW_H

#include "pso/TObject.h"
#include "types.h"

class TObjItemOKWindow : public TObject {
public:
    char m_text[0x40];
    void *m_5c;
    void *m_60;
    void *m_64;

    TObjItemOKWindow(TObject *parent);
    // never defined; keeps the vtable hand-written in TQuestThread.cpp from being emitted
    virtual void render();
    virtual ~TObjItemOKWindow();

    static void *create(void *parent);
    s32 get_result();
    s32 is_done();
};

#endif
