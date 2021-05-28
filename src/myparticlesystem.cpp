// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "myparticlesystem.h"

using namespace std;
using namespace agl;
using namespace glm;

void MyParticleSystem::createParticles(int size) 
{
   mTexture = theRenderer.loadTexture("../textures/ParticleFireCloud.png");
   for (int i = 0; i < size; i++)
   {
	   Particle particle = { random_unit_cube(),random_unit_vector(), vec4(vec3(random_float(),random_float(),random_float()), 1.0), 0.05, random_float() };
	   mParticles.push_back(particle);
   }
}

void MyParticleSystem::update(float dt)
{
}

