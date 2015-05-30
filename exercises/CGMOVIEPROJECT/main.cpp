//================ Copyright (c) 2015, <Sorin Davidoi>, <Andreea Muscalagiu>, All rights reserved. =================//
//
// <Alien Nightmare>
//
//=============================================================================================================//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>

#include <GLee.h>

#if defined(__APPLE__) || defined(__APPLE_CC__)
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else

# include <GL/glu.h>	// OpenGL Utility header
# include <GL/glut.h>	// GLUT header

#endif

#include <vector>

#include <oogl/gl_error.h>
#include <oogl/timer.h>
#include <oogl/Model.h>

#include "include/Scene.h"
#include "include/CaveScene.h"
#include "include/ChaseScene.h"
#include "include/RoomScene.h"

using namespace AlienNightmare;

struct Camera {
	Position eye, center, up;

	GLfloat speed;

	GLfloat moveX, moveZ;
};

// global variables
Camera camera;

float movieTime = 0.0f;
float delta = 0.0f;
int fps = 0;

int lastFpsUpdate = 0.0f;
int frameCounter = 0;

bool useFreeCamera = true;
bool wireframe = false;
bool culling = false;

std::vector<Scene *> scenes;

/**
* called ONCE after we have a valid window with an opengl context
*/
void init() {
	camera.eye.y = 5;
	camera.eye.z = 30;
	camera.up.y = 1;
	camera.speed = 0.05;

	// you may adapt all this to your needs!
	scenes.push_back(new CaveScene(Position(-16, 0, 0), Size(10, 10, 10)));
	scenes.push_back(new ChaseScene(Position(-5, 0, 0), Size(10, 10, 10)));
	scenes.push_back(new RoomScene(Position(6, 0, 0), Size(10, 10, 10)));

	// enable stuff
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	// wireframe mode
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// shading
	glShadeModel(GL_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// backface culling
	//glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CCW); // default is CounterClockWise

	// "background" color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

/**
* called within display()
*/
void renderScene() {
	//TODO: draw your scenes here
	for (int i = 0; i < scenes.size(); ++i) {
		scenes[i]->render(movieTime);
	}

	// draw stuff! (you may remove or replace this!)
}

/**
* called to create the camera/view matrix
*/
void setupViewMatrix() {
	if (useFreeCamera) {
		//TODO: free camera (view matrix)
		gluLookAt(camera.eye.x, camera.eye.y, camera.eye.z,
		          camera.center.x, camera.center.y, camera.center.z,
		          camera.up.x, camera.up.y, camera.up.z
		);
	}
	else {
		//TODO: animated camera (view matrix)
	}
}

void animatedCameraUpdate(float delta) {
	//TODO: update or animate the variables of your animated camera in here, which then get used in the display() function
}

void freeCameraUpdate(float delta) {
	//TODO: update or animate the variables of your free camera in here, which then get used in the display() function
	camera.eye.x += delta * camera.moveX;
	camera.center.x += delta * camera.moveX;

	camera.eye.z += delta * camera.moveZ;
	camera.center.z += delta * camera.moveZ;
}

/**
 * called just before display(), every frame. 
 */
void update() {
	// curTime is the number of milliseconds since glutInit() was called, it gets bigger and bigger.
	// delta is the number of milliseconds that the last frame, we just rendered, took.
	float curTime = glutGet(GLUT_ELAPSED_TIME);
	delta = curTime - movieTime;
	movieTime = curTime;
	frameCounter++;

	if (movieTime > lastFpsUpdate) {
		lastFpsUpdate = movieTime + 500;
		fps = frameCounter * 2;
		frameCounter = 0;
	}

	// why use delta for animations? because otherwise the speed of the animation is dependent on the framerate.
	// if someone with a better computer or a 144 Hz screen starts this program, we don't want everything to be twice as fast.
	// simply multiply every movement calculation with delta. (e.g. nextPosition = curPosition + velocity * delta)

	// update everything
	if (useFreeCamera) {
		freeCameraUpdate(delta);
	}
	else {
		animatedCameraUpdate(delta);
	}


	// TODO: update your scene logic in here
	for (int i = 0; i < scenes.size(); ++i) {
		scenes[i]->update();
	}

	// force a redisplay
	glutPostRedisplay();
}

/**
* called when a frame should be rendered
*/
void display() {
	// clear color buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// handle wireframe mode
	if (wireframe) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	// handle culling
	if (culling) {
		glEnable(GL_CULL_FACE);
	}
	else {
		glDisable(GL_CULL_FACE);
	}

	// reset model matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// set the camera/view matrix
	setupViewMatrix();

	// after the camera matrix has been set, render the scene
	renderScene();

	// draw info text (you may remove or replace this!)
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	{
		int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
		int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

		// set orthogonal projection for rendering text
		glLoadIdentity();
		gluOrtho2D(0, windowWidth, 0, windowHeight);

		// glutBitmapCharacter() requires the use of glRasterPos to set the position
		int offset = 10;
		glRasterPos2i(offset, windowHeight - 15 - offset);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

		// draw first line
		std::string testString = "Press W to toggle wireframe mode";
		for (int i = 0; i < testString.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, testString[i]);
		}

		// set new offset, draw second line
		glRasterPos2i(offset, windowHeight - 15 * 2 - offset - 7);
		testString = "Press B to toggle backface culling";
		for (int i = 0; i < testString.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, testString[i]);
		}

		// set new offset, draw third line
		glRasterPos2i(offset, windowHeight - 15 * 3 - offset - 7 * 2);
		testString = "Press C to switch between animated/free camera";
		for (int i = 0; i < testString.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, testString[i]);
		}

		// set new offset, draw fourth line
		glRasterPos2i(offset, windowHeight - 15 * 4 - offset - 7 * 3);
		std::stringstream stringStream;
		stringStream << "Frames per second: ";
		stringStream << fps;
		testString = stringStream.str();
		for (int i = 0; i < testString.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, testString[i]);
		}
	}
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW); // reset matrix mode




	// display possible opengl errors and swap front/backbuffer
	LOG_GL_ERRORS();
	glutSwapBuffers();
}

