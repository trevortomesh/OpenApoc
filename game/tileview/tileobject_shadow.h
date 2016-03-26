#pragma once

#include "game/tileview/tileobject.h"

namespace OpenApoc
{

class Vehicle;

class TileObjectShadow : public TileObject
{
  public:
	void draw(Renderer &r, TileView &view, Vec2<float> screenPosition, TileViewMode mode) override;
	virtual ~TileObjectShadow();
	void setPosition(Vec3<float> newPosition) override;
	const Vec3<float> getPosition() const override;

  private:
	friend class TileMap;
	std::weak_ptr<Vehicle> owner;
	TileObjectShadow(TileMap &map, sp<Vehicle> owner);
	Vec3<float> shadowPosition;
	bool fellOffTheBottomOfTheMap;
};

} // namespace OpenApoc
