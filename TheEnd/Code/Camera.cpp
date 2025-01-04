#include "Camera.h"

Camera::Camera(sf::Vector2f cameraSize, sf::Vector2f scenaSize){
	view.reset(sf::FloatRect(0, 0, cameraSize.x, cameraSize.y));
	setScenaSize(scenaSize);
}

sf::Vector2f Camera::cameraCorrection(sf::Vector2f centerCameraPosition){
	if (centerCameraPosition.x - view.getSize().x / 2 < 0) {
		centerCameraPosition.x = view.getCenter().x;
	}
	if (centerCameraPosition.x + view.getSize().x / 2 > scenaSize.x) {
		centerCameraPosition.x = scenaSize.x - view.getSize().x / 2;
	}
	if (centerCameraPosition.y - view.getSize().y / 2 < 0) {
		centerCameraPosition.y = view.getCenter().y;
	}
	if (centerCameraPosition.y + view.getSize().y / 2 > scenaSize.y) {
		centerCameraPosition.y = scenaSize.y - view.getSize().y / 2;
	}

	return sf::Vector2f(centerCameraPosition);
}
void Camera::setZoom(float scale){
	view.zoom(scale);
	sf::Vector2f temp = view.getSize();
	if (temp.x > scenaSize.x) {
		temp.x = scenaSize.x;
	}
	if (temp.y > view.getSize().y) {
		temp.y = scenaSize.y;
	}
	view.setSize(temp);
}
void Camera::setCenter(sf::Vector2f centerCameraPositionxy){
	sf::Vector2f currentPosition = cameraCorrection(centerCameraPositionxy);
	view.setCenter(currentPosition);
}
void Camera::setScenaSize(sf::Vector2f scenaSize){
	this->scenaSize = scenaSize;
}
