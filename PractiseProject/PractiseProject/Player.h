#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public:
	Player();
	void Start() override;
	void Update() override;
	virtual ~Player();
};

