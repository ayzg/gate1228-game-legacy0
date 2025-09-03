#include "../engine/graphics/Animation.hpp"
//
//
//Animation::Animation(sf::Texture sourceTexture, sf::Vector2i spriteSize)
//	: sprite_sheet_(sourceTexture), size_(spriteSize)
//{
//	//Assume equal frame size
//	frame_count_.x = sprite_sheet_.getSize().x / size_.x;
//	frame_count_.y = sprite_sheet_.getSize().y / size_.y;
//
//	//Initial Frame
//	frame_current_.x = 0;
//	frame_current_.y = 0;
//
//	//Frame iterator
//	frame_iter_ = sf::IntRect(frame_current_,size_);
//
//	//Set source texture
//	sprite_.setTexture(sprite_sheet_);
//	
//	//Set
//	sprite_.setTextureRect(frame_iter_);
//}
//
//
//Animation::~Animation()
//{
//}
