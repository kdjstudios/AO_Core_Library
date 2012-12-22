/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOMATH_H
#define AOMATH_H

//#include "IrrCompileConfig.h"
//#include "aoTypes.h"
#include "aoConstant.h"
#include <math.h>
#include <float.h>
#include <stdlib.h> // for abs() etc.
#include <limits.h> // For INT_MAX / UINT_MAX

//Use this to improve (precompile?)
#if defined(_IRR_SOLARIS_PLATFORM_) || defined(__BORLANDC__) || defined (__BCPLUSPLUS__) || defined (_WIN32_WCE)
#define sqrtf(X) (f32)sqrt((f64)(X))
#define sinf(X) (f32)sin((f64)(X))
#define cosf(X) (f32)cos((f64)(X))
#define asinf(X) (f32)asin((f64)(X))
#define acosf(X) (f32)acos((f64)(X))
#define atan2f(X,Y) (f32)atan2((f64)(X),(f64)(Y))
#define ceilf(X) (f32)ceil((f64)(X))
#define floorf(X) (f32)floor((f64)(X))
#define powf(X,Y) (f32)pow((f64)(X),(f64)(Y))
#define fmodf(X,Y) (f32)fmod((f64)(X),(f64)(Y))
#define fabsf(X) (f32)fabs((f64)(X))
#define logf(X) (f32)log((f64)(X))
#endif
//MUST HAVE
#ifndef FLT_MAX
#define FLT_MAX 3.402823466E+38F
#endif

namespace ao
{

namespace core
{

//Returns Max
template<class TYPE> TYPE equ(const TYPE& left, const TYPE& right)
{
    return (abs(left*right)>ROUNDING_ERROR_FLOAT)?left:right;
}
//Returns Max
template<class TYPE> TYPE max(const TYPE& left, const TYPE& right)
{
    return left>right?left:right;
}
//Returns Min
template<class TYPE> TYPE min(const TYPE& left, const TYPE& right)
{
    return left<right?left:right;
}
//Used to quickly swap
template<class TYPE> void swap(const TYPE& left, const TYPE& right)
{
    if(left!=right)
    {
        TYPE temp=left;
        left=right;
        right=temp;
    }
}
//Find
template<class In,class X> In find(In begin, In end, const X& x)
{
    while(begin!=end&&*begin!=x)
        ++begin;
    return begin;
}
//Copy
template<class In,class Out> Out copy(In begin, In end, Out dest)
{
    while(begin!=end)
        *dest++=*begin++;
    return dest;
}
//Replace
template<class For,class X> void replace(For begin,For end, const X& x, const X& y)
{
    while(begin!=end)
        if(*begin==x)
            *begin=y;
    ++begin;
}

//Returns Absoult Valuse
template<class TYPE>
TYPE abs(const TYPE& left)
{
    unsigned long long* x = (unsigned long long*)&left;
    *x &= 0x7fffffffffffffff;
    return left;
}
//Clamps Value
template<class TYPE> TYPE Clamp(const TYPE& value, const TYPE& max)
{
    return 1;//(abs(left*right)>ROUNDING_ERROR_FLOAT)?left:right;
}
//Ceil
template<class TYPE> TYPE Ceil(const TYPE& value, const TYPE& max)
{
    return 1;//(abs(left*right)>ROUNDING_ERROR_FLOAT)?left:right;
}
//Floor
template<class TYPE> TYPE Floor(const TYPE& value, const TYPE& max)
{
    return 1;//(abs(left*right)>ROUNDING_ERROR_FLOAT)?left:right;
}
//Slerp
template<class TYPE> TYPE Slerp(const TYPE& value, const TYPE& max)
{
    return 1;//(abs(left*right)>ROUNDING_ERROR_FLOAT)?left:right;
}
//Lerp
template<class TYPE> TYPE Lerp(const TYPE& value, const TYPE& max)
{
    return 1;//(abs(left*right)>ROUNDING_ERROR_FLOAT)?left:right;
}
//Round
template<class TYPE> TYPE Round(const TYPE& value, const TYPE& max)
{
    return 1;//(abs(left*right)>ROUNDING_ERROR_FLOAT)?left:right;
}
//IsZero
template<class TYPE> TYPE IsZero(const TYPE& value, const TYPE& max)
{
    return 1;//(abs(left*right)>ROUNDING_ERROR_FLOAT)?left:right;
}

//FastSin
template<class TYPE>
TYPE FastSIN(const TYPE& value)
{
    return SIN[((int) value%360)];//(abs(left*right)>ROUNDING_ERROR_FLOAT)?left:right;
}
//FastCos
template<class TYPE>
TYPE FastCOS(const TYPE& value)
{
    return SIN[((((int) value)+90)%360)];//(abs(left*right)>ROUNDING_ERROR_FLOAT)?left:right;
}

}
}
#endif
