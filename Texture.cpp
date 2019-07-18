#include "stdafx.h"



Texture::Texture()
{
	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;
}


Texture::~Texture()
{
	free();
}

bool Texture::loadFromFile(std::string path )
{
	
	//Delete pre existing texture
	free();

	SDL_Texture* newTexture = NULL;

	//Load image at path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_Image error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{

		newTexture =  SDL_CreateTextureFromSurface(SDL_wrapper::gRenderer, loadedSurface);


		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error; %s\n", path.c_str(), SDL_GetError());

		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;

		}

		SDL_FreeSurface(loadedSurface);

	}

	mTexture = newTexture;

	return mTexture != NULL;
}

bool Texture::loadFromFile( std::string path, SDL_Color colorKey )
{
	//Delete pre existing texture
	free();

	SDL_Texture* newTexture = NULL;

	//Load image at path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if (loadedSurface == NULL) 
	{
		printf( "Unable to load image %s! SDL_Image error: %s\n", path.c_str(), IMG_GetError() );
	} else
	{

		if ( SDL_SetColorKey( loadedSurface, SDL_TRUE, 
							  SDL_MapRGB( loadedSurface->format, colorKey.r, colorKey.g, colorKey.b ) < 0 ) )
		{
			printf("Unable to ser colorKey for %s! SDL Error error: %s\n", path.c_str(), SDL_GetError());
		}

		newTexture = SDL_CreateTextureFromSurface( SDL_wrapper::gRenderer, loadedSurface );


		if ( newTexture == NULL ) 
		{
			printf( "Unable to create texture from %s! SDL Error; %s\n", path.c_str(), SDL_GetError() );
		
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		
		}

		SDL_FreeSurface( loadedSurface );

	}

	mTexture = newTexture;

	return mTexture != NULL;
}

void Texture::free()
{
	if ( mTexture != NULL || mTexture != nullptr ) 
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}

}


void Texture::render( int x, int y, SDL_Rect * clip, float angle, SDL_Point * center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if ( clip != nullptr )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;

	}
	
	//Render to screen
	SDL_RenderCopyEx( SDL_wrapper::gRenderer, mTexture , clip, &renderQuad, angle, center, flip );

}

void Texture::render(float x, float y, SDL_Rect * clip, float angle, SDL_Point * center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { static_cast< int >( x ), static_cast< int >( y ), static_cast< int >( mWidth ), static_cast< int >( mHeight ) };

	//Set clip rendering dimensions
	if (clip != nullptr)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;

	}

	//Render to screen
	SDL_RenderCopyEx(SDL_wrapper::gRenderer, mTexture, clip, &renderQuad, angle, center, flip);

}

void Texture::render(b2Vec2 vec, SDL_Rect * clip, float angle, SDL_Point * center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { static_cast<int>( vec.x ), static_cast<int>( vec.y ), mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != nullptr)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;

	}

	//Render to screen
	SDL_RenderCopyEx( SDL_wrapper::gRenderer, mTexture, clip, &renderQuad, static_cast< double >( angle ), center, flip);

}

void Texture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture
	SDL_SetTextureColorMod( mTexture, red, green, blue );

}

void Texture::setBlendMode( SDL_BlendMode blending )
{
	SDL_SetTextureBlendMode( mTexture, blending );
}

void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

int Texture::getWidth()
{
	return mWidth;
}

int Texture::getHeight()
{
	return mHeight;
}
