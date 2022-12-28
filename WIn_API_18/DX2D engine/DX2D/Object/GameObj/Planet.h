#pragma once
class Planet
{
public:
	Planet(string name, Vector2 size);
	~Planet();

	void Update();
	void Render();

	void SetParent(shared_ptr<Transform> parent);

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }

	Vector2& Getpos() { return _quad->GetTransform()->Getpos(); }
	Vector2& GetScale() { return _quad->GetTransform()->GetScale(); }
	float& GetAngle() { return _quad->GetTransform()->GetAngle(); }

private:
	string _name;
	shared_ptr<Quad> _quad;
};