#ifndef MD_STARS
#define MD_STARS
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <list>
#include <cstdlib>
#include <time.h>
#include <iostream>

class Stars3D {
	private:
		float spread;
		float speed;
		float centerX;
		float centerY;
		float visableRadius;
		float tanHalfFOV;
		std::list<double> starX;
		std::list<double> starY;
		std::list<double> starZ;
		std::list<double> starR;
		std::list<double> starG;
		std::list<double> starB;
	public:
		Stars3D(int numStars, float spread, float speed);
		void CreateStar();
		void InitStar(std::list<double>::iterator ix, std::list<double>::iterator iy, std::list<double>::iterator iz, std::list<double>::iterator ir, std::list<double>::iterator ig, std::list<double>::iterator ib);
		float Random();
		void SetCenter(float x, float y);
		void SetCenterX(float val);
		void SetCenterY(float val);
		void SetFalloffRadius(float val);
		void work(sf::RenderWindow *target, float delta);
};
#endif
