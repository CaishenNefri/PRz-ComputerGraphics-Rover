#include "Rover.h"
#include <array>


Rover::Rover()
{
	amountWheels = 3;
	sizeWheel = 10;
	depthWheel = 10;
	width = 100;
	heigth = 30;
	depth = 60;




	wheelL1 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x] - width / 2, pos[Param::y] - heigth / 2, pos[Param::x] + depth / 2);

	wheelR1 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x] - width / 2, pos[Param::y] - heigth / 2, pos[Param::x] - depth / 2);

	wheelL2 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x], pos[Param::y] - heigth / 2, pos[Param::x] + depth / 2);

	wheelR2 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x], pos[Param::y] - heigth / 2, pos[Param::x] - depth / 2);

	wheelL3 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x] + width / 2, pos[Param::y] - heigth / 2, pos[Param::x] + depth / 2);

	wheelR3 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x] + width / 2, pos[Param::y] - heigth / 2, pos[Param::x] - depth / 2);

	body = new Body(width, heigth, depth, pos[Param::x], pos[Param::y], pos[Param::z]);
}


Rover::~Rover()
{
}

void Rover::draw()
{
	wheelL1->draw();
	wheelL2->draw();
	wheelL3->draw();
	wheelR1->draw();
	wheelR2->draw();
	wheelR3->draw();

	body->draw();
	
}
