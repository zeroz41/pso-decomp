#ifndef PSO_ITEM_TOBJITEMOKWINDOW_H
#define PSO_ITEM_TOBJITEMOKWINDOW_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMenu;

class TObjItemOKWindow : public TObject {
public:
    char m_text[0x40];
    TWindowMenu *name_menu;       // shows the entered item name
    TWindowMenu *confirm_menu;    // the yes/no choice get_result reads
    void *message_window;

    TObjItemOKWindow(TObject *parent);
    virtual ~TObjItemOKWindow();

    static TObjItemOKWindow *create(void *parent);
    s32 get_result();
    s32 is_done();
};

#endif
