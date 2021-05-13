#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416


GLint i; //, j, k;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0,ar=0,cr=0,bs=0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;
GLfloat spin1 = 0.0;
GLfloat spin2 = 0.0;
GLfloat spin3 = 0.0;
GLfloat spin4 = 0.0;


int ldr=255,ldg=255,ldb=255;
char school[] = "School";
char hospital[] = "Hospital";
char hotel[] = "Hotel";

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void init(void)
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, -250.0, 900.0);
}


///*** Circle_Model***///
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;

    //glColor3ub(23,60,43);
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
void print( float x, float y, char *st)
{
    int l,i;

    l=strlen( st ); // see how many characters are in text string.
    glColor3ub(13, 13, 13);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}
void Tree_One_Model()
{
    glColor3f(0.6156863,0,0);
    glBegin(GL_POLYGON);
    glVertex3i(50, 350, 0);
    glVertex3i(70, 350, 0);
    glVertex3i(70, 500, 0);
    glVertex3i(50, 500, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);
    glVertex3i(10, 500, 0);
    glVertex3i(110, 500, 0);
    glVertex3i(60, 600, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(15, 550, 0);
    glVertex3i(105, 550, 0);
    glVertex3i(60, 650, 0);
    glEnd();

}
void HotelBelowWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+19,y);
    glVertex2i(x+19,y+13);
    glVertex2i(x,y+13);
    glEnd();
    glPopMatrix();
}

void HotelAboveWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+17,y);
    glVertex2i(x+17,y+21);
    glVertex2i(x,y+21);
    glEnd();
    glPopMatrix();
}
void Hotel()
{

    glColor3ub(8,32,19);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(644,257);
    glVertex2i(644,289);
    glVertex2i(449,289);
    glEnd();



    glColor3ub(23,60,43);
    glBegin(GL_QUADS);
    glVertex2i(473,289);
    glVertex2i(500,289);
    glVertex2i(500,413);
    glVertex2i(473,413);
    glEnd();


    glColor3ub(15,47,106);
    glBegin(GL_QUADS);
    glVertex2i(500,289);
    glVertex2i(517,289);
    glVertex2i(517,435);
    glVertex2i(500,435);
    glEnd();

    glPushMatrix();  // above name plate
    glColor3ub(30,72,230);
    glBegin(GL_QUADS);
    glVertex2i(526,408);
    glVertex2i(600,408);
    glVertex2i(600,423);
    glVertex2i(526,423);
    glEnd();
    glPopMatrix();



    glColor3ub(21,63,53);
    glBegin(GL_QUADS);
    glVertex2i(517,289);
    glVertex2i(617,289);
    glVertex2i(617,408);
    glVertex2i(517,408);
    glEnd();






     int HotelBelowStripe1=-430;
    for(int i=7;i>=0;i--)
    {
        HotelBelowStripe1+=24;
        HotelBelowWindow1(HotelBelowStripe1,267);
    }

    int HotelAboveStripe1=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe1+=24;
        HotelAboveWindow1(HotelAboveStripe1,377);
    }

    int HotelAboveStripe2=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe2+=24;
        HotelAboveWindow1(HotelAboveStripe2,350);
    }

    int HotelAboveStripe3=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe3+=24;
        HotelAboveWindow1(HotelAboveStripe3,323);
    }

    int HotelAboveStripe4=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe4+=24;
        HotelAboveWindow1(HotelAboveStripe4,295);
    }
}

void Door()
{
    glColor3ub(8,32,19);
       // door
    glColor3ub(119,81,70);
    glBegin(GL_QUADS);
    glVertex2i(524,258);
    glVertex2i(570,258);
    glVertex2i(570,281);
    glVertex2i(524,281);
    glEnd();

     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(528,280);
    glVertex2i(546,280);
    glVertex2i(546,257);
    glVertex2i(528,257);
    glEnd();

     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(548,257);
    glVertex2i(565,257);
    glVertex2i(565,280);
    glVertex2i(548,280);
    glEnd();


}
void Hotel_position()
{
    glPushMatrix();
    glTranslatef(-360,-306,0);
    Hotel();
    Door();
    glPopMatrix();
}



void HospitalWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+16,y);
    glVertex2i(x+16,y+30);
    glVertex2i(x,y+30);
    glEnd();
    glPopMatrix();
}

void HospitalMidWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+12,y);
    glVertex2i(x+12,y+18);
    glVertex2i(x,y+18);
    glEnd();
    glPopMatrix();
}

void Hospital()
{
    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(151,257);
    glVertex2i(181,257);
    glVertex2i(181,424);
    glVertex2i(151,424);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(449,424);
    glVertex2i(420,424);
    glVertex2i(420,257);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(181,381);
    glVertex2i(420,381);
    glVertex2i(420,400);
    glVertex2i(181,400);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(181,258);
    glVertex2i(420,258);
    glVertex2i(420,381);
    glVertex2i(181,381);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(151,390);
    glVertex2i(181,390);
    glVertex2i(181,401);
    glVertex2i(151,401);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(420,390);
    glVertex2i(449,390);
    glVertex2i(449,401);
    glVertex2i(420,401);
    glEnd();
    glPopMatrix();

    int HospitalStripe1=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe1+=20;
        HospitalWindow1(HospitalStripe1,349);
    }

    int HospitalStripe2=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe2+=20;
        HospitalWindow1(HospitalStripe2,315);
    }

    int HospitalStripe3=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe3+=20;
        HospitalWindow1(HospitalStripe3,281);
    }

    glPushMatrix(); //middle long stripe
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(263,257);
    glVertex2i(339,257);
    glVertex2i(339,400);
    glVertex2i(263,400);
    glEnd();
    glPopMatrix();

    int HospitalStripe4=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe4+=14;
        HospitalMidWindow1(HospitalStripe4,370);
    }

    int HospitalStripe5=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe5+=14;
        HospitalMidWindow1(HospitalStripe5,340);
    }

     int HospitalStripe6=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe6+=14;
        HospitalMidWindow1(HospitalStripe6,310);
    }

    glPushMatrix();  //Door
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(286,257);
    glVertex2i(318,257);
    glVertex2i(318,298);
    glVertex2i(286,298);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
}

//******Circle******
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;

    glColor3ub(252,222,66);
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

    glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(295,395);
    glVertex2i(307,395);
    glVertex2i(307,426);
    glVertex2i(295,426);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(284,408);
    glVertex2i(318,408);
    glVertex2i(318,418);
    glVertex2i(284,418);
    glEnd();
    glPopMatrix();
}

void Hospital_position()
{
    glPushMatrix();
    glTranslatef(220,-306,0);
    Hospital();
    drawFilledCircle(300.0f,400.0f,40.0f);
    glPopMatrix();

}

void LampPost()
{
    for(int i=0;i<10*115;i+=115)
    {
        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(34+i,158);
        glVertex2i(51+i,158);
        glVertex2i(51+i,160);
        glVertex2i(34+i,160);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(37+i,160);
        glVertex2i(48+i,160);
        glVertex2i(48+i,162);
        glVertex2i(37+i,162);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(40+i,162);
        glVertex2i(45+i,162);
        glVertex2i(45+i,206);
        glVertex2i(40+i,206);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(38+i,206);
        glVertex2i(48+i,206);
        glVertex2i(48+i,209);
        glVertex2i(38+i,209);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(ldr,ldg,ldb);
        drawCircle(43+i,218,9);
        glPopMatrix();

        if(ldr==255 && ldg==244 && ldb==78)
        {
            glPushMatrix();
            glColor3ub(255,244,78);
            glBegin(GL_LINES);
            glVertex2i(43+i,218);
            glVertex2i(70+i,225);
            glEnd();

            glColor3ub(255,244,78);
            glBegin(GL_LINES);
            glVertex2i(43+i,218);
            glVertex2i(60+i,245);
            glEnd();

            glColor3ub(255,244,78);
            glBegin(GL_LINES);
            glVertex2i(43+i,218);
            glVertex2i(40+i,245);
            glEnd();

            glColor3ub(255,244,78);
            glBegin(GL_LINES);
            glVertex2i(43+i,218);
            glVertex2i(20+i,240);
            glEnd();

            glColor3ub(255,244,78);
            glBegin(GL_LINES);
            glVertex2i(43+i,218);
            glVertex2i(10+i,225);
            glEnd();

            glColor3ub(255,244,78);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2i(48+i,209);
            glVertex2i(38+i,209);
            glVertex2i(0+i,150);
            glVertex2i(80+i,150);
            glEnd();

            glPopMatrix();
        }
    }
}
void Lampost_position()
{
    glPushMatrix();
    glTranslatef(0,-309,0);
    LampPost();
    glPopMatrix();
}

void SchoolWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(190,202,200);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+20,y);
    glVertex2i(x+20,y+17);
    glVertex2i(x,y+17);
    glEnd();
    glPopMatrix();
}

