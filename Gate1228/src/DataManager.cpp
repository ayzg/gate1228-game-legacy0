//G_DATA
#include "../engine/data/DataManager.hpp"

// DataManager : Constructor : DataManager()
// define string path for all textures, sounds and data; relative to sourceFolder.
// maintain clean names with underscores between words, no filename should be duplicate.
DataManager::DataManager()
{
	//Load necessary game files here.
	/** Textures **/
		/** Characters **/
		textures_["images/chars/warrior.png"];
		textures_["images/hex.png"];
		textures_["images/shex.png"];

	/** Sounds **/
		sounds_["audio/whoo.wav"];

}

// DataManager : Destructor : ~DataManager()
DataManager::~DataManager()
= default;

// DataManager : Public method : void load(std::string sourceFolder)
// @param takes [in] a string path source folder for the manager to load
void DataManager::load(const std::string& source_folder)
{
	//For each predefined string path in textures_
	for (auto it(textures_.begin()); it != textures_.end(); ++it)
	{
		//Append string path to sourceFolder string
		//Load texture from new path into current key
		it->second.loadFromFile(source_folder + it->first);
	}
		

	//For each predefined string path in sounds_
	for (auto it(sounds_.begin()); it != sounds_.end(); ++it)
	{
		//Append string path to sourceFolder string
		//Load sound from new path into current key
		it->second.loadFromFile(source_folder + it->first);
	}
}

// DataManager : Public method : sf::Texture& DataManager::findTexture(std::string name)
// @param takes [in] a substring to find in textures_ string path key
// @return a sfml Texture object by reference
sf::Texture& DataManager::find_texture(const std::string& name)
{

	for (auto it(textures_.begin()); it != textures_.end(); ++it)
	{
		// If name is substring of key
		if (it->first.find(name) != std::string::npos)
		{
			if (it->second.getSize() != sf::Vector2u(0, 0))
			{
				return it->second; //Return accossiated texture
			}
			else
			{
				auto error_msg = "DataManager: Texture file " + name + " is empty.";
				throw std::exception(error_msg.c_str());
			}
		}
	}

	auto error_msg = "DataManager: Texture " + name + " not found.";
	throw std::exception(error_msg.c_str());
};

// DataManager : Public method : sf::SoundBuffer& DataManager::findSound(std::string name)
// @param takes [in] a substring to find in sounds_ string path key
// @return a sfml SoundBuffer object by reference
sf::SoundBuffer& DataManager::find_sound(const std::string& name)
{

	for (auto it(sounds_.begin()); it != sounds_.end(); ++it)
	{
		// If name is substring of key
		if (it->first.find(name) != std::string::npos)
		{
			if (it->second.getDuration() != sf::Time())
			{
				return it->second; 
			}
			else
			{
				auto error_msg = "DataManager: Sound file " + name + " is empty.";
				throw std::exception(error_msg.c_str());
			}
		}
	}

	auto error_msg = "DataManager: Sound " + name + " not found.";
	throw std::exception(error_msg.c_str());
};

