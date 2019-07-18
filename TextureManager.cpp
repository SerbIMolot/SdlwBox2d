#include "stdafx.h"




TextureManager* TextureManager::tmInstance = nullptr;
std::map<std::string, std::shared_ptr<Texture>> TextureManager::Textures;


void TextureManager::loadTextures() {
	addTexture("Data/box.jpg");
	addTexture("Data/wall.png");
}


TextureManager::TextureManager() {

}


TextureManager::~TextureManager() {
	Close("all");
	delete tmInstance;
}

void TextureManager::addTexture(const char * path) {
	std::string temp = path;

	std::string fileName;

	if ( temp.find_last_of("/") == -1 ) 
	{
		fileName = temp;
	}

	fileName = temp.substr(temp.find_last_of("/") + 1, temp.size());

	int i = 0;
	for (auto k : Textures)
	{
		if (k.first == fileName)
		{
			i++;
		}
	}
	if (i != 0) {
		fileName += std::to_string(i);
	}
	
	printf( "Texture : %s\n", fileName.c_str() );
	Textures[fileName] = std::make_shared<Texture>();
 	Textures[fileName]->loadFromFile(path);
}



TextureManager* TextureManager::Initialize() {
	if (tmInstance == nullptr) {

		tmInstance = new TextureManager();
		tmInstance->loadTextures();

	}
	return tmInstance;
}

void TextureManager::Close(std::string fileName) {

	if (fileName == "all") {

		Textures.clear();
	}

	for (auto t : Textures) {
		if (t.first == fileName) {


			Textures.erase(fileName);

			break;
		}
	}

}

std::shared_ptr<Texture> TextureManager::getTexture(const char * fileName) {
	if (Textures.find(fileName) == Textures.end()) {
		std::cout << "Could not find texture " << fileName << std::endl;
		return nullptr;
	}
	else {
		return Textures[fileName];
	}
}


