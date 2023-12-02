#include </Users/roman/Library/Frameworks/SFML.framework/Headers/Graphics.hpp>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <cmath>
#include <iostream>
#include<unistd.h>               // for linux


sf::Image image;
GLuint textureID;

float angle;
float r = 10.0;
float x_0 = 0;
float y_0 = 0;
float z_0 = 20;


float g_RotateX = 0.0f;
float g_RotationSpeed = 0.1f;

float alpha = 0.0f;


void setupLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    float posx = x_0 + -1 * r * sin(angle);
    float posy = y_0 + r * (-0.447213 * cos(angle) - 2 * sin(angle));
    float posz = z_0 + r * (-0.894427 * cos(angle) + sin(angle));
    //std::cout << posx << " " << posy << std::endl;
    GLfloat lightDirection[] = {posx, posy, posz, 0.0f};
    GLfloat ambientLight[] = {0.01f, 0.01f, 0.01f, 1.0f};
    GLfloat diffuseLight[] = {0.5f, 0.5f, 0.5f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, lightDirection);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
}

void display_figure_1(){
    glBegin( GL_TRIANGLES );

    //base
//    GLfloat colorA[] = { 1.0f, 0.0f, 0.0f, 1.0f }; // Red color
//    GLfloat colorB[] = { 1.0f, 1.0f, 0.0f, 1.0f }; // Yellow color
//    GLfloat colorC[] = { 1.0f, 0.0f, 1.0f, 1.0f }; // Purple color
//    GLfloat colorD[] = { 0.0f, 1.0f, 1.0f, 1.0f }; // Cyan color
//    GLfloat colorE[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // White color

    GLfloat colorA[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // White color
    GLfloat colorB[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // White color
    GLfloat colorC[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // White color
    GLfloat colorD[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // White color
    GLfloat colorE[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // White color

    // base
//
//    glTexCoord2f(0.0f, 0.0f);
//    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorA);
//    glVertex3f( 3.0f, 3.0f, -1.0f); // A
//    //glNormal3f(-20/3, 25/3, 29/3);
//    glTexCoord2f(1.0f, 0.0f);
//    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorB);
//    glVertex3f( -1.0f, 2.0f, -1.0f); //B
//    //glNormal3f(-40/3, 5, 43/3);
//    glTexCoord2f(0.0f, 1.0f);
//    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorD);
//    glVertex3f( 2.0f, 0.0f, -1.0f); //D
//    //glNormal3f(10/3, -5/3, 10);



    glTexCoord2f(1.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorC);
    glVertex3f( 0.0f, -5.0f, -1.0f); //C
    //glNormal3f(-10/3, -5, 44/3);
    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorB);
    glVertex3f( 3.0f, 3.0f, -1.0f); //A
    //glNormal3f(-40/3, 5, 43/3);
    glTexCoord2f(0.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorD);
    glVertex3f( 2.0f, 0.0f, -1.0f); //D
    //glNormal3f(10/3, -5/3, 10);





    glTexCoord2f(1.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorC);
    glVertex3f( -1.0f, 2.0f, -1.0f); //B
    //glNormal3f(-10/3, -5, 44/3);
    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorB);
    glVertex3f( 3.0f, 3.0f, -1.0f); //A
    //glNormal3f(-40/3, 5, 43/3);
    glTexCoord2f(0.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorD);
    glVertex3f( 0.0f, -5.0f, -1.0f); //C
    //glNormal3f(10/3, -5/3, 10);





    //sides

    glTexCoord2f(1.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorA);
    glVertex3f( 3.0f, 3.0f, -1.0f); // A
    //glNormal3f(-20/3, 25/3, 29/3);
    glTexCoord2f(0.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorB);
    glVertex3f( -1.0f, 2.0f, -1.0f); //B
    //glNormal3f(-40/3, 5, 43/3);
    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorE);
    glVertex3f( 0.0f, 0.0f, 5.0f); //E
    //glNormal3f(-7.5, 2.5, 3.75);

    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorD);
    glVertex3f( 0.0f, -5.0f, -1.0f); //C
    //glNormal3f(-10/3, -5, 44/3); // FIXME
    glTexCoord2f(1.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorB);
    glVertex3f( -1.0f, 2.0f, -1.0f); //B
    //glNormal3f(-40/3, 5, 43/3);
    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorE);
    glVertex3f( 0.0f, 0.0f, 5.0f); //E
    //glNormal3f(-7.5, 2.5, 3.75);

    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorD);
    glVertex3f( 2.0f, 0.0f, -1.0f); //D
    //glNormal3f(10/3, -5/3, 10);
    glTexCoord2f(1.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorC);
    glVertex3f( 0.0f, -5.0f, -1.0f); //C
    //glNormal3f(-10/3, -5, 44/3);
    glTexCoord2f(0.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorE);
    glVertex3f( 0.0f, 0.0f, 5.0f); //E
    //glNormal3f(-7.5, 2.5, 3.75);

    glTexCoord2f(1.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorA);
    glVertex3f( 3.0f, 3.0f, -1.0f); // A
    //glNormal3f(-20/3, 25/3, 29/3);
    glTexCoord2f(1.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorC);
    glVertex3f( 2.0f, 0.0f, -1.0f); //D
    //glNormal3f(10/3, -5/3, 10); // FIXME
    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorE);
    glVertex3f( 0.0f, 0.0f, 5.0f); //E
    //glNormal3f(-7.5, 2.5, 3.75);


    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);


    glEnd();
}

