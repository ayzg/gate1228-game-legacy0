#ifndef ENTITY_HPP
#define ENTITY_HPP

/*!===============================================================================================
==================================================================================================
\file: Entity.hpp
\module: entity_component
\project: Simple and Fast Game Engine 2018
\author: Anton Yashchenko - www.nton.ca
==================================================================================================
================================================================================================*/

/*!=========================================\INCLUDES\==========================================*/

/*STL - Standard Template Library*/
#include <array>
#include <memory>
#include <vector>
#include <bitset> 

/*SFGE - Simple and Fast Game Engine*/
#include "Component.hpp"

/*!==========================================\CONTENT\==========================================*/

//! @class:	Entity
//! @purpose: composes component-derived classes, and a bitset to identify them.
//			  access to update() and draw() functions on all owned component			
//! @notes: cannot contain repeat components, getComponent<typename T>() will become ambiguous.
class Entity
{
	private:
		static const int MAX_COMPONENTS = 32;
		std::vector<std::unique_ptr<Component>> components_;
		std::bitset<MAX_COMPONENTS> component_bitset_;
		std::array<Component*, MAX_COMPONENTS> component_array_;
		bool exists_{true};

	public:
		Entity(Entity& e)
		{
			this->component_array_ = e.component_array_;
			this->component_bitset_ = e.component_bitset_;
		};	

		Entity() = default;
		~Entity() = default;

		bool exists() const { return exists_; }

		//@method: update
		//calls update on all components belonging to entity
		void update(float mFT)
		{
			for (auto& c : component_array_)
			{
				if (c != nullptr)
					c->update(mFT);

			}
		}

		//@method: update
		//calls draw on all components belonging to entity
		void draw(sf::RenderWindow& target)
		{
			for (auto& c : component_array_)
			{
				if(c != nullptr)
					c->draw(target);
			}
		}

		//! @method: hasComponent
		//! @purpose: checks if this entity has a certain component by Type
		template <typename T>
		bool hasComponent() const
		{
			return component_bitset_[getComponentTypeID<T>()];
		}

		//! @method: addComponent
		//! @purpose: adds a component to this entity by forwarding TArgs to the component's constructor
		template <typename T, typename... TArgs>
		T& addComponent(TArgs&&... mArgs)
		{
			assert(!hasComponent<T>());
			auto* new_comp(new T(std::forward<TArgs>(mArgs)...));
			component_array_[getComponentTypeID<T>()] = new_comp;
			component_bitset_[getComponentTypeID<T>()] = true;
			return *new_comp;
		}

		//! @method: addComponent
		//! @returns: a component by reference by type
		template <typename T>
		T& getComponent() const
		{
			assert(hasComponent<T>());
			auto ptr(component_array_[getComponentTypeID<T>()]);
			return *reinterpret_cast<T*>(ptr);
		}
		
		//@method: broadcast
		//broadcast a message to all components belonging to this entity
		void broadcast(int message)
		{
			for (int i = 0; i < MAX_COMPONENTS; i++)
			{
				if (component_array_[i] != nullptr)
				{
					component_array_[i]->recieve(message);
				}
			}
		}

		//@method: send
		//send a message to a component by Type belinging to this entity
		template<typename T>
		void send(int message)
		{
			if (hasComponent<T>())
				component_array_[getComponentTypeID<T>()]->recieve(message);
			else
				std::cout << typeid(T).name() << " does not exist in this entity. Message sent: " << message << std::endl;
		}				
};

/*!==========================================\HISTORY\==========================================*/
/*!===============================================================================================

\CurrentVersion 1.0.0: 8/21/2018

==================================================================================================
==================================================================================================

Copyright Anton Yashchenko, 2018

The copyright to the computer program(s) herein
is the property of Anton Yashchenko, Canada.
The program(s) may be used and/or copied only with
the written permission of Anton Yashchenko
or in accordance with the terms and conditions
stipulated in the agreement/contract under which
the program(s) have been supplied.

==================================================================================================
================================================================================================*/
#endif

