#include "Leaderboard.h"
#include "Utility.h"
#include "raylib.h"
#include <algorithm>

void Leaderboard::InsertNewHighScore(std::string name)
{
	PlayerData newData{ name, score };
	records.push_back(newData);
	std::ranges::sort(records, std::ranges::greater{}, &PlayerData::score);
	records.erase(records.end() - 1);
	ResetScore();
}

void Leaderboard::Render(int textPosX, int fontSize) noexcept {
	for (const auto& player : records) {
		const int posY = 140 + (&player - &records.at(0)) * 40;
		DrawText(player.name.data(), textPosX, posY, fontSize, YELLOW);
		DrawText(TextFormat("%i", player.score), textPosX + 300, posY, fontSize, YELLOW);
	}
}