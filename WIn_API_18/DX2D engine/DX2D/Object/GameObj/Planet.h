#pragma once
class Planet
{

public:
	Planet(string name, Vector2 size);
	~Planet();

	void Update();
	void Render();

	void SetParent(shared_ptr<Transform> parent);

	shared_ptr<Transform> GetTrnasform() { return _texture->GetTransform(); }


	Vector2& Getpos() { return _texture->GetTransform()->Getpos(); }
	Vector2& GetScale() { return _texture->GetTransform()->GetScale(); }
	float& GetAngle() { return _texture->GetTransform()->GetAngle(); }

	
private:
	string _name;
	shared_ptr<Quad> _texture;
};

