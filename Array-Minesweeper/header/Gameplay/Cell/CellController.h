#pragma once
#include <sfml/Graphics.hpp>

namespace Gameplay
{
    namespace Cell
    {
        class CellView;

        class CellController
        {
        private:
            CellView* cell_view;

            void destroy();

        public:
            CellController();
            ~CellController();

            void initialize(float cell_width, float cell_height);
            void update();
            void render();
        };
    }
}