void display_figure_2(){
    glBegin( GL_TRIANGLES );

    //base
//    GLfloat colorA[] = { 1.0f, 0.0f, 0.0f, 1.0f }; // Red color
//    GLfloat colorB[] = { 1.0f, 1.0f, 0.0f, 1.0f }; // Yellow color
//    GLfloat colorC[] = { 1.0f, 0.0f, 1.0f, 1.0f }; // Purple color
//    GLfloat colorD[] = { 0.0f, 1.0f, 1.0f, 1.0f }; // Cyan color
//    GLfloat colorE[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // White color

    GLfloat colorA[] = { 1.0f, 0.0f, 1.0f, 1.0f }; // Purple color
    GLfloat colorB[] = { 1.0f, 0.0f, 1.0f, 1.0f }; // Purple color
    GLfloat colorC[] = { 1.0f, 0.0f, 1.0f, 1.0f }; // Purple color
    GLfloat colorD[] = { 1.0f, 0.0f, 1.0f, 1.0f }; // Purple color
    GLfloat colorE[] = { 1.0f, 0.0f, 1.0f, 1.0f }; // Purple color

//    glTexCoord2f(0.0f, 0.0f);
//    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorA);
//    glVertex3f( 2.0f, 2.0f, 0.0f); // A
//    //glNormal3f(-20/3, 25/3, 29/3);
//    glTexCoord2f(1.0f, 0.0f);
//    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorB);
//    glVertex3f( -3.0f, -2.0f, 0.0f); //B
//    //glNormal3f(-40/3, 5, 43/3);
//    glTexCoord2f(0.0f, 1.0f);
//    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorD);
//    glVertex3f( 2.0f, 0.0f, -1.0f); //D
//    //glNormal3f(10/3, -5/3, 10);


    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorB);
    glVertex3f( 2.0f, 2.0f, 0.0f); // A
    //glNormal3f(-40/3, 5, 43/3);
    glTexCoord2f(1.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorC);
    glVertex3f( 4.0f, -8.0f, 0.0f); //C
    //glNormal3f(-10/3, -5, 44/3);
    glTexCoord2f(0.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorD);
    glVertex3f( 8.0f, -3.0f, 0.0f); //D
    //glNormal3f(10/3, -5/3, 10);

    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorB);
    glVertex3f( 2.0f, 2.0f, 0.0f); // A
    //glNormal3f(-40/3, 5, 43/3);
    glTexCoord2f(1.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorC);
    glVertex3f( 4.0f, -8.0f, 0.0f); //C
    //glNormal3f(-10/3, -5, 44/3);
    glTexCoord2f(0.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorD);
    glVertex3f( -3.0f, -2.0f, 0.0f); //B
    //glNormal3f(10/3, -5/3, 10);

    //sides

    glTexCoord2f(1.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorA);
    glVertex3f( 2.0f, 2.0f, 0.0f); // A
    //glNormal3f(-20/3, 25/3, 29/3);
    glTexCoord2f(0.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorB);
    glVertex3f( -3.0f, -2.0f, 0.0f); //B
    //glNormal3f(-40/3, 5, 43/3);
    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorE);
    glVertex3f( 4.0f, -2.0f, 7.0f); //E
    //glNormal3f(-7.5, 2.5, 3.75);

    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorD);
    glVertex3f( 4.0f, -8.0f, 0.0f); //C
    //glNormal3f(-10/3, -5, 44/3); // FIXME
    glTexCoord2f(1.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorB);
    glVertex3f( -3.0f, -2.0f, 0.0f); //B
    //glNormal3f(-40/3, 5, 43/3);
    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorE);
    glVertex3f( 4.0f, -2.0f, 7.0f); //E
    //glNormal3f(-7.5, 2.5, 3.75);

    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorD);
    glVertex3f( 8.0f, -3.0f, 0.0f); //D
    //glNormal3f(10/3, -5/3, 10);
    glTexCoord2f(1.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorC);
    glVertex3f( 4.0f, -8.0f, 0.0f); //C
    //glNormal3f(-10/3, -5, 44/3);
    glTexCoord2f(0.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorE);
    glVertex3f( 4.0f, -2.0f, 7.0f); //E
    //glNormal3f(-7.5, 2.5, 3.75);

    glTexCoord2f(1.0f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorA);
    glVertex3f( 2.0f, 2.0f, 0.0f); // A
    //glNormal3f(-20/3, 25/3, 29/3);
    glTexCoord2f(1.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorC);
    glVertex3f( 8.0f, -3.0f, 0.0f); //D
    //glNormal3f(10/3, -5/3, 10); // FIXME
    glTexCoord2f(0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorE);
    glVertex3f( 4.0f, -2.0f, 7.0f); //E
    //glNormal3f(-7.5, 2.5, 3.75);


    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);


    glEnd();
}

