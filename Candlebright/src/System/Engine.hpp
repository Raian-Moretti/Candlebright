#pragma once
#include <SFML/Graphics.hpp>

namespace System {
    class Engine {
        private:
            sf::RenderWindow window;
            sf::View view;

        public:
            Engine();
            ~Engine();

            sf::RenderWindow* getWindow(){ return &window; }
            void draw(const sf::Drawable& drawable);

            const bool isWindowOpen() const { return window.isOpen(); }

            void clearWindow();
            void render();
    };
}