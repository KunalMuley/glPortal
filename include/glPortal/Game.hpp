#ifndef GAME_HPP
#define GAME_HPP

#include "World.hpp"
#include "GameController.hpp"

#include <radix/Window.hpp>
#include <radix/renderer/Renderer.hpp>
#include <radix/env/Config.hpp>
#include <radix/BaseGame.hpp>
#include "glPortal/renderer/GameRenderer.hpp"
#include "glPortal/renderer/UiRenderer.hpp"
#include "glPortal/renderer/PortalRenderer.hpp"

namespace glPortal {

class Game : public radix::BaseGame {
public:
  Game();
  void processInput();
  void update();

  GameController& getGameController() { return *gameController; }
private:
  std::unique_ptr<GameController> gameController;
  std::unique_ptr<GameRenderer> gameRenderer;
  std::unique_ptr<PortalRenderer> portalRenderer;
  std::unique_ptr<UiRenderer> uiRenderer;
  void initHook();
  void initFunctionStack();
  double dtime;
  void initRenderers();
  void addRenderers();
};

} /* namespace glPortal */

#endif /* GAME_HPP */
