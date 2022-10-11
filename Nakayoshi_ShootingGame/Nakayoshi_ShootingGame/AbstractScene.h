#pragma once
class AbstractScene {
public:
	virtual ~AbstractScene() {};

	virtual void Update() = 0;

	virtual void Draw() const = 0;

	virtual AbstractScene* ChangeScene() = 0;
};


