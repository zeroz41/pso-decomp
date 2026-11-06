#include "types.h"
#include "pso/item/TItemLoad_80110540.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/item/TItemLoad.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);
int update__9TItemLoadFv(void*);

int run_task__9TItemLoadFv(void* p) { return update__9TItemLoadFv(p); }

extern s32 __vt__9TItemLoad[];
extern void *lbl_805D2BF4;

void *__ct__9TItemLoadFv(void *item_load) {
    __ct__7TObjectFP7TObject(item_load);
    *(s32 **)((s8 *)item_load + 0x18) = __vt__9TItemLoad;
    *(void * *)&((TItemLoad *)item_load)->m_name = lbl_805D2BF4;
    disallow_rendering__7TObjectFv((TObject *)item_load);
    return item_load;
}

}
