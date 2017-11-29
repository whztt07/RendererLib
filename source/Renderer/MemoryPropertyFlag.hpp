/*
This file belongs to Renderer.
See LICENSE file in root folder
*/
#pragma once

#include <VkLib/FlagCombination.hpp>

namespace renderer
{
	/**
	*\brief
	*	Masques de bits décrivant les propriétés pour un type de mémoire.
	*/
	enum class MemoryPropertyFlag
		: uint32_t
	{
		//! Non cached on host.
		eDeviceLocal = 0x00000001,
		//! Host can map memory allocated with this flag.
		eHostVisible = 0x00000002,
		//! Cache commands to flush or invalidate the host memory changes are not necessary anymore, with this flag.
		eHostCoherent = 0x00000004,
		//! The memory allocated with this flag is cached on the host (hence changes will need flush or invalidate commands).
		eHostCached = 0x00000008,
		//! Non visible to host, moreover object's memory may be provided lazily, by implementation.
		eLazilyAllocated = 0x00000010,
	};
	VkLib_ImplementFlag( MemoryPropertyFlag )
	/**
	*\brief
	*	Convertit un renderer::MemoryPropertyFlags en VkMemoryPropertyFlags.
	*\param[in] flags
	*	Le renderer::MemoryPropertyFlags.
	*\return
	*	Le VkMemoryPropertyFlags.
	*/
	VkMemoryPropertyFlags convert( MemoryPropertyFlags const & flags );
}