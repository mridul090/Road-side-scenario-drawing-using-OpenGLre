#include<windows.h>
#include <glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416
static float	tx	=  15;  /// sun
static float	ty	=  15;  /// sun
static float	cdx	=  0;   /// Cloud
static float	hx	=  5;  /// house
int cdr=230,cdg=234,cdb=237;
float c1xp=0.0;
float cdxp1=0.0;
float cdxp2=0.0;
float cdxp3=0.0;
char run[] = "Left arrow to START";
char stop[] = "Right arrow to STOP";
void BusMove_left()
{
   hx -=0.05;
   if (hx < -30)
   {
        hx = 20;
   }
    cdx +=0.003;
   if (cdx > 35)
   {
       cdx = -30;
   }
   glutPostRedisplay();
}

void print( float x, float y, char *st)
{
    int l,i;

    l=strlen( st ); // see how many characters are in text string.
    glColor3f(1.0,0.0,0.0);

    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}

void BusMove_stop()
{
    glutIdleFunc(NULL);
   glutPostRedisplay();
}
void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
	glBegin(GL_POLYGON);
		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}
	glEnd();
}
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50;


    GLfloat twicePi = 2.0f * 3.1416;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
        glEnd();
}
void angle(){
     glBegin(GL_POLYGON);
                glVertex2f(0,0);
                 glVertex2f(1,1);
                 glVertex2f(1,0);
            glEnd();
}

void Cloud()
{
      glPushMatrix();
        glTranslatef(c1xp+cdxp1,0,0);
        glColor3ub(cdr,cdg,cdb);
        drawCircle(0.15,1,1);
        drawCircle(1.2f,1.8f,1);
        drawCircle(0.9f,0.7f,1);
      glPopMatrix();
}

void draw_window(){

    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(1,0);
        glVertex2f(1,1);
        glVertex2f(0,1);
    glEnd();
}
void sky(){
 glColor3f(0.53,0.80,0.92);
    glBegin(GL_POLYGON);    ///Back Sky
            glVertex2f(-20,20);
            glVertex2f(20,20);
            glVertex2f(20,0);
            glVertex2f(-20,0);
    glEnd();
}
void field(){
    glColor3f(0.68,0.99,0.09);
    glBegin(GL_POLYGON);
        glVertex2f(20,0);
        glVertex2f(-20,0);
        glVertex2f(-20,-20);
        glVertex2f(20,-20);
    glEnd();
}
void sun(){
        glPushMatrix();         /// Sun
        glColor3f(0.99,0.64, 0.0);
        glTranslatef(tx,ty,0);
        circle(2.5,2.5);
	glPopMatrix();
}
void bus(){
    glBegin(GL_POLYGON);
                glVertex2f(0,1.7);
                glVertex2f(.7,3.5);
                glVertex2f(4,3.5);
                glVertex2f(5,3.4);
                glVertex2f(5,0);
                glVertex2f(0,0);
            glEnd();
}
void draw_Bus(){
     glPushMatrix();

            glColor3f( 1, 0, 0);
            glTranslatef(3,-8,0);
            glScalef(2,1.5,0);
            bus();
        glPopMatrix();
        ///bus_light
        glPushMatrix();

            glColor3f( 1, 1, 0);
            glTranslatef(3,-7.5,0);
            glScalef(.5,1.5,0);
            draw_window();
        glPopMatrix();
        glPushMatrix();
            glColor3f( 1, 1, 0);
            glTranslatef(12.5,-7.1,0);
            glScalef(.5,.5,0);
            draw_window();
        glPopMatrix();

        glPushMatrix();
            glColor3f( 1, 1, 0);
            glTranslatef(12.5,-7.8,0);
            glScalef(.5,.5,0);
            draw_window();
        glPopMatrix();

        ///bus_window
        glPushMatrix();
            glColor3f( 1, 1, 1);
            glTranslatef(3.2,-5.5,0);
            glScalef(1.5,2.3,0);
            angle();
        glPopMatrix();

        glPushMatrix();//1
            glColor3f( 1, 1, 1);
            glTranslatef(5,-5.5,0);
            glScalef(1.5,2.2,0);
            draw_window();
        glPopMatrix();

        glPushMatrix();//2
            glColor3f( 1, 1, 1);
            glTranslatef(7,-5.5,0);
            glScalef(1.5,2.2,0);
            draw_window();
        glPopMatrix();

        glPushMatrix();//3
            glColor3f( 1, 1, 1);
            glTranslatef(9,-5.5,0);
            glScalef(1.5,2.2,0);
            draw_window();
        glPopMatrix();

        glPushMatrix();//4
            glColor3f( 1, 1, 1);
            glTranslatef(11,-5.5,0);
            glScalef(1.5,2.2,0);
            draw_window();
        glPopMatrix();
        ///bus_wheel
        glPushMatrix();//1
            glColor3f( 0,0,0);
            glTranslatef(6,-8,0);
            circle(.9,.9);
        glPopMatrix();

        glPushMatrix();//1_1
            glColor3f( 0.752941, 0.752941, 0.752941);
            glTranslatef(6,-8,0);
            circle(.5,.5);
        glPopMatrix();

        glPushMatrix();//2
            glColor3f( 0,0,0);
            glTranslatef(11,-8,0);
            circle(.9,.9);
        glPopMatrix();

        glPushMatrix();//2_1
            glColor3f( 0.752941, 0.752941, 0.752941);
            glTranslatef(11,-8,0);
            circle(.5,.5);
        glPopMatrix();
}
void road(){
    glColor3f( .35, 0.35, .35);
    glBegin(GL_POLYGON);    ///Back field
        glVertex2f(20,-5);
        glVertex2f(-20,-5);
        glVertex2f(-20,-12);
        glVertex2f(20,-12);
    glEnd();
}

