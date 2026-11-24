#include "pso/object/base/TObjMotion.h"

saddr TObjMotion::get_joint_matrix(s32 joint) {
    return (saddr)this->joint_matrices + (joint * 0x30);
}
