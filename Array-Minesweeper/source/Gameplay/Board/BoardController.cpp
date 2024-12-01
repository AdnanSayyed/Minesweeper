#include "../header/Gameplay/Board/BoardController.h"
#include "../header/Gameplay/Board/BoardView.h"

namespace Gameplay
{
	using namespace Cell;

	namespace Board
	{
		
		BoardController::BoardController()
		{
			board_view = new BoardView(this);
			createBoard();
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::createBoard()
		{
			cell = new CellController(sf::Vector2i(0,0));
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			cell->initialize(15,15);
		}

		void BoardController::update()
		{
			board_view->update();
			cell->update();
		}

		void BoardController::render()
		{
			board_view->render();
			cell->render();
		}

		void BoardController::reset()
		{
			//cell->reset();
		}

		void BoardController::deleteBoard()
		{
			delete(cell);
		}

		void BoardController::destroy()
		{
			deleteBoard();
			delete(board_view);
		}
	}
}