#include "../header/Gameplay/Board/BoardView.h"
#include "../header/Gameplay/Board/BoardController.h"
#include "../header/Global/ServiceLocator.h"
#include "../header/UI/UIElement/ImageView.h"
#include "../header/UI/UIElement/UIView.h"
namespace Gameplay
{
    namespace Board
    {

        using namespace Global;
        using namespace UI;
        using namespace UI::UIElement;

        BoardView::BoardView(BoardController *controller)
        {
            board_controller = controller;
            board_image = new ImageView();
            background_image = new ImageView();
        }

        BoardView::~BoardView()
        {
            delete (board_image);
            delete (background_image);
        }

        void BoardView::initialize()
        {
            initializeBackgroundImage();
            initializeBoardImage();
        }

        void BoardView::initializeBackgroundImage()
        {
            sf::RenderWindow *game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void BoardView::initializeBoardImage()
        {
            board_image->initialize(Config::board_texture_path, board_width, board_height, sf::Vector2f(0, 0));
            board_image->setCentreAlinged();
        }

        void BoardView::update()
        {
            background_image->update();
            board_image->update();
        }

        void BoardView::render()
        {
            background_image->render();
            board_image->render();
        }

    }
}