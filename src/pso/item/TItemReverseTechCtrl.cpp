#include "pso/item/TItemReverseTechCtrl.h"
#include "pso/item/TItemReverseTech.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/ControllerInput.h"

#pragma readonly_strings on


const char *TItemReverseTechCtrl_name = "TItemReverseTechCtrl";
extern ReverseTechCode reverse_tech_codes[3];

void TItemReverseTechCtrl::run_task() {
    s32 letter;
    ReverseTechCode *code;
    s32 *progress;
    s32 key;
    s32 i;
    key = keyboard_get_ascii_key();
    if (key >= 'a' && key <= 'z') {
        letter = key - 'a';
    } else if (key >= 'A' && key <= 'Z') {
        letter = key - 'A';
    } else {
        letter = -1;
    }
    if (letter != -1) {
        progress = key_progress;
        code = reverse_tech_codes;
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
    m_name = TItemReverseTechCtrl_name;
    disallow_rendering();
    key_progress[0] = 0;
    key_progress[1] = 0;
    key_progress[2] = 0;
}


s8 uraending_code_letters[12] = {
    'u' - 'a', 'r' - 'a', 'a' - 'a', 'e' - 'a', 'n' - 'a', 'd' - 'a',
    'i' - 'a', 'n' - 'a', 'g' - 'a',
};
s8 gyakukaiten_code_letters[12] = {
    'g' - 'a', 'y' - 'a', 'a' - 'a', 'k' - 'a', 'u' - 'a', 'k' - 'a',
    'a' - 'a', 'i' - 'a', 't' - 'a', 'e' - 'a', 'n' - 'a',
};
s8 kousokukaiten_code_letters[16] = {
    'k' - 'a', 'o' - 'a', 'u' - 'a', 's' - 'a', 'o' - 'a', 'k' - 'a',
    'u' - 'a', 'k' - 'a', 'a' - 'a', 'i' - 'a', 't' - 'a', 'e' - 'a', 'n' - 'a',
};
ReverseTechCode reverse_tech_codes[3] = {
    { uraending_code_letters, 9, activate_uraending_code },
    { gyakukaiten_code_letters, 11, (void (*)(void))activate_reverse_rotation_code },
    { kousokukaiten_code_letters, 13, (void (*)(void))activate_fast_rotation_code },
};

TItemReverseTechCtrl *TItemReverseTechCtrl::create(TObject *parent) {
    return new TItemReverseTechCtrl(parent);
}

TItemReverseTechCtrl::~TItemReverseTechCtrl() {}
