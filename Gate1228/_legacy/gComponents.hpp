#ifndef G_COMPONENTS_HPP
#define G_COMPONENTS_HPP

#include "entitycomp.hpp"
#include "SFML\Graphics.hpp"

namespace g_core {


	//struct CPosition : public g_core::Component
	//{
	//	sf::Vector2f position;

	//	CPosition() = default;
	//	CPosition(const sf::Vector2f& mPosition) : position{ mPosition } {}

	//	float x() const noexcept { return position.x; }
	//	float y() const noexcept { return position.y; }
	//};


	//// An entity can have a circular shape.
	//struct CCircle : public g_core::Component
	//{
	//	CPosition* cPosition{ nullptr };
	//	sf::CircleShape shape;
	//	float radius;

	//	CCircle( float mRadius) : radius{ mRadius } {}

	//	void init() override
	//	{
	//		cPosition = &entity->getComponent<CPosition>();

	//		shape.setRadius(radius);
	//		shape.setFillColor(sf::Color::Red);
	//		shape.setOrigin(radius, radius);
	//	}

	//	void update(float mFT) override
	//	{
	//		// The shape will automatically get its position from
	//		// `CPosition`.
	//		shape.setPosition(cPosition->position);
	//	}

	//	void draw(sf::RenderWindow& target) override
	//	{
	//		target.draw(shape);
	//	};
	//};


	//// An entity can have a circular shape.
	//struct CHex : public g_core::Component
	//{
	//	CPosition* cPosition{ nullptr };
	//	DataManager* data;
	//	sf::Sprite hexSprite;
	//	float radius;
	//	bool isMousedOver{ false };

	//	CHex(DataManager* data) : data(data) {}

	//	void init() override
	//	{
	//		cPosition = &entity->getComponent<CPosition>();

	//		// create an empty shape
	//		hexSprite.setTexture(data->find_texture("hex.png"));

	//	}

	//	void update(float mFT) override
	//	{
	//		// The shape will automatically get its position from
	//		// `CPosition`.
	//		hexSprite.setPosition(cPosition->position);

	//		if (isMousedOver)
	//			hexSprite.setTexture(data->find_texture("hex.png"));
	//		else
	//			hexSprite.setTexture(data->find_texture("shex.png"));
	//	}

	//	void draw(sf::RenderWindow& target) override
	//	{
	//		target.draw(hexSprite);
	//	};
	//};

	//struct CPhysics : public g_core::Component
	//{
	//	CPosition* cPosition{ nullptr };
	//	sf::Vector2f velocity, halfSize;

	//	// We will use a callback to handle the "out of bounds" event.
	//	std::function<void(const sf::Vector2f&)> onOutOfBounds;

	//	CPhysics(const sf::Vector2f& mHalfSize) : halfSize{ mHalfSize }{}

	//	void init() override
	//	{
	//		// A requirement for `CPhysics` is obviously `CPosition`.
	//		cPosition = &entity->getComponent<CPosition>();

	//	}

	//	void update(float mFT) override
	//	{
	//		cPosition->position += velocity * mFT;

	//		if (onOutOfBounds == nullptr) return;

	//		if (left() < 0)
	//			onOutOfBounds(sf::Vector2f{ 1.f, 0.f });
	//		else if (right() > 1920)
	//			onOutOfBounds(sf::Vector2f{ -1.f, 0.f });

	//		if (top() < 0)
	//			onOutOfBounds(sf::Vector2f{ 0.f, 1.f });
	//		else if (bottom() > 1080)
	//			onOutOfBounds(sf::Vector2f{ 0.f, -1.f });
	//	}

	//	float x() const noexcept { return cPosition->x(); }
	//	float y() const noexcept { return cPosition->y(); }
	//	float left() const noexcept { return x() - halfSize.x; }
	//	float right() const noexcept { return x() + halfSize.x; }
	//	float top() const noexcept { return y() - halfSize.y; }
	//	float bottom() const noexcept { return y() + halfSize.y; }
	//};


	////Handle keyboard input for character
	//struct CControl : public g_core::Component
	//{
	//	CPhysics* cPhysics{ nullptr };

	//	void init() override { cPhysics = &entity->getComponent<CPhysics>(); }

	//	void update(float mFT)
	//	{
	//		cPhysics->velocity.x = 0;
	//		cPhysics->velocity.y = 0;

	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	//		{
	//			cPhysics->velocity.x = -100.f;
	//		}

	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	//			cPhysics->velocity.x = 100.f;

	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	//			cPhysics->velocity.y = -100.f;

	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	//			cPhysics->velocity.y = 100.f;
	//	}

	//};

}
#endif //G_COMPONENTS_HPP