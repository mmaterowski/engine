#include <cassert>
#include <engine/particle.h>

using namespace whirlwind;

void Particle::integrate(real duration) {
  // We don't integrate with infinite mass
  if (inverseMass <= 0.0F) {
    return;
  }

  assert(duration > 0.0);

  // Update linear position
  position.addScaledVector(velocity, duration);

  // Work out acceleration from the force
  Vector3 resultingAcc = acceleration;

  // Update velocity from acceleration
  velocity.addScaledVector(resultingAcc, duration);

  // Impose drag
  velocity *= real_pow(damping, duration);

  // Clear the forces
  // TODO: Not implemented yet?
  clearAccumulator();
}

auto Particle::kineticEnergy() -> whirlwind::real {
  if (inverseMass <= 0.0F) {
    return 0.0F;
  }

  return 0.5 * (1.0 / inverseMass) * (velocity.squareMagnitude());
}
