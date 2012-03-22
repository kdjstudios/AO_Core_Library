/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AO_H
#define AO_H
//All Includes below
// #include "dimension2d.h"
// #include "position2d.h"
#include "aoRect.h"
// #include "aabbox3d.h"
#include "aoIAABox.h"
// #include "line2d.h"
// #include "line3d.h"
// #include "plane3d.h"
// #include "triangle3d.h"
#include "matrix2x2.h"
#include "matrix3x3.h"
#include "matrix4x4.h"
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "quaternion.h"
#include "aoBST.h"
#include "aoFSM.h"
//MAY NOT BE AS GOOD AS CAN BE
// #include "aoArray.h"
#include "aoList.h"
#include "Lists.h"
#include "vector.h"
#include "aoStack.h"
#include "aoFSM.h"
// #include "aoMap.h"
#include "aoMath.h"
#include "aoConstant.h"
#include "aoTelegram.h"
//#include "aoRefPtrHandle.h"
//#include "aoMesh.h"
#include "aoShape.h"
#include "aoLine.h"
//#include "Str.h"
//#include "aoTypes.h"
// #include "aoatof.h"
//#include "aoSorts.h"
//#include "aoEntityManager.h"
//#include "aoEntity.h"
//#include "aoMovingEntity.h"
//#include "aoBodyEntity.h"
//#include "aoRigidBody.h"
#include "aoClock.h"
// #include "coreutil.h"


//The complete api for Adrenaline Obsession
namespace ao
{
// THE FOLLOWING IS AN EMPTY LIST OF ALL SUB NAMESPACES

//Basic classes such as vectors, planes, arrays, lists, and so on can be found in this namespace.
namespace  	core {};
//Basic classes for opening files such as txt, xml and mpo/jpg can be found in this namespace.
namespace  	io {};
//Basic classes such as Vertex, Entity, Rigidbodys, Entity Manager, Meshs, and so on can be found in this namespace.
namespace  	graphics {};
};

#endif
