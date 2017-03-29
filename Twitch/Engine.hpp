//
//  Engine.hpp
//  Twitch
//
//  Created by Matt Amerige on 3/29/17.
//  Copyright © 2017 Matt Amerige. All rights reserved.
//

#ifndef Engine_hpp
#define Engine_hpp

#include <GLFW/glfw3.h>
#include <OpenGL/OpenGL.h>

class Engine {
    
public:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    
    Engine();
    ~Engine();
    
    bool initialize(char *windowTitle);
    void update();
    void render();
    
    
private:
    static GLFWwindow *window;
};

#endif /* Engine_hpp */
