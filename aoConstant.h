/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOCONSTANT_H
#define AOCONSTANT_H

namespace ao
{
namespace core
{
enum RetStat { SUCCESS, FAIL, DUPLICATE_ERROR };
const float ROUNDING_ERROR_FLOAT = 0.000001f;

const int ROUNDING_ERROR_S32 = 0;
const double ROUNDING_ERROR_f64 = 0.00000001;

#ifdef PI // make sure we don't collide with a define
#undef PI
#endif
const float PI            = 3.14159265359f;

const float RECIPROCAL_PI = 1.0f/PI;

const float HALF_PI       = PI/2.0f;

#ifdef PI64 // make sure we don't collide with a define
#undef PI64
#endif
const double PI64          = 3.1415926535897932384626433832795028841971693993751;
const double RECIPROCAL_PI64 = 1.0/PI64;

const float DEGTORAD = PI / 180.0f;

const float RADTODEG   = 180.0f / PI;

const double DEGTORAD64 = PI64 / 180.0;

const double RADTODEG64 = 180.0 / PI64;

}
}

#endif
