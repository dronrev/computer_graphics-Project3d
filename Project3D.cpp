/*
Qawi
Zhariff
Azim
Chris
Vernord
*/

#include <windows.h>
#include <gl\gl.h>
#include <gl\glut.h>

float counter = -19;
float hangTuahLeftHand = 0.0;
float hangTuahRightHand = 0.0;
float BD3_LeftHand = 0.0;
float BD3_RightHand = 0.0;
float move = 0;
float bodyMove = 0;
float handmoveAngle = 0;
float legMoveAngle1 = 0;
float legMoveAngle2 = 0;
float hangTuah_SC1_x = 1;
float hangTuah_Rotate = 0;
float BD1_SC1_y = 1;
float BD1_SC1_x = 0;
float BD1_SC1_z = -4;
float BD1_Rotate = 0;
float BD1_LH = 0;
float BD1_RH = 0;
float BD1_LL = 0;
float BD1_RL = 0;
float BD2_SC1_y = 2;
float BD2_SC1_x = 0;
float BD2_SC1_z = -4;
float BD2_Rotate = 0;
float BD2_LH = 0;
float BD2_LL = 0;
float BD2_RL = 0;
float Sword_Move_x = -2.5;
float Sword_Move_y = 100;
float Sword_Move_z = 0;
float SwordRotate = 180;
float March = -9;
float BD1_x = 1;
float BD1_y = 0;
float BD1_z = 0;
float BD2_x = 1;
float BD2_y = 0;
float BD2_z = 0;
float BD3_x = 0;
float BD3_y = 1;
float BD3_z = 0;
float BD3_Rotate = 0;
float BD3_SC1_x = 0;
float BD3_SC1_y = 0;
float Lipo_Rotate = 0;
float lipoLeftHand = 0;
float lipoRightHand = 0;
float lipo_SC1_x = 0, lipo_SC1_y = 0, Marchlipo = -9;
float lipo_Rotate = 180, lipo_x, lipo_y = 1, lipo_z = 0;
float sultanLeftHand = 0;
float SultanRotate = 0;
float sultanRightHand = 0;
float cam_x = 5.0, cam_y = 5.0, cam_z = 5.0, focus_x = 0, focus_y = 0, focus_z = 0;
void update(int value) {
	counter += 0.05;
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, update, 0);
}
void square() {
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 1);
	glVertex3d(1, 0, 1);
	glVertex3d(1, 1.5, 1);
	glVertex3d(0, 1.5, 1);
	glEnd();
}
void smallSquare() {
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 1);
	glVertex3d(0.3, 0, 1);
	glVertex3d(0.3, 1.5, 1);
	glVertex3d(0, 1.5, 1);
	glEnd();
}
void hangBody() {
	glPushMatrix();
	glRotated(90, 0.0, 0.2, 0.0);
	glTranslated(-1.3, 0, 0);
	smallSquare();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 0.0, 0.2, 0.0);
	glTranslated(1.0, 0, -1);
	smallSquare();
	glPopMatrix();

	glPushMatrix();
	square();
	glTranslated(0, 0, 0.3);
	square();
	glPopMatrix();
}

void hangLeg() {
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 1);
	glVertex3d(0.3, 0, 1);
	glVertex3d(0.3, 0.8, 1);
	glVertex3d(0.0, 0.8, 1);
	glEnd();
}
void theFeet() {
	glTranslated(0.0, -0.3, 0.0);
	glutSolidCube(0.3);
	glTranslated(0.0, -0.3, 0.0);
	glutSolidCube(0.3);
}
void theLeg() {
	glutSolidCube(0.3);
	glTranslated(0.0, -0.3, 0.0);
	glutSolidCube(0.3);
	theFeet();
}

void theHand() {
	glTranslated(-0.28, 0.0, 0.0);
	glutSolidCube(0.28);
	glTranslated(-0.28, 0.0, 0.0);
	glutSolidCube(0.28);
	glTranslated(-0.28, 0.0, 0.0);
	glutSolidCube(0.28);
}