void School()
{
    glPushMatrix();
    glColor3ub(214,130,5);
    glBegin(GL_QUADS);
    glVertex2i(643,257);
    glVertex2i(884,257);
    glVertex2i(884,351);
    glVertex2i(643,351);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(73,3,5);
    glBegin(GL_QUADS);
    glVertex2i(640,351);
    glVertex2i(887,351);
    glVertex2i(887,358);
    glVertex2i(640,358);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(648,265);
    glVertex2i(719,265);
    glVertex2i(719,275);
    glVertex2i(648,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(808,265);
    glVertex2i(879,265);
    glVertex2i(879,275);
    glVertex2i(808,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(217,132,3);
    glBegin(GL_POLYGON);
    glVertex2i(713,358);
    glVertex2i(813,358);
    glVertex2i(813,381);
    glVertex2i(763,402);
    glVertex2i(713,381);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(707,381);
    glVertex2i(819,381);
    glVertex2i(763,409);
    glEnd();
    glPopMatrix();

    glColor3ub(200,200,240);
    drawCircle(762.0f,369.0f,10.0f);

    int SchoolStripe1=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe1+=25;
        SchoolWindow1(SchoolStripe1,328);
    }

     int SchoolStripe2=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe2+=25;
        SchoolWindow1(SchoolStripe2,304);
    }

    int SchoolStripe3=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe3+=25;
        SchoolWindow1(SchoolStripe3,281);
    }

    int SchoolStripe4=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe4+=25;
        SchoolWindow1(SchoolStripe4,328);
    }

    int SchoolStripe5=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe5+=25;
        SchoolWindow1(SchoolStripe5,304);
    }

    int SchoolStripe6=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe6+=25;
        SchoolWindow1(SchoolStripe6,282);
    }

}
void SchoolDoor()
{
    glPushMatrix();
    glColor3ub(72,2,4);
    glBegin(GL_QUADS);
    glVertex2i(728,257);
    glVertex2i(797,257);
    glVertex2i(797,321);
    glVertex2i(728,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(722,321);
    glVertex2i(803,321);
    glVertex2i(763,347);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(100,150,100);
    glBegin(GL_QUADS);
    glVertex2i(733,304);
    glVertex2i(792,304);
    glVertex2i(792,321);
    glVertex2i(733,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(89,107,121);
    glBegin(GL_QUADS);
    glVertex2i(743,257);
    glVertex2i(782,257);
    glVertex2i(782,295);
    glVertex2i(743,295);
    glEnd();
    glPopMatrix();
}

void School_position()
{
    glPushMatrix();
    glTranslatef(110,-306,0);
    School();
    SchoolDoor();
    glPopMatrix();

}



void Tree_One(){

    glPushMatrix();
    glTranslatef(0,-400,0);
    Tree_One_Model();
    glPopMatrix();

}



void Tree_Two(){

    glPushMatrix();
    glTranslatef(260,-400,0);
    Tree_One_Model();
    glPopMatrix();

}

void Tree_Three(){

    glPushMatrix();
    glTranslatef(665,-400,0);
    Tree_One_Model();
    glPopMatrix();

}




/// *** Sun_Model **///
void Sun_Model(){
    glPushMatrix();
    glTranslatef(200,840,0);
    circle(30);
    glPopMatrix();

}
///*** Airplane model***///
void airplane_model()
{
    ///Airplane body
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(5, 450);
	glVertex2i(30, 450);
	glVertex2i(45, 420);
	glVertex2i(5, 420);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 1.5);
	glVertex2i(5, 420);
	glVertex2i(140, 420);
	glVertex2i(150, 410);
	glVertex2i(160, 410);
	glVertex2i(165, 400);
	glVertex2i(160, 390);
	glVertex2i(15, 390);
	glVertex2i(5, 400);
	glVertex2i(5, 420);
	glEnd();
    ///Airplane lower red part
	glBegin(GL_POLYGON);
    glColor3f(0.8, 0.0, 0.0);
    glVertex2i(165, 400);
	glVertex2i(160, 390);
	glVertex2i(15, 390);
	glVertex2i(5, 400);
	glEnd();
    ///Airplane windows
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(140, 420);
	glVertex2i(150, 410);
	glVertex2i(140, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(100, 415);
	glVertex2i(105, 415);
	glVertex2i(105, 410);
	glVertex2i(100, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(110, 415);
	glVertex2i(115, 415);
	glVertex2i(115, 410);
	glVertex2i(110, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(90, 415);
	glVertex2i(95, 415);
	glVertex2i(95, 410);
	glVertex2i(90, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(80, 415);
	glVertex2i(85, 415);
	glVertex2i(85, 410);
	glVertex2i(80, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(70, 415);
	glVertex2i(75, 415);
	glVertex2i(75, 410);
	glVertex2i(70, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(60, 415);
	glVertex2i(65, 415);
	glVertex2i(65, 410);
	glVertex2i(60, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(50, 415);
	glVertex2i(55, 415);
	glVertex2i(55, 410);
	glVertex2i(50, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(40, 415);
	glVertex2i(45, 415);
	glVertex2i(45, 410);
	glVertex2i(40, 410);
	glEnd();
    ///Airplane wings
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(65, 420);
	glVertex2i(60, 435);
	glVertex2i(80, 435);
	glVertex2i(95, 420);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(65, 390);
	glVertex2i(60, 375);
	glVertex2i(80, 375);
	glVertex2i(95, 390);
	glEnd();
}


///*** Cloud_Model***///
void cloud_model_one(){

    glColor3f(1.25, 0.924, 0.930);
    ///Top_Left
    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ///Right

    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();


    ///middle_Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,204,0);
    circle(10);
    glPopMatrix();

    ///****Fill End****

}

void cloud_model_Two(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(305,205,0);
    circle(10);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(334,207,0);
    circle(10);
    glPopMatrix();

    ///Bottom_Part
    glPushMatrix();
    glTranslatef(320,207,0);
    circle(10);
    glPopMatrix();



}

void cloud_model_Three(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(300,200,0);
    circle(15);
    glPopMatrix();

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340,220,0);
    circle(16);
    glPopMatrix();

    ///Top_Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(380,200,0);
    circle(15);
    glPopMatrix();

    ///Bottom_Right
    glPushMatrix();
    glTranslatef(360,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom_Left
    glPushMatrix();
    glTranslatef(320,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom
    glPushMatrix();
    glTranslatef(340,190,0);
    circle(20);
    glPopMatrix();


}
///*** Hill_Model***///
void hill_big(){

    ///Hill
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(70, 70);
	glVertex2i(200, 225);
	glVertex2i(330, 70);

	glEnd();

	///Hill_Snow
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);

	glVertex2i(200, 225);
	glVertex2i(230, 190);
	glVertex2i(220, 180);
	glVertex2i(200, 190);
	glVertex2i(190, 180);
	glVertex2i(170, 190);

	glEnd();

}
///*** House_Model ***///
void house(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);

	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);

	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);

	glEnd();

    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);

	glEnd();

    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();


}

/// HILL Updated

void hill_large_up(){

	glBegin(GL_POLYGON);
    glColor3f(   0.52, 0.37 , 0.26);
	glVertex2i(180, 120);
	glVertex2i(270, 360);
	glVertex2i(350, 120);

	glEnd();


}


void hill_small_up(){

	glBegin(GL_POLYGON);
    glColor3f(  0.82 ,0.55 , 0.30);
	glVertex2i(180, 100);
	glVertex2i(250, 250);
	glVertex2i(320, 100);

	glEnd();


}


void road_model()
{

    glBegin(GL_QUADS);
    glColor3f(0.658824 , 0.658824 , 0.658824);
	glVertex2i(0,0);
	glVertex2i(0,-250);
	glVertex2i(1000,-250);
	glVertex2i(1000, 0);

	glEnd();

}
void RoadCorner1()
{
    for(int i=0;i<16*70;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner2()
{
    for(int i=0;i<16*70;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148-100);
        glVertex2i(16+i,148-100);
        glVertex2i(16+i,157-100);
        glVertex2i(0+i,157-100);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148-100);
        glVertex2i(39+i,148-100);
        glVertex2i(39+i,157-100);
        glVertex2i(16+i,157-100);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner1_position()
{
    glPushMatrix();
    glTranslatef(0,-200,0);
    RoadCorner1();
    glPopMatrix();
}

void RoadCorner2_position()
{
    glPushMatrix();
    glTranslatef(0,-300,0);
    RoadCorner2();
    glPopMatrix();
}



void car_model_1()
{
    glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(10, -10);
	glVertex2i(80, -10);
	glVertex2i(95, -40);
	glVertex2i(95, -80);
	glVertex2i(10, -80);

	glEnd();

	//
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(95, -40);
	glVertex2i(125, -40);
	glVertex2i(135, -80);
	glVertex2i(95, -80);


	glEnd();

	//window 1

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(15, -15);
	glVertex2i(40, -15);
	glVertex2i(40, -40);
	glVertex2i(15, -40);
	glEnd();


	//window2
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(50, -15);
	glVertex2i(78, -15);
	glVertex2i(90, -40);
	glVertex2i(50, -40);


	glEnd();

	//line
	glLineWidth(5);

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(9,-80 );
	glVertex2i(136,-80);

	glEnd();


	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(110,-80,0);
    circle(15);
    glPopMatrix();
    //circle small
    glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
    glTranslatef(110,-80,0);
    circle(10);
    glPopMatrix();

    //circle2

	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(35,-80,0);
    circle(15);
    glPopMatrix();
    //circle2 small
    glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
    glTranslatef(35,-80,0);
    circle(10);
    glPopMatrix();



}

void car_model_2()
{
    glBegin(GL_POLYGON);
	glColor3f(0.4, 0, 0);
	glVertex2i(300, -15);
	glVertex2i(280, -52);
	glVertex2i(280, -110);
	glVertex2i(480, -110);
	glVertex2i(480, -15);

	glEnd();

	//triagle
    glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2i(300, -15);
	glVertex2i(280, -52);
	glVertex2i(300, -52);

	glEnd();

	//square

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(305, -25);
	glVertex2i(305, -52);
	glVertex2i(470, -52);
	glVertex2i(470, -25);

	glEnd();




//big square
    glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2i(305, -28);
	glVertex2i(325, -28);
	glVertex2i(325, -60);
	glVertex2i(305, -60);

	glEnd();
	//big square white
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(325, -28);
	glVertex2i(340, -28);
	glVertex2i(340, -80);
	glVertex2i(325, -80);

	glEnd();

	//window 1

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(345, -28);
	glVertex2i(380, -28);
	glVertex2i(380, -50);
	glVertex2i(345, -50);

	glEnd();

	//window 2
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(385, -28);
	glVertex2i(415, -28);
	glVertex2i(415, -50);
	glVertex2i(385, -50);

	glEnd();

	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(310,-110,0);
    circle(15);
    glPopMatrix();

    //circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(450,-110,0);
    circle(15);
    glPopMatrix();



}

///*** Field_Model ***///

void field(){
    ///Field
	glBegin(GL_POLYGON);
	glColor3f( 0.0 , 0.80 ,0.0);

    //glColor3f(0.137255 , 0.556863 , 0.137255);
	glVertex2i(0, 50);
	glVertex2i(0, 200);// ch=70to 200
	glVertex2i(1000, 200); //    ||
	glVertex2i(1000, 50);

	glEnd();


    ///Field_Shadow
	glBegin(GL_POLYGON);
	glColor3f( 0.419608 , 0.556863 , 0.137255);
	glVertex2i(0, -50);  //change
	glVertex2i(0, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, -50); //change

	glEnd();
}


///Tilla with 2 dff houses

void Tilla()
{
    ///  lines

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 205);
	glVertex2i(756, 180);
	glEnd();


	//

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(760, 205);
	glVertex2i(760, 170);
	glEnd();


	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(764, 205);
	glVertex2i(764, 160);
	glEnd();

	//

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(768, 205);
	glVertex2i(768, 150);
	glEnd();

	//
	glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(772, 205);
	glVertex2i(772, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(776, 205);
	glVertex2i(776, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(780, 205);
	glVertex2i(780, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(784, 205);
	glVertex2i(784, 140);
	glEnd();


//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 205);
	glVertex2i(788, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(792, 205);
	glVertex2i(792, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(826, 205);
	glVertex2i(826, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(830, 205);
	glVertex2i(830, 140);
	glEnd();
	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(834, 205);
	glVertex2i(834, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(838, 205);
	glVertex2i(838, 140);

	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(842, 205);
	glVertex2i(842, 140);


	glEnd();


    ///house 1
    glBegin(GL_POLYGON);
    glColor3f(0.99 , 0.99 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(820, 190);
	glVertex2i(820, 260);
	glVertex2i(860, 260);
	glVertex2i(860, 190);

	glEnd();
//dark shade
    glBegin(GL_POLYGON);
    glColor3f(0.9 , 0.9 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(820, 190);
	glVertex2i(820, 260);
	glVertex2i(800, 260);
	glVertex2i(800, 210);
	glEnd();


	//triangle
    glBegin(GL_POLYGON);
    glColor3f(0.5 , 0.5 , 0.5);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(760, 290);
	glVertex2i(755, 270);
	glVertex2i(771, 270);
	glEnd();


	//roof

    glBegin(GL_POLYGON);
    glColor3f(0.9 , 0.9 , 0.9);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(863, 260);
	glVertex2i(853, 290);
	glVertex2i(760, 290);
	glVertex2i(770, 260);
	glEnd();



	//lower poly
	glBegin(GL_POLYGON);
    glColor3f(0.8 , 0.8 , 0.8);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(800, 210);
	glVertex2i(755, 205);
	glVertex2i(770, 175);
	glVertex2i(820, 190);

	glEnd();


    //fence

    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.6 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 270);
	glVertex2i(756, 230);
	glEnd();


    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.6 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 260);
	glVertex2i(771, 200);
	glEnd();

	glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 230);
	glVertex2i(771, 200);


	glEnd();


	glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 230);

	glVertex2i(800, 230);


	glEnd();

	//
	glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 200);

	glVertex2i(788, 200);


	glEnd();

	//


   glLineWidth(5);
   glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 230);

	glVertex2i(756, 205);


	glEnd();

	//

	glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 200);

	glVertex2i(771, 175);


	glEnd();

	//
	glLineWidth(5);
   glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 205);

	glVertex2i(771, 175);


	glEnd();

	//


    glLineWidth(6);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 175);

	glVertex2i(788, 175);


	glEnd();
	 glBegin(GL_POLYGON);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 200);
	glVertex2i(788, 165);

	glVertex2i(800, 136);


	glEnd();


	//stair



   glBegin(GL_POLYGON);

    glColor3f(0.7 , 0.7 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 189);
	glVertex2i(800, 136);

	glVertex2i(832, 136);

    glVertex2i(820, 189);

	glEnd();

	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 182);

	glVertex2i(820, 182);


	glEnd();
	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 175);

	glVertex2i(822, 175);


	glEnd();

	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 168);

	glVertex2i(823, 168);


	glEnd();

	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 161);

	glVertex2i(824, 161);


	glEnd();

	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(792, 154);

	glVertex2i(824, 154);


	glEnd();

	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(796, 147);

	glVertex2i(824, 147);


	glEnd();



//
	glLineWidth(7);
   glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 200);

	glVertex2i(800, 136);


	glEnd();

//
	glLineWidth(7);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(820, 190);

	glVertex2i(832, 136);


	glEnd();

    //tilla road mud
	glBegin(GL_POLYGON);
    glColor3f(  0.92 ,0.75 , 0.50);
    //glColor3f(0.623529 , 0.623529 , 0.372549);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(910, 310);
	glVertex2i(830, 160);

	glVertex2i(850, 160);
	glVertex2i(930, 290);

	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(  0.92 ,0.75 , 0.50);
    //glColor3f(0.623529 , 0.623529 , 0.372549);

	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(830, 160);
	glVertex2i(800, 130);
	glVertex2i(840, 130);
	glVertex2i(850, 160);


	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(  0.92 ,0.75 , 0.50);

    //glColor3f(0.623529 , 0.623529 , 0.372549);

	//glColor3f(0.196078 ,0.8, 0.196078);

	glVertex2i(840, 130);
	glVertex2i(740, 130);
	glVertex2i(740, 110);
	glVertex2i(840, 110);
	glEnd();



   //tilla green
    glBegin(GL_POLYGON);
    glColor3f( 0.576471 , 0.858824, 0.439216);
    //glColor3f(0.196078 ,0.8, 0.196078);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(1000, 370);
	glVertex2i(920, 370);
	glVertex2i(900, 260);
	glVertex2i(825, 110);
	glVertex2i(1000, 110);

	glEnd();


	///Tilla house 1
    //square
    glBegin(GL_POLYGON);
    glColor3f(1 ,1, 1);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(950, 370);
	glVertex2i(970, 370);
	glVertex2i(970, 410);
	glVertex2i(950, 410);


	glEnd();

	//window

    glBegin(GL_POLYGON);
    glColor3f(0 ,0, 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(965, 385);
	glVertex2i(965, 400);
	glVertex2i(955, 400);
	glVertex2i(955, 385);
	glEnd();
	//door part


    glBegin(GL_POLYGON);
    glColor3f(0.97 ,0.97, 0.97);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(950, 370);
	glVertex2i(950, 425);
	glVertex2i(939, 425);
	glVertex2i(939, 374);

	glEnd();
	//roof

	glBegin(GL_POLYGON);
    glColor3f(1 ,0, 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(948, 410);
	glVertex2i(972, 410);
	glVertex2i(966, 460);
	glVertex2i(942, 460);
	glEnd();

	//small triangle


    glBegin(GL_POLYGON);
    glColor3f(0.5 ,0, 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(942, 460);
	glVertex2i(935, 425);
	glVertex2i(946, 425);
	glEnd();



}
/// Tree model updated

void Tree_Model_circle_1(){

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f( 0.3, 0,0); //dark red
	glVertex2f(130, 130);
	glVertex2f(130, 95);
    glEnd();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(130,130,0);
    circle(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(125,126,0);
    circle(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(135,126,0);
    circle(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(130,125,0);
    circle(10);
    glPopMatrix();


}

void Tree_Model_circle_2(){

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f( 0.3, 0,0); //dark red
	glVertex2f(133, 125);
	glVertex2f(133, 92);
    glEnd();

    glColor3f( 0, 0.198039,0);
    glBegin(GL_POLYGON);
	glVertex2f(123, 123);
	glVertex2f(134, 147);
	glVertex2f(147, 123);

	glEnd();

}


/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model(){

    glColor3ub(141, 47, 47);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

///*** Windmill_Blades_Model ***///

void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///*** Windmill_Final_Model ***///
void Windmill(){

        ///Windmill_Stand
    glColor3ub(141, 47, 47);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    glColor3ub(243, 239, 239 );
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3ub(243, 239, 239 );
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();
}
///*** Sun ***///
void Sun(){
    glColor3f(1, 1, 0);
    glPushMatrix();
    glRotatef(-spin4,0,0,90);
    Sun_Model();
    glPopMatrix();
}

///*** Cloud_One_Model_One ***///
void airplane(){
    glPushMatrix();
    glTranslatef(ar-300,200,0);
    airplane_model();
    glPopMatrix();

}

///*** Cloud_One_Model_One ***///
void cloud_one(){
    glPushMatrix();
    glTranslatef(cx,500,0);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Two_Model_one ***///

void cloud_two(){
    glPushMatrix();
    glTranslatef(bx+100,300,0);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Three_Model_Two ***///

void cloud_three(){
    glPushMatrix();
    glTranslatef(ax-80,400,0);
    cloud_model_Two();
    glPopMatrix();

}
///*** Cloud_Four_Model_Two ***///

void cloud_four(){
    glPushMatrix();
    glTranslatef(dx+300,610,0);
    cloud_model_Two();
    glPopMatrix();

}
///*** Cloud_Five_Model_Three ***///
void cloud_five()
{
    glPushMatrix();
    glTranslatef(ax-300,456,0);
    cloud_model_Three();
    glPopMatrix();
}
///*** Cloud_Six_Model_Three ***///
void cloud_six()
{
    glPushMatrix();
    glTranslatef(cx+500,340,0);
    cloud_model_Three();
    glPopMatrix();
}
void house_three()
{
    glPushMatrix();
    glTranslatef(140,130,0);
    house();
    glPopMatrix();
}
///*** Hill_big_One ***///
void Hill_Big_One()
{
    glPushMatrix();
    glTranslatef(-100,100,0);
    hill_big();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two()
{
    glPushMatrix();
    glTranslatef(90,100,0);
    hill_big();
    glPopMatrix();
}

/// *** Windmill ***///
void Windmill_One()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0,100,0);
    Windmill();
    glPopMatrix();

}

void Windmill_Two()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(150,100,0);
    Windmill();
    glPopMatrix();

}
void Windmill_Three()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(270,100,0);
    Windmill();
    glPopMatrix();

}

void hill_large_up_pos1()
{
    glPushMatrix();
    glTranslatef(350,-5,0);
    hill_large_up();
    glPopMatrix();

}

void hill_small_up_pos1()
{

    glPushMatrix();
    glTranslatef(460,10,0);
    hill_small_up();
    glPopMatrix();

}

void Tree_Circle1_pos1(){


    glPushMatrix();
    glTranslatef(734,90,0);
    Tree_Model_circle_1();
    glPopMatrix();

}
void Tree_Circle1_pos2(){


    glPushMatrix();
    glTranslatef(767,195,0);
    Tree_Model_circle_1();
    glPopMatrix();

}

void Tree_Circle2_pos1(){

    glPushMatrix();
    glTranslatef(745,140,0);
    Tree_Model_circle_2();
    glPopMatrix();

}
void car_1(){
    glPushMatrix();
    glTranslatef(cr-200,-50,0);
    car_model_1();
    glPopMatrix();

}

void Bus(){
    glPushMatrix();
    glTranslatef(bs+800,-135,0);
    car_model_2();
    glPopMatrix();

}
void house_four()
{
    glPushMatrix();
    glTranslatef(-120,70,0);
    house();
    glPopMatrix();
}
///========================///
///*** Night Function Start***///
///========================///


///*** Circle_Model***///
void circle_Night(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
void drawCircle_Night(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;

    //glColor3ub(23,60,43);
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
void print_Night( float x, float y, char *st)
{
    int l,i;

    l=strlen( st ); // see how many characters are in text string.
    glColor3ub(13, 13, 13);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}

void Tree_One_Model_Night()
{
    glColor3ub(0.6156863,0,0);
    glBegin(GL_POLYGON);
    glVertex3i(50, 350, 0);
    glVertex3i(70, 350, 0);
    glVertex3i(70, 500, 0);
    glVertex3i(50, 500, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);
    glVertex3i(10, 500, 0);
    glVertex3i(110, 500, 0);
    glVertex3i(60, 600, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(15, 550, 0);
    glVertex3i(105, 550, 0);
    glVertex3i(60, 650, 0);
    glEnd();

}
void HotelBelowWindow1_Night(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+19,y);
    glVertex2i(x+19,y+13);
    glVertex2i(x,y+13);
    glEnd();
    glPopMatrix();
}

void HotelAboveWindow1_Night(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+17,y);
    glVertex2i(x+17,y+21);
    glVertex2i(x,y+21);
    glEnd();
    glPopMatrix();
}




void Hotel_Night()
{

    glColor3ub(8,32,19);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(644,257);
    glVertex2i(644,289);
    glVertex2i(449,289);
    glEnd();



    glColor3ub(23,60,43);
    glBegin(GL_QUADS);
    glVertex2i(473,289);
    glVertex2i(500,289);
    glVertex2i(500,413);
    glVertex2i(473,413);
    glEnd();


    glColor3ub(15,47,106);
    glBegin(GL_QUADS);
    glVertex2i(500,289);
    glVertex2i(517,289);
    glVertex2i(517,435);
    glVertex2i(500,435);
    glEnd();

    glPushMatrix();  // above name plate
    glColor3ub(30,72,230);
    glBegin(GL_QUADS);
    glVertex2i(526,408);
    glVertex2i(600,408);
    glVertex2i(600,423);
    glVertex2i(526,423);
    glEnd();
    glPopMatrix();



    glColor3ub(21,63,53);
    glBegin(GL_QUADS);
    glVertex2i(517,289);
    glVertex2i(617,289);
    glVertex2i(617,408);
    glVertex2i(517,408);
    glEnd();






     int HotelBelowStripe1=-430;
    for(int i=7;i>=0;i--)
    {
        HotelBelowStripe1+=24;
        HotelBelowWindow1_Night(HotelBelowStripe1,267);
    }

    int HotelAboveStripe1=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe1+=24;
        HotelAboveWindow1_Night(HotelAboveStripe1,377);
    }

    int HotelAboveStripe2=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe2+=24;
        HotelAboveWindow1_Night(HotelAboveStripe2,350);
    }

    int HotelAboveStripe3=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe3+=24;
        HotelAboveWindow1_Night(HotelAboveStripe3,323);
    }

    int HotelAboveStripe4=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe4+=24;
        HotelAboveWindow1_Night(HotelAboveStripe4,295);
    }
}

void Door_Night()
{
    glColor3ub(8,402,19);
       // door
    glColor3ub(119,81,70);
    glBegin(GL_QUADS);
    glVertex2i(524,258);
    glVertex2i(570,258);
    glVertex2i(570,281);
    glVertex2i(524,281);
    glEnd();

     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(528,280);
    glVertex2i(546,280);
    glVertex2i(546,257);
    glVertex2i(528,257);
    glEnd();

     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(548,257);
    glVertex2i(565,257);
    glVertex2i(565,280);
    glVertex2i(548,280);
    glEnd();


}
void Hotel_position_Night()
{
    glPushMatrix();
    glTranslatef(-360,-306,0);
    Hotel_Night();
    Door_Night();
    glPopMatrix();
}



void HospitalWindow1_Night(int x,int y)
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+16,y);
    glVertex2i(x+16,y+30);
    glVertex2i(x,y+30);
    glEnd();
    glPopMatrix();
}

void HospitalMidWindow1_Night(int x,int y)
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+12,y);
    glVertex2i(x+12,y+18);
    glVertex2i(x,y+18);
    glEnd();
    glPopMatrix();
}

