#include "types.h"
#include "pso/render/render_util.h"
#include "pso/system/CxxRuntime.h"

u8 lbl_805D5DD8[8];
DestructorChain lbl_80511DD8;

// Builds the global object above and registers its destructor, spelled out because the object's class (built by
// clear_first_word, destroyed by delete_object_if_delete_flag) is not known.
void __sinit_ZeroedGlobalObject_cpp() {
    __register_global_object(clear_first_word(lbl_805D5DD8), (ObjectDestructor)delete_object_if_delete_flag,
        &lbl_80511DD8);
}

__declspec(section ".ctors") static void *const zeroed_object_global_initializer = (void *)__sinit_ZeroedGlobalObject_cpp;
