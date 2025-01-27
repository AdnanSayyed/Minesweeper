#pragma once
#include <sfml/Graphics.hpp>
#include "../header/Gameplay/Cell/CellController.h"
namespace Gameplay
{
    namespace Board
    {
        class BoardView;
        class BoardController
        {


        public:
            static const int number_of_rows = 9;
            static const int number_of_colums = 9;
            static const int mines_count = 8;

            BoardController();
            ~BoardController();

            void initialize();
            void update();
            void render();
            void reset();

        private:
            BoardView *board_view;
            Cell::CellController *cell;

            Cell::CellController* board[number_of_rows][number_of_colums];

        private:
            void createBoard();
            void destroy();
            void deleteBoard();

            void initializeCells();
        };
    }
}