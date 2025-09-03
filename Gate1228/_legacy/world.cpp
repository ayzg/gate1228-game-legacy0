#include "world.hpp"

void World::init()
{
	
	//Rectangular map
	//For every horizontal unit
	for (auto x = 0; x != mapSizeX; x++)
	{
		//create collumn
		map_.push_back(std::vector<hexl::Hex>());
		//For every vertical unit
		for (int y = 0; y != mapSizeX; y++)
		{
			// [r][q + floor(r / 2)]
			const int ycoord = y + (-floor(x/ 2));
			const int scoord = -x - ycoord;

			map_[x].emplace_back(x, ycoord, scoord);
		}
	}

}

void World::load(std::istream filename)
{

}

void World::save(std::ostream filename)
{
}

hexl::Hex& World::get_hex_by_axial(int q, int r)
{
	return map_[r][q + floor(r / 2)];
}

hexl::Hex& World::get_hex_by_index(int x, int y)
{
	return map_[x][y];
}


hexl::Point World::flat_hex_to_pixel(hexl::Hex& hex) const
{
	int x = 49 * (3. / 2 * hex.q);
	int y = 58 * (sqrt(3) / 2 * hex.q + sqrt(3) * hex.r);
	return hexl::Point(x, y);
}

void World::set_hex(int q, int r)
{

}