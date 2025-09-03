#ifndef GATE_COMPONENTS_HPP
#define GATE_COMPONENTS_HPP

#pragma region PositionHandlers
#include <wincrypt.h>

class cPos 
{
private:
	sf::Vector2u position;
public:
//constructors
	cPos()
	{
		position.x = 0;
		position.y = 0;
	}

	cPos(const unsigned& x, const unsigned& y)
	{
		position.x = x;
		position.y = y;
	}

	explicit cPos(const sf::Vector2u unsig_vector)
	{
		position = unsig_vector;
	}
//view
	unsigned			x() const						{ return position.x; }
	unsigned			y() const						{ return position.y; }
//modfiy
	sf::Vector2u&		expose()						{ return position; }
	void				setx(const unsigned ui_value)	{ position.x = ui_value; }
	void				sety(const unsigned ui_value)   { position.y = ui_value; }

	void bumpx(const int amount)			
	{
		if (UINT_MAX - position.x < amount) 
			position.x = 0;
		else	
			position.x += amount;
	}

	void bumpy(const int amount)			
	{
		if (UINT_MAX - position.x < amount)
			position.x = 0;
		else
			position.x += amount;
	}
};

#pragma endregion


#endif // GATE_COMPONENTS_HPP
