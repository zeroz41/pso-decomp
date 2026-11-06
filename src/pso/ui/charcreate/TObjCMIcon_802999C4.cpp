#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TObjCMIcon_802999C4.h"
#include "types.h"

class TObjCMIcon : public TObject {
public:
    virtual ~TObjCMIcon();
    virtual void run_task();
    virtual void render();
};

s32 TObjCMIcon__icon_group_table[35] = {
    2, 0x38, 0xA8, 0, 0,
    2, 0x38, 0xA9, 0, 0,
    2, 0x38, 0xAA, 0, 0,
    3, 0x38, 0x37, 0xAA, 0,
    2, 0x37, 0xA7, 0, 0,
    2, 0x37, 0xAB, 0, 0,
    2, 0x37, 0xAC, 0, 0,
};
__declspec(section ".data") f32 cm_icon_screen_position[2] = { 604.0f, 443.0f };

TObjCMIcon::~TObjCMIcon() {}

extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__10TObjCMIcon[];
extern void *lbl_805D3CF0;

void *__ct__10TObjCMIconFv(void *object) {
    __ct__7TObjectFP7TObject(object);
    *(s32 **)((s8 *)object + 0x18) = __vt__10TObjCMIcon;
    *(void **)((s8 *)object + 0x0) = lbl_805D3CF0;
    return object;
}

}
