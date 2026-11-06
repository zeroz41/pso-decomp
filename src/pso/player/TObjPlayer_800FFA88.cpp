#include "pso/object/base/TObjMotion.h"

s32 TObjMotion::get_item_ptr(s32 arg1) {
    return (*(s32 *)&this->joint_matrices) + (arg1 * 0x30);
}
