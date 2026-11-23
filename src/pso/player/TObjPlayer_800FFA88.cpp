#include "pso/object/base/TObjMotion.h"

saddr TObjMotion::get_joint_matrix(s32 arg1) {
    return (*(s32 *)&this->joint_matrices) + (arg1 * 0x30);
}
