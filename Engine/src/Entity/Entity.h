#pragma once
#include "Export.h"
namespace Engine
{
	class ENGINE_API IEntity
	{
	public:
		virtual void draw() = 0;
	private:
	};
}