#ifndef ANIMATION_HPP
#define ANIMATION_HPP

//
//#include <SFML\Graphics.hpp>
//
//class Animation
//{
//	//type
//	using dimension		= sf::Vector2i;
//	//data
//	struct Frame
//	{
//		/* frame location relative to animation a sprite_sheet */
//		sf::Vector2i loc; 
//		sf::Vector2i size;
//
//		/* returns the rectangle of a frame within its sprite sheet*/
//		sf::IntRect get() const
//		{
//			return sf::IntRect(loc.x * size.x,loc.y * size.y,
//								size.x,size.y);
//		}
//	};
//
//private:
//	sf::Sprite			sprite_;
//	sf::Texture			sprite_sheet_;
//	std::vector<Frame>	frames_;
//
//	dimension			size_;
//	dimension			frame_count_;
//	dimension			frame_current_;
//
//
////access
//public:
//	const sf::Sprite& sprite() const { return sprite_; }
//	void nextFrame()
//	{
//		//If not at the end of row, move left (most common)
//		if (!frame_current_.x >= frame_count_.x)
//			frame_iter_.left
//		else
//			frame_iter_.left += 300;
//
//		sprite_.setTextureRect(frame_iter_);
//	};
//	void prevFrame();
//
//
//	
//public:
//	Animation(sf::Texture source_texture, sf::Vector2i sprite_size);
//	~Animation();
//private:
//	
//
//};
//
#endif // !ANIMATION_HPP
