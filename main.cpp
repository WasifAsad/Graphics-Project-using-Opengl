#include<windows.h>
#include<cstdio>
#include<mmsystem.h>
#ifdef __APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<math.h>>

# define PI           3.14159265358979323846

void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}



float bx = -1.0;
float sy=-1.5;
float my=-1.5;
float cx=-1.0;
float ix=-0.9;
static int flag=1;
static int mark=1;
GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 0.0001f;
int key;



void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}



void update(int value) {

    bx += 0.003;
	glutPostRedisplay();
	glutTimerFunc(5, update, 0);
}



void truck(){
    glPushMatrix();
    glTranslatef(bx, 0, 0);
    glBegin(GL_POLYGON);
    glColor4f(0.47f, 0.596f, 0.521f, 1.0f);
    glVertex2f(-0.97f, -0.62f);
    glVertex2f(-0.97f, -0.46f);
    glVertex2f(-0.64f, -0.46f);
    glVertex2f(-0.64f, -0.62f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.501f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.64f, -0.62f);
    glVertex2f(-0.64f, -0.55f);
    glVertex2f(-0.51f, -0.55f);
    glVertex2f(-0.51f, -0.62f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.501f, 0.27f, 0.0f, 1.0f);
    glVertex2f(-0.64f, -0.55f);
    glVertex2f(-0.55f, -0.55f);
    glVertex2f(-0.58f, -0.5f);
    glVertex2f(-0.64f, -0.5f);
    glEnd();
//glass
    glBegin(GL_POLYGON);
    glColor4f(0.529f, 0.808f, 0.922f, 1.0f);
    glVertex2f(-0.64f, -0.55f);
    glVertex2f(-0.57f, -0.55f);
    glVertex2f(-0.585f, -0.515f);
    glVertex2f(-0.64f, -0.515f);
    glEnd();

    //wheels
    int i;

	GLfloat x=-0.9f; GLfloat y=-0.62f; GLfloat radius =.05f;
	int triangleAmount = 100;


	GLfloat twicePi = 2.0f * PI;

    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();


	int j;

	GLfloat x1=-0.71f; GLfloat y1=-0.62f;



    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f( x1 + (radius * cos(j *  twicePi / triangleAmount)),
                        y1 + (radius * sin(j * twicePi / triangleAmount)) );
		}
	glEnd();

    glPopMatrix();

    if(bx>2.0)
    {
        bx=-1.0;
    }
    glutPostRedisplay();

}
void sound()
{

    PlaySound("audio.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}


void SpecialInput(int key, int x, int y)
{
switch(key)
{
  case GLUT_KEY_UP:
    speed += 0.0001f;
    break;
  case GLUT_KEY_DOWN:
    speed = 0.0f;
    break;
  case GLUT_KEY_LEFT:
    speed -= 0.0001f;
    break;
  case GLUT_KEY_RIGHT:
    break;
}
  glutPostRedisplay();
}
void car(){
    glPushMatrix();
    glTranslatef(position, 0, 0);

    glBegin(GL_POLYGON);
    glColor4f(0.0f, 0.501f, 0.601f, 1.0f);
    glVertex2f(0.78f, -0.83f);
    glVertex2f(0.78f, -0.76f);
    glVertex2f(0.51f, -0.76f);
    glVertex2f(0.51f, -0.83f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.501f, 0.501f, 0.501f, 1.0f);
    glVertex2f(0.745f, -0.76f);
    glVertex2f(0.55f, -0.76f);
    glVertex2f(0.58f, -0.69f);
    glVertex2f(0.73f, -0.69f);
    glEnd();
//glass
    glBegin(GL_POLYGON);
    glColor4f(0.529f, 0.808f, 0.922f, 1.0f);
    glVertex2f(0.64f, -0.75f);
    glVertex2f(0.57f, -0.75f);
    glVertex2f(0.585f, -0.695f);
    glVertex2f(0.64f, -0.695f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.529f, 0.808f, 0.922f, 1.0f);
    glVertex2f(0.73f, -0.75f);
    glVertex2f(0.65f, -0.75f);
    glVertex2f(0.65f, -0.695f);
    glVertex2f(0.72f, -0.695f);
    glEnd();


    //wheels
 int i;

	GLfloat x=0.71f; GLfloat y=-0.83f; GLfloat radius =.038f;
	int triangleAmount = 100;


	GLfloat twicePi = 2.0f * PI;

    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();


	int j;

	GLfloat x1=0.585f; GLfloat y1=-0.83f;



    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f( x1 + (radius * cos(j *  twicePi / triangleAmount)),
                        y1 + (radius * sin(j * twicePi / triangleAmount)) );
		}
	glEnd();
	glPopMatrix();

    position -= speed;
    if(position<-2.0)
    {
        position=1.5;
    }



    glutPostRedisplay();

}

void sun()
{


    glPushMatrix();
    glTranslatef(0, sy, 0);
	int i;

	GLfloat x=0.7f; GLfloat y=0.75f; GLfloat radius =.1f;
	int triangleAmount = 100;


	GLfloat twicePi = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
	glPopMatrix();

    sy += .000009;
    if(sy>2.0)
    {
        sy=-1.5;
    }
    glutPostRedisplay();
}
void moon()
{


    glPushMatrix();
    glTranslatef(0, my, 0);
	int i;

	GLfloat x=0.7f; GLfloat y=0.75f; GLfloat radius =.1f;
	int triangleAmount = 100;


	GLfloat twicePi = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
	glPopMatrix();

    my += .000021;
    if(my>2.0)
    {
        my=-1.5;
    }
    glutPostRedisplay();
}

void clouds()
{
    glPushMatrix();
    glTranslatef(cx, 0, 0);
    //clouds
   int j;

	GLfloat x1=-0.6f; GLfloat y1=0.7f; GLfloat radius1 =.075f;
	int triangleAmount1 = 100;
	GLfloat twicePi = 2.0f * PI;
	glColor3f(0.866f, 0.866f, 0.866f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(j = 0; j <= triangleAmount1;j++) {
			glVertex2f( x1 + (radius1 * cos(j *  twicePi / triangleAmount1)),
                        y1 + (radius1 * sin(j * twicePi / triangleAmount1)) );
		}
	glEnd();


    int j1;
	GLfloat x2=-0.7f; GLfloat y2=0.75f;
	glColor3f(0.866f, 0.866f, 0.866f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(j1 = 0; j1 <= triangleAmount1;j1++) {
			glVertex2f( x2 + (radius1 * cos(j1 *  twicePi / triangleAmount1)),
                        y2 + (radius1 * sin(j1 * twicePi / triangleAmount1)) );
		}
	glEnd();


    int j2;
	GLfloat x3=-0.8f; GLfloat y3=0.7f;
	glColor3f(0.866f, 0.866f, 0.866f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(j2 = 0; j2 <= triangleAmount1;j2++) {
			glVertex2f( x3 + (radius1 * cos(j2 *  twicePi / triangleAmount1)),
                        y3 + (radius1 * sin(j2 * twicePi / triangleAmount1)) );
		}
	glEnd();


    int j3;
	GLfloat x4=-0.7f; GLfloat y4=0.65f;
	glColor3f(0.866f, 0.866f, 0.866f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(j3 = 0; j3 <= triangleAmount1;j3++) {
			glVertex2f( x4 + (radius1 * cos(j3 *  twicePi / triangleAmount1)),
                        y4 + (radius1 * sin(j3 * twicePi / triangleAmount1)) );
		}
	glEnd();

	glPopMatrix();
	if(flag)
	{
		cx+=0.00002;

		if(cx>2.0)
		 flag=0;
	}

	if(!flag)
	{
		cx-=0.00002;
		if(cx<-0.9)
		 flag=1;
	}


    glutPostRedisplay();
}

void birds()
{
    glPushMatrix();
    glTranslatef(ix, 0, 0);
    //birds
    glBegin(GL_POLYGON);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.86f, 0.62);
    glVertex2f(-0.9f, 0.64f);
    glVertex2f(-0.86f, 0.61f);
    glVertex2f(-0.82f, 0.64f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.8f, 0.58);
    glVertex2f(-0.84f, 0.6f);
    glVertex2f(-0.8f, 0.57f);
    glVertex2f(-0.76f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.75f, 0.62);
    glVertex2f(-0.79f, 0.64f);
    glVertex2f(-0.75f, 0.61f);
    glVertex2f(-0.71f, 0.64f);
    glEnd();

    glPopMatrix();
	if(mark)
	{
		ix+=0.00007;

		if(ix>2.0)
		 mark=0;
	}

	if(!mark)
	{
		ix-=0.00005;
		if(ix<-0.9)
		 mark=1;
	}


    glutPostRedisplay();
}


void display() {

	glBegin(GL_POLYGON);
    glColor4f(0.529f, 0.808f, 0.922f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

//sun
    sun();

//clouds
    clouds();
    glTranslatef(+0.4f, -0.3f, 0.0f);
    clouds();
    glLoadIdentity();

//birds
    birds();

//top square
    glBegin(GL_POLYGON);
    glColor4f(0.992f, 0.929f, 0.788f, 1.0f);
    glVertex2f(0.4f, 0.275f);
    glVertex2f(0.4f, 0.025f);
    glVertex2f(0.525f, 0.025f);
    glVertex2f(0.525f, 0.275f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.643f, 0.572f, 0.486f, 1.0f);
    glVertex2f(0.425f, 0.25f);
    glVertex2f(0.425f, 0.025f);
    glVertex2f(0.5f, 0.025f);
    glVertex2f(0.5f, 0.25f);
    glEnd();
//Shadow unit
    glBegin(GL_POLYGON);
    glColor4f(0.224f, 0.227f, 0.169f, 1.0f);
    glVertex2f(0.725f, -0.025f);
    glVertex2f(0.8f, 0.1f);
    glVertex2f(0.0f, 0.25f);
    glVertex2f(-0.8f, 0.1f);
    glVertex2f(-0.725f,-0.025f);
    glEnd();
//Main building
    glBegin(GL_POLYGON);
    glColor4f(0.976f, 0.988f, 0.945f, 1.0f);
    glVertex2f(-0.7f, 0.0f);
    glVertex2f(0.7f, 0.0f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(-0.7f,-0.5f);
    glEnd();

//triangles
    glBegin(GL_TRIANGLES);
    glColor4f(0.992f, 0.929f, 0.788f, 1.0f);
    glVertex2f(0.8,0.05);
    glVertex2f(0.95,0.245);
    glVertex2f(0.325,0.155);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor4f(0.992f, 0.929f, 0.788f, 1.0f);
    glVertex2f(-0.8,0.05);
    glVertex2f(-0.95,0.25);
    glVertex2f(-0.325,0.155);
    glEnd();

//red part
    glBegin(GL_POLYGON);
    glColor4f(0.588f, 0.364f, 0.286f, 1.0f);
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(-0.4f,-0.5f);
    glEnd();

//pillers
    glBegin(GL_POLYGON); //2 sides
    glColor4f(0.549f, 0.533f, 0.556f, 1.0f);
    glVertex2f(0.75f, 0.1f);
    glVertex2f(0.7f, 0.1f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.75f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //shade
    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
    glVertex2f(0.75f, -0.45);
    glVertex2f(0.7f, -0.45f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.75f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.549f, 0.533f, 0.556f, 1.0f);
    glVertex2f(-0.75f, 0.1f);
    glVertex2f(-0.7f, 0.1f);
    glVertex2f(-0.7f, -0.5f);
    glVertex2f(-0.75f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //shade
    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
    glVertex2f(-0.75f, -0.45);
    glVertex2f(-0.7f, -0.45f);
    glVertex2f(-0.7f, -0.5f);
    glVertex2f(-0.75f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON); //mid pair
    glColor4f(0.549f, 0.533f, 0.556f, 1.0f);
    glVertex2f(-0.325f, 0.16f);
    glVertex2f(-0.275f, 0.165f);
    glVertex2f(-0.275f, -0.5f);
    glVertex2f(-0.325f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //shade
    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
    glVertex2f(-0.325f, -0.45);
    glVertex2f(-0.275f, -0.45f);
    glVertex2f(-0.275f, -0.5f);
    glVertex2f(-0.325f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.549f, 0.533f, 0.556f, 1.0f);
    glVertex2f(0.325f, 0.16f);
    glVertex2f(0.275f, 0.165f);
    glVertex2f(0.275f, -0.5f);
    glVertex2f(0.325f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //shade
    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
    glVertex2f(0.325f, -0.45);
    glVertex2f(0.275f, -0.45f);
    glVertex2f(0.275f, -0.5f);
    glVertex2f(0.325f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON); //mid
    glColor4f(0.549f, 0.533f, 0.556f, 1.0f);
    glVertex2f(0.025f, -0.1);
    glVertex2f(-0.025f, -0.1f);
    glVertex2f(-0.025f, -0.5f);
    glVertex2f(0.025f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //shade
    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
    glVertex2f(0.025f, -0.45);
    glVertex2f(-0.025f, -0.45f);
    glVertex2f(-0.025f, -0.5f);
    glVertex2f(0.025f,-0.5f);
    glEnd();

//doors
    glBegin(GL_POLYGON); //right
    glColor4f(0.247f, 0.286f, 0.325f, 1.0f);
    glVertex2f(0.05f, -0.35);
    glVertex2f(0.25f, -0.35f);
    glVertex2f(0.25f, -0.5f);
    glVertex2f(0.05f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //door glass
    glColor4f(0.105f, 0.243f, 0.219f, 1.0f);
    glVertex2f(0.05f, -0.33);
    glVertex2f(0.25f, -0.33f);
    glVertex2f(0.25f, -0.38f);
    glVertex2f(0.05f,-0.38f);
    glEnd();

    glBegin(GL_POLYGON); //left
    glColor4f(0.247f, 0.286f, 0.325f, 1.0f);
    glVertex2f(-0.05f, -0.35);
    glVertex2f(-0.25f, -0.35f);
    glVertex2f(-0.25f, -0.5f);
    glVertex2f(-0.05f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //door glass
    glColor4f(0.105f, 0.243f, 0.219f, 1.0f);
    glVertex2f(-0.05f, -0.33);
    glVertex2f(-0.25f, -0.33f);
    glVertex2f(-0.25f, -0.38f);
    glVertex2f(-0.05f,-0.38f);
    glEnd();

//windows
    glBegin(GL_POLYGON); //right
    glColor4f(0.105f, 0.243f, 0.219f, 1.0f);
    glVertex2f(0.05f, -0.19);
    glVertex2f(0.25f, -0.19f);
    glVertex2f(0.25f, -0.27f);
    glVertex2f(0.05f,-0.27f);
    glEnd();

    glBegin(GL_POLYGON); //left
    glColor4f(0.105f, 0.243f, 0.219f, 1.0f);
    glVertex2f(-0.05f, -0.19);
    glVertex2f(-0.25f, -0.19f);
    glVertex2f(-0.25f, -0.27f);
    glVertex2f(-0.05f,-0.27f);
    glEnd();

//head
    glBegin(GL_POLYGON);
    glColor4f(0.976f, 0.988f, 0.945f, 1.0f);
    glVertex2f(0.0f, 0.245f);
    glVertex2f(0.38f, 0.1315f);
    glVertex2f(0.38f, 0.165f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(-0.38f, 0.1315f);
    glVertex2f(-0.37f, 0.165f);
    glEnd();



//dark head
    glBegin(GL_POLYGON);
    glColor4f(0.643f, 0.572f, 0.486f, 1.0f);
    glVertex2f(0.0f, 0.245f);
    glVertex2f(0.38f, 0.1315f);
    glVertex2f(0.38f, 0.1625f);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(-0.38f, 0.1315f);
    glVertex2f(-0.37f, 0.1625f);
    glEnd();
//hard tri
    glBegin(GL_TRIANGLES);
    glColor4f(0.643f, 0.572f, 0.486f, 1.0f);
    glVertex2f(0.8,0.05);
    glVertex2f(0.9185,0.2);
    glVertex2f(0.365,0.138);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor4f(0.643f, 0.572f, 0.486f, 1.0f);
    glVertex2f(-0.8,0.05);
    glVertex2f(-0.9185,0.2);
    glVertex2f(-0.365,0.138);
    glEnd();

//glass
    glBegin(GL_POLYGON);
    glColor4f(0.568f, 0.831f, 0.737f, 1.0f);
    glVertex2f(0.4f, -0.05f);
    glVertex2f(0.6f, -0.05f);
    glVertex2f(0.6f, -0.45f);
    glVertex2f(0.4f,-0.45f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.568f, 0.831f, 0.737f, 1.0f);
    glVertex2f(-0.4f, -0.05f);
    glVertex2f(-0.6f, -0.05f);
    glVertex2f(-0.6f, -0.45f);
    glVertex2f(-0.4f,-0.45f);
    glEnd();

//Ground
    glBegin(GL_POLYGON);
    glColor4f(0.8f, 0.694f, 0.576f, 1.0f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f,-0.5f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f,-1.0f);
    glEnd();
 //front chad
    glBegin(GL_POLYGON);
    glColor4f(0.992f, 0.929f, 0.788f, 1.0f);
    glVertex2f(-0.55f, 0.0f);
    glVertex2f(0.55f, 0.0f);
    glVertex2f(0.325f, -0.155f);
    glVertex2f(-0.325f,-0.155f);
    glEnd();

//stairs
    glBegin(GL_POLYGON); //big
    glColor4f(0.952f, 0.937f, 0.815f, 1.0f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(-0.8f, -0.56f);
    glVertex2f(0.8f, -0.56f);
    glVertex2f(0.8f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON); //med
    glColor4f(0.537f, 0.36f, 0.207f, 1.0f);
    glVertex2f(-0.8f, -0.52f);
    glVertex2f(-0.8f, -0.56f);
    glVertex2f(0.8f, -0.56f);
    glVertex2f(0.8f,-0.52f);
    glEnd();

    glBegin(GL_POLYGON); //small
    glColor4f(0.509f, 0.337f, 0.219f, 1.0f);
    glVertex2f(-0.8f, -0.54f);
    glVertex2f(-0.8f, -0.56f);
    glVertex2f(0.8f, -0.56f);
    glVertex2f(0.8f,-0.54f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.752f, 0.752f, 0.752f, 1.0f);
    glVertex2f(0.35f, -0.5f);
    glVertex2f(0.35f, -0.56f);
    glVertex2f(0.05f, -0.56f);
    glVertex2f(0.05f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.752f, 0.752f, 0.752f, 1.0f);
    glVertex2f(-0.35f, -0.5f);
    glVertex2f(-0.35f, -0.56f);
    glVertex2f(-0.05f, -0.56f);
    glVertex2f(-0.05f,-0.5f);
    glEnd();

    //shades
    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(0.345f, -0.515f);
    glVertex2f(0.345f, -0.525f);
    glVertex2f(0.065f, -0.525f);
    glVertex2f(0.065f,-0.515f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(0.345f, -0.535f);
    glVertex2f(0.345f, -0.545f);
    glVertex2f(0.065f, -0.545f);
    glVertex2f(0.065f,-0.535f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(0.345f, -0.555f);
    glVertex2f(0.345f, -0.56f);
    glVertex2f(0.065f, -0.56f);
    glVertex2f(0.065f,-0.555f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(-0.345f, -0.515f);
    glVertex2f(-0.345f, -0.525f);
    glVertex2f(-0.065f, -0.525f);
    glVertex2f(-0.065f,-0.515f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(-0.345f, -0.535f);
    glVertex2f(-0.345f, -0.545f);
    glVertex2f(-0.065f, -0.545f);
    glVertex2f(-0.065f,-0.535f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(-0.345f, -0.555f);
    glVertex2f(-0.345f, -0.56f);
    glVertex2f(-0.065f, -0.56f);
    glVertex2f(-0.065f,-0.555f);
    glEnd();
//board
    glBegin(GL_POLYGON);
    glColor4f(0.156f, 0.262f, 0.470f, 1.0f);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(-0.2f,0.1f);
    glEnd();

//writing

    glColor3f(1.0, 1.0, 1.0);
    renderBitmapString(-0.1f, 0.03f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "Rajshahi Railway Station");


//road

    glBegin(GL_POLYGON);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-1.0f, -0.56);
    glVertex2f(-1.0f, -0.9f);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(1.0f,-0.56f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -0.72);
    glVertex2f(-1.0f, -0.74f);
    glVertex2f(1.0f, -0.74f);
    glVertex2f(1.0f,-0.72f);
    glEnd();
//


	truck();
	car();


	glFlush();
}

void display1() {

	glBegin(GL_POLYGON);
    glColor4f(0.019f, 0.031f, 0.109f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

//moon
    moon();

//clouds
    clouds();
    glTranslatef(+0.4f, -0.3f, 0.0f);
    clouds();
    glLoadIdentity();

//birds
    //birds();

//top square
    glBegin(GL_POLYGON);
    glColor4f(0.992f, 0.929f, 0.788f, 1.0f);
    glVertex2f(0.4f, 0.275f);
    glVertex2f(0.4f, 0.025f);
    glVertex2f(0.525f, 0.025f);
    glVertex2f(0.525f, 0.275f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.643f, 0.572f, 0.486f, 1.0f);
    glVertex2f(0.425f, 0.25f);
    glVertex2f(0.425f, 0.025f);
    glVertex2f(0.5f, 0.025f);
    glVertex2f(0.5f, 0.25f);
    glEnd();
//Shadow unit
    glBegin(GL_POLYGON);
    glColor4f(0.224f, 0.227f, 0.169f, 1.0f);
    glVertex2f(0.725f, -0.025f);
    glVertex2f(0.8f, 0.1f);
    glVertex2f(0.0f, 0.25f);
    glVertex2f(-0.8f, 0.1f);
    glVertex2f(-0.725f,-0.025f);
    glEnd();
//Main building
    glBegin(GL_POLYGON);
    glColor4f(0.976f, 0.988f, 0.945f, 1.0f);
    glVertex2f(-0.7f, 0.0f);
    glVertex2f(0.7f, 0.0f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(-0.7f,-0.5f);
    glEnd();

//triangles
    glBegin(GL_TRIANGLES);
    glColor4f(0.992f, 0.929f, 0.788f, 1.0f);
    glVertex2f(0.8,0.05);
    glVertex2f(0.95,0.245);
    glVertex2f(0.325,0.155);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor4f(0.992f, 0.929f, 0.788f, 1.0f);
    glVertex2f(-0.8,0.05);
    glVertex2f(-0.95,0.25);
    glVertex2f(-0.325,0.155);
    glEnd();

//red part
    glBegin(GL_POLYGON);
    glColor4f(0.588f, 0.364f, 0.286f, 1.0f);
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(-0.4f,-0.5f);
    glEnd();

//pillers
    glBegin(GL_POLYGON); //2 sides
    glColor4f(0.549f, 0.533f, 0.556f, 1.0f);
    glVertex2f(0.75f, 0.1f);
    glVertex2f(0.7f, 0.1f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.75f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //shade
    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
    glVertex2f(0.75f, -0.45);
    glVertex2f(0.7f, -0.45f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.75f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.549f, 0.533f, 0.556f, 1.0f);
    glVertex2f(-0.75f, 0.1f);
    glVertex2f(-0.7f, 0.1f);
    glVertex2f(-0.7f, -0.5f);
    glVertex2f(-0.75f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //shade
    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
    glVertex2f(-0.75f, -0.45);
    glVertex2f(-0.7f, -0.45f);
    glVertex2f(-0.7f, -0.5f);
    glVertex2f(-0.75f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON); //mid pair
    glColor4f(0.549f, 0.533f, 0.556f, 1.0f);
    glVertex2f(-0.325f, 0.16f);
    glVertex2f(-0.275f, 0.165f);
    glVertex2f(-0.275f, -0.5f);
    glVertex2f(-0.325f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //shade
    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
    glVertex2f(-0.325f, -0.45);
    glVertex2f(-0.275f, -0.45f);
    glVertex2f(-0.275f, -0.5f);
    glVertex2f(-0.325f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.549f, 0.533f, 0.556f, 1.0f);
    glVertex2f(0.325f, 0.16f);
    glVertex2f(0.275f, 0.165f);
    glVertex2f(0.275f, -0.5f);
    glVertex2f(0.325f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //shade
    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
    glVertex2f(0.325f, -0.45);
    glVertex2f(0.275f, -0.45f);
    glVertex2f(0.275f, -0.5f);
    glVertex2f(0.325f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON); //mid
    glColor4f(0.549f, 0.533f, 0.556f, 1.0f);
    glVertex2f(0.025f, -0.1);
    glVertex2f(-0.025f, -0.1f);
    glVertex2f(-0.025f, -0.5f);
    glVertex2f(0.025f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //shade
    glColor4f(0.254f, 0.254f, 0.262f, 1.0f);
    glVertex2f(0.025f, -0.45);
    glVertex2f(-0.025f, -0.45f);
    glVertex2f(-0.025f, -0.5f);
    glVertex2f(0.025f,-0.5f);
    glEnd();

//doors
    glBegin(GL_POLYGON); //right
    glColor4f(0.247f, 0.286f, 0.325f, 1.0f);
    glVertex2f(0.05f, -0.35);
    glVertex2f(0.25f, -0.35f);
    glVertex2f(0.25f, -0.5f);
    glVertex2f(0.05f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //door glass
    glColor4f(0.105f, 0.243f, 0.219f, 1.0f);
    glVertex2f(0.05f, -0.33);
    glVertex2f(0.25f, -0.33f);
    glVertex2f(0.25f, -0.38f);
    glVertex2f(0.05f,-0.38f);
    glEnd();

    glBegin(GL_POLYGON); //left
    glColor4f(0.247f, 0.286f, 0.325f, 1.0f);
    glVertex2f(-0.05f, -0.35);
    glVertex2f(-0.25f, -0.35f);
    glVertex2f(-0.25f, -0.5f);
    glVertex2f(-0.05f,-0.5f);
    glEnd();
    glBegin(GL_POLYGON); //door glass
    glColor4f(0.105f, 0.243f, 0.219f, 1.0f);
    glVertex2f(-0.05f, -0.33);
    glVertex2f(-0.25f, -0.33f);
    glVertex2f(-0.25f, -0.38f);
    glVertex2f(-0.05f,-0.38f);
    glEnd();

//windows
    glBegin(GL_POLYGON); //right
    glColor4f(0.105f, 0.243f, 0.219f, 1.0f);
    glVertex2f(0.05f, -0.19);
    glVertex2f(0.25f, -0.19f);
    glVertex2f(0.25f, -0.27f);
    glVertex2f(0.05f,-0.27f);
    glEnd();

    glBegin(GL_POLYGON); //left
    glColor4f(0.105f, 0.243f, 0.219f, 1.0f);
    glVertex2f(-0.05f, -0.19);
    glVertex2f(-0.25f, -0.19f);
    glVertex2f(-0.25f, -0.27f);
    glVertex2f(-0.05f,-0.27f);
    glEnd();

//head
    glBegin(GL_POLYGON);
    glColor4f(0.976f, 0.988f, 0.945f, 1.0f);
    glVertex2f(0.0f, 0.245f);
    glVertex2f(0.38f, 0.1315f);
    glVertex2f(0.38f, 0.165f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(-0.38f, 0.1315f);
    glVertex2f(-0.37f, 0.165f);
    glEnd();



//dark head
    glBegin(GL_POLYGON);
    glColor4f(0.643f, 0.572f, 0.486f, 1.0f);
    glVertex2f(0.0f, 0.245f);
    glVertex2f(0.38f, 0.1315f);
    glVertex2f(0.38f, 0.1625f);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(-0.38f, 0.1315f);
    glVertex2f(-0.37f, 0.1625f);
    glEnd();
//hard tri
    glBegin(GL_TRIANGLES);
    glColor4f(0.643f, 0.572f, 0.486f, 1.0f);
    glVertex2f(0.8,0.05);
    glVertex2f(0.9185,0.2);
    glVertex2f(0.365,0.138);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor4f(0.643f, 0.572f, 0.486f, 1.0f);
    glVertex2f(-0.8,0.05);
    glVertex2f(-0.9185,0.2);
    glVertex2f(-0.365,0.138);
    glEnd();

//glass
    glBegin(GL_POLYGON);
    glColor4f(0.568f, 0.831f, 0.737f, 1.0f);
    glVertex2f(0.4f, -0.05f);
    glVertex2f(0.6f, -0.05f);
    glVertex2f(0.6f, -0.45f);
    glVertex2f(0.4f,-0.45f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.568f, 0.831f, 0.737f, 1.0f);
    glVertex2f(-0.4f, -0.05f);
    glVertex2f(-0.6f, -0.05f);
    glVertex2f(-0.6f, -0.45f);
    glVertex2f(-0.4f,-0.45f);
    glEnd();

//Ground
    glBegin(GL_POLYGON);
    glColor4f(0.8f, 0.694f, 0.576f, 1.0f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f,-0.5f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f,-1.0f);
    glEnd();
 //front chad
    glBegin(GL_POLYGON);
    glColor4f(0.992f, 0.929f, 0.788f, 1.0f);
    glVertex2f(-0.55f, 0.0f);
    glVertex2f(0.55f, 0.0f);
    glVertex2f(0.325f, -0.155f);
    glVertex2f(-0.325f,-0.155f);
    glEnd();

//stairs
    glBegin(GL_POLYGON); //big
    glColor4f(0.952f, 0.937f, 0.815f, 1.0f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(-0.8f, -0.56f);
    glVertex2f(0.8f, -0.56f);
    glVertex2f(0.8f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON); //med
    glColor4f(0.537f, 0.36f, 0.207f, 1.0f);
    glVertex2f(-0.8f, -0.52f);
    glVertex2f(-0.8f, -0.56f);
    glVertex2f(0.8f, -0.56f);
    glVertex2f(0.8f,-0.52f);
    glEnd();

    glBegin(GL_POLYGON); //small
    glColor4f(0.509f, 0.337f, 0.219f, 1.0f);
    glVertex2f(-0.8f, -0.54f);
    glVertex2f(-0.8f, -0.56f);
    glVertex2f(0.8f, -0.56f);
    glVertex2f(0.8f,-0.54f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.752f, 0.752f, 0.752f, 1.0f);
    glVertex2f(0.35f, -0.5f);
    glVertex2f(0.35f, -0.56f);
    glVertex2f(0.05f, -0.56f);
    glVertex2f(0.05f,-0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.752f, 0.752f, 0.752f, 1.0f);
    glVertex2f(-0.35f, -0.5f);
    glVertex2f(-0.35f, -0.56f);
    glVertex2f(-0.05f, -0.56f);
    glVertex2f(-0.05f,-0.5f);
    glEnd();

    //shades
    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(0.345f, -0.515f);
    glVertex2f(0.345f, -0.525f);
    glVertex2f(0.065f, -0.525f);
    glVertex2f(0.065f,-0.515f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(0.345f, -0.535f);
    glVertex2f(0.345f, -0.545f);
    glVertex2f(0.065f, -0.545f);
    glVertex2f(0.065f,-0.535f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(0.345f, -0.555f);
    glVertex2f(0.345f, -0.56f);
    glVertex2f(0.065f, -0.56f);
    glVertex2f(0.065f,-0.555f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(-0.345f, -0.515f);
    glVertex2f(-0.345f, -0.525f);
    glVertex2f(-0.065f, -0.525f);
    glVertex2f(-0.065f,-0.515f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(-0.345f, -0.535f);
    glVertex2f(-0.345f, -0.545f);
    glVertex2f(-0.065f, -0.545f);
    glVertex2f(-0.065f,-0.535f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.364f, 0.360f, 0.352f, 1.0f);
    glVertex2f(-0.345f, -0.555f);
    glVertex2f(-0.345f, -0.56f);
    glVertex2f(-0.065f, -0.56f);
    glVertex2f(-0.065f,-0.555f);
    glEnd();
//board
    glBegin(GL_POLYGON);
    glColor4f(0.156f, 0.262f, 0.470f, 1.0f);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(-0.2f,0.1f);
    glEnd();

//writing

    glColor3f(1.0, 1.0, 1.0);
    renderBitmapString(-0.1f, 0.03f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "Rajshahi Railway Station");


//road

    glBegin(GL_POLYGON);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-1.0f, -0.56);
    glVertex2f(-1.0f, -0.9f);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(1.0f,-0.56f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -0.72);
    glVertex2f(-1.0f, -0.74f);
    glVertex2f(1.0f, -0.74f);
    glVertex2f(1.0f,-0.72f);
    glEnd();
//


	truck();
	car();


	glFlush();
}
void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
    {
    case 'm':
        glutDisplayFunc(display);
        break;
    case 'n':
        glutDisplayFunc(display1);
        break;

    glutPostRedisplay();

	}
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("Railway");
	glutDisplayFunc(display);
	glutTimerFunc(5, update, 0);
    glutIdleFunc(Idle);
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(SpecialInput);
    sound();

	glutMainLoop();
	return 0;
}