void road_border(){
    glColor3f( 1, 1, 1);

    glBegin(GL_POLYGON);    ///Back field
        glVertex2f(-20,0);
        glVertex2f(20,0);
        glVertex2f(20,1);
        glVertex2f(-20,1);
    glEnd();
}
void house()
{
    //glColor3f(0.98,0.64, 0.33);
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(5,0);
        glVertex2f(5,5);
        glVertex2f(0,5);
    glEnd();
}
void door(){
     ///Door
            glBegin(GL_POLYGON);
                glVertex2f(0,0);
                glVertex2f(2,0);
                glVertex2f(2,3);
                glVertex2f(0,3);
            glEnd();
}
void stairs()
{
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(5,0);
        glVertex2f(5,.7);
        glVertex2f(0,.7);
    glEnd();
}
void roof(){
    glBegin(GL_POLYGON);
                glVertex2f(1,2);
                glVertex2f(4,2);
                glVertex2f(5,0);
                glVertex2f(0,0);
            glEnd();
}
void triangle(){
           // glColor3f(0.0,0.0,0);
            glBegin(GL_POLYGON);
                glVertex2f(2.5,1.5);
                glVertex2f(5,0);
                glVertex2f(0,0);
            glEnd();
}
void house1(){
    glPushMatrix();
        glColor3f( 0.184314,0.184314 , 0.309804);
        glTranslatef(-14,0,0);
        glScalef(1.2,1.8,0);
        house();
    glPopMatrix();
    ///door_house
    glPushMatrix();
        glColor3f( 0.52, 0.37, 0.26);
        glTranslatef(-13.5,0.3,0);
        glScalef(.8,1.2,0);
        door();
    glPopMatrix();
    /// Stair
    glPushMatrix();
        glColor3f( 0, 0, 0);
        glTranslatef(-14,-0.7,0);
        glScalef(1.2,1.2,0);
        stairs();
    glPopMatrix();
    /// Roof
    glPushMatrix();
        glColor3f( 0, 0, 0);
        glTranslatef(-14.4,9,0);
        glScalef(1.35,1.2,0);
        stairs();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-12,4,0);
        glPushMatrix();
            glPushMatrix();
                glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(0.5,1,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                  glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(2,1,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                 glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(0.5,3,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                 glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(2,3,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    ///hotelwindow_down
    glPushMatrix();
        glTranslatef(-12,0,0);
        glPushMatrix();
            glPushMatrix();
                glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(0.5,1,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                  glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(2,1,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                 glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(0.5,3,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                 glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(2,3,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}
void house2(){
    glPushMatrix();
        glColor3f( 0.556863,0.137255 , 0.137255);
        glTranslatef(-7,0,0);
        glScalef(1,1.5,0);
        house();
    glPopMatrix();
    ///door_house
    glPushMatrix();
        glColor3f( 1, 1, 0);
        glTranslatef(-4,1,0);
        glScalef(.8,1,0);
        door();
    glPopMatrix();
    /// Stair
    glPushMatrix();
        glColor3f( 0, 0, 0);
        glTranslatef(-7,0,0);
        glScalef(1,1.2,0);
        stairs();
    glPopMatrix();
    ///hotelwindow_down
    glPushMatrix();
        glTranslatef(-7.2,3.3,0);
        glScalef(1,.8,0);
        glPushMatrix();
            glPushMatrix();
                glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(0.5,1,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                  glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(2,1,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                 glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(0.5,3,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                 glColor3f(  0.74902, 0.847059 ,0.847059);
                glTranslatef(2,3,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    ///house_roof
    glPushMatrix();
        glColor3f( 0, 0, 0);
        glTranslatef(-7.5,7.5,0);
        glScalef(1.2,1,0);
        roof();
    glPopMatrix();
}
void house3(){
        ///triangle2
         glPushMatrix();
            glColor3f( 0, 0, 0);
            glTranslatef(4,9,0);
            glScalef(1,1,0);
            triangle();
        glPopMatrix();
        ///house_top
        glPushMatrix();
            glColor3f(0.98,0.64, 0.33);
            glTranslatef(4.5,7,0);
            glScalef(.8,.4,0);
            house();
        glPopMatrix();
        ///window
        glPushMatrix();
            glColor3f( 0.8, 0.8,0.8);
            glTranslatef(6,7,0);
            glScalef(1,1.5,0);
            draw_window();
        glPopMatrix();
        /// Stairs2
        glPushMatrix();
            glColor3f( 0, 0, 0);
            glTranslatef(0,6.5,0);
            glScalef(2.5,1,0);
            stairs();
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.98,0.64, 0.33);
            glScalef(2.5,1.3,0);
            house();
        glPopMatrix();
        ///triangle
         glPushMatrix();
            glColor3f( 0, 0, 0);
            glTranslatef(5.25,3.5,0);
            glScalef(.5,1,0);
            triangle();
        glPopMatrix();
        ///door_house
         glPushMatrix();
            glColor3f( 0.52, 0.37, 0.26);
            glTranslatef(5.5,0.5,0);
            door();
        glPopMatrix();
        /// Stairs
        glPushMatrix();
            glColor3f( 0, 0, 0);
            glTranslatef(0,0,0);
            glScalef(2.5,1,0);
            stairs();
        glPopMatrix();
        ///windows
        glPushMatrix(); ///left sides
            glColor3f( 0.8, 0.8,0.8);
            glTranslatef(0.5,1,0);
            glScalef(1,1.5,0);
            draw_window();
        glPopMatrix();
        glPushMatrix();
            glColor3f( 0.8, 0.8,0.8);
            glTranslatef(2,1,0);
            glScalef(1,1.5,0);
            draw_window();
        glPopMatrix();
        glPushMatrix();
            glColor3f( 0.8, 0.8,0.8);
            glTranslatef(0.5,3,0);
            glScalef(1,1.5,0);
            draw_window();
        glPopMatrix();
        glPushMatrix();
            glColor3f( 0.8, 0.8,0.8);
            glTranslatef(2,3,0);
            glScalef(1,1.5,0);
            draw_window();
        glPopMatrix();
 glPushMatrix();///right sides
        glTranslatef(9,0,0);
        glPushMatrix();
            glPushMatrix();
                glColor3f( 0.8, 0.8,0.8);
                glTranslatef(0.5,1,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                glColor3f( 0.8, 0.8,0.8);
                glTranslatef(2,1,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                glColor3f( 0.8, 0.8,0.8);
                glTranslatef(0.5,3,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
            glPushMatrix();
                glColor3f( 0.8, 0.8,0.8);
                glTranslatef(2,3,0);
                glScalef(1,1.5,0);
                draw_window();
            glPopMatrix();
        glPopMatrix();
        glPopMatrix();
        /// end of windows function
}
void lamp_post(){

    glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(.65,3.7,0);
    glScalef(1,1,0);
    circle(.6,.6);
    glPopMatrix();

    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(.2,0,0);
    glScalef(1,.8,1);
    glBegin(GL_POLYGON);
                glVertex2f(.3,.4);
                glVertex2f(.3,4);
                glVertex2f(.7,4);
                glVertex2f(.7,0.4);

            glEnd();
    glPopMatrix();
           glBegin(GL_POLYGON);
                glVertex2f(0,0);
                glVertex2f(1.4,0);
                glVertex2f(.7,.7);
            glEnd();
}
void drawTree1()
{
glPushMatrix();
    glTranslatef(16,-0.6,0);
    glColor3f(0.52,0.37, 0.26);
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0.5,0);
        glVertex2f(0.5,2.5);
        glVertex2f(0,2.5);
    glEnd();

    glColor3f(   0.137255, 0.556863 , 0.137255);
    glPushMatrix();
    glScalef(.8,1,1);
    glBegin(GL_POLYGON);
        glVertex2f(-2,2.5);
        glVertex2f(0.2,7);
        glVertex2f(2.5,2.5);
    glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,1,0);
        glScalef(.7,1,1);
        glBegin(GL_POLYGON);
            glVertex2f(-2,3);
            glVertex2f(0.2,7);
            glVertex2f(2.5,3);
        glEnd();
    glPopMatrix();
glPopMatrix();
}

void drawTree2()
{
glPushMatrix();
    glTranslatef(-17.23,-0.6,0);
    glColor3f(0.52,0.37, 0.26);
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0.5,0);
        glVertex2f(0.5,3);
        glVertex2f(0,3);
    glEnd();
    glColor3f( 0.184314,0.309804,0.184314);
    glBegin(GL_POLYGON);
        glVertex2f(-2,3);
        glVertex2f(0.2,7);
        glVertex2f(2.5,3);
    glEnd();
    glPushMatrix();
        glTranslatef(0,2.5,0);
        glScalef(.8,.8,1);
        glBegin(GL_POLYGON);
            glVertex2f(-2,3);
            glVertex2f(0.2,7);
            glVertex2f(2.5,3);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,4.5,0);
        glScalef(.6,.6,1);
        glBegin(GL_POLYGON);
            glVertex2f(-2,3);
            glVertex2f(0.2,7);
            glVertex2f(2.5,3);
        glEnd();
    glPopMatrix();
glPopMatrix();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    ///Back Sky
    sky();
    /// Sun
    sun();

    ///cloud
    glPushMatrix();
    glTranslatef(cdx,0,0);
        glPushMatrix();
        glTranslatef(-15,13,0);
        glScalef(1.5,1,0);
        glRotatef(60,0,0,1);
        Cloud();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,17,0);
        glScalef(2,1.5,0);
        glRotatef(160,0,0,1);
        Cloud();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(14,12,0);
        glScalef(1,.5,0);
        glRotatef(-130,0,0,1);
        Cloud();
        glPopMatrix();

    glPopMatrix();

    ///Back field
    field();
    ///road
    road();
    ///road_border
    glPushMatrix();
        glTranslatef(0,-12.6,0);
        glScalef(1,.6,1);
        road_border();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,-5.6,0);
        glScalef(1,.6,1);
        road_border();
    glPopMatrix();

	///lamp_post

    glPushMatrix();
    glTranslatef(-16,-5,0);
	lamp_post();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8,-5,0);
	lamp_post();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-5,0);
	lamp_post();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(8,-5,0);
	lamp_post();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(16,-5,0);
	lamp_post();
    glPopMatrix();

    ///road_middle_border
    glPushMatrix();
    glTranslatef(0,-9,0);
    glScalef(.1,.6,1);
    road_border();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,-9,0);
    glScalef(.1,.6,1);
    road_border();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,-9,0);
    glScalef(.1,.6,1);
    road_border();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20,-9,0);
    glScalef(.1,.6,1);
    road_border();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-18,-9,0);
    glScalef(.1,.6,1);
    road_border();
    glPopMatrix();


	glPushMatrix();
    ///House1
    glTranslatef(0,0.7,0);
    house1();
    glPopMatrix();
    ///House2
    house2();
    ///House3
    house3();
    ///Tree1
    drawTree1();
    ///tree2
    drawTree2();
	glPushMatrix();
        glTranslatef(hx,0,0);
        //glScalef(2,2,0);
        draw_Bus();
	glPopMatrix();
	print(-19,12,run);
	print(-19,10.8,stop);
	glFlush();


}
void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-20.0, 20.0, -20.0, 20.0, -20.0, 20.0);
}
void spe_key(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_LEFT:
				tx -=0.01;
				glutIdleFunc(BusMove_left);
				glutPostRedisplay();
				break;
		case GLUT_KEY_RIGHT:
				//tx +=0.001;
				glutIdleFunc(BusMove_stop);
				glutPostRedisplay();
				break;
	  default:
			break;
	}
}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Translating Circle");
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(spe_key);//up,down,left,right
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