void Hospital_Night()
{
    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(151,257);
    glVertex2i(181,257);
    glVertex2i(181,424);
    glVertex2i(151,424);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(449,424);
    glVertex2i(420,424);
    glVertex2i(420,257);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(181,381);
    glVertex2i(420,381);
    glVertex2i(420,400);
    glVertex2i(181,400);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(190,27,9);
    glBegin(GL_QUADS);
    glVertex2i(181,258);
    glVertex2i(420,258);
    glVertex2i(420,381);
    glVertex2i(181,381);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(151,390);
    glVertex2i(181,390);
    glVertex2i(181,401);
    glVertex2i(151,401);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(420,390);
    glVertex2i(449,390);
    glVertex2i(449,401);
    glVertex2i(420,401);
    glEnd();
    glPopMatrix();

    int HospitalStripe1=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe1+=20;
        HospitalWindow1_Night(HospitalStripe1,349);
    }

    int HospitalStripe2=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe2+=20;
        HospitalWindow1_Night(HospitalStripe2,315);
    }

    int HospitalStripe3=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe3+=20;
        HospitalWindow1_Night(HospitalStripe3,281);
    }

    glPushMatrix(); //middle long stripe
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(263,257);
    glVertex2i(339,257);
    glVertex2i(339,400);
    glVertex2i(263,400);
    glEnd();
    glPopMatrix();

    int HospitalStripe4=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe4+=14;
        HospitalMidWindow1_Night(HospitalStripe4,370);
    }

    int HospitalStripe5=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe5+=14;
        HospitalMidWindow1_Night(HospitalStripe5,340);
    }

     int HospitalStripe6=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe6+=14;
        HospitalMidWindow1_Night(HospitalStripe6,310);
    }

    glPushMatrix();  //Door
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(286,257);
    glVertex2i(318,257);
    glVertex2i(318,298);
    glVertex2i(286,298);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
}

//******Circle******
void drawFilledCircle_Night(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;

    glColor3ub(252,20,255);
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

    glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(295,395);
    glVertex2i(307,395);
    glVertex2i(307,426);
    glVertex2i(295,426);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(284,408);
    glVertex2i(318,408);
    glVertex2i(318,418);
    glVertex2i(284,418);
    glEnd();
    glPopMatrix();
}

