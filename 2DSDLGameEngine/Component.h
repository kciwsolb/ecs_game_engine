#pragma once

struct Component {
public:	
	virtual void Update() {}
	virtual ~Component() {}
private:
	virtual void Init() {}
};