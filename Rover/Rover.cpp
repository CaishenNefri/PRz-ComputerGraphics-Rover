#include "Rover.h"
#include <array>


Rover::Rover()
{
	int scale = 20;

	amountWheels = 3;
	sizeWheel = 20 / scale;
	depthWheel = 10 / scale;
	width = 100 / scale;
	heigth = 30 / scale;
	depth = 60 / scale;




	wheelL1 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x] - width / 2, pos[Param::y] - heigth / 2, pos[Param::z] + depth);

	wheelL2 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x], pos[Param::y] - heigth / 2, pos[Param::z] + depth);

	wheelL3 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x] + width / 2, pos[Param::y] - heigth / 2, pos[Param::z] + depth);

	wheelR1 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x] - width / 2, pos[Param::y] - heigth / 2, pos[Param::z] - depth);

	wheelR2 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x], pos[Param::y] - heigth / 2, pos[Param::z] - depth);

	wheelR3 = new Wheel(sizeWheel, depthWheel,
		pos[Param::x] + width / 2, pos[Param::y] - heigth / 2, pos[Param::z] - depth);

	suspensionL1 = new Wheel(sizeWheel / 2, depth / 2,
		pos[Param::x] - width / 2, pos[Param::y] - heigth / 2, pos[Param::z] + depth / 1.5);
	suspensionL2 = new Wheel(sizeWheel / 2, depth / 2,
		pos[Param::x], pos[Param::y] - heigth / 2, pos[Param::z] + depth / 1.5);
	suspensionL3 = new Wheel(sizeWheel / 2, depth / 2,
		pos[Param::x] + width / 2, pos[Param::y] - heigth / 2, pos[Param::z] + depth / 1.5);

	suspensionR1 = new Wheel(sizeWheel / 2, depth / 2,
		pos[Param::x] - width / 2, pos[Param::y] - heigth / 2, pos[Param::z] - depth / 1.5);
	suspensionR2 = new Wheel(sizeWheel / 2, depth / 2,
		pos[Param::x], pos[Param::y] - heigth / 2, pos[Param::z] - depth / 1.5);
	suspensionR3 = new Wheel(sizeWheel / 2, depth / 2,
		pos[Param::x] + width / 2, pos[Param::y] - heigth / 2, pos[Param::z] - depth / 1.5);

	body = new Body(width, heigth, depth, pos[Param::x], pos[Param::y], pos[Param::z]);

	spoilerLeft = new Body(width/16, heigth, depth/8,
		pos[Param::x] + width / 2.5, pos[Param::y] + heigth , pos[Param::z] + depth / 2);
	spoilerRight = new Body(width / 16, heigth, depth / 8,
		pos[Param::x] + width / 2.5, pos[Param::y] + heigth, pos[Param::z] - depth / 2);
	spoilerTop1 = new Body(width/16, heigth/8, depth + depth/3,
		pos[Param::x] + width / 2.5, pos[Param::y] + heigth, pos[Param::z]);
	spoilerTop2 = new Body(width / 16, heigth / 8, depth + depth / 3,
		pos[Param::x] + width / 2.5, pos[Param::y] + heigth*1.5, pos[Param::z]);

	GLdouble aerialWD = 3 / scale;
	GLdouble aerialH = 50 / scale;
	aerial1 = new Body(aerialWD, aerialH, aerialWD,
		pos[Param::x] - width / 2.5, pos[Param::y] + heigth/2 + aerialH/2, pos[Param::z]);
	aerial2 = new Body(aerialWD, aerialH*1.5, aerialWD,
		pos[Param::x] - width / 2.5, pos[Param::y] + heigth / 2 + aerialH*1.5 / 2, pos[Param::z]+depth/2.5);
	aerial3 = new Body(aerialWD, aerialH*1.5, aerialWD,
		pos[Param::x] - width / 2.5, pos[Param::y] + heigth / 2 + aerialH*1.5 / 2, pos[Param::z]-depth/2.5);

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

	suspensionL1->color[Color::r] = 1;
	suspensionL1->color[Color::g] = 1;
	suspensionL1->color[Color::b] = 1;

	suspensionL2->color[Color::r] = 1;
	suspensionL2->color[Color::g] = 1;
	suspensionL2->color[Color::b] = 1;

	suspensionL3->color[Color::r] = 1;
	suspensionL3->color[Color::g] = 1;
	suspensionL3->color[Color::b] = 1;

	suspensionR1->color[Color::r] = 1;
	suspensionR1->color[Color::g] = 1;
	suspensionR1->color[Color::b] = 1;
			  
	suspensionR2->color[Color::r] = 1;
	suspensionR2->color[Color::g] = 1;
	suspensionR2->color[Color::b] = 1;
			  
	suspensionR3->color[Color::r] = 1;
	suspensionR3->color[Color::g] = 1;
	suspensionR3->color[Color::b] = 1;

	suspensionL1->draw();
	suspensionL2->draw();
	suspensionL3->draw();
	suspensionR1->draw();
	suspensionR2->draw();
	suspensionR3->draw();

	body->draw();

	spoilerLeft->color[Color::r] = 0;
	spoilerLeft->color[Color::b] = 1;
	spoilerLeft->draw();

	spoilerRight->color[Color::r] = 0;
	spoilerRight->color[Color::b] = 1;
	spoilerRight->draw();

	spoilerTop1->color[Color::r] = 0;
	spoilerTop1->color[Color::b] = 1;
	spoilerTop1->draw();

	spoilerTop2->color[Color::r] = 0;
	spoilerTop2->color[Color::b] = 1;
	spoilerTop2->draw();

	aerial1->color[Color::r] = 0;
	aerial1->color[Color::g] = 1;
	aerial1->draw();

	aerial2->color[Color::r] = 0;
	aerial2->color[Color::g] = 1;
	aerial2->draw();

	aerial3->color[Color::r] = 1;
	aerial3->color[Color::g] = 1;
	aerial3->draw();
	
}