void Hospital_position_Night()
{
    glPushMatrix();
    glTranslatef(220,-306,0);
    Hospital_Night();
    drawFilledCircle_Night(300.0f,400.0f,40.0f);
    glPopMatrix();

}

void LampPost_Night()
{
    for(int i=0;i<10*115;i+=115)
    {
        glPushMatrix();
        glColor3ub(150,177,144);
        glBegin(GL_QUADS);
        glVertex2i(34+i,158);
        glVertex2i(51+i,158);
        glVertex2i(51+i,160);
        glVertex2i(34+i,160);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(255,200,255);
        glBegin(GL_QUADS);
        glVertex2i(37+i,160);
        glVertex2i(48+i,160);
        glVertex2i(48+i,162);
        glVertex2i(37+i,162);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(100,50,10);
        glBegin(GL_QUADS);
        glVertex2i(40+i,162);
        glVertex2i(45+i,162);
        glVertex2i(45+i,206);
        glVertex2i(40+i,206);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(38+i,206);
        glVertex2i(48+i,206);
        glVertex2i(48+i,209);
        glVertex2i(38+i,209);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(ldr,ldg,ldb);
        drawCircle_Night(43+i,218,9);
        glPopMatrix();
    }
}
void Lampost_position_Night()
{
    glPushMatrix();
    glTranslatef(0,-309,0);
    LampPost_Night();
    glPopMatrix();
}

void SchoolWindow1_Night(int x,int y)
{
    glPushMatrix();
    glColor3ub(190,202,200);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+20,y);
    glVertex2i(x+20,y+17);
    glVertex2i(x,y+17);
    glEnd();
    glPopMatrix();
}

