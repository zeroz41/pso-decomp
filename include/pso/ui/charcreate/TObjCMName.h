#ifndef PSO_UI_CHARCREATE_TOBJCMNAME_H
#define PSO_UI_CHARCREATE_TOBJCMNAME_H
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "types.h"
#include "pso/math/TMath.h"

extern "C" vec2f creation_name_panel_position[];

struct CharacterAppearanceFields;

struct TKeyBoardControl;

class TObjCMName : public TObject {
public:
    CharacterAppearanceFields *appearance;
    s32 initialized;
    TKeyBoardControl *keyboard;
    s32 ticks;
    s32 active;
    f32 fade;
    TObjCMName(TObject *parent);
    virtual ~TObjCMName();
    virtual void run_task();
    virtual void render();
    static TObjCMName *create(TObject *parent);
};

typedef char TObjCMNameSize[sizeof(TObjCMName) == 0x34 ? 1 : -1];
typedef char TObjCMNameFadeOffset[offsetof(TObjCMName, fade) == 0x30 ? 1 : -1];

#endif
