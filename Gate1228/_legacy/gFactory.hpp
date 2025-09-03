#ifndef G_FACTORY_HPP
#define G_FACTORY_HPP

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

//BOX2D
#include "Box2D\Box2D.h"

//ImGUI
#include "imgui.h"
#include "imgui-SFML.h"

#include "entitycomp.hpp"
#include "gComponents.hpp"

#include "world.hpp"

//using namespace g_core;
//
//// We'll use groups to keep track of our entities.
//enum EntityGroup : std::size_t
//{
//	GCharacter,GTile
//};
//
//struct gGame;
//
//class gFactory
//{
//private:
//	g_core::EntityManager* emanager_;
//	DataManager* data_;
//
//public:
//	gFactory(EntityManager* src,DataManager* data) : emanager_(src),data_(data){}
//	~gFactory() = default;;
//
//	// Creating entities can be done through simple "factory" functions.
//	g_core::Entity& create_character() const
//	{
//		auto& entity(emanager_->addEntity());
//
//		entity.addComponent<CPosition>(sf::Vector2f{ 250, 250 });
//
//		entity.addComponent<CPhysics>(sf::Vector2f{ 50, 50 });
//
//		entity.addComponent<CCircle>(50);
//
//		entity.addComponent<CControl>();
//
//		entity.addGroup(EntityGroup::GCharacter);
//
//		return entity;
//	}
//
//	Entity& createTile(World& world,hexl::Hex& hex)
//	{
//
//				auto& entity(emanager_->addEntity());
//
//				float xpos = world.flat_hex_to_pixel(hex).x;
//				float ypos = world.flat_hex_to_pixel(hex).y;
//
//				entity.addComponent<CPosition>(sf::Vector2f{ xpos,
//					ypos });
//
//				entity.addComponent<CPhysics>(sf::Vector2f{ 50, 50 });
//
//				entity.addComponent<CHex>(data_);
//
//				entity.addGroup(EntityGroup::GTile);
//
//
//				return entity;
//	}
//
//};
//
#endif