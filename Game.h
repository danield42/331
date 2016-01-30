/*******************************
 * This is the main game board.
 * It is implemented as a Singleton: That measn there can only be one instance.
 *******************************/
#ifndef GAME_H_
#define GAME_H_

#include <stdlib.h>
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */

#include "Car.h"

class Car;
class ImageLoader;

#define MAX_OBJECTS 50

class Game {
// Required portions for making this a Singleton.
    public:
        // Insead of a constructor, use this static method to create an instance
        // (or used the already created instance) of Game
        static Game& getInstance()
        {
            static Game    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        };
    private:
        // Make al the constructors private. If you want an instance, use the 
        // getInstance() method above
        Game() {
           m_margine = 4;
           m_width = 507*2;
           m_height = 432*2;
        }; // Default Constructor (the {} brackets) are needed here, even if it is empty.
        Game(Game const&);           // Don't Implement
        void operator=(Game const&); // Don't implement

// Now that we are  a Singleton, define the rest of the class as usual.
   private:
      const static int c_interval = 1000 / 60; // 60 frames per second

      // window size 
      int m_width;
      int m_height;
      int m_margine;

      GLuint m_backgroundTexture;

      // Items in the game
      Car m_myCar;

   public:
      // Functions for GL. key handles keyboard input. Run is the comuting loop
      // Run calls update
      static bool c_running;
      static void key(unsigned char key, int x, int y);
      static void run();
      static void idle();
      static void timer(int id);
      void update();
      void splashScreen();
      void reshape(GLsizei newwidth, GLsizei newheight);
      int LoadImage(char *filename);

      void init();

      GLfloat frand();
};


#endif /* GAME_H_ */
