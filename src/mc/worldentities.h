/*
 * Copyright 2012-2014 Moritz Hilscher
 *
 * This file is part of mapcrafter.
 *
 * mapcrafter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mapcrafter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mapcrafter.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WORLDENTITIES_H_
#define WORLDENTITIES_H_

#include "nbt.h"
#include "pos.h"
#include "world.h"

#include <map>
#include <vector>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace mapcrafter {
namespace mc {

class WorldEntitiesCache {
public:
	WorldEntitiesCache(const World& world);
	~WorldEntitiesCache();

	/**
	 * Updates the entity cache.
	 */
	void update();
private:
	World world;
	fs::path cache_file;

	std::map<RegionPos, std::map<ChunkPos, std::vector<nbt::TagCompound> > > entities;

	/**
	 * Reads the file with the cached entities and returns a timestamp when this cache
	 * was updated the last time.
	 */
	int readCacheFile();

	/**
	 * Writes the file with the cached entities.
	 */
	void writeCacheFile() const;
};

} /* namespace mc */
} /* namespace mapcrafter */

#endif /* WORLDENTITIES_H_ */