void hangNeck() {
	glPushMatrix();
	glColor3ub(212, 155, 85);
	glTranslated(0, -0.5, 0);
	glutSolidCube(0.3);
	glPopMatrix();
}
void Sword() {
	//straight
	glutSolidCube(0.15);
	glTranslated(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslated(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslated(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslated(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslated(0, 0.2, 0);
	glutSolidCube(0.2);
	//holder
	glTranslated(0.2, -0.7, 0.0);
	glutSolidCube(0.2);
	glTranslated(-0.4, 0.0, 0.0);
	glutSolidCube(0.2);
	//mata
	glRotated(-90, 1, 0, 0);
	glTranslated(0.2, 0, 0.8);
	glutSolidCone(0.14, 0.3, 100, 100);

}

void init()
{
	glClearColor(0.15, 0.88, 0.96, 0.8);

	glMatrixMode(GL_PROJECTION);
	glPointSize(4.0);
	glLoadIdentity();
	gluPerspective(45, 1.0, 2.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	GLfloat dir[] = { 0.2,0.0,1.0,0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, dir);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

}

//badguy1
void badGuy1() {
	//head
	glColor3ub(255, 181, 114);
	glTranslated(0.6 - BD1_SC1_x, BD1_SC1_y, BD1_SC1_z);
	glRotated(BD1_Rotate, BD1_x, BD1_y, BD1_z);
	glPushMatrix();
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();
	//neck
	hangNeck();
	//body
	glPushMatrix();
	glColor3ub(194, 143, 52);
	glTranslated(-0.5, -2.0, -1.1);
	hangBody();
	glPopMatrix();
	//hand
	glPushMatrix();

	glTranslated(0.6, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	glRotated(BD1_LH, 0, 1, 0);
	theHand();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.66, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	glRotated(BD1_RH, 0, 1, 0);
	theHand();
	glPopMatrix();

	//leg
	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(-0.3, -2.1, 0.05);
	glRotated(BD1_LL, 1, 0, 0);
	theLeg();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(0.3, -2.1, 0.05);
	glRotated(BD1_RL, 1, 0, 0);
	theLeg();
	glPopMatrix();
	//hair
}
//badguy2
void badGuy2() {
	//head
	glColor3ub(255, 181, 114);
	glTranslated(0.6 - BD2_SC1_x, BD2_SC1_y, BD2_SC1_z);
	glRotated(BD2_Rotate, BD2_x, BD2_y, BD2_z);
	glPushMatrix();
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();
	//neck
	hangNeck();
	//body
	glPushMatrix();
	glColor3ub(194, 143, 52);
	glTranslated(-0.5, -2.0, -1.1);
	hangBody();
	glPopMatrix();
	//hand
	glPushMatrix();

	glTranslated(0.6, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	//move hand
	glRotated(0, 0, 1, 0);
	theHand();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.66, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	glRotated(0, 0, 1, 0);
	theHand();
	glPopMatrix();

	//leg
	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(-0.3, -2.1, 0.05);
	glRotated(BD2_LL, 1, 0, 0);
	theLeg();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(0.3, -2.1, 0.05);
	glRotated(BD2_RL, 1, 0, 0);
	theLeg();
	glPopMatrix();
	//hair
}
//badguy3
void badGuy3() {
	//head
	glColor3ub(255, 181, 114);
	glTranslated(BD3_SC1_x, BD3_SC1_y, March);
	glRotated(BD3_Rotate, BD3_x, BD3_y, BD3_z);
	glPushMatrix();
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();
	//neck
	hangNeck();
	//body
	glPushMatrix();
	glColor3ub(194, 143, 52);
	glTranslated(-0.5, -2.0, -1.1);
	hangBody();
	glPopMatrix();
	//hand
	glPushMatrix();

	glTranslated(0.6, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	glRotated(BD3_LeftHand, 0, 1, 0);
	theHand();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.66, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	glRotated(BD3_RightHand, 0, 1, 0);
	theHand();
	glPopMatrix();

	//leg
	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(-0.3, -2.1, 0.05);
	glRotated(legMoveAngle1, 1, 0, 0);
	theLeg();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(0.3, -2.1, 0.05);
	glRotated(legMoveAngle2, 1, 0, 0);
	theLeg();
	glPopMatrix();
	//hair
}
void hangTuah(float x) {
	//head
	glColor3ub(233, 170, 92);
	glRotated(hangTuah_Rotate, 0, 1, 0);
	glPushMatrix();
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();
	//neck
	hangNeck();
	//body
	glPushMatrix();
	glColor3ub(98, 149, 84);
	glTranslated(-0.5, -2.0, -1.1);
	hangBody();
	glPopMatrix();
	//hand
	glPushMatrix();
	glTranslated(0.6, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	glRotated(hangTuahLeftHand, 0, 1, 0);
	theHand();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.66, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	glRotated(hangTuahRightHand, 0, 1, 0);
	theHand();
	glPopMatrix();

	//leg
	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(-0.3, -2.1, 0.05);

	glRotated(legMoveAngle1, 1, 0, 0);
	theLeg();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(0.3, -2.1, 0.05);
	glRotated(legMoveAngle2, 1, 0, 0);
	theLeg();
	glPopMatrix();
	//hair
	glPushMatrix();
	glScaled(0.8, 0.8, 0.8);
	glTranslated(Sword_Move_x, Sword_Move_y, Sword_Move_z);
	glRotated(SwordRotate, 1, 0, 0);
	Sword();
	glPopMatrix();
}
void hairLipo()
{
	glColor3ub(188, 158, 130);
	glutSolidCube(0.5);
	glColor3ub(0, 0, 0);
	glTranslated(0, -0.25, 0.3);
	glScalef(1.0f, 2.0f, 0.3f);
	glutSolidCube(0.5);
}
void Lipo(float x) {
	//head
	//glColor3ub(233, 170, 92);
	//glRotated(Lipo_Rotate, 0, 1, 0);
	glTranslated(lipo_SC1_x, lipo_SC1_y, Marchlipo);
	glRotated(lipo_Rotate, lipo_x, lipo_y, lipo_z);


	glPushMatrix();
	hairLipo();
	glPopMatrix();
	//neck
	hangNeck();
	//body
	glPushMatrix();
	glColor3ub(255, 180, 0);
	glTranslated(-0.5, -2.0, -1.1);
	hangBody();
	glPopMatrix();
	//hand
	glPushMatrix();
	glTranslated(0.6, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	glRotated(lipoLeftHand, 0, 1, 0);
	theHand();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.66, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	glRotated(lipoRightHand, 0, 1, 0);
	theHand();
	glPopMatrix();

	//leg
	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(-0.3, -2.1, 0.05);

	glRotated(legMoveAngle1, 1, 0, 0);
	theLeg();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(0.3, -2.1, 0.05);
	glRotated(legMoveAngle2, 1, 0, 0);
	theLeg();
	glPopMatrix();

}
void pyramid(float r, float g, float b) {

	glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glEnd();
	//draw the nose

	glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
	glVertex3f(0.5, -0.5, 0.0);
	glColor3ub(r, g, b);
	glVertex3f(0.0, 0.0, 1);

	glColor3ub(r, g, b);
	glVertex3f(0.5, 0.5, 0.0);
	glColor3ub(r, g, b);
	glVertex3f(0.0, 0.0, 1);
	glColor3ub(r, g, b);
	glVertex3f(-0.5, 0.5, 0.0);
	glColor3ub(r, g, b);
	glVertex3f(0.0, 0.0, 1);

	glColor3ub(r, g, b);
	glVertex3f(-0.5, -0.5, 0.0);
	glColor3ub(r, g, b);
	glVertex3f(0.0, 0.0, 1);
	glEnd();
}
void tanjak() {

	glutSolidSphere(0.4, 50, 50);
	glRotated(30, 0, 1, 0);
	glTranslated(0, 0.7, 0);
	pyramid(255, 180, 15);

}
void sultan() {
	//head
	glColor3ub(233, 170, 92);
	glRotated(SultanRotate, 0, 1, 0);
	tanjak();
	glPopMatrix();
	//neck
	hangNeck();
	//body
	glPushMatrix();
	glColor3ub(250, 253, 15);
	glTranslated(-0.5, -2.0, -1.1);
	hangBody();
	glPopMatrix();
	//hand
	glPushMatrix();
	glTranslated(0.6, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	glRotated(sultanLeftHand, 0, 1, 0);
	theHand();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.66, -0.6, 0.1);
	glRotated(90, 0, 0, 1);
	glutSolidCube(0.28);
	glRotated(sultanRightHand, 0, 1, 0);
	theHand();
	glPopMatrix();

	//leg
	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(-0.3, -2.1, 0.05);

	glRotated(legMoveAngle1, 1, 0, 0);
	theLeg();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(235, 198, 130);
	glTranslated(0.3, -2.1, 0.05);
	glRotated(legMoveAngle2, 1, 0, 0);
	theLeg();
	glPopMatrix();
	//hair
	glPushMatrix();
	glScaled(0.8, 0.8, 0.8);
	glTranslated(Sword_Move_x, Sword_Move_y, Sword_Move_z);
	glRotated(SwordRotate, 1, 0, 0);
	Sword();
	glPopMatrix();
}
void FightBackground() {
	glPushMatrix();
	glTranslated(0, -6, 0);
	glColor3ub(193, 104, 19);
	glBegin(GL_QUADS);
	glVertex3f(-2, -1, 0);
	glVertex3f(5, -1, 0);
	glVertex3f(5, 0, -5);
	glVertex3f(-2, 0, -5);
	glEnd();
	glPopMatrix();
}

void Floor() {
	FightBackground();

	glPushMatrix();
	glTranslated(-4, 0, 4);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-6.4, 0, 4);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-21, 0, -36);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-19, 0, -30);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-16, 0, -23);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-16.7, 0, -24);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15, 0, -19);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-14, 0, -17);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-13, 0, -14);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11.6, 0, -10);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-9, 0, -6);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-9, 0, -4);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-9, 0, -3.5);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-7, 0, 2);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-8, 0, 1);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-8, 0, 0);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-9.8, 0, -4);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-8, 0, -2);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-7, 0, 0);
	FightBackground();
	glTranslated(6, 0, -4);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-8, 0, -4);
	FightBackground();
	glTranslated(5, 0, -6);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-9, 0, -7);
	FightBackground();
	glTranslated(5, 0, -8);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 0, -10);
	FightBackground();
	glTranslated(4, 0, -12);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11, 0, -15);
	FightBackground();
	glTranslated(6, 0, -15);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-12, 0, -19);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-13.4, 0, -26);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-14.5, 0, -30);
	FightBackground();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-16, 0, -36);
	FightBackground();
	glPopMatrix();
}