/**
* called when the user presses or releases a mouse key
* @param button which mouse button was pressed, one of GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON and GLUT_RIGHT_BUTTON
* @param state button pressed (GLUT_DOWN) or released(GLUT_UP)
* @param x mouse x position in pixel relative to the window, when the mouse button was pressed
* @param y mouse y position in pixel relative to the window, when the mouse button was pressed
*/
void mouseDown(int button, int state, int x, int y) {
	//TODO: implement free camera rotation here
}

/**
* called when the mouse moves
* @param x mouse x position in pixel relative to the window
* @param y mouse x position in pixel relative to the window
*/
void mouseMotion(int x, int y) {
	//TODO: implement free camera rotation here too
}

/**
 * called when the user pressed a character key (this excludes UP, DOWN, DEL, PGDN etc., these are handled in specialKeyDown)
 * @param key ASCII character code
 * @param x mouse x position in pixel relative to the window, when the key was pressed
 * @param y mouse y position in pixel relative to the window, when the key was pressed
 */
void keyDown(unsigned char key, int x, int y) {
	//printf("key = %c\n", key);

	switch (key) {
		case 27: // 27 = the escape key as decimal number in the ASCII table
			exit(0);
	        break;

		case 'w': // w-key toggles wireframe mode
			wireframe = !wireframe;
	        break;

		case 'b': // b-key toggles backface culling
			culling = !culling;
	        break;

		case 'c':
			useFreeCamera = !useFreeCamera;
	        if (!useFreeCamera) {
		        printf("Switched to animated camera.\n");
	        }
	        else {
		        printf("Switched to free camera.\n");
	        }
	        break;
	}
}

/**
* called when the user pressed a special key (UP, DOWN, DEL, PGDN etc.)
* @param GLUT key code
* @param x mouse x position in pixel relative to the window, when the key was pressed
* @param y mouse y position in pixel relative to the window, when the key was pressed
*/
void specialKeyDown(int key, int x, int y) {
	//printf("special key: %i\n", key);

	//TODO: implement free camera movement with the arrow keys here (please only update the position of the camera in freeCameraUpdate(), not in the keyDown function!)

	switch (key) {
		case GLUT_KEY_UP:
			printf("up\n");
	        camera.moveZ = -camera.speed;
	        break;
		case GLUT_KEY_DOWN:
			printf("down\n");
	        camera.moveZ = camera.speed;
	        break;
		case GLUT_KEY_RIGHT:
			printf("right\n");
	        camera.moveX = camera.speed;
	        break;
		case GLUT_KEY_LEFT:
			printf("left\n");
	        camera.moveX = -camera.speed;
	        break;
	}
}

void specialKeyUp(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_UP:
			printf("up\n");
	        camera.moveZ = 0;
	        break;
		case GLUT_KEY_DOWN:
			printf("down\n");
	        camera.moveZ = 0;
	        break;
		case GLUT_KEY_RIGHT:
			printf("right\n");
	        camera.moveX = 0;
	        break;
		case GLUT_KEY_LEFT:
			printf("left\n");
	        camera.moveX = 0;
	        break;
	}
}

/**
* called when the window was resized
* @param w new window width in pixel
* @param h new window height in pixel
*/
void reshape(int w, int h) {
	// rebuild viewport
	glViewport(0, 0, w, h);

	// rebuild projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ((float) w) / h, 0.1f, 100);
}

int setupGLUT(int argc, char **argv) {
	// initialize glut
	glutInit(&argc, argv);

	// display mode
	//glutInitContextVersion(3, 0);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	// window size and position
	int windowWidth = 1280;
	int windowHeight = 720;
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2,
	                       (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2); // center the window

	// create window
	int windowId = glutCreateWindow("<INSERT_MOVIE_TITLE_HERE>");

	// register callback functions
	glutDisplayFunc(display);
	glutIdleFunc(update);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyDown);

	glutSpecialFunc(specialKeyDown);
	glutSpecialUpFunc(specialKeyUp);
	glutMouseFunc(mouseDown);
	glutMotionFunc(mouseMotion);

	// fullscreen
	//glutFullScreen();

	return windowId;
}

int main(int argc, char **argv) {
	setupGLUT(argc, argv);

	oogl::dumpGLInfos();

	init();

	glutMainLoop();

	return 0;
}
