#pragma once
#include "Shape/Shape.h"
namespace Engine
{
	class ENGINE_API CollisionManager {
	public:
		std::list<Shape*>GetShapeList();
		void SetShapeList(std::list<Shape*> ShapeList);
		void CheckCollisions();
		bool ShapeAreColliding(Shape* shape1, Shape* shape2);
	private:
		std::list<Shape*> shapeList;
	};
}