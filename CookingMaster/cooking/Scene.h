#pragma once

//シーン管理の基底クラス
class Scene
{
public:
	virtual bool Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Finalize() = 0;
};