void Line() {
	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);
	glTranslated(0, -6, 0);
	glVertex3f(0.5f, -0.5f, 100.0f);
	glVertex3f(0.5f, -0.5f, -100.5f);
	glEnd();
}
void WoodLine() {
	glPushMatrix();
	glTranslated(0, -5, -4);
	Line();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, -5, -4);
	Line();
	glPopMatrix();

	glPushMatrix();
	glTranslated(4, -5, -4);
	Line();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2, -5, -4);
	Line();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-4, -5, -4);
	Line();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-6, -5, -4);
	Line();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-8, -5, -4);
	Line();
	glPopMatrix();
}

void boatShelf() {
	glPushMatrix();
	glRotated(20, 0, 1, 0);
	glTranslated(-11, -5, -4);
	Line();
	glPopMatrix();

	glPushMatrix();
	glRotated(20, 0, 1, 0);
	glTranslated(-9, -5, -4);
	Line();
	glPopMatrix();
}

void Wall() {
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 100);
	glVertex3d(1, 0, 100);
	glVertex3d(1, 1, -100);
	glVertex3d(0, 1, -100);
	glEnd();
}

void sea() {

	glColor3f(0, 0, 128);
	glBegin(GL_POLYGON);
	glVertex3f(-100, -5, -100);
	glVertex3f(-100, -5, 100);
	glVertex3f(100, -5, 100);
	glVertex3f(100, -5, -100);
	glEnd();
}

