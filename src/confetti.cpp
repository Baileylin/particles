// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "confetti.h"

using namespace std;
using namespace agl;
using namespace glm;

void Confetti::createParticles(int size) 
{
   mTexture = theRenderer.loadTexture("../textures/particle.png");
   for (int i = 0; i < size; i++) 
   {
	   Particle particle = { random_unit_cube(),random_unit_vector(), vec4(vec3(random_float(),random_float(),random_float()), 1.0), 0.25, random_float()};
	   mParticles.push_back(particle);
   }
}

void Confetti::update(float dt)
{
	for (int i = 0; i < mParticles.size() - 1; i++)
	{

		if (mParticles[i].pos.x > 1)
		{
			mParticles[i].vel = reflect(mParticles[i].vel, vec3(-1,0,0));
		}
		else if (mParticles[i].pos.x < -1)
		{
			mParticles[i].vel = reflect(mParticles[i].vel, vec3(1, 0, 0));
		}
		else if (mParticles[i].pos.y > 1)
		{
			mParticles[i].vel = reflect(mParticles[i].vel, vec3(0, -1, 0));
		}
		else if (mParticles[i].pos.y < -1)
		{
			mParticles[i].vel = reflect(mParticles[i].vel, vec3(0, 1, 0));
		}
		else if (mParticles[i].pos.z > 1)
		{
			mParticles[i].vel = reflect(mParticles[i].vel, vec3(0, 0, -1));
		}
		else if (mParticles[i].pos.z < -1)
		{
			mParticles[i].vel = reflect(mParticles[i].vel, vec3(0, 0, 1));
		}
		mParticles[i].pos = mParticles[i].pos + dt * mParticles[i].vel;
	}

	int min_idx = 0;
	for (int i = 0; i < mParticles.size() - 1; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < mParticles.size(); j++)
		{
			//float d1 = length(mParticles[j].pos - theRenderer.cameraPosition());
			//float d2 = length(mParticles[min_idx].pos - theRenderer.cameraPosition());
			if (mParticles[j].pos.z < mParticles[min_idx].pos.z)
			{
				min_idx = j;
			}
		}
		swap(mParticles[min_idx], mParticles[i]);
	}

}

