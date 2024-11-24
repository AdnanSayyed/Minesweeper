#include "../header/Gameplay/Cell/CellController.h"
#include "../header/Gameplay/Cell/CellView.h"

namespace Gameplay
{
	namespace Cell
	{

		CellController::CellController()
		{
			cell_view = new CellView(this);
		}

		CellController::~CellController()
		{
			destroy();
		}

		void CellController::initialize(float cell_width, float cell_height)
		{
			cell_view->initialize(cell_width,cell_height);
		}

		void CellController::update()
		{
			cell_view->update();
		}

		void CellController::render()
		{
			cell_view->render();
		}
				
		void CellController::destroy()
		{
			delete (cell_view);
		}
	}
}