void boat(float x, float y, float z) {


	glPushMatrix();
	glColor3ub(63, 0, 15);
	// glScalef(2, 2, 2);
	glBegin(GL_POLYGON);
	glVertex3f(x + 1, y, z + 1);//atas kanan
	glVertex3f(x + 1, y, z - 1);//atas kiri
	glVertex3f(x + 1, y - 2, z);
	glPopMatrix();
	glEnd();

	glPushMatrix();
	glColor3ub(63, 0, 15);
	// glScalef(2, 2, 2);
	glBegin(GL_POLYGON);
	glVertex3f(x + 1, y, z - 1);
	glVertex3f(x - 1, y + 1, z);
	glVertex3f(x + 1, y - 2, z);
	glPopMatrix();
	glEnd();

	glPushMatrix();
	glColor3ub(63, 0, 15);
	// glScalef(2, 2, 2);
	glBegin(GL_POLYGON);
	glVertex3f(x + 1, y - 2, z);
	glVertex3f(x - 1, y + 1, z);
	glVertex3f(x + 1, y, z + 1);
	glPopMatrix();
	glEnd();

	glPushMatrix();
	glColor3ub(0, 0, 0);
	//glScalef(2, 2, 2);
	glBegin(GL_POLYGON);
	glVertex3f(x + 1, y, z + 1);
	glVertex3f(x + 1, y - 1, z);
	glVertex3f(x + 1, y, z - 1);
	glPopMatrix();
	glEnd();

	//belakang
	glPushMatrix();
	glColor3ub(255, 255, 255);
	// glScalef(2, 2, 2);
	glBegin(GL_POLYGON);
	glVertex3f(x + 7, y, z + 1);//atas kanan
	glVertex3f(x + 7, y, z - 1);//atas kiri
	glVertex3f(x + 7, y - 2, z);
	glPopMatrix();
	glEnd();

	//atas
	glPushMatrix();
	glColor3ub(213, 123, 115);
	// glScalef(2, 2, 2);
	glBegin(GL_POLYGON);
	glVertex3f(x + 1, y, z + 1);//atas kanan
	glVertex3f(x + 1, y, z - 1);//atas kiri
	glVertex3f(x + 7, y, z - 1);//atas kiri
	glVertex3f(x + 7, y, z + 1);//atas kanan
	glPopMatrix();
	glEnd();


	glPushMatrix();
	glColor3ub(63, 0, 15);
	// glScalef(2, 2, 2);
	glBegin(GL_POLYGON);
	glVertex3f(x + 1, y, z - 1);//atas kiri
	glVertex3f(x + 1, y - 2, z);
	glVertex3f(x + 7, y - 2, z);
	glVertex3f(x + 7, y, z - 1);//atas kiri
	glPopMatrix();
	glEnd();


	glPushMatrix();
	glColor3ub(63, 0, 15);
	// glScalef(2, 2, 2);
	glBegin(GL_POLYGON);
	glVertex3f(x + 1, y, z + 1);//atas kanan
	glVertex3f(x + 1, y - 2, z);
	glVertex3f(x + 7, y - 2, z);
	glVertex3f(x + 7, y, z + 1);//atas kanan
	glPopMatrix();
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glNormal3f(0, 0, 1);
	//scene1
	if (counter > -9 && counter < 12) {
		sea();
		if (counter > -9) {
			glPushMatrix();
			glTranslated(move, 0, 0);
			boat(0, 0, 0);
			glPopMatrix();

		}
		if (counter > -7 && counter < 4) {
			if (cam_z > -45) {
				cam_z == -45;
			}
			move -= 0.02f;
			cam_z -= 0.1f;
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(cam_x, cam_y, cam_z, focus_x, focus_y, focus_z, 0.0, 1.0, 0.0);
		}
		if (counter > 4 && counter < 11) {
			move -= 0.1f;
		}
	}
	//scene2
	if (counter > 12) {
		Floor();
		glPushMatrix();
		glColor3ub(105, 76, 15);
		glTranslated(-3.4, 0, 0);
		glRotated(20, 0, 1, 0);
		Wall();
		glPopMatrix();

		glPushMatrix();
		glColor3ub(87, 82, 73);
		glTranslated(-2.5, 0, 0);
		glRotated(20, 0, 1, 0);
		Wall();
		glPopMatrix();

		glPushMatrix();
		glRotated(20, 0, 1, 0);
		WoodLine();
		glPopMatrix();
		boatShelf();
		glPushMatrix();
		hangTuah(21);
		glPopMatrix();
		glPushMatrix();
		badGuy1();
		glPopMatrix();
		if (counter > 14 && counter < 26)
		{
			BD1_LH = 90;
			hangTuah_SC1_x += 0.01f;

			if (counter > 17 && counter < 26) {
				hangTuah_Rotate -= 1.0f;
			}
		}
		if (counter > 26 && counter < 32) {
			BD1_SC1_x += 0.01f;
			BD1_SC1_y -= 0.01f;
			BD1_SC1_z += 0.01f;
			BD1_LH = 0;
			BD1_LL -= 1.0f;
			if (BD1_LL == -45) {
				BD1_LL = 0;
			}
		}
		if (counter > 37 && counter < 42) {
			Sword_Move_y -= 1.0f;
			BD1_LL = 0;
			BD1_Rotate -= 1.0f;
			BD1_SC1_x -= 0.01f;
			BD1_SC1_y -= 0.05f;
			BD1_SC1_z -= 0.01f;
		}
	}
	if (counter > 42) {
		glPushMatrix();
		badGuy2();
		glPopMatrix();
		if (counter > 44 && counter < 48) {
			BD2_SC1_x += 0.01f;
			BD2_SC1_y -= 0.01f;
			BD2_SC1_z += 0.01f;
			hangTuahLeftHand = 0;
			BD2_LL -= 1.0f;
			if (BD2_LL == -45) {
				BD2_LL += 30;
				BD2_LL = 0;
			}
		}
		if (counter > 48 && counter < 57) {
			hangTuahRightHand += 1.0f;
			Sword_Move_x += 0.016f;
			Sword_Move_z += 0.01f;
			SwordRotate = 90;
		}
		if (counter > 57 && counter < 62) {
			hangTuahRightHand -= 0.9f;
			Sword_Move_z += 0.016f;
		}
		if (counter > 63 && counter < 65) {
			Sword_Move_x -= 0.036f;
			Sword_Move_z -= 0.07f;
		}
		if (counter > 66 && counter < 71) {
			BD2_Rotate -= 1.0f;
			BD2_SC1_x -= 0.01f;
			BD2_SC1_y -= 0.05f;
			BD2_SC1_z -= 0.01f;
		}
	}
	if (counter > 72) {
		glPushMatrix();
		badGuy3();
		glPopMatrix();
		if (counter > 76 && counter < 82) {
			March += 0.03f;
		}
		if (counter > 83 && counter < 88) {
			BD1_Rotate += 1.0f;
			BD1_SC1_x += 0.02f;
			BD1_SC1_y += 0.06f;
			BD1_SC1_z += -0.01f;
			BD3_LeftHand += 1.0f;

		}
		if (counter > 88 && counter < 93) {
			BD2_Rotate += 1.0f;
			BD2_SC1_x += -0.01f;
			BD2_SC1_y += 0.05f;
			BD2_SC1_z += -0.01f;

			BD3_RightHand += 1.0f;
		}
		if (counter > 95) {
			BD3_RightHand = 0;
			BD3_LeftHand = 0;
		}
		if (counter > 97) {
			BD3_RightHand = 90;
		}
		if (counter > 100 && counter < 104) {
			BD1_SC1_z += 0.02f;
			BD1_x = 0;
			BD1_y = 1;
			BD1_LL -= 1.0f;
			if (BD1_LL == -45) {
				BD1_LL += 30;
				BD1_LL = 0;
			}
		}
		if (counter > 105 && counter < 107) {
			BD1_Rotate = 30;
		}
		if (counter > 107 && counter < 112) {
			BD2_LL = 0;
			BD2_x = 0;
			BD2_y = 1;
			BD2_SC1_x = 1.2;
			BD2_SC1_z = 1;
			BD2_Rotate += 1.0f;
		}
		if (counter > 113 && counter < 132) {
			hangTuah_Rotate += 10.0f;
		}
	}
	if (counter > 123) {
		BD1_Rotate += 2.0f;
		BD1_SC1_x += 0.1f;
		BD1_x = 1;
		BD1_y = 1;
		BD1_z = 1;

		BD2_Rotate += 2.0f;
		BD2_SC1_x += 0.1f;
		BD2_x = 1;
		BD2_y = 1;
		BD2_z = 1;
	}
	if (counter > 133 && counter < 134) {
		hangTuah_Rotate = 180;
		BD3_LeftHand = 0;
		BD3_RightHand = 0;
	}
	if (counter > 134 && counter < 138) {
		BD3_Rotate += 2.0f;
		BD3_LeftHand = 0;
		BD3_RightHand = 0;
	}
	if (counter > 139) {
		Sword_Move_z += 0.1f;
	}
	if (counter > 142 && counter < 146) {
		BD3_Rotate += 2.0f;
		BD3_SC1_x += 0.1f;
		BD3_x = 1;
		BD3_y = 1;
		BD3_z = 1;
		hangTuahRightHand = 0;
		hangTuahLeftHand = 0;
	}
	//scene3
	if (counter > 146) {

		glPushMatrix();
		Lipo(21);
		glPopMatrix();
		if (counter > 150 && counter < 155) {
			Marchlipo += 0.03f;
		}

		if (counter > 166 && counter < 170) {
			Marchlipo += 0.03f;
		}
		//scene4
		if (counter > 170) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glLoadIdentity();
			gluLookAt(5.0, -5, 14.0, 0.0, -4, 0.0, 0.0, 1.0, 0.0);
			glPushMatrix();
			sultan();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-3, -4, 0);
			hangTuah(21);
			glPopMatrix();

			glPushMatrix();
			glTranslated(3, -4, 0);
			glRotated(180, 0, 1, 0);
			Lipo(21);
			glPopMatrix();

		}

		if (counter > 170 && counter < 175) {

			hangTuahRightHand += 1.0f;
		}
		if (counter > 175 && counter < 180) {

			Marchlipo += 0.03;
			lipo_SC1_x += 0.03;
		}
		if (counter > 180 && counter < 185) {
			lipo_SC1_x += 0.009;
			lipo_SC1_y += 0.04;
		}
		if (counter > 185 && counter < 195) {
			lipo_Rotate += 1;
			lipo_y = 1;
		}
	}
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("Satria");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(1000, update, 0);
	glutMainLoop();
	return 0;
}