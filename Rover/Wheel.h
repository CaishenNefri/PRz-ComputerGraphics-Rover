#include "Part.h"

class Wheel :
	public Part
{
public:
	Wheel(GLdouble radius, GLdouble depth,
		GLdouble bX = 0, GLdouble bY = 0, GLdouble bZ = 0);
	~Wheel();

	void draw();

protected:
	GLdouble radius, depth;
};
