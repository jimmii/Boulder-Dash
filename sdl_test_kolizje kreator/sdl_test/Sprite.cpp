#include"Global_headers.h"
#include "Sprite.h"


Sprite::Sprite(SDL_Renderer *przekazywany_renderer, std::string File_Path, int x, int y, int w, int h, Collision passed_collisionRectangle):
	sprite_renderer(przekazywany_renderer)
{
	collisionRect = passed_collisionRectangle;
	
	_image = IMG_LoadTexture(sprite_renderer, File_Path.c_str());
	if (_image == NULL)
	{																					
		std::cerr << "Failed to load "<<File_Path.c_str() << SDL_GetError() <<std::endl;
	}
	
	collisionimage = IMG_LoadTexture(sprite_renderer,"img/Enviroment/kolizje.png");
	if (collisionimage == NULL)
	{																					
		std::cerr << "Failed to load " << File_Path.c_str() << SDL_GetError() << std::endl;
	}
	//end tmp

	_rect.x = x;
	_rect.y = y;																	
	_rect.w = w;
	_rect.h = h;

	SDL_QueryTexture(_image, NULL, NULL, &img_width, &img_height);

	_crop.x = 0;
	_crop.y = 0;
	_crop.w=img_width;
	_crop.h = img_height;

	currentFrame = 0;
	Amount_Frame_X = 0;
	Amount_Frame_Y = 0;
	
}


Sprite::~Sprite()
{
	SDL_DestroyTexture(_image);
	_image = NULL;
	SDL_DestroyTexture(collisionimage);
	collisionimage = NULL;
	SDL_DestroyRenderer(sprite_renderer);
	sprite_renderer = NULL;
	
}

void Sprite::SetUpAnimation(int passed_Amount_X, int passed_amount_Y)
{
	Amount_Frame_X = passed_Amount_X;
	Amount_Frame_Y = passed_amount_Y;
}

void Sprite::PlayAnimation(int beginFrame, int endFrame, int row, float speed)
{
	if (animationDelay + speed < SDL_GetTicks())
	{
		if (endFrame <= currentFrame)
			currentFrame = beginFrame;
		else
			currentFrame++;

		_crop.x = currentFrame*(img_width / Amount_Frame_X);
		_crop.y = row*(img_height / Amount_Frame_Y);
		_crop.w = img_width / Amount_Frame_X;
		_crop.h = img_height / Amount_Frame_Y;
		
		animationDelay = SDL_GetTicks();
	}
}


void Sprite::draw()
{
	
		collisionRect.setXRectangle(_rect.x);
		collisionRect.setYRectangle(_rect.y);
	
	SDL_RenderCopy(sprite_renderer, _image, &_crop, &_rect);

	SDL_RenderCopy(sprite_renderer, collisionimage, NULL, &collisionRect.GetRectangle());//kolizje pogladowe wyswietlenie rect
}

void Sprite::SetX(int X)
{
	_rect.x = X;
}

void Sprite::SetY(int Y)
{
	_rect.y = Y;
}

void Sprite::SetPosition(int X, int Y)
{
	_rect.x = X;
	_rect.y = Y;
}

int Sprite::GetX()
{
	return _rect.x;
}

int Sprite::GetY()
{
	return _rect.y;
}

bool Sprite::isColliding(Collision Collider)
{
	return !(collisionRect.GetRectangle().x + collisionRect.GetRectangle().w < Collider.GetRectangle().x || collisionRect.GetRectangle().y + collisionRect.GetRectangle().h < Collider.GetRectangle().y || collisionRect.GetRectangle().x > Collider.GetRectangle().x + Collider.GetRectangle().w || collisionRect.GetRectangle().y > Collider.GetRectangle().y + Collider.GetRectangle().h);
}