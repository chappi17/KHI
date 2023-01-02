#pragma once
class FilterScene : public Scene
{
public:

	FilterScene();
	virtual  ~FilterScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:

	shared_ptr<Quad> _quad;
	shared_ptr<FilterBuffer> _filterbuffer;
	shared_ptr<ImageSizeBuffer> _imagesizebuffer;
};

