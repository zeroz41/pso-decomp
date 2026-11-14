#include "pso/boss/darkfalz/TBoss4Fade.h"

TBoss4Fade::~TBoss4Fade() {}

#include "types.h"

#pragma readonly_strings on

extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__10TBoss4Fade[];
const char *TBoss4Fade__name = "TBoss4Fade";

void *__ct__10TBoss4FadeFv(void *boss4_fade) {
    __ct__7TObjectFP7TObject(boss4_fade);
    *(s32 **)((s8 *)boss4_fade + 0x18) = __vt__10TBoss4Fade;
    ((TBoss4Fade *)boss4_fade)->m_name = TBoss4Fade__name;
    *(u32 *)((s8 *)boss4_fade + 0x20) = 0;
    *(u32 *)((s8 *)boss4_fade + 0x2C) = 0;
    *(u32 *)((s8 *)boss4_fade + 0x1C) = 0;
    return boss4_fade;
}

}
