#include "Collision.h"


Collision::Collision()
{
	offsetX = 0;
	offsetY = 0;
	SetRectangle(0, 0, 0, 0);
}
 
Collision::Collision(int x, int y, int w, int h)
{
	offsetX = x;
	offsetY = y;
	SetRectangle(0,0,w,h);
}


Collision::~Collision()
{
}

void Collision::SetRectangle(int x, int y, int w, int h)
{
	CollisionRect.x = x+offsetX;
	CollisionRect.y = y+offsetY;
	CollisionRect.w = w;
	CollisionRect.h = h;
}