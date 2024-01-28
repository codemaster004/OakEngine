/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_ENGINE_H
#define OAKENGINE_ENGINE_H

#include "SDL.h"

namespace oak {
	class Engine {
	protected:
		/* Private Fields */

		SDL_Window* window = nullptr; ///< Application window for showing content
		SDL_Event event{}; ///< Event that occurred by pressing or lifting some key

		bool isRunning = true; ///< For main game loop.


		/* Methods */

		/**
		 * @brief Handles the user events.
		 *
		 * Overridable method meant for handling of user input, meaning keyboard mouse events.
		 *
		 * @note By default it handles only case of system Quit and game end by pressing Esc key
		 */
		virtual void handleInputs();

		/**
		 * @brief Updates the game.
		 *
		 * This method is responsible for updating the game's state.
		 */
		virtual void stepObjects();

		/**
		 * @brief Renders a frame of the game.
		 *
		 * This method is responsible for clearing the renderer, presenting everything on the screen.
		 */
		virtual void renderFrame();

		/**
		 * @brief Handle in game mechanics.
		 *
		 * This method is meant for detecting and handling in game logic and mechanics.
		 * For example physics, collision, npc.
		 */
		virtual void gameMechanics();

		/**
		 * @brief Runs the game loop.
		 *
		 * This function runs the game loop, handling events, updating the game state, and rendering
		 * the frame. The loop continues until the game is no longer running.
		 */
		void gameTick();

		/**
	* @brief Clean up the resources used by the game.
	*
	* This function destroys the SDL window and renderer, and quits the SDL library.
	*/
		void clean();

	public:
		/* Public Fields */

		static SDL_Renderer* renderer; ///< Main renderer for showing on screen.

		static float delta;


		/* Constructors & Destructors */

		Engine() {
			initialize("Powered by Oak", 640, 480);
		};


		Engine(int width, int height) {
			initialize("Powered by Oak", width, height);
		}


		Engine(const char* title, int width, int height) {
			initialize(title, width, height);
		}


		~Engine() {
			clean();
		}

		/* Public Methods */

		/**
	 * @brief Initializes the Game object.
	 *
	 * This method initializes the SDL library, creates a window and a renderer, and sets the initial render draw color.
	 *
	 * @param title The title of the window.
	 * @param width The width of the window.
	 * @param height The height of the window.
	 * @return True if the initialization is successful, otherwise false.
	 */
		bool initialize(const char* title, int width, int height);

		virtual void run();

	};
}
#endif //OAKENGINE_ENGINE_H
