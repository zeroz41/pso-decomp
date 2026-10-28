#include "pso/TItemReverseTechCtrl.h"
#include "pso/item/TItemReverseTech_8011A1E8.h"
#include "pso/misc/TKeyBoardControl.h"

struct ReverseTechCode {
    s8 *keys;
    s32 length;
    void (*activate)(void);
};

extern "C" {
extern const char *lbl_805D2C58;
extern ReverseTechCode lbl_804A0468[3];
}

void TItemReverseTechCtrl::run_task() {
    s32 letter;
    ReverseTechCode *code;
    s32 *progress;
    s32 key;
    s32 i;
    key = TKeyBoardControl::get_ascii_key();
    if (key >= 'a' && key <= 'z') {
        letter = key - 'a';
    } else if (key >= 'A' && key <= 'Z') {
        letter = key - 'A';
    } else {
        letter = -1;
    }
    if (letter != -1) {
        progress = key_progress;
        code = lbl_804A0468;
        for (i = 0; i != 3; i++, progress++, code++) {
            if (letter == code->keys[*progress]) {
                *progress = *progress + 1;
            } else {
                *progress = 0;
            }
            if (*progress == code->length) {
                code->activate();
                *progress = 0;
            }
        }
    }
}

TItemReverseTechCtrl::TItemReverseTechCtrl(TObject *parent) : TObject(parent) {
    m_name = lbl_805D2C58;
    disallow_rendering();
    key_progress[0] = 0;
    key_progress[1] = 0;
    key_progress[2] = 0;
}

extern "C" {
s8 lbl_804A0440[12] = {
    'u' - 'a', 'r' - 'a', 'a' - 'a', 'e' - 'a', 'n' - 'a', 'd' - 'a',
    'i' - 'a', 'n' - 'a', 'g' - 'a',
};
s8 lbl_804A044C[12] = {
    'g' - 'a', 'y' - 'a', 'a' - 'a', 'k' - 'a', 'u' - 'a', 'k' - 'a',
    'a' - 'a', 'i' - 'a', 't' - 'a', 'e' - 'a', 'n' - 'a',
};
s8 lbl_804A0458[16] = {
    'k' - 'a', 'o' - 'a', 'u' - 'a', 's' - 'a', 'o' - 'a', 'k' - 'a',
    'u' - 'a', 'k' - 'a', 'a' - 'a', 'i' - 'a', 't' - 'a', 'e' - 'a', 'n' - 'a',
};
ReverseTechCode lbl_804A0468[3] = {
    { lbl_804A0440, 9, TItemReverseTech__sub_8011A5A4 },
    { lbl_804A044C, 11, (void (*)(void))TItemReverseTech__sub_8011A580 },
    { lbl_804A0458, 13, (void (*)(void))TItemReverseTech__sub_8011A55C },
};
}

TItemReverseTechCtrl *TItemReverseTechCtrl::create(TObject *parent) {
    return new TItemReverseTechCtrl(parent);
}

TItemReverseTechCtrl::~TItemReverseTechCtrl() {}
