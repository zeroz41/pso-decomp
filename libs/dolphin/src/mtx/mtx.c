#include <dolphin.h>
#include <dolphin/mtx.h>
#include <macros.h>


extern f32 sinf(f32);
extern f32 cosf(f32);
extern f32 tanf(f32);


static float Unit01[2] = { 0.0f, 1.0f };

const f32 one_c[1] = { 1.0f };
const f32 zero_c[1] = { 0.0f };


asm void PSMTXIdentity(register GC_Mtx m) {
#include "orig_asm/mtx/mtx/PSMTXIdentity.inc"
}


















asm void PSMTXCopy(const register GC_Mtx src, register GC_Mtx dst) {
#include "orig_asm/mtx/mtx/PSMTXCopy.inc"
}















asm void PSMTXConcat(const register GC_Mtx mA, const register GC_Mtx mB, register GC_Mtx mAB) {
#include "orig_asm/mtx/mtx/PSMTXConcat.inc"
}























































asm void PSMTXTranspose(const register GC_Mtx src, register GC_Mtx xPose) {
#include "orig_asm/mtx/mtx/PSMTXTranspose.inc"
}



































asm u32 PSMTXInverse(const register GC_Mtx src, register GC_Mtx inv) {
#include "orig_asm/mtx/mtx/PSMTXInverse.inc"
}

































































void PSMTXRotRad(GC_Mtx m, char axis, f32 rad)
{
	f32 s = sinf(rad);
	f32 c = cosf(rad);

	PSMTXRotTrig(m, axis, s, c);
}

asm void PSMTXRotTrig(register GC_Mtx m, register char axis, register f32 sinA,
                  register f32 cosA) {
#include "orig_asm/mtx/mtx/PSMTXRotTrig.inc"
}




























































asm void PSMTXRotAxisRad(register GC_Mtx m, const Vec* axis, register f32 rad) {
#include "orig_asm/mtx/mtx/PSMTXRotAxisRad.inc"
}



















































asm void PSMTXTrans(register GC_Mtx m, register f32 xT, register f32 yT,
                register f32 zT) {
#include "orig_asm/mtx/mtx/PSMTXTrans.inc"
}










































asm void PSMTXScale(register GC_Mtx m, register f32 xS, register f32 yS,
                register f32 zS) {
#include "orig_asm/mtx/mtx/PSMTXScale.inc"
}









































asm void PSMTXQuat(register GC_Mtx m, const register PSQuaternion* q) {
#include "orig_asm/mtx/mtx/PSMTXQuat.inc"
}

















































void C_MTXLookAt(GC_Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target) {
    Vec vLook;
    Vec vRight;
    Vec vUp;

    ASSERTMSGLINE(2105, m, "MTXLookAt():  NULL MtxPtr 'm' ");
    ASSERTMSGLINE(2106, camPos, "MTXLookAt():  NULL VecPtr 'camPos' ");
    ASSERTMSGLINE(2107, camUp, "MTXLookAt():  NULL VecPtr 'camUp' ");
    ASSERTMSGLINE(2108, target, "MTXLookAt():  NULL Point3dPtr 'target' ");

    vLook.x = camPos->x - target->x;
    vLook.y = camPos->y - target->y;
    vLook.z = camPos->z - target->z;
    VECNormalize(&vLook, &vLook);
    VECCrossProduct(camUp, &vLook, &vRight);
    VECNormalize(&vRight, &vRight);
    VECCrossProduct(&vLook, &vRight, &vUp);
    m[0][0] = vRight.x;
    m[0][1] = vRight.y;
    m[0][2] = vRight.z;
    m[0][3] = -((camPos->z * vRight.z) + ((camPos->x * vRight.x) + (camPos->y * vRight.y)));
    m[1][0] = vUp.x;
    m[1][1] = vUp.y;
    m[1][2] = vUp.z;
    m[1][3] = -((camPos->z * vUp.z) + ((camPos->x * vUp.x) + (camPos->y * vUp.y)));
    m[2][0] = vLook.x;
    m[2][1] = vLook.y;
    m[2][2] = vLook.z;
    m[2][3] = -((camPos->z * vLook.z) + ((camPos->x * vLook.x) + (camPos->y * vLook.y)));
}

void C_MTXLightFrustum(GC_Mtx m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 scaleS,
                       f32 scaleT, f32 transS, f32 transT)
{
	f32 _tmp;

	_tmp    = one_c[0] / (r - l);
	m[0][0] = (scaleS * (2 * n * _tmp));
	m[0][1] = zero_c[0];
	m[0][2] = (scaleS * (_tmp * (r + l))) - transS;
	m[0][3] = zero_c[0];
	_tmp    = one_c[0] / (t - b);
	m[1][0] = zero_c[0];
	m[1][1] = (scaleT * (2 * n * _tmp));
	m[1][2] = (scaleT * (_tmp * (t + b))) - transT;
	m[1][3] = zero_c[0];
	m[2][0] = zero_c[0];
	m[2][1] = zero_c[0];
	m[2][2] = -1;
	m[2][3] = zero_c[0];
}

void C_MTXLightPerspective(GC_Mtx m, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT,
                           f32 transS, f32 transT)
{
	f32 angle;
	f32 cot;

	angle   = (0.5f * fovY);
	angle   = angle * 0.017453293f;
	cot     = one_c[0] / tanf(angle);
	m[0][0] = (scaleS * (cot / aspect));
	m[0][1] = zero_c[0];
	m[0][2] = -transS;
	m[0][3] = zero_c[0];
	m[1][0] = zero_c[0];
	m[1][1] = (cot * scaleT);
	m[1][2] = -transT;
	m[1][3] = zero_c[0];
	m[2][0] = zero_c[0];
	m[2][1] = zero_c[0];
	m[2][2] = -1;
	m[2][3] = zero_c[0];
}

