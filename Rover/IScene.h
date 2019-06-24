#pragma once
#include "InputManager.h"
#include "Entity.h"
#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include "RoverX.h"

class IScene : public Entity
{
public:
	InputManager& inputManager = InputManager::GetInstance();

	// Rotation amounts
	// Rotate around 0,0,0
	GLfloat xRot = 0.0f;
	GLfloat yRot = 0.0f;
	GLfloat zRot = 0.0f;
	RoverX *rover;

	IScene()
	{
		rover = new RoverX();
	}

	virtual ~IScene() = default;
	void Init() override
	{
		
	}

	void RenderScene()
	{
		// Clear the window with current clearing color
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		// Enable rotate view | deprecatedd
		glRotatef(xRot, 1.0f, 0.0f, 0.0f);
		glRotatef(yRot, 0.0f, 1.0f, 0.0f);
		glRotatef(zRot, 0.0f, 0.0f, 1.0f);



		glPolygonMode(GL_FRONT_FACE, GLU_FILL);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		//szescian();
		rover->draw();

		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glFlush(); // Flush drawing commands
	}

	void Update(float frameTime)
	{
		this->UpdateInputs();

		// Rotate around 0,0,0
		this->xRot = (const int)this->xRot % 360;
		this->yRot = (const int)this->yRot % 360;
		this->zRot = (const int)this->zRot % 360;
	}


	void szescian(void)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		{
			// Parametry wierzcholkow

			GLfloat sa[3] = { 0.0f,0.0f,0.0f };
			GLfloat sb[3] = { 10.0f,0.0f,0.0f };
			GLfloat sc[3] = { 10.0f,10.0f,0.0f };
			GLfloat sd[3] = { 0.0f,10.0f,0.0f };
			GLfloat se[3] = { 0.0f,0.0f,-10.0f };
			GLfloat sf[3] = { 10.0f,0.0f,-10.0f };
			GLfloat sg[3] = { 10.0f,10.0f,-10.0f };
			GLfloat sh[3] = { 0.0f,10.0f,-10.0f };

			////przesuniecie do gory o dlugsc krawedzi
			GLfloat da[3] = { 0.0f,0.0f,10.0f };
			GLfloat db[3] = { 10.0f,0.0f,10.0f };
			GLfloat dc[3] = { 10.0f,10.0f,10.0f };
			GLfloat dd[3] = { 0.0f,10.0f,10.0f };

			////zadanie druie. Przesuniecie w plaszczyznie xy
			//GLfloat da[3] = { 10.0f,0.0f,0.0f };
			//GLfloat db[3] = { 20.0f,0.0f,0.0f };
			//GLfloat dc[3] = { 20.0f,10.0f,0.0f };
			//GLfloat dd[3] = { 10.0f,10.0f,0.0f };

			////Gorna sciana pod katem ale inne dlugosci
			/*float h = 10 * sin(param * M_PI / 180);
			float a = 10 * cos(param * M_PI / 180);
			GLfloat da[3] = { 10-a,0.0f,h };
			GLfloat db[3] = { 10.0f,0.0f,0.0f };
			GLfloat dc[3] = { 10.0f,10.0f,0.0f };
			GLfloat dd[3] = { 10 - a,10.0f,h};*/

			////Zadanie4
			////Obrocenie pokrywy kwadratu
			//float result = 10 * sin(45 * M_PI / 180);
			//GLfloat da[3] = { 10.0f - result, result,0.0f };
			//GLfloat db[3] = { 10.0f,0.0f,0.0f };
			//GLfloat dc[3] = { 10.0f + result,result,0.0f };
			//GLfloat dd[3] = { 10.0f, 2*result,0.0f };


			// Sciany skladowe
			glColor3f(1.0f, 0.0f, 0.0f);
			glBegin(GL_POLYGON);
			glVertex3fv(da);
			glVertex3fv(db);
			glVertex3fv(dc);
			glVertex3fv(dd);
			glEnd();

			glColor3f(0.0f, 1.0f, 0.0f);
			glBegin(GL_POLYGON);
			glVertex3fv(sb);
			glVertex3fv(sf);
			glVertex3fv(sg);
			glVertex3fv(sc);
			glEnd();

			glColor3f(0.0f, 0.0f, 1.0f);
			glBegin(GL_POLYGON);
			glVertex3fv(sf);
			glVertex3fv(se);
			glVertex3fv(sh);
			glVertex3fv(sg);
			glEnd();

			glColor3f(1.0f, 1.0f, 0.0f);
			glBegin(GL_POLYGON);
			glVertex3fv(se);
			glVertex3fv(sa);
			glVertex3fv(sd);
			glVertex3fv(sh);
			glEnd();

			glColor3f(0.0f, 1.0f, 1.0f);
			glBegin(GL_POLYGON);
			glVertex3fv(sd);
			glVertex3fv(sc);
			glVertex3fv(sg);
			glVertex3fv(sh);
			glEnd();

			glColor3f(1.0f, 0.0f, 1.0f);
			glBegin(GL_POLYGON);
			glVertex3fv(sa);
			glVertex3fv(sb);
			glVertex3fv(sf);
			glVertex3fv(se);
			glEnd();
		}
	}

	void UpdateInputs()
	{
		// Rotate around 0,0,0
		if (inputManager.IsDown('W'))
			this->xRot -= 5.0f;

		if (inputManager.IsDown('S'))
			this->xRot += 5.0f;

		if (inputManager.IsDown('A'))
			this->yRot -= 5.0f;

		if (inputManager.IsDown('D'))
			this->yRot += 5.0f;

		if (inputManager.IsDown('Q'))
			this->zRot -= 5.0f;

		if (inputManager.IsDown('E'))
			this->zRot += 5.0f;
	}
};