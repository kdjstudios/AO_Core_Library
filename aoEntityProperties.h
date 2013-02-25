/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOENTITYPROPERTIES_H
#define AOENTITYPROPERTIES_H

#include "vector3.h"
#include "aoTelegram.h"
#include "aoMath.h"

namespace ao
{
	using namespace core;
	namespace graphics
	{

		class EntityProperties //:public Entity{
		{
			virtual void Update(double time_elapsed) {};
			virtual void Render();
		}

	}
}
#endif
