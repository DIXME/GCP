#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H
#endif

#include <iostream>
#include <string>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_oldnames.h>

class WindowManager {
public:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    WindowManager(int width, int height, const std::string& title) {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
            throw std::runtime_error("SDL Initialization failed");
        }

        // Create a window
        window = SDL_CreateWindow(title.c_str(), width, height, 0);
        if (!window) {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            throw std::runtime_error("Window creation failed");
        }

        // Create a renderer
        renderer = SDL_CreateRenderer(window, nullptr);
        if (!renderer) {
            std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            throw std::runtime_error("Renderer creation failed");
        }
    }

    ~WindowManager() {
        // Clean up
        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
        SDL_Quit();
    }

    void clear() {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
    }
    void present() {
        SDL_RenderPresent(renderer);
    }
    void handleEvents(bool& quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
    }
};