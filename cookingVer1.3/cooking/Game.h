#pragma once
class Game : public Scene
{
public:
	bool Initialize() override;
	void Update()	  override;
	void Draw()       override;
	void Finalize()   override;

private:
	int bghandle;

};
