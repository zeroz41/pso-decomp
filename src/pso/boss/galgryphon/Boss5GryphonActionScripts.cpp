#include "pso/boss/galgryphon/Boss5GryphonActionScripts.h"

// gryphon_action_script_<n> is boss5_gryphon_action_scripts[n]; a {33, 0, 0, n} step chains to script n.
static Boss5GryphonActionStep gryphon_action_script_0[6] = {
    {0, 2},
    {12, -1},
    {13, 30},
    {14, 60, 120, {{-1, 0}, {112}}, {{3.5f}, {275.0f}}},
    {16, -1},
    {33},
};
static Boss5GryphonActionStep gryphon_action_script_1[22] = {
    {9, 30, 0, {{0, 0}, {56}}, {{1.8f}, {300.0f}}},
    {10, -1, 0, {{0, 0}, {8}}, {{0.8f}, {700.0f}}},
    {10, -1, 0, {{0, 0}, {57}}, {{0.7f}, {400.0f}}},
    {29, -1},
    {30, 120, 60},
    {27, 18000, 120},
    {10, -1, 0, {{0, 0}, {8}}, {{0.8f}, {700.0f}}},
    {10, -1, 0, {{0, 0}, {57}}, {{0.7f}, {400.0f}}},
    {29, -1},
    {30, 120, 60},
    {32, -1},
    {10, -1, 0, {{0, 0}, {8}}, {{0.8f}, {700.0f}}},
    {10, -1, 0, {{0, 0}, {57}}, {{0.7f}, {400.0f}}},
    {29, -1},
    {30, 120, 60},
    {32, -1},
    {10, -1, 0, {{0, 0}, {8}}, {{0.8f}, {700.0f}}},
    {10, -1, 0, {{0, 0}, {57}}, {{0.7f}, {400.0f}}},
    {29, -1},
    {30, 120, 60},
    {32, -1},
    {33},
};
static Boss5GryphonActionStep gryphon_action_script_2[7] = {
    {9, 90, 60, {{0, 0}, {96}}, {{0.75f}, {320.0f}}},
    {7, -1},
    {9, 60, 30, {{0, 0}, {96}}, {{0.75f}, {310.0f}}},
    {7, -1},
    {9, 60, 30, {{0, 0}, {96}}, {{0.75f}, {300.0f}}},
    {7, -1},
    {33, 0, 0, 1},
};
static Boss5GryphonActionStep gryphon_action_script_3[7] = {
    {9, 90, 60, {{1, 0}, {96}}, {{0.75f}, {275.0f}}},
    {7, -1},
    {9, 60, 30, {{1, 0}, {96}}, {{0.75f}, {300.0f}}},
    {7, -1},
    {9, 60, 30, {{1, 0}, {96}}, {{0.75f}, {330.0f}}},
    {7, -1},
    {33, 0, 0, 1},
};
static Boss5GryphonActionStep gryphon_action_script_4[5] = {
    {9, 120, 60, {{-1, 0}, {96}}, {{0.75f}, {275.0f}}},
    {7, -1},
    {9, 90, 60, {{-1, 0}, {96}}, {{0.75f}, {300.0f}}},
    {7, -1},
    {33, 0, 0, 1},
};
static Boss5GryphonActionStep gryphon_action_script_5[6] = {
    {10, -1, 0, {{0, 0}, {8}}, {{0.8f}, {700.0f}}},
    {10, -1, 0, {{0, 0}, {57}}, {{0.7f}, {400.0f}}},
    {12, -1},
    {13, 30, 30},
    {16, -1},
    {33, 0, 0, 2},
};
static Boss5GryphonActionStep gryphon_action_script_6[5] = {
    {10, -1, 0, {{0, 0}, {8}}, {{0.8f}, {700.0f}}},
    {10, -1, 0, {{0, 0}, {57}}, {{0.7f}, {400.0f}}},
    {12, -1},
    {15, -1},
    {33, 0, 0, 3},
};
static Boss5GryphonActionStep gryphon_action_script_7[6] = {
    {10, -1, 0, {{0, 0}, {8}}, {{0.8f}, {700.0f}}},
    {10, -1, 0, {{0, 0}, {57}}, {{0.7f}, {400.0f}}},
    {17, -1},
    {13, 60},
    {19, -1},
    {33, 0, 0, 2},
};
static Boss5GryphonActionStep gryphon_action_script_8[5] = {
    {10, -1, 0, {{0, 0}, {8}}, {{0.8f}, {700.0f}}},
    {10, -1, 0, {{0, 0}, {57}}, {{0.7f}, {400.0f}}},
    {17, -1},
    {18, -1},
    {33, 0, 0, 3},
};
static Boss5GryphonActionStep gryphon_action_script_9[4] = {
    {10, -1, 0, {{0, 0}, {56}}, {{0.8f}, {250.0f}}},
    {29, -1},
    {30, 120, 60},
    {33, 0, 0, 3},
};
static Boss5GryphonActionStep gryphon_action_script_10[4] = {
    {10, -1, 0, {{0, 0}, {96}}, {{0.8f}, {400.0f}}},
    {10, -1, 0, {{0, 0}, {96}}, {{0.5f}, {350.0f}}},
    {11, -1},
    {33, 0, 0, 3},
};
static Boss5GryphonActionStep gryphon_action_script_11[9] = {
    {23, -1},
    {24, 180, 90},
    {31, -1},
    {23, -1},
    {24, 90, 60},
    {20, -1},
    {21, 90, 60},
    {22, -1},
    {33, 0, 0, 4},
};
static Boss5GryphonActionStep gryphon_action_script_12[9] = {
    {23, -1},
    {24, 180, 90},
    {31, -1},
    {23, -1},
    {24, 60, 30},
    {26, -1},
    {27, 150, 120},
    {28, -1},
    {33, 0, 0, 4},
};
static Boss5GryphonActionStep gryphon_action_script_13[9] = {
    {23, -1},
    {24, 150, 60},
    {20, -1},
    {21, 90, 60},
    {22, -1},
    {23, -1},
    {24, 120, 90},
    {31, -1},
    {33, 0, 0, 4},
};
static Boss5GryphonActionStep gryphon_action_script_14[8] = {
    {23, -1},
    {26, -1},
    {27, 120, 90},
    {28, -1},
    {23, -1},
    {24, 30, 90},
    {31, -1},
    {33, 0, 0, 4},
};
static Boss5GryphonActionStep gryphon_action_script_15[8] = {
    {23, -1},
    {26, -1},
    {27, 150, 90},
    {28, -1},
    {20, -1},
    {21, 90, 60},
    {22, -1},
    {33, 0, 0, 4},
};
static Boss5GryphonActionStep gryphon_action_script_16[2] = {
    {2, 270, 150},
    {33, 0, 0, 5},
};
static Boss5GryphonActionStep gryphon_action_script_17[5] = {
    {2, 240, 60},
    {23, -1},
    {24, 150, 90},
    {31, -1},
    {33, 0, 0, 5},
};
static Boss5GryphonActionStep gryphon_action_script_18[8] = {
    {2, 180, 60},
    {23, -1},
    {24, 150, 60},
    {20, -1},
    {21, 90, 60},
    {22, -1},
    {2, 120, 60},
    {33, 0, 0, 5},
};
static Boss5GryphonActionStep gryphon_action_script_19[6] = {
    {23, -1},
    {24, 150, 30},
    {20, -1},
    {21, 300, 120},
    {22, -1},
    {33, 0, 0, 5},
};
static Boss5GryphonActionStep gryphon_action_script_20[14] = {
    {23, -1},
    {24, 90, 30},
    {20, -1},
    {21, 90, 30},
    {22, -1},
    {23, -1},
    {24, 30, 90},
    {31, -1},
    {23, -1},
    {24, 30, 30},
    {20, -1},
    {21, 90, 30},
    {22, -1},
    {33, 0, 0, 5},
};
static Boss5GryphonActionStep gryphon_action_script_21[15] = {
    {23, -1},
    {24, 30},
    {20, -1},
    {21, 90, 30},
    {22, -1},
    {23, -1},
    {26, -1},
    {27, 90, 120},
    {28, -1},
    {23, -1},
    {24, 60, 30},
    {20, -1},
    {21, 90, 30},
    {22, -1},
    {33, 0, 0, 5},
};
static Boss5GryphonActionStep gryphon_action_script_22[2] = {
    {6, -1},
    {33, 0, 0, 6},
};
static Boss5GryphonActionStep gryphon_action_script_23[2] = {
    {16, -1},
    {33, -1},
};
static Boss5GryphonActionStep gryphon_action_script_24[2] = {
    {30, 120, 60},
    {33, -1},
};
static Boss5GryphonActionStep gryphon_action_script_25[3] = {
    {6, -1},
    {5, -1},
    {34, -1},
};
static Boss5GryphonActionStep gryphon_action_script_26[2] = {
    {5, -1},
    {34, -1},
};
static Boss5GryphonActionStep gryphon_action_script_27[4] = {
    {30, 120, 60},
    {6, -1},
    {5, -1},
    {34, -1},
};
static Boss5GryphonActionStep gryphon_action_script_28[3] = {
    {16, -1},
    {5, -1},
    {34, -1},
};

Boss5GryphonActionStep *boss5_gryphon_action_scripts[30] = {
    gryphon_action_script_0, gryphon_action_script_1, gryphon_action_script_2, gryphon_action_script_3,
    gryphon_action_script_4, gryphon_action_script_5, gryphon_action_script_6, gryphon_action_script_7,
    gryphon_action_script_8, gryphon_action_script_9, gryphon_action_script_10, gryphon_action_script_11,
    gryphon_action_script_12, gryphon_action_script_13, gryphon_action_script_14, gryphon_action_script_15,
    gryphon_action_script_16, gryphon_action_script_17, gryphon_action_script_18, gryphon_action_script_19,
    gryphon_action_script_20, gryphon_action_script_21, gryphon_action_script_22, gryphon_action_script_23,
    gryphon_action_script_24, gryphon_action_script_25, gryphon_action_script_26, gryphon_action_script_27,
    gryphon_action_script_28, NULL,
};