// Call this before drawing your geometry
void setupMaterial() {
    GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat mat_shininess[] = { 50.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setupLighting();
    setupMaterial();

    glEnable(GL_TEXTURE);
    glBindTexture(GL_TEXTURE, textureID);

    display_figure_1();
    display_figure_2();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5*cos(alpha), 5, 5*sin(alpha),
              0, 0, 0,
              0, 0, 1);
    alpha += 0.05;
    std::cout << 5*cos(alpha) << std::endl;


    glFlush();
    glutPostRedisplay();
}

// Sets up global attributes like clear color and drawing color, enables and
// initializes any needed modes (in this case we want backfaces culled), and
// sets up the desired projection and modelview matrices. It is cleaner to
// define these operations in a function separate from main().
void init() {
    glEnable(GL_DEPTH_TEST); // Enable depth testing

    // Set the current clear color to sky black and the current drawing color to
    // white.
    glClearColor(0,0,0, 1.0);

    // Tell the rendering engine not to draw backfaces.  Without this code,
    // all four faces of the tetrahedron would be drawn and it is possible
    // that faces farther away could be drawn after nearer to the viewer.
    // Since there is only one closed polyhedron in the whole scene,
    // eliminating the drawing of backfaces gives us the realism we need.
    // THIS DOES NOT WORK IN GENERAL.
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);

    // Set the camera lens so that we have a perspective viewing volume whose
    // horizontal bounds at the near clipping plane are -2..2 and vertical
    // bounds are -1.5..1.5.  The near clipping plane is 1 unit from the camera
    // and the far clipping plane is 40 units away.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-2, 2, -1.5, 1.5, 1, 40);

    // Set up transforms so that the tetrahedron which is defined right at
    // the origin will be rotated and moved into the view volume.  First we
    // rotate 70 degrees around y so we can see a lot of the left side.
    // Then we rotate 50 degrees around x to "drop" the top of the pyramid
    // down a bit.  Then we move the object back 3 units "into the screen".



//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(5*cos(alpha), 5, 5*sin(alpha),
//              0, 0, 0,
//              0, 0, 1);
//    alpha += 1;
//    std::cout << 5*cos(alpha) << std::endl;

//    glRotatef( g_RotateX, 0, 1.0f, 0 );
//    g_RotateX += g_RotationSpeed;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    GLfloat material_color[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material_color);
}

void idle() {
    angle+= 0.05;
    if(angle > 360) {
        angle = 0;
    }
    sleep(0.1);
}

void loadTexture() {
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());

    glBindTexture(GL_TEXTURE_2D, 0);
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("A Simple Tetrahedron");

    if (!image.loadFromFile("/Users/roman/src/opengl-tutorial/orange.jpg"))
    {
        std::cout << "Error on loading texture file!\n";
        return -1;
    }

    loadTexture();

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    init();
    glutMainLoop();
}