#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_oldnames.h>

#include <GameEngine/windowManager.h>

using namespace std;

const int WIDTH = 800, HEIGHT = 800;

int main(int argc, char *argv[]) {
    WindowManager window(WIDTH, HEIGHT, "SDL3 Window");
    bool quit = false;
    while (!quit) {
        window.handleEvents(quit);
        window.clear();
        // Here you can add your rendering code
        window.present();
    }

    return 0;
}