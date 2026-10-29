#ifndef PSO_OBJECT_CURSORACTION_H
#define PSO_OBJECT_CURSORACTION_H

#include "types.h"

// What the action button does on an object the cursor targets.
enum {
    CURSOR_ACTION_NONE = 0,
    CURSOR_ACTION_TALK = 1,      // quest consoles and monuments (TUnk_804B27D8)
    CURSOR_ACTION_USE = 3,       // keys, consoles, monuments
    CURSOR_ACTION_PICK_UP = 4,   // items
    CURSOR_ACTION_TELEPIPE = 6,
};

struct CursorAction {
    s32 kind;  // CURSOR_ACTION_*

    CursorAction();
    void set_talk();
    void set_use();
    void set_pick_up();
    void set_telepipe();
    s32 get();
};

#endif
