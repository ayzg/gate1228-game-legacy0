#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP

//STL
#include <vector>
#include <memory>
#include <map>

//SFML
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include "../../core/strictSingleton.hpp"


// Class:DataManager
// holds and loads textures, sounds and datafiles for future use
// @method load() takes [in] a string path, loads files based on map keys
//
// @method findTexture() take [in] a substring to be found in textures_ keys
//			and returns [out] a texture
// @method findSound() take [in] a substring to be found in sounds_ keys
//			and returns [out] a sound buffer

class DataManager : StrictSingleton<DataManager>
{
	//types
	using texture_map = std::map<std::string, sf::Texture>;
	using sound_map = std::map<std::string, sf::SoundBuffer>;
private:
	texture_map textures_;
	sound_map sounds_;

public:
	DataManager();
	~DataManager();

	void load(const std::string& source_folder);

	sf::Texture& find_texture(const std::string& name);
	sf::SoundBuffer& find_sound(const std::string& name);

	const texture_map& textures() const { return textures_; }
	const sound_map& sounds() const { return sounds_; }
	
};

#endif // !DATA_MANAGER_HPP