void School_Night()
{
    glPushMatrix();
    glColor3ub(214,530,520);
    glBegin(GL_QUADS);
    glVertex2i(643,257);
    glVertex2i(884,257);
    glVertex2i(884,351);
    glVertex2i(643,351);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(73,3,5);
    glBegin(GL_QUADS);
    glVertex2i(640,351);
    glVertex2i(887,351);
    glVertex2i(887,358);
    glVertex2i(640,358);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(648,265);
    glVertex2i(719,265);
    glVertex2i(719,275);
    glVertex2i(648,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(808,265);
    glVertex2i(879,265);
    glVertex2i(879,275);
    glVertex2i(808,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(217,132,3);
    glBegin(GL_POLYGON);
    glVertex2i(713,358);
    glVertex2i(813,358);
    glVertex2i(813,381);
    glVertex2i(763,402);
    glVertex2i(713,381);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(707,381);
    glVertex2i(819,381);
    glVertex2i(763,409);
    glEnd();
    glPopMatrix();

    glColor3ub(200,200,240);
    drawCircle_Night(762.0f,369.0f,10.0f);

    int SchoolStripe1=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe1+=25;
        SchoolWindow1_Night(SchoolStripe1,328);
    }

     int SchoolStripe2=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe2+=25;
        SchoolWindow1_Night(SchoolStripe2,304);
    }

    int SchoolStripe3=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe3+=25;
        SchoolWindow1_Night(SchoolStripe3,281);
    }

    int SchoolStripe4=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe4+=25;
        SchoolWindow1_Night(SchoolStripe4,328);
    }

    int SchoolStripe5=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe5+=25;
        SchoolWindow1_Night(SchoolStripe5,304);
    }

    int SchoolStripe6=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe6+=25;
        SchoolWindow1_Night(SchoolStripe6,282);
    }

}
void SchoolDoor_Night()
{
    glPushMatrix();
    glColor3ub(72,2,4);
    glBegin(GL_QUADS);
    glVertex2i(728,257);
    glVertex2i(797,257);
    glVertex2i(797,321);
    glVertex2i(728,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(722,321);
    glVertex2i(803,321);
    glVertex2i(763,347);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(100,150,100);
    glBegin(GL_QUADS);
    glVertex2i(733,304);
    glVertex2i(792,304);
    glVertex2i(792,321);
    glVertex2i(733,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(89,107,121);
    glBegin(GL_QUADS);
    glVertex2i(743,257);
    glVertex2i(782,257);
    glVertex2i(782,295);
    glVertex2i(743,295);
    glEnd();
    glPopMatrix();
}

void School_position_Night()
{
    glPushMatrix();
    glTranslatef(110,-306,0);
    School_Night();
    SchoolDoor_Night();
    glPopMatrix();

}



void Tree_One_Night(){

    glPushMatrix();
    glTranslatef(0,-400,0);
    Tree_One_Model_Night();
    glPopMatrix();

}



void Tree_Two_Night(){

    glPushMatrix();
    glTranslatef(260,-400,0);
    Tree_One_Model_Night();
    glPopMatrix();

}

void Tree_Three_Night(){

    glPushMatrix();
    glTranslatef(665,-400,0);
    Tree_One_Model_Night();
    glPopMatrix();

}




void Moon_Night()
{
    glPushMatrix();
    glColor3ub(247, 245, 245);
    drawCircle_Night(740.0f,640.0f,40.0f);
    glColor3ub(247, 245, 245);
    drawCircle_Night(740.0f,640.0f,40.0f);
    glPopMatrix();
}

void Moon_Night_Position()
{
    glPushMatrix();
    glTranslatef(-500,180,0);
    Moon_Night();
    glPopMatrix();
}


///*** Airplane model***///
void airplane_model_Night()
{
    ///Airplane body
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(5, 450);
	glVertex2i(30, 450);
	glVertex2i(45, 420);
	glVertex2i(5, 420);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 1.5);
	glVertex2i(5, 420);
	glVertex2i(140, 420);
	glVertex2i(150, 410);
	glVertex2i(160, 410);
	glVertex2i(165, 400);
	glVertex2i(160, 390);
	glVertex2i(15, 390);
	glVertex2i(5, 400);
	glVertex2i(5, 420);
	glEnd();
    ///Airplane lower red part
	glBegin(GL_POLYGON);
    glColor3f(0.8, 0.0, 0.0);
    glVertex2i(165, 400);
	glVertex2i(160, 390);
	glVertex2i(15, 390);
	glVertex2i(5, 400);
	glEnd();
    ///Airplane windows
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(140, 420);
	glVertex2i(150, 410);
	glVertex2i(140, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(100, 415);
	glVertex2i(105, 415);
	glVertex2i(105, 410);
	glVertex2i(100, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(110, 415);
	glVertex2i(115, 415);
	glVertex2i(115, 410);
	glVertex2i(110, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(90, 415);
	glVertex2i(95, 415);
	glVertex2i(95, 410);
	glVertex2i(90, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(80, 415);
	glVertex2i(85, 415);
	glVertex2i(85, 410);
	glVertex2i(80, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(70, 415);
	glVertex2i(75, 415);
	glVertex2i(75, 410);
	glVertex2i(70, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(60, 415);
	glVertex2i(65, 415);
	glVertex2i(65, 410);
	glVertex2i(60, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(50, 415);
	glVertex2i(55, 415);
	glVertex2i(55, 410);
	glVertex2i(50, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(40, 415);
	glVertex2i(45, 415);
	glVertex2i(45, 410);
	glVertex2i(40, 410);
	glEnd();
    ///Airplane wings
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(65, 420);
	glVertex2i(60, 435);
	glVertex2i(80, 435);
	glVertex2i(95, 420);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(65, 390);
	glVertex2i(60, 375);
	glVertex2i(80, 375);
	glVertex2i(95, 390);
	glEnd();
}


/*** Hill_Model***///
void hill_big_Night(){

    ///Hill
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(70, 70);
	glVertex2i(200, 225);
	glVertex2i(330, 70);

	glEnd();


}
///*** House_Model ***///
void house_Night(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);

	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);

	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(1.555, 1.0, 21.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);

	glEnd();

    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);

	glEnd();

    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();


}

/// HILL Updated

void hill_large_up_Night(){

	glBegin(GL_POLYGON);
    glColor3f( 0.38, 0.41, 0.36);
	glVertex2i(180, 120);
	glVertex2i(270, 360);
	glVertex2i(350, 120);

	glEnd();


}


void hill_small_up_Night(){

	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(180, 100);
	glVertex2i(250, 250);
	glVertex2i(320, 100);

	glEnd();


}


void road_model_Night()
{

    glBegin(GL_QUADS);
    glColor3ub(82, 71, 67);
	glVertex2i(0,0);
	glVertex2i(0,-250);
	glVertex2i(1000,-250);
	glVertex2i(1000, 0);

	glEnd();

}
void RoadCorner1_Night()
{
    for(int i=0;i<16*70;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner2_Night()
{
    for(int i=0;i<16*70;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148-100);
        glVertex2i(16+i,148-100);
        glVertex2i(16+i,157-100);
        glVertex2i(0+i,157-100);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148-100);
        glVertex2i(39+i,148-100);
        glVertex2i(39+i,157-100);
        glVertex2i(16+i,157-100);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner1_position_Night()
{
    glPushMatrix();
    glTranslatef(0,-200,0);
    RoadCorner1_Night();
    glPopMatrix();
}

void RoadCorner2_position_Night()
{
    glPushMatrix();
    glTranslatef(0,-300,0);
    RoadCorner2_Night();
    glPopMatrix();
}



void car_model_1_Night()
{
    glBegin(GL_POLYGON);
	glColor3f(21, 1, 1);
	glVertex2i(10, -10);
	glVertex2i(80, -10);
	glVertex2i(95, -40);
	glVertex2i(95, -80);
	glVertex2i(10, -80);

	glEnd();

	//
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(95, -40);
	glVertex2i(125, -40);
	glVertex2i(135, -80);
	glVertex2i(95, -80);


	glEnd();

	//window 1

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(15, -15);
	glVertex2i(40, -15);
	glVertex2i(40, -40);
	glVertex2i(15, -40);
	glEnd();


	//window2
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(50, -15);
	glVertex2i(78, -15);
	glVertex2i(90, -40);
	glVertex2i(50, -40);


	glEnd();

	//line
	glLineWidth(5);

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(9,-80 );
	glVertex2i(136,-80);

	glEnd();


	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(110,-80,0);
    circle_Night(15);
    glPopMatrix();
    //circle small
    glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
    glTranslatef(110,-80,0);
    circle_Night(10);
    glPopMatrix();

    //circle2

	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(35,-80,0);
    circle_Night(15);
    glPopMatrix();
    //circle2 small
    glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
    glTranslatef(35,-80,0);
    circle_Night(10);
    glPopMatrix();



}

void car_model_2_Night()
{
    glBegin(GL_POLYGON);
	glColor3f(0.4, 1, 0);
	glVertex2i(300, -15);
	glVertex2i(280, -52);
	glVertex2i(280, -110);
	glVertex2i(480, -110);
	glVertex2i(480, -15);

	glEnd();

	//triagle
    glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2i(300, -15);
	glVertex2i(280, -52);
	glVertex2i(300, -52);

	glEnd();

	//square

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(305, -25);
	glVertex2i(305, -52);
	glVertex2i(470, -52);
	glVertex2i(470, -25);

	glEnd();




//big square
    glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2i(305, -28);
	glVertex2i(325, -28);
	glVertex2i(325, -60);
	glVertex2i(305, -60);

	glEnd();
	//big square white
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(325, -28);
	glVertex2i(340, -28);
	glVertex2i(340, -80);
	glVertex2i(325, -80);

	glEnd();

	//window 1

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(345, -28);
	glVertex2i(380, -28);
	glVertex2i(380, -50);
	glVertex2i(345, -50);

	glEnd();

	//window 2
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(385, -28);
	glVertex2i(415, -28);
	glVertex2i(415, -50);
	glVertex2i(385, -50);

	glEnd();

	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(310,-110,0);
    circle_Night(15);
    glPopMatrix();

    //circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(450,-110,0);
    circle_Night(15);
    glPopMatrix();



}

///*** Field_Model ***///

void field_Night(){
    ///Field
	glBegin(GL_POLYGON);
	glColor3ub( 215, 187, 175 );

    //glColor3f(0.137255 , 0.556863 , 0.137255);
	glVertex2i(0, 50);
	glVertex2i(0, 200);// ch=70to 200
	glVertex2i(1000, 200); //    ||
	glVertex2i(1000, 50);

	glEnd();


    ///Field_Shadow
	glBegin(GL_POLYGON);
	glColor3ub( 215, 187, 175 );
	glVertex2i(0, -50);  //change
	glVertex2i(0, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, -50); //change

	glEnd();
}


///Tilla with 2 dff houses

void Tilla_Night()
{
    ///  lines

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 205);
	glVertex2i(756, 180);
	glEnd();


	//

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(760, 205);
	glVertex2i(760, 170);
	glEnd();


	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	glVertex2i(764, 205);
	glVertex2i(764, 160);
	glEnd();



    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	glVertex2i(768, 205);
	glVertex2i(768, 150);
	glEnd();

	//
	glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(772, 205);
	glVertex2i(772, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(776, 205);
	glVertex2i(776, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(780, 205);
	glVertex2i(780, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(784, 205);
	glVertex2i(784, 140);
	glEnd();



    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 205);
	glVertex2i(788, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(792, 205);
	glVertex2i(792, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(826, 205);
	glVertex2i(826, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(830, 205);
	glVertex2i(830, 140);
	glEnd();
	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(834, 205);
	glVertex2i(834, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(838, 205);
	glVertex2i(838, 140);

	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(842, 205);
	glVertex2i(842, 140);


	glEnd();


    ///house 1
    glBegin(GL_POLYGON);
    glColor3f(0.99 , 0.99 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(820, 190);
	glVertex2i(820, 260);
	glVertex2i(860, 260);
	glVertex2i(860, 190);

	glEnd();
//dark shade
    glBegin(GL_POLYGON);
    glColor3f(0.9 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(820, 190);
	glVertex2i(820, 260);
	glVertex2i(800, 260);
	glVertex2i(800, 210);
	glEnd();


	//triangle
    glBegin(GL_POLYGON);
    glColor3f(0.5 , 0 , 0.5);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(760, 290);
	glVertex2i(755, 270);
	glVertex2i(771, 270);
	glEnd();


	//roof

    glBegin(GL_POLYGON);
    glColor3f(0.9 , 0.9 , 0.9);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(863, 260);
	glVertex2i(853, 290);
	glVertex2i(760, 290);
	glVertex2i(770, 260);
	glEnd();



	//lower poly
	glBegin(GL_POLYGON);
    glColor3f(0.8 , 0.8 , 0.8);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(800, 210);
	glVertex2i(755, 205);
	glVertex2i(770, 175);
	glVertex2i(820, 190);

	glEnd();


    //fence

    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.6 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 270);
	glVertex2i(756, 230);
	glEnd();


    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.6 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 260);
	glVertex2i(771, 200);
	glEnd();

	glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 230);
	glVertex2i(771, 200);


	glEnd();


	glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 230);

	glVertex2i(800, 230);


	glEnd();

	//
	glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 200);

	glVertex2i(788, 200);


	glEnd();

	//


   glLineWidth(5);
   glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 230);

	glVertex2i(756, 205);


	glEnd();

	//

	glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 200);

	glVertex2i(771, 175);


	glEnd();

	//
	glLineWidth(5);
   glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 205);

	glVertex2i(771, 175);


	glEnd();

	//


    glLineWidth(6);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 175);

	glVertex2i(788, 175);


	glEnd();
	 glBegin(GL_POLYGON);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 200);
	glVertex2i(788, 165);

	glVertex2i(800, 136);


	glEnd();


	//stair



   glBegin(GL_POLYGON);

    glColor3f(0.7 , 0.7 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 189);
	glVertex2i(800, 136);

	glVertex2i(832, 136);

    glVertex2i(820, 189);

	glEnd();

	//
	glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 182);

	glVertex2i(820, 182);


	glEnd();
	//
	glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 175);

	glVertex2i(822, 175);


	glEnd();

	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 168);

	glVertex2i(823, 168);


	glEnd();

	//
	glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 161);

	glVertex2i(824, 161);


	glEnd();

	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(792, 154);

	glVertex2i(824, 154);


	glEnd();

	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(796, 147);

	glVertex2i(824, 147);


	glEnd();



//
	glLineWidth(7);
   glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 200);

	glVertex2i(800, 136);


	glEnd();

//
	glLineWidth(7);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(820, 190);

	glVertex2i(832, 136);


	glEnd();

    //tilla road mud
	glBegin(GL_POLYGON);
    glColor3f(  0.92 ,0.75 , 0.50);
    //glColor3f(0.623529 , 0.623529 , 0.372549);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(910, 310);
	glVertex2i(830, 160);

	glVertex2i(850, 160);
	glVertex2i(930, 290);

	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(  0.92 ,0.75 , 0.50);
    //glColor3f(0.623529 , 0.623529 , 0.372549);

	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(830, 160);
	glVertex2i(800, 130);
	glVertex2i(840, 130);
	glVertex2i(850, 160);


	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(  0.92 ,0.75 , 0.50);

    //glColor3f(0.623529 , 0.623529 , 0.372549);

	//glColor3f(0.196078 ,0.8, 0.196078);

	glVertex2i(840, 130);
	glVertex2i(740, 130);
	glVertex2i(740, 110);
	glVertex2i(840, 110);
	glEnd();



   //tilla green
    glBegin(GL_POLYGON);
    glColor3f( 0.576471 , 0.858824, 0.439216);
    //glColor3f(0.196078 ,0.8, 0.196078);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(1000, 370);
	glVertex2i(920, 370);
	glVertex2i(900, 260);
	glVertex2i(825, 110);
	glVertex2i(1000, 110);

	glEnd();


	///Tilla house 1
    //square
    glBegin(GL_POLYGON);
    glColor3f(1 ,1, 1);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(950, 370);
	glVertex2i(970, 370);
	glVertex2i(970, 410);
	glVertex2i(950, 410);


	glEnd();

	//window

    glBegin(GL_POLYGON);
    glColor3f(0 ,0, 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(965, 385);
	glVertex2i(965, 400);
	glVertex2i(955, 400);
	glVertex2i(955, 385);
	glEnd();
	//door part


    glBegin(GL_POLYGON);
    glColor3f(0.97 ,0.97, 0.97);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(950, 370);
	glVertex2i(950, 425);
	glVertex2i(939, 425);
	glVertex2i(939, 374);

	glEnd();
	//roof

	glBegin(GL_POLYGON);
    glColor3f(1 ,0, 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(948, 410);
	glVertex2i(972, 410);
	glVertex2i(966, 460);
	glVertex2i(942, 460);
	glEnd();

	//small triangle


    glBegin(GL_POLYGON);
    glColor3f(0.5 ,0, 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(942, 460);
	glVertex2i(935, 425);
	glVertex2i(946, 425);
	glEnd();



}
/// Tree model updated

void Tree_Model_circle_1_NIght(){

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f( 0.3, 0.3,0); //dark red
	glVertex2f(130, 130);
	glVertex2f(130, 95);
    glEnd();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(130,130,0);
    circle_Night(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(125,126,0);
    circle_Night(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(135,126,0);
    circle_Night(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(130,125,0);
    circle_Night(10);
    glPopMatrix();


}

void Tree_Model_circle_2_Night(){

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f( 0.3, 0,0); //dark red
	glVertex2f(133, 125);
	glVertex2f(133, 92);
    glEnd();

    glColor3f( 0, 0.198039,0);
    glBegin(GL_POLYGON);
	glVertex2f(123, 123);
	glVertex2f(134, 147);
	glVertex2f(147, 123);

	glEnd();

}


/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model_Night(){

    glColor3ub(141, 47, 47);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

///*** Windmill_Blades_Model ***///

void Windmill_Blade_NIght(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///bridge night
void Bridge1(){

    ///main line
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2i(168, 165);
	glVertex2i(262, 165);
	glVertex2i(262, 157);
	glVertex2i(168, 157);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2i(168, 162);
	glVertex2i(262, 162);
	glVertex2i(262, 161);
	glVertex2i(168, 161);
	glEnd();

    ///left
    glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2i(198, 157);
	glVertex2i(196, 157);
    glVertex2i(196, 150);
	glVertex2i(198, 150);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2i(192, 157);
	glVertex2i(190, 157);
    glVertex2i(190, 144);
	glVertex2i(192, 144);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2i(185, 157);
	glVertex2i(183, 157);
    glVertex2i(183, 138);
	glVertex2i(185, 138);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2i(175, 131);
	glVertex2i(175, 126);
    glVertex2i(210, 157);
	glVertex2i(210, 162);
	glEnd();

	///right
    glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2i(232, 157);
	glVertex2i(234, 157);
    glVertex2i(234, 150);
	glVertex2i(232, 150);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2i(238, 157);
	glVertex2i(240, 157);
    glVertex2i(240, 144);
	glVertex2i(238, 144);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2i(245, 157);
	glVertex2i(247, 157);
    glVertex2i(247, 138);
	glVertex2i(245, 138);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2i(255, 131);
	glVertex2i(255, 126);
    glVertex2i(220, 157);
	glVertex2i(220, 162);
	glEnd();
}
///star
void star()
{

	glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2i(230, 175);
	glVertex2i(235, 175);
    glVertex2i(235, 170);
	glVertex2i(230, 170);
	glEnd();
	glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2i(230, 175);
	glVertex2i(232, 179);
    glVertex2i(235, 175);
	glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2i(235, 175);
	glVertex2i(237, 172);
    glVertex2i(235, 170);
	glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2i(230, 170);
	glVertex2i(232, 166);
    glVertex2i(235, 170);
	glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2i(230, 175);
	glVertex2i(228, 172);
    glVertex2i(230, 170);
	glEnd();
}
///*** Windmill_Final_Model ***///
void Windmill_NIght(){

        ///Windmill_Stand
    glColor3ub(141, 47, 47);
    glPushMatrix();
    Windmill_Stand_Model_Night();
    glPopMatrix();

    ///Windmill_Motor
    glColor3ub(243, 239, 239 );
    glPushMatrix();
    glTranslatef(380,250,0);
    circle_Night(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3ub(243, 239, 239 );
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade_NIght();
    glPopMatrix();
}

///*** Cloud_One_Model_One ***///
void airplane_Night(){
    glPushMatrix();
    glTranslatef(ar-300,200,0);
    airplane_model_Night();
    glPopMatrix();

}


void house_three_Night()
{
    glPushMatrix();
    glTranslatef(140,130,0);
    house_Night();
    glPopMatrix();
}
///*** Hill_big_One ***///
void Hill_Big_One_Night()
{
    glPushMatrix();
    glTranslatef(-100,100,0);
    hill_big_Night();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two_NIght()
{
    glPushMatrix();
    glTranslatef(90,100,0);
    hill_big_Night();
    glPopMatrix();
}

/// *** Windmill ***///
void Windmill_One_Night()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0,100,0);
    Windmill_NIght();
    glPopMatrix();

}

void Windmill_Two_Night()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(150,100,0);
    Windmill_NIght();
    glPopMatrix();

}
void Windmill_Three_Night()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(270,100,0);
    Windmill_NIght();
    glPopMatrix();

}

void hill_large_up_pos1_Night()
{
    glPushMatrix();
    glTranslatef(350,-5,0);
    hill_large_up_Night();
    glPopMatrix();

}

void hill_small_up_pos1_Night()
{

    glPushMatrix();
    glTranslatef(460,10,0);
    hill_small_up_Night();
    glPopMatrix();

}

void Tree_Circle1_pos1_Night(){


    glPushMatrix();
    glTranslatef(734,90,0);
    Tree_Model_circle_1_NIght();
    glPopMatrix();

}
void Tree_Circle1_pos2_Night(){


    glPushMatrix();
    glTranslatef(767,195,0);
    Tree_Model_circle_1_NIght();
    glPopMatrix();

}

void Tree_Circle2_pos1_Night(){

    glPushMatrix();
    glTranslatef(745,140,0);
    Tree_Model_circle_2_Night();
    glPopMatrix();

}
void car_1_Night(){
    glPushMatrix();
    glTranslatef(cr-200,-40,0);
    car_model_1_Night();
    glPopMatrix();

}

void Bus_Night(){
    glPushMatrix();
    glTranslatef(bs+800,-135,0);
    car_model_2_Night();
    glPopMatrix();

}
void Bridge_night()
{
    glPushMatrix();
    glTranslatef(-20,100,0);
    Bridge1();
    glPopMatrix();
}
void star_night1()
{
    glPushMatrix();
    glRotatef(-spin3,0,0,90);
    glTranslatef(-150,600,0);
    star();
    glPopMatrix();
}
void star_night2()
{
    glPushMatrix();
    glRotatef(spin2,0,0,90);
    glTranslatef(-10,500,0);
    star();
    glPopMatrix();
}
void star_night3()
{
    glPushMatrix();
    glRotatef(-spin1,0,0,90);
    glTranslatef(100,650,0);
    star();
    glPopMatrix();
}
void star_night4()
{
    glPushMatrix();
    glRotatef(spin3,0,0,90);
    glTranslatef(220,620,0);
    star();
    glPopMatrix();
}
void star_night5()
{
    glPushMatrix();
    glRotatef(-spin2,0,0,90);
    glTranslatef(340,520,0);
    star();
    glPopMatrix();
}
void star_night6()
{
    glPushMatrix();
    glRotatef(spin3,0,0,90);
    glTranslatef(420,580,0);
    star();
    glPopMatrix();
}
void star_night7()
{
    glPushMatrix();
    glRotatef(-spin1,0,0,90);
    glTranslatef(490,650,0);
    star();
    glPopMatrix();
}
void star_night8()
{
    glPushMatrix();
    glRotatef(spin2,0,0,90);
    glTranslatef(580,520,0);
    star();
    glPopMatrix();
}
void star_night9()
{
    glPushMatrix();
    glRotatef(-spin1,0,0,90);
    glTranslatef(660,610,0);
    star();
    glPopMatrix();
}
void star_night()
{
    glPushMatrix();

    star_night1();
    star_night2();
    star_night3();
    star_night4();
    star_night5();
    star_night6();
    star_night7();
    star_night8();
    star_night9();
    glPopMatrix();
}

///========================///
///*** Display Function ***///
///========================///

void Night(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor( 0.0, 0.0 , 0.3, 0);

    star_night();
    Moon_Night_Position();
    Windmill_Three_Night();
    Bridge_night();
    Hill_Big_One_Night();
    house_three_Night();
    Hill_Big_Two_NIght();

    Windmill_One_Night();
    Windmill_Two_Night();

    airplane_Night();
    road_model_Night();
    car_1_Night();
    Bus_Night();
    field_Night();
    Tree_Circle2_pos1_Night();
    Tree_Circle1_pos2_Night();
    Tilla_Night();
    hill_large_up_pos1_Night();
    hill_small_up_pos1_Night();
    Tree_Circle1_pos1_Night();
    Hotel_position_Night();
    Hospital_position_Night();
    Tree_One_Night();
    Tree_Two_Night();
    Lampost_position_Night();
    School_position_Night();
    Tree_Three_Night();
    RoadCorner1_position_Night();
    RoadCorner2_position_Night();




    print_Night(855,-1,school);
    print_Night(185,105,hotel);
    print_Night(500,70,hospital);

	glFlush();
}


///========================///
///*** Night Function End ***///
///========================///


///========================///
///*** Rain Function Start***///
///========================///

///*** Circle_Model***///
void circle_Rain(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
void drawCircle_Rain(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;

    //glColor3ub(23,60,43);
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
void print_Rain( float x, float y, char *st)
{
    int l,i;

    l=strlen( st ); // see how many characters are in text string.
    glColor3ub(13, 13, 13);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}
void rain_Rain()
{
    int x=0;
    int y=500;
    static float a=-760.0f;
    if(a<=-768)
    {
         a=-760.0f;

    }
    else
    {
        a+=0.05f;
    }
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(0.0f,a,0.0f);
    glBegin(GL_LINES);
    for(int i=500;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            glVertex3i(x,y,0);
            glVertex3i(x+3,y+10,0);
            x+=rand()%2050;
        }
        y+=rand()%15;
        x=0;

    }
    glEnd();
    glPopMatrix();
    glutPostRedisplay();

}




void Tree_One_Model_Rain()
{
    glColor3ub(0.6156863,0,0);
    glBegin(GL_POLYGON);
    glVertex3i(50, 350, 0);
    glVertex3i(70, 350, 0);
    glVertex3i(70, 500, 0);
    glVertex3i(50, 500, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);
    glVertex3i(10, 500, 0);
    glVertex3i(110, 500, 0);
    glVertex3i(60, 600, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(15, 550, 0);
    glVertex3i(105, 550, 0);
    glVertex3i(60, 650, 0);
    glEnd();

}
void HotelBelowWindow1_Rain(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+19,y);
    glVertex2i(x+19,y+13);
    glVertex2i(x,y+13);
    glEnd();
    glPopMatrix();
}

void HotelAboveWindow1_Rain(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+17,y);
    glVertex2i(x+17,y+21);
    glVertex2i(x,y+21);
    glEnd();
    glPopMatrix();
}




void Hotel_Rain()
{

    glColor3ub(8,32,19);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(644,257);
    glVertex2i(644,289);
    glVertex2i(449,289);
    glEnd();



    glColor3ub(23,60,43);
    glBegin(GL_QUADS);
    glVertex2i(473,289);
    glVertex2i(500,289);
    glVertex2i(500,413);
    glVertex2i(473,413);
    glEnd();


    glColor3ub(15,47,106);
    glBegin(GL_QUADS);
    glVertex2i(500,289);
    glVertex2i(517,289);
    glVertex2i(517,435);
    glVertex2i(500,435);
    glEnd();

    glPushMatrix();  // above name plate
    glColor3ub(30,72,230);
    glBegin(GL_QUADS);
    glVertex2i(526,408);
    glVertex2i(600,408);
    glVertex2i(600,423);
    glVertex2i(526,423);
    glEnd();
    glPopMatrix();



    glColor3ub(21,63,53);
    glBegin(GL_QUADS);
    glVertex2i(517,289);
    glVertex2i(617,289);
    glVertex2i(617,408);
    glVertex2i(517,408);
    glEnd();






     int HotelBelowStripe1=-430;
    for(int i=7;i>=0;i--)
    {
        HotelBelowStripe1+=24;
        HotelBelowWindow1_Rain(HotelBelowStripe1,267);
    }

    int HotelAboveStripe1=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe1+=24;
        HotelAboveWindow1_Rain(HotelAboveStripe1,377);
    }

    int HotelAboveStripe2=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe2+=24;
        HotelAboveWindow1_Rain(HotelAboveStripe2,350);
    }

    int HotelAboveStripe3=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe3+=24;
        HotelAboveWindow1_Rain(HotelAboveStripe3,323);
    }

    int HotelAboveStripe4=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe4+=24;
        HotelAboveWindow1_Rain(HotelAboveStripe4,295);
    }
}

void Door_Rain()
{
    glColor3ub(8,402,19);
       // door
    glColor3ub(119,81,70);
    glBegin(GL_QUADS);
    glVertex2i(524,258);
    glVertex2i(570,258);
    glVertex2i(570,281);
    glVertex2i(524,281);
    glEnd();

     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(528,280);
    glVertex2i(546,280);
    glVertex2i(546,257);
    glVertex2i(528,257);
    glEnd();

     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(548,257);
    glVertex2i(565,257);
    glVertex2i(565,280);
    glVertex2i(548,280);
    glEnd();


}
void Hotel_position_Rain()
{
    glPushMatrix();
    glTranslatef(-360,-306,0);
    Hotel_Rain();
    Door_Rain();
    glPopMatrix();
}



void HospitalWindow1_Rain(int x,int y)
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+16,y);
    glVertex2i(x+16,y+30);
    glVertex2i(x,y+30);
    glEnd();
    glPopMatrix();
}

