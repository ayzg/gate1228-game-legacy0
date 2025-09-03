//#ifndef ENTITYCOMP_HPP
//#define ENTITYCOMP_HPP
//
///* Name: Entity Component System
//* Author: Anton Yashchenko
//* Date: 3/28/2018
//*
//*
//*/
//
////STL 
//#include <iostream>
//#include <vector>
//#include <memory>
//#include <algorithm>
//#include <bitset>
//#include <array>
//#include <cassert>
//#include <type_traits>
//#include <chrono> 
//#include <functional>
//
//#include "SFML\Graphics.hpp"
//namespace g_core
//{
//	//Forward declaration
//	struct Component;
//	class Entity;
//	class EntityManager;
//
//	//ECS constants
//	constexpr std::size_t maxComponents{ 32 }; //Max components per entity
//	constexpr std::size_t maxGroups{ 32 }; //Max groups of entities
//
//	using ComponentID = std::size_t;
//	using Group = std::size_t;
//
//	namespace Internal
//	{
//		inline ComponentID getUniqueComponentID() noexcept
//		{
//			static ComponentID lastID{ 0u };
//			return lastID++;
//		}
//	}
//
//	template <typename T>
//	inline ComponentID getComponentTypeID() noexcept
//	{
//		static_assert(std::is_base_of<Component, T>::value,
//			"T must inherit from Component");
//
//		static ComponentID typeID{ Internal::getUniqueComponentID() };
//		return typeID;
//	}
//
//
//	using ComponentBitset = std::bitset<maxComponents>;
//	using ComponentArray = std::array<Component*, maxComponents>;
//
//	using GroupBitset = std::bitset<maxGroups>;
//
//	/* Struct: Component
//	* Purpose: Base class for all components - virtual base functions
//	*			include: init(), update(float mFT), draw()
//	* Contains: Entity* entity -> points to owner entity of component
//	*
//	*/
//	struct Component
//	{
//		Entity* entity;
//
//		virtual void init() {}
//		virtual void update(float mFT) {}
//		virtual void draw(sf::RenderWindow& target) {}
//
//		virtual ~Component() {}
//	};
//
//
//	/* Class: Entity
//	* Purpose: Base entity class represents an array of components as a single object.
//	*			Calls update(float mFT) and draw() for each component beling to entity.
//	* Contains: EntityManager& - reference to entity manager - required on construction.
//	*
//	* Access: T& getComponent<ComponentType>() const
//	*/
//	class Entity
//	{
//	private:
//		EntityManager & manager;
//
//		unsigned int id;
//		bool alive{ true };
//		std::vector<std::unique_ptr<Component>> components;
//		ComponentArray componentArray;
//		ComponentBitset componentBitset;
//
//		GroupBitset groupBitset;
//
//	public:
//		Entity(EntityManager& mEntityManager) : manager(mEntityManager){}
//
//		void update(float mFT)
//		{
//			for (auto& c : components) c->update(mFT);
//		}
//		void draw(sf::RenderWindow& target)
//		{
//			for (auto& c : components) c->draw(target);
//		}
//
//		bool isAlive() const { return alive; }
//
//		unsigned int getId() const { return id; }
//
//		void destroy() { alive = false; }
//
//		template <typename T>
//		bool hasComponent() const
//		{
//			return componentBitset[getComponentTypeID<T>()];
//		}
//
//		bool hasGroup(Group mGroup) const noexcept
//		{
//			return groupBitset[mGroup];
//		}
//
//		void addGroup(Group mGroup) noexcept;
//		void delGroup(Group mGroup) noexcept { groupBitset[mGroup] = false; }
//
//		template <typename T, typename... TArgs>
//		T& addComponent(TArgs&&... mArgs)
//		{
//			assert(!hasComponent<T>());
//
//			T* c(new T(std::forward<TArgs>(mArgs)...));
//			c->entity = this;
//			std::unique_ptr<Component> uPtr{ c };
//			components.emplace_back(std::move(uPtr));
//
//			componentArray[getComponentTypeID<T>()] = c;
//			componentBitset[getComponentTypeID<T>()] = true;
//
//			c->init();
//			return *c;
//		}
//
//		template <typename T>
//		T& getComponent() const
//		{
//			assert(hasComponent<T>());
//			auto ptr(componentArray[getComponentTypeID<T>()]);
//			return *reinterpret_cast<T*>(ptr);
//		}
//
//	};
//
//	/* Class: EntityManager
//	* Purpose: Contains vector of entities - calls update(float mFT) and draw() for
//	*			all entity objects.
//	* Add entities: Entity& addEntity()
//	* Refresh to destroy 'dead' entities: refresh()
//	*
//	*/
//	class EntityManager
//	{
//	private:
//		std::vector<std::unique_ptr<Entity>> entities;
//		std::array<std::vector<Entity*>, maxGroups> groupedEntities;
//
//	public:
//		void update(float mFT)
//		{
//			for (auto& e : entities) e->update(mFT);
//		}
//		void draw(sf::RenderWindow& target)
//		{
//			for (auto& e : entities) e->draw(target);
//		}
//
//		void addToGroup(Entity* mEntity, Group mGroup)
//		{
//			groupedEntities[mGroup].emplace_back(mEntity);
//		}
//
//		std::vector<Entity*>& getEntitiesByGroup(Group mGroup)
//		{
//			return groupedEntities[mGroup];
//		}
//
//		Entity& getEntityById(unsigned int id)
//		{
//			for (auto& e : entities)
//			{
//				if (e->getId() == id)
//				{
//					return *e;
//				}
//			}
//			
//			throw std::exception("No such entity exists");
//		}
//
//		void refresh()
//		{
//			for (auto i(0u); i < maxGroups; ++i)
//			{
//				auto& v(groupedEntities[i]);
//
//				v.erase(std::remove_if(std::begin(v), std::end(v),
//					[i](Entity* mEntity)
//				{
//					return !mEntity->isAlive() ||
//						!mEntity->hasGroup(i);
//				}),
//					std::end(v));
//			}
//
//			entities.erase(
//				std::remove_if(std::begin(entities), std::end(entities),
//					[](const std::unique_ptr<Entity>& mEntity)
//			{
//				return !mEntity->isAlive(); //Remove entity if isAlive = false
//			}),
//				std::end(entities));
//		}
//
//		Entity& addEntity()
//		{
//			Entity* e(new Entity(*this));
//			std::unique_ptr<Entity> uPtr{ e };
//			entities.emplace_back(std::move(uPtr));
//			return *e;
//		}
//	};
//
//
//	//NOTE: if not inline -> cannot include entitycomp.hpp multiple times (LINK Error - already defined in .obj)
//	inline void Entity::addGroup(Group mGroup) noexcept
//	{
//		groupBitset[mGroup] = true;
//		manager.addToGroup(this, mGroup);
//	}
//
//}
//
//
//#endif
