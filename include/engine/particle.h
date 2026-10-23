#include "engine/core.h"
class Particle {
protected:
  whirlwind::Vector3 position;

  whirlwind::Vector3 velocity;

  whirlwind::Vector3 acceleration;

  /** Holds the amount of damping applied to linear motion.
   * Damping is required to remove energy added
   * through numerical instability in the
   * integrator. **/
  whirlwind::real damping;
  /** Holds the inverse of the mass of the particle. It* is more useful to hold
   * the inverse mass because integration is simpler, and because in real-time
   * simulation it is more useful to have objects with infinite mass (immovable)
   * than zero mass (completely unstable in numerical simulation). */
  whirlwind::real inverseMass;

  /** This function uses a Newton - Euler integration method,
   * which is a linear approximation to the correct
   * integral.For this reason it may be inaccurate in some cases.**/
  void integrate(whirlwind::real duration);

  auto kineticEnergy() -> whirlwind::real;

  void clearAccumulator();
};
