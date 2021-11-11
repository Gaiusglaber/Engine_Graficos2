#include "CollisionManager.h"
namespace Engine
{
	std::list<Shape*> CollisionManager::GetShapeList()
	{
		return shapeList;
	}

	void CollisionManager::SetShapeList(std::list<Shape*> ShapeList)
	{
		shapeList = ShapeList;
	}

	void CollisionManager::CheckCollisions()
	{
		for (std::list<Shape*>::iterator it1 = shapeList.begin(); it1 != shapeList.end(); ++it1)
		{
			for (std::list<Shape*>::iterator it2 = shapeList.begin(); it2 != shapeList.end(); ++it2)
			{
				if (it1 != it2) 
				{
					if (ShapeAreColliding(*it1, *it2)) {
						std::cout << "collision";
					}
				}
			}
		}
	}

	bool CollisionManager::ShapeAreColliding(Shape* shape1, Shape* shape2)
	{
		return shape1->GetPos().x< shape2->GetPos().x+ shape1->GetWidth()&&
			shape1->GetPos().x+ shape1->GetWidth()>shape2->GetPos().x&&
			shape1->GetPos().y< shape2->GetPos().y + shape1->GetHeight() &&
			shape1->GetPos().y + shape1->GetHeight()>shape2->GetPos().y;
	}

}
