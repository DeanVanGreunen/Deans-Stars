#include "Stars3D.hpp"

float Stars3D::Random(){
	return (rand() / double(RAND_MAX));
}

void Stars3D::InitStar(std::list<double>::iterator ix, std::list<double>::iterator iy, std::list<double>::iterator iz, std::list<double>::iterator ir, std::list<double>::iterator ig, std::list<double>::iterator ib){
	*ix=(2 * (this->Random() - 0.5f) * this->spread);
	*iy=(2 * (this->Random() - 0.5f) * this->spread);
	*iz=((this->Random() + 0.00001f) * this->spread);
	*ir= *ig = *ib = 0;
}

void Stars3D::CreateStar(){
	starX.insert(starX.begin(),2 * (this->Random() - 0.5f) * this->spread);
	starY.insert(starY.begin(),2 * (this->Random() - 0.5f) * this->spread);
	starZ.insert(starZ.begin(),(this->Random() + 1.0f) * this->spread);
	starR.insert(starR.begin(),0);
	starG.insert(starG.begin(),0);
	starB.insert(starB.begin(),0);
}

Stars3D::Stars3D(int numStars, float spread, float speed){
	int width=800;
	int height=600;
	this->tanHalfFOV = 1;
	this->centerX = 0.0f;
	this->centerY = 0.0f;
	this->visableRadius = 100.0f;
	this->spread = spread;
	this->speed = speed;
	for(int i = 0; i < numStars; i++){
		this->CreateStar();
	}
}

void Stars3D::SetCenter(float x, float y){
	this->centerX = x;
	this->centerY = y;
}

void Stars3D::SetCenterX(float val){
	this->centerX = val;
}

void Stars3D::SetCenterY(float val){
	this->centerY = val;
}

void Stars3D::SetFalloffRadius(float val){
	this->visableRadius = ((val>0)?(val):(val*-1));
}	
		
void Stars3D::work(sf::RenderWindow *target, float delta){
	float halfWidth  = (float)(target->getSize().x)/2.0f;
	float halfHeight = (float)(target->getSize().y)/2.0f;
	sf::CircleShape tmp_circle(1);
	std::list<double>::iterator ix=this->starX.begin(), iy=this->starY.begin(), iz=this->starZ.begin();
	std::list<double>::iterator ir=this->starR.begin(), ig=this->starG.begin(), ib=this->starB.begin();
	int i = 0;
	for(; ix != this->starX.end();){
		i++;
		++ix;
		++iy;
		++iz;
		++ir;
		++ig;
		++ib;
		
		if(*iz < 0){
			InitStar(ix,iy,iz,ir,ig,ib );
		}
		
		*iz-=(delta * speed);
		int x = (int)((double)(*ix / *iz) * halfWidth + halfWidth);
		int y = (int)((double)(*iy / *iz) * halfHeight + halfHeight);

		if((x < 0 || x >= (halfWidth*2)) || (y < 0 || y >= (halfHeight*2))){
			InitStar(ix, iy, iz, ir, ig, ib);
		} else {
			*ir = (int)((float)(255-(*iz * (255/2.5f) * 0.9f)));
			*ig = (int)((float)(255-(*iz * (255/2.5f) * 0.9f)));
			*ib = (int)((float)(255-(*iz * (255/2.5f) * 0.9f)));
			tmp_circle.setFillColor(sf::Color(*ir, *ig, *ib, 255));
			tmp_circle.setPosition(x, y);
			target->draw(tmp_circle);
		}
	}
}
