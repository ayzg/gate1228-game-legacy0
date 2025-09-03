#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

/////////////////////////////////////////////////////////////////////////////////////////////////
//! @file: EntityFrame.hpp																		/
//! @module: entity_component																	/
//! @project: Simple and Fast Game Engine 2018													/
//! @author: Anton Yashchenko																	/
//! @date: 8/18/2018																			/
/////////////////////////////////////////////////////////////////////////////////////////////////

//STL
#include "vector"

//nTC
#include "../../core/strictSingleton.hpp"

//SFGE
#include "EntityFrame.h"

//! @class:EntityManager
//!	@purpose: 

class EntityManager : public StrictSingleton<EntityManager>
{																		   
public:
	using entity_uptr_list = std::vector<std::unique_ptr<Entity>>;
private:
	entity_uptr_list entities_;
public:
	entity_uptr_list& entities();

	void refresh();
	void update(const float m_ft);
	void draw(sf::RenderWindow& target);

	Entity& add(EntityFrame* eframe);
};

#endif
