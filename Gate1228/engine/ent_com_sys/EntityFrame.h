#ifndef ENTITYFRAME_H
#define ENTITYFRAME_H

//STL includes
#include <array>
#include <memory>
#include <vector>
#include <bitset> // critical

//SFGE
#include "Entity.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//! @file: EntityFrame.hpp																		/
//! @module: entity_component																	/
//! @project: Simple and Fast Game Engine 2018													/
//! @author: Anton Yashchenko																	/
//! @date: 8/18/2018																			/
/////////////////////////////////////////////////////////////////////////////////////////////////

//! @class: EntityFrame
//! @purpose: interface for creating components to add to entites 
class EntityFrame
{
protected:
	Entity * frame_;

	EntityFrame()
	{
		frame_ = new Entity;
	}

public:
	Entity* create()
	{
		Entity* newe(new Entity(*frame_));
		return newe;
	}
};

#endif // !ENTITY_H