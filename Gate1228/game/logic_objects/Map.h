#ifndef MAP_H
#define MAP_H
#include <array>
#include <vector>

#include "../../_external/pugi_xml/pugixml.hpp"


enum sprite_id 
{
	grass, dirt, water
};

struct TileLayer
{
	int id;
	int objectid;
};

struct Tile
{
	int id;
	int spriteid;
	std::vector<TileLayer> layers;
};

using vectormap3_d = std::vector<std::vector<Tile>>;


/*
 * @class: Map
 * @purpose: a three dimensional tilemap stored in a vector
 */
class Map
{	
private:
	unsigned int width_;
	unsigned int length_;
	unsigned int height_;

public:
	vectormap3_d tilemap{ width_,std::vector<Tile>(length_) };

	unsigned int width() const { return width_; }
	unsigned int length() const { return length_; }
	unsigned int height() const { return height_; }

	Map(const int width, const int length) : width_(width), length_(length)
	{
		//fill availible tiles with

	}

	bool add(Tile newtile)
	{
		bool isAdd = false;

		while (!isAdd)
		{
			//Y-Axis equals tile id divided by width_
			int const yaxis = newtile.id/width_;

			//Create tile iterator at y axes
			std::vector<Tile>::iterator tileit 
								= tilemap[yaxis].begin();

			//Advance to proper x axes 
			std::advance(tileit, newtile.id - (10 * yaxis));

			//emplace tile
			tilemap[yaxis].insert(tileit, newtile);

			isAdd = true;
		}
		return isAdd;
	}
	
};



/*
 * @class: MapLoader
 * @purpose: parse tiled xml file or .map format
 */
class MapLoader
{
public:
	static Map load(const char* filename)
	{
		pugi::xml_document doc;

		doc.load_file(filename);

		pugi::xml_node srcmap = doc.document_element();

		Map newmap(srcmap.attribute("width").as_int(),srcmap.attribute("height").as_int());

		//for each layer [0 -> MAX_LAYERS]
			//parse in tile objects
			for (pugi::xml_node tile : srcmap.children())
			{
				//Create Tile 
				Tile newtile;
				
				//Get base tile values
				newtile.id = tile.attribute("id").as_int();
				newtile.spriteid = tile.attribute("spriteid").as_int();

				//for each layer
				for(pugi::xml_node tilelayer : tile.children())
				{
					//Create tilelayer
					TileLayer newtilelayer;

					//Get values
					newtilelayer.id = tilelayer.attribute("id").as_int();
					newtilelayer.objectid = tilelayer.attribute("objectid").as_int();

					//Add to new tile
					newtile.layers.emplace_back(newtilelayer);
				}

				//Add tile to map
				newmap.add(newtile);
			}
		return newmap;
	}
};


/*
 * @class: MapSaver
 * @purpose: save map to .map format
 */
class MapSaver
{
public:
	static bool save(Map amap, const char* name)
	{
		pugi::xml_document doc;

		pugi::xml_node xmlmap = doc.append_child("map");

		xmlmap.append_attribute("width");

		xmlmap.append_attribute("length");

		for (auto row : amap.tilemap)
		{
			for (Tile tile : row)
			{
				pugi::xml_node tilenode = xmlmap.append_child("tile");
				tilenode.append_attribute("id") = tile.id;
				tilenode.append_attribute("spriteid") = tile.spriteid;

				for (TileLayer tlayer : tile.layers)
				{
					pugi::xml_node tlayernode = tilenode.append_child("tilelayer");
					tlayernode.set_name("tilelayer");
					tlayernode.append_attribute("id") = tlayer.id;
					tlayernode.append_attribute("objectid") = tlayer.objectid;
				}
			}
		}
		return doc.save_file(name);
	}
 };








#endif