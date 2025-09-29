#include "Cheats.hpp"

Vector2 fun::ScreenSize = { GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN) };
DWORD64 fun::GameBase = 0;

void fun::Fun()
{
	uint64_t viewRender = I::Read<uint64_t>(GameBase + OFF_VIEW_RENDER);
	uint64_t viewMatrix = I::Read<uint64_t>(viewRender + OFF_VIEW_MATRIX);
	Matrix m = I::Read<Matrix>(viewMatrix);

	for (int i = 0; i <= 100; i++) {
		DWORD64 Entity = GetEntityById(i, GameBase);
		if (Entity == 0)
			continue;

		Vector3 Position = I::Read<Vector3>(Entity + OFF_VecAbsOrigin);
		Vector3 ScreenPosition = _WorldToScreen(Position, m, ScreenSize);
		if (ScreenPosition.z <= 0.f)
			continue;

		// Color based on health
		int MaxHealth = I::Read<int>(Entity + OFF_iMaxHealth);
		float TargetHealth = I::Read<float>(Entity + OFF_iHealth) / (float)MaxHealth * 255.f;
		float r = 255.f - TargetHealth;
		float g = TargetHealth;
		float b = 0.f;

		ImDrawList* dL = ImGui::GetBackgroundDrawList();
		dL->AddCircle({ ScreenPosition.x,ScreenPosition.y }, 3, ImColor(0, 255, 0, 255), 0, 1.5f);
	}
}
