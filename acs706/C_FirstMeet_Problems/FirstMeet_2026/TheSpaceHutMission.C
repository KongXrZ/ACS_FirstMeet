#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    double target_distance;
    int max_research;

    scanf("%lf %d", &target_distance, &max_research);

    double empty_ship_mass = 2500.0;
    int config_found = 0;

    for (int R = max_research; R >= 0; R--) {

      double base_mass = empty_ship_mass + (R * 200.0);
      for (int F = 2; F <= 20000; F += 2) {

        double total_mass = base_mass + F;
        double petro_mass = F / 2.0;
        double thrust = F * 60.0;
        double mass_penalty = (total_mass / 100.0) * (total_mass / 100.0);
        double actual_distance = thrust - mass_penalty;
        if (actual_distance >= target_distance) {
          int petro_int = (int)petro_mass;
          int oxy_mass_int = (int)petro_mass;
          int petro_tanks = (petro_int + 899) / 900;
          int oxy_tanks = (oxy_mass_int + 1799) / 1800;

          printf("Mission %d -> Best: Research %d | Petroleum: %d kg (%d "
                 "tanks), Liquid Oxy: %d kg (%d tanks)\n",
                 i, R, petro_int, petro_tanks, oxy_mass_int, oxy_tanks);
          config_found = 1;
          break;
        }
      }

      if (config_found == 1) {
        break;
      }
    }

    if (config_found == 0) {
      printf("Mission %d -> Out of range\n", i);
    }
  }

  return 0;
}