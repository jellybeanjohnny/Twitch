//
//  Engine.cpp
//  Twitch
//
//  Created by Matt Amerige on 3/29/17.
//  Copyright © 2017 Matt Amerige. All rights reserved.
//

#include "Engine.hpp"
#include <iostream>

using namespace std;

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow *Engine::window = NULL;

Engine::Engine() {
    
}

Engine::~Engine() {
    
}

bool Engine::initialize(char* windowTitle) {
    
    if (!glfwInit()) {
        cout << "Error initializing GLFW" << endl;
        return false;
    }
    
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
    if (!window) {
        cout << "Error creating widow" << endl;
        return false;
    }
    
    // GLFW setup
    glfwMakeContextCurrent(window);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glfwSwapInterval(1);
    
    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int xPos = (mode->width - SCREEN_WIDTH) / 2;
    int yPos = (mode->height - SCREEN_HEIGHT) / 2;
    glfwSetWindowPos(window, xPos, yPos);
    
    
    // OpenGL Setup
    // Viewport
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -10, 10);
    glDepthRange(-10, 10);
    glMatrixMode(GL_MODELVIEW);
    
    // Alpha blending
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    return true;
}

void Engine::update() {
    
}

void Engine::render() {
    glClearColor(0, 1, 0, 1); // blue color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // humans can see this
    
    glfwSwapBuffers(window);
    
    // won't see stuff after this due to swapping the buffers
}












