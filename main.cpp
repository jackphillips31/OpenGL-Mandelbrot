#include <SDL2/SDL.h>
#include <iostream>

// Globals
int gScreenWidth = 640;
int gScreenHeight = 480;
SDL_Window* gGraphicsApplicationWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;

bool gQuit = false; // If true, we quit

void InitializeProgram() {

    if(SDL_Init(SDL_INIT_VIDEO)<0){
        std::cout << "SDL2 could not initialize video subsystem" << std::endl;
        exit(1);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


    gGraphicsApplicationWindow = SDL_CreateWindow("OpenGL Window", 0, 0, gScreenWidth, gScreenHeight, SDL_WINDOW_OPENGL);

    if(gGraphicsApplicationWindow == nullptr){
        std::cout << "SDL Window was not able to be created" << std::endl;
        exit(1);
    }

    gOpenGLContext = SDL_GL_CreateContext(gGraphicsApplicationWindow);

    if(gOpenGLContext == nullptr) {
        std::cout << "OpenGL context not available" << std::endl;
        exit(1);
    }
    
}

void Input(){
    SDL_Event e;

    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT){
            std::cout << "Goodbye!" << std::endl;
            gQuit = true;
        }
    }
}

void PreDraw(){

}

void Draw(){

}

void MainLoop() {

    while(!gQuit){

        Input();

        PreDraw();

        Draw();

        // Update the screen
        SDL_GL_SwapWindow(gGraphicsApplicationWindow);
    }

}

void CleanUp() {
    std::cout << "Clean up called" << std::endl;
    SDL_DestroyWindow(gGraphicsApplicationWindow);

    SDL_Quit();
}

int main() {

    InitializeProgram();

    MainLoop();

    CleanUp();

    return 0;
}