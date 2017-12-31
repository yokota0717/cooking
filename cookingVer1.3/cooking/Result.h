#pragma once

class Result : public Scene
{
public:
	bool Initialize() override;
	void Update()	  override;
	void Draw()       override;
	void Finalize()   override;
	Sound sound;
private:
	int bghandle;
	
	bool flag;
};