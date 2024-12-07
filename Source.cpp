#include "Application.h"

int main() {
  Application *app = new Application(800, 600);

	app->init();
  app->run();
}