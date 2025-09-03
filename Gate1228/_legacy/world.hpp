#ifndef WORLD_HPP
#define WORLD_HPP

#include "SFML\Graphics.hpp"
#include <sstream>
#include <vector>
#include "hex.hpp"

// Class:World
// an instance of the game world containing:
//		* World terrain map grid
//		* Entities in the world and their location
// @method World init() creates a new world based on predefined settings
// @method World load(isstream FileName) loads a saved world from a datafile
// @method File save() compresses current world data into a file
// s = -q - r

const int mapSizeX{10};
const int mapSizeY{10};


typedef std::vector<std::vector<hexl::Hex>> hexmap;

class World
{
public:
	World()
	{

	}

	~World()
	{
	}

private:	
	hexmap map_;	

public:
	void init();

	static void load(std::istream filename);

	static void save(std::ostream filename);

	hexl::Hex& get_hex_by_axial(int q, int r);

	hexl::Hex& get_hex_by_index(int x, int y);

	void set_hex(int q, int r);

	int get_world_x(){ return mapSizeX; }
	int get_world_y() { return mapSizeY; }

	hexl::Point flat_hex_to_pixel(hexl::Hex& hex) const;
};




#endif // !WORLD_HPP
