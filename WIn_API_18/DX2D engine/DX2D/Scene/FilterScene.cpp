#include "framework.h"
#include "FilterScene.h"

FilterScene::FilterScene()
{
	_quad = make_shared<Quad>(L"2B.png");
	_quad->GetTransform()->Getpos() = { CENTER_X , CENTER_Y };
	_quad->SetPixelShader(ADD_PS(L"Filter/FilterShader"));

	_filterbuffer = make_shared<FilterBuffer>();
	_filterbuffer->_data.selected = 1;
	_filterbuffer->_data.value1 = 2;


	_imagesizebuffer = make_shared<ImageSizeBuffer>();
	_imagesizebuffer->_data.imageSize = _quad->GetSize();
}

FilterScene::~FilterScene()
{
}

void FilterScene::Update()
{
	_filterbuffer->Update();
	_imagesizebuffer->Update();
	_quad->Update();
}

void FilterScene::Render()
{
	_filterbuffer->SetPSBuffer(1);
	_imagesizebuffer->SetPSBuffer(2);
	_quad->Render();
}

void FilterScene::PostRender()
{
	ImGui::SliderInt("Selected", &_filterbuffer->_data.selected, 0, 5);
	ImGui::SliderInt("Value1", &_filterbuffer->_data.value1, 0, 100);
	ImGui::SliderInt("Value2", &_filterbuffer->_data.value2, 1, 100);
	ImGui::SliderInt("Value3", &_filterbuffer->_data.value3, 0, 100); 
}
