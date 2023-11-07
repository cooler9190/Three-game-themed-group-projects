#include "BattleField.hpp"

int main() {
  std::string terranFleetComposition;
  std::string protossFleetCompositon;

  std::cin >> terranFleetComposition >> protossFleetCompositon;
  std::vector<std::unique_ptr<TerranFleet>> terranFleet;
  std::vector<std::unique_ptr<ProtossFleet>> protosFleet;

  BattleField battleField;

  battleField.generateTerranFleet(terranFleetComposition, terranFleet);
  battleField.generateProtossFleet(protossFleetCompositon, protosFleet);

  battleField.startBattle(terranFleet, protosFleet);

  return EXIT_SUCCESS;
}