void HospitalMidWindow1_Rain(int x,int y)
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+12,y);
    glVertex2i(x+12,y+18);
    glVertex2i(x,y+18);
    glEnd();
    glPopMatrix();
}

void Hospital_Rain()
{
    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(151,257);
    glVertex2i(181,257);
    glVertex2i(181,424);
    glVertex2i(151,424);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(449,424);
    glVertex2i(420,424);
    glVertex2i(420,257);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(181,381);
    glVertex2i(420,381);
    glVertex2i(420,400);
    glVertex2i(181,400);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(190,27,9);
    glBegin(GL_QUADS);
    glVertex2i(181,258);
    glVertex2i(420,258);
    glVertex2i(420,381);
    glVertex2i(181,381);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(151,390);
    glVertex2i(181,390);
    glVertex2i(181,401);
    glVertex2i(151,401);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(420,390);
    glVertex2i(449,390);
    glVertex2i(449,401);
    glVertex2i(420,401);
    glEnd();
    glPopMatrix();

    int HospitalStripe1=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe1+=20;
        HospitalWindow1_Rain(HospitalStripe1,349);
    }

    int HospitalStripe2=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe2+=20;
        HospitalWindow1_Rain(HospitalStripe2,315);
    }

    int HospitalStripe3=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe3+=20;
        HospitalWindow1_Rain(HospitalStripe3,281);
    }

    glPushMatrix(); //middle long stripe
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(263,257);
    glVertex2i(339,257);
    glVertex2i(339,400);
    glVertex2i(263,400);
    glEnd();
    glPopMatrix();

    int HospitalStripe4=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe4+=14;
        HospitalMidWindow1_Rain(HospitalStripe4,370);
    }

    int HospitalStripe5=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe5+=14;
        HospitalMidWindow1_Rain(HospitalStripe5,340);
    }

     int HospitalStripe6=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe6+=14;
        HospitalMidWindow1_Rain(HospitalStripe6,310);
    }

    glPushMatrix();  //Door
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(286,257);
    glVertex2i(318,257);
    glVertex2i(318,298);
    glVertex2i(286,298);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
}

//******Circle******
void drawFilledCircle_Rain(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;

    glColor3ub(252,20,255);
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

    glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(295,395);
    glVertex2i(307,395);
    glVertex2i(307,426);
    glVertex2i(295,426);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(284,408);
    glVertex2i(318,408);
    glVertex2i(318,418);
    glVertex2i(284,418);
    glEnd();
    glPopMatrix();
}

void Hospital_position_Rain()
{
    glPushMatrix();
    glTranslatef(220,-306,0);
    Hospital_Rain();
    drawFilledCircle_Rain(300.0f,400.0f,40.0f);
    glPopMatrix();

}

void LampPost_Rain()
{
    for(int i=0;i<10*115;i+=115)
    {
        glPushMatrix();
        glColor3ub(150,177,144);
        glBegin(GL_QUADS);
        glVertex2i(34+i,158);
        glVertex2i(51+i,158);
        glVertex2i(51+i,160);
        glVertex2i(34+i,160);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(255,200,255);
        glBegin(GL_QUADS);
        glVertex2i(37+i,160);
        glVertex2i(48+i,160);
        glVertex2i(48+i,162);
        glVertex2i(37+i,162);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(100,50,10);
        glBegin(GL_QUADS);
        glVertex2i(40+i,162);
        glVertex2i(45+i,162);
        glVertex2i(45+i,206);
        glVertex2i(40+i,206);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(38+i,206);
        glVertex2i(48+i,206);
        glVertex2i(48+i,209);
        glVertex2i(38+i,209);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(ldr,ldg,ldb);
        drawCircle_Rain(43+i,218,9);
        glPopMatrix();
    }
}
void Lampost_position_Rain()
{
    glPushMatrix();
    glTranslatef(0,-309,0);
    LampPost_Rain();
    glPopMatrix();
}

void SchoolWindow1_Rain(int x,int y)
{
    glPushMatrix();
    glColor3ub(190,202,200);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+20,y);
    glVertex2i(x+20,y+17);
    glVertex2i(x,y+17);
    glEnd();
    glPopMatrix();
}

void School_Rain()
{
    glPushMatrix();
    glColor3ub(214,530,520);
    glBegin(GL_QUADS);
    glVertex2i(643,257);
    glVertex2i(884,257);
    glVertex2i(884,351);
    glVertex2i(643,351);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(73,3,5);
    glBegin(GL_QUADS);
    glVertex2i(640,351);
    glVertex2i(887,351);
    glVertex2i(887,358);
    glVertex2i(640,358);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(648,265);
    glVertex2i(719,265);
    glVertex2i(719,275);
    glVertex2i(648,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(808,265);
    glVertex2i(879,265);
    glVertex2i(879,275);
    glVertex2i(808,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(217,132,3);
    glBegin(GL_POLYGON);
    glVertex2i(713,358);
    glVertex2i(813,358);
    glVertex2i(813,381);
    glVertex2i(763,402);
    glVertex2i(713,381);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(707,381);
    glVertex2i(819,381);
    glVertex2i(763,409);
    glEnd();
    glPopMatrix();

    glColor3ub(200,200,240);
    drawCircle_Rain(762.0f,369.0f,10.0f);

    int SchoolStripe1=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe1+=25;
        SchoolWindow1_Rain(SchoolStripe1,328);
    }

     int SchoolStripe2=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe2+=25;
        SchoolWindow1_Rain(SchoolStripe2,304);
    }

    int SchoolStripe3=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe3+=25;
        SchoolWindow1_Rain(SchoolStripe3,281);
    }

    int SchoolStripe4=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe4+=25;
        SchoolWindow1_Rain(SchoolStripe4,328);
    }

    int SchoolStripe5=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe5+=25;
        SchoolWindow1_Rain(SchoolStripe5,304);
    }

    int SchoolStripe6=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe6+=25;
        SchoolWindow1_Rain(SchoolStripe6,282);
    }

}
void SchoolDoor_Rain()
{
    glPushMatrix();
    glColor3ub(72,2,4);
    glBegin(GL_QUADS);
    glVertex2i(728,257);
    glVertex2i(797,257);
    glVertex2i(797,321);
    glVertex2i(728,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(722,321);
    glVertex2i(803,321);
    glVertex2i(763,347);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(100,150,100);
    glBegin(GL_QUADS);
    glVertex2i(733,304);
    glVertex2i(792,304);
    glVertex2i(792,321);
    glVertex2i(733,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(89,107,121);
    glBegin(GL_QUADS);
    glVertex2i(743,257);
    glVertex2i(782,257);
    glVertex2i(782,295);
    glVertex2i(743,295);
    glEnd();
    glPopMatrix();
}

void School_position_Rain()
{
    glPushMatrix();
    glTranslatef(110,-306,0);
    School_Rain();
    SchoolDoor_Rain();
    glPopMatrix();

}



void Tree_One_Rain(){

    glPushMatrix();
    glTranslatef(0,-400,0);
    Tree_One_Model_Rain();
    glPopMatrix();

}



void Tree_Two_Rain(){

    glPushMatrix();
    glTranslatef(260,-400,0);
    Tree_One_Model_Rain();
    glPopMatrix();

}

void Tree_Three_Rain(){

    glPushMatrix();
    glTranslatef(665,-400,0);
    Tree_One_Model_Rain();
    glPopMatrix();

}


///*** Airplane model***///
void airplane_model_Rain()
{
    ///Airplane body
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(5, 450);
	glVertex2i(30, 450);
	glVertex2i(45, 420);
	glVertex2i(5, 420);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 1.5);
	glVertex2i(5, 420);
	glVertex2i(140, 420);
	glVertex2i(150, 410);
	glVertex2i(160, 410);
	glVertex2i(165, 400);
	glVertex2i(160, 390);
	glVertex2i(15, 390);
	glVertex2i(5, 400);
	glVertex2i(5, 420);
	glEnd();
    ///Airplane lower red part
	glBegin(GL_POLYGON);
    glColor3f(0.8, 0.0, 0.0);
    glVertex2i(165, 400);
	glVertex2i(160, 390);
	glVertex2i(15, 390);
	glVertex2i(5, 400);
	glEnd();
    ///Airplane windows
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(140, 420);
	glVertex2i(150, 410);
	glVertex2i(140, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(100, 415);
	glVertex2i(105, 415);
	glVertex2i(105, 410);
	glVertex2i(100, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(110, 415);
	glVertex2i(115, 415);
	glVertex2i(115, 410);
	glVertex2i(110, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(90, 415);
	glVertex2i(95, 415);
	glVertex2i(95, 410);
	glVertex2i(90, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(80, 415);
	glVertex2i(85, 415);
	glVertex2i(85, 410);
	glVertex2i(80, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(70, 415);
	glVertex2i(75, 415);
	glVertex2i(75, 410);
	glVertex2i(70, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(60, 415);
	glVertex2i(65, 415);
	glVertex2i(65, 410);
	glVertex2i(60, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(50, 415);
	glVertex2i(55, 415);
	glVertex2i(55, 410);
	glVertex2i(50, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(40, 415);
	glVertex2i(45, 415);
	glVertex2i(45, 410);
	glVertex2i(40, 410);
	glEnd();
    ///Airplane wings
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(65, 420);
	glVertex2i(60, 435);
	glVertex2i(80, 435);
	glVertex2i(95, 420);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(65, 390);
	glVertex2i(60, 375);
	glVertex2i(80, 375);
	glVertex2i(95, 390);
	glEnd();
}


/*** Hill_Model***///
void hill_big_Rain(){

    ///Hill
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(70, 70);
	glVertex2i(200, 225);
	glVertex2i(330, 70);

	glEnd();


}
///*** House_Model ***///
void house_Rain(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);

	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);

	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(1.555, 1.0, 21.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);

	glEnd();

    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);

	glEnd();

    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();


}

/// HILL Updated

void hill_large_up_Rain(){

	glBegin(GL_POLYGON);
    glColor3f( 0.38, 0.41, 0.36);
	glVertex2i(180, 120);
	glVertex2i(270, 360);
	glVertex2i(350, 120);

	glEnd();


}


void hill_small_up_Rain(){

	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(180, 100);
	glVertex2i(250, 250);
	glVertex2i(320, 100);

	glEnd();


}


void road_model_Rain()
{

    glBegin(GL_QUADS);
    glColor3ub(82, 71, 67);
	glVertex2i(0,0);
	glVertex2i(0,-250);
	glVertex2i(1000,-250);
	glVertex2i(1000, 0);

	glEnd();

}
void RoadCorner1_Rain()
{
    for(int i=0;i<16*70;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner2_Rain()
{
    for(int i=0;i<16*70;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148-100);
        glVertex2i(16+i,148-100);
        glVertex2i(16+i,157-100);
        glVertex2i(0+i,157-100);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148-100);
        glVertex2i(39+i,148-100);
        glVertex2i(39+i,157-100);
        glVertex2i(16+i,157-100);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner1_position_Rain()
{
    glPushMatrix();
    glTranslatef(0,-200,0);
    RoadCorner1_Rain();
    glPopMatrix();
}

void RoadCorner2_position_Rain()
{
    glPushMatrix();
    glTranslatef(0,-300,0);
    RoadCorner2_Rain();
    glPopMatrix();
}



void car_model_1_Rain()
{
    glBegin(GL_POLYGON);
	glColor3f(21, 1, 1);
	glVertex2i(10, -10);
	glVertex2i(80, -10);
	glVertex2i(95, -40);
	glVertex2i(95, -80);
	glVertex2i(10, -80);

	glEnd();

	//
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(95, -40);
	glVertex2i(125, -40);
	glVertex2i(135, -80);
	glVertex2i(95, -80);


	glEnd();

	//window 1

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(15, -15);
	glVertex2i(40, -15);
	glVertex2i(40, -40);
	glVertex2i(15, -40);
	glEnd();


	//window2
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(50, -15);
	glVertex2i(78, -15);
	glVertex2i(90, -40);
	glVertex2i(50, -40);


	glEnd();

	//line
	glLineWidth(5);

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(9,-80 );
	glVertex2i(136,-80);

	glEnd();


	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(110,-80,0);
    circle_Rain(15);
    glPopMatrix();
    //circle small
    glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
    glTranslatef(110,-80,0);
    circle_Rain(10);
    glPopMatrix();

    //circle2

	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(35,-80,0);
    circle_Rain(15);
    glPopMatrix();
    //circle2 small
    glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
    glTranslatef(35,-80,0);
    circle_Rain(10);
    glPopMatrix();



}

void car_model_2_Rain()
{
    glBegin(GL_POLYGON);
	glColor3f(0.4, 1, 0);
	glVertex2i(300, -15);
	glVertex2i(280, -52);
	glVertex2i(280, -110);
	glVertex2i(480, -110);
	glVertex2i(480, -15);

	glEnd();

	//triagle
    glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2i(300, -15);
	glVertex2i(280, -52);
	glVertex2i(300, -52);

	glEnd();

	//square

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(305, -25);
	glVertex2i(305, -52);
	glVertex2i(470, -52);
	glVertex2i(470, -25);

	glEnd();




//big square
    glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2i(305, -28);
	glVertex2i(325, -28);
	glVertex2i(325, -60);
	glVertex2i(305, -60);

	glEnd();
	//big square white
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(325, -28);
	glVertex2i(340, -28);
	glVertex2i(340, -80);
	glVertex2i(325, -80);

	glEnd();

	//window 1

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(345, -28);
	glVertex2i(380, -28);
	glVertex2i(380, -50);
	glVertex2i(345, -50);

	glEnd();

	//window 2
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(385, -28);
	glVertex2i(415, -28);
	glVertex2i(415, -50);
	glVertex2i(385, -50);

	glEnd();

	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(310,-110,0);
    circle_Rain(15);
    glPopMatrix();

    //circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(450,-110,0);
    circle_Rain(15);
    glPopMatrix();



}

///*** Field_Model ***///

void field_Rain(){
    ///Field
	glBegin(GL_POLYGON);
	glColor3ub( 215, 187, 175 );

    //glColor3f(0.137255 , 0.556863 , 0.137255);
	glVertex2i(0, 50);
	glVertex2i(0, 200);// ch=70to 200
	glVertex2i(1000, 200); //    ||
	glVertex2i(1000, 50);

	glEnd();


    ///Field_Shadow
	glBegin(GL_POLYGON);
	glColor3ub( 215, 187, 175 );
	glVertex2i(0, -50);  //change
	glVertex2i(0, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, -50); //change

	glEnd();
}
///bridge model
void Bridge(){

    ///bridge
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2i(168, 165);
	glVertex2i(262, 165);
	glVertex2i(262, 157);
	glVertex2i(168, 157);
	glEnd();

    ///left
    glBegin(GL_QUADS);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex2i(198, 157);
	glVertex2i(196, 157);
    glVertex2i(196, 150);
	glVertex2i(198, 150);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex2i(192, 157);
	glVertex2i(190, 157);
    glVertex2i(190, 144);
	glVertex2i(192, 144);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex2i(185, 157);
	glVertex2i(183, 157);
    glVertex2i(183, 138);
	glVertex2i(185, 138);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2i(175, 131);
	glVertex2i(175, 126);
    glVertex2i(210, 157);
	glVertex2i(210, 162);
	glEnd();

	///right
    glBegin(GL_QUADS);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex2i(232, 157);
	glVertex2i(234, 157);
    glVertex2i(234, 150);
	glVertex2i(232, 150);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex2i(238, 157);
	glVertex2i(240, 157);
    glVertex2i(240, 144);
	glVertex2i(238, 144);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex2i(245, 157);
	glVertex2i(247, 157);
    glVertex2i(247, 138);
	glVertex2i(245, 138);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2i(255, 131);
	glVertex2i(255, 126);
    glVertex2i(220, 157);
	glVertex2i(220, 162);
	glEnd();
}

///Tilla with 2 dff houses

void Tilla_Raint()
{
    ///  lines

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 205);
	glVertex2i(756, 180);
	glEnd();


	//

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(760, 205);
	glVertex2i(760, 170);
	glEnd();


	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	glVertex2i(764, 205);
	glVertex2i(764, 160);
	glEnd();



    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	glVertex2i(768, 205);
	glVertex2i(768, 150);
	glEnd();

	//
	glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(772, 205);
	glVertex2i(772, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(776, 205);
	glVertex2i(776, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(780, 205);
	glVertex2i(780, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(784, 205);
	glVertex2i(784, 140);
	glEnd();



    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 205);
	glVertex2i(788, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(792, 205);
	glVertex2i(792, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(826, 205);
	glVertex2i(826, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(830, 205);
	glVertex2i(830, 140);
	glEnd();
	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(834, 205);
	glVertex2i(834, 140);
	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(838, 205);
	glVertex2i(838, 140);

	glEnd();

	//
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(842, 205);
	glVertex2i(842, 140);


	glEnd();


    ///house 1
    glBegin(GL_POLYGON);
    glColor3f(0.99 , 0.99 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(820, 190);
	glVertex2i(820, 260);
	glVertex2i(860, 260);
	glVertex2i(860, 190);

	glEnd();
//dark shade
    glBegin(GL_POLYGON);
    glColor3f(0.9 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(820, 190);
	glVertex2i(820, 260);
	glVertex2i(800, 260);
	glVertex2i(800, 210);
	glEnd();


	//triangle
    glBegin(GL_POLYGON);
    glColor3f(0.5 , 0 , 0.5);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(760, 290);
	glVertex2i(755, 270);
	glVertex2i(771, 270);
	glEnd();


	//roof

    glBegin(GL_POLYGON);
    glColor3f(0.9 , 0.9 , 0.9);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(863, 260);
	glVertex2i(853, 290);
	glVertex2i(760, 290);
	glVertex2i(770, 260);
	glEnd();



	//lower poly
	glBegin(GL_POLYGON);
    glColor3f(0.8 , 0.8 , 0.8);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(800, 210);
	glVertex2i(755, 205);
	glVertex2i(770, 175);
	glVertex2i(820, 190);

	glEnd();


    //fence

    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.6 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 270);
	glVertex2i(756, 230);
	glEnd();


    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.6 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 260);
	glVertex2i(771, 200);
	glEnd();

	glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 230);
	glVertex2i(771, 200);


	glEnd();


	glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 230);

	glVertex2i(800, 230);


	glEnd();

	//
	glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 200);

	glVertex2i(788, 200);


	glEnd();

	//


   glLineWidth(5);
   glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 230);

	glVertex2i(756, 205);


	glEnd();

	//

	glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 200);

	glVertex2i(771, 175);


	glEnd();

	//
	glLineWidth(5);
   glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(756, 205);

	glVertex2i(771, 175);


	glEnd();

	//


    glLineWidth(6);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(771, 175);

	glVertex2i(788, 175);


	glEnd();
	 glBegin(GL_POLYGON);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 200);
	glVertex2i(788, 165);

	glVertex2i(800, 136);


	glEnd();


	//stair


   glBegin(GL_POLYGON);

    glColor3f(0.7 , 0.7 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 189);
	glVertex2i(800, 136);

	glVertex2i(832, 136);

    glVertex2i(820, 189);

	glEnd();
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 182);

	glVertex2i(820, 182);

	glEnd();
	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 175);

	glVertex2i(822, 175);
	glEnd();

	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 168);

	glVertex2i(823, 168);


	glEnd();

	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 161);

	glVertex2i(824, 161);

	glEnd();

	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(792, 154);

	glVertex2i(824, 154);

	glEnd();
	//
	glLineWidth(3);
   glBegin(GL_LINES);

    glColor3f(0 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(796, 147);

	glVertex2i(824, 147);


	glEnd();

	glLineWidth(7);
   glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(788, 200);

	glVertex2i(800, 136);


	glEnd();

//
	glLineWidth(7);
    glBegin(GL_LINES);

    glColor3f(0.4 , 0 , 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(820, 190);

	glVertex2i(832, 136);


	glEnd();

    //tilla road mud
	glBegin(GL_POLYGON);
    glColor3f(  0.92 ,0.75 , 0.50);
    //glColor3f(0.623529 , 0.623529 , 0.372549);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(910, 310);
	glVertex2i(830, 160);

	glVertex2i(850, 160);
	glVertex2i(930, 290);

	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(  0.92 ,0.75 , 0.50);
    //glColor3f(0.623529 , 0.623529 , 0.372549);

	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(830, 160);
	glVertex2i(800, 130);
	glVertex2i(840, 130);
	glVertex2i(850, 160);


	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(  0.92 ,0.75 , 0.50);

    //glColor3f(0.623529 , 0.623529 , 0.372549);

	//glColor3f(0.196078 ,0.8, 0.196078);

	glVertex2i(840, 130);
	glVertex2i(740, 130);
	glVertex2i(740, 110);
	glVertex2i(840, 110);
	glEnd();



   //tilla green
    glBegin(GL_POLYGON);
    glColor3f( 0.576471 , 0.858824, 0.439216);
    //glColor3f(0.196078 ,0.8, 0.196078);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(1000, 370);
	glVertex2i(920, 370);
	glVertex2i(900, 260);
	glVertex2i(825, 110);
	glVertex2i(1000, 110);

	glEnd();


	///Tilla house 1
    //square
    glBegin(GL_POLYGON);
    glColor3f(1 ,1, 1);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(950, 370);
	glVertex2i(970, 370);
	glVertex2i(970, 410);
	glVertex2i(950, 410);


	glEnd();

	//window

    glBegin(GL_POLYGON);
    glColor3f(0 ,0, 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(965, 385);
	glVertex2i(965, 400);
	glVertex2i(955, 400);
	glVertex2i(955, 385);
	glEnd();
	//door part


    glBegin(GL_POLYGON);
    glColor3f(0.97 ,0.97, 0.97);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(950, 370);
	glVertex2i(950, 425);
	glVertex2i(939, 425);
	glVertex2i(939, 374);

	glEnd();
	//roof

	glBegin(GL_POLYGON);
    glColor3f(1 ,0, 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(948, 410);
	glVertex2i(972, 410);
	glVertex2i(966, 460);
	glVertex2i(942, 460);
	glEnd();

	//small triangle


    glBegin(GL_POLYGON);
    glColor3f(0.5 ,0, 0);
	//glColor3f(0.196078 ,0.8, 0.196078);
	glVertex2i(942, 460);
	glVertex2i(935, 425);
	glVertex2i(946, 425);
	glEnd();



}
/// Tree model updated

void Tree_Model_circle_1_Rain(){

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f( 0.3, 0.3,0); //dark red
	glVertex2f(130, 130);
	glVertex2f(130, 95);
    glEnd();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(130,130,0);
    circle_Rain(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(125,126,0);
    circle_Rain(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(135,126,0);
    circle_Rain(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(130,125,0);
    circle_Rain(10);
    glPopMatrix();


}

void Tree_Model_circle_2_Rain(){

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f( 0.3, 0,0); //dark red
	glVertex2f(133, 125);
	glVertex2f(133, 92);
    glEnd();

    glColor3f( 0, 0.198039,0);
    glBegin(GL_POLYGON);
	glVertex2f(123, 123);
	glVertex2f(134, 147);
	glVertex2f(147, 123);

	glEnd();

}


/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model_Rain(){

    glColor3ub(141, 47, 47);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

///*** Windmill_Blades_Model ***///

void Windmill_Blade_Rain(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///*** Windmill_Final_Model ***///
void Windmill_Rain(){

        ///Windmill_Stand
    glColor3ub(141, 47, 47);
    glPushMatrix();
    Windmill_Stand_Model_Rain();
    glPopMatrix();

    ///Windmill_Motor
    glColor3ub(243, 239, 239 );
    glPushMatrix();
    glTranslatef(380,250,0);
    circle_Rain(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3ub(243, 239, 239 );
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade_Rain();
    glPopMatrix();
}

///*** Cloud_One_Model_One ***///
void airplane_Rain(){
    glPushMatrix();
    glTranslatef(ar-300,200,0);
    airplane_model_Rain();
    glPopMatrix();

}


void house_three_Rain()
{
    glPushMatrix();
    glTranslatef(140,130,0);
    house_Rain();
    glPopMatrix();
}
///*** Hill_big_One ***///
void Hill_Big_One_Rain()
{
    glPushMatrix();
    glTranslatef(-100,100,0);
    hill_big_Rain();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two_Rain()
{
    glPushMatrix();
    glTranslatef(90,100,0);
    hill_big_Rain();
    glPopMatrix();
}

/// *** Windmill ***///
void Windmill_One_Rain()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0,100,0);
    Windmill_Rain();
    glPopMatrix();

}

void Windmill_Two_Rain()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(150,100,0);
    Windmill_Rain();
    glPopMatrix();

}
void Windmill_Three_Rain()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(270,100,0);
    Windmill_Rain();
    glPopMatrix();

}

void hill_large_up_pos1_Rain()
{
    glPushMatrix();
    glTranslatef(350,-5,0);
    hill_large_up_Rain();
    glPopMatrix();

}

void hill_small_up_pos1_Rain()
{

    glPushMatrix();
    glTranslatef(460,10,0);
    hill_small_up_Rain();
    glPopMatrix();

}

void Tree_Circle1_pos1_Rain(){


    glPushMatrix();
    glTranslatef(734,90,0);
    Tree_Model_circle_1_Rain();
    glPopMatrix();

}
void Tree_Circle1_pos2_Rain(){


    glPushMatrix();
    glTranslatef(767,195,0);
    Tree_Model_circle_1_Rain();
    glPopMatrix();

}

void Tree_Circle2_pos1_Rain(){

    glPushMatrix();
    glTranslatef(745,140,0);
    Tree_Model_circle_2_Rain();
    glPopMatrix();

}
void car_1_Rain(){
    glPushMatrix();
    glTranslatef(cr-200,-40,0);
    car_model_1_Rain();
    glPopMatrix();

}

void Bus_Rain(){
    glPushMatrix();
    glTranslatef(bs+800,-135,0);
    car_model_2_Rain();
    glPopMatrix();

}
void Bridge_day()
{
    glPushMatrix();
    glTranslatef(-20,100,0);
    Bridge();
    glPopMatrix();
}


///========================///
///*** Display Function ***///
///========================///

void Rain(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor( 0.22, 0.69 , 0.87, 0);


    Windmill_Three_Rain();
    Bridge_day();
    Hill_Big_One_Rain();
    house_three_Rain();
    Hill_Big_Two_Rain();

    Windmill_One_Rain();
    Windmill_Two_Rain();

    airplane_Rain();
    road_model_Rain();
    car_1_Rain();
    Bus_Rain();
    field_Rain();
    Tree_Circle2_pos1_Rain();
    Tree_Circle1_pos2_Rain();
    Tilla_Raint();
    hill_large_up_pos1_Rain();
    hill_small_up_pos1_Rain();
    Tree_Circle1_pos1_Rain();
    Hotel_position_Rain();
    Hospital_position_Rain();
    Tree_One_Rain();
    Tree_Two_Rain();
    Lampost_position_Rain();
    School_position_Rain();
    Tree_Three_Rain();
    RoadCorner1_position_Rain();
    RoadCorner2_position_Rain();
    rain_Rain();


    print_Rain(855,-1,school);
    print_Rain(185,105,hotel);
    print_Rain(500,70,hospital);

	glFlush();
}

///========================///
///*** Rain Function End***///
///========================///


///========================///
///*** Day Function Start ***///
///========================///

void Day(void)
{	glClearColor( 0.22, 0.69 , 0.87, 0);
	glClear(GL_COLOR_BUFFER_BIT);


    Sun();
    Windmill_Three();
    Bridge_day();
    Hill_Big_One();
    house_three();
    Hill_Big_Two();
    cloud_three();
    cloud_four();
    Windmill_One();
    Windmill_Two();
    cloud_one();
    cloud_two();
    cloud_five();
    cloud_six();
    airplane();
    road_model();
    car_1();
    Bus();
    field();
    Tree_Circle2_pos1();
    Tree_Circle1_pos2();
    Tilla();
    hill_large_up_pos1();
    hill_small_up_pos1();
    Tree_Circle1_pos1();
    Hotel_position();
    Hospital_position();
    house_four();
    Tree_One();
    Tree_Two();
    Lampost_position();
    School_position();
    Tree_Three();
    RoadCorner1_position();
    RoadCorner2_position();


    print(855,-1,school);
    print(185,105,hotel);
    print(500,70,hospital);

	glFlush();
}
/// ======================== ///
/// *** Speed & Movement *** ///
/// ======================== ///

void move_right(){

    spin = spin +.1;
    spin1 = spin1 +.000095;
    spin2 = spin2 +.00015;
    spin3 = spin3 +.00015;
    spin4 = spin4 +.0009;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
            bx= -400;
    }
    if(ax>1000){
            ax= -400;
    }
    if(dx>1000){
            dx= -500;
    }
    glutPostRedisplay();
}
void move_rightx()
{

    spin = spin +.1;
    spin1 = spin1 +.5;
    spin2 = spin2 +.5;
    spin3 = spin3 +.09;
    spin4 = spin4 +.0009;

    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;
    ar = ar + .20;
    cr = cr +.20;
    bs =  bs -.50;


    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
            bx= -400;

    }
    if(ax>1000){
            ax= -400;

    }
    if(dx>1000){
            dx= -500;

    }

    if(ar>1300){
            ar= -400;

    }

     if(cr>1000){
            cr= -400;

    }
    if(bs<-1300)
    {
        bs=500;
    }
}

void mouse(int key, int state, int x, int y){
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);

        }
        break;
    case GLUT_MIDDLE_BUTTON:



    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}
void handleKeypress(unsigned char key, int x, int y) {

if(key=='y')
{
    glutIdleFunc(move_rightx) ;
}
}

void SpecialInput(int key, int x, int y)
{
switch(key)
{
    case GLUT_KEY_UP:
    glutDisplayFunc(Day);
break;

case GLUT_KEY_DOWN:
  glutDisplayFunc(Night);
break;

case GLUT_KEY_LEFT:
    glutDisplayFunc(Rain);
break;

case GLUT_KEY_RIGHT:
break;
glutPostRedisplay();
}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(-50, 0);
	glutInitWindowSize(1930, 1080);
	glutCreateWindow("Hill tracks Village");
	init();
	glutDisplayFunc(Day);
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(SpecialInput);
    glutMouseFunc(mouse);
    glutIdleFunc(Idle);
	glutMainLoop();
